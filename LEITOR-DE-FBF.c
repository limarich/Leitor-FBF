/*FEITO POR: Richard Lima Ribeiro*/
// INICIANDO A MAIN
#include<stdio.h>
int main() {
	int is_number(char*);
	int is_alfa(char*);
	int is_ordened(char*);
	int parentheses(char*);
	int cont_parentheses(char*);
	int func2(char*, int);
	int func2(char*, int);
	int op;
	char str[101] = "\0";
			printf("\nALGUMAS REGRAS:\n");
			printf("\n-->Use apenas letras MAIUSCULAS para as proposicoes (A ate Z)\n");
			printf("\n-->Para o valor OU use 'v'\n\n-->Para o valor E use '^'\n");
			printf("\n-->Use '->' para IMPLICACAO\n\n-->Use '<>' para BI-IMPLICACAO\n");
			printf("\n-->Use '!' para NEGACAO\n");
			printf("\n-->Use '1' para VERDADEIRO\n\n-->Use '0' para FALSO\n");
			printf("\n-->O uso de PARENTESES eh opcional\n");
			printf("\n-->CASO O TESTE TERMINE EM '^' APERTE ESPACO E DEPOIS ENTER PARA EVITAR ERRO!\n");
			printf("\n-->CASO CONTRARIO: NAO use a BARRA DE ESPACO\n");
			printf("\n\n-->EM CASO DE ERROS CONSTANTES, EXPERIMENTE REINICIAR O PROGRAMA\n\n");
			system("pause");
			system("cls");
	do {
			printf("\t\tSelecione uma acao:\n\n(1) para verificar uma fbf\n(0)Para finalizar\n");
			scanf("%d", &op);
			if(op) {
				printf("\nEscreva sua sentenca:\n");
				setbuf(stdin, NULL);
				scanf("%[^\n]", str);
				setbuf(stdin, NULL);
				if(!(is_alfa(str))) {
					printf("\nErro, caracter invalido detectado\n");
				}else {
					if(!is_ordened(str)) {
						printf("\nErro, escrita incorreta\n");
					}
					else{
						printf("\nIsso eh uma fbf\n");
					}
				}
			}
			system("pause");
			system("cls");
	} while(op);
	printf("\nFim de execucao\nFeito por: RICHARD LIMA RIBEIRO\n");
	return 0;
}
//VERIFICADOR DE NUMEROS
int is_number(char*str) {
	int i;
	for(i = 0; str[i]; i++) {
		if(str[i] >= '2' && str[i] <= '9') return 0;
	}
	return 1;
}
//VERIFICADOR DE ALFABETO
int is_alfa(char*str) {
	int i;
	if(!is_number(str)) return 0;
	for(i = 0; str[i]; i++) {
		if(!(str[i] == '^' || str[i] == 'v' || str[i] == '!' || str[i] == '1'|| str[i] == '0'|| str[i] == '('|| str[i] == ')')) {
			if(!(str[i] >= 'A' && str[i] <= 'Z')) {
				if(!(str[i]=='-' && str[++i] == '>')) {
					if(!(str[i] == '<' && str[++i] == '>')) {
						if(str[i] >= 'a' && str[++i] <= 'z') {
							if(!(str[i] == 'v'))
								return 0; 
						}
					}
				}
			}
		}
	}
	return 1;
}
//VERIFICA A ORDENAÇÃO DOS ELEMENTOS
int is_ordened(char*str) {
	int i;
	for(i = 0; str[i]; i++) {
		//EM CASO DE SEQUENCIA 
		if(((str[i] >= 'A' && str[i] <= 'Z') || (str[i] == '1' || str[i] == '0'))&&(str[++i] >= 'A' && str[i] <= 'Z') || (str[i] == '1' || str[i] == '0')) return 0;
		if(str[i] == '!') { // NEGAÇÃO
			if(!func(str, i))return 0;			  		   	   
		}
		else if(str[i] == '^' || str[i] == 'v') { // E/OU
			if(!((str[i-1] >= 'A' && str[i-1] <= 'Z') || (str[i-1] >= '0' && str[i-1] <= '1') || (str[i-1] == ')'))) {
				return 0;
			}
			else {
				if(!((str[++i] >= 'A' && str[i] <= 'Z') || (str[i] == '!') || (str[i] >= '0' && str[i] <= '1') || (str[i] == '('))) {
					return 0;
				}
				else {
					if(str[i] == '(') {
						if(!parentheses(str)) return 0;
					}
					if(str[i] == '!') { // NEGAÇÃO
						if(!func(str, i))return 0;	
					}
				}
			}
		}
		else if(str[i] == '-' && str[++i] == '>') { // IMPLICAÇÃO
		if(!func2(str, i)) return 0;	
		}
		else if(str[i] == '<' && str[++i] == '>') { // BI-IMPLICAÇÃO
			if(!func2(str, i)) return 0;
		}
		else if(str[i] == '(' || str[i] == ')') { // PARENTESES
			if(!parentheses(str)) return 0;
		}
	}
	return 1;
}
//VERIFICA SE OS PARENTESES ESTÃO CORRETOS
int parentheses(char*str) {
	int i;
	if(cont_parentheses(str)) return 0;
	else {
		for(i = 0; str[i]; i++) {
			if(str[i] == ')' && str[++i] == '(') { // )(
				return 0;
			}
			if(str[i] == '(' && str[++i] == ')') { // ()
				return 0;
			}
		}
	}
	return 1;
}
int cont_parentheses(char*str) {
	int i, c1 = 0,c2 = 0;
	for(i = 0; str[i]; i++) {
		if(str[i] == '(') c1++;
		if(str[i] == ')') c2++;
	}
	return(c1-c2); // SE A QTD FOR IGUAL RETORNA 0 
}
int func(char*str, int i) { // FUNÇÃO RESPONSÁVEL PELA NEGAÇÃO
	if(!((str[++i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '1'))) {
						  if(!(str[i] == '(')) {
						  			  return 0;
						  }
						  else {
						  	if(!parentheses(str)) return 0;
						  }
			}
	return 1;
}
int func2(char*str, int i) { // FUNÇÃO RESPNSÁVEL PELA IMPLICAÇÃO/BI-IMPLICAÇÃO
	if(!((str[i-2] >= 'A' && str[i-2] <= 'Z') || str[i-2] == ')' || (str[i-2] == '1' || str[i-2] == '0'))) {
				return 0;
			}
			else {
				if(str[i+1] == '\0') return 0;
				if(!((str[++i] >= 'A' && str[i] <= 'Z') || (str[i] == '(') || str[i] == '!' || str[i] == '0' || str[i] == '1')) {
					return 0;
				}
				else {
					if(str[i] == '(') {
						if(!parentheses(str)) return 0;
					}
					if(str[i] == '!') { // NEGAÇÃO DNV
							  if(!func(str, i))return 0;			  		   	   
							  }
				}
			}
	return 1;
}
