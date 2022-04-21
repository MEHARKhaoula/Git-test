#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

// Déclaration
#define SIZE 200000
#define N_ITERATIONS 200

int main() {
	
	int i, j, k;
	double temps_debut, temps_fin;
	long double temps_total_pris;

	int nb_threads[] = {1, 2, 4, 8,  12, 20, 30, 40, 50,  100, 200};

	// Initialisation
	long double A[SIZE], B[SIZE], NUM;
	for(i=0; i<SIZE; ++i)
		A[i] = rand();
	NUM = rand();

	for(j=0; j<11; ++j)
	{
		temps_total_pris = 0;

		for(k=0; k<N_ITERATIONS; ++k)
		{
			temps_debut = omp_get_wtime();
			#pragma omp parallel for default(none) private(i) shared(A,B,NUM) num_threads(nb_threads[j]) 
			for(i=0; i<SIZE; ++i)
				B[i] = A[i]/NUM;
			temps_fin = omp_get_wtime();
			temps_total_pris += (temps_fin- temps_debut);
		}
		
		printf("No.de Threads = %d, Temps pris: %Lf\n", nb_threads[j], temps_total_pris/N_ITERATIONS);
	}
	
}