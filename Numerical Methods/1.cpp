#include <iostream>
#include <fstream>
#include <math.h>
#define N 3

using namespace std;

int main(){
	//მონაცემების ინიციალიზაცია;
	double A[N][N], V[N] = { 0 }, AV[N], Sum, Anorm = 0;

	// მონაცემების შეტანა ფაილიდან;
	ifstream in("1.txt");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			in >> A[i][j];
		}
		in >> V[i];
	}

	//A მატრიცის ნამრვალი V ვექტორზე;
	for (int i = 0; i < N; i++){
		Sum = 0;
		for (int j = 0; j < N; j++){
			Sum += A[i][j] * V[j];
		}
		AV[i] = Sum;
	}

	//AV-ვექტორის V ვექტორზე;
	for (int i = 0; i < N; i++){
		Anorm += AV[i] * V[i];
	}

	cout << "A Norm = " << sqrt(Anorm) << endl;

	system("pause");
	return 0;
}