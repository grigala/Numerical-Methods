#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#define N 4

using namespace std;

int main(){
	// მონაცემების შეტანა; A მატრიცა, B ცნობილი მარჯვენა მხარე;
	// xNew საწყისი უცნობების მატრიცა, xOld გარდაქმნილი საძიებელი ვექტორი;
	// eps ცდომილება, norm ვექტორის ნორმა 

	double A[N][N], B[N], xNew[N] = { 0 }, xOld[N], eps = 0.0000001, norm;
	// K იტერაციებისთვის;
	int k = 0, kMax = 500;

	// მონაცემების წაკითხვა ფაილიდან;
	ifstream in("9.txt");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			in >> A[i][j];
		}
	}

	for (int i = 0; i < N; i++){ 
		in >> B[i];
	}

	do{
		k++;
		for (int i = 0; i < N; i++){
			xOld[i] = xNew[i];
		}

		for (int i = 0; i < N; i++){
			xNew[i] = B[i];

			for (int j = 0; j < i; j++){
				xNew[i] -= A[i][j] * xNew[j];
			}

			for (int j = i + 1; j < N; j++){
				xNew[i] -= A[i][j] * xOld[j];
			}
			xNew[i] = xNew[i] / A[i][i];
		}

		norm = 0;
		// პირველი ნორმა;
		for (int i = 0; i < N; i++) 
			norm += fabs(xOld[i] - xNew[i]);
	} while (norm > eps && k < kMax);


	// პასუხის დაბეჭდვა;
	cout << k << "\n";
	for (int i = 0; i < N; i++)
		cout << xNew[i] << "\t";
	cout << "\n\n";

	system("pause");
	return 0;
}
