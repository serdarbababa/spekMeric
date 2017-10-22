#include "agac.h"
#include "Utility.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


#define boy  60
#define derinlik 3
#define oversample 4
void oku();
float sawFunc(float pos);
void readFilterCoefs();

int main(){	
	int windowSize =16;
	getchar();
	Utility * u = new Utility();
	char  filename [200]= "C:\\Users\\DELLWS1\\OneDrive\\spectron\\data\\test_mono_8000Hz_16bit_PCM.wav";

	readFilterCoefs();

	


	//u->readWav(filename);
	//for(int i = 0 ; i < 10; i++)
	//{
	//	cout << i << "\t";
	//	 for(int j = 0 ; j < windowSize-1 ;j++){
	//		 //cout <<" j = "<<j<< " "<< u->data[i*windowSize+j]<<"\t";
	//		 for (int k=0;k<oversample;k++)
	//			 cout << u->data[i*windowSize+j] + (k)*(u->data[i*windowSize+j+1]-u->data[i*windowSize+j])/oversample <<"\t";
	//	 }
	//	cout <<" son ="<< " "<< u->data[(i+1)*windowSize-1]<<"\t";
	//	cout << endl;
	//}

	getchar();
	return 0;
}
float sawFunc(float pos)
{
	return pos*2-1;
}


void main1(){
	agac *a = new agac();

	//Utility * u = new Utility();
	//char  filename [200]= "C:\\Users\\dellCTA\\OneDrive\\spectron\\data\\test_mono_8000Hz_16bit_PCM.wav";
	//u->readWav(filename);
	//
	int depth = 5;
	data_tipi  *veri= new int[depth];// {5,4,7,1,3};

	for (int j = 0 ; j < 10;j++){
		for (int i = 0 ; i < depth;i++){
			veri[i]=(int)(rand())%255;
			printf("%d\t",veri[i]);
		}
		a->dalEkle(veri,5);
		printf("\n");
	}
	a->Preorder();
	a->save();
	agac *b=new agac();
	//b->open();
	//b->Preorder();
	oku();

	//a->dalEkle(veri,5);



	//getchar();

	//int windowSize = 16;


	//for(int i = 0 ; i < 10000; i++)
	//{
	//	 /*for(int j = 0 ; j < windowSize ;j++)
	//		cout << u->data[i*windowSize+j]<<"\t";
	//	cout << endl;*/

	//	data_tipi *sonuc = u->discreteHaarWaveletTransform(u->data+i*windowSize,windowSize);

	//	/* for(int j = 0 ; j < windowSize ;j++)
	//		cout << sonuc[j]<<"\t";
	//	cout << endl;
	//	cout << endl;*/

	//	a->dalEkle(sonuc, windowSize);

	//
	//}


	////a->Preorder();

	//a->save();
	//printf("done\n");
	//initialize data
	//data_tipi *data = new data_tipi[boy];
	//srand(time(NULL));	
	//for (int i = 0; i < boy; i++)
	//data[i] = (int)rand()%1000 -500 ;

	/*	

	CWave *c = new CWave();


	c->Load(filename);
	byte * dataa = c->GetData();

	cout << c->GetSize()<<endl;
	for( int i = 0 ; i < 10; i+=2)		
	cout << (dataa[i+1]*256+dataa[i]) <<endl;

	*/
}
void calisan(){

	int *data = new int[boy];
	//srand(time(NULL));


	for (int i = 0; i < boy; i++)
		data[i] = (int)rand()%1000 -500 ;

	/*for (int i = 0; i < boy; i++)
	cout << data[i] << endl;
	*/


	vector<vector <data_tipi>> *layers = new vector<vector<data_tipi>>;

	vector < dugum *> *katman;
	katman = new vector<dugum* >;

	for (int i = 0; i < boy / derinlik; i++){
		for (int j = 0; j < derinlik; j++){
			cout << data[i*derinlik + j] << "\t";
		}
		cout << endl;
	}


	for (int i = 0; i < boy / derinlik; i++)
	{
		dugum * n = new dugum();
		n->deger = data[i*derinlik];
		n->parent = NULL;
		n->children= NULL;
		bool inserted = false;

		if (katman->size() >0){		
			for (int j = 0; j < katman->size(); j++){
				if (katman->at(j)->deger > n->deger)	{
					{
						katman->insert(katman->begin() + j, n); //->insert(it + i, n);
						inserted = true;
						break;
					}
				}
			}
		}
		if(!inserted)
			katman->push_back(n);
	}


	for (int i = 0; i < boy / derinlik; i++)
		cout << katman->at(i)->deger << endl;




	char  filename [200]= "C:\\Users\\dellCTA\\OneDrive\\spectron\\data\\test_mono_8000Hz_16bit_PCM.wav";

	CWave *c = new CWave();


	c->Load(filename);
	byte * dataa = c->GetData();

	for( int i = 0 ; i < 10; i+=2)		
		cout << (dataa[i+1]*256+dataa[i]) <<endl;



	data_tipi data1[boy]={-40,-290,128,-30, -261,490,128,303,-449,288,63, -304,337,-355,478,
		426,-237,-65,394,223,-330,-438,65, -164,-150,-222,-460,254,46, 322,
		-3, -11,-220,197,-342,457,116,-460,-37,309,184,383,241,441,-343,
		319,-41,173,-160,-213,190,442,-121,17, -437,-77,-495,-128,-4, 348};


	for (int i = 0; i < boy; i++)
		cout << data1[i] <<"\t";
	cout << endl;

	agac *a1 = new agac();

	for(int i = 0 ; i < 3;i++)
		a1->dalEkle(data1+i*derinlik,3);
	cout <<endl<<endl<<endl;
	a1->Postorder(a1->root);
	cout <<endl<<endl<<endl;
	a1->Preorder(a1->root);

	data_tipi a[] ={56,40,8,24,48,48,40,16};

	Utility *u = new Utility();
	data_tipi *sonuc = u->discreteHaarWaveletTransform(a,8);
	for(int i = 0 ; i < 8; i++)
		cout << sonuc[i]<<endl;
}

