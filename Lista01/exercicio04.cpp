#include <iostream>
#include <cstdlib>

#define TAMANHO_MAX 100

using namespace std;

typedef struct{
    int index;
    int apontador;
}kIndex;


void inicializaVetor(int * vetorNumeros);

int recebeNumero();

int insere(int tamanhoAtual, int* vetorNumeros);

void ordena(int tamanhoAtual, int* vetorNumeros);

void mostrarNumero(int posicao, int numeroBusca);

kIndex* allocaKindex(int tamanhoAtual);

kIndex* gerarIndices(int tamanhoAtual, int* vetorNumeros, int distanciaIndices);

int buscaNumero(int tamanhoAtual, int* vetorNumeros, int distanciaIndices, kIndex * indices, int numeroBusca);

int deleta(int tamanhoAtual, int* vetorNumeros, int distanciaIndices, kIndex * indices);

int menu(int tamanhoAtual, int * vetorNumeros,  int distanciaIndices, kIndex * indices, int opcao);

void mostarMenu();

void listarIndices(int tamanhoAtual ,int distanciaIndices, kIndex * indices);

void listarNumeros(int tamanhoAtual, int * vetorNumeros);

int main()
{
    int vetorNumeros[TAMANHO_MAX];
    int tamanhoAtual = TAMANHO_MAX;
    int distanciaIndices = 7;

    inicializaVetor(vetorNumeros);
    ordena(tamanhoAtual, vetorNumeros);
    kIndex* indices = gerarIndices(tamanhoAtual, vetorNumeros, distanciaIndices);

    int opcao = 1;

    while(opcao){

      mostarMenu();
      opcao = recebeNumero();
      tamanhoAtual = menu(tamanhoAtual, vetorNumeros, distanciaIndices, indices, opcao);

    }

    free(indices);
    return 0;
}


void inicializaVetor(int * vetorNumeros){
  for(int contador = 0; contador < TAMANHO_MAX; contador ++ ){
    vetorNumeros[contador] = rand() % 1000;
  }
}

int recebeNumero(){
  int numero;

  cin >> numero;

  return numero;
}

//Função de inserção
int insere(int tamanhoAtual, int* vetorNumeros){
  if( tamanhoAtual < TAMANHO_MAX){
    vetorNumeros[tamanhoAtual] = recebeNumero();
    tamanhoAtual++;

    cout << "Numero inserido com sucesso" << endl;

  }else{
    cout << "Vetor cheio" << endl;
  }
  return tamanhoAtual;
}

//Fun��o de ordenar o vetor atrav�s do Bubble Sort
void ordena(int tamanhoAtual, int* vetorNumeros){
    bool troca = true;
    while(troca){
        troca = false;
        for(int i = 0; i < tamanhoAtual-1; i++){
            int atual = vetorNumeros[i];
            if (atual > vetorNumeros[i+1]){
                vetorNumeros[i] = vetorNumeros[i+1];
                vetorNumeros[i+1] = atual;
                troca = true;
            }
        }
    }
}

//Função de alocação
kIndex* allocaKindex(int tamanhoAtual){
    kIndex* indices = (kIndex*)malloc(tamanhoAtual*sizeof(kIndex));
    return indices;
}

kIndex* gerarIndices(int tamanhoAtual, int* vetorNumeros, int distanciaIndices){
    int contador = 0, tamanhoAtualIndice = 0;
    tamanhoAtualIndice = tamanhoAtual / distanciaIndices;
    kIndex* indices = allocaKindex(tamanhoAtualIndice);
    for(int i = 0; i < tamanhoAtual; i+=distanciaIndices){
        indices[contador].index = vetorNumeros[i];
        indices[contador].apontador = i;
        contador++;

    }
    return indices;
}

int buscaNumero(int tamanhoAtual, int* vetorNumeros, int distanciaIndices, kIndex * indices, int numeroBusca){
  int tamanhoAtualIndice = tamanhoAtual / distanciaIndices;
  int indice = -1,indiceFinal = -1;

  //Laco que percorre o vetor de indices
  for(int contador = 0; contador<tamanhoAtualIndice - 1; contador++){
    if(indices[contador].index <= numeroBusca && indices[contador + 1].index >= numeroBusca ){
        indice = contador * distanciaIndices;
      break;
    }
  }

  if (indice == -1){
    indice = (tamanhoAtualIndice - 1) * distanciaIndices;
  }

  //Laco que percorre o vetor principal entre dois valores

  for(int contador = indice; contador <= indice + distanciaIndices && contador < tamanhoAtual; contador++){
    if(vetorNumeros[contador] == numeroBusca){
      indiceFinal = contador;
    }
  }
  return indiceFinal;
}

//Função de deleção
int deleta(int tamanhoAtual, int* vetorNumeros, int distanciaIndices, kIndex * indices){
  int indice = 0;
  int numeroBusca = recebeNumero();

  indice = buscaNumero(tamanhoAtual, vetorNumeros, distanciaIndices, indices, numeroBusca);

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

int menu(int tamanhoAtual, int * vetorNumeros, int distanciaIndices, kIndex * indices, int opcao){
  int numeroBusca = 0, posicao = 0;

  switch(opcao){
    case 1:
      tamanhoAtual = insere(tamanhoAtual, vetorNumeros);
      ordena(tamanhoAtual, vetorNumeros);
      free(indices);
      indices = gerarIndices(tamanhoAtual, vetorNumeros, distanciaIndices);
      break;
    case 2:
      tamanhoAtual = deleta(tamanhoAtual, vetorNumeros, distanciaIndices, indices);
      ordena(tamanhoAtual, vetorNumeros);
      free(indices);
      indices = gerarIndices(tamanhoAtual, vetorNumeros, distanciaIndices);
      break;
    case 3:
      cout << "Entre com o numero que deseja procurar:" << endl;
      numeroBusca = recebeNumero();
      posicao = buscaNumero(tamanhoAtual, vetorNumeros, distanciaIndices, indices, numeroBusca);
      mostrarNumero(posicao, numeroBusca);
      break;
    case 4:
      listarNumeros(tamanhoAtual, vetorNumeros);
      break;
    case 5:
      listarIndices(tamanhoAtual,distanciaIndices, indices);
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

void listarNumeros(int tamanhoAtual, int * vetorNumeros){
  for(int contador = 0; contador < tamanhoAtual; contador++){
    cout << contador << " | " << vetorNumeros[contador] << endl;
  }
}

void listarIndices(int tamanhoAtual ,int distanciaIndices, kIndex * indices){
  int contador = 0;
  for(int i = 0; i < tamanhoAtual; i+=distanciaIndices){
      cout <<"Indices:"<< indices[contador].index << ", " << indices[contador].apontador<<endl;
      contador++;
  }
}

void mostrarNumero(int posicao, int numeroBusca){
  if(posicao != -1){
    cout << posicao << " | " << numeroBusca << endl;
  }else{
    cout << "Número não encontrado" << endl;
  }
}

void mostarMenu(){
  cout << "======================== MENU ========================"<<endl;
  cout << "1 - Inserir numero\n2 - Excluir numero\n3 - Buscar numero\n4 - Listar numeros\n5 - Listar indices\n0 - Sair" << endl;
}
