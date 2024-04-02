#include <stdio.h>
#include <stdlib.h>

/* seu corpo suado 
e voc� por cima de mim 
Quando eu te encontrar 
� sequ�ncia de lovezinho*/

//declara��o de constantes

const int MODULO = 3;

//declara��o do no 

struct no {
	int numero;
	struct no *proximo;
};

//declara��o do no diretor 

struct diretor {
	int resto;
	struct no *proximoNo;
	struct diretor *proximoDiretor;
};

//fun��o que procura por um no diretor

struct diretor *procurarDiretor(struct diretor *cabeca, int resto) {
	//declara��o de vari�veis
	struct diretor *ponteiro = cabeca;
	
	//procura do diretor cujo resto seja igual ao parametro
	while (ponteiro != NULL) {
		if (ponteiro -> resto == resto) {
			break;
		}
		ponteiro = ponteiro -> proximoDiretor;
	}
	
	return ponteiro;
}

//fun��o que inclui um no na matriz 

struct diretor *inserir(struct diretor *cabeca, int numero) {
	//declara��o do ponteiro para o diretor correto
	struct diretor *ponteiroDiretor = procurarDiretor(cabeca, numero % MODULO);
	
	if (ponteiroDiretor == NULL){
	ponteiroDiretor = (struct diretor *) malloc(sizeof(struct diretor));
	ponteiroDiretor -> resto = (numero % MODULO);
	ponteiroDiretor -> proximoNo = NULL;
	ponteiroDiretor -> proximoDiretor = cabeca;
	cabeca = ponteiroDiretor;
}
	
	//cria��o do novo no 
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = ponteiroDiretor -> proximoNo;
	ponteiroDiretor -> proximoNo = novoNo;
	
	return cabeca;
}

//fun��o que imprime a matriz esparsa

void imprimir(struct diretor *cabeca) {
	struct diretor *ponteiroDiretor = cabeca;
	while (ponteiroDiretor != NULL) {
		struct no *ponteiroNo = ponteiroDiretor -> proximoNo;
	
	printf("%d:\t", ponteiroDiretor -> resto);
	while (ponteiroNo != NULL) {
		printf("%d, ", ponteiroNo -> numero); 
		
		ponteiroNo = ponteiroNo -> proximo;
	}
	printf("\n");
	
	ponteiroDiretor = ponteiroDiretor -> proximoDiretor;
}
}

//fun��o que remove um no da matriz 

void remover(struct diretor *cabeca, int numero) {
	//declara��o do ponteiro para o diretor correto
	struct diretor *ponteiroDiretor = procurarDiretor(cabeca, numero % MODULO);
	
	//n�o foi encontrado diretor
	if (ponteiroDiretor == NULL) {
		return;
	}
	
	//foi encontrado diretor
	struct no *ponteiroNo = ponteiroDiretor -> proximoNo;
	
	//excluir primeiro no da lista
	if (ponteiroNo -> numero == numero) {
		ponteiroDiretor -> proximoNo = ponteiroNo -> proximo;
		free(ponteiroNo);
		return;
	}
	
	//excluir um no no meio da lista
	while (((ponteiroNo -> proximo != NULL) &&
	ponteiroNo -> proximo -> numero != numero)) {
		ponteiroNo = ponteiroNo -> proximo;
	}
	if (ponteiroNo -> proximo != NULL) {
		struct no *temp = ponteiroNo -> proximo;
		ponteiroNo -> proximo = ponteiroNo -> proximo -> proximo;
		free(temp);
	}
}

//fun��o principal de execu��o do programa

int main() {
	struct diretor *cabeca = NULL;
	int i =0;
	
	for (i=0; i<20; i++) {
		cabeca = inserir(cabeca, i);
	}
	imprimir(cabeca);
	
	for (i=0; i<20; i++) {
		remover(cabeca, i);
	}
	
	imprimir(cabeca);
}

