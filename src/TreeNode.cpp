#include "TreeNode.hpp"

TreeNode::TreeNode(string ism, int yil, int kg ,int yas, TreeNode* sl, TreeNode* sg) 
{
	kisi = new Kisi(ism, yil, kg,yas);
    sol = sl;
    sag = sg;
    yukseklik = 0;
    derinlik = -1;
    yigit = new Stack();
    yigit->insert('O');
}

Kisi* TreeNode::getKisi()
{
	return kisi;
}

void TreeNode::setKisi(Kisi* kisi)
{
	this->kisi = kisi;
}

TreeNode* TreeNode::getSol()
{
    return sol;
}

void TreeNode::setSol(TreeNode* sol)
{
    this->sol = sol;
}

TreeNode* TreeNode::getSag()
{
    return sag;
}

void TreeNode::setSag(TreeNode* sag)
{
    this->sag = sag;
}

int TreeNode::getYukseklik()
{
    return yukseklik;
}

void TreeNode::setYukseklik(int yukseklik)
{
    this->yukseklik = yukseklik;
}

int TreeNode::getDerinlik()
{
    return derinlik;
}

void TreeNode::setDerinlik(int derinlik)
{
    this->derinlik = derinlik;
}

Stack* TreeNode::getYigit()
{
    return yigit;
}

TreeNode::~TreeNode()
{
    delete yigit;
}
