#include <iostream>
#include <fstream>
#include <math.h>
#define N 3

using namespace std;

int main(){
	//მონაცემების ინიციალიზაცია;
	double A[N][N], x[N], A1norm = 0, InfinityANorm = 0;

	// მონაცემების შეტანა ფაილიდან;
	ifstream in("2.txt");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			in >> A[i][j];
		}
	}

	//A მატრიცის პირველი ნორმის გამოთვლა;
	for (int i = 0; i < N; i++){
		x[i] = 0;
		for (int j = 0; j < N; j++){
			x[i] += fabs(A[j][i]);
		}
	}

	A1norm = x[0];
	for (int i = 1; i < N; i++){
		if (x[i] > x[i - 1]){
			A1norm = x[i];
		}
	}

	// A მატრიცის უსასრულობა ნორმის გამოთვლა;
	for (int i = 0; i < N; i++){
		x[i] = 0;
		for (int j = 0; j < N; j++){
			x[i] += fabs(A[i][j]);
		}
	}

	InfinityANorm = x[0];

	for (int i = 1; i < N; i++){
		if (x[i] > x[i - 1]){
			InfinityANorm = x[i];
		}
	}

	cout << "A Matrix's First Norm = " << A1norm << endl;
	cout << "A Matrix's Infinity Norm = " << InfinityANorm << endl;

	system("pause");
	return 0;
}