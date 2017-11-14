//
//  bellek.cpp
//  mericSpek
//
//  Created by ser on 28/10/2017.
//  Copyright © 2017 home sweet home. All rights reserved.
//

#include "Bellek.hpp"
Bellek::Bellek(){
    a=new Agac();
    //this->depth=depth;
}
Bellek::~Bellek(){
    a->~Agac();
}

int Bellek::agac_egit(data_tipi *veri,int depth, int option){
    Utility *u = new Utility();
    if(option ==1)
        a->dalEkle(veri,depth, option);
    else if(option==2)
        a->dalEkle(veri,depth,option);
    else if(option==3)
        a->dalEkle(u->discreteHaarWaveletTransform(veri,depth),depth, 1);
    else if(option==4)
        a->dalEkle(u->discreteHaarWaveletTransform(veri,depth),depth, 2);
    return 0;
}

int Bellek::agac_wavIleEgit(char *filename, int depth, int kaydirma,int option){
    Utility *u = new Utility();
    short * output;
    int fs;
    int datasize;
    //char filename[100];
    
    //sprintf(filename, "/Users/ser/OneDrive/spectron/data/amy.wav");
    //sprintf(filename, "/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/test_mono_8000Hz_16bit_PCM.wav");
    if( u->readWav(filename, &output,&fs, &datasize )==0)
        cout <<filename << " okuma basarili"  << endl;
    else{
        cout <<filename << " okuma basarisiz"  << endl;
        return -1;
    }
    //cout << "sampling rate " << fs<< endl;
    for(int i = 0; i< datasize; i+=kaydirma){
        //data_tipi  *veri= new data_tipi[depth];// {5,4,7,1,3};
        //for (int j = 0 ; j < depth;j++){
        //    veri[j]=output[i+j];
        //    cout << i << j << veri[j]<<endl;;
        //}
        //egit( veri,depth);
        if(option ==1)
            a->dalEkle(output+i,depth, option);
        else if(option==2)
            a->dalEkle(output+i,depth,option);
        else if(option==3)
            a->dalEkle(u->discreteHaarWaveletTransform(output+i,depth),depth, 1);
        else if(option==4)
            a->dalEkle(u->discreteHaarWaveletTransform(output+i,depth),depth, 2);
        
    }
    return 0;
}


void Bellek::agac_goster(){
    a->Preorder();
}

void Bellek::agac_ozetle(){
    a->summarize();
}

void Bellek::agac_kisa_ozetle(){
    a->brief_summary();
}

void Bellek::yaprak_topla(){
    a->registerLeafs();
}


int Bellek::agac_kaydet(char * filename){
    return a->saveB(filename);
}

int Bellek::agac_gerigetir(char * filename){
    a=new Agac();
    return a->openB(filename);
}

/*
int Bellek::getWavIDs(char * filename, int *ids, int *count, int depth, int kaydirma, int option ){
    Utility *u = new Utility();
    short * output;
    int fs;
    int datasize;
    
    if( u->readWav(filename, &output,&fs, &datasize )==0)
        cout <<filename << " okuma basarili"  << endl;
    else{
        cout <<filename << " okuma basarisiz"  << endl;
        return -1;
    }

    for(int i = 0; i< datasize; i+=kaydirma){
        
        if(option ==1)
            a->dalEkle(output+i,depth, option);
        else if(option==2)
            a->dalEkle(output+i,depth,option);
        else if(option==3)
            a->dalEkle(u->discreteHaarWaveletTransform(output+i,depth),depth, 1);
        else if(option==4)
            a->dalEkle(u->discreteHaarWaveletTransform(output+i,depth),depth, 2);
        
    }
    
    return 0;
}
 
 */

int Bellek::getBranchId(data_tipi *veri,int depth, int option){
    Utility *u = new Utility();
    int result = 0 ;
    if(option ==1|| option ==2 )
        result = a->getLeafId(veri,depth, option);
    else if(option==3)
        result = a->getLeafId(u->discreteHaarWaveletTransform(veri,depth),depth, 1);
    else if(option==4)
        result = a->getLeafId(u->discreteHaarWaveletTransform(veri,depth),depth, 2);
    return result;
}
