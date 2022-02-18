#ifndef ASSIGNMENT4_HUFFMAN_H
#define ASSIGNMENT4_HUFFMAN_H
#include <map>
#include <vector>
#include <queue>
using namespace std;
#include <string>

class Huffman {
    map<char,int> frequencyMap;
public:
    struct Node {
        char character;
        int frequency;
        Node *left, *right;
    };
    struct TreeComparator{
        bool operator()(Node *node1, Node *node2); //it is using for sorting

    };
    string encodedstring;
    map<char, string> encodedcodes;
    queue<Node*> gquiz;
    void frequencyCounter(string str);
    void buildTree(map<char,int> frequencyMap,string encodedstring);
    void sort();
    void encode(Node * root,string str);
    void decode(string decodestring);
    string displayencoding(string enco);
    void tree(map<char, string> map );//for save characters in txt
    void readingCharacter(string character);//for display character
};


#endif //ASSIGNMENT4_HUFFMAN_H
