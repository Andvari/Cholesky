
#include "main.h"

#define	SIZE	8

int main(void){
	int i;
	int j;

	COMPLEX K[SIZE];
	COMPLEX b[SIZE];
	COMPLEX bb[SIZE];
	COMPLEX x[SIZE];

	COMPLEX *pA[SIZE];
	COMPLEX *pL[SIZE];
	COMPLEX *pR[SIZE];
	COMPLEX *pLT[SIZE];
	COMPLEX *pDT[SIZE];
	COMPLEX **A;
	COMPLEX **L;
	COMPLEX **R;
	COMPLEX **LT;
	COMPLEX **DT;
	float max;

	A = &pA[0];
	L = &pL[0];
	R = &pR[0];
	LT = &pLT[0];
	DT = &pDT[0];

	for(i=0; i<SIZE; i++){
		pA[i]  = (COMPLEX *)malloc(SIZE*sizeof(COMPLEX));
		pL[i]  = (COMPLEX *)malloc(SIZE*sizeof(COMPLEX));
		pR[i]  = (COMPLEX *)malloc(SIZE*sizeof(COMPLEX));
		pLT[i] = (COMPLEX *)malloc(SIZE*sizeof(COMPLEX));
		pDT[i] = (COMPLEX *)malloc(SIZE*sizeof(COMPLEX));
	}

	for(i=0; i<SIZE; i++){
		K[i].re = 30000.*(float)random()/RAND_MAX;
		K[i].im = 30000.*(float)random()/RAND_MAX;
	}

	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			A[i][j] = cmltf(K[j], cnjf(K[i]));

		}
	}

	for(i=0; i<SIZE; i++){
		A[i][i].re += A[i][i].re*.001;
	}


	for(i=0; i<SIZE; i++){
		b[i].re = 100000.*(float)random()/RAND_MAX;
		b[i].im = 100000.*(float)random()/RAND_MAX;
	}

	print_matrix("A", A, SIZE);
	print_vector("b", b, SIZE);

	holesky(A, L, SIZE);
	print_matrix("L", L, SIZE);

	mattran(L, LT, SIZE);

	matmult(L, LT, R, SIZE);
	print_matrix("R", R, SIZE);

	matsub(A, R, DT, SIZE);
	print_matrix("DT", DT, SIZE);

	holesky_solve(L, b, x, SIZE);
	print_vector("x", x, SIZE);

	matmultvector(A, x, bb, SIZE);
	print_vector("bb", bb, SIZE);

	for(i=0; i<SIZE; i++){
		free(pA[i]);
		free(pL[i]);
		free(pR[i]);
		free(pLT[i]);
		free(pDT[i]);
	}

	return (0);
}

