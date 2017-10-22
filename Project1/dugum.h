#pragma once
#include "Utility.h"


using namespace std;
//using  data_tipi = double;


class dugum
{
public:
	dugum::dugum( );
	dugum(int deger);
	~dugum();
	void addChild(data_tipi);
public:
	data_tipi deger;
	dugum * parent;
	int uzerindenGecme;
	vector <dugum*> *children;

};

