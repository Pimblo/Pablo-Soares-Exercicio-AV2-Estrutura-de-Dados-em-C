#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
  
int main() {
  int op, n;
  printf("Insira o tamanho do vetor:\n");
  scanf("%d", &n);
  int vet[n];
  printf("Preencha o vetor:\n");
  for(int i = 0; i < n; i++){
    scanf("%d", &vet[i]);
  }
do{
  printf("\nEscolha o método de ordenação: ");
  printf("\n1 - Bubble Sort");
  printf("\n2 - Isertion Sort");
  printf("\n0 - Sair\n");
  scanf("%d", &op);
  switch(op){
    
    case 1: 
      bubbleSort(vet, n);
      printf("Ordenação em BubbleSort: \n");
      printVet(vet, n);
      break;
    case 2: 
      insertSort(vet, n);
      printf("Ordenação em Isertion Sort:\n");
      printVet(vet, n);
      break;
    case 0: 
      break;
    default: 
      printf("Opção inválida");
      break;
  }
} while(op != 0);
  return 0;
}
