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

int Bellek::egit(data_tipi *veri,int depth){
    a->dalEkle(veri,depth);
    return 0;
}

int Bellek::wavIleEgit(char *filename, int depth, int kaydirma){
    Utility *u = new Utility();
    short * output;
    int fs;
    int datasize;
    //char filename[100];
    
    //sprintf(filename, "/Users/ser/OneDrive/spectron/data/amy.wav");
    //sprintf(filename, "/Users/ser/OneDrive/git/spekMeric/mericSpek/mericSpek/test_mono_8000Hz_16bit_PCM.wav");
    cout << u->readWav(filename, &output,&fs, &datasize ) << endl;
    cout << "sampling rate " << fs<< endl;
    for(int i = 0; i< datasize; i+=kaydirma){
        //data_tipi  *veri= new data_tipi[depth];// {5,4,7,1,3};
        //for (int j = 0 ; j < depth;j++){
        //    veri[j]=output[i+j];
        //    cout << i << j << veri[j]<<endl;;
        //}
        //egit( veri,depth);
        
        a->dalEkle(output+i,depth);
    }
    return 0;
}


void Bellek::goster(){
    a->Preorder();
}
void Bellek::ozetle(){
    a->summarize();
}
