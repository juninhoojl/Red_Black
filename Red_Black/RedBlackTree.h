//
//  Red_Black
//  Created by:
//  Andre Felipe Magalhães Silva - 2017020218
//  José Luiz Corrêa Junior - 2017020933
//  Copyright 2019. All rights reserved.
//

#ifndef RedBlackTree_h
#define RedBlackTree_h

//Facilitando ponteiro para ponteiro
typedef struct NO* ArvLLRB;

#include <stdio.h>
#include <stdlib.h>

int insere_RedBlack(ArvLLRB* raiz, int valor);

int remove_RedBlack(ArvLLRB* raiz, int valor);

struct NO* insereNO(struct NO* H, int valor, int *resp);

struct NO* procuraMenor(struct NO* atual);

struct NO* removeNO(struct NO* H, int valor);



// Funcao que consulta existencia de um valor
// Retorna 1 se ele existe e 0 caso contrario
int consulta_RedBlack(ArvLLRB* raiz, int valor);

#endif /* RedBlackTree_h */
