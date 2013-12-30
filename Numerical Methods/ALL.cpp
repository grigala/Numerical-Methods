//
//  main.cpp
//  რიცხვითი
//
//  Created by c0mrad on 10/15/13.
//  Copyright (c) 2013 Giorgi Grigalashvili. All rights reserved.
//

/*************************************************************************
 // 1. ვექტორის პირველი ნორმა.
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <math.h>

#define PI 3.1415961765
#define eps 0.000001
#define N 3

using namespace std;


int main(){
    double Matrix[N][N], Vector[N], SumMatrix[N] = { 0 }, Norma = 0;
    int i, j;
    
    cout<<"შემოიტანეთ 3 განზომილებიანი მატრიცი:\n";
    //ifstream in("Matrix.txt");
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            cin >> Matrix[i][j];
        }
    }
    
    cout<<"შემოიტანეთ ვექტორი:\n";
    for(i=0; i<N; i++){
        cin >> Vector[i];
    }
    
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            SumMatrix[i] += Matrix[i][j] * Vector[j];
        }
    }
    
    for (i=0; i<N; i++) {
        Norma += SumMatrix[i] * Vector[i];
    }
    
    cout<<"ვექტორის ნორმა = "<< sqrt(Norma) << endl;
    
    system("pause");
    return 0;
}
*************************************************************************/

/**********************************************************************
 // 2. მატრიცის პირველი და უსასრულობა ნორმის დათვლა;
#include <iostream>
#include <fstream>
#include <math.h>
#define N 3

using namespace std;

int main(){
	//მონაცემების ინიციალიზაცია;
	double A[N][N], x[N], A1norm = 0, InfinityANorm = 0;
    
	// მონაცემების შეტანა ფაილიდან;
	//ifstream in("2.txt");
    cout<<"შემოიტანეთ 3 განზომილებიანი A მატრიცი: "<<endl;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> A[i][j];
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
**********************************************************************/

/*************************************************************************
 // 3. წრფივ განტოლებათა სისტემის ამოხსნა გაუსის მეთოდით წამყვანი ელემენტის ამორჩევის გარეშე.
#include <iostream>
#include <fstream>
#include <math.h>
#define N 3

using namespace std;

int main(){
	//მონაცემების ინიციალიზაცია, q  = M(i, j) ნამრავლი;
	double A[N][N], B[N], X[N], eps = 0.001, q;
    
	// მონაცემების შეტანა;
	for (int i = 0; i < N; i++){
		B[i] = 0;
		for (int j = 0; j < N; j++){
			A[i][j] = 1. / (i + j + 1);
			B[i] += A[i][j];
		}
		B[i] += eps;
	}
	
	// პირდაპირი სვლა;
	for (int k = 0; k < N - 1; k++){ // ბიჯები k = 1...n-1;
		for (int i = k + 1; i < N; i++){ // განულების ნომერი;
			q = A[i][k] / A[k][k];
			for (int j = k; j < N; j++){ // i-ური განტოლების კოეფიციენტის ნომერი;
				A[i][j] -= q * A[k][j];
			}
			B[i] -= q * B[k]; // ცდომილება;
		}
	}
    
	// უკუსვლა;
	X[N - 1] = B[N - 1] / A[N - 1][N - 1];
	for ( int i = N - 2; i >= 0; i--){
		X[i] = 0;
		for (int j = i + 1; j < N; j++){
			X[i] += A[i][j] * X[j];
		}
		X[i] = (B[i] - X[i]) / A[i][i];
	}
    
	//მონაცემების დაბეჭდვა;
	cout << "i\tX[i]\tFardobitiCdomileba" << endl;
    
	for (int i = 0; i < N; i++){
		cout << i << "\t" << X[i] << "\t" << fabs(((X[i] - 1) / X[i]) * 100) << "%" << endl;
	}
    
	system("pause");
	return 0;
}
*************************************************************************/

/***********************************************************************
// 6. სამდიაგონალური მატრიცის LU ფაქტორიზაცია თომასის ალგორითმით.
//0 2 1 3
//2 3 1 6
//2 3 1 6
//2 3 0 5
#include<iostream>
#include<fstream>
#include<math.h>
#define n 4

using namespace  std;

int  main(){
	double a[n], b[n], c[n], f[n], x[n], y[n], alfa[n], beta[n];
    
	//ifstream in("6.txt");
	for (int i = 0; i < n; i++){
		cin >> b[i];
		cin >> a[i];
		cin >> c[i];
		cin >> f[i];
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
*******************************************************************/

