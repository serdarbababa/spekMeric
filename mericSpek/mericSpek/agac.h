#pragma once
#include "Dugum.h"
#include <iostream>
#define MARKER '#'

using namespace std;

class Agac
{
public:
	Agac(void );
	~Agac(void);
    
	void agacYarat();
	void dalEkle(data_tipi * veriler, int derinlik );
	void dugumEkle(data_tipi *deger,int derinlik, Dugum * nod);
	void dugumEkleFarkli(data_tipi *deger,int derinlik, Dugum * nod);
	
    //gosterim
    
	void Postorder();
	void Preorder();

    //tree saving ops
	void save();
	void open();
	void serialize(Dugum* nod, FILE *fp);
	void deSerialize(Dugum *&nod, FILE *fp);

private:
	Dugum * root;
    int neighbour ;
    void Postorder(Dugum * nod);
    void Preorder(Dugum* nod);
    void Preorder1(Dugum* nod);
};

