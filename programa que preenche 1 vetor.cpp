////////////////////////////////////////
// PROGRAMA QUE PREENCHE UM VETOR :D ///
////////////////////////////////////////

#include <stdio.h>

////////////////////////////////////////
// declara��o de vari�veis /////////////
////////////////////////////////////////

int vetor[10]; 
int i; 

////////////////////////////////////////
// fun��o principal de execu��o do programa 
////////////////////////////////////////

int main(){
	// mandar o usu�rio preencher o vetor
	for (i=0 ; i<10 ; i++) {
		printf("digite o valor da posi��o %d do vetor: ", i);
		scanf("%d", &vetor[i]);
	}
	
	//imprimir o vetor na tela
	for (i=0; i<10; i++) {
		printf("vetor[%d] = %d\n", i, vetor[i]);
	}
}
