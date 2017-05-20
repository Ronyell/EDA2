#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <math.h>

using namespace std;

#define NOT_MAJORITY -1

int findMajority(int *vectorNumbers,  int initIndex,  int endIndex);

void printMajority(int majorityNumber);

void header();

int main(){
  int quantityCards;
  cout << "Digite a quantidade de cartões: ";
  cin >> quantityCards;

  int * vectorNumbers = new int[quantityCards];

  for(int count = 0; count < quantityCards; count++){
    do{
        cout << "Digite o número do cartão ["  << count << "]:";
        cin >> vectorNumbers[count];
    }while(vectorNumbers[count] < 0);
  }

  int majorityNumber = findMajority(vectorNumbers, 0, quantityCards - 1);

  printMajority(majorityNumber);

  return 0;
}

void printMajority(int majorityNumber){
  if(majorityNumber != NOT_MAJORITY){
    cout << "Número de cartão majoritário: " << majorityNumber << endl;
  }else{
    cout << "Não existe cartão majoritário!" << endl;
  }
}

int findMajority(int *vectorNumbers,  int initIndex,  int endIndex){
  int quantity = endIndex - initIndex + 1;
  if (quantity == 1){
    return vectorNumbers[initIndex];
  }

  int numberMajorityA = findMajority(vectorNumbers, initIndex, (initIndex + endIndex - 1)/2);
  int numberMajorityB = findMajority(vectorNumbers, (initIndex + endIndex - 1)/2 + 1, endIndex);

  if( numberMajorityA == numberMajorityB ) return numberMajorityA ;

  int count = 0;
  for(int i = initIndex; i <= endIndex; i++){
    if(vectorNumbers[i] == numberMajorityA){
      count ++;
    }
  }

  if(count > quantity/2){
    return numberMajorityA;
  }

  count = 0;
  for(int i = initIndex; i <= endIndex; i++){
    if(vectorNumbers[i] == numberMajorityB){
      count ++;
    }
  }

  if(count > quantity/2){
    return numberMajorityB;
  }

  return NOT_MAJORITY;
}
