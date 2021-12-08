#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <cmath>
#include <iostream>

#include "TreeNode.hpp"

using namespace std;

class AVLTree 
{
private:
	TreeNode* root; //Ağacın kök düğümünü işaret eden pointer.
	TreeNode* AraveEkle(TreeNode* alt_TreeNode, string yeni, int dogumYili, int kilo,int yas);
	TreeNode* SolCocukIleDegistir(TreeNode* alt_TreeNode); //Sol çocuk ile değişim yapan metot.
	TreeNode* SagCocukIleDegistir(TreeNode* alt_TreeNode); //Sağ çocuk ile değişim yapan metot.
	void Postorder(TreeNode* alt_TreeNode) ;
	int Yukseklik(TreeNode* alt_TreeNode) ;
	bool TreeNodeSil(TreeNode*& alt_TreeNode); //alt_TreeNode silen metot.
	bool Ara(TreeNode* alt_TreeNode, string aranan);//alt_TreeNode köküne sahip alt ağaç içinde aranan isimli kişiyi içeren düğümü arayan metot.
	void derinlikHesapla(TreeNode* alt_TreeNode, int derinlik);//Düğümlerin derinliklerini hesaplayıp, yığıtlara gerekli harfi ekleyen metot.

public:
	AVLTree(); //AVLTree sınıfının yapıcı metotu.
	bool Bosmu() ; //Ağacın boş olup olmadığını kontrol eden metot.
	void Ekle(string yeni, int dogumYili, int kilo,int yas);
	void Postorder() ; //Ağacı postorder şekilde gezip, gereken bilgileri ekrana bastıran metot.
	bool Arama(string aranan); //Argüman olarak gelen ismi ağaçta arayan metot.
	void Temizle(); //Ağacı temizleyen metot.
	int Yukseklik() ; //Ağacın yüksekliğini hesaplayıp geri döndüren metot.
	~AVLTree(); //AVLTree sınıfının yıkıcı metotu.
};

#endif