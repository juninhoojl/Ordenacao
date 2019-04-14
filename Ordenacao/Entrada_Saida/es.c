//
//  es.c
//  Ordenacao
//
//  Created by José Luiz Junior on 18/03/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//


#include "es.h"

int lerArquivo(int vet[], FILE *arqEntrada, int tam){
    
    int i = 0;
    //Enquando nao chega ao fim, continua entrando
    //find end of file
    while (!feof(arqEntrada)) {
        //Passa onde esta lendo
        fscanf(arqEntrada, "%d", &vet[i]);
        i+=1;
    }
    //Se o arquivo é maior
    if(i > tam) return 1;

    //Se o arquivo é menor
    if (i != tam) return 2;
    
    //Se tudo ocorreu bem
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
    printf("\n");
    return;
}

void gerarAleatorio(FILE *arqSaida, int qtd, int op){
    srand((int)time(NULL));
    
    int i = 0;
    if(op == 1){ // Aleatorio
        for (i = 0; i < qtd; i++){
            if (i+1 == qtd){
                fprintf(arqSaida, "%d", rand());
            }else{
                fprintf(arqSaida, "%d\n", rand());
            }
        }
        
    }else if (op == 2){ //Crescente, ja ordenado
        for (i = 0; i < qtd; i++){
            if (i+1 == qtd){
                fprintf(arqSaida, "%d", i);
            }else{
                fprintf(arqSaida, "%d\n", i);
            }
        }
    }else{ //Decrescente, invertido
        for (i = qtd-1; i >= 0; i--){
            if (i > 0){
                fprintf(arqSaida, "%d\n", i);
            }else{
                fprintf(arqSaida, "%d", i);
            }
        }
    }
    
    return;
}
