#include "Agac.h"
#include "Utility.h"
#include "Haberlesme.h"
#include "Bellek.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


#define boy  60
#define derinlik 3
#define oversample 4

void testTree();
void testWaveletTree();
void testReadSound();
void communicate();
void testLearning(Bellek *bellek);
void restoreTree(Bellek *bellek);
//Bellek *bellek;

int main(){
    
    Bellek *bellek = new Bellek();
    //testTree();
    //testWaveletTree();
    //testReadSound();
    //communicate();
    //testLearning(bellek);
    //restoreTree(bellek);
    //testLearning(bellek);
    restoreTree(bellek);
    return 0;
}

void restoreTree(Bellek *bellek ){
    
    cout << "restoring tree from file " << bellek->dosyadanGeriGetir("/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/treeData.txt")<<endl;
    bellek->goster();
    bellek->ozetle();
    
}
void testLearning(Bellek *bellek ){
    //= new Bellek();
    
    int depth = 8;
    data_tipi  *veri= new data_tipi[depth];// {5,4,7,1,3};
    
    for (int j = 0 ; j < 4;j++){
        for (int i = 0 ; i < depth;i++){
            veri[i]=(int)(rand())%16;
            printf("%d\t",veri[i]);
        }
        bellek->egit(veri, depth, 1);
        printf("\n");
    }
    /*char  filename[200];
    sprintf(filename, "/Users/ser/OneDrive/teza/datasets/Heinrich Mann - Ingerul albastru.mp3");
    sprintf(filename, "/Users/ser/OneDrive/spectron/data/brian.wav");
    bellek->wavIleEgit(filename, 16, 8, 4);
    bellek->ozetle();
    bellek->wavIleEgit(filename, 16, 8, 4);
    */
    bellek->goster();
    bellek->ozetle();
    cout << "saving tree to file " << bellek->kaydet("/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/treeData.txt")<<endl;
}
void communicate(){
    Haberlesme *h = new Haberlesme();
    
    //h->test();
    h->haberles();
    
}

void testTree(){
    Agac *a = new Agac();
    int depth = 5;
    data_tipi  *veri= new data_tipi[depth];// {5,4,7,1,3};
    
    for (int j = 0 ; j < 100;j++){
        if(j!=1)
            for (int i = 0 ; i < depth;i++){
                veri[i]=(int)(rand())%16;
                printf("%d\t",veri[i]);
            }
        a->dalEkle(veri, depth, 1);
        printf("\n");
    }
    cout << endl;
    a->Preorder();
}

void testWaveletTree(){
    Utility *u =new Utility();
    int depth = 8;
    //data_tipi  *veri= new int[depth];
    data_tipi veri[8]= {12,6,4,2,5,1,2,0};
    
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
    int datasize;
    char filename[100];
    
    sprintf(filename, "/Users/ser/OneDrive/spectron/data/amy.wav");
    sprintf(filename, "/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/test_mono_8000Hz_16bit_PCM.wav");
    cout << u->readWav(filename, &output,&fs ,&datasize) << endl;
    cout << "sampling rate " << fs<< endl;
    for(int i = 100060; i< 100070; i++)
        cout << i<<"\t"<< output[i]<<endl;
}
