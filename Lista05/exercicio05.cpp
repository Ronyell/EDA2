#include <bits/stdc++.h>
using namespace std;

// Calcula a mediana de dois inteiros
float MO2(int a, int b)
{ return ( a + b ) / 2.0; }

// Calcula a mediana de 3 inteiros
float MO3(int a, int b, int c)
{
	return a + b + c - max(a, max(b, c))- min(a, min(b, c));
}

// Calcula a mediana de 4 inteiros
float MO4(int a, int b, int c, int d)
{
	int Max = max( a, max( b, max( c, d ) ) );
	int Min = min( a, min( b, min( c, d ) ) );
	return ( a + b + c + d - Max - Min ) / 2.0;
}

// Calcula a mediana de um array simples
float medianSingle(int arr[], int n)
{
if (n == 0)
	return -1;
if (n%2 == 0)
		return (arr[n/2] + arr[n/2-1])/2;
return arr[n/2];
}

float findMedianUtil( int A[], int N, int B[], int M )
{
	// If smaller array is empty, return median from second array
	if (N == 0)
	return medianSingle(B, M);

	// If the smaller array has only one element
	if (N == 1)
	{
		// Case 1: If the larger array also has one element,
		// simply call MO2()
		if (M == 1)
			return MO2(A[0], B[0]);


		if (M & 1)
			return MO2( B[M/2], MO3(A[0], B[M/2 - 1], B[M/2 + 1]) );

		return MO3( B[M/2], B[M/2 - 1], A[0] );
	}

	else if (N == 2)
	{
		if (M == 2)
			return MO4(A[0], A[1], B[0], B[1]);
		if (M & 1)
			return MO3 ( B[M/2],
						max(A[0], B[M/2 - 1]),
						min(A[1], B[M/2 + 1])
					);

		return MO4 ( B[M/2],
					B[M/2 - 1],
					max( A[0], B[M/2 - 2] ),
					min( A[1], B[M/2 + 1] )
				);
	}

	int idxA = ( N - 1 ) / 2;
	int idxB = ( M - 1 ) / 2;

	if (A[idxA] <= B[idxB] )
	return findMedianUtil(A + idxA, N/2 + 1, B, M - idxA );

	return findMedianUtil(A, N/2 + 1, B + idxA, M - idxA );
}

float findMedian( int A[], int N, int B[], int M )
{
	if (N > M)
	return findMedianUtil( B, M, A, N );

	return findMedianUtil( A, N, B, M );
}


int main()
{
	int i, entrada, tamanhoA, tamanhoB;

	cout << "****Atenção, os conjuntos devem ser do mesmo tamanho!****\n\n";

	cout << "Digite o tamanho do conjunto A:\n";
	cin >> tamanhoA;
	cout << "Digite o tamanho do conjunto B:\n";
	cin >> tamanhoB;

	if(tamanhoA != tamanhoB){
		cout << "Os conjuntos A e B devem ser do mesmo tamanho!\n\n";
		do{
			cout << "Digite o tamanho do conjunto A:\n";
			cin >> tamanhoA;
			cout << "Digite o tamanho do conjunto B:\n";
			cin >> tamanhoB;
		}while(tamanhoA != tamanhoB);
	}

	int A[tamanhoA];
	int B[tamanhoB];

  printf("Digite os números do conjunto A:(digite -1 para parar)\n");
	for(i=0;i<tamanhoA;i++){
		cin >> entrada;
		if(entrada == -1){
			break;
		}else{
			A[i] = entrada;
		}
	}

	printf("Digite os números do conjunto B:(digite -1 para parar)\n");
	for(i=0;i<tamanhoB;i++){
		cin >> entrada;
		if(entrada == -1){
			break;
		}else{
			B[i] = entrada;
		}
	}

	int N = sizeof(A) / sizeof(A[0]);
	int M = sizeof(B) / sizeof(B[0]);

	cout << "A mediana é: ";
	printf("%.3f", findMedian( A, N, B, M ) );
	return 0;
}
