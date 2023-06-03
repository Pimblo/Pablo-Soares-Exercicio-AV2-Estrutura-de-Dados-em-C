void bubbleSort(int vet[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}
void insertSort(vet[], int n) {
  int i, j, k;
  for(i = 0; i <n; i++){
    k = vet[i];
    j = i - 1;
    while(j >= 0 && vet[j] > k){
      vet[j +1] = vet[j];
      j = j - 1;
    }
    vet[j + 1] = k;
  }
}
void printVet(int vet[], int n){
  for(int i = 0; i < n; i++){
    printf("%d ", vet[i]);
  }
  printf("\n");
}
