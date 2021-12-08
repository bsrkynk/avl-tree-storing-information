#include "Kisi.hpp"

Kisi::Kisi(string isim, int dogumYili, int kilo,int yas)
{
	this->isim = isim;
	this->dogumYili = dogumYili;
	this->kilo = kilo;
	this->yas = yas;
}

string Kisi::getIsim()
{
	return isim;
}

void Kisi::setIsim(string isim)
{
	this->isim = isim;
}

int Kisi::getDogumYili()
{
	return dogumYili;
}

void Kisi::setDogumYili(int dogumYili)
{
	this->dogumYili = dogumYili;

}

int Kisi::getKilo()
{
	return kilo;
}

void Kisi::setKilo(int kilo)
{
	this->kilo = kilo;
}
int Kisi::getYas()
{
	return yas;
}

void Kisi::setYas(int yas)
{
	this->yas = yas;
}
