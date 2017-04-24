#include <iostream>
#include <cstdlib>
#include <time.h>


#define TAMANHO_MAX 1000

using namespace std;

long int recebeNumero();

void inicializaVetor(long int * vetorNumeros, long int tamanhoAtual);

long int * countingSort(long int * vetorNumeros, long int tamanhoAtual, long int divisor);

long int * radixSort(long int * vetorNumeros, long int tamanhoAtual);

long int * allocaVetor(long int tamanhoAtual);

void printVetor(long int * vetorNumeros, long int tamanhoAtual);

void header();

int main(){
  long int tamanhoAtual = 0;

  header();

  cout << "Entre com o tamanho do Vetor:"<< endl;
  tamanhoAtual = recebeNumero();

  while( tamanhoAtual > 0){

    long int * vetorNumeros;

    vetorNumeros = allocaVetor(tamanhoAtual);

    inicializaVetor(vetorNumeros, tamanhoAtual);
    vetorNumeros = radixSort(vetorNumeros, tamanhoAtual);

    cout << "Deseja observar o vetor ordenado? \n1-Sim \n2-Nao"<<endl;
    int print = recebeNumero();

    if(print == 1){
      printVetor(vetorNumeros, tamanhoAtual);
    }

    free(vetorNumeros);

    cout << "Entre com o tamanho do Vetor:"<< endl;
    tamanhoAtual = recebeNumero();

  }
  return 0;
}

long int recebeNumero(){
  long int numero;

  cin >> numero;

  return numero;
}

void inicializaVetor(long int * vetorNumeros, long int tamanhoAtual){
  for(long int contador = 0; contador < tamanhoAtual; contador ++ ){
    vetorNumeros[contador] = rand() % 100000000;
  }
}

long int * allocaVetor(long int tamanhoAtual){
  long int * vetorNumeros = (long int *) malloc(tamanhoAtual * sizeof(long int));

  return vetorNumeros;
}

long int * countingSort(long int * vetorNumeros, long int tamanhoAtual, long int divisor){
  long int menor = 0, maior = 0;

    //Acha o range.
  for(long int contador = 1; contador < tamanhoAtual; contador++ ){
    if((long int)(vetorNumeros[menor] % divisor)/(divisor/10) > (long int)(vetorNumeros[contador]% divisor)/(divisor/10)){
      menor = contador;
    }

    if((long int)(vetorNumeros[maior] % divisor)/(long int)(divisor/10) < (long int)(vetorNumeros[contador]% divisor)/(divisor/10)){
      maior = contador;
    }
  }

  long int range  =  1 + (long int)(vetorNumeros[maior] % divisor)/(divisor/10) - (long int)(vetorNumeros[menor]% divisor)/(divisor/10);

  //Cria vetor com o tamanho do range e inicializa com 0
  long int * vetorAuxiliar = (long int *) malloc (range * sizeof(long int));

  for(long int contador = 0; contador < range; contador ++){
    vetorAuxiliar[contador] = 0;
  }


  //Conta a quantidade de cada número no espaço do range
  for(long int contador = 0; contador < tamanhoAtual; contador++){
    long int posicao = (long int)(vetorNumeros[contador] % divisor)/(divisor/10) - (long int)(vetorNumeros[menor] % divisor)/(divisor/10);
    vetorAuxiliar[posicao] ++;
  }

  //Acha a ultima posição de cada número
  for(long int contador = 1; contador < range; contador++){
    vetorAuxiliar[contador] += vetorAuxiliar[contador - 1];
  }

  //Ordena em um novo vetor
  long int * vetorFinal = (long int *) malloc (tamanhoAtual * sizeof(long int));

  for(long int contador = tamanhoAtual - 1; contador >= 0; contador--){
    long int posicao = (long int)(vetorNumeros[contador]% divisor)/(divisor/10) - (long int)(vetorNumeros[menor] % divisor)/(divisor/10);
    long int posicaoFinal = vetorAuxiliar[posicao] - 1;

    vetorFinal[posicaoFinal] = vetorNumeros[contador];
    vetorAuxiliar[posicao]--;
  }

  return vetorFinal;
}

long int * radixSort(long int * vetorNumeros, long int tamanhoAtual){
  long int divisor = 10;

  clock_t tInicio, tFim, tDecorrido;
  tInicio = clock();

  for(long int contador = 7; contador > -1; contador--){
    vetorNumeros = countingSort(vetorNumeros, tamanhoAtual, divisor);
    divisor *= 10;
    printVetor(vetorNumeros, tamanhoAtual);
  }

  tFim = clock();
  tDecorrido = tFim - tInicio;

  cout << "Tempo decorrido:" << double(tDecorrido)/CLOCKS_PER_SEC << endl;

  return vetorNumeros;
}


void printVetor(long int * vetorNumeros, long int tamanhoAtual){
  for(long int contador = 0; contador<tamanhoAtual; contador++){
    cout << vetorNumeros[contador]<< endl;
  }
  cout << endl;
}

void header() {
  cout << ("Universidade de Brasilia - Campus Gama\n");
  cout <<("Disciplina: Estrutura de Dados e Algoritmos 2\n");
  cout <<("Professor: Mauricio Serrano\n");
  cout <<("Aluno: Gustavo Vieira Braz Gonçalves\n");
  cout <<("Aluno: Ronyell Henrique dos Santos\n");
  cout <<("Tema: Ordenação RadixSort e CountingSort\n\n");
}
