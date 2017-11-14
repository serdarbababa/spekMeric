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
void testWriteSound();
void communicate();
void testLearning(Bellek *bellek);
void restoreTree(Bellek *bellek);
void testWaveTrain(Bellek *bellek);
void one_cycle();
//Bellek *bellek;

int main(){
    
    Bellek *bellek = new Bellek();
    //testTree();
    //testWaveletTree();
    
    /* test wav read/write*/
    //testWriteSound();
    //testReadSound();
    
    /* use server client to recieve and */
    //communicate();
    
    /*testing with 5 samples */
    {
        //testLearning(bellek);
        //restoreTree(bellek);
        //testLearning(bellek);
        //restoreTree(bellek);
    }
    
    /*train tre with wav*/
    //testWaveTrain(bellek);
    
    /* build, save, restore tree, give wav, get id's , save id's, read id's restore tree and wav*/
    one_cycle();
    
    return 0;
}

/* build, save, restore tree, give wav and get id's , save id's, read id's restore tree and wav*/
void one_cycle(){
    Bellek *bellek=new Bellek();
    char filename[100];
    
    
    /*
    testLearning(bellek);
    
    data_tipi veri[8]={8    ,5,    11,    6,    8,    7,    9,    2};
    cout << bellek->getBranchId(veri, 8, 1)<<endl;
    for(int i =0 ; i < 8;i++)
        printf("%d\t", veri[i]);
    cout << endl<<endl;
    
    
    bellek->agac_goster();
    cout <<endl<<endl<<"agac ozeti";
    bellek->agac_kisa_ozetle();
    
    
    bellek->yaprak_topla();
    cout << bellek->getBranchId(veri, 8, 1)<<endl;
    bellek->agac_goster();
    cout <<endl<<endl<<"agac ozeti";
    bellek->agac_kisa_ozetle();
    */
    
    /*read wav to tree*/
    /*
    sprintf(filename, "/Users/ser/OneDrive/spectron/data/amy.wav");
    bellek->agac_wavIleEgit(filename, 128, 32, 1);
    bellek->agac_kaydet("/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/treeData.txt");
    bellek->yaprak_topla();
    cout <<endl<<endl<<"agac ozeti";
    bellek->agac_kisa_ozetle();
    
    
    Bellek *bellek1=new Bellek();
    /*restore tree from file *
    cout << endl<<endl<<"restoring tree from file " << bellek1->agac_gerigetir("/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/treeData.txt")<<endl<<endl;
    cout <<endl<<endl<<"agac kisa ozeti";
    bellek1->yaprak_topla();
    bellek1->agac_kisa_ozetle();
    
    int *ids;
    int id_count;
    */
    //bellek1->getWavIDs(filename,  ids,  &id_count, 32,32,1 );
    //cout <<endl<<endl<<"agac ozeti";
    //bellek1->agac_ozetle();
    
    
}


void testWaveTrain(Bellek *bellek){
    char filename[100];
    
    sprintf(filename, "/Users/ser/OneDrive/spectron/data/amy.wav");
    bellek->agac_wavIleEgit(filename, 32, 16, 4);
    
}

void restoreTree(Bellek *bellek ){
    
    cout << endl<<endl<<"restoring tree from file " << bellek->agac_gerigetir("/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/treeData.txt")<<endl<<endl;
    bellek->agac_goster();
    bellek->agac_ozetle();
    
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
        bellek->agac_egit(veri, depth, 1);
        printf("\n");
    }
    cout << endl<<endl;
    
    
    
    /*char  filename[200];
    sprintf(filename, "/Users/ser/OneDrive/teza/datasets/Heinrich Mann - Ingerul albastru.mp3");
    sprintf(filename, "/Users/ser/OneDrive/spectron/data/brian.wav");
    bellek->wavIleEgit(filename, 16, 8, 4);
    bellek->ozetle();
    bellek->wavIleEgit(filename, 16, 8, 4);
    */
    //bellek->agac_goster();
    //bellek->agac_ozetle();
    //bellek->yaprak_topla();
    //bellek->agac_goster();
    //bellek->agac_ozetle();
    //cout << endl<<endl<<"saving tree to file " << bellek->agac_kaydet("/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/treeData.txt")<<endl<<endl;
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
    //sprintf(filename, "/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/test_mono_8000Hz_16bit_PCM.wav");
    cout << u->readWav(filename, &output,&fs ,&datasize) << endl;
    cout << "sampling rate " << fs<< endl;
    for(int i = 200060; i< 200070; i++)
        cout << i<<"\t"<< output[i]<<endl;
    
    sprintf(filename, "/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/cikti.wav");
    //sprintf(filename, "/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/test_mono_8000Hz_16bit_PCM.wav");
    cout << u->readWav(filename, &output,&fs ,&datasize) << endl;
    cout << "sampling rate " << fs<< endl;
    for(int i = 200060; i< 200070; i++)
        cout << i<<"\t"<< output[i]<<endl;
}

void testWriteSound(){
    Utility *u = new Utility();
    short * output;
    int fs;
    int datasize;
    char filename[100];
    
    sprintf(filename, "/Users/ser/OneDrive/spectron/data/emma.wav");
    //sprintf(filename, "/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/test_mono_8000Hz_16bit_PCM.wav");
    cout << "read = " << u->readWav(filename, &output,&fs ,&datasize) << endl;
    //cout << "sampling rate " << fs<< endl;
    //u->readWavFile(filename);
    sprintf(filename, "/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/cikti.wav");
    //u->testWav(filename, output, datasize/2, fs);
    
    cout << "write = " << u->writeWav(filename,output, fs, datasize)<<endl;
    //u->readWavFile(filename);
    //u->testWav(filename);
}
