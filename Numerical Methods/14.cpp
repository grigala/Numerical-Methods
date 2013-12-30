#include<iostream>
#include<cmath>
#define PI 3.1415961765

using namespace std;

//ინტეგრალქვეშა ფუნქცია
double f(double x){
	return cos(x);
}
// a - მონაკვეთის მარცხენა ბოლო, b - მონაკვეთის მარჯვენა ბოლო, n - კვანძების რაოდენობა;
double trapecia(double a, double b, double n);

int main(){
	double a = 0, b = PI / 2., eps = 0.000001, I1 = 0, I0;
	int n = 1, nmax = 500000;
	do{
		n *= 2;
		I0 = I1;
		I1 = trapecia(a, b, n);
	} while (fabs(I1 - I0) > eps && n < nmax);
	cout << "n=" << n << "      I=" << I1 << endl;
	system("pause");
	return 0;
}

// ტრაპეციის მეთოდი;
double trapecia(double a, double b, double n){
	double h, sum; int i;
	h = (b - a) / n;
	sum = f(a) + f(b);
	for (int i = 1; i <= n - 1; i += 1){
		sum += 2 * f(a + i*h);
	}
	sum *= (h / 2);
	return sum;
}