#pragma once
#include "dugum.h"
#include <iostream>
#define MARKER '#'

using namespace std;

class agac
{
public:
	agac(void );
	~agac(void);
    
	void agacYarat();
	void dalEkle(data_tipi * veriler, int derinlik );
	void dugumEkle(data_tipi *deger,int derinlik, dugum * nod);
	void dugumEkleFarkli(data_tipi *deger,int derinlik, dugum * nod);
	
    //gosterim
    
	void Postorder();
	void Preorder();

    //tree saving ops
	void save();
	void open();
	void serialize(dugum* nod, FILE *fp);
	void deSerialize(dugum *&nod, FILE *fp);

private:
	dugum * root;
    int neighbour ;
    void Postorder(dugum * nod);
    void Preorder(dugum* nod);
    void Preorder1(dugum* nod);
};

