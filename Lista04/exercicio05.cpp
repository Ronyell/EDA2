#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

#define MILHA 4.0

void header();

double valorAbsoluto(double x);

double calculaDistancia(double ocidente, double oriente);

int calculaQuantidadeEstacoes(double * localizacoes, int quantidadeCasas, double distanciaTotal);

void displayHalf(double * vectorNumbers, int init, int end);

void merge(double *vectorNumbers, int init, int half, int end);

void mergeSort(double *vectorNumbers, int init, int end);

int main(){
    double ocidente, oriente;
		int quantidadeCasas;

    header();

    cout << "Digite a extremidade ocidental: ";
    cin >> ocidente;

    cout << "Digite a extremidade oriental:";
    cin >> oriente;

    if(oriente < ocidente){
      double aux = oriente;
      oriente = ocidente;
      ocidente = aux;
    }

    cout << "Digite a quantidade de casas:";
    cin >> quantidadeCasas;

		double * localizacoes = new double[quantidadeCasas];

		for(int count = 0; count < quantidadeCasas; count++){
      do{
          cout << "Digite a casa na posição["  << count << "]:";
          cin >> localizacoes[count];
      }while(localizacoes[count] < ocidente || localizacoes[count] > oriente);
		}

		mergeSort(localizacoes, 0, quantidadeCasas - 1);

    double distancia = calculaDistancia(ocidente, oriente);
    int quantidadeBases = calculaQuantidadeEstacoes(localizacoes, quantidadeCasas, distancia);

    cout << "Quantidade de Bases: " << quantidadeBases << endl;

		delete(localizacoes);
    return 0;
}

double calculaDistancia(double ocidente, double oriente){
    return valorAbsoluto(oriente - ocidente);
}

double valorAbsoluto(double x){
    if(x >= 0){
        return x;
    }else{
        return -x;
    }
 }

 int calculaQuantidadeEstacoes(double * localizacoes, int quantidadeCasas, double distanciaTotal){
   double distanciaAtual = 0.0;
   bool adicionaBase = false;
   int quantidadeBases = 0;

   for(int contador = 0; contador < quantidadeCasas; contador++){
     if(!contador){
       distanciaAtual = localizacoes[contador] + MILHA;
       quantidadeBases++;

       if(distanciaAtual > distanciaTotal){
         distanciaAtual = distanciaTotal;
       }

       cout << "Base [" << quantidadeBases << "] adicionada na milha: "<<  distanciaAtual << endl;
     }else if((distanciaAtual) < localizacoes[contador]){
       distanciaAtual = localizacoes[contador] + MILHA;
       quantidadeBases++;

       if(distanciaAtual > distanciaTotal){
         distanciaAtual = distanciaTotal;
       }

       cout << "Base [" << quantidadeBases << "] adicionada na milha: "<<  distanciaAtual << endl;
     }

   }
   return quantidadeBases;
 }


 void merge(double *vectorNumbers, int init, int half, int end){
   bool end1=false, end2=false;
	 int length;
   double *vectorNumbersAux;
   int count1 = init, count2 = half+1;

   length = end-init+1;
   vectorNumbersAux = (double *) malloc(length*sizeof(double));
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

 }

 void mergeSort(double *vectorNumbers, int init, int end){
   if (init < end){
     int half = (int) floor((init+end)/2);
     mergeSort(vectorNumbers,init,half);
     mergeSort(vectorNumbers,half+1,end);
     merge(vectorNumbers,init,half,end);
   }
 }

 void displayHalf(double * vectorNumbers, int init, int end){
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
   cout <<("Tema: Quantidade de bases\n\n");
 }
