#include <iostream>
#include <cstdlib>
#include <math.h>


using namespace std;

typedef struct tarefa{
	int tempoSupercomputador;
  int tempoComputador;
}Tarefa;

void header();
void merge(Tarefa *tarefas, int init, int half, int end);
void displayHalf(Tarefa *tarefas, int init, int end);
void mergeSort(Tarefa *tarefas, int init, int end);

int main(){
    int quantidade;

    header();

    cout << "Digite a quantidade de tarefas: ";
    cin >> quantidade;

    Tarefa * tarefas = new Tarefa[quantidade];

    for(int count = 0; count < quantidade; count++){
      cout << "["<< count << "] Digite o tempo de super computador necessário:";
      cin.ignore();
      cin >> tarefas[count].tempoSupercomputador;

      cout << "["<< count << "] Digite o tempo de computador necessário:";
      cin >> tarefas[count].tempoComputador;
    }

    mergeSort(tarefas, 0, quantidade - 1);
    displayHalf(tarefas, 0,quantidade - 1);

    delete(tarefas);
    return 0;
}



void displayVector(int * vectorNumbers, int actualLenght){
  for(int count = 0; count < actualLenght; count++){
    cout << vectorNumbers[count] << " ";
  }

  cout << endl;
}

void merge(Tarefa *tarefas, int init, int half, int end){
  bool end1=false, end2=false;
  Tarefa *tarefasAux;
  int length;
  int count1 = init, count2 = half+1;

  length = end-init+1;
  tarefasAux = (Tarefa *) malloc(length*sizeof(Tarefa));
  int countAux = 0;

  while(!end1 && !end2){
    if(tarefas[count1].tempoComputador > tarefas[count2].tempoComputador){
      tarefasAux[countAux]=tarefas[count1];
      count1++;
      if(count1 > half){
        end1 = true;
      }
    }else{
      tarefasAux[countAux]=tarefas[count2];
      count2++;
      if(count2 > end){
        end2 = true;
      }
    }
    countAux++;
  }

  if(!end1){
    for (;countAux < length; countAux++){
      tarefasAux[countAux]=tarefas[count1];
      count1 ++;
    }
  }

  if(!end2){
    for (;countAux < length; countAux++){
      tarefasAux[countAux]=tarefas[count2];
      count2 ++;
    }
  }

  int secondPosition = init;

  for(int i=0; i<length; i++){
    tarefas[secondPosition]=tarefasAux[i];
    secondPosition++;
  }

}

void mergeSort(Tarefa *tarefas, int init, int end){
  if (init < end){
    int half = (int) floor((init+end)/2);
    mergeSort(tarefas,init,half);
    mergeSort(tarefas,half+1,end);
    merge(tarefas,init,half,end);
  }
}

void displayHalf(Tarefa *tarefas, int init, int end){
  int tempoCorrenteSuper = 0;
  int tempoParcial = 0;
  int tempoTotal = 0;

  for(int count = init; count <= end; count++){
    cout << "["<< count << "] "<< tarefas[count].tempoComputador << " " << tarefas[count].tempoSupercomputador;
    if(count!=end){
      cout << ", ";
    }
    tempoCorrenteSuper += tarefas[count].tempoSupercomputador;

    if(count == init){
      tempoTotal = tempoCorrenteSuper +  tarefas[count].tempoComputador;
    }

    if ((tempoCorrenteSuper + tarefas[count].tempoComputador) > tempoTotal) {
        tempoTotal = tempoCorrenteSuper + tarefas[count].tempoComputador;
    }
  }
  cout << endl;
  cout << "Tempo total:" << tempoTotal << endl;
}

void header() {
  cout << ("Universidade de Brasilia - Campus Gama\n");
  cout <<("Disciplina: Estrutura de Dados e Algoritmos 2\n");
  cout <<("Professor: Mauricio Serrano\n");
  cout <<("Aluno: Gustavo Vieira Braz Gonçalves\n");
  cout <<("Aluno: Ronyell Henrique dos Santos\n");
  cout <<("Tema: Algoritmos ambiciosos, Scheduling \n\n");
}
