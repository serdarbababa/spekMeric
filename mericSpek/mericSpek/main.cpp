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
    
    int option = 3;
    
    /*read wav to tree*/
    sprintf(filename, "/Users/ser/OneDrive/spectron/data/amy.wav");
    bellek->agac_wavIleEgit(filename, 32, 32, option);
    
    sprintf(filename, "/Users/ser/OneDrive/spectron/data/brian.wav");
    bellek->agac_wavIleEgit(filename, 32, 32, option);
    
    bellek->agac_yaprak_topla();
    bellek ->agac_kisa_ozetle();
    
    sprintf(filename, "/Users/ser/OneDrive/spectron/data/amy.wav");
    bellek->agac_restoreWav(filename, "/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/brian.wav", 32, 32, option);
    
    /*
    testLearning(bellek);
    bellek->yaprak_topla();
    
    
    data_tipi veri[8]={8    ,5,    11,    6,    8,    7,    9,    2};
    int id =bellek->getBranchId(veri, 8, 2);
    cout << "yaprak id = "<< id<<endl<<"verisi = " ;
    for(int i =0 ; i < 8;i++)
        printf("%d\t", veri[i]);
    cout << endl<<endl;
    
    data_tipi *geriGetir;
    cout <<id<< " icin dal getirme = "<< bellek->getBranch(id, &geriGetir, 8)<<endl;
    for(int i =0 ; i < 8;i++)
        printf("%d\t", geriGetir[i]);
    
    cout << endl<<endl;
    
    id=1;
    cout <<id<< " icin dal getirme = "<< bellek->getBranch(id, &geriGetir, 8)<<endl;
    for(int i =0 ; i < 8;i++)
        printf("%d\t", geriGetir[i]);
    cout << endl<<endl;
    
    bellek->agac_goster();
    cout <<endl<<endl<<"agac ozeti";
    bellek->agac_kisa_ozetle();
    /*
    
    
    cout << bellek->getBranchId(veri, 8, 1)<<endl;
    bellek->agac_goster();
    cout <<endl<<endl<<"agac ozeti";
    bellek->agac_kisa_ozetle();
    
    
    
    
    /*
     
     sprintf(filename, "/Users/ser/OneDrive/spectron/data/amy.wav");
    bellek->agac_wavIleEgit(filename, 32, 32, 2);
    //bellek->agac_kaydet("/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/treeData.txt");
    
    cout <<endl<<endl<<"agac ozeti"<<endl;
    bellek->agac_kisa_ozetle();
    
    int *ids;
    int count;
    bellek->agac_wavGetIDs(filename, &ids, &count, 32, 32, 2);
    cout << "toplam id's " << count<<endl;
    for(int i = 0 ; i< 10;i++)
        cout << i<<"\t" << ids[10000+i]<<endl;
    bellek->yaprak_topla();
    
    bellek->agac_wavGetIDs(filename, &ids, &count, 32, 32, 2);
    cout << "toplam id's " << count<<endl;
    for(int i = 0 ; i< 10;i++)
        cout << i<<"\t" << ids[10000+i]<<endl;
    
   // bellek->agac_ozetle();
    bellek->agac_kisa_ozetle();
    Utility *u = new Utility();
    u->saveDataToBinary("/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/treeDataIDs.txt", ids, count);
    
    int * ids1;
    int count1;
    u->getDataFromBinary("/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/treeDataIDs.txt", &ids1, &count1);
    
    cout << "elem count = "<< count << "\t" << count1<< endl;
    for(int i = 0 ; i< 10;i++)
        cout << i+10000<<"\t" << ids[10000+i]<<"\t"<< ids1[10000+i]<< endl;
    cout << endl<<endl;
    
    
    
    //Bellek *bellek1=new Bellek();
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
        bellek->agac_egit(veri, depth, 2);
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


void testHarr(){
    data_tipi veri[8]= {6,1,14,2,55,10,2,-10};
    cout << "input"<<"\t";
    for(int i = 0 ; i < 8 ; i++)
        cout << veri[i]<<"\t";
    cout << endl;
    
    data_tipi * sonuc;
    data_tipi * restore ;
    Utility* u = new Utility();
    sonuc = u->discreteHaarWaveletTransform(veri, 8);
    
    cout << "transformed"<<"\t";
    for(int i = 0 ; i < 8 ; i++)
        cout << sonuc[i]<<"\t";
    cout << endl;
    
    
    restore = u->inverseDiscreteHaarWaveletTransform(sonuc, 8);
    cout << "restored " <<"\t";
    for(int i = 0 ; i < 8 ; i++)
        cout << restore[i]<<"\t";
    cout << endl;
    
}
