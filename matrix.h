/*
 * matrix.h
 *
 *  Created on: Jun 8, 2013
 *      Author: nemo
 */

#ifndef MATRIX_H_
#define MATRIX_H_

void matmult(COMPLEX **, COMPLEX **, COMPLEX **, int);
void matadd(COMPLEX **, COMPLEX **, COMPLEX **, int);
void matsub(COMPLEX **, COMPLEX **, COMPLEX **, int);
void mattran(COMPLEX **, COMPLEX **, int);
void matmultvector(COMPLEX **, COMPLEX *, COMPLEX *, int);

#endif /* MATRIX_H_ */
