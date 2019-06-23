//
//  RedBlackTree.c
//  Red_Black
//  Created by:
//  Andre Felipe Magalhães Silva - 2017020218
//  José Luiz Corrêa Junior - 2017020933
//  Copyright 2019. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "RedBlackTree.h"

//Define cores
#define RED 1
#define BLACK 0

struct NO{
    int info; //Dado contido
    struct NO *esq; //Sub Arv esq
    struct NO *dir; //Sub Arv dir
    int cor; // Cor do no
};


RedBlack* cria_RedBlack(void){
    // Ou seja
    RedBlack* raiz = (RedBlack*) malloc(sizeof(RedBlack));
    
    //Se deu certo, aponta null
    if(raiz != NULL)
        *raiz = NULL;
    
    return raiz;
}


//Pega a cor do no
int cor(struct NO* H){
    if(H == NULL) // Se for nulo sempre é preto
        return BLACK;
    else // Senao retorna o que tem de cor nele
        return H->cor;
}


//Funcao para trocar as cores dos nos
// Considerando um no H
void trocaCor(struct NO* H){
    H->cor = !H->cor; //Recebe o oposto
    if (H->esq != NULL){ // Se for null nao faz nada
        H->esq->cor = !H->esq->cor;
    }
    if (H->dir != NULL){ // Se for null nao faz nada
        H->dir->cor = !H->dir->cor;
    }

}


// Funcoes de rotacao da arvore

// Rotacao a esquerda e a direita

// Atualiza os ponteiros de lugar complexidade (1)

//Rotacao a esquerda
// - Recebe um nó A com B como filho a direito
// - Move B para o lugar de A, e A se torna filho esquerdo de B
// - B recebe a cor do A, e A fica vermelho

struct NO* rotacionaEsquerda(struct NO* A){
    struct NO* B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

// A rotacao se preocupa em rotacionar, ja
//que nao podemos ter dois filhos vemelhos na sequencia
// A rotacao nao corrige todos os problemas
//Tambem nao podemos ter filho a direita vermelho

//Rotacao a esquerda
// - Recebe um nó A com B como filho a esquerdo
// - Move B para o lugar de A, e A se torna filho direito de B
// - B recebe a cor do A, e A fica vermelho

struct NO* rotacionaDireita(struct NO* A){
    struct NO* B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

//Movendo os nos vermelhos
//Quando fazemos rotacoes e trocas de
// cores, podemos criar uma nova
// violacao das propriedade da arvore

// # funcoes para garantir propriedades

// mover no vermelho para esquerda
// mover um no vermelho para a direita
// arrumar o balanceamento geral ou sub

// Essas funcoes movimentam um no
// vemelho para uma sub esq ou dir
// dependendo de como esta


// ******* Mover um no vermelho para a esquerda

// recebe um no H e troca as cores dele e de seus filhos
// se o filho a esquerda do filho direito é vermelho, aplica rotacao a direira
// no filho direito e uma rotacao esquerda no pai
// troca as cores do no pai e de seus filhos


struct NO* move2EsqRED(struct NO* H){
    trocaCor(H);
    if (cor(H->dir->esq) == RED) {
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        trocaCor(H);
    }
    //Retorna quem ficou sendo a nova raiz da sub arvore
    return H;
}

// ******* Mover um no vermelho para a direita

// recebe um no H e troca as cores dele e de seus filhos
// se o filho a esquerda do filho esquerdo é vermelho, aplica rotacao a direita no pai
// troca as cores do no pai e de seus filhos



struct NO* move2DirRED(struct NO* H){
    trocaCor(H);
    if (cor(H->esq->esq) == RED) {
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaDireita(H);
        trocaCor(H);
    }
    //Retorna quem ficou sendo a nova raiz da sub arvore
    return H;
}


// ******** Funcao arrumar balanceamento
// Se o filho direito é vermelho
//          Rotaciona a esquerda
// Se o filho direito e o neto da esquerda sao vermelhos
//          Rotaciona a direita
// Se ambos os filhos sao vermelhos
//          Troca cor do pai e dos filhos

struct NO* balancear(struct NO* H){
    
    //No vermelho é sempre filho a esquerda
    if(cor(H->dir) == RED){
        H = rotacionaEsquerda(H);
    }
    //Filho da direita e neto da esquerda sao vermelhos
    if(H->esq != NULL && cor(H->dir) == RED && cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
    }
    
    // Dois filhos vermelhos: troca cor!
    if (cor(H->esq) == RED && cor(H->dir) == RED) {
        trocaCor(H);
    }
    
    return H;
}


// Insere na arvore
int insere_RedBlack(RedBlack* raiz, int valor){
    
    int resp;
    //funcao responsavel pela busca do local
    // de insercao do no
    
    *raiz = insereNO(*raiz,valor,&resp);
    if ((*raiz) != NULL){
        (*raiz)->cor = BLACK;
    }
    
    // se deu ou nao para inserir
    return resp;
}


struct NO* insereNO(struct NO* H, int valor, int *resp){
    
    //Arvore esta vazia ou chegou num no nulo
    if(H == NULL){
        struct NO *novo;//crio no, aloca memoria
        novo = (struct NO*)malloc(sizeof(struct NO));
        
        if (novo == NULL){ //Caso a insercao falhe
            *resp = 0;
            return NULL;
        }
        
        //Como é folha, tem filhos nulos
        novo -> info = valor;
        novo -> cor = RED;
        novo -> dir = NULL;
        novo -> esq = NULL;
        *resp = 1;
        
    
        // retorna a subarvore
        return novo;
    }
    
