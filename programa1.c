#include <stdio.h>

int main() {
	double r = 50000;
	double c = 0;
	double i, j;
	for (i=-r; i<r; ++i) {
		for (j=-r; j<r; ++j) {
			c += (i*i + j*j) <= (r*r);
		}
	}
	double pi = c/(((r*2 + 1)*(r*2 + 1))/4.0);
	printf("%.6lf\n", pi);
	return 0;
}