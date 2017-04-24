
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int value;
struct node *next;
struct node *previous;
} Node;

void header() {
printf("Aluno: Gustavo Vieira Braz Gonçalves\n");
printf("Aluno: Ronyell Henrique dos Santos\n");
}

int partition(int *vector, int initial, int end) {
int left, right, pivot, auxiliary;
left = initial;
right = end;
pivot = vector[initial];

while(left < right){
  while(vector[left] <= pivot)
    left++;
  while(vector[right] > pivot)
    right--;

  if(left < right){
    auxiliary = vector[left];
    vector[left] = vector[right];
    vector[right] = auxiliary;
  }
}
vector[initial] = vector[right];
vector[right] = pivot;
return right;
}

void quickSort(int *vector, int initial, int end) {
int pivot;

if(end > initial){
  pivot = partition(vector, initial, end);
  quickSort(vector, initial, pivot-1);
  quickSort(vector, pivot+1, end);
}
}

Node *insert_node(Node *vector, int value) {

 Node *temporary, *initial;

 if(vector == NULL) {
    vector = (Node *)malloc(sizeof(Node));
    vector->value = value;
    vector->next = NULL;
    vector->previous = NULL;
    initial = vector;
  }

  else{
    vector = initial;

    while(vector->next != NULL)
      vector = vector->next;

    vector->next = (Node *)malloc(sizeof(Node));
    temporary = vector;
    vector = vector->next;
    vector->value = value;
    vector->previous = temporary;
    vector->next = NULL;
  }
  return initial;
}

int main() {

  int length, i, number, *store;
  Node *vector, *remove;

  header();

  vector = NULL;

  printf("\nDigite a quantidade de numeros a serem armazenados: ");
  scanf("%d", &length);

  store = (int *)malloc(length*sizeof(int));

  for(i=0; i<length; i++){
    printf("Digite o %d.o numero: ", i+1);
    scanf("%d", &number);
    store[i] = number;
    vector = insert_node(vector, number);
  }

  remove = vector;

  printf("\nOs numeros foram digitados nessa sequencia: \n");

  while(vector != NULL){
    printf("-> %d ", vector->value);
    vector = vector->next;
  }

  quickSort(store, 0, length-1);

  vector = remove;

  for(i=0; i<length; i++){
    vector->value = store[i];
    vector = vector->next;
  }

  vector = remove;

  printf("\n\nNumeros ordenados com QuickSort: \n [ ");

  while(vector != NULL){
    printf("%d ", vector->value);
    vector = vector->next;
  }
  printf("]\n\n");

  while(remove != NULL){
    vector = remove->next;
    free(remove);
    remove = vector;
  }

  free(store);

return 0;
}
