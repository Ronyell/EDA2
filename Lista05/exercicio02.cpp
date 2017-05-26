#include <iostream>
#include <cstdlib>
#include <math.h>

#define MAX_LENGHT 10

using namespace std;
void header();
void inicializesVector(int * vectorNumbers);
void displayVector(int * vectorNumbers, int actualLenght);
void displayHalf(int * vectorNumbers, int init, int end);
int merge(int *vectorNumbers, int init, int half, int end);
int mergeSort(int *vectorNumbers, int init, int end);


int main(){
  int vectorNumbers[MAX_LENGHT] = {0,1,2,4,5,6,7,8,9,3};
  header();
  //inicializesVector(vectorNumbers);
  displayVector(vectorNumbers, MAX_LENGHT);
  int countingInvesion = mergeSort(vectorNumbers, 0, MAX_LENGHT-1);
  cout << "INVERSIONS: " << countingInvesion << endl;
  return 0;
}

void inicializesVector(int * vectorNumbers){
  srand(time(NULL));
  for(int count = 0; count < MAX_LENGHT; count ++ ){
    vectorNumbers[count] = rand() % 100;
  }
}

void displayVector(int * vectorNumbers, int actualLenght){
  for(int count = 0; count < actualLenght; count++){
    cout << vectorNumbers[count] << " ";
  }

  cout << endl;
}

int merge(int *vectorNumbers, int init, int half, int end){
  int countInversion = 0;
  bool end1=false, end2=false;
  int *vectorNumbersAux, length;
  int count1 = init, count2 = half+1;

  length = end-init+1;
  vectorNumbersAux = (int *) malloc(length*sizeof(int));
  int countAux = 0;

  while(!end1 && !end2){
    if(vectorNumbers[count1] < vectorNumbers[count2]){
      vectorNumbersAux[countAux]=vectorNumbers[count1];
      count1++;
      if(count1 > half){
        end1 = true;
      }
    }else{
      vectorNumbersAux[countAux]=vectorNumbers[count2];
      count2++;
      if(count2 > end){
        end2 = true;
      }
        for(int countInAux = count1; countInAux <= half; countInAux++){
          if(vectorNumbers[countInAux] > 2*vectorNumbers[count2-1]){
            countInversion = countInversion + (half - countInAux + 1);
            break;
          }
        }

    }
    countAux++;
  }
  if(!end1){
    for (;countAux < length; countAux++){
      vectorNumbersAux[countAux]=vectorNumbers[count1];
      count1 ++;
    }
  }

  if(!end2){
    for (;countAux < length; countAux++){
      vectorNumbersAux[countAux]=vectorNumbers[count2];
      count2 ++;
    }
  }

  int secondPosition = init;

  for(int i=0; i<length; i++){
    vectorNumbers[secondPosition]=vectorNumbersAux[i];
    secondPosition++;

  }
  return countInversion;

}

int mergeSort(int *vectorNumbers, int init, int end){
  int countInversion = 0;
  if (init < end){
    int half = (int) floor((init+end)/2);
    countInversion = mergeSort(vectorNumbers,init,half);
    countInversion += mergeSort(vectorNumbers,half+1,end);
    countInversion += merge(vectorNumbers,init,half,end);
    displayHalf(vectorNumbers, init,end);
  }
  return countInversion;
}

void displayHalf(int * vectorNumbers, int init, int end){
  for(int count = init; count <= end; count++){
    cout << vectorNumbers[count] << " ";
  }

  cout << endl;
}

void header() {
  cout << ("Universidade de Brasilia - Campus Gama\n");
  cout <<("Disciplina: Estrutura de Dados e Algoritmos 2\n");
  cout <<("Professor: Mauricio Serrano\n");
  cout <<("Aluno: Gustavo Vieira Braz Gonçalves\n");
  cout <<("Aluno: Ronyell Henrique dos Santos\n");
  cout <<("Tema: Ordenação MergeSort Recursivo\n\n");
}
