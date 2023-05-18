#include "HuffmanTree.h"
#include<queue>
#include<vector>
HuffmanTree::HuffmanTree() {

	root = new HuffmanNode("", 0, NULL, NULL);


};

void HuffmanTree::encode(string sourceFileName) {
	int* table = buildFrequencyTable(sourceFileName);
	int size = 0;
	for (int i = 0;i < 256;i++) {
		if (table[i] > 0) {
			size++;//in this index there is a chracter that appears in the sourceFile
		}
	}
	cout << size << endl;
	buildTree(table);
	string str2 = breadscan(root);
	cout << endl << str2 << endl;
	string* codedTable = buildCodedTabe();

	for (int i = 0;i < (sourceFileName.size());i++) {//encoding for each letter in the file
		cout << encode2(sourceFileName[i], codedTable);
	}
};


int* HuffmanTree::buildFrequencyTable(string text) {
	int* frequencyTable = new int[256];
	for (int i = 0;i < 256;i++) {
		frequencyTable[i] = 0;

	}
	int size = text.size();
	for (int i = 0;i < size;i++) {
		frequencyTable[int(text[i])] += 1;
	}
	return frequencyTable;
};
void HuffmanTree::buildTree(int* frequencyTable) {
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareNode> pQueue;
	string str1 = "";
	char name[] = "cplusplus.com";
	char* str3 = name;
	HuffmanNode* huff4;
	for (int i = 0;i < 256;i++) {
		if (frequencyTable[i] > 0) {
			*str3 = char(i);
			str1 = *str3;
			HuffmanNode* huff = new HuffmanNode(str1, frequencyTable[i], NULL, NULL);//putting the letters that exist in the string and their frequencies  in the priority queue
			pQueue.push(huff);
		}
	}
	while (pQueue.size() > 1) {

		HuffmanNode* huff2 = pQueue.top();
		pQueue.pop();
		HuffmanNode* huff3 = pQueue.top();
		pQueue.pop();
		if ((huff3->getFrequency() == huff2->getFrequency()) && ((huff2->getStr().size() > 1) || (huff3->getStr().size() > 1))) {
			if (huff3->getStr().size() > 1) {
				huff4 = new HuffmanNode((huff2->getStr() + huff3->getStr()), (huff2->getFrequency() + huff3->getFrequency()), huff3, huff2);

			}
			else {
				huff4 = new HuffmanNode((huff2->getStr() + huff3->getStr()), (huff2->getFrequency() + huff3->getFrequency()), huff2, huff3);

			}
		}
		else {

			huff4 = new HuffmanNode((huff2->getStr() + huff3->getStr()), (huff2->getFrequency() + huff3->getFrequency()), huff2, huff3);

		}

		pQueue.push(huff4);
	}
	root = pQueue.top();//the biggest ellemnt will be the root

};

HuffmanNode* HuffmanTree::place(HuffmanNode* m, string letter) {//finds and returns the adress of the letter in the tree 
	if (m->getStr() == letter) {
		return m;
	}
	if ((m->getLeftChild() == NULL) && (m->getLeftChild() == NULL)) { return NULL; }
	if (m->getLeftChild() != NULL) {
		if (place(m->getLeftChild(), letter) != NULL)
			return place(m->getLeftChild(), letter);
	}
	if (m->getRightChild() != NULL) {
		return place(m->getRightChild(), letter);
	}
	return NULL;
};
string* HuffmanTree::buildCodedTabe() {
	string* codedTable = new string[256];
	for (int i = 0;i < 256;i++) {
		codedTable[i] = "";
	}
	char name[] = "cplusplus.com";
	char* ch = name;
	string str2;
	for (int i = 0;i < 256;i++) {
		*ch = char(i);
		str2 = *ch;
		HuffmanNode* g = place(root, str2);
		if (g != NULL) {//if the letter exists in the hf tree

			str2 = path(g);
			codedTable[i] = str2;
		}
	}
	return codedTable;
};

string HuffmanTree::path(HuffmanNode* m) {//returns the code of of the letter that the function gets its place bin the huffman tree
	HuffmanNode* p;
	string str1;
	if (m == root) { return ""; }
	p = parent(root, m);
	if (p->getLeftChild() == m) {
		return  path(p) + '0';
	}
	if (p->getRightChild() == m) {
		return   path(p) + '1';

	}
};

