#include "HuffmanNode.h"
HuffmanNode::HuffmanNode() {};
HuffmanNode::HuffmanNode(string str, int frequency, HuffmanNode* left = NULL, HuffmanNode* right = NULL) {
	this->str = str;
	this->frequency = frequency;
	this->left = left;
	this->right = right;
};
int HuffmanNode::getFrequency() {
	return frequency;
}
string HuffmanNode::getStr() {
	return str;
};
void HuffmanNode::setFrequency(int freq) { frequency = freq; };
void HuffmanNode::getStr(string str) { this->str = str; };
HuffmanNode* HuffmanNode::getLeftChild() {
	return left;
};
HuffmanNode* HuffmanNode::getRightChild() {
	return right;

};