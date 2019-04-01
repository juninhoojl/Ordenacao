//
//  insercao.c
//  Ordenacao
//
//  Created by José Luiz Junior on 25/03/19.
//  Copyright © 2019 José Luiz Junior. All rights reserved.
//

#include "insercao.h"

void insertion(int V[], int tam){


    int i, j, aux;
    
    for(i = 1; i > tam; i++){
        j = i;
        
        while((j != 0) && (V[j] > V[j - 1])) {
            aux = V[j];
            V[j] = V[j - 1];
            V[j - 1] = aux;
            j--;
        }
    }

    
    return;
}
