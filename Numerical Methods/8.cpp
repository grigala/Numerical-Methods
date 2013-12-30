#include<iostream>
#include<fstream>
#include<cmath>
#define n 4
using namespace std;
int main(){
	double a[n][n], b[n], x0[n], x1[n] = { 0 }, eps = 0.000001, normaB = 0, sum, normaX;
	int iter = 0;

	// ფაილიდან მონაცემების წაკითხვა;
	ifstream in("8.txt");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			in >> a[i][j];
		in >> b[i];
	}

	//B-ს პირველი ნორმის გამოთვლა;
	for (int j = 0; j < n; j++){
		sum = 0;
		for (int i = 0; i<n; i++){
			if (i != j){
				sum += fabs(-a[i][j] / a[i][i]);
			}
			if (sum > normaB){
				normaB = sum;
			}
		}
	}

	do{
		iter++;
		for (int i = 0; i < n; i++)
			x0[i] = x1[i];
		// ახალი მიახლოების გამოთვლა;
		for (int i = 0; i < n; i++){
			x1[i] = b[i];
			for (int j = 0; j < n; j++){
				if (i != j){
					x1[i] -= a[i][j] * x0[j];
				}
			}
			x1[i] /= a[i][i];
		}

		// x-ის ნორმის გამოთვლა;
		normaX = 0;
		for (int i = 0; i < n; i++){
			normaX += fabs(x1[i] - x0[i]);
		}
	} while (normaB*normaX / fabs(1 - normaB)>eps);

	cout << "B-s norma = " << normaB << endl;
	cout << "iter = " << iter << endl;
	cout << "x[i]: \t";
	for (int i = 0; i < n; i++){
		cout << x1[i] << "\t";
	}

	cout << endl;
	system("pause");
	return 0;
}