/*
	Algorithm to calculate the derived of an equation
	Author: Jordi Ugarte
	Email: jordi933@gmail.com
	Date: 09/30/2019
*/

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define f(x) ((3.0 * pow(x, 2.0)) + (2.0 * x))
#define h 0.001
#define dydx(x) ((f((x + h)) - f((x - h))) / (2.0 * h))
#define x0 2.0

int main(){
	printf("%0.3f\n", dydx(x0));
}