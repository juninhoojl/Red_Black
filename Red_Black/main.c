//
//  main.c
//  Red_Black
//  Created by:
//  Andre Felipe Magalhães Silva - 2017020218
//  José Luiz Corrêa Junior - 2017020933
//  Copyright 2019. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RedBlackTree.h"
#include "es.h"

#define true 1
#define false 0

int main(int argc, const char * argv[]){
    
    int aux = 0, tam = 0, tipoArquivo = 0, *vet, verifica = 0, opcao = 0;
    char nomeArq[30], op = '\0';
    FILE *arq;

//Leitura e criacao de arquivo
    
    printf("Deseja gerar um arquivo? sim[s] nao[n]\n");
    while (op != 's' && op != 'S' && op != 'n' && op != 'N' ) {
        if (op != '\0')
            printf("Opcao invalida, digite novamente: ");
        scanf("%s", &op);
    } // Se a resposta for sim
    if (op == 's' || op == 'S') {
        
        printf("Digite o nome que deseja: ");
        scanf("%s",nomeArq);
        
        printf("Digite a quantidade de elementos que deseja: ");
        scanf("%d", &tam);
        
        // Criando arquivo solicitado
        arq = fopen(nomeArq, "w");
        if (!arq){//se o arq nao é nulo
            printf("Erro ao criar arquivo\n");
            exit(1);
        }
        
        //Capturar opcao do tipo de arquivo
        printf("\nTipo de arquivo:\n");
        printf("\t1 - Aleatorio\n");
        printf("\t2 - Ordenado\n");
        printf("\t3 - Invertido\n");
        printf("Digite a opcao desejada: ");
        while (tipoArquivo != 1 && tipoArquivo != 2 && tipoArquivo != 3) {
            if (tipoArquivo){
                printf("Opcao invalida, digite novamente: ");
            }
            
            scanf("%d",&tipoArquivo);
        }
        
        //Escolhe o tipo de aquivo
        verifica = gerarArquivo(arq, tam, tipoArquivo);
        if (verifica) { // erro em alocar
            return 1;
        }
        tipoArquivo = 0;
        
        //Depois de escrever fecha
        fclose(arq);
        //Se escreveu, pergunta se quer usar
        
        arq = fopen(nomeArq, "r");
        if (!arq){//se o arq nao é nulo
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }
        
        vet = (int*)malloc(tam*sizeof(int));
        if (vet == NULL){ // Erro ao alocar
            return 1;
        }
        
        //Ler arquivo
        aux = lerArquivo(vet, arq, tam);
        
        //Depois de ler fecha
        fclose(arq);
        
        if (aux == 1) {
            printf("\nTamanho do arquivo é maior que o especificado!");
            printf("\nO programa sera encerrado\n");
            exit(1);
        }else if (aux == 2){
            printf("\nTamanho do arquivo é menor que o especificado!");
            printf("\nO programa sera encerrado\n");
            exit(1);
        }
        
    }else{
        
        //O fopen retorna o endereco da primeira posicao onde o aquivo esta na memoria
        printf("Digite o nome do arquivo de entrada: ");
        fflush(stdin);
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
            printf("\nO programa sera encerrado\n");
            exit(1);
        }else if (aux == 2){
            printf("\nTamanho do arquivo é menor que o especificado!");
            printf("\nO programa sera encerrado\n");
            exit(1);
        }
    }
    
    
    //Ate aqui o Vet vai conter o que tem que estar na arvore
    while(true){
        
        printf("\n---------------------------------------------");
        printf("\nOpcoes:\n");
        printf("\t1. Inserir novo elemento na árvore 2-3-4\n");
        printf("\t2. Remover elemento da árvore 2-3-4\n");
        printf("\t3. Imprimir árvore 2-3-4\n");
        printf("\t4. Converter em uma árvore rubro-negra\n");
        printf("\t5. Sair\n");
        printf("---------------------------------------------\n");
        printf("Digite a opcao desejada: ");
        
        //Captura opcao
        scanf("%d",&opcao);

        switch (opcao) {
            case 1: // Insere na arvore 2-3-4
                printf("Opcao 1\n");
                break;
            case 2: // Remove na arvore 2-3-4
                printf("Opcao 2\n");
                break;
            case 3: // Imprimir arvore 2-3-4
                printf("Opcao 3\n");
                break;
            case 4: // Converter em rubro negra
                printf("Opcao 4\n");
                break;
            case 5: // Sair
                printf("Opcao 5 - Sair\n");
                return 1;
                break;
            default: // Opcao invalida
                printf("Opcao Invalida!\n");
                break;
        }
        
    };
    
    
    
    
//Loop ate 4 ou 5
//Árvores Balanceadas : Menu
//1. Inserir novo elemento na árvore 2-3-4
//2. Remover elemento da árvore 2-3-4
//3. Imprimir árvore 2-3-4 (pesquisar melhor forma de apresentar uma b-tree na tela)
//4. Converter em uma árvore rubro-negra
//5. Sair

//Loop ate 4
//Árvores Balanceadas : Menu
//1. Inserir novo elemento na árvore rubro-negra
//2. Remover elemento da árvore rubro-negra
//3. Imprimir árvore rubro-negra
//4. Sair


    return 0;
}
