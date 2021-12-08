#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <iostream>

#include "Stack.hpp"
#include "Kisi.hpp"

using namespace std;

class TreeNode 
{

public:
	TreeNode(string ism, int yil, int kg ,int yas, TreeNode* sl = NULL, TreeNode* sg = NULL);
	~TreeNode();
	Kisi* getKisi();
	void setKisi(Kisi* kisi);
	TreeNode* getSol();
	void setSol(TreeNode* sol);
	TreeNode* getSag();
	void setSag(TreeNode* sag);
	int getYukseklik();
	void setYukseklik(int yukseklik);
	int getDerinlik();
	void setDerinlik(int derinlik);
	Stack* getYigit();

private:
	Kisi* kisi;
	int derinlik;
	int yukseklik;
	TreeNode* sol;
	TreeNode* sag;
	Stack* yigit;
};

#endif