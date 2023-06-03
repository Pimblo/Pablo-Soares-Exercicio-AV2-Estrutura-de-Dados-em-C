#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "pilha.h"
#include "fila.h"
#include "arv.h"

int main(){
  int op, np, nf, na;
  int valor, item, remove, search;

  NodeP *PILHA = (NodeP*)malloc(sizeof(NodeP));
  PILHA->prox = NULL;
  int tam = 0;
  
  NodeF *FILA = (NodeF*)malloc(sizeof(NodeF));
  FILA->prox = NULL;

  ArvB arv;
  arv.raiz = NULL;
  No *raiz = NULL;


  do{
    printf("Selecione a opção desejada: \n");
    printf("(1)-PILHA\n");
    printf("(2)-FILA\n");
    printf("(3)-ÁRVORE\n");
    printf("(0)-SAIR\n");
    printf(">");
    scanf("%d", &op);

    switch(op){
      case 1:
      do{
        printf("\nSelecione a Função da Pilha:\n");
        printf("(1)-EMPILHAR\n");
        printf("(2)-DESEMPILHAR\n");
        printf("(3)-IMPRIMIR PILHA\n");
        printf("(4)-IMPRIMIR TOPO DA PILHA\n");
        printf("(5)-LIMPAR PILHA\n");
        printf("(0)-SAIR\n");
        printf(">");
        scanf("%d", &np);

        switch(np){
          case 1: PUSH(PILHA, tam); break;
          case 2: POP(PILHA, tam); break;
          case 3: PrintP(PILHA, tam); break;
          case 4: PrintTOP(PILHA); break;
          case 5: CLEANP(PILHA); break;
          case 0: break;
          default: printf("\n-OPÇÃO INVÁLIDA-\n"); break;
        }
      }while(np != 0); 
      break;

      case 2:
      do{
        printf("\nSelecione a Função da Fila:\n");
        printf("(1)-ENFILEIRAR\n");
        printf("(2)-DESENFILEIRAR\n");
        printf("(3)-IMPRIMIR FILA\n");
        printf("(4)-IMPRIMIR MAIOR ELEMENTO\n");
        printf("(5)-IMPRIMIR MENOR ELEMENTO\n");
        printf("(6)-LIMPAR\n");
        printf("(0)-SAIR\n");
        printf(">");
        scanf("%d", &nf);

        switch(nf){
          case 1: ENQUEUE(FILA, tam); break;
          case 2: DEQUEUE(FILA, tam); break;
          case 3: PRINTF(FILA, tam); break;
          case 4: MAIORF(FILA); break;
          case 5: MENORF(FILA); break;
          case 6: CLEANF(FILA); break;
          case 0: break;
          default: printf("\n-OPÇÃO INVÁLIDA-\n"); break;
        }
      }while(nf != 0);
      break;

      case 3:
      do{
        printf("\nSelecione a Função da Árvore:\n");
        printf("(1)-ADICIONAR ITEM\n");
        printf("(2)-IMPRIMIR ÁRVORE\n");
        printf("(3)-IMPRIMIR ÁRVORE DA DIREITA PRA ESQUERDA\n");
        printf("(4)-IMPRIMIR MAIOR ITEM\n");
        printf("(5)-BUSCAR ITEM\n");
        printf("(6)-REMOVER ITEM\n");
        printf("(0)-SAIR\n");
        printf("\n>");
        scanf("%d", &na);

        switch(na){
          case 1: raiz = VALOR(raiz); break;
          case 2: PrintA(raiz); break;
          case 3: PrintRL(raiz); break;
          case 4: FindBIG(raiz); break;
          case 5: 
            printf("\nBusque um item:\n");
            scanf("%d", &search); 
            SEARCH(raiz, search); break;
          case 6: 
            printf("\nRemova um item:\n");
            scanf("%d", &remove); 
            raiz = REMOVE(raiz, remove); break;
          case 0: break;
          default: printf("\n-OPÇÃO INVÁLIDA-\n"); break;
        }
      }while(na != 0);
      default:
      break;
    }
  }while(op != 0);
  printf("---FIM DE CÓDIGO---");
  return 0;
}
