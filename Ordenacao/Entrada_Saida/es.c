//
//  es.c
//  Ordenacao
//
//  Created by José Luiz Junior on 18/03/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "es.h"

int lerArquivo(int vet[], FILE *arqEntrada, int tam){
    
    int i = 0;
    //Enquando nao chega ao fim, continua entrando
    //find end of file
    while (!feof(arqEntrada)) {
        //Passa onde esta lendo
        fscanf(arqEntrada, "%d", &vet[i]);
        i+=1;
        //Se o arquivo é maior
        if(i >= tam) return 1;
    }
    
    //Se o arquivo é menor
    if (i != tam) return 1;
    

    return 0;
}

void escreveArquivo(int vet[], FILE *arqSaida, int tam){
    
    int i = 0;
    for (i = 0; i<tam; i++)
        fprintf(arqSaida, "%d\n", vet[i]);
    return;
}


void imprimeVetor(int vet[], int tam){
    
    int i = 0;
    for (i = 0; i<tam; i++)
        printf("%d ", vet[i]);
    return;
}
