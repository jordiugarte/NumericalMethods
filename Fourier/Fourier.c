/*
	Algorithm to calculate the Fourier Sequence
	Author: Jordi Ugarte
	Email: jordi933@gmail.com
	Date: 09/30/2019
*/

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define pi (4.0 * atan(1.0))
#define ffa(x, m) cos((m * pi * x) / l)
#define ffb(x, m) sin((m * pi * x) / l)
#define fa(x, m) (f(x) * ffa(x, m))
#define fb(x, m) (f(x) * ffb(x, m))

////////////////////////////
#define l (pi / 2.0)
#define a (0.0)
#define b (2.0 * l)
#define N 10000.0
#define h ((b - a) / N)
#define f(x) (exp(-x))
#define aproximaciones 4
////////////////////////////
FILE *fp, *fp1;
double integrarA(int index){
	double R;
	R = fa(a, index) + fa(b, index);
	for(int i = 1; i < N; i++){
		double p = a + (i * h);
		R += (2.0 * fa(p, index));
	}
	R *= (h / 2.0) * (1.0 / l);
	return R;
}

double integrarB(int index){
	double R;
	R = fb(a, index) + fb(b, index);
	for(int i = 1; i < N; i++){
		double p = a + (i * h);
		R += (2.0 * fb(p, index));
	}
	R *= (h / 2.0) * (1.0 / l);
	return R;
}

void valuesAB(){
	for (int j = 0; j <= aproximaciones; j++){
		double A = integrarA(j);
		double B = integrarB(j);
		printf("a[%d] = %0.3f ", j, A);
		printf("b[%d] = %0.3f \n", j, B);
	}
	printf("\n");
}

void valuesXY(){
	double x = a;
	double a0 = integrarA(0);
	while (x < b) {
		double y = (a0 / 2.0);
		for (int j = 1; j <= aproximaciones; j++){
			double A = integrarA(j);
			double B = integrarB(j);
			y += A * ffa(x, j) + B * ffb(x, j);
			fprintf(fp,"%0.3f\t%0.3f\n", x, y);
		}
		x += 0.01;
	}	
}


int main(){
	fp=fopen("datos.txt","w");
	fp1=fopen("graficador.txt","w");
	valuesAB();
	valuesXY();
	fprintf(fp1, "set title \"Series de Fourier\"\n");
	fprintf(fp1, "set grid \n");
	fprintf(fp1, "set xrange [%0.3f:%0.3f]\n", a, b);
	fprintf(fp1, "plot \"datos.txt\" smooth csplines, exp(-x) with lines linestyle 2\n");
	fprintf(fp1, "set term eps\n");
	//fprintf(fp1, "set output \"fourier_graph.eps\"\n");
	//fprintf(fp1, "replot\n");
	//fprintf(fp1, "set term x11\n");
	fprintf(fp1,"pause -1\n");
	fclose(fp);fclose(fp1);
	system("gnuplot graficador.txt");
}