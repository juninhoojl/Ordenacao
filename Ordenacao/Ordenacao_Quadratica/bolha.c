//
//  bolha.c
//  Ordenacao
//
//  Created by José Luiz Junior on 18/03/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include "bolha.h"

void bubbleSort(int vet[], int tam){
    
    clock_t inicio = clock();
    int i, n, aux = 0;
    
    for(i=0;i<tam;i++){
        for(n=0;n<tam-1;n++){
            if(vet[n]>vet[n+1]){
                //Troca
                aux = vet[n];
                vet[n] = vet[n+1];
                vet[n+1] = aux;

            }
        }
    }

    printf("Tempo: %fms\n",1000*(double)(clock() - inicio) / CLOCKS_PER_SEC);
    
    return;
}
