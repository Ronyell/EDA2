#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <math.h>

using namespace std;

int calculateForce(double * vectorNumbers,  int initIndex,  int endIndex);

int main(){
  double vectorNumbers[6] = {1.0,2.0,3.0,4.0,5.0,6.0};
  int quantity = 6;

  calculateForce(vectorNumbers, 0, quantity - 1);
  return 0;
}

int calculateForce(double * vectorNumbers,  int initIndex,  int endIndex){
    for(int i = 0;i <= endIndex ; i++){
      double force = 0.0;
      for(int j = 0; j <= endIndex ; j++){
        if(j < i){
          double aux1 = (vectorNumbers[i]*vectorNumbers[j]);
          double aux2 = (i - j) * (i - j);
          force += aux1 / aux2;
        }else if(j > i){
          double aux1 = (vectorNumbers[i]*vectorNumbers[j]);
          double aux2 = (i - j) * (i - j);
          force -= aux1 / aux2;
        }
      }
      cout <<"Force [" << i << "]: " << force << endl;
    }
    return 0;
}
