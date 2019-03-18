//
//  bolha.c
//  Ordenacao
//
//  Created by José Luiz Junior on 18/03/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include "bolha.h"

void bubbleSort (int vet[], int tam){
    
    clock_t inicio = 0, fim = 0;
    inicio = clock();
    double tempo;
    
    int i, n, aux = 0;
    
    for(i=0;i<tam;i++){
        for(n=i;n<tam;n++){
            
            //[1,2,3,4,5]
            
            if(vet[i]>vet[n]){
                //Troca
                aux = vet[i];
                vet[i] = vet[n];
                vet[n] = aux;
            }
            
            
        }
        
    }
    
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo: %lfs\n",tempo);
    
    return;
}
