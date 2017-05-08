#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct point{
    double x;
    double y;
}Point;

double valorAbsoluto(double x);

double calculaDistancia(double ocidente, double oriente);

int calculaQuantidadeEstacoes(double distancia, double milha);

int main(){
    double ocidente, oriente;

    cout << "Digite a extremidade ocidental: ";
    cin >> ocidente;

    cout << "Digite a extremidade oriental:";
    cin >> oriente;

    double distancia = calculaDistancia(ocidente, oriente);
    int quantidadeBases = calculaQuantidadeEstacoes(distancia, 4.0);

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

 int calculaQuantidadeEstacoes(double distancia, double milha){
     double distanciaAtual = 0.0;
     bool adicionaBase = false;
     int quantidadeBases = 0;

     while(distancia >= distanciaAtual){
         if(adicionaBase){
             quantidadeBases ++;
             cout << "Base " << quantidadeBases << " na milha: " << distanciaAtual << endl;
             adicionaBase = false;
         }else{
             adicionaBase = true;
         }
         distanciaAtual += milha;
     }

     if(adicionaBase){
         quantidadeBases ++;
         cout << "Base " << quantidadeBases << " na milha: " << distancia << endl;
     }

     cout << "Quantidade de Bases: " << quantidadeBases << endl;
     return quantidadeBases;
 }
