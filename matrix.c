/*
 * matrix.c
 *
 *  Created on: Jun 8, 2013
 *      Author: nemo
 */

#include "main.h"

void matmult(COMPLEX **A, COMPLEX **B, COMPLEX **C, int size){
	int i, j, k;

	for(i=0 ; i<size; i++){
		for(j=0; j<size; j++){
			C[i][j].re = 0;
			C[i][j].im = 0;
			for(k=0; k<size; k++){
				C[i][j] = caddf(C[i][j], cmltf(A[i][k], B[k][j]));
			}
		}
	}
}

void matadd(COMPLEX **A, COMPLEX **B, COMPLEX **C, int size){
	int i, j;

	for(i=0 ; i<size; i++){
		for(j=0; j<size; j++){
			C[i][j] = caddf(A[i][j], B[i][j]);
		}
	}
}

void matsub(COMPLEX **A, COMPLEX **B, COMPLEX **C, int size){
	int i, j;

	for(i=0 ; i<size; i++){
		for(j=0; j<size; j++){
			C[i][j] = csubf(A[i][j], B[i][j]);
		}
	}
}

void mattran(COMPLEX **A, COMPLEX **C, int size){
	int i, j;

	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			C[i][j] = cnjf(A[j][i]);
		}
	}
}

void matmultvector(COMPLEX **A, COMPLEX *x, COMPLEX *b, int size){
	int i, j;

	for(i=0; i<size; i++){
		b[i].re = 0;
		b[i].im = 0;
		for(j=0; j<size; j++){
			b[i] = caddf(b[i], cmltf(A[i][j], x[j]));
		}
	}
}
