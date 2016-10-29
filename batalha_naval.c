/*FAETERJ-Rio
  Algoritmos e Linguagens de Programação I - 2016/1
  Professor Leonardo Vianna - Turma A - Manhã
  Aluno: Leonardo Damasceno
  Trabalho III - Batalha Naval
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h> //habilita limpeza do buffer de teclado no linux
#define L 15
#define C 15
#define TRUE 1
#define FALSE 0

void zerarMatriz(char m[L][C]);
void exibeMatriz(char m[L][C]);
void montaTabuleiro (char m[L][C]);
void recebeValores(char m[L][C], int tam, char nav);
int inserirPeca(char m[L][C], int posLinha, int posCol, int dir, int tam, char nav);
int confereJogo(char m[L][C]);
int atirar(char m[L][C]);
void exibirJogo(char m[L][C]);


int main() {
	char m1[L][C], m2[L][C];
	int i = 0;


	//zerando as matrizes com água
	zerarMatriz(m1);
	zerarMatriz(m2);

	//MONTAGEM DOS TABULEIROS
	exibeMatriz(m1);
	printf("\n\n=================== PLAYER 1: ====================\n\n");
	montaTabuleiro(m1);

	exibeMatriz(m2);
	printf("\n\n=================== PLAYER 2: ====================\n\n");
	montaTabuleiro(m2);

	printf("\n\n========== TUDO PRONTO! VAMOS AO JOGO! ===========\n\n");

	do {
		i++;
		printf("%s\n", ((i % 2) == 0)? "\n--------- PLAYER 2 --------\n": "\n--------- PLAYER 1 --------\n");

		do {
			exibirJogo(((i % 2) == 0)? m1: m2);
			printf("\nPREPARAR CANHÕES!!!\n");

		} while(atirar(((i % 2) == 0)? m1: m2) == TRUE);

	} while(confereJogo(m1) == FALSE && confereJogo(m2) == FALSE);

	if(confereJogo(m2) == TRUE) {
		printf("\n============================================================\n");
		printf("PARABÉNS!!! Player 1 é o vencedor e MASSACROU o player 2!!!!");
		printf("\n============================================================\n\n");
	}
	else {	
		printf("\n============================================================\n");
		printf("PARABÉNS!!! Player 2 é o vencedor e MASSACROU o player 1!!!!");
		printf("\n============================================================\n\n");
	}

	return 0;
} 


//ZERA A MATRIZ COM AGUA
void zerarMatriz(char m[L][C]) {
	int i, j;

	//zerando tudo com 'a'
	for(i=0; i<L; i++) {
		for(j=0; j<C; j++) {
			m[i][j] = 'a';
		}
	}
}

//EXIBE A MATRIZ
void exibeMatriz(char m[L][C]){
	int i, j;
	char v[L];

	printf("\n\t     ");

	//preenche vetor com as letras do indice
	for(i=0; i<L; i++) {
		v[i] = (char) 'A' + i;

		//ao mesmo tempo que preenche as letras printa os numeros do indice
		if(i >= 8) {
			printf("%d ", i+1);
		}
		else {
			printf("%d  ", i+1); //só altera o espaço entre os valores com 2 casas decimais
		}
	}

	printf("\n");

	for(i=0; i<L; i++) {
		printf("\t(%c)  ", v[i]);
		for(j=0; j<C; j++) {
			printf("%c  ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//CONSTROI TABULEIRO
void montaTabuleiro(char m[L][C]) {
	int i;

	printf("Posicionar Porta Aviões (5 casas): \n");
	recebeValores(m, 5, 'P');
	exibeMatriz(m);

	printf("Posicionar Cruzador (4 casas): \n");
	recebeValores(m, 4, 'C');
	exibeMatriz(m);

	for(i=0; i<2; i++) {
		printf("Posicionar %dº Contra-Torpedeiro (3 casas): \n", i + 1);
		recebeValores(m, 3, 'T');
		exibeMatriz(m);
	}

	for(i=0; i<2; i++) {
		printf("Posicionar %dª Rebocador (2 casas): \n", i + 1);
		recebeValores(m, 2, 'R');
		exibeMatriz(m);
	}

	for(i=0; i<4; i++) {
		printf("Posicionar %dª Submarino: (1 casa): \n", i + 1);
		recebeValores(m, 1, 'S');
		exibeMatriz(m);
	}
}

//RECEBE OS VALORES
void recebeValores(char m[L][C], int tam, char nav) {	
	char linha, dir;
	int coluna;

	do {
		__fpurge(stdin); //limpando buffer de teclado no linux
		fflush(stdin);	 //limpando buffer de teclado no windows

		printf("Linha: ");
		scanf("%c", &linha);

		printf("Coluna: ");
		scanf("%d", &coluna);
		
		__fpurge(stdin); //limpando buffer de teclado no linux
		fflush(stdin);   //limpando buffer de teclado no windows

		if(tam > 1) {
			printf("Direção (h ou v): ");
			scanf("%c", &dir);
		}

	} while(inserirPeca(m, linha, coluna -1, dir, tam, nav) == FALSE);

}

//INSERI AS PEÇAS
int inserirPeca(char m[L][C], int posLinha, int posCol, int dir, int tam, char nav){
	int i;
	int iPosLinha;

	//passando caracter para inteiro
	iPosLinha = (int) posLinha - 97; //97 = 'a' em ascii

	switch(dir) {
		case 'h':
			if((posCol + tam) <= C) {  		//confere se a peça cabe nos limites da matriz
				for(i = 0; i < tam; i++) {  //confere se já existe um navio na posição inserida
					if(m[iPosLinha][posCol + i] != 'a') {
						printf("\n\nJá existe um navio posicionado aí! Tente outra posição.\n\n");
						return FALSE;
					}
				}

				for(i = 0; i < tam; i++) {  //faz a inserção
					m[iPosLinha][posCol + i] = nav;
				}

				return TRUE;
			}
			else {
				printf("\n\nA peça ficou fora dos limites do tabuleiro. Por favor tente outra posição.\n\n");
				return FALSE;
			}

		case 'v':
			if((iPosLinha + tam) <= L) {
				for(i = 0; i < tam; i++) {
					if(m[iPosLinha + i][posCol] != 'a') {
						printf("\n\nJá existe um navio posicionado aí! Tente outra posição.\n\n");
						return FALSE;
					}
				}

				for(i = 0; i < tam; i++) {
					m[iPosLinha + i][posCol] = nav;			
				}

				return TRUE;
			}
			else {
				printf("\n\nA peça ficou fora dos limites do tabuleiro. Por favor tente outra posição.\n\n");
				return FALSE;
			}

		default:
			printf("\n\nDireção Inválida! Tente novamente.\n\n");
			return FALSE;
	}

}

//CONFERE SE O JOGO TERMINOU
int confereJogo(char m[L][C]) {
	int i, j;

	for(i=0; i<L; i++) {
		for(j=0; j<C; j++) {
			if(m[i][j] != 'a' && m[i][j] != 'X' && m[i][j] != 'A') {
				return FALSE;
			}
		}
	}

	return TRUE;
}

//EXECUTA A JOGADA
int atirar(char m[L][C]) {
	int iLinha, coluna;
	char linha;

	__fpurge(stdin); 	 //limpando buffer de teclado no linux
		fflush(stdin);	 //limpando buffer de teclado no windows

	printf("\nLinha: ");
	scanf("%c", &linha);
	iLinha = (int) linha - 97;

	__fpurge(stdin); 	 //limpando buffer de teclado no linux
		fflush(stdin);	 //limpando buffer de teclado no windows

	printf("Coluna: ");
	scanf("%d", &coluna);
	coluna--;

	__fpurge(stdin); 	 //limpando buffer de teclado no linux
		fflush(stdin);	 //limpando buffer de teclado no windows

	printf("\nATIRAR!!!!! ");

	switch(m[iLinha][coluna]) {
		case 'a' : 
			printf("OOOOOH, NÃO! ÁGUA...\n");
			m[iLinha][coluna] = 'A';
			return FALSE;

		case 'X' :
			printf("Você já atirou aí, marujo... Sai do canhão!\n");
			return FALSE;

		case 'P' :
			printf("BOA, MARUJO! ACERTOU O PORTA AVIÕES!! BELO TIRO!\n");
			m[iLinha][coluna] = 'X';
			return TRUE;

		case 'C' :
			printf("BOA, MARUJO! ACERTOU UM CRUZADOR!! BELO TIRO!\n");
			m[iLinha][coluna] = 'X';
			return TRUE;

		case 'T' :
			printf("BOA, MARUJO! ACERTOU UM CONTRA-TORPEDEIRO!! BELO TIRO!\n");
			m[iLinha][coluna] = 'X';
			return TRUE;

		case 'R' :
			printf("BOA, MARUJO! ACERTOU UM REBOCADOR!! BELO TIRO!\n");
			m[iLinha][coluna] = 'X';
			return TRUE;

		case 'S' :
			printf("BOA, MARUJO! ACERTOU UM SUBMARINO!! BELO TIRO!\n");
			m[iLinha][coluna] = 'X';
			return TRUE;
	}
}

//EXIBE O JOGO SÓ COM AS CASAS JOGADAS
void exibirJogo(char m[L][C]) {
	int i, j;
	char v[L];

	printf("\n\t     ");

	//preenche vetor com as letras do indice
	for(i=0; i<L; i++) {
		v[i] = (char) 'A' + i;

		//ao mesmo tempo que preenche as letras printa os numeros do indice
		if(i >= 8) {
			printf("%d ", i+1);
		}
		else {
			printf("%d  ", i+1); //só altera o espaço entre os valores com 2 casas decimais
		}
	}

	printf("\n");

	for(i=0; i<L; i++) {
		printf("\t(%c)  ", v[i]);
		for(j=0; j<C; j++) {
			switch(m[i][j]) {
				case 'X' :
					printf("X  ");
					break;

				case 'A' :
					printf("A  ");
					break;

				default :
					printf("?  ");
					break;
			}
		}
		printf("\n");
	}
	printf("\n");
}
