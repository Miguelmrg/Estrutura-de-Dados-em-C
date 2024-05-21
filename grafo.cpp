#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declara��o de quantidade de v�rtices do grafo

#define VERTICES 600

//fun��o que cria o grafo

void criar(int grafo[VERTICES][VERTICES]) {
	int i = 0;
	int j = 0;
	int adjacencia = 0;
	
	for (i = 0; i < VERTICES; i++){
		for (j = 0; j < VERTICES; j++){
			grafo[i][j] = 0;
		}
	}
	
	for (i = 0 ; i < (VERTICES - 1) ; i++) { //primeiro ao pen�ltimo
		for (j = (i + 1) ; j < VERTICES ; j++) { //pr�ximo ao �ltimo
			//printf("Digite <l> se %d for adjacente a %d: ", i, j);
			
			//scanf("%d", &adjacencia);
			adjacencia =(rand() % 2); 
			grafo[i][j] = adjacencia;
			grafo[j][i] = adjacencia;
		}
	}
}

//fun��o que imprime o grafo

void imprimir (int grafo[VERTICES][VERTICES]) {
	int i = 0;
	int j = 0;
	
	printf("V: adjacencias \n");
	
	for (i = 0; i < VERTICES; i++) {
		printf("%d: ", i);
		for (j = 0; j< VERTICES; j++){
			if (grafo [i][j]){
				printf("%d", j);
			}
		}
		printf("\n");
	}
	printf("\n");
}

//fun��o que descobre o v�rtice de maior grau

int descobrirMaiorGrau(int grafo[VERTICES][VERTICES]){
	int i = 0;
	int j = 0;
	int grau = 0;
	int maiorGrau = 0;
	int vertice = 0;
	
	for (i = 0; i < VERTICES; i++){
		grau  = 0;
		for (j = 0; j< VERTICES; j++){
			if (grafo[i][j]){
				grau++;
			}
		}
		if (grau > maiorGrau){
			maiorGrau = grau;
			vertice = i;
		}
	}
	return vertice;
}

int main(){
	
	int grafo[VERTICES][VERTICES];
	
	time_t t;
	srand(time(&t));
	
	criar(grafo);
	imprimir(grafo);
	
	printf("v�rtice de maior grau: %d\n", descobrirMaiorGrau(grafo));
}
