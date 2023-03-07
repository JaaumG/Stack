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

bool migrate(pilha * topo1, pilha * topo2, int * valor){
    if(*topo1!=NULL){
        if(pop(topo1, valor)){
            if(push(topo2, *valor)){
                return true;
            }
        }
    }
    return false;
}


void exibir(pilha * topo){
    if(*topo!=NULL){
        pilha aux = *topo;
        while(aux!=NULL){
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }
}

int main() {

    int valor;
    pilha topo, topo2;
    criar(&topo);
    criar(&topo2);
    int opcao;
   do{
    system("cls");
    printf("Pilha-1:");
    exibir(&topo);
    printf("Pilha-2:");
    exibir(&topo2);
    printf("\n1- Inserir\n");
    printf("2- Remover\n");
    printf("3- Migrar valor\n");
    printf("4- Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            system("cls");
            printf("Valor: ");
            scanf("%d", &valor);
            if(push(&topo, valor)){
                printf("Valor inserido com sucesso!\n");
            } else {
                printf("Erro ao inserir o valor!\n");
            }
            break;
        case 2:
            system("cls");
            if(pop(&topo, &valor)){
                printf("Valor removido com sucesso: %d\n", valor);
            } else {
                printf("Pilha vazia!\n");
            }
            break;
        case 3:
            system("cls");
            if(migrate(&topo, &topo2, &valor)){
                printf("Valor removido com sucesso: %d\n", valor);
            } else {
                printf("Pilha vazia!\n");
            }
            break;
        case 4:
            system("cls");
            printf("Finalizando o programa...\n");
            break;
        default:
            system("cls");
            printf("Opção inválida!\n");
        }
    } while(opcao!=4);
    return 0;

}

