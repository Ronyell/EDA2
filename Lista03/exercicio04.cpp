#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>


#define TAMANHO_MAX 10000

using namespace std;

int recebeNumero();

void inicializaVetor(int * vetorNumeros, int tamanhoAtual);

void countingSort(int * vetorNumeros, int inicio, int fim, int divisor);

int acharDivisor(int * vetorNumeros, int tamanhoAtual);

int * radixSort(int * vetorNumeros, int tamanhoAtual);

int * allocaVetor(int tamanhoAtual);

void bucketSort(int * vetorNumeros, int tamanhoAtual, int inicio, int fim);

void printVetor(int * vetorNumeros, int tamanhoAtual);

int pegaValor(int num, int divisor);

void displayHalf(int * vectorNumbers, int init, int end);



void header();

int main(){
  int tamanhoAtual = 0;

  header();

  cout << "Entre com o tamanho do Vetor:"<< endl;
  tamanhoAtual = recebeNumero();
  int * vetorNumeros = allocaVetor(tamanhoAtual);

  while( tamanhoAtual > 0){

    inicializaVetor(vetorNumeros, tamanhoAtual);
    vetorNumeros = radixSort(vetorNumeros, tamanhoAtual);

    cout << "Deseja observar o vetor ordenado? \n1-Sim \n2-Nao"<<endl;
    int print = recebeNumero();

    if(print == 1){
      printVetor(vetorNumeros, tamanhoAtual);
    }

    cout << "Entre com o tamanho do Vetor:"<< endl;
    tamanhoAtual = recebeNumero();

  }

  free(vetorNumeros);
  return 0;
}

int recebeNumero(){
  int numero;

  cin >> numero;

  return numero;
}

void inicializaVetor(int * vetorNumeros, int tamanhoAtual){
  srand(time(NULL));
  for(int contador = 0; contador < tamanhoAtual; contador ++ ){
    vetorNumeros[contador] = rand() % TAMANHO_MAX;
  }
}

int * allocaVetor(int tamanhoAtual){
  int * vetorNumeros =  new int [tamanhoAtual];

  return vetorNumeros;
}

void countingSort(int * vetorNumeros, int inicio, int fim, int divisor){
  int menor = inicio, maior = inicio;
  int tamanhoAtual = fim - inicio + 1;

    //Acha o range.
  for(int contador = inicio; contador <= fim; contador++ ){
    if((pegaValor(vetorNumeros[menor],divisor)) > (pegaValor(vetorNumeros[contador],divisor))){
      menor = contador;
    }

    if((pegaValor(vetorNumeros[maior],divisor)) < (pegaValor(vetorNumeros[contador],divisor))){
      maior = contador;
    }
  }

  cout << " Maior : " << vetorNumeros[maior]<< " Menor : "<< vetorNumeros[menor]<< endl;

  int range  =  1 + pegaValor(vetorNumeros[maior], divisor) - pegaValor(vetorNumeros[menor], divisor);
  //Cria vetor com o tamanho do range e inicializa com 0
  cout << "Range : " << range<< endl;
  int * vetorAuxiliar = new int[range];
  cout << "/////Range :\\\\\\" << range<< endl;
  int * vetorAuxiliarRecurcao = new int[range];
  for(int contador = 0; contador < range; contador ++){
    vetorAuxiliar[contador] = 0;
  }


  //Conta a quantidade de cada número no espaço do range
  for(int contador = inicio; contador <= fim; contador++){
    int posicao = pegaValor(vetorNumeros[contador], divisor) - pegaValor(vetorNumeros[menor], divisor);
    vetorAuxiliar[posicao] ++;
  }

  //Acha a ultima posição de cada número
  vetorAuxiliarRecurcao[0] = vetorAuxiliar[0];

  for(int contador = 0; contador < range; contador++){
    vetorAuxiliar[contador] += vetorAuxiliar[contador - 1];
    vetorAuxiliarRecurcao[contador] = vetorAuxiliar[contador];
    cout << "Posicao: " << contador << " Quantidade: " << vetorAuxiliar[contador] << endl;
  }

  //Ordena em um novo vetor
  int * vetorFinal = allocaVetor(tamanhoAtual);

  for(int contador = fim ; contador >= inicio; contador--){
    int posicao = pegaValor(vetorNumeros[contador],divisor) - pegaValor(vetorNumeros[menor],divisor);
    int posicaoFinal = vetorAuxiliar[posicao] - 1;
    if(posicaoFinal == -1)
      continue;
    vetorFinal[posicaoFinal] = vetorNumeros[contador];
    vetorAuxiliar[posicao]--;
    cout << posicaoFinal << " "<< vetorFinal[posicaoFinal] << " " << endl;
  }

  int contadorAux = 0;
  for(int contador = inicio; contador <= fim; contador++){
    vetorNumeros[contador] = vetorFinal[contadorAux];
    contadorAux++;
  }

  divisor = divisor / 10;
  for(int contador = 0; contador < range && divisor > 0 ; contador++){
      int esquerda = 0;
      int direita = 0;

      if(contador){
        esquerda = vetorAuxiliarRecurcao[contador- 1];
      }
      if (vetorAuxiliarRecurcao[contador] != esquerda ){
        direita = vetorAuxiliarRecurcao[contador] - 1;
      }else{
        direita = vetorAuxiliarRecurcao[contador];
      }

      if ((direita - esquerda)){
        displayHalf(vetorNumeros, esquerda, direita);
        cout << "===========" << esquerda << " ======== "<< direita << endl;
        countingSort(vetorNumeros, esquerda, direita, divisor);
      }

  }

}


int * radixSort(int * vetorNumeros, int tamanhoAtual){
  int divisor = acharDivisor(vetorNumeros, tamanhoAtual);
  printVetor(vetorNumeros, tamanhoAtual);
  cout <<"///"<<endl;
  countingSort(vetorNumeros, 0, tamanhoAtual - 1, divisor);

  return vetorNumeros;
}


void printVetor(int * vetorNumeros, int tamanhoAtual){
  cout <<"-----"<< endl;

  for(int contador = 0; contador<tamanhoAtual; contador++){
    cout << vetorNumeros[contador]<< endl;
  }
  cout <<"-----"<< endl;
}

void header() {
  cout << ("Universidade de Brasilia - Campus Gama\n");
  cout <<("Disciplina: Estrutura de Dados e Algoritmos 2\n");
  cout <<("Professor: Mauricio Serrano\n");
  cout <<("Aluno: Gustavo Vieira Braz Gonçalves\n");
  cout <<("Aluno: Ronyell Henrique dos Santos\n");
  cout <<("Tema: Ordenação RadixSort e CountingSort\n\n");
}

void bucketSort(int * vetorNumeros, int tamanhoAtual, int inicio, int fim){

}

int pegaValor(int num, int divisor){
    int valor = 1;

    if(divisor != 0 )
      valor = ((int)(num / divisor))% 10;

    return valor;
}

void displayHalf(int * vectorNumbers, int init, int end){
  for(int count = init; count <= end; count++){
    cout << vectorNumbers[count] << " ";
  }

  cout << endl;
}

int acharDivisor(int * vetorNumeros, int tamanhoAtual){
  int maior = vetorNumeros[0];
  for(int contador = 1; contador < tamanhoAtual; contador++){
    if (maior < vetorNumeros[contador]){
      maior = vetorNumeros[contador];
    }
  }
  int divisor = 1;

  while((maior/=10)){
    divisor *= 10;
  }
  return divisor;
}
