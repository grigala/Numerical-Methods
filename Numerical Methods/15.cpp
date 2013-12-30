#include<iostream>
#include<cmath>
#define PI 3.1415961765

using namespace std;

// ინტეგრალქვეშა ფუნქცია;
double f(double x){
	return cos(x);
}

//a - მონაკვეთის მარცხენა ბოლო, b - მონაკვეთის მარჯვენა ბოლო, n - კვანძების რაოდენობა;
double simpson(double a, double b, int n);

int main(){
	double a = 0, b = PI / 2., eps = 0.000001, I1 = 0, I0;
	int n = 1, nmax = 500000;
	do{
		n *= 2;
		I0 = I1;
		I1 = simpson(a, b, n);
	} while (fabs(I1 - I0) > eps && n < nmax);
	cout << "n=" << n << "      I=" << I1 << endl;
	system("pause");
	return 0;
}

//სიმპსონის ფორმულა;
double simpson(double a, double b, int n){
	double h, sum; int i;
	h = (b - a) / n;
	sum = f(a) + f(b);
	for (int i = 1; i <= n - 1; i += 2){
		sum += 4 * f(a + i*h);
	}
	for (int i = 2; i <= n - 2; i += 2){
		sum += 2 * f(a + i*h);
	}
	sum *= h / 3;
	return sum;
}