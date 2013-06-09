/*
 * console.c

 *
 *  Created on: Jun 9, 2013
 *      Author: nemo
 */

#include "main.h"

void print_matrix(char *name, COMPLEX **A, int size){
	char str[32];
	int i;
	int j;

	printf("---------------%s----------------\n", name);

	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			printf("%s", ctostr(str, A[i][j]));
		}
		printf("\n");
	}

}

void print_vector(char *name, COMPLEX *A, int size){
	char str[32];
	int i;

	printf("---------------%s----------------\n", name);

	for(i=0; i<size; i++){
		printf("%s", ctostr(str, A[i]));
	}
	printf("\n");
}


char *ctostr(char *str, COMPLEX a){

	if(a.re == -0) a.re = abs(a.re);
	if(a.im == -0) a.im = abs(a.im);

	if(a.re >= 0){
		sprintf(str, "[ %1.5e : ", a.re);
	}
	else{
		sprintf(str, "[%1.5e : ", a.re);
	}

	if(a.im >= 0){
		sprintf(&str[strlen(str)], " %1.5e]", a.im);
	}
	else{
		sprintf(&str[strlen(str)], "%1.5e]", a.im);
	}

	return str;
}
