#ifndef ASSIGNMENT4_READINGFILE_H
#define ASSIGNMENT4_READINGFILE_H
#include <cstring>
using namespace std;


class ReadingFile {
public:
    void reading();  //input text method
    void readingDecode();  //decode text method
    static char input[50];   //for argv
    static char decodeinput[50];   //for argv

};

#endif //ASSIGNMENT4_READINGFILE_H
