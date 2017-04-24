#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <math.h>

#define LER "r"
#define ESCREVER "w"

using namespace std;

long int recebeNumero();

void insere(long int tamanhoMax, long int tamanhoAtual,long int* vetorNumeros);

void ordena(long int tamanhoAtual, long int* vetorNumeros);

int buscaNumero(long int tamanhoAtual, long int * vetorNumeros, long int numeroBusca);

void mostrarNumero(int posicao, int numeroBusca);

void lerArquivo(FILE * arquivo, long int * vetorNumeros);

long int * allocaVetor(long int tamanhoTotal);

FILE * menu( long int * tamanhoAtual);

int main(){

  long int * vetorNumeros;
  long int tamanhoMax = 0;
  long int tamanhoAtual = 0;
  long int numeroBusca = 0;
  long int posicao = 0, numero = 0;
  FILE * arquivo = NULL;

  arquivo = menu( &tamanhoMax);
  vetorNumeros = allocaVetor(tamanhoMax);
  tamanhoAtual = tamanhoMax;
  lerArquivo(arquivo, vetorNumeros);

  cout << "Entre com o número de busca:" << endl;
  numeroBusca = recebeNumero();
  posicao = buscaNumero(tamanhoAtual, vetorNumeros, numeroBusca);
  mostrarNumero(posicao, numeroBusca);



  free(vetorNumeros);
  fclose(arquivo);
  return 0;
}

long int * allocaVetor(long int tamanhoTotal){
  long int * vetorNumeros;

  vetorNumeros = (long int *) malloc(tamanhoTotal * sizeof(long int));

  return vetorNumeros;
}

long int recebeNumero(){
  long int numero;

  cin >> numero;

  return numero;
}

int buscaNumero(long int tamanhoAtual, long int * vetorNumeros, long int numeroBusca){
  long int limiteInferior = 0;
  long int limiteSuperior = tamanhoAtual - 1;
  long int metade = 0;

  clock_t tInicio, tFim, tDecorrido;

  tInicio = clock();
  long int contador = 0;

  while(limiteInferior < limiteSuperior && vetorNumeros[limiteSuperior] > numeroBusca){

    double auxiliar =  (double)(numeroBusca - vetorNumeros[limiteInferior]) / (double)(vetorNumeros[limiteSuperior] - vetorNumeros[limiteInferior]);
    double auxiliar2 = (double)limiteInferior + ((limiteSuperior - limiteInferior) * auxiliar);

    metade = (long int) ceil(auxiliar2);

    cout << metade << " - "<<auxiliar2<< " - " << limiteInferior << " - "<< limiteSuperior << endl;
    contador ++;

      if(numeroBusca == vetorNumeros[metade]){
          tFim = clock();

          tDecorrido = tFim - tInicio;

          cout << "Tempo decorrido:" << double(tDecorrido)/CLOCKS_PER_SEC  << " - " << contador << endl;

          return metade;
      }else if (numeroBusca > vetorNumeros[metade]){
        limiteInferior = (metade + 1);
      }else if (numeroBusca < vetorNumeros[metade]){
        limiteSuperior =  (metade - 1);
      }

    }

  tFim = clock();

  tDecorrido = tFim - tInicio;

  cout << "Tempo decorrido:" << double(tDecorrido)/CLOCKS_PER_SEC  << " - " << contador << endl;

  return -1;
}

void mostrarNumero(int posicao, int numeroBusca){
  if(posicao != -1){
    cout << posicao << " | " << numeroBusca << endl;
  }else{
    cout << "Número não encontrado" << endl;
  }
}

void lerArquivo(FILE * arquivo, long int * vetorNumeros){
  long int contador = 0, numero;
  while((fscanf(arquivo,"%ld\n", &numero)) != EOF){
    vetorNumeros[contador] = numero;
    contador++;
  }
}

FILE * menu( long int * tamanhoAtual){
  cout << "Menu" << endl;
  cout << "0 - 10 \n1 - 25 \n2 - 50 \n3 - 100 \n4 - 500 \n5 - 1000 \n6 - 10000 \n7 - 100000 \n8 - 1000000 \n9 - 10000000 \n10 - 100000000" << endl;
  cout << "Entre com um número de 0 a 8:" << endl;

  int numero = recebeNumero();

  while(numero < 0 || numero > 10){
    numero = recebeNumero();
  }

  FILE * arquivo = NULL;

  switch(numero){
    case 0:
        arquivo = fopen("exemploDez.txt", LER);
        *tamanhoAtual = 10;
      break;
    case 1:
      arquivo = fopen("exemploVinteECinco.txt", LER);
        *tamanhoAtual = 25;
      break;
    case 2:
      arquivo = fopen("exemploCinquenta.txt", LER);
      *tamanhoAtual = 50;
      break;
    case 3:
      arquivo = fopen("exemploCem.txt", LER);
      *tamanhoAtual = 100;
      break;
    case 4:
      arquivo = fopen("exemploQuinhentos.txt", LER);
      *tamanhoAtual = 500;
      break;
    case 5:
      arquivo = fopen("exemploMil.txt", LER);
      *tamanhoAtual = 1000;
      break;
    case 6:
      arquivo = fopen("exemploDezMil.txt", LER);
      *tamanhoAtual = 10000;
      break;
    case 7:
      arquivo = fopen("exemploCemMil.txt", LER);
      *tamanhoAtual = 100000;
      break;
    case 8:
      arquivo = fopen("exemploMilhao.txt", LER);
      *tamanhoAtual = 1000000;
      break;
    case 9:
        arquivo = fopen("exemploDezMilhoes.txt", LER);
        *tamanhoAtual = 10000000;
        break;
    case 10:
        arquivo = fopen("exemploCemMilhoes.txt", LER);
        *tamanhoAtual = 100000000;
        break;
    default:
      break;
  }
  return arquivo;
}
