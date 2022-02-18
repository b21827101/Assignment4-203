#include "Huffman.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

void Huffman::frequencyCounter(string str1) {
    encodedstring = str1;
    int length = str1.length();
    for (int i = 0; i < length; i++) {//to calculate frequency for each character
        int c = str1[i];
        if (isspace(c)){ //to calculate whitespaces
            frequencyMap[' ']++;
        }
        else{ //to others
            frequencyMap[c]++;
        }
    }
    Huffman h;
    h.buildTree(frequencyMap,encodedstring);
}

bool Huffman::TreeComparator::operator()(Node *node1, Node *node2) {
    return (node1->frequency < node2->frequency);//sorting
}

void Huffman::sort(){
    std::vector<Node*> v;
    while(!gquiz.empty()){ //sorting the queue
        v.push_back(gquiz.front());
        gquiz.pop();
    }
    std::sort(v.begin(), v.end(), TreeComparator());
    for(int i = 0; i < v.size(); i++){
        gquiz.push(v[i]);
    }
}

void Huffman::buildTree(map<char,int> frequencyMap, string encodedstring ) {
    map<char, int>::iterator it;

    for (it = frequencyMap.begin(); it != frequencyMap.end(); it++){
        Node* node = new Node();
        node->character = it->first;
        node->frequency = it->second;//add it to the queue.
        node->left = NULL;
        node->right = NULL;
        gquiz.push(node);
    };
    Huffman::sort();

    while (gquiz.size() != 1){

        Node *left = gquiz.front();
        gquiz.pop();// Remove the two highest nodes of the queue
        Node *right = gquiz.front();
        gquiz.pop();

        Node* node = new Node();
        node->character = '\0';
        int sum = left->frequency + right->frequency;
        // frequency equal to the sum of the two nodes frequencies.
        node->frequency = sum;
        node->left = left;
        node->right = right;
        gquiz.push(node);
        sort();

    }
    string str2;
    encode( gquiz.front(), str2);
    string s3 = encodedstring;
    displayencoding(s3);
}



void Huffman::encode(Node * root,string str2) {
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL){ //situation for leaf
        encodedcodes[root->character]=str2; //store huffman codes in map
    }
    encode(root->left, str2 + "0");
    encode(root->right, str2 + "1");
}


string Huffman::displayencoding(string enco){//to display in console
    string string5;
    for (int i = 0; i < enco.length(); i++) {
        string5+=encodedcodes[enco[i]];
    };
    cout << "\n" << string5 << endl;
    tree(encodedcodes);
    return string5 ;
}

void Huffman::decode(string s) {
    ifstream inFile;
    string char1;
    string str2;
    string decodestr;

    for (int i = 0; i < s.length(); i++) {
        str2 +=s[i];  //each character at current index to another string

        inFile.open("tree.txt");

        while (getline(inFile, char1)){ //get info from table
            istringstream iss(char1);
            string s1,frequency;
            iss >> s1>> frequency;
            if(str2 == frequency){//If str2 equals the huffman code of any character
                str2.clear() ;
                decodestr+=s1;
            }
	     else if(str2 == s1){
                str2.clear() ;
                decodestr+=" ";
            }
        }
        inFile.close();
    }
    cout<<decodestr<<"\n"; //display decode string in console
}


void Huffman::tree(map<char, string> encodedcodes) { //to save characters and it's frequencies in txt
    std::ofstream outfile ("tree.txt");
    map<char, string>::iterator itr;

    for (itr = encodedcodes.begin(); itr != encodedcodes.end(); ++itr) {
        outfile << itr->first
                << " "<< itr->second << '\n';
    }

    outfile.close();

}

void Huffman::readingCharacter(string character) {//for -s character
    string myText;
    // Read from the text file
    ifstream MyReadFile("tree.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {//to display characters and it's frequencies in console
        // Output the text from the file
        if(myText.find(character)< myText.length()){
            cout << myText<<"\n";
            break;
        }
    }

}



