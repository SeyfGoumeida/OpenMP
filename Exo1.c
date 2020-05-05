#include <stdio.h>
#include <omp.h>
#define NTHREADS 10


int main(int argc,char *argv[]){
	
	int tid;
     

	/*#pragma omp parallel private (tid)
	{
		tid=omp_get_thread_num();
		printf("Hello world from thread: %d\n",tid);
		
		if(tid==0){
			printf("le nombre de threads  est : %d\n  ,et le nombre de processeurs est : = %d"
				,omp_get_num_threads(),omp_get_num_procs());
		}
	}*/

	omp_set_num_threads(NTHREADS);	//Si on force le nombre de threads à 10 
	#pragma omp parallel private (tid) 
	{
		tid=omp_get_thread_num();
		printf("Hello world from thread: %d\n",tid);
		
		if(tid==0){
			printf("le nombre de threads  est : %d\n  ,et le nombre de processeurs est : = %d"
				,omp_get_num_threads(),omp_get_num_procs());
		}
	}
	return 0;
}
 