    //Recursivamente ate um ponto de insercao
    //Outro caso, valor duplicado
    if (valor == H->info){
        *resp = 0; // Valor duplicado nao insere
    }else{
        if (valor < H->info) { // se o valor for menor, pesquisa na esquerda, senao, direita
            H->esq = insereNO(H->esq, valor, resp);
        }else{
            H->dir = insereNO(H->dir, valor, resp);
        }
    }
    
    //Depois de voltar da recursao, temos que tratar o balanceamento
    
    // Nao pode ter filho direito vermelho
    if(cor(H->dir) == RED && cor(H->esq) == BLACK){
        H = rotacionaEsquerda(H);
    }
    
    // Nao pode ter dois vermelhos seguidos
    if(cor(H->esq) == RED && cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
    }
    
    //Nao podemos ter dois filhos vermelhos
    if(cor(H->esq) == RED && cor(H->dir) == RED){
        trocaCor(H);
    }
    

    
    return H;
}

// Remocao da arvore rubro negra
// 3 casos de remocao
//  no folha (sem filhos)
//  no com 1 filho
//  no com 2 filhos
//
// ** Cuidados
// Nao podemos remover de uma arvore vazia
// removendo o ultimo no, a arvore fica vazia

//Balanceamento
//  ao voltar da recursao, verifique as propriedades de cada sub-arvore
// aplique a rotacao ou mudanca de cor necessaria se alguma propriedade foi violada



int remove_RedBlack(RedBlack* raiz, int valor){
    
    if(consulta_RedBlack(raiz,valor)){//confere se existe
        
        struct NO* h = *raiz;
        //funcao responsavel pela busca
        //do no a ser removido
        
        *raiz = removeNO(h,valor); // se a raiz nao ficar vazia, pinta de preto
        if(*raiz != NULL){
            (*raiz)->cor = BLACK;
        }
            
            return 1; // deu certo
    }else{// se o no nao existe
        return 0; // nao deu certo
    }

}

//Antes de remover ja faz algumas alteracoes
struct NO* removeNO(struct NO* H, int valor){
    
    // Se o valor a ser removido for menor
    if(valor < H ->info){
        if (cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK){
            H = move2EsqRED(H);
        }
        
        H ->esq = removeNO(H->esq, valor);
        
    // Se o valor a ser removido for maior
    }else{ // An
        if (cor(H->esq) == RED) {
            H = rotacionaDireita(H);
        }
        
        if (valor == H->info && (H->dir == NULL)) {
            free(H);
            return NULL;
        }
        
        if(cor(H->dir) == BLACK && cor(H->dir->esq) == BLACK){
            //Funcao que move no vermelho pra direita
            H = move2DirRED(H);
        }
  
        if (valor == H->info){
            //Procura o menor valor
            //Copia o menor no lugar do H e depois remove ele, para nao comprometer a recursao
            struct NO* x = procuraMenor(H->dir);
            H -> info = x->info;
            H->dir = removeNO(H->dir, valor);
        }else{
            
            H->dir = removeNO(H->dir, valor);
        }
    
    }
    
        return balancear(H); //So verifica possibilidades de violacao da regra
    
}
    

struct NO* removeMenor(struct NO* H){
    
    if(H->esq == NULL){
        free(H);
        return NULL;
    }
    
    if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK){
        H = move2EsqRED(H);
    }

    H->esq = removeMenor(H->esq);
    
    return balancear(H);
}

struct NO* procuraMenor(struct NO* atual){

    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }

    return no1;
}


// Funcao que consulta existencia de um valor
// Retorna 1 se ele existe e 0 caso contrario
int consulta_RedBlack(RedBlack* raiz, int valor){
    
    //Raiz nula, nao tem nenhum valor
    if(raiz == NULL)
        return 0;
    
    struct NO* atual = *raiz;
    
    //Ate o atual for nulo vai procurando
    while(atual != NULL){
        if(valor == atual->info){
            return 1;// No existe
        }
        
        if(valor > atual->info){
            atual = atual->dir;
        }else{
            
            atual = atual->esq;
        }
    }

    //Caso termine chegue aqui nao encontrou
    return 0;
}

void preOrdem_RedBlack(RedBlack *raiz){
    
    //O valor que recebeu nao é null
    if (raiz == NULL) {
        return;
    }//se onde aponta nao é null
    if(*raiz != NULL) {
        
        printf("%d\n",(*raiz)->info);
        preOrdem_RedBlack(&((*raiz)->esq));
        preOrdem_RedBlack(&((*raiz)->dir));
        
    }
    
}

void emOrdem_RedBlack(RedBlack *raiz){
    
    //O valor que recebeu nao é null
    if (raiz == NULL) {
        return;
    }//se onde aponta nao é null
    if(*raiz != NULL) {
        
        emOrdem_RedBlack(&((*raiz)->esq));
        printf("%d\n",(*raiz)->info);
        emOrdem_RedBlack(&((*raiz)->dir));
    }
    
}

void posOrdem_RedBlack(RedBlack *raiz){
    
    //O valor que recebeu nao é null
    if (raiz == NULL) {
        return;
    }//se onde aponta nao é null
    if(*raiz != NULL) {
        
        posOrdem_RedBlack(&((*raiz)->esq));
        posOrdem_RedBlack(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
        
    }
}
