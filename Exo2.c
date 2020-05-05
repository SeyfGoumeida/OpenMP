#include <stdio.h>
#define SIZE 351

int main() {
	double a[SIZE], b[SIZE], c[SIZE], d[SIZE];
	for (size_t i = 0; i < SIZE; i++)
		a[i] = b[i] = i;
	#pragma omp parallel  
	{
		#pragma omp for schedule(static) nowait
		for (size_t i = 0; i < SIZE; i++){
			c[i] = a[i] + b[i];
			
		}
		#pragma omp for schedule(static)
		for (size_t i = 0; i < SIZE; i++){
			d[i] = a[i] + c[i];
			printf("%g %d %d\n", d[i], i, omp_get_thread_num());
		}
	}
	for (size_t i = 0; i < SIZE; i++)
		printf("%g ", d[i]);
	printf("\n");
	return 0;
}
