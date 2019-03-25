//
//  main.c
//  Ordenacao
//
//  Created by José Luiz Junior on 18/03/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "selecao.h"
#include "bolhainteligente.h"
#include "bolha.h"
#include "es.h"

int main(int argc, const char * argv[]) {
    
    //Qual é o arquivo de entrada, qual o tamanha e qual codigo usar para ordenar
    
    int *vet;//Ponteiro para o vetor
    int tam = 0, metodoOrdenacao = 0, aux = 0;
    char nomeArq[30];
    FILE *arq;
    
    //O fopen retorna o endereco da primeira posicao onde o aquivo esta na memoria
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s",nomeArq);


    arq = fopen(nomeArq, "r");
    if (!arq){//se o arq nao é nulo
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    
    printf("Digite a quantidade de elementos do arquivo: ");
    scanf("%d", &tam);
    //O vetor sempre é alocado sequencialmente
    vet = (int*)malloc(tam*sizeof(int));
    
    //Ler arquivo
    aux = lerArquivo(vet, arq, tam);
    
    //Depois de ler fecha
    fclose(arq);

    if (aux == 1) {
        printf("\nTamanho do arquivo é maior que o especificado!");
        printf("\nO programa sera encerrado\nar");
        exit(1);
    }else if (aux == 2){
        printf("\nTamanho do arquivo é menor que o especificado!");
        printf("\nO programa sera encerrado\nar");
        exit(1);
    }
    
    //Menu
    //Criar menu loop
    printf("\nAlgoritmos de ordenacao:\n");
    printf("\t1 - Bolha\n");
    printf("\t2 - Bolha Inteligente\n");
    printf("\t3 - Selecao\n");
    printf("Digite a opcao desejada: ");
    scanf("%d",&metodoOrdenacao);
    
    switch (metodoOrdenacao) {
        case 1:
            bubbleSort(vet, tam);
            break;
        case 2:
            bubbleSortInteligente(vet, tam);
            break;
        case 3:
            selectSort(vet, tam);
            break;
        default:
            break;
    }
    
    printf("Digite o nome do arquivo de saida: ");
    scanf("%s",nomeArq);
    
    arq = fopen(nomeArq, "w");
    
    if (!arq){//se o arq nao é nulo
        printf("Erro ao escrever no arquivo\n");
        exit(1);
    }
    
    escreveArquivo(vet, arq, tam);
    //fechar aquivo
    
    fclose(arq);
    
    
    return 0;
}

