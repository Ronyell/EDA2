#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node{
	string evento;
	struct node *prox;
}Node;

void header();

void inicializaFila(Node * fila, int *quantidadeAtual);

int filaVazia(Node * fila);

void insereNo(Node * fila, int *quantidadeAtual, string evento);

Node *retiraNo(Node * fila, int *quantidadeAtual);

Node *alocaNo();

Node *desalocaFila(Node * fila);

void exibirFila(Node * fila);

void eSubsequente(Node * subsequencia, Node * sequencia, int * quantidadeSubsequencia, int * quantidaSequencia);

int main(){
    int quantidaSequencia = 0;
    int quantidadeSubsequencia = 0;
    int quantidade = 0;
    string evento;
    Node * subsequencia = (Node *) malloc(sizeof(Node));
    Node * sequencia = (Node *) malloc(sizeof(Node));

	inicializaFila(subsequencia, &quantidadeSubsequencia);
    inicializaFila(sequencia, &quantidaSequencia);

    header();

    do{
        cout << "Digite a quantidade de números da Subsequencia: ";
        cin >> quantidade;
    }while(quantidade < 1);

    do{
        cout << "Digite um evento da Subsequencia:" << endl;
        cin >> evento;
        insereNo(subsequencia, &quantidadeSubsequencia, evento);
    }while(quantidade > quantidadeSubsequencia);

    do{
        cout << "Digite a quantidade de números da Sequencia: ";
        cin >> quantidade;
    }while(quantidade < 1);

    do{
        cout << "Digite um evento da Sequencia:" << endl;
        cin >> evento;
        insereNo(sequencia, &quantidaSequencia, evento);
    }while(quantidade > quantidaSequencia);

    eSubsequente(subsequencia, sequencia, &quantidadeSubsequencia, &quantidaSequencia);

    sequencia = desalocaFila(sequencia);
    subsequencia = desalocaFila(subsequencia);

    return 0;
}


void inicializaFila(Node * fila, int *quantidadeAtual){
    fila->prox = NULL;
	*quantidadeAtual = 0;
}

Node *alocaNo(){
    Node *novo=(Node *) malloc(sizeof(Node));

    if(!novo){
		exit(1);
	}else{
		return novo;
	}

}

void insereNo(Node * fila, int *quantidadeAtual, string evento){
    Node * novo = alocaNo();
	novo->prox = NULL;
    novo->evento =  evento;

	if(filaVazia(fila)){
		fila->prox = novo;
    }else{
		Node *aux = fila->prox;

		while(aux->prox != NULL){
			aux = aux->prox;
        }

		aux->prox = novo;
	}
	*quantidadeAtual = *quantidadeAtual + 1;
}


int filaVazia(Node * fila){

    if(fila->prox == NULL){
		return 1;
    }
	else{
		return 0;
    }

}

Node *retiraNo(Node * fila, int *quantidadeAtual){
    Node *aux = fila->prox;
    if(fila->prox == NULL){
		cout << "Fila ja esta vazia\n" << endl;
		return NULL;
	}else{
		fila->prox = aux->prox;
		*quantidadeAtual = *quantidadeAtual - 1;
		return aux;
	}
}

Node *desalocaFila(Node * fila){
    if(!filaVazia(fila)){
		Node *noProximo, *noAtual;

		noAtual = fila->prox;
		while(noAtual != NULL){
			noProximo = noAtual->prox;
			free(noAtual);
			noAtual = noProximo;
            noProximo = NULL;
		}
	}
}


void exibirFila(Node * fila){
	if(filaVazia(fila)){
		cout << "Fila vazia!" << endl;
		return ;
	}

	Node *aux;
	aux = fila->prox;
	while( aux != NULL){
		cout << aux->evento << " " << endl;
		aux = aux->prox;
	}
}

void eSubsequente(Node * subsequencia, Node * sequencia, int * quantidadeSubsequencia, int * quantidaSequencia){
    Node * noSubsequencia = (Node *) malloc(sizeof(Node));
    Node * noSequencia = (Node *) malloc(sizeof(Node));
    int quantidadeEsperada = *quantidadeSubsequencia;
    int quantidadeSequenciaTotal = * quantidaSequencia;
    int quantidadeContido = 0;
    int quantidade = 0;

    while(!filaVazia(subsequencia) && !filaVazia(sequencia)){
        quantidade ++;
        noSubsequencia = retiraNo(subsequencia, &*quantidadeSubsequencia);
        bool igual = false;
        do{
            noSequencia = retiraNo(sequencia, &*quantidaSequencia);
            quantidade ++;
            if(noSequencia->evento == noSubsequencia->evento){
                quantidadeContido ++;
                igual = true;

            }
        }while(!igual &&  !filaVazia(sequencia));
    }

    if(quantidadeContido == quantidadeEsperada){
        cout << "A subsequencia está contida na sequencia!"<< endl;
        cout << "O(m + n) = " << quantidade << " interações. Onde m = " << quantidadeEsperada << " e n = " << quantidadeSequenciaTotal << "." << endl;
    }else{
        cout << "A subsequencia não está contida na sequencia!" << endl;
    }

}

void header() {
  cout << ("Universidade de Brasilia - Campus Gama\n");
  cout <<("Disciplina: Estrutura de Dados e Algoritmos 2\n");
  cout <<("Professor: Mauricio Serrano\n");
  cout <<("Aluno: Gustavo Vieira Braz Gonçalves\n");
  cout <<("Aluno: Ronyell Henrique dos Santos\n");
  cout <<("Tema: Exercício 4\n\n");
}
