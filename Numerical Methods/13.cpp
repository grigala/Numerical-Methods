#include<iostream>
#include<cmath>
#include<conio.h>
#include <math.h>
#define PI 3.1415961765

using namespace std;

// ინტეგრალქვეშა ფუნქცია;
double func(double x){
	return cos(x);
}

double rectangle(double a, double b, int n);

int main(){
	double a = 0, b = PI / 2., eps = 0.000001, I1 = 0, I0;
	int n = 1, nmax = 500000;
	do{
		n *= 2;
		I0 = I1;
		I1 = rectangle(a, b, n);
	} while (fabs(I1 - I0) > eps && n < nmax);
	cout << "n=" << n << " I=" << I1 << endl;
	
	system("pause");
	return 0;
}

// მართკუთხედის მეთოდი;
double rectangle(double a, double b, int n){
	double h, sum; int i;
	h = (b - a) / n;
	sum = 0;
	for (int i = 0; i <= n - 1; i++)
		sum += func(a + i*h + h / 2);
	sum *= h;
	return sum;
}