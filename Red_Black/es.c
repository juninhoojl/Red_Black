//
//  es.c
//  Red_Black
//  Created by:
//  Andre Felipe Magalhães Silva - 2017020218
//  José Luiz Corrêa Junior - 2017020933
//  Vítor Siqueira Lobão - 2018004809
//  Copyright 2019. All rights reserved.
//

#include "es.h"

//Funcao para embaralhar vetor
void embaralha(int vet[], int tam){
    
    for (int i = 0; i < tam; i++)
    {
        int r = rand() % tam;
        
        int temp = vet[i];
        vet[i] = vet[r];
        vet[r] = temp;
    }
    
}

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
    for (i = 0; i<tam; i++){
        if (i+1 == tam){
            fprintf(arqSaida, "%d", vet[i]);
        }else{
            fprintf(arqSaida, "%d\n", vet[i]);
        }
    }

    return;
}


void imprimeVetor(int vet[], int tam){
    int i = 0;
    for (i = 0; i<tam; i++)
        printf("%d ", vet[i]);
    printf("\n");
    return;
}

void gerarAleatorio(FILE *arqSaida, int tam, int op){
    srand((int)time(NULL));
    
    int i = 0;
    
    if(op == 1){ // Aleatorio
        
        int *vet;
        
        vet = (int *) malloc(tam * sizeof(int));
        //Gera vetor ordenado e embaralha na sequencia
        
        for (i = 0; i < tam; i++)
            vet[i] = i;
        //Embaralha
        embaralha(vet, tam);
        //Grava no arquivo
        escreveArquivo(vet, arqSaida, tam);
        //Libera depois de usar
        free(vet);

    }else if (op == 2){ //Crescente
        for (i = 0; i < tam; i++){
            if (i+1 == tam){
                fprintf(arqSaida, "%d", i);
            }else{
                fprintf(arqSaida, "%d\n", i);
            }
        }
    }else{ //Decrescente, invertido
        for (i = tam-1; i >= 0; i--){
            if (i > 0){
                fprintf(arqSaida, "%d\n", i);
            }else{
                fprintf(arqSaida, "%d", i);
            }
        }
    }
    
    return;
}