HuffmanNode* HuffmanTree::parent(HuffmanNode* p, HuffmanNode* m) {//find the parent of a node it gets as a parameter
	if (p->getFrequency() == 0) { return NULL; }
	if ((p->getLeftChild() == NULL) && (p->getRightChild() == NULL)) { return NULL; }
	if ((p->getLeftChild() == m) || (p->getRightChild() == m)) { return p; }
	if (p->getLeftChild() != NULL) {
		if (parent(p->getLeftChild(), m) != NULL) {
			return parent(p->getLeftChild(), m);
		}
	}
	if (p->getRightChild() != NULL) {
		return parent(p->getRightChild(), m);
	}
}

string HuffmanTree::encode2(char letter, string* codedTable) {//gets a letter and the codedTable and returns the letter code 
	int i = int(letter);
	return codedTable[i];


};
string	HuffmanTree::breadscan(HuffmanNode* huff) {//go over all of the tree and printing the values of the leafs it finds and returning the structure of the tree
	if (huff->getFrequency() == 0) {//if the tree is empty
		return "1";
	}
	string str1;
	if (((huff->getLeftChild() != NULL)) && (huff->getRightChild() != NULL)) {
		str1 = "0" + breadscan(huff->getLeftChild());
		str1 += breadscan(huff->getRightChild());

		return str1;
	}
	if ((huff->getLeftChild() == NULL) && (huff->getRightChild() != NULL)) { return "0" + breadscan(huff->getRightChild()); }
	if ((huff->getLeftChild() != NULL) && (huff->getRightChild() == NULL)) { return "0" + breadscan(huff->getLeftChild()); }

	if ((huff->getLeftChild() == NULL) && (huff->getRightChild() == NULL)) {
		cout << huff->getStr();
		return "1";
	}
};
void HuffmanTree::buildTree(int n, string letters, string tree, string word) {
	if (n == 0) { cout << "ERROR\n";return; }
	int num2 = 0;
	for (int i = 0;i < tree.size();i++) {
		if (tree[i] == '1') {
			num2++;
		}
	}
	if (num2 != n) {//if the number of the children in the tree does not equal to the number of the letters in the tree return ERROR
		cout << "ERROR\n";return;
	}
	HuffmanNode* p;
	int i = 0;
	if (tree[0] == '1') {
		char name[] = "cplusplus.com";
		char* str3 = name;
		*str3 = letters[0];
		string l = str3;
		root = new HuffmanNode(l, 1, NULL, NULL);
		return;
	}
	root = new HuffmanNode("", 1, NULL, NULL);
	int num1 = 0;
	int num = 0;

	root = buildTreeForDecode(root, tree, num1, num, letters);
	string* data = new string[n];
	string str2;
	HuffmanNode* a;
	for (int i = 0;i < n;i++) {
		string l = "";
		char name[] = "cplusplus.com";
		char* str3 = name;
		*str3 = letters[i];
		l = *str3;
		a = place(root, l);
		str2 = path(a);
		data[i] = str2;
		str2 = "";

	}
	str2 = "";
	cout << "The decoded string is \n" << " ";

	for (int j = 0;j < word.size();j++) {
		str2 += word[j];
		for (int k = 0;k < n;k++) {
			if (data[k] == str2) {
				cout << letters[k];
				str2 = "";
			}
		}

	}
};

HuffmanNode* HuffmanTree::buildTreeForDecode(HuffmanNode* p, string tree, int& i, int& j, string letters) {
	int n1;
	int n2;
	int size = tree.size();
	if (i >= size) { return NULL; }
	if (tree[i] == '0') {
		i++;
		HuffmanNode* m = buildTreeForDecode(p, tree, i, j, letters);
		HuffmanNode* g = buildTreeForDecode(p, tree, i, j, letters);
		if (g == NULL) {
			p = new  HuffmanNode(m->getStr() + g->getStr(), 1, m, NULL);
		}
		if (m == NULL) {
			p = new  HuffmanNode(m->getStr() + g->getStr(), 1, NULL, g);

		}
		if ((m != NULL) && (g != NULL)) {
			p = new  HuffmanNode(m->getStr() + g->getStr(), 1, m, g);
		}

		return p;
	}
	else {
		string l = "";
		char name[] = "cplusplus.com";
		char* str3 = name;
		*str3 = letters[j];
		l = *str3;

		p = new HuffmanNode(l, 1, NULL, NULL);
		j++;
		i++;
		return p;
	}

};

void HuffmanTree::destructorOfTheTree(HuffmanNode* m) {

	if ((m->getRightChild() == NULL) && (m->getLeftChild() == NULL)) { delete m; return; }

	if (m->getLeftChild() != NULL) { 
		destructorOfTheTree(m->getLeftChild());
	}

	if (m->getRightChild() != NULL) {
		destructorOfTheTree(m->getRightChild());
	}
	delete m;


};
