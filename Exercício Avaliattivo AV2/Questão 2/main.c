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
}
