#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double f(double x){
	return 2 * x - 0.5*sin(5 * x) + 1;
}
double f1(double x){
	return 2 - 2.5*cos(5 * x);
}

int main(){
	int k = 0, kmax = 500;
	double x1, x0, eps = 0.000001;
	cout << "Enter x1: \n";
	cin >> x1;
	do{
		k++, x0 = x1;
		x1 = x0 - (f(x0) / f1(x0));
	} while ((fabs(x1 - x0) > eps || fabs(f(x1)) > eps)&& k < kmax);
	cout << "iter=" << k << endl;
	cout << "x:  " << x1 << endl;
	system("pause");
	return 0;
}