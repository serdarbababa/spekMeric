#include "dugum.h"

dugum::dugum( )
{
	this->parent=NULL;
	this->children=new vector<dugum *>;
	uzerindenGecme=0;
}
dugum::dugum(int deger)
{
	this->deger = deger;
	this->parent=NULL;
	this->children=new vector<dugum *>;
	uzerindenGecme=0;
}


dugum::~dugum()
{
}

void dugum::addChild(data_tipi data){
	dugum * n = new dugum(data);				
	n->parent = this;						
	n->children= new vector<dugum *>;
	
	this->children->push_back(n);
}