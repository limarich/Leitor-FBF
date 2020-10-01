#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
int replace(char* source, size_t sourceSize, char* substring, char* with) { // STR_ORIGEM, TAM_ORIGEM, SUBSTR, STRTROCA
	char* substring_source = strstr(source, substring); // VERIFICA A OCORRENCIA DE SUBSTRING
	if(substring_source == NULL) {
		return 0; // SEM OCORRENCIA
	}
	
	if(sourceSize < strlen(source) + (strlen(with) - strlen(substring) + 1)) {
		printf("\nTamanho insuficiente\n");
		return 0; // TAMANHO INSUFICIENTE, NAO SERA PRECISO ALOCAR MEMORIA
	}
	memmove( // COPIA N ELEMENTOS DE UMA STR PARA OUTRA, SOBRESCREVENDO OS ELEMENTOS, MOVIMENTA OS ELEMENTOS A FRENTE
	substring_source + strlen(with), //LOCAL ONDE OS ELEMENTOS VAO
	substring_source+strlen(substring), //A FONTE DOS DADOS COPIADOS
	strlen(substring_source) - strlen(substring) +1 // BYTES A SEREM COPIADOS
	);
	//FICARÁ UM ESPAÇO LIVRE, NESSE ESPAÇO ONDE A SUBSTITUIÇÃO ENTRA
	memcpy(substring_source, with, strlen(with));//COPIA N ELEMENTOS PARA UM LOCAL DE DESTINO
	return 1;
}
int main() {
	int i;
	char str[100] = "\0";
	char temp[2] = "";
	char temp2[2] = "";
	printf("\nEntre com sua FBF\n");
	scanf("%[^\n]", str);
	for(i = 0; str[i]; i++) {
		if(str[i] >= 'A' && str[i] <= 'Z') {
			printf("\nValor de %c\n", str[i]);
			setbuf(stdin,NULL);
			temp[0] = str[i];
			setbuf(stdin,NULL);
			scanf("%s", temp2);
			while(replace(str,100,temp,temp2));
		}
	}
	printf("Apos a mudanca de valores voce tem: \t%s\n", str);
	return 0;
}
