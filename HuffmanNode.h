#pragma once
#include<iostream>
using namespace std;
class compareNode;
class HuffmanNode
{
	string str;
	int frequency;
	HuffmanNode* left;
	HuffmanNode* right;
	friend class compareNode;
public:
	HuffmanNode();
	HuffmanNode(string str, int frequency, HuffmanNode* left, HuffmanNode* right);
	int getFrequency();
	string getStr();
	void setFrequency(int);
	void getStr(string);
	HuffmanNode* getLeftChild();
	HuffmanNode* getRightChild();

};

class compareNode {
public:
	bool operator()(HuffmanNode* const& n1, HuffmanNode* const& n2)
	{
		return n1->frequency > n2->frequency;
	}
};
