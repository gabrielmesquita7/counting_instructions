#ifndef MATRIZ_H 
#define MATRIZ_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>

#define N 7

typedef struct Matriz{
	int M[N][N];
	char flag; //**se eu retirar a flag a soma nao funciona
	int soma;
	int vetor[N*N];
}Matriz;

void IniciaM(Matriz *m);
void PercorrerM(Matriz *m);
void PrintaM(Matriz *m);
void Caminho(Matriz *m);
void ValoresCaminho(Matriz *m);

#endif