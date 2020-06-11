#include <stdio.h>
#include <stdlib.h>

//Funçoes


int main(){
	//Inicialização
//	FILE *arquivo_csv = fopen("/home/ericsales/Downloads/teste.csv", "r");	//abrindo o aquivo
	char linha[8048];							//Vetor que armazenara a linha do aquivo
	int i = 0, j = 0;							//Contador de laço
	FILE *arquivo_csv = fopen("/media/ericsales/Acer/Users/eric-/OneDrive/Área de Trabalho/Sally/IBC-SPSS/DADOS/DM_ALUNO.CSV", "r");	
	FILE *arquivo_sql = fopen("teste.sql", "w");
	
	//Verificar abertura de arquivo_csv
	if(arquivo_csv == NULL || arquivo_sql == NULL)
	{
		printf("Arquivo não encontrado\n");
		return 1;
	}

	/*
	while(fgets(linha, sizeof(linha), arquivo_csv) != NULL){
		//fscanf(aquivo, "%c", vet[i])
		printf("%s", linha);
		i++;
	}
	*/

	//lendo a primeira linha do arquivo_csv
	fgets(linha, sizeof(linha), arquivo_csv);
	
	//Armazenhando
	while(linha[j] != '\0'){
		if(linha[j] != '|'){
			printf("%c", linha[j]);
		}else{
			printf("\n");
		}
		j++;
	}
	j = 0;


	while(i <= 3){
		//leitura das linhas do arquivo_csv
		fgets(linha, sizeof(linha), arquivo_csv);
		
		//Armazenhando
		printf("INSERT INTO IC (CAMPOS)VALUES("VALORES")");
		while(linha[j] != '\0'){
			if(linha[j] != '|'){
				printf("%c", linha[j]);
			}else{
				printf("\n");
			}
			j++;
		}
		j = 0;	//Zerando contador

		i++;
	}

	//fechando aquivo
	fclose(arquivo_csv);
	fclose(arquivo_sql);	

	return 0;
}
