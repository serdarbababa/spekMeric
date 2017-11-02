#pragma once
#include "Dugum.h"
#include <stdio.h>
#include <iostream>
#define MARKER "#"

using namespace std;

class Agac
{
public:
	Agac(void );
	~Agac(void);
    
    
	void agacYarat();
	void dalEkle(data_tipi * veriler, int derinlik, int option );
	void dugumEkle(data_tipi *deger,int derinlik, Dugum * nod, int option);
	
	
    //gosterim
    
	void Postorder();
	void Preorder();

    //tree saving ops
    //save binary
    int saveB(char * filename);
    void serializeB(Dugum* nod, std::ofstream *fp);
    //open binary
    int openB(char *filename);
    //save
	int save(char * filename);
	void serialize(Dugum* nod, FILE *fp);
    //opening
    int open(char * filename);
    int open1(char * filename);
    
    //keeping track of the leafs
    void registerLeafs();
    Dugum * getLeaf(int idLeaf);
    int * getBranch(int idLeaf);

    void summarize(){
        cout<<"toplam dugum sayisi = "<<root->getDugumCount()<<endl;
        for(int i=0;i<root->getChildrenCount();i++)
            cout<<"cocuk "<<i<< ", id ="<< root->getChildAt(i)->getId()<<", deger="<< root->getChildAt(i)->getDeger() <<", count ="<< root->getChildAt(i)->getUzerindenGecme()<<endl;
    }
private:
	Dugum * root;
    vector<Dugum *> leafs;
    //int neighbour ;
    
    void Postorder(Dugum * nod);
    void Preorder(Dugum* nod);
    void Preorder1(Dugum* nod);
};

