//
//  bolhainteligente.c
//  Ordenacao
//
//  Created by José Luiz Junior on 25/03/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include "bolhainteligente.h"

#include "bolha.h"

void bubbleSortInteligente(int vet[], int tam){
    
    clock_t inicio = clock();
    int i, n, aux = 0, flag = 0;
    
    for(i=0;i<tam;i++){
        flag = 0;
        for(n=0;n<tam-1-i;n++){
            if(vet[n]>vet[n+1]){
                //Troca
                aux = vet[n];
                vet[n] = vet[n+1];
                vet[n+1] = aux;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
        
    }
    
    printf("Tempo: %fms\n",1000*(double)(clock() - inicio) / CLOCKS_PER_SEC);
    
    return;
}
