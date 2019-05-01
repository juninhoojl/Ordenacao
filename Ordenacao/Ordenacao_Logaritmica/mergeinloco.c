//
//  mergeinloco.c
//  Ordenacao
//
//  Created by José Luiz Junior on 14/04/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include "mergeinloco.h"

void in_place(int vetor[],int inicio,int meio,int fim){
    int aux,pos_esq=inicio, pos_dir = meio+1,pos_aux;
    //ordenaÁ„o inplace
    while((pos_esq<=meio)&&(pos_dir<=fim)){
        if(vetor[pos_esq]<=vetor[pos_dir]){
            pos_esq++;
        }
        else{
            pos_aux = pos_dir;
            aux=vetor[pos_dir];
            while(pos_aux>pos_esq){
                vetor[pos_aux]=vetor[pos_aux-1];
                pos_aux--;
            }
            vetor[pos_esq]=aux;
            pos_esq++;
            meio++;
            pos_dir++;
            
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
    in_place(vetor,inicio,meio,fim);
    return;
}
