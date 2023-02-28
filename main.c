#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int valor;
    struct no * prox;
} no;

typedef no * pilha;

void criar(pilha * topo){
    *topo = NULL;
}

bool push(pilha * topo, int valor){
    pilha novo = (pilha)malloc(sizeof (no));
    if(novo!=NULL){
        novo->valor = valor;
        novo->prox = *topo;
        *topo = novo;
        return true;
    }
    return false;
}

void main() {

    pilha topo;
    criar(&topo);
    if(push(&topo, 10)){
        printf("Push na pilha ok!");
    }

}

