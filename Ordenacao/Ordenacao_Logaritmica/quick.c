//
//  quick.c
//  Ordenacao
//
//  Created by José Luiz Junior on 14/04/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include "quick.h"

void quickSort(int *v, int inicio, int fim){
    int pivo;
    
    if(inicio < fim){
        pivo = Particiona(v, inicio, fim);
        quickSort(v, inicio, pivo-1);
        quickSort(v, pivo+1, fim);
    }
    return;
}

int Particiona(int *v, int inicio, int fim){
    int pivo, pos, i = 0, aux;
    
    pivo = v[inicio];
    pos = inicio;
    
    for( i = inicio+1; i <= fim; i ++){
        if(v[i] <pivo){
            pos = pos +1;
            if( i != pos){
                aux= v[i];
                v[i] = v[pos];
                v[pos] = aux;
            }
        }
    }
    aux= v[inicio];
    v[inicio] = v[pos];
    v[pos] = aux;
    return pos;
}