/**************************************************************************

// 8. წრფივ განტოლებათა სისტემის ამოხსნა იაკობის იტერაციული მეთოდით.
#include<iostream>
#include<fstream>
#include<cmath>
#define n 4
using namespace std;
int main(){
	double a[n][n], b[n], x0[n], x1[n] = { 0 }, eps = 0.000001, normaB = 0, sum, normaX;
	int iter = 0;
    
	// ფაილიდან მონაცემების წაკითხვა;
	//ifstream in("8.txt");
    cout<<"შემოიტანეთ 4 განზომილებიანი A მატრიცი: "<<endl;
    for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
        }
    }
    
    cout<<"შემოიტანეთ B ვექგტორი: "<<endl;
    for(int i = 0; i < n; i++){
        cin >> b[i];
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
**************************************************************************/

/*************************************************************************
 // 9 . წრფივ განტოლებათა სისტემის ამოხსნა გაუს-ზეიდელის იტერაციული მეთოდით.
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
 
 cout<<"შემოიტანეთ 4 განზომილებიანი A მატრიცი:"<<endl;
 // მონაცემების წაკითხვა ფაილიდან;
 //ifstream in("9.txt");
 for (int i = 0; i < N; i++){
 for (int j = 0; j < N; j++){
 cin >> A[i][j];
 }
 }
 
 cout<<"შემოიტანეთ B ვექტორი:"<<endl;
 for (int i = 0; i < N; i++){
 cin >> B[i];
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
 *************************************************************************/

/*************************************************************************
// 10. არაწრფივი განტოლების ფესვის გამოთვლა ბისექციის მეთოდით;
#include <iostream>
#include <cmath>

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
 
 *************************************************************************/



/**************************************************************************
// 11. არაწრფივი განტოლების ფესვის გამოთვლა მეთოდით;
#include <iostream>
#include <cmath>

using namespace std;

double f1(double x){
    return cos(x);
}

double f(double x){
    return x - cos(x);
}
int main(){
    double x0, x1, eps = 0.000001;
    int k = 0, maxk = 300;
    
    cout<<"x1 = ";
    cin>>x1;
    
    do{
        k++;
        x0 = x1;
        x1 = f1(x0);
        
    }while (fabs(x1 - x0) > eps || (fabs(f(x1) > eps) && k < maxk));
    
    cout<<"k = " << k << " x1 = "<< x1 <<endl;
    
    system("pause");
    return 0;
}
 *************************************************************************/

/**************************************************************************
// 12. არაწრფივი განტოლების ფესვის გამოთვლა ნიუტონის (მხებთა) მეთოდით
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

*************************************************************************/

/*************************************************************************
 
// 13. განსაზღვრული ინტეგრალის გამოთვლა მართკუთხედების განზოგადებული ფორმულით;
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <math.h>
 
#define PI 3.1415961765
#define eps 0.000001
#define N 3
 
 
 double func(double x){
    return 1/sqrt(x*x+1);
}

double rectangle(double a, double b, int n);

int main(){
    double a = 0.2, b = 1.2, I1 = 0, I0;
    int n = 1, nmax = 50000;
    do{
        n *= 2;
        I0 = I1;
        I1 = rectangle(a, b, n);
    }while (fabs(I1 - I0) > eps && n < nmax);
    cout<<"n = " << n << " I = "<< I1 <<endl;
    
    system("pause");
    return 0;
}

double rectangle(double a, double b, int n){
    double h, sum = 0;
    int i;
    h = (b - a)/ n;
    for (i = 0; i <= n - 1; i++) {
        sum += func(a + i * h + h / 2);
    }
    sum *= h;
    return sum;
}
*************************************************************************/

/*************************************************************************
// 14. განსაზღვრული ინტეგრალის გამოთვლა ტრაპეციების განზოგადოებული ფორმულით;

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
	cout << "n = " << n << "      I = " << I1 << endl;
	system("pause");
	return 0;
}

// ტრაპეციის მეთოდი;
double trapecia(double a, double b, double n){
	double h, sum;
	h = (b - a) / n;
	sum = f(a) + f(b);
	for (int i = 1; i <= n - 1; i += 1){
		sum += 2 * f(a + i*h);
	}
	sum *= (h / 2);
	return sum;
}
**************************************************************************/

/*************************************************************************
// 15. განსაზღვრული ინტეგრალის გამოთვლა სიმპსონის განზოგადოებული ფორმულით;

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
	cout << "n = " << n << "      I = " << I1 << endl;
	system("pause");
	return 0;
}

//სიმპსონის ფორმულა;
double simpson(double a, double b, int n){
	double h, sum;
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
*************************************************************************/
