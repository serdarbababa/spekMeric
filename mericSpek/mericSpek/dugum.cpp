#include "Dugum.h"

int Dugum::idCount=0;
int Dugum::komsuluk=5;

Dugum::Dugum( )
{
	this->parent=NULL;
	this->children=new vector<Dugum *>;
	uzerindenGecme=0;
    this->id=idCount++;
    depth=0;
}

Dugum::Dugum(data_tipi deger)
{
	this->deger = deger;
	this->parent=NULL;
	this->children=new vector<Dugum *>;
    this->id=idCount++;
	uzerindenGecme=0;
    depth=0;
}

Dugum::~Dugum()
{
}

data_tipi Dugum::getDeger(){
    return deger;
}

Dugum * Dugum::getParent(){
    return parent;
}

Dugum * Dugum::getChildAt(int index){
    return children->at(index);
}

void Dugum::visited(){
    this->uzerindenGecme++;
}

int Dugum::addChild(data_tipi data, int option){
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
        //cocugu var ise
        if (children->size() >0){
            //cocugu ekleyecek yeri belirle
            for (int j = 0; j < children->size(); j++){
                if (abs(children->at(j)->deger - data)<= komsuluk){
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
    if(willBeInserted){
        Dugum * n = new Dugum(data);
        n->parent = this;
        n->children= new vector<Dugum *>;
        n->depth= this->depth+1;
    
        this->children->insert(children->begin()+insertedChildIndex, n);
    }
    
    this->uzerindenGecme++;
    return insertedChildIndex;
}



int Dugum::getChildLocation(data_tipi data, int option){
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
        //cocugu var ise
        if (children->size() >0){
            //cocugu ekleyecek yeri belirle
            for (int j = 0; j < children->size(); j++){
                if (abs(children->at(j)->deger - data)<= komsuluk){
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
    if(willBeInserted)
        return -2;
    else
        return insertedChildIndex;
}


int Dugum::buildChild(int id, data_tipi data, int option){
    bool willBeInserted = true;
    int insertedChildIndex = 0;
    
    
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
    if(willBeInserted){
        Dugum * n = new Dugum(data);
        n->parent = this;
        n->children= new vector<Dugum *>;
        n->depth= this->depth+1;
        n->id=id;
        this->children->insert(children->begin()+insertedChildIndex, n);
        //Dugum::idCount++;
        
    }
    return insertedChildIndex;
        
    return 0;
    
}

//sets the id count = 0 for root
void Dugum::setIDMax(int idi){
    //idCount=++idi;
    this->id=0;
}

void Dugum::setID(int idi){
    //idCount=++idi;
    this->id=idi;
}

int Dugum::getChildrenCount(){
    return (int)children->size();
}

char * Dugum::toString(){
    char * cikti = new char[100];
    for(int i = 0 ; i < depth; i++)
        sprintf(cikti,"%s\t",cikti);
    //sprintf(cikti,"%snode (%d) %d %d",cikti, id,deger,uzerindenGecme);
    sprintf(cikti,"%s%d (%d) %d",cikti,deger,uzerindenGecme,id);
    return cikti;
}

int Dugum::getDugumPosition(data_tipi veri, int option){
    int position = -999;
    for(int i = 0 ; i < this->children->size(); i++){
        if(this->children->at(i)->deger==deger && option == 1){
            position=i;
            break;
        }
        else if(abs( this->children->at(i)->deger-veri)<=komsuluk && option == 2){
            position=i;
            break;
        }
        
    }
    return position;
}

