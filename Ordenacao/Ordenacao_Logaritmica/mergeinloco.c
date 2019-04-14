//
//  mergeinloco.c
//  Ordenacao
//
//  Created by José Luiz Junior on 14/04/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include "mergeinloco.h"

void in_place(int vetor[],int inicio,int meio,int fim){
    int aux,pos_esq=inicio, pos_dir = meio;
    if(pos_esq<pos_dir){
        //ordenaÁ„o inplace
        while(pos_dir<=fim){
            if(vetor[pos_esq]<=vetor[pos_dir]){
                pos_esq++;
            }
            else{
                aux=vetor[pos_esq];
                vetor[pos_esq]=vetor[pos_dir];
                vetor[pos_dir]=aux;
                pos_esq++;
            }
            if (pos_esq == pos_dir){
                pos_dir++;
                pos_esq=inicio;
            }
        }
    }
    return;
    
}

void mergein(int vetor[],int inicio, int fim){
    int meio;
    meio=(inicio+fim)/2;
    if(inicio<fim){
        //esquerda
        mergein(vetor,inicio,meio);
        //direita
        mergein(vetor,meio+1,fim);
    }
    in_place(vetor,inicio,meio+1,fim);
    return;
}
