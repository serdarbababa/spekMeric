#include "agac.h"
#include "Utility.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Haberlesme.h"
using namespace std;


#define boy  60
#define derinlik 3
#define oversample 4

void testTree();
void testWaveletTree();
void testReadSound();
void communicate();

int main(){
    
    //testTree();
    //testWaveletTree();
    //testReadSound();
    communicate();
    return 0;
}




void communicate(){
    Haberlesme *h = new Haberlesme(16);
    //h->test();
    h->haberles();
    
}

void testTree(){
    agac *a = new agac();
    int depth = 5;
    data_tipi  *veri= new int[depth];// {5,4,7,1,3};
    
    for (int j = 0 ; j < 100;j++){
        if(j!=1)
            for (int i = 0 ; i < depth;i++){
                veri[i]=(int)(rand())%16;
                printf("%d\t",veri[i]);
            }
        a->dalEkle(veri,depth);
        printf("\n");
    }
    cout << endl;
    a->Preorder();
}

void testWaveletTree(){
    Utility *u =new Utility();
    int depth = 8;
    //data_tipi  *veri= new int[depth];
    int veri[8]= {12,6,4,2,5,1,2,0};
    
    /*for (int i = 0 ; i < depth;i++){
        veri[i]=(int)(rand())%16;
        printf("%d\t",veri[i]);
    }*/
    
    cout << endl;
    data_tipi *rez =  u->discreteHaarWaveletTransform(veri, depth);
    for (int i = 0 ; i < depth;i++){
        printf("%d\t",rez[i]);
    }
}

void testReadSound(){
    Utility *u = new Utility();
    short * output;
    int fs;
    char filename[100];
    
    sprintf(filename, "/Users/ser/OneDrive/spectron/data/amy.wav");
    sprintf(filename, "/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/test_mono_8000Hz_16bit_PCM.wav");
    cout << u->readWav(filename, &output,&fs ) << endl;
    cout << "sampling rate " << fs<< endl;
    for(int i = 100060; i< 100070; i++)
        cout << i<<"\t"<< output[i]<<endl;
}