void readFilterCoefs(){
	//ifstream in("Bandpassfilter_250_500.txt");
	 fstream       cleanedFile;
     cleanedFile.open("Bandpassfilter_250_500.txt", ios::in|ios::binary|ios::ate);
    if (cleanedFile.is_open())
	{
		char * readBuffer =  new char[windowSize];
	}
	else
	{
		cout<<"file could not be opened!"<<endl;
	}
    
    
   
    
    
}

void oku(){
	FILE *fp = fopen("tree.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file - exiting...\n");
		exit(1);
	} 

	// item is marker, then return
	int val;
	bool rootInserted = true;
	//this->agacYarat();
	char line[10000];

	data_tipi *veri =new int[100];
	int maxElems=0;

	while(fgets(line, sizeof(line), fp) != NULL)
	{ 
		//printf("%s",line);
		char * pch;
		printf ("Splitting string \"%s\" into tokens:\n",line);
		pch = strtok (line," \n");
		int indice = 0 ;
		while (pch != NULL)
		{	
			if(rootInserted){
				maxElems++;
				if(maxElems > 1)
					veri[indice++]=atoi(pch);
			}
			printf ("%s\n",pch);
			pch = strtok (NULL, " \n");
		}

		rootInserted = false;
	}


	fclose(fp);
}


void generateSawtooth(){
	//sawtooth signal
	int n_frames =100;
	float frequency = 10;
	int sample_rate = 100;
	int fixedAmplitude = 5;

	for (size_t frame=0; frame!=n_frames; ++frame) {
		float pos = fmod(frequency*frame/sample_rate,1.0);
		printf( "%d %f %f\n",frame, pos, sawFunc(pos)*fixedAmplitude);
	}
}