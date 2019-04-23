#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NMAT 100
#define SIZE 4

typedef double Mat[SIZE][SIZE];
Mat vec1[NMAT];
Mat vec2[NMAT];

void mulMatMat(Mat &m1, Mat &m2, Mat &m3) {
	for (int i=0; i<SIZE; ++i) {
		for (int j=0; j<SIZE; ++j) {
			double sum = 0;
			for (int k=0; k<SIZE; ++k) {
				sum += m1[i][k]*m2[k][j];
			}
			m3[i][j] = sum;
		}
	}
}

void fillMat(Mat &m) {
	for (int i=0; i<SIZE; ++i) {
		for (int j=0; j<SIZE; ++j) {
			m[i][j] = 2 - rand() * (4 / (double)(RAND_MAX));
		}
	}
}

void printMat(Mat m) {
	for (int i=0; i<SIZE; ++i) {
		for (int j=0; j<SIZE; ++j) {
			if (j) {
				printf(" ");
			}
			printf("%5f", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	srand(time(nullptr));
	for (int i=0; i<NMAT; ++i) {
		fillMat(vec1[i]);
	}
}