//
//  es.h
//  Red_Black
//  Created by:
//  Andre Felipe Magalhães Silva - 2017020218
//  José Luiz Corrêa Junior - 2017020933
//  Copyright 2019. All rights reserved.
//

#ifndef es_h
#define es_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//A funcao le um arquivo de entrada e aloca os elementos em um vetor
//A funcao le numeros inteiros apenas
//Se retornar 1 o arquivo contem mais valores que o especificado
//Se retornar 2 o arquivo contem menos valores que o especificado

int lerArquivo(int vet[], FILE *arqEntrada, int tam);

void escreveArquivo(int vet[], FILE *arqSaida, int tam);

void imprimeVetor(int vet[], int tam);

//Se for opcao 1, é aleatorio, se 2 é crescente, se 3 é decrecente
int gerarArquivo(FILE *arqSaida, int qtd, int op);

#endif /* es_h */
