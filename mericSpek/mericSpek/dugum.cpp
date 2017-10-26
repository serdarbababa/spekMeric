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

data_tipi dugum::getDeger(){
    return deger;
}

dugum * dugum::getParent(){
    return parent;
}

dugum * dugum::getChildAt(int index){
    return children->at(index);
}

void dugum::visited(){
    uzerindenGecme++;
}
int dugum::addChild(data_tipi data, int option){
    bool willBeInserted = true;
    int insertedChildIndex = 0;
    
    if(option ==1){
        
        //cocugu var ise
        if (children->size() >0){
            //cocugu ekleyecek yeri belirle
            for (int j = 0; j < children->size(); j++){
                if (children->at(j)->deger == data){
                    insertedChildIndex = j;
                    willBeInserted=false;
                    break;
                }
                else if (children->at(j)->deger > data){
                    insertedChildIndex =j;
                    break;
                }
                else
                    insertedChildIndex++;
            }
        }
        else{
            willBeInserted=true;
            insertedChildIndex=0;
        }
        
    }
    else if(option ==2){
        
    }
    if(willBeInserted){
        dugum * n = new dugum(data);
        n->parent = this;
        n->children= new vector<dugum *>;
        n->depth= this->depth+1;
    
        this->children->insert(children->begin()+insertedChildIndex, n);
    }
    this->uzerindenGecme++;
    return insertedChildIndex;
}

int dugum::getChildrenCount(){
    return (int)children->size();
}

char * dugum::toString(){
    char * cikti = new char[100];
    for(int i = 0 ; i < depth; i++)
        sprintf(cikti,"%s\t",cikti);
    //sprintf(cikti,"%snode (%d) %d %d",cikti, id,deger,uzerindenGecme);
    sprintf(cikti,"%s%d (%d)",cikti,deger,uzerindenGecme);
    return cikti;
}
