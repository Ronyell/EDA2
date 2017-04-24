#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

#define MAX_LENGHT 100000

void inicializesVector(int * vectorNumbers);
void heapify(int * vectorNumbers, int position, int actualLenght);
void buildHeap(int * vectorNumbers, int actualLenght);//build heap one vector
void buildHeapTwo(int * vectorNumbers, int * vectorNumbersAux, int actualLenght);//build heap two vectors
bool siftUp(int * vectorNumbers, int actualLenght, int numberInsert);
int removeHeap(int * vectorNumbers, int actualLenght);
void destroyHeap(int * vectorNumbers, int * actualLenght);
void displayVector(int * vectorNumbers, int actualLenght);
void header();

int main(){
  int vectorNumbers[MAX_LENGHT];
  int vectorNumbersAux[MAX_LENGHT];
  int actualLenght = MAX_LENGHT;
  int actualLenghtTwo = MAX_LENGHT;

  header();

  inicializesVector(vectorNumbersAux);

  clock_t tInicioB, tFimB, tDecorridoB;
  tInicioB = clock();

  int vectorNumbersTwo[MAX_LENGHT];
  buildHeapTwo(vectorNumbersAux, vectorNumbersTwo, actualLenghtTwo);
  destroyHeap(vectorNumbersTwo, &actualLenghtTwo);

  tFimB = clock();
  tDecorridoB = tFimB - tInicioB;

  cout << endl << endl << endl<< "Tempo decorrido 2:" << double(tDecorridoB)/CLOCKS_PER_SEC << endl << endl << endl;


  inicializesVector(vectorNumbers);

  clock_t tInicio, tFim, tDecorrido;
  tInicio = clock();

  buildHeap(vectorNumbers, actualLenght);
  destroyHeap(vectorNumbers, &actualLenght);

  tFim = clock();
  tDecorrido = tFim - tInicio;

  cout << endl << endl << endl<< "Tempo decorrido 1:" << double(tDecorrido)/CLOCKS_PER_SEC << endl << endl << endl;

  return 0;
}

void inicializesVector(int * vectorNumbers){
  for(int count = 0; count < MAX_LENGHT; count ++ ){
    vectorNumbers[count] = rand() % 10000000;
  }
}


void heapify(int * vectorNumbers, int position, int actualLenght){
  int left = 2 * position;
  int right = 2 * position + 1;
  int largest = position;


  if (left < actualLenght && vectorNumbers[left] > vectorNumbers[largest]){
    largest = left;
  }

  if (right < actualLenght && vectorNumbers[right] > vectorNumbers[largest]){
    largest = right;
  }

  if (largest != position) {
     int aux = vectorNumbers[position];
     vectorNumbers[position] = vectorNumbers[largest];
     vectorNumbers[largest] = aux;

     heapify(vectorNumbers, largest, actualLenght);
  }
}

void buildHeap(int * vectorNumbers, int actualLenght){
  int halfLength = actualLenght/2;

  for (int count = halfLength; count >= 0; count--) {
    heapify(vectorNumbers, count, actualLenght);
  }

}


void buildHeapTwo(int * vectorNumbers, int * vectorNumbersAux, int actualLenght){
  int actualLenghtAux = 0;

  for (int count = 0; count < actualLenght; count++) {
    siftUp(vectorNumbersAux, actualLenghtAux, vectorNumbers[count]);
    actualLenghtAux++;
  }
}

bool siftUp(int * vectorNumbers, int actualLenght, int numberInsert){

  if (actualLenght == MAX_LENGHT){
    return false;
  }

  int count = actualLenght;
  int parent = count/2;

  vectorNumbers[count] = numberInsert;

  while (count > 0 && vectorNumbers[parent] < vectorNumbers[count]){
     int aux = vectorNumbers[count];
     vectorNumbers[count] = vectorNumbers[parent];
     vectorNumbers[parent] = aux;
     count = parent;
     parent = count/2;
  }
  return true;
}

int removeHeap(int * vectorNumbers, int  actualLenght){
  int numberRemove = vectorNumbers[0];

  actualLenght = actualLenght - 1;
  vectorNumbers[0] = vectorNumbers[actualLenght];

  heapify(vectorNumbers, 0, actualLenght);

  return numberRemove;
}

void destroyHeap(int * vectorNumbers, int * actualLenght){
  int numberRemove = 0;
  int lenght = *actualLenght;

  for(int count = 0; count < lenght; count ++){
    numberRemove = removeHeap(vectorNumbers, *actualLenght);
    *actualLenght = *actualLenght - 1;
    cout << numberRemove << " ";
  }
}

void displayVector(int * vectorNumbers, int actualLenght){
  for(int count = 0; count < actualLenght; count++){
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
  cout <<("Tema: Ordenação HeapSort em vetor\n\n");
}
