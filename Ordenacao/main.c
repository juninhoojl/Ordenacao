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
#include "selecao.h"
#include "bolhainteligente.h"
#include "insercao.h"
#include "bolha.h"
#include "es.h"
#include "merge.h"
#include "mergeinloco.h"
#include "quick.h"

int main(int argc, const char * argv[]) {
    
    //Qual é o arquivo de entrada, qual o tamanha e qual codigo usar para ordenar
    
    int *vet;//Ponteiro para o vetor
    int tam = 0, metodoOrdenacao = 0, aux = 0;
    char nomeArq[30];
    char op = '\0';
    FILE *arq;
    clock_t inicio;
    
    printf("Deseja gerar um arquivo? sim[s] nao[n]\n");
    while (op != 's' && op != 'S' && op != 'n' && op != 'N' ) {
        if (op != '\0')
            printf("Opcao invalida, digite novamente: ");
        scanf("%s", &op);
    }
    if (op == 's' || op == 'S') {
        
        printf("Digite o nome que deseja: ");
        scanf("%s",nomeArq);
        
        printf("Digite a quantidade de elementos que deseja: ");
        scanf("%d", &tam);
        
        // deseja usar o arquivo gerado?
        arq = fopen(nomeArq, "w");
        if (!arq){//se o arq nao é nulo
            printf("Erro ao criar arquivo\n");
            exit(1);
        }
        
        //Escreve aqui
        //Capturar opcao
        printf("\nTipo de arquivo:\n");
        printf("\t1 - Aleatorio\n");
        printf("\t2 - Ordenado\n");
        printf("\t3 - Invertido\n");
        printf("Digite a opcao desejada: ");
        while (metodoOrdenacao != 1 && metodoOrdenacao != 2 && metodoOrdenacao != 3) {
            if (metodoOrdenacao){
                printf("Opcao invalida, digite novamente: ");
            }
            
            scanf("%d",&metodoOrdenacao);
        }
        
        //Escolhe o tipo de aquivo
        gerarAleatorio(arq, tam, metodoOrdenacao);
        metodoOrdenacao = 0;
        
        //Depois de escrever fecha
        fclose(arq);
        //Se escreveu, pergunta se quer usar
        
        arq = fopen(nomeArq, "r");
        if (!arq){//se o arq nao é nulo
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }
        
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
        
    }else{
    
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
    }
    //Menu
    //Criar menu loop
    printf("\nAlgoritmos de ordenacao:\n");
    printf("\t1 - Bolha\n");
    printf("\t2 - Bolha Inteligente\n");
    printf("\t3 - Selecao\n");
    printf("\t4 - Insercao\n");
    printf("\t5 - Merge\n");
    printf("\t6 - Merge in Loco\n");
    printf("\t7 - Quick\n");
    printf("Digite a opcao desejada: ");
    while ((metodoOrdenacao != 1) && (metodoOrdenacao != 2) && (metodoOrdenacao != 3) && (metodoOrdenacao != 4) && (metodoOrdenacao != 5) && (metodoOrdenacao != 6) && (metodoOrdenacao != 7)) {
        if (metodoOrdenacao){
            printf("Opcao invalida, digite novamente: ");
        }
        
        scanf("%d",&metodoOrdenacao);
    }
    
    //Inicio clock
    inicio = clock();
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
        case 4:
            insertion(vet, tam);
            break;
        case 5:
            mergeSort(vet, 0, (tam-1));
            break;
        case 6:
            mergein(vet,0,tam-1);
            break;
        case 7:
            quickSort(vet, 0, (tam-1));
            break;
        default:
            break;
    }
    //Fim Clock
    printf("Tempo: %fms\n",1000*(double)(clock() - inicio) / CLOCKS_PER_SEC);
    
    printf("Deseja printar o vetor ordenado? sim[s] nao[n]\n");
    op = '\0';
    while (op != 's' && op != 'S' && op != 'n' && op != 'N' ) {
        if (op != '\0')
            printf("Opcao invalida, digite novamente: ");
        scanf("%s", &op);
    }
    if(op == 's' || op == 'S')
        imprimeVetor(vet, tam);
    
    //Opcao arquivo de saida
    printf("Deseja salvar em um arquivo de saida? sim[s] nao[n]\n");
    op = '\0';
    while (op != 's' && op != 'S' && op != 'n' && op != 'N' ) {
        if (op != '\0')
            printf("Opcao invalida, digite novamente: ");
        scanf("%s", &op);
    }
    
    if (op == 's' || op == 'S') {
        printf("\nDigite o nome do arquivo de saida: ");
        scanf("%s",nomeArq);
        arq = fopen(nomeArq, "w");
        if (!arq){//se o arq nao é nulo
            printf("Erro ao escrever no arquivo\n");
            exit(1);
        }
        escreveArquivo(vet, arq, tam);
        //fechar aquivo
        fclose(arq);
    }

    return 0;
}
