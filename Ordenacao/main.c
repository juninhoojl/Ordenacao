//
//  main.c
//  Ordenacao
//
//  Created by José Luiz Junior on 18/03/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bolha.h"
#include "es.h"

void mostra(int vet[], int w);

static void extracted(int *vet) {
    bubbleSort(vet, 10);
}

int main(int argc, const char * argv[]) {
    
    int vet[10] = {5,4,3,2,6,7,3,8,6,1};
    mostra(vet, 10);
    extracted(vet);
    printf("Ordenado: \n"); mostra(vet, 10);

    return 0;
}

void mostra(int vet[], int w){
    
    int i = 0;
    for(i=0;i<w;i++)
        printf(" %d",vet[i]);
    printf("\n");
    
}
