#include <stdio.h>

/* 4*2^10 = 4K */
#define BUFFER_LEN 0x1000

/* 2^10 = 1K */
#define MAX_I 0x400

/* 2^10 = 1K */
#define MAX_J 0x400

unsigned char buffer[BUFFER_LEN] = {};

void write(FILE* file, int pos) {
	fseek(file, pos, SEEK_SET);
	fwrite(buffer, BUFFER_LEN, 1, file);
	fflush(file);
}

int main() {
	buffer[0] = 1;
	buffer[BUFFER_LEN - 1] = 1;
	int* counter = (int*)(buffer + (BUFFER_LEN >> 1));
	FILE* file1 = fopen("file1.bin", "wb");
	FILE* file2 = fopen("file2.bin", "wb");
	int i, j;
	for (i=0; i<MAX_I; ++i) {
		for (j=0; j<MAX_J; ++j) {
			int pos = (j*MAX_I + i)*BUFFER_LEN;
			write(file1, pos);
			write(file2, pos);
			++*counter;
		}
	}
	fclose(file1);
	fclose(file2);
	return 0;
}