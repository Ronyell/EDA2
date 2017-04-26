#include <stdio.h>
#include <math.h>

void display(int * vetor, int tamanho);
void quickSort(int * vetor, int comeco, int fim);
void shellSort(int * vetor, int tamanho);

int main(){
  int vetor [9] = {9,1,8,3,4,1,8,5,6};
  int comeco = 0, fim = 8;
  // quickSort(vetor, comeco, fim);
  shellSort(vetor, 9);
  return 0;
}


void quickSort(int * vet, int comeco, int fim){
    int pivot, aux;
	int i, j;

	pivot = vet[(comeco+fim)/2];
  printf("PIVO:%d\n", pivot);
	i = comeco;
	j = fim;

	while(i < j){
		while(vet[i] < pivot)
			i++;

		while(vet[j] > pivot)
			j--;

		if(i < j){
			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			i++;
      j--;
    }

	}

	if(j > comeco){
    printf("====%d====\n", comeco);
    printf("====%d====\n", j);
		quickSort(vet, comeco, j);
  }

	if(i < fim){
    printf("((((((Inicio: %d))))))\n", j+1);
    printf("((((((%d))))))\n", fim);
		quickSort(vet, j+1, fim);
  }
}

void display(int * vetor, int tamanho){
  printf("+++++++++++++++++++++++++++++\n");
  for(int i = 0; i < tamanho; i++){
    printf("%d\n", vetor[i]);
  }
  printf("+++++++++++++++++++++++++++++\n");
}

void shellSort(int * vetor, int tamanho){
  display(vetor, tamanho);

  int gap = ceil(tamanho/2.0);

  while(gap){
    for(int i = 0; i < tamanho; i++){
      int posicao = i + gap;

      while(posicao < tamanho){
        if(vetor[posicao] < vetor[posicao - gap]){
          int aux = vetor[posicao];
    			vetor[posicao] = vetor[posicao - gap];
    			vetor[posicao - gap] = aux;
        }
        posicao += gap;
      }

    }
    display(vetor, tamanho);

    gap = ceil(gap / 2);
  }

//  display(vetor, tamanho);
}
