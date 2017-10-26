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

int main(){
    //testTree();
    Haberlesme *h = new Haberlesme();
    //h->test();
    h->haberles();
    return 0;
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

