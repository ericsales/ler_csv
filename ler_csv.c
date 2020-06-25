#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funçoes


int main(){
	//Inicialização
	char linha[4048], caminho[200];					//Vetor que armazenara a linha do aquivo
	int i = 0, j = 0, indiceUltimoCaractere, contCols = 0;		//Contador de laço
	
	//Entrada de dados
	printf("Insira o caminho do aquivo csv: ");
	scanf("%s", caminho);
	
	FILE *arquivo_csv = fopen("/media/ericsales/Acer/Users/eric-/OneDrive/Área de Trabalho/Sally/IBC-SPSS/DADOS/DM_ALUNO.CSV", "r");	
	FILE *arquivo_sql = fopen("teste.sql", "w");
	
	//Verificar abertura de arquivo_csv
	if(arquivo_csv == NULL || arquivo_sql == NULL)
	{
		printf("Arquivo não encontrado\n");
		return 1;
	}

	//lendo a primeira linha do arquivo_csv
	fgets(linha, sizeof(linha), arquivo_csv);

	//Retirando \n do final da string	
	indiceUltimoCaractere = strlen(linha) - 1;
	if(linha[indiceUltimoCaractere] == '\n'){
		linha[indiceUltimoCaractere - 1] = ';';
	}

	//Armazenhando
	fprintf(arquivo_sql, "INSERT INTO IC (\'");
	while(linha[j] != '\0'){
			if(linha[j] != '|' && linha[j] != ';'){
				fprintf(arquivo_sql, "%c", linha[j]);
			}else{ 
				if(linha[j] != ';'){
					fprintf(arquivo_sql, "\', \'");
					contCols++;
				}else{
					fprintf(arquivo_sql, "\')");
					contCols++;
				}
			}
			j++;
	}
	j = 0;

	printf("NUMERO DE COLUNAS: %d\n", contCols);

	
	while(fgets(linha, sizeof(linha), arquivo_csv) != NULL){
		//leitura das linhas do arquivo_csv
		fgets(linha, sizeof(linha), arquivo_csv);

		//
		int indiceUltimoCaractere = strlen(linha) - 1;
		if(linha[indiceUltimoCaractere] == '\n'){
			linha[indiceUltimoCaractere - 1] = ';';
		}

		//Armazenhando
		fprintf(arquivo_sql, "VALUES(\'");
		while(linha[j] != '\0'){
			if(linha[j] != '|' && linha[j] != ';'){
				fprintf(arquivo_sql, "%c", linha[j]);
			}else{ 
				if(linha[j] != ';'){
					fprintf(arquivo_sql, "\', \'");
				}else{
					fprintf(arquivo_sql, "\')");
				}
			}
			j++;
		}
		j = 0;	//Zerando contador
	}
	
	//fechando aquivo
	fclose(arquivo_csv);
	fclose(arquivo_sql);	

	return 0;
}
