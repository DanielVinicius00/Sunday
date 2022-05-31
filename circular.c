#include "TCircularList.h"
#include <stdio.h>
#include <stdlib.h>
#define END 0
#define BEGIN 1

typedef struct no {
    int info;
    struct no* prox;
}TNo;

TNo* TNo_createNFill(int);
_Bool TCircularList_insert(TCircularList*, int, char);

struct linked_list{
    TNo* fim;
};

TCircularList* TCircularList_create(){
    TCircularList* nova = malloc(sizeof(TCircularList));
    if(nova!=NULL){
        nova->fim = NULL;
    } return nova;
}

_Bool TCircularList_insert_begin(TCircularList* lista, int info){
    return TCircularList_insert(lista, info, BEGIN);
}

_Bool TCircularList_insert_end(TCircularList* lista, int info){
    return TCircularList_insert(lista, info, END);
}

void TCircularList_print(TCircularList* lista){
    if(lista->fim == NULL) return;

    TNo* aux = lista->fim->prox;

    do{
        if(aux==NULL) break;
        printf("%d ", aux->info);
        aux = aux->prox;
    }while(aux != lista->fim->prox);
    putchar('\n');
}

_Bool TCircularList_remove_after_n_steps(TCircularList* lista, int n){
    if(lista->fim == NULL) return false;
    TNo* x = lista->fim->prox;
    TNo* y = lista->fim;
    for(int i=0; i<n; i++){
        y = x;
        x = x->prox;
    }
    y->prox = x->prox;
    if(x==lista->fim)
        lista->fim = x->prox;
    printf("Removendo x = %d\n", x->info);
    free(x);
}

//Auxiliares

TNo* TNo_createNFill(int info){
    TNo* novo = malloc(sizeof(TNo));
    if(novo!=NULL){
        novo->info = info;
        novo->prox = NULL;
    } return novo;
}

_Bool TCircularList_insert(TCircularList* lista, int info, char flag){
    TNo* novo = TNo_createNFill(info);
    if(novo==NULL) return false;
    
    if(lista->fim == NULL){
        novo->prox = novo;
        lista->fim = novo;
    }
    else{
        novo->prox = lista->fim->prox;
        lista->fim->prox = novo;
    }
    if(flag == END)
        lista->fim = novo;

    return true;
}