//
//  bellek.cpp
//  mericSpek
//
//  Created by ser on 28/10/2017.
//  Copyright © 2017 home sweet home. All rights reserved.
//

#include "Bellek.hpp"
Bellek::Bellek(int depth){
    a=new agac();
    this->depth=depth;
}

int Bellek::egit(data_tipi *veri){
    a->dalEkle(veri,depth);
    return 0;
}

int Bellek::wavIleEgit(char *filename){
    
    return 0;
}


void Bellek::goster(){
    a->Preorder();
}
