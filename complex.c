/*
 * complex.c
 *
 *  Created on: Jun 8, 2013
 *      Author: nemo
 */

#include "main.h"

COMPLEX cmltf(COMPLEX op1, COMPLEX op2){
	COMPLEX dst;

	dst.re = op1.re * op2.re - op1.im * op2.im;
	dst.im = op1.re * op2.im + op1.im * op2.re;

	return dst;
}

COMPLEX cnjf(COMPLEX op){
	COMPLEX dst;

	dst.re =  op.re;
	dst.im = -op.im;

	return dst;
}

float cabf(COMPLEX op){
	float dst;
	dst = sqrt(op.re * op.re + op.im * op.im);

	return dst;
}

COMPLEX caddf(COMPLEX op1, COMPLEX op2){
	COMPLEX dst;

	dst.re = op1.re + op2.re;
	dst.im = op1.im + op2.im;

	return dst;
}

COMPLEX csubf(COMPLEX op1, COMPLEX op2){
	COMPLEX dst;

	dst.re = op1.re - op2.re;
	dst.im = op1.im - op2.im;

	return dst;
}

COMPLEX cdivf(COMPLEX op1, COMPLEX op2){
	COMPLEX dst;

	dst = cmltf(op1, cnjf(op2));
	dst.re /= op2.re*op2.re + op2.im*op2.im;
	dst.im /= op2.re*op2.re + op2.im*op2.im;

	return dst;
}

float carf(COMPLEX op){
	float dst;

	dst = atan2(op.im, op.re);

	return dst;
}


COMPLEX csqrf(COMPLEX op){
	COMPLEX dst;
	float a;
	float phase;

	a = sqrt(cabf(op));
	phase = carf(op);

	dst.re = a*cos((phase + 2.*M_PI)/2.);
	dst.im = a*sin((phase + 2.*M_PI)/2.);

	return dst;
}
