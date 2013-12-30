#include <iostream>

using namespace std;

double f(double x){
	return x - cos(x);
}

int main(){
	double a = 0, b = 2, eps = 0.000001, x;
	int k = 0;
	while (b - a > eps){
		k++;
		x = (a + b) / 2;
		if (f(a) * f(x) < 0){
			b = x;
		}
		if (f(b) * f(x) < 0){
			a = x;
		}
		if (f(x) == 0){
			break;
		}
		cout << "K = " << k << "\t" << "X = " << x << endl;
		system("pause");
		return 0;
	}
}