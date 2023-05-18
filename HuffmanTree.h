#pragma once
#include "HuffmanNode.h"
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class HuffmanTree
{
	HuffmanNode* root;
public:
	HuffmanTree();
	int* buildFrequencyTable(string text);
	void encode(string sourceFileName);
	string* buildCodedTabe();
	void buildTree(int n, string letters, string tree, string word);
	void buildTree(int* frequencyTable);
	string path(HuffmanNode* m);
	HuffmanNode* parent(HuffmanNode* p, HuffmanNode* m);
	string	breadscan(HuffmanNode* huff);
	HuffmanNode* place(HuffmanNode* m, string letter);
	string encode2(char letter, string* codedTable);
	HuffmanNode* buildTreeForDecode(HuffmanNode* p, string tree, int& i, int& j, string letters);
	void destructorOfTheTree(HuffmanNode* m);
};



