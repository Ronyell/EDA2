#include <iostream>
#include <cstdlib>
#include <math.h>

#define TAMANHO_MAX 24

using namespace std;

int recebeNumero();

int buscaInicio(int tamanhoAtual, int * vetorNumeros); //Funcao que retorna o inicio do vetor, presupoe que o vetor já esteja ordenado

int buscaNumero(int inicio, int tamanhoAtual, int * vetorNumeros, int numeroBusca);

int deleta(int inicio, int tamanhoAtual, int* vetorNumeros);

void listarNumeros(int inicio, int tamanhoAtual, int * vetorNumeros);

void mostrarNumero(int posicao, int numeroBusca);


int menu(int inicio, int tamanhoAtual, int * vetorNumeros, int opcao);


void mostarMenu();

int main(){
  int  vetorNumeros [TAMANHO_MAX] = {20,30,40,50,60,70,77,80,81,90,91,99,100,0,1,4,6,7,9,11,15,16,18,19};
  int tamanhoAtual = TAMANHO_MAX;
  int inicio = buscaInicio(tamanhoAtual, vetorNumeros);

  int opcao = 1;

  while(opcao){

    mostarMenu();
    opcao = recebeNumero();
    tamanhoAtual = menu(inicio, tamanhoAtual, vetorNumeros, opcao);
    inicio = buscaInicio(tamanhoAtual, vetorNumeros);

  }
  return 0;
}

int recebeNumero(){
  int numero;

  cin >> numero;

  return numero;
}

int buscaInicio(int tamanhoAtual, int * vetorNumeros){
  int inicio = 0;

  for(int contador = 1; contador < tamanhoAtual; contador++){
    if(vetorNumeros[inicio] > vetorNumeros[contador]){
      inicio = contador;
    }
  }
  return inicio;
}

int buscaNumero(int inicio, int tamanhoAtual, int * vetorNumeros, int numeroBusca){
  int limiteInferior = inicio;
  int limiteSuperior = 0;
  int meio = 0;

  if(limiteInferior != 0){
    limiteSuperior = inicio - 1;
  }else{
    limiteSuperior = tamanhoAtual - 1;
  }

  while(vetorNumeros[limiteInferior] <= vetorNumeros[limiteSuperior]){
    int soma  = limiteInferior + limiteSuperior;

    if(limiteInferior > limiteSuperior){
      meio = (soma - tamanhoAtual)/2;
    }else{
      meio = (soma) / 2;
    }

    if(vetorNumeros[meio] == numeroBusca){
        return meio;
    }else if (numeroBusca < vetorNumeros[meio]){
          if(meio){
            limiteSuperior = (meio - 1);
          }else{
            limiteSuperior = tamanhoAtual - 1;
          }
    }else{
          if(meio == tamanhoAtual - 1){
            limiteInferior =  0;
          }else{
            limiteInferior =  (meio + 1);
          }
    }
  }

  return -1;
}


int deleta(int inicio, int tamanhoAtual, int* vetorNumeros){
  int indice = 0;
  int numeroBusca = recebeNumero();

  indice = buscaNumero(inicio, tamanhoAtual, vetorNumeros, numeroBusca);

  if(indice != -1){
    cout << "Numero excluido com sucesso" << endl;

    for(int contador = indice ; contador < tamanhoAtual - 2; contador++){
      vetorNumeros[contador] = vetorNumeros[contador + 1];
    }

    tamanhoAtual--;

  }else{
    cout << "Numero nao encontrado" << endl;
  }

  return tamanhoAtual;
}


int insere(int inicio,int tamanhoAtual, int* vetorNumeros){
  if( tamanhoAtual < TAMANHO_MAX){
    vetorNumeros[tamanhoAtual] = recebeNumero();
    tamanhoAtual++;

    for(int contador = inicio; contador < tamanhoAtual; contador ++){
      cout << contador << " | " << vetorNumeros[contador] << endl;
    }

    if (inicio > 0){
      for(int contador = 0; contador < inicio; contador ++){
        cout << contador << " | " << vetorNumeros[contador] << endl;
      }
    }

    cout << "Numero inserido com sucesso" << endl;

  }else{
    cout << "Vetor cheio" << endl;
  }
  return tamanhoAtual;
}

void listarNumeros(int inicio, int tamanhoAtual, int * vetorNumeros){
  for(int contador = inicio; contador < tamanhoAtual; contador ++){
    cout << contador << " | " << vetorNumeros[contador] << endl;
  }

  if (inicio > 0){
    for(int contador = 0; contador < inicio; contador ++){
      cout << contador << " | " << vetorNumeros[contador] << endl;
    }
  }
}


void mostrarNumero(int posicao, int numeroBusca){
  if(posicao != -1){
    cout << posicao << " | " << numeroBusca << endl;
  }else{
    cout << "Número não encontrado" << endl;
  }
}

int menu(int inicio, int tamanhoAtual, int * vetorNumeros, int opcao){
  int numeroBusca = 0, posicao = 0;

  switch(opcao){
    case 1:
      //tamanhoAtual = insere(inicio ,tamanhoAtual, vetorNumeros);
      break;
    case 2:
      tamanhoAtual = deleta(inicio ,tamanhoAtual, vetorNumeros);
      break;
    case 3:
      cout << "Entre com o numero que deseja procurar:" << endl;
      numeroBusca = recebeNumero();
      posicao = buscaNumero(inicio, tamanhoAtual, vetorNumeros, numeroBusca);
      mostrarNumero(posicao, numeroBusca);
      break;
    case 4:
      listarNumeros(inicio ,tamanhoAtual, vetorNumeros);
      break;
    case 0:
      cout << "Sair" << endl;
    break;
    default:
      cout << "Opcao Invalida!" << endl;
      break;
  }

  return tamanhoAtual;
}

void mostarMenu(){
  cout << "======================== MENU ========================"<<endl;
  cout << "1 - Inserir numero\n2 - Excluir numero\n3 - Buscar numero\n4 - Listar numeros\n0 - Sair" << endl;
}
