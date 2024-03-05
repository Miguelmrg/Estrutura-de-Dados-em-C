sq/////////////////////////////////////////////////////
//programa que implementa a busca exaustiva//////////
/////////////////////////////////////////////////////

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

////////////////////////////////////////////////////
//fun��o principal de execu��o do programa//////////
////////////////////////////////////////////////////

int main(){
	//declara��o de vari�veis
	int vetor[100000];
	int i;
	int procura;
	int achei;
	
	//inicializa��o da aleatoriedade
	time_t t;
	srand(time(&t));
	
	//preenchimento do vetor
	for (i=0;i<100000;i++){
		vetor[i]=(rand() % 100000);
		
	}
	
	//definir o par�metro de pesquisa
	printf("digite o valor a ser buscado: ");
	scanf("%d", &procura);
	
	//busca exaustiva propriamente dita
	achei = -1;
	for (i=0;i<100000;i++){
		if (vetor[i] == procura){
			achei = i;
			break;
		}
	}
	
	//resposta
	if(achei==-1){
		printf("me fodi | n�o encontrei \n");
	} else {
		printf("encontrei na posi��o %d\n");
	}
}
