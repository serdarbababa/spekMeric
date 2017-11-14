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
    static int komsuluk;
    
public:
    //functions, constructors, destructures
    Dugum( );
    Dugum(data_tipi deger);
    ~Dugum();
    
    data_tipi getDeger();
    Dugum * getParent();
    
    int addChild(data_tipi, int option);
    int buildChild(int id, data_tipi, int option);
    
    void setIDMax(int id);
    void setID(int id);
    
    void visited();
    int getChildrenCount();
    Dugum * getChildAt(int index);
    char * toString();
    int getId(){
        return id;
    }
    int getDugumPosition(data_tipi veri, int option);
    int getDugumCount(){
        return idCount;
    }
    int getUzerindenGecme(){
        return uzerindenGecme;
    }
};

