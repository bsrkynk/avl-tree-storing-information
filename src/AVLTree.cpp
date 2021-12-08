#include "AVLTree.hpp"
using namespace std;

TreeNode* AVLTree::AraveEkle(TreeNode* alt_TreeNode, string yeni, int dogumYili, int kilo,int yas) // Dugume ekleme yapilir
{
	if (alt_TreeNode == NULL) 
	{
		alt_TreeNode = new TreeNode(yeni, dogumYili, kilo,yas);
	}
    
	else if (yas <= alt_TreeNode->getKisi()->getYas()) 
	{
		alt_TreeNode->setSol(AraveEkle(alt_TreeNode->getSol(), yeni, dogumYili, kilo, yas));
		if (Yukseklik(alt_TreeNode->getSol()) - Yukseklik(alt_TreeNode->getSag()) == 2) 
		{
            //Sol sol durumu
			if (yas <= alt_TreeNode->getSol()->getKisi()->getYas())
				alt_TreeNode = SolCocukIleDegistir(alt_TreeNode);
			else 
			{ 
                //Sag sol durumu
				alt_TreeNode->setSol(SagCocukIleDegistir(alt_TreeNode->getSol())); 
				alt_TreeNode = SolCocukIleDegistir(alt_TreeNode);
			}
		}
	}
    else if (yas > alt_TreeNode->getKisi()->getYas()) 
	{
		alt_TreeNode->setSag(AraveEkle(alt_TreeNode->getSag(), yeni, dogumYili, kilo,yas));
		if (Yukseklik(alt_TreeNode->getSag()) - Yukseklik(alt_TreeNode->getSol()) == 2) 
		{      //Sag sag durumu
			if (yas > alt_TreeNode->getSag()->getKisi()->getYas())
				alt_TreeNode = SagCocukIleDegistir(alt_TreeNode);
			else 
			{  // Sol sag durumu
				alt_TreeNode->setSag(SolCocukIleDegistir(alt_TreeNode->getSag()));
				alt_TreeNode = SagCocukIleDegistir(alt_TreeNode);
			}
		}
	}
	
	else; 
	
	alt_TreeNode->setYukseklik(Yukseklik(alt_TreeNode));
	return alt_TreeNode;
}

TreeNode* AVLTree::SolCocukIleDegistir(TreeNode* alt_TreeNode)
{
    TreeNode* tmp = alt_TreeNode->getSol();
    alt_TreeNode->setSol(tmp->getSag());
    tmp->setSag(alt_TreeNode);
    // Yukseklikleri güncelle
    alt_TreeNode->setYukseklik(Yukseklik(alt_TreeNode));
    
    tmp->setYukseklik(max(Yukseklik(tmp->getSol()), alt_TreeNode->getYukseklik()) + 1);
    
    return tmp;
}

TreeNode* AVLTree::SagCocukIleDegistir(TreeNode* alt_TreeNode)
{
    TreeNode* tmp = alt_TreeNode->getSag();
    alt_TreeNode->setSag(tmp->getSol());
    tmp->setSol(alt_TreeNode);

    alt_TreeNode->setYukseklik(Yukseklik(alt_TreeNode));
    tmp->setYukseklik(max(Yukseklik(tmp->getSag()), alt_TreeNode->getYukseklik()) + 1);

    return tmp;
}
//Dugumdeki elemanlar bastırılır
void AVLTree::Postorder(TreeNode* alt_TreeNode) 
{
    if (alt_TreeNode != NULL) 
    {
        Postorder(alt_TreeNode->getSol());
        Postorder(alt_TreeNode->getSag());
        cout << alt_TreeNode->getKisi()->getIsim() << ", " << alt_TreeNode->getKisi()->getDogumYili() // Dugumdeki kisi nesnesine ulasılıp ,bastirilir
            << ", " << alt_TreeNode->getKisi()->getKilo();
        cout << "    Yigit: ";
        while(!alt_TreeNode->getYigit()->isEmpty())
        {
            cout << alt_TreeNode->getYigit()->getTop() << " ";
            alt_TreeNode->getYigit()->pop(); //Dugumdeki stack e ulasma
        }
        cout << endl;
    }
}
// Yukseklik hesaplama
int AVLTree::Yukseklik(TreeNode* alt_TreeNode)
{
    if (alt_TreeNode == NULL)
        return -1; 
    return 1 + max(Yukseklik(alt_TreeNode->getSol()), Yukseklik(alt_TreeNode->getSag()));
}

