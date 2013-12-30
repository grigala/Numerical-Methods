#include <iostream>
#include <fstream>
#include <math.h>
#define N 3

using namespace std;

int main(){
	//მონაცემების ინიციალიზაცია, q  = M(i, j) ნამრავლი;
	double A[N][N], B[N], X[N], eps = 0.001, q;

	// მონაცემების შეტანა;
	for (int i = 0; i < N; i++){
		B[i] = 0;
		for (int j = 0; j < N; j++){
			A[i][j] = 1. / (i + j + 1);
			B[i] += A[i][j];
		}
		B[i] += eps;
	}
	
	// პირდაპირი სვლა;
	for (int k = 0; k < N - 1; k++){ // ბიჯები k = 1...n-1;
		for (int i = k + 1; i < N; i++){ // განულების ნომერი;
			q = A[i][k] / A[k][k];
			for (int j = k; j < N; j++){ // i-ური განტოლების კოეფიციენტის ნომერი;
				A[i][j] -= q * A[k][j];
			}
			B[i] -= q * B[k]; // ცდომილება;
		}
	}

	// უკუსვლა;
	X[N - 1] = B[N - 1] / A[N - 1][N - 1];
	for ( int i = N - 2; i >= 0; i--){
		X[i] = 0;
		for (int j = i + 1; j < N; j++){
			X[i] += A[i][j] * X[j];
		}
		X[i] = (B[i] - X[i]) / A[i][i];
	}

	//მონაცემების დაბეჭდვა;
	cout << "i\tX[i]\tFardobitiCdomileba" << endl;

	for (int i = 0; i < N; i++){
		cout << i << "\t" << X[i] << "\t" << fabs(((X[i] - 1) / X[i]) * 100) << "%" << endl;
	}

	system("pause");
	return 0;
}