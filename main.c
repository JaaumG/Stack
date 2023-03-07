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

bool pop(pilha * topo, int * valor){
    if(*topo!=NULL){
        pilha aux = *topo;
        *valor = aux->valor;
        *topo = aux->prox;
        free(aux);
        return true;
    }
    return false;
}

int main() {

    int valor;
    pilha topo;
    criar(&topo);
    if(push(&topo, 10)){
        printf("Push na pilha ok!\n");
    }
    if(pop(&topo, &valor)){
        printf("Pop na pilha ok! Valor removido: %d\n", valor);
    }
    return 0;

}

