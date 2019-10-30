/*
	Algorithm to calculate the Rnge-Kutta Method
	Author: Jordi Ugarte
	Email: jordi933@gmail.com
	Date: 09/30/2019
*/

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define f(x, y) ((-x * sin(x)) + (y/x))
#define x0 2.0
#define y0 3.0
#define h 0.5

double getX(double xn) {
	return xn + h;
}

double getY(double xn, double yn, double kn, int index, double R) {
	if (index == 1) {
		double k = h * f((xn), (yn));
		R += k / 6.0;
		index++;
		return getY(xn, yn, k, index,  R);
	} else if (index == 2 || index == 3) {
		double k = h * f((xn + h / 2.0), (yn + kn / 2.0));
		R += k / 3.0;
		index++;
		return getY(xn, yn, k, index, R);
	} else if (index == 4) {
		double k = h * f((xn + h), (yn + kn));
		R += k / 6.0;
		index++;
		return getY(xn, yn, k, index, R);
	} else {
		return yn + R;
	}
}

int main (){
	double x1 = getX(x0);
	double y1 = getY(x0, y0, 0.0, 1, 0.0);
	double x2 = getX(x1);
	double y2 = getY(x1, y1, 0.0, 1, 0.0);
	printf("| x | y | \n");
	printf("%0.3f %0.3f \n", x0, y0);
	printf("%0.3f %0.3f \n", x1, y1);
	printf("%0.3f %0.3f \n", x2, y2);
}
