#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct job{
  double tempoJob;
  int pesoJob;
  struct job* proximo;
  int coeficiente;
}job;

int marcador = 1;

int contarJobs(job*lista){
  job* aux = lista;
  int contador = 0;

  while(aux!=NULL){
    aux=aux->proximo;
    contador++;
  }
  return contador;
}

job* insereJob (job* listaTrabalhos, double tempo, int peso){
  job* novo = malloc(sizeof(job));
  novo->tempoJob = tempo;
  novo->pesoJob = peso;
  novo->proximo = NULL;
  novo->coeficiente = 0;

  if(listaTrabalhos==NULL){
    listaTrabalhos=novo;
  }else{
    job* temp = NULL;
    temp=listaTrabalhos;

    while(temp->proximo!=NULL){
      temp=temp->proximo;
    }
      temp->proximo=novo;
  }

  return listaTrabalhos;
}

job* removeMenor (job* lista, double menorDuracao){
   job* temp=lista;

   while(temp!=NULL && menorDuracao!=temp->tempoJob){
    if(temp->proximo->tempoJob==menorDuracao){
      break;
    }
    if(temp->tempoJob!=menorDuracao){
     temp=temp->proximo;
    }

   }

   if(temp->tempoJob==menorDuracao){
    job *lixo;
    lixo = temp;
    lista = lixo->proximo;
    free (lixo);

   }else if(temp){
    job *lixo;
    lixo = temp->proximo;
    temp->proximo = lixo->proximo;
    free (lixo);
   }
   return lista;
}

job* removeMaior (job* lista, int maiorPeso){
   job* temp=lista;

   while(temp!=NULL && maiorPeso!=temp->pesoJob){
    if(temp->proximo->pesoJob==maiorPeso){
      break;
    }
    if(temp->pesoJob!=maiorPeso){
     temp=temp->proximo;
    }

   }

   if(temp->pesoJob==maiorPeso){
    job *lixo;
    lixo = temp;
    lista = lixo->proximo;
    free (lixo);

   }else if(temp){
    job *lixo;
    lixo = temp->proximo;
    temp->proximo = lixo->proximo;
    free (lixo);
   }
   return lista;
}

job* ordenaPorDuracao(job*lista){
  job* novaLista=NULL;
  job* temp;
  double menorDuracao=0;
  int peso=0, contador=0;
  int tamanhoLista = contarJobs(lista);

  while(contador<tamanhoLista){
    temp=lista;
    menorDuracao=temp->tempoJob;
    peso=0;
    while(temp!=NULL){

      if(temp->tempoJob <= menorDuracao){
        menorDuracao = temp->tempoJob;
        peso = temp->pesoJob;
      }else{
        //nada a ser feito.
      }
       temp=temp->proximo;
    }

    novaLista = insereJob(novaLista, menorDuracao, peso);
    lista=removeMenor(lista, menorDuracao);

    contador++;
  }
  return novaLista;
}

job* ordenaPorPeso (job* work){

  work=ordenaPorDuracao(work);
  job* novaLista=NULL;
  job* temp;
  double duracao=0;
  int maiorPeso=0, contador=0;
  int tamanhoLista = contarJobs(work);

  while(contador<tamanhoLista){
    temp=work;
    maiorPeso=temp->pesoJob;
    duracao=0;
    while(temp!=NULL){
      if(temp->pesoJob >= maiorPeso){
        maiorPeso = temp->pesoJob;
        duracao = temp->tempoJob;
      }else{
        //nada a ser feito.
      }
       temp=temp->proximo;
    }

    novaLista = insereJob(novaLista, duracao, maiorPeso);
    work = removeMaior(work, maiorPeso);

    contador++;
  }
  return novaLista;
}

int somaResultante(job* lista){
  job* temp=lista;
  int tamanho = contarJobs(lista);
  int cont=0, total=0;

  while(cont<tamanho){
    total = total + temp->coeficiente;
    temp=temp->proximo;
    cont++;
  }

  return total;
}

void exibirJobs (job* lista){
    if(lista){
      printf("Tarefa %d com Duração: %.1lf    Peso: %d     Coeficiente: %d\n",marcador, lista->tempoJob, lista->pesoJob, lista->coeficiente);
      marcador++;
      exibirJobs(lista->proximo);
    }
}

job* calculaCoeficiente (job* lista){
  job* temp = lista;
  int tamanhoLista = contarJobs(lista);
  int cont=0;
  double duracao=0;

  while(cont<tamanhoLista){
    duracao = temp->tempoJob + duracao;

    temp->coeficiente = (int) duracao * temp->pesoJob;

    temp=temp->proximo;
    cont++;
  }

  return lista;
}

int main (){
  job* jobs = NULL;
  int peso=0, opcao=0, total=0;
  double duracao=0;

  printf("******Algoritmo de ordenação de Jobs******\nPor favor escolha as opções de acordo com o menu:\n");

  while(opcao!=4){

    printf("1- Inserir um Job\n2- Ordenar os Jobs de maneira otimizada\n3- Exibir resultado\n4- Encerrar programa\nOpção: ");
    scanf("%d", &opcao);
    printf("\n");

    switch(opcao){
      case 1:
        printf("Insira a duracão, em minutos, e o peso de cada job:\n");
        printf("Duração da tarefa: ");
        scanf("%lf",&duracao);
        printf("Peso da tarefa: ");
        scanf("%d", &peso);

        jobs= insereJob(jobs, duracao, peso);
        printf("\n");
        break;

      case 2:
        jobs=ordenaPorPeso(jobs);
        printf("\n");
        jobs=calculaCoeficiente(jobs);
        printf("Para ver o resultado escolha a opção 3\n");
        break;

      case 3:
        if(jobs){
          printf("A melhor ordem é:\n");
          exibirJobs(jobs);
          total=somaResultante(jobs);
          printf("\nSoma total: %d\n", total);
        }else{
        printf("Primeiramente cadastre os Jobs :(");
        }
        printf("\n");
        break;

      case 4:
        break;
    }

  }
  return 0;
}
