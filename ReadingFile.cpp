#include "ReadingFile.h"
#include "Huffman.h"
using namespace std;
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cctype>

char  ReadingFile::input[50];
char  ReadingFile::decodeinput[50];

void ReadingFile::reading() {
    int input = 0;
    ifstream inFile;
    inFile.open(ReadingFile::input);//"input.txt"
    int jp = 0;
    if (!inFile) {
    }
    string strp;
    while (getline(inFile, strp)) {  //in there saving number of lines
        input++;
    }
    inFile.close();

    inFile.open(ReadingFile::input);
    string packarr[input+1];

    while (getline(inFile, strp)) {
        packarr[jp] = strp;
        jp++;
    }
    inFile.close();
    Huffman h;
    string str1;
    for(int i =0;i<input;i++){
        str1 =packarr[i];
        transform(str1.begin(), str1.end(), str1.begin(), ::tolower); //converts a given character to lowercase
    }
    h.frequencyCounter(str1); //calculating frequencies
}


void ReadingFile::readingDecode() {
    string myText;
    string myDecode;
    // Read from the text file
    ifstream MyReadFile;
    MyReadFile.open(ReadingFile::decodeinput);//decode.txt
    Huffman h;
    if (!MyReadFile) {
    }
    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
        myDecode = myText;
    }
    MyReadFile.close();
    h.decode(myDecode);


}


