/*
 * holesky.c
 *
 *  Created on: Jun 9, 2013
 *      Author: nemo
 */

#include "main.h"

void holesky(COMPLEX **A, COMPLEX **L, int size){
	int i, j, k;
	COMPLEX tmp;

	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			L[i][j].re = 0;
			L[i][j].im = 0;
		}
	}

	for(i=0; i<size; i++){
		for(j=0; j<i; j++){
			tmp.re = 0;
			tmp.im = 0;
			for(k=0; k<j; k++){
				tmp = caddf(tmp, cmltf(L[i][k], cnjf(L[j][k])));
			}
			L[i][j] = cdivf(csubf(A[i][j], tmp), L[j][j]);
		}

		tmp.re = 0;
		tmp.im = 0;
		for(k=0; k<i; k++){
			tmp = caddf(tmp, cmltf(L[i][k], cnjf(L[i][k])));
		}
		L[i][i].re = sqrtf(cabf(csubf(A[i][i], tmp)));
		L[i][i].im = 0.;
	}

}

void holesky_solve(COMPLEX **L, COMPLEX *b, COMPLEX *x, int size){
	COMPLEX *y;
	int i, j;
	COMPLEX tmp;

	y = (COMPLEX *)malloc(size*sizeof(COMPLEX));

	for(i=0; i<size; i++){
		tmp.re = 0;
		tmp.im = 0;
		for(j=0; j<i; j++){
			tmp = caddf(tmp, cmltf(L[i][j], y[j]));
		}
		y[i].re = (b[i].re - tmp.re)/cabf(L[i][i]);
		y[i].im = (b[i].im - tmp.im)/cabf(L[i][i]);
	}

	for(i=size-1; i>=0; i--){
		tmp.re = 0;
		tmp.im = 0;
		for(j=i+1; j<size; j++){
			tmp = caddf(tmp, cmltf(cnjf(L[j][i]), x[j]));
		}
		x[i].re = (y[i].re - tmp.re)/cabf(L[i][i]);
		x[i].im = (y[i].im - tmp.im)/cabf(L[i][i]);
	}

	free(y);
}
