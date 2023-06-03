typedef struct NodeP{
  int item, tam;
  struct NodeP *prox;
}NodeP;

int vazia(NodeP *PILHA){
  if(PILHA->prox == NULL){
    return 1;
  }else{
    return 0;
  }
}

void PUSH(NodeP *PILHA, int tam){
  NodeP *novo=(NodeP *) malloc(sizeof(NodeP));
  novo->prox = NULL;
  printf("Novo item: \n");
  scanf("%d", &novo->item);
  if(vazia(PILHA)){
    PILHA->prox = novo;
  }else{
    NodeP *tmp = PILHA->prox;
    while(tmp->prox != NULL){
      tmp = tmp->prox;
    }
    tmp->prox = novo;
  }
  tam++; 
}

void PrintP(NodeP *PILHA, int tam){
  if(vazia(PILHA)){
    printf("Pilha vazia!\n");
  return;
  }
  NodeP *tmp;
  tmp = PILHA->prox;
  printf("\nPilha: \n");
  while(tmp != NULL){
    printf("%3d ", tmp->item);
    tmp = tmp->prox;
    tam++;
  }
  printf("\nQuantidade de itens: %d\n", tam);
  printf("\n ");
}

void POP(NodeP *PILHA, int tam){
  if(PILHA->prox == NULL){
    printf("\nPilha vazia!!!\n");
    return;
  }else{
    NodeP *ultimo = PILHA->prox;
    NodeP *penultimo = PILHA;
    while(ultimo->prox != NULL){
      penultimo = ultimo;
      ultimo = ultimo->prox;
    }
    free(ultimo);
    penultimo->prox = NULL;
    tam--; 
  }
}

void PrintTOP(NodeP *PILHA){
  if(vazia(PILHA)){
    printf("\nPilha vazia!!!\n");
    return;
  }else{
    NodeP *tmp = PILHA -> prox;
    printf("\nTopo da Pilha: \n");
    while(tmp->prox != NULL){
      tmp = tmp->prox;
    }
    printf("%3d ", tmp->item);
  }
}

void CLEANP(NodeP *PILHA){
  if(vazia(PILHA)){
    printf("\n!!!Pilha vazia!!!\n");
    return;
  }else{
    while(!vazia(PILHA)){
      NodeP *penultimo = PILHA;
      NodeP *ultimo = PILHA -> prox;
        while(ultimo->prox != NULL){
          penultimo = ultimo;
          ultimo = ultimo -> prox;
        }
      free(ultimo);
      penultimo -> prox = NULL;
    }
  }
}
