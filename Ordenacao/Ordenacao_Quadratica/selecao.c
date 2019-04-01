//
//  selecao.c
//  Ordenacao
//
//  Created by José Luiz Junior on 18/03/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include "selecao.h"


void selectSort(int vet[], int tam){

    int i = 0,n = 0,aux = 0;

    //De fora dita a posicao do ordenado
    for(i=0;i<tam;i++){
        //o de dentro anda por todas as posicoes entre a parte ordenada e a nao
        for(n=i+1;n<tam-1;n++){

            if(vet[i] > vet[n]){
                //Troca de posicao
                aux = vet[n];
                vet[n] = vet[i];
                vet[i] = aux;
            }
        }
        
        
    }

    return;
}