bool AVLTree::TreeNodeSil(TreeNode*& alt_TreeNode)
{
    TreeNode* silinecekTreeNode = alt_TreeNode;

    if (alt_TreeNode->getSag() == NULL)
        alt_TreeNode = alt_TreeNode->getSol();
    else if (alt_TreeNode->getSol() == NULL)
        alt_TreeNode = alt_TreeNode->getSag();
    else 
    {
        silinecekTreeNode = alt_TreeNode->getSol();
        TreeNode* ebeveynTreeNode = alt_TreeNode;
        while (silinecekTreeNode->getSag() != NULL) 
        {
            ebeveynTreeNode = silinecekTreeNode;
            silinecekTreeNode = silinecekTreeNode->getSag();
        }
        alt_TreeNode->getKisi()->setIsim(silinecekTreeNode->getKisi()->getIsim());
        if (ebeveynTreeNode == alt_TreeNode)
            alt_TreeNode->setSol(silinecekTreeNode->getSol());
        else
            ebeveynTreeNode->setSag(silinecekTreeNode->getSol());
    }
    delete silinecekTreeNode;
    return true;
}

bool AVLTree::Ara(TreeNode* alt_TreeNode, string aranan) 
{
    if (alt_TreeNode == NULL)
        return false;
    if (alt_TreeNode->getKisi()->getIsim() == aranan)
        return true;
    if (aranan < alt_TreeNode->getKisi()->getIsim())
        return Ara(alt_TreeNode->getSol(), aranan);
    if (aranan > alt_TreeNode->getKisi()->getIsim())
        return Ara(alt_TreeNode->getSag(), aranan);
}

// Dugumun derinligi hesaplanır
void AVLTree::derinlikHesapla(TreeNode* alt_TreeNode, int derinlik)
{
    if (alt_TreeNode != NULL) 
    {
        if(alt_TreeNode->getDerinlik() == -1)
            ;
        else if(derinlik < alt_TreeNode->getDerinlik())
            alt_TreeNode->getYigit()->insert('Y');
        else if(derinlik > alt_TreeNode->getDerinlik())
            alt_TreeNode->getYigit()->insert('A');
        else
            alt_TreeNode->getYigit()->insert('D');

        alt_TreeNode->setDerinlik(derinlik);
        derinlikHesapla(alt_TreeNode->getSol(), derinlik+1);
        derinlikHesapla(alt_TreeNode->getSag(), derinlik+1);
    }
}
// Kurucu fonksiyon
AVLTree::AVLTree() 
{
    root = NULL;
}
// agacın boş olup olmadığını hesaplama
bool AVLTree::Bosmu() 
{
    return root == NULL;
}

void AVLTree::Ekle(string yeni, int dogumYili, int kilo,int yas)
{
    root = AraveEkle(root, yeni, dogumYili, kilo,yas);
    derinlikHesapla(root, 0);
}
// ağacı  ekrana bastırır
void AVLTree::Postorder() 
{
    Postorder(root);
}

bool AVLTree::Arama(string aranan) 
{
    return Ara(root, aranan);
}

void AVLTree::Temizle() 
{
    while (!Bosmu()) TreeNodeSil(root);
}

int AVLTree::Yukseklik()
{
    return Yukseklik(root);
}
// Avl temizlenir
AVLTree::~AVLTree() 
{
    Temizle();
}
