#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <math.h>

#define LER "r"
#define ESCREVER "w"

using namespace std;

int main(int argc, char const *argv[]) {
  FILE * arquivo = fopen("exemploDezMilhoes.txt", ESCREVER);

  long int num = 10000000, prss = 0;

   for (long int contador = 0; contador < num; contador ++){
      fprintf(arquivo, "%ld\n", prss +=3 );
   }

   cout << prss;

  return 0;
}
