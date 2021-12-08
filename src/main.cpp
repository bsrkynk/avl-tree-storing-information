#include <iostream>
#include <fstream>
#include <sstream>

#include "AVLTree.hpp"
#include "AVLTree.hpp"

using namespace std;

int main()
{
    AVLTree avlTree;
    ifstream inputFile; // dosya olusturulur
    inputFile.open("Kisiler.txt"); // dosya acilir
    string line;
    
    while(getline(inputFile, line)) // dosya okuma
    {
        stringstream ss(line);
        string isim, dYili, kg;
        int dogumYili, kilo,yas;
        getline(ss, isim, '#');
        getline(ss, dYili, '#');
        getline(ss, kg);

        std::stringstream convert;
    	convert << dYili;
    	convert >> dogumYili;
    	convert.str("");
    	convert.clear();
    	convert << kg;
    	convert >> kilo;

        yas = 2020 - dogumYili;
        avlTree.Ekle(isim, dogumYili, kilo,yas);
    }

    inputFile.close();

    avlTree.Postorder(); // Ekrana agac dugumleri bastirilir
    
    getchar();

    return 0;
}
