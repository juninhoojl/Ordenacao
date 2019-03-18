//
//  main.c
//  Ordenacao
//
//  Created by José Luiz Junior on 18/03/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "bolha.h"
#include <time.h>

void mostra(int vet[], int w);

int main(int argc, const char * argv[]) {
    
    clock_t begin, end;
    double tempo;
    begin = clock();
    
    int vet[10] = {5,4,3,2,6,7,3,8,6,1};
    mostra(vet, 10);
    bubbleSort(vet, 10);
     printf("Ordenado: \n"); mostra(vet, 10);
    
    
    end = clock();
    tempo = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("Tempo: %lfs\n",tempo);
    return 0;
    
}

void mostra(int vet[], int w){
    int i = 0;
    for(i=0;i<w;i++){
        printf(" %d",vet[i]);
    }
    printf("\n");
    
}


