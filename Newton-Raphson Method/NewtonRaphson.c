/*
	Algorithm that calculates the Newton-Raphson method
	Author: Jordi Ugarte
	Email: jordi933@gmail.com
	Date: 09/30/2019
*/

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define dydx(x) ((f((x + h)) - f((x - h))) / (2.0 * h))
//////////////////////
#define h 0.001
#define f(x) 2
#define x0 4.000
#define aproximacion 4
//////////////////////

double getDyDx(double xn) {
	double r = dydx(xn);
	if (r == 0.0) {
		printf("\nOperación inválida:\nEl resultado de la derivada numérica es cero.\n");
		exit(-1);
	} else {
		return r;
	}
}

double newtonRaphson(double xn, int i) {
	printf("x[%d] = %0.5f\n", i, xn);
	i++;
	double xnn;
	xnn = xn - (f(xn))/(getDyDx(xn));
	if (i < aproximacion){
		return newtonRaphson(xnn, i);
	} else {
		printf("x[%d] = %0.5f\n", i, xn);
		return xnn
;		
	}
}

int main() {
	newtonRaphson(x0, 0);
	return 0;
}
