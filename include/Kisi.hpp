#ifndef KISI_HPP
#define KISI_HPP

#include <iostream>

using namespace std;

class Kisi
{
public:
    Kisi(string isim, int dogumYili, int kilo,int yas);
    string getIsim();
	void setIsim(string isim);
	int getDogumYili();
	void setDogumYili(int dogumYili);
	int getKilo();
	void setKilo(int kilo);
	int getYas();
	void setYas(int yas);
private:
	string isim;
	int dogumYili;
	int kilo;
	int yas;
};

#endif