#pragma once
#include "Utility.h"


using namespace std;
//using  data_tipi = int;


class Dugum
{

private:
    //id info
    static int idCount;
    //data structure
    int id;
    data_tipi deger;
    Dugum * parent;
    int uzerindenGecme;
    vector <Dugum*> *children;
    int depth;
    
public:
    //functions, constructors, destructures
    Dugum( );
    Dugum(data_tipi deger);
    ~Dugum();
    
    data_tipi getDeger();
    Dugum * getParent();
    int addChild(data_tipi, int option);
    void visited();
    int getChildrenCount();
    Dugum * getChildAt(int index);
    char * toString();
};

