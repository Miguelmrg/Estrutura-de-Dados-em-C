//////////////////////////////////////////
//programa que implementa o bubblesort////
//////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//////////////////////////////////////////
//declara��o de vari�veis/////////////////
//////////////////////////////////////////

int vetor[1000];
int i;
int j;
int troquei;

//////////////////////////////////////////
//fun��o principal de execu��o do programa
//////////////////////////////////////////

int main(){
	//inicializa��o da aleatoriedade
	time_t t;
	srand(time(&t));
	
	//preenchimento do vetor
	for(i=0;i<1000;i++){
		vetor[i]=(rand()%1000);
	}
	
	//impress�o do vetor
	for (i=0;i<1000;i++){
		printf("%d\t", vetor[i]);
	}
	//ordena��o propriamente dita
	troquei=1;
	while(troquei){
		troquei=0;
		
		for (i=0; i<999; i++){
			if (vetor[i]>vetor[i+1]){
				int temp = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = temp;
				
				troquei = 1;
			}
		}
	}
	
	//impress�o do vetor
	printf("\n=======================================================================================================================\n");
	for (i=0;i<1000;i++){
		printf("%d\t", vetor[i]);
	}
}
