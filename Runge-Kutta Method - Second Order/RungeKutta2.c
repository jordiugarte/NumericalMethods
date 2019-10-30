/*
	Algorithm to calculate the Second Order Runge-Kutta
	Author: Jordi Ugarte
	Email: jordi933@gmail.com
	Date: 09/30/2019
*/

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define f(x, y, v) v
#define g(x, y, v) (x - 2.0 * y + 3.0 * v)
#define x0 1.0
#define y0 2.0
#define v0 3.0
#define h 0.5

double r[2];

double getX(double xn) {
	return xn + h;
}

double getYV(double xn, double yn, double vn, double kn, double ln, int index, double R, double V) {
	if (index == 1) {
		double k = h * f((xn), (yn), (vn));
		double l = h * g((xn), (yn), (vn));
		R += k / 6.0;
		V += l /6.0;
		index++;
		return getYV(xn, yn, vn, k, l, index, R, V);
	} else if (index == 2 || index == 3) {
		double k = h * f((xn + h / 2.0), (yn + kn / 2.0), (vn + ln / 2.0));
		double l = h * f((xn + h / 2.0), (yn + kn / 2.0), (vn + ln / 2.0));
		R += k / 3.0;
		V += l / 3.0;
		index++;
		return getYV(xn, yn, vn, k, l, index, R, V);
	} else if (index == 4) {
		double k = h * f((xn + h), (yn + kn), (vn + ln));
		double l = h * f((xn + h), (yn + kn), (vn + ln));
		R += k / 6.0;
		V += l / 6.0;
		index++;
		return getYV(xn, yn, vn, k, l, index, R, V);
	} else {
		r[0] = yn + R;
		r[1] = vn + V;
		return 0;
	}
}

int main (){
	double x1 = getX(x0);
	getYV(x0, y0, v0, 0.0, 0.0, 1, 0.0, 0.0);
	double y1 = r[0];
	double v1 = r[1];

	double x2 = getX(x1);
	getYV(x1, y1, v1, 0.0, 0.0, 1, 0.0, 0.0);
	double y2 = r[0];
	double v2 = r[1];

	printf("| x | y | v | \n");
	printf("%0.3f %0.3f %0.3f \n", x0, y0, v0);
	printf("%0.3f %0.3f %0.3f \n", x1, y1, v1);
	printf("%0.3f %0.3f %0.3f \n", x2, y2, v2);
}
