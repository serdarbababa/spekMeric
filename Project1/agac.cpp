#include "agac.h"


agac::agac()
{
	//this->derinlik = derin;
	root=NULL;
	neighbour=20;
}


agac::~agac(void)
{
}

void agac::agacYarat(){	
	root = NULL;
	neighbour=20;
	//create layers
	/*layers = *(new vector<vector <dugum *>>);

	for (int i = 0 ; i < this->derinlik;i++){
	vector < dugum *> katman1;
	katman1= *(new vector<dugum* >);
	layers->push_back(katman1);
	}*/
}

void agac::dalEkle(data_tipi * veriler, int derinligi){

	if(root==NULL){		
		root = new dugum(-9999);
	}	
	dugumEkleFarkli(veriler, derinligi,this->root);

	//int prevInserted = -1;
	//for(int i=0; i < derinlik;i++){
	//	dugum * n = new dugum();
	//	n->deger = veriler[i];
	//	if(prevInserted ==-1)
	//		n->parent = NULL;
	//	else
	//		n->parent= prevInserted;
	//	n->children= NULL;
	//	bool inserted = false;
	//	
	//	if(katman->at(i).size() ==0){
	//		katman->at(i).push_back(n);		
	//	}
	//	else (katman->at(i).size() >0){		
	//		for (int j = 0; j < katman->at(i).size(); j++){
	//			if (katman->at(i).at(j)->deger > n->deger)	{
	//				{
	//					katman->insert(katman->begin() + j, n); //->insert(it + i, n);
	//					inserted = true;
	//					break;
	//				}
	//			}
	//		}
	//	}
	//	
	//		

	//}
}

void agac::dugumEkle(data_tipi *veriler, int derinlik, dugum *nod){
	
	bool willBeInserted = true;
	int insertedChildIndex = -1;
	//cocugu var ise
	if (nod->children->size() >0){		
		//cocugu ekleyecek yeri belirle
		for (int j = 0; j < nod->children->size(); j++){
			if (nod->children->at(j)->deger == veriler[0]){
				insertedChildIndex = j;
				willBeInserted=false;
			}
			else if (nod->children->at(j)->deger > veriler[0]){
				
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
		insertedChildIndex = nod->children->size()-1;
	}
	//cout << insertedChildIndex << endl;
	if(derinlik ==1)
		return;
	else
		dugumEkle(veriler+1,derinlik-1,nod->children->at(insertedChildIndex));
}

void agac::dugumEkleFarkli(data_tipi *veriler, int derinlik, dugum *nod){
	
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
		insertedChildIndex = nod->children->size()-1;
	}
	//cout << insertedChildIndex << endl;
	if(derinlik ==1)
		return;
	else
		dugumEkleFarkli(veriler+1,derinlik-1,nod->children->at(insertedChildIndex));
}


void agac::Postorder(dugum * nod)
{
	if (nod != NULL)
	{
		for (int i = 0; i < nod->children->size(); i++)
			Postorder(nod->children->at(i));

		cout << nod->deger << endl;

	}
}

void agac::Preorder(dugum* nod)
{
	if (nod)
	{
		cout << nod->deger << " ";
		for (int i = 0; i < nod->children->size(); i++)
			Preorder(nod->children->at(i));
		if (nod->children->size()==0)
			cout << endl;

	}
	
}


void agac::Preorder1(dugum* nod)
{
	if (nod)
	{
		cout << nod->deger << " ";
		int count = 0 ;
		dugum *tempN = nod->parent;
		while( tempN){
			count++;
			tempN=tempN->parent;
		}
		cout <<"seviye " << count << endl;
		for (int i = 0; i < nod->children->size(); i++)
			Preorder(nod->children->at(i));

	}
}

void agac::Postorder(){
	Postorder(this->root);
}
void agac::Preorder(){
		Preorder(this->root);
	}

void agac::save(){


	FILE *fp = fopen("tree.txt", "w");
    if (fp == NULL)
    {
        printf("Could not open file");
        return ;
    }
    serialize(root, fp);
    fclose(fp);


}

void agac::serialize(dugum* nod, FILE *fp){
	// If current node is NULL, store marker
	if (nod->children->size() == 0 )
    {
		fprintf(fp, "%d ", nod->deger);
        fprintf(fp, "\n%c ", MARKER);
        return;
    }
 
    // Else, store current node and recur for its children
	fprintf(fp, "%d ", nod->deger);
	for (int i = 0; i < nod->children->size(); i++)
		serialize(nod->children->at(i),fp);
	//if (nod->children->size()==0)
	//		cout << endl;
    fprintf(fp, "%c ", MARKER);
    


}


void agac::open(){
	if(root==NULL){		
		root = new dugum(-9999);
	}	
	
    FILE *fp = fopen("tree.txt", "r");
    // item is marker, then return
    int val;
	bool rootInserted = true;
	//this->agacYarat();

    while ( fscanf(fp, "%d ", &val) ){
		if(rootInserted && val ==-9999)
			rootInserted=false;
		if(val != MARKER){
		}
	}
       
 
    // Else create node with this item and recur for children
    

	fclose(fp);
}
//void open(){
//	if(root==NULL){		
//		root = new dugum(-9999);
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

void agac::deSerialize(dugum *&nod, FILE *fp)
{
    // Read next item from file. If theere are no more items or next
    // item is marker, then return
    int val;
    if ( !fscanf(fp, "%d ", &val) || val == MARKER)
       return;
 
    // Else create node with this item and recur for children
    root = new dugum(val);
    //deSerialize(root->left, fp);
    //deSerialize(root->right, fp);


}