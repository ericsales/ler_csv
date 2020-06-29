#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"

int main(){
	//Inicialização
	char linha[4048];		//Vetor que armazenara a linha do arquivo
	char caminho[200];		//Vetor que armazenara o caminho do arquvo 
	int i = 0, j = 0;		//Contadores de laço
	int indiceUltimoCaractere;	//Armazena a posicao do ultimo caracter da string
	int contCols = 0;		//Contador de laço
	
	//Entrada de dados
	printf("Insira o caminho do aquivo csv: ");
	scanf("%s", caminho);


	return converte(caminho, 200);
}
