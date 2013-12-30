#include<iostream>
#include<fstream>
#include<math.h>
#define n 4

using namespace  std;

int  main(){
	double a[n], b[n], c[n], f[n], x[n], y[n], alfa[n], beta[n];

	ifstream in("6.txt");
	for (int i = 0; i < n; i++){
		in >> b[i];
		in >> a[i];
		in >> c[i];
		in >> f[i];
	}
	// L და U-ს გამოთვლა;
	alfa[0] = a[0];
	for (int i = 1; i < n; i++){
		beta[i] = b[i] / alfa[i - 1];
		alfa[i] = a[i] - beta[i] * c[i - 1];
	}
	// LY=f
	y[0] = f[0];
	for (int i = 1; i < n; i++){
		y[i] = f[i] - beta[i] * y[i - 1];
	}

	// Ux=y
	x[n - 1] = y[n - 1] / alfa[n - 1];
	for (int i = n - 2; i >= 0; i--){
		x[i] = (y[i] - c[i] * x[i + 1]) / alfa[i];
	}

	// პასუხი  
	for (int i = 0; i < n; i++){
		cout << x[i] << endl;
	}
	system("pause");
	return 0;
}