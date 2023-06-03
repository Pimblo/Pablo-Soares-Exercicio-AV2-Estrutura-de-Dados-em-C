typedef struct No{
  int chave;
  struct No *left, *right;
} No;

typedef struct{
  No *raiz;
  int tam;
} ArvB;

No* INSERT(No *raiz, int valor){
  if(raiz == NULL){
    No *novo = (No *)malloc(sizeof(No));
    novo->chave = valor;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
  }else{
    if(valor < raiz->chave){
        raiz->left = INSERT(raiz->left, valor);
    }
    if(valor > raiz->chave){
        raiz->right = INSERT(raiz->right, valor);
    }
    return raiz;
  }
}

No* VALOR(No* raiz){
  int n;
  int tam;    
    
  printf("\nInsira um item: \n");
  scanf("%d", &n);
  raiz = INSERT(raiz, n);
  return raiz;
}

No* REMOVE(No *raiz, int item){
  if(raiz == NULL){
    printf("Valor Indisponível\n");
    return NULL;
  }else{
    if(raiz->chave == item){
      if(raiz->left == NULL && raiz->right == NULL){
        free(raiz);
        return NULL;
      }
      else{
        if(raiz->left == NULL || raiz->right == NULL){
          No* aux;
          if(raiz->left != NULL){
            aux = raiz->left;
          }else{
            aux= raiz->right;
            free(raiz);
            return aux;
          }
        }else{
          No* aux = raiz->left;
          while(aux->right != NULL)
              aux = aux->right;
          raiz->chave = aux->chave;
          aux->chave = item;
          raiz->left = REMOVE(raiz->left, item);
          return raiz;
        }
      }
    }else{
      if(item < raiz->chave){
        raiz->left = REMOVE(raiz->left, item);
      }else{
        raiz->right = REMOVE(raiz->right, item);
        return raiz;
      }
    }
  }
}

void PrintA(No *raiz){
  if(raiz != NULL) {
    PrintA(raiz->left);
    printf("%d ", raiz->chave);
    PrintA(raiz->right);
  }
}

void SEARCH(No* raiz, int valor){
  if(raiz == NULL){
    printf("\nValor Indisponível\n");
  }else{
    if(raiz->chave == valor){
      printf("\nValor encontrado\n");
    }else if(valor < raiz->chave){
      SEARCH(raiz->left, valor);
    }else{
      SEARCH(raiz->right, valor);
    }
  }
}

void PrintRL(No* raiz){
  if(raiz != NULL){
    PrintRL(raiz->right);
    printf("%d ", raiz->chave);
    PrintRL(raiz->left);
  }
}

void FindBIG(No* raiz){
  if(raiz == NULL){
    printf("\nÁrvore vazia!!!\n");
    return 0;
  }else if(raiz->right != NULL){
    return FindBIG(raiz->right);
  }else{
    printf("\nMaior Elemento: %d\n", raiz->chave);
    return raiz->chave;
  }
}
