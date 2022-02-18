all:a4

a4: main.o ReadingFile.o Huffman.o
	 g++ main.o ReadingFile.o Huffman.o -o a4.exe

main.o: main.cpp
	g++ -c main.cpp

ReadingFile.o: ReadingFile.cpp ReadingFile.h
	g++ -c ReadingFile.cpp

Huffman.o: Huffman.cpp Huffman.h
	g++ -c Huffman.cpp

clean:
	rm *.o a4