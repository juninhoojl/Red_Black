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
typedef struct NO* RedBlack;
//Ponteiro inicial

#include <stdio.h>
#include <stdlib.h>


RedBlack* cria_RedBlack(void);

int insere_RedBlack(RedBlack* raiz, int valor);

int remove_RedBlack(RedBlack* raiz, int valor);

struct NO* insereNO(struct NO* H, int valor, int *resp);

struct NO* procuraMenor(struct NO* atual);

struct NO* removeNO(struct NO* H, int valor);



void preOrdem_RedBlack(RedBlack *raiz);
void emOrdem_RedBlack(RedBlack *raiz);
void posOrdem_RedBlack(RedBlack *raiz);


void libera_RedBlack(RedBlack *raiz);



// Funcao que consulta existencia de um valor
// Retorna 1 se ele existe e 0 caso contrario
int consulta_RedBlack(RedBlack* raiz, int valor);

#endif /* RedBlackTree_h */
