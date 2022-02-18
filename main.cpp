#include <iostream>
#include "ReadingFile.h"
#include "Huffman.h"

using namespace std;

int main(int argc, char** argv){

    if(argc == 4){
        string str1 =argv[3] ;
        if(str1 == "-encode"){ //using for -i input_file.txt -encode
            strcpy (ReadingFile::input,argv[2]);
            ReadingFile read;
            read.reading();
        }
        else if(str1 == "-decode"){//using for -i input_file.txt -decode
            strcpy (ReadingFile::decodeinput,argv[2]);
            ReadingFile r;
            r.readingDecode();
        }
    }
    else if(argc == 3){ //using for -s character
        string str1 =argv[2] ;
        Huffman h;
        h.readingCharacter(str1);
    }

    return 0;
}
