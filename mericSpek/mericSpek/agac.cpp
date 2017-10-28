#include "Agac.h"


Agac::Agac(){
	root=NULL;
    neighbour=5;
}

Agac::~Agac(void){
}

void Agac::agacYarat(){
	root = NULL;
    neighbour=5;
}

void Agac::dalEkle(data_tipi * veriler, int derinligi){
	if(root==NULL){
		root = new Dugum(-9999);
	}	
	dugumEkle(veriler, derinligi,this->root);
}

void Agac::dugumEkle(data_tipi *veriler, int derinlik, Dugum *nod){
    int insertedChildIndex = nod->addChild(veriler[0], 1);
	//cout << insertedChildIndex << endl;
    if(derinlik ==1){
        nod->getChildAt(insertedChildIndex)->visited();
        return;
    }
	else
		dugumEkle(veriler+1,derinlik-1,nod->getChildAt(insertedChildIndex));
}
/*
void Agac::dugumEkleFarkli(data_tipi *veriler, int derinlik, dugum *nod){
	
	bool willBeInserted = true;
	int insertedChildIndex = -1;

	if (nod->children->size() >0){		
		for (int j = 0; j < nod->children->size(); j++){
			if ( abs( veriler[0]-nod->children->at(j)->deger) <neighbour ){
				insertedChildIndex = j;
				willBeInserted=false;
				//cout << "dugum atlandi "<<endl;

			}
			else if (nod->children->at(j)->deger > veriler[0]  && willBeInserted ){
				
				dugum * n = new dugum(veriler[0]);				
				nod->children->insert( nod->children->begin() + j,n ); //->insert(it + i, n);
				n->parent = nod;				
				insertedChildIndex =j;

				break;

			}
		}
	}
	if(insertedChildIndex < 0 && willBeInserted){
		nod->addChild(veriler[0]);
		insertedChildIndex = (int)nod->children->size()-1;
	}
	//cout << insertedChildIndex << endl;
	if(derinlik ==1)
		return;
	else
		dugumEkleFarkli(veriler+1,derinlik-1,nod->children->at(insertedChildIndex));
}
*/

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

void Agac::save(){


	FILE *fp = fopen("tree.txt", "w");
    if (fp == NULL)
    {
        printf("Could not open file");
        return ;
    }
    serialize(root, fp);
    fclose(fp);


}

void Agac::serialize(Dugum* nod, FILE *fp){
	// If current node is NULL, store marker
	if (nod->getChildrenCount() == 0 )
    {
		fprintf(fp, "%d ", nod->getDeger());
        fprintf(fp, "\n%c ", MARKER);
        return;
    }
 
    // Else, store current node and recur for its children
	fprintf(fp, "%d ", nod->getDeger());
	for (int i = 0; i < nod->getChildrenCount(); i++)
		serialize(nod->getChildAt(i),fp);
	//if (nod->children->size()==0)
	//		cout << endl;
    fprintf(fp, "%c ", MARKER);
    


}


void Agac::open(){
	if(root==NULL){		
		root = new Dugum(-9999);
	}	
	
    FILE *fp = fopen("tree.txt", "r");
    // item is marker, then return
    int val;
	bool rootInserted = true;
	//this->AgacYarat();

    while ( fscanf(fp, "%d ", &val) ){
		if(rootInserted && val ==-9999)
			rootInserted=false;
		if(val != MARKER){
		}
	}
       
 
    // Else create node with this item and recur for children
    

	fclose(fp);
}

/*
//void open(){
//	if(root==NULL){		
//		root = new Dugum(-9999);
//	}	
//	
//    FILE *fp = fopen("tree.txt", "r");
//    deSerialize(root, fp);
//	
//	int val;
//
//	if ( !fscanf(fp, "%d ", &val) || val == MARKER)
//       return;
//
//	fclose(fp);
//}
*/
 
void Agac::deSerialize(Dugum *&nod, FILE *fp)
{
    // Read next item from file. If theere are no more items or next
    // item is marker, then return
    int val;
    if ( !fscanf(fp, "%d ", &val) || val == MARKER)
       return;
 
    // Else create node with this item and recur for children
    root = new Dugum(val);
    //deSerialize(root->left, fp);
    //deSerialize(root->right, fp);


}
