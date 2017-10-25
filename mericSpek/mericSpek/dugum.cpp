#include "dugum.h"

int dugum::idCount=0;

dugum::dugum( )
{
	this->parent=NULL;
	this->children=new vector<dugum *>;
	uzerindenGecme=0;
    this->id=idCount++;
    depth=0;
}
dugum::dugum(int deger)
{
	this->deger = deger;
	this->parent=NULL;
	this->children=new vector<dugum *>;
    this->id=idCount++;
	uzerindenGecme=0;
    depth=0;
}


dugum::~dugum()
{
}

int dugum::addChild(data_tipi data, int option){
    bool willBeInserted = true;
    int insertedChildIndex = -1;
    
    if(option ==1){
        
        //cocugu var ise
        if (children->size() >0){
            //cocugu ekleyecek yeri belirle
            for (int j = 0; j < nod->children->size(); j++){
                if (children->at(j)->deger == data){
                    insertedChildIndex = j;
                    willBeInserted=false;
                }
                else if (children->at(j)->deger > data){
                    
                    dugum * n = new dugum(data);
                    children->insert( nod->children->begin() + j,n ); //->insert(it + i, n);
                    n->parent = nod;
                    insertedChildIndex =j;
                    break;
                    
                }
            }
        }
        if(insertedChildIndex < 0 && willBeInserted){
            nod->addChild(veriler[0]);
            insertedChildIndex = (int) nod->children->size()-1;
        }
    }
    else if(option ==2){
        
    }
    
    this->uzerindenGecme++;
    dugum * n = new dugum(data);
	n->parent = this;						
	n->children= new vector<dugum *>;
    n->depth= this->depth+1;
    
	this->children->push_back(n);
    
    return insertedChildIndex;
}

int dugum::getChildrenCount(){
    return (int)children->size();
}

char * dugum::toString(){
    char * cikti = new char[100];
    for(int i = 0 ; i < depth; i++)
        sprintf(cikti,"%s\t",cikti);
    sprintf(cikti,"%snode (%d) %d %d",cikti, id,deger,uzerindenGecme);
    return cikti;
}
