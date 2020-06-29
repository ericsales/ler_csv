#include "csv.h"

int converte(char *caminho, int n_caminho){
	//Inicializaçoes
	int i = 0, j = 0;		//Contadores de laço
	int indiceUltimoCaractere;	//Armazena a posicao do ultimo caracter da string
	int contCols = 0;		//Contador de laço
	char linha[2048];		//Buffer da linha


	//Abertura de aquivos
	FILE *arquivo_csv = fopen(caminho, "r");	//Arquivo CSV
	FILE *arquivo_sql = fopen("dados.sql", "w");	//Arquivo SQL

	//Verificar abertura de arquivo_csv
	if(arquivo_csv == NULL || arquivo_sql == NULL){
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

	//Armazenhando a primeira linha que contem o nome das colunas
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

	//Gravando dados no arquivo	
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
