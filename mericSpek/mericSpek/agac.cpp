#include "Agac.h"

int Agac::leaf_id_counter=0;
Agac::Agac(){
	root=NULL;
    //neighbour=5;
}

Agac::~Agac(void){
}

/*
void Agac::agacYarat(){
	root = NULL;
    //neighbour=5;
}
 */

void Agac::dalEkle(data_tipi * veriler, int derinligi, int option){
	
    if(root==NULL){
		root = new Dugum(-9999);
	}	
	dugumEkle(veriler, derinligi,this->root, option);
}

void Agac::dugumEkle(data_tipi *veriler, int derinlik, Dugum *nod, int option){
    int insertedChildIndex = nod->addChild(veriler[0], option);
	//cout << insertedChildIndex << endl;
    if(derinlik ==1){
        nod->getChildAt(insertedChildIndex)->visited();
        return;
    }
	else
		dugumEkle(veriler+1,derinlik-1,nod->getChildAt(insertedChildIndex), option);
}

int Agac::dalGetir(int yaprakId, data_tipi **deger , int derinlik){
    (*deger)=new data_tipi[derinlik];
    Dugum *d = yapraklar->at(yaprakId);
    for(int i =derinlik- 1;i >= 0 && d!=NULL ; i--){
        (*deger)[i]=d->getDeger();
        d=d->getParent();
    }
    return 0;
}

void Agac::Postorder(Dugum * nod)
{
	if (nod != NULL)
	{
		for (int i = 0; i < nod->getChildrenCount(); i++)
			Postorder(nod->getChildAt(i));

		cout << nod->getDeger() << endl;

	}
}

void Agac::Preorder(Dugum* nod)
{
	if (nod)
	{
		cout << nod->toString() << endl;
        
		for (int i = 0; i < nod->getChildrenCount(); i++)
			Preorder(nod->getChildAt(i));
		if (nod->getChildrenCount()==0)
			cout << endl;

	}
	
}


void Agac::Preorder1(Dugum* nod)
{
	if (nod)
	{
		cout << nod->getDeger() << " ";
		int count = 0 ;
		Dugum *tempN = nod->getParent();
		while( tempN){
			count++;
			tempN=tempN->getParent();
		}
		cout <<"seviye " << count << endl;
		for (int i = 0; i < nod->getChildrenCount(); i++)
			Preorder(nod->getChildAt(i));

	}
}

void Agac::Postorder(){
	Postorder(this->root);
}

void Agac::Preorder(){
		Preorder(this->root);
	}

int Agac::save(char * filename){


	FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Could not open file");
        return -1;
    }
    serialize(root, fp);
    fclose(fp);
    return 0;
}

void Agac::serialize(Dugum* nod, FILE *fp){
	// If current node is NULL, store marker
	if (nod->getChildrenCount() == 0 )
    {
		fprintf(fp, "%d\n", nod->getDeger());
        fprintf(fp, "%s\n", MARKER);
        return;
    }
 
    // Else, store current node and recur for its children
	fprintf(fp, "%d\n", nod->getDeger());
	for (int i = 0; i < nod->getChildrenCount(); i++)
		serialize(nod->getChildAt(i),fp);
	//if (nod->children->size()==0)
	//		cout << endl;
    fprintf(fp, "%s\n", MARKER);
}


int Agac::open(char * filename){
    ifstream in(filename);
    
    if(!in) {
        //cout << "Cannot open input file.\n";
        return -1;
    }
    Dugum * nod;
    char str[255];
    
    if(root==NULL){
        root = new Dugum(-9999);
    }
    
    bool rootInserted = false;
    
    while(in) {
        in.getline(str, 255);  // delim defaults to '\n'
        if(in) {
            if(strcmp(str,MARKER)==0)
                nod= nod->getParent() ;
            else if(!rootInserted && atoi(str) ==-9999){
                nod=root;
                rootInserted=true;
            }
            else {
                int newNod = nod->addChild(atoi(str), 0);
                nod = nod->getChildAt(newNod);
                
            }
            
            
        }
    }
    
    in.close();
    
    return 0;
}
/*
int Agac::open1(char * filename){
	if(root==NULL){		
		root = new Dugum(-9999);
	}	
	
    FILE *fp = fopen(filename, "r");
    // item is marker, then return
    int val;
	bool rootInserted = true;
	//this->AgacYarat();

    Dugum * nod=root;
    while ( fscanf(fp, "%d ", &val) ){
		if(rootInserted && val ==-9999)
            nod=root;
		//	rootInserted=false;
		else if(val != atoi(MARKER)){
        //else if(val != MARKER){
            int newNod = nod->addChild(val, 1);
            nod = nod->getChildAt(newNod);
            
		}
        else{
            nod= nod->getParent();
        }
	}
       
 
    // Else create node with this item and recur for children
    

	fclose(fp);
    return 0;
}
*/
int Agac::saveB(char * filename){
    std::ofstream *fp=new std::ofstream();
    fp->open(filename, std::ios::binary);
    if(!fp) {
        //cout << "Cannot open input file.\n";
        return -1;
    }
    serializeB(root, fp);
    (*fp).close();
    return 0;
}


