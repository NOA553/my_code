#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "HuffmanTree.h"


int main() {
	char choice;


	HuffmanTree* t = new HuffmanTree();
	cout << "enter E to encode a text\n";
	cout << "enter D to decode a text\n";
	cout << "enter X to exit\n";
	string word;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 'E':
		{
			cout << "enter the original text" << endl;
			cin >> word;
			cout << "The encoded string is\n";
			t->encode(word);
			cout << "\n";
			//Build Huffman tree given the data inside "word".
			//Then find the code of each letter.
			//Then print the output - number of leaves, order of letters, tree structure and the encoded text - according to the explanation in the exercise.

			break;}
		case 'D': {

			int n;
			string letters, tree, word;
			cout << "enter n" << endl;
			cin >> n;
			cout << "enter the letters" << endl;
			cin >> letters;

			cout << "enter the encoded structure" << endl;
			cin >> tree;
			cout << "enter the encoded text " << endl;

			cin >> word;
			t->buildTree(n, letters, tree, word);
			cout << "\n";
			//input the number of leaves, the  order of letters, tree structure and the encoded text.
			//build the Huffman Tree according to the tree strcture. put the letters in the leaves according to the given order. 
			//Given the Huffman Tree and the encoded text, find the original text, and print it. 
		}
		}

	} while (choice != 'X');
	cout << "bye";
	return 0;
}