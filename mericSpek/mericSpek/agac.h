#pragma once
#include "Dugum.h"
#include <stdio.h>
#include <iostream>
#define MARKER "#"

using namespace std;

class Agac
{
public:
    static int leaf_id_counter;
    
	Agac(void );
	~Agac(void);
    
	//void agacYarat();
    
    /* dal eklemek icin dugum ekle cagiriliyor*/
	void dalEkle(data_tipi * veriler, int derinlik, int option );
	
    /*gosterim*/
	void Postorder();
	void Preorder();

    /* agaci dosyaya kaydetme ve okuma(geri getirme)*/
    
    //save binary by calling serializeB. It opens and closes file
    int saveB(char * filename);
    //restore binary file to tree
    int openB(char *filename);
    
    //agaci text dosyasina yazarak kaydediyor
	int save(char * filename);
	
    //opening
    int open(char * filename);
    //int open1(char * filename);
    
    //keeping track of the leafs
    void registerLeafs();
    
    int dalIdGetir(data_tipi * veriler, int derinlik, int option);
    
    /* dal getir */
    int dalGetir(int yaprakId, data_tipi **deger,int derinlik);
    
    /*  */
    void brief_summary(){
        cout<<"toplam dugum sayisi = "<<root->getDugumCount()<<endl;
        cout<< "leaf count = " << leaf_id_counter<<endl;
    }
    
    void summarize(){
        cout<<"toplam dugum sayisi = "<<root->getDugumCount()<<endl;
        for(int i=0;i<root->getChildrenCount();i++)
            cout<<"cocuk "<<i<< ", id ="<< root->getChildAt(i)->getId()<<", deger="<< root->getChildAt(i)->getDeger() <<", count ="<< root->getChildAt(i)->getUzerindenGecme()<<endl;
    }
    
    /*void setAgacDepth(int depth){
        this->depth = depth;
    }
    
    int getAgacDepth(){
        return this->depth;
    }
    */
    
private:
	Dugum * root;
    vector<Dugum *> *yapraklar;
    //int depth;
    
    
    /*dal eklemek icin dugum ekler*/
    void dugumEkle(data_tipi *deger,int derinlik, Dugum * nod, int option);
    
    /*dal id bulmak icin */
    int dalBul(data_tipi *deger,int derinlik, Dugum * nod, int option);
    
    
    /* agaci binary dosyaya yazar*/
    void serializeB(Dugum* nod, std::ofstream *fp);
    /* agaci text dosyaya yazar*/
    void serialize(Dugum* nod, FILE *fp);
    
    
    void doRegisterLeaf(Dugum *nod);
    
    //int neighbour ;
    
    void Postorder(Dugum * nod);
    void Preorder(Dugum* nod);
    void Preorder1(Dugum* nod);
};

