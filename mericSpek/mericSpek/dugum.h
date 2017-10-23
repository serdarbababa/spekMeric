#pragma once
#include "Utility.h"


using namespace std;
//using  data_tipi = int;


class dugum
{
public:
	dugum( );
	dugum(data_tipi deger);
	~dugum();
	void addChild(data_tipi);
public:
	data_tipi deger;
	dugum * parent;
	int uzerindenGecme;
	vector <dugum*> *children;

};