void Agac::serializeB(Dugum* nod, std::ofstream *fp){
    // If current node is NULL, store marker
    data_tipi data ;
    int id ;
    if (nod->getChildrenCount() == 0 )
    {
        data = nod->getDeger();
        id = nod->getId();
        fp->write((char*) &data, sizeof(data_tipi));
        fp->write((char*) &id, sizeof(int));
        
        data = 0;
        id=0;
        fp->write((char*) &data, sizeof(data_tipi));
        fp->write((char*) &id, sizeof(int));
        
        //fprintf(fp, "%d\n", nod->getDeger());
        //fprintf(fp, "%s\n", MARKER);
        return;
    }
    
    // Else, store current node and recur for its children
    data = nod->getDeger();
    id = nod->getId();
    fp->write((char*) &data, sizeof(data_tipi));
    fp->write((char*) &id, sizeof(int));
    
    for (int i = 0; i < nod->getChildrenCount(); i++)
        serializeB(nod->getChildAt(i),fp);
    data = 0;
    id=0;
    fp->write((char*) &data, sizeof(data_tipi));
    fp->write((char*) &id, sizeof(int));
}



int Agac::openB(char * filename){
    FILE* in = fopen(filename, "rb");
    
    if(!in) {
        //cout << "Cannot open input file.\n";
        return -1;
    }
    Dugum * nod;
    int idMax=-1;
    bool rootInserted = false;
    if(root==NULL){
        root = new Dugum(-9999);
        //nod=root;
    }
    while(!feof(in))
    {
        int id=0;
        data_tipi deger=0;
    
        fread(&deger, sizeof(data_tipi), 1, in);
        fread(&id, sizeof(int), 1, in);
        if(idMax<id)
            idMax=id;
        
        if(id==0 && deger==0){
            if(nod==NULL)
                 break;
            nod= nod->getParent() ;
        }
        else if(!rootInserted && deger ==-9999){
            nod=root;
            rootInserted=true;
        }
        else {
            int newNod = nod->buildChild(id,deger, 0);
            nod = nod->getChildAt(newNod);
            
        }

    }
    fclose(in);
    
    //only for root, set the id =0
    root->setIDMax(idMax);
    
    /*ifstream in;
    in.open(filename, ios::in | ios::binary);
    
    if(!in) {
        //cout << "Cannot open input file.\n";
        return -1;
    }
    
    Dugum * nod;
    char str[255];
    
    if(root==NULL){
        root = new Dugum(-9999);
    }
    
    bool rootInserted = false;
    
    while(in) {
        int id=0;
        data_tipi deger=0;
        in.read(&deger, sizeof(data_tipi));
        in.read(&id,sizeof(int));
        
        /*
        in.getline(str, 255);  // delim defaults to '\n'
        if(in) {
            if(strcmp(str,MARKER)==0)
                nod= nod->getParent() ;
            else if(!rootInserted && atoi(str) ==-9999){
                nod=root;
                rootInserted=true;
            }
            else {
                int newNod = nod->addChild(atoi(str), 0);
                nod = nod->getChildAt(newNod);
                
            }
          *
            
        }
    }
    
    in.close();
    */
    return 0;
}


void Agac::registerLeafs(){
    Agac::leaf_id_counter=1;
    this->yapraklar = new vector<Dugum *>;
    doRegisterLeaf(this->root);
}

void Agac::doRegisterLeaf(Dugum *nod){
    if (nod != NULL){
        if(nod->getChildrenCount()==0){
            
            nod->setID( Agac::leaf_id_counter++);
            this->yapraklar->insert(yapraklar->end(),nod);
            //Agac::leaf_id_counter= Agac::leaf_id_counter+1;
        }
        else{
            nod->setID( -1);
            for (int i = 0; i < nod->getChildrenCount(); i++){
                doRegisterLeaf(nod->getChildAt(i));
            }
        }
        //cout << nod->getDeger() << endl;
        
    }

}


int Agac::dalIdGetir(data_tipi *veriler, int derinlik, int option){
    if(root==NULL){
        return -999;
    }
    return dalBul(veriler, derinlik, this->root, option);
}


int Agac::dalBul(data_tipi *veriler, int derinlik, Dugum *nod, int option){
    int childIndex = nod->getChildLocation(veriler[0], option);
    if(childIndex == -2)
        for(int i = 0 ; i < derinlik; i++)
            cout << veriler[i]<<"\t";
        //cout << childIndex << endl;
    nod->getChildLocation(veriler[0], option);
    if(derinlik ==1){
        nod->getChildAt(childIndex)->visited();
        int temp = nod->getChildAt(childIndex)->getId();
        return temp;
        
    }
    else{
        int temp =  dalBul(veriler+1,derinlik-1,nod->getChildAt(childIndex), option);
        return temp;
    }
}











