typedef struct NodeF{
  int conteudo, tam;
  struct NodeF *prox;
}NodeF;

int EMPTY(NodeF *FILA){
  if(FILA->prox == NULL){
    return 1;
  }else{
    return 0;
  }
}

void ENQUEUE(NodeF *FILA, int tam){
  NodeF *novo=(NodeF*)malloc(sizeof(NodeF));
  novo->prox = NULL;
  printf("Novo item da Fila: \n");
  scanf("%d", &novo->conteudo);
  if(EMPTY(FILA)){
    FILA->prox=novo;
  }else{
    NodeF *tmp = FILA->prox;
    while(tmp->prox != NULL){
      tmp = tmp->prox;
    }
    tmp->prox = novo;
  }
  tam++;
}

void DEQUEUE(NodeF *FILA, int tam){
  if(FILA->prox == NULL){
    printf("Fila vazia.\n");
    return;
  }else{
    NodeF *tmp = FILA->prox;
    FILA->prox = tmp->prox;
    tam--;
    free(tmp);
  }
}  

void PRINTF(NodeF *FILA, int tam){
  if(EMPTY(FILA)){
    printf("Fila vazia!!!\n");
    return;
  }
  NodeF *tmp = FILA -> prox;
  printf("\nFila: \n");
  while(tmp != NULL){
    printf("%3d ", tmp->conteudo);
    tmp = tmp->prox;
    tam++;
  }
}

void MAIORF(NodeF *FILA){
  if(EMPTY(FILA)){
    printf("Fila vazia!!!\n");
    return;
  }else{
    int maior = INT_MIN;
    NodeF *tmp = FILA->prox;
    while(tmp != NULL){
      if(tmp->conteudo>maior){
        maior = tmp->conteudo;
      }
      tmp = tmp->prox;
    }
    printf("Maior Elemento: %d\n", maior);
  }
}

void MENORF(NodeF *FILA){
  if(EMPTY(FILA)){
    printf("Fila vazia!!!\n");
    return;
  }else{
    int menor = INT_MAX;
    NodeF *tmp = FILA->prox;
    while(tmp != NULL){
      if(tmp->conteudo < menor){
        menor = tmp->conteudo;
      }
      tmp = tmp->prox;
    }
    printf("Menor Elemento: %d\n", menor);
  }
}

void CLEANF(NodeF *FILA){
  if(EMPTY(FILA)){
    printf("Fila vazia!!!\n");
    return;
  }else{
    while(!EMPTY(FILA)){
      NodeF *penultimo = FILA;
      NodeF *ultimo = FILA -> prox;
      while(ultimo->prox != NULL){
        penultimo = ultimo;
        ultimo = ultimo->prox;
      }
      free(ultimo);
      penultimo->prox = NULL;
    }
  }
}
