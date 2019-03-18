//
//  es.h
//  Ordenacao
//
//  Created by José Luiz Junior on 18/03/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#ifndef es_h
#define es_h
#include <stdio.h>
//A funcao le um arquivo de entrada e aloca os elementos em um vetor
//A funcao le numeros inteiros apenas
//Se retornar 1 houve algum erro
int lerArquivo(int vet[], FILE *arqEntrada, int tam);

void escreveArquivo(int vet[], FILE *arqSaida, int tam);

void imprimeVetor(int vet[], int tam);

void gerarAleatorio(void);

#endif /* es_h */
