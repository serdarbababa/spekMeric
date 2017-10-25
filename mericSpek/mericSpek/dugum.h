#pragma once
#include "Utility.h"


using namespace std;
//using  data_tipi = int;


class dugum
{

private:
    //id info
    static int idCount;
    //data structure
    int id;
    data_tipi deger;
    dugum * parent;
    int uzerindenGecme;
    vector <dugum*> *children;
    int depth;
    
public:
    //functions, constructors, destructures
    dugum( );
    dugum(data_tipi deger);
    ~dugum();
    
    int addChild(data_tipi, int option);
    void visited();
    int getChildrenCount();
    char * toString();
};

