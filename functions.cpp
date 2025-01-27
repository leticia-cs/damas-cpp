// FAZER:
// [ O ] imprimir tabuleiro vazio
// [ O ] colocar pecas no tabuleiro
// [ - ] mover uma peça

// RODAR LINUX:
// $ g++ arquivo.cpp -o compilado
// $ ./compilado

// --------------------------------------


#include <stdio.h>
#include <cstdlib>

#define MAX 8

// 0 = preto; 1 = branco;
char pecas[3] = "BW";
char casas[3] = "bw";

bool troca = false;
char tabuleiroLimpo[MAX][MAX];
char tabuleiro[MAX][MAX];

// --------------------------------------

// FUNCIONAIS

void esvaziarTabuleiro(){
	// preencher Limpo
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			troca = !troca;

			tabuleiroLimpo[i][j] = casas[troca];
			
		}
		troca = !troca;
	}

	// adicionar para atual
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			tabuleiro[i][j] = tabuleiroLimpo[i][j];
		}
	}
}

void imprimeTabuleiro(){
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			printf("%c ", tabuleiro[i][j]);
		}
		printf("\n");
	}
}

void colocaPecas(){
	int cor;

	do {
		printf("\nQual cor quer jogar? (0 - preto, 1 - branco)\n");
		scanf("%i", &cor);
	} while (cor > 1 || cor < 0);
	

	// pecas player
	for(int i = MAX-1; i > MAX-4; i--){
		for(int j = 0; j < MAX; j++){
			if(tabuleiro[i][j] == casas[cor]){
				tabuleiro[i][j] = pecas[cor];
			}
		}
	}

	// pecas adv.
	// for(int i = 0; i < MAX-5; i++){
	// 	for(int j = 0; j < MAX; j++){
	// 		if(tabuleiro[i][j] != casas[cor]){
	// 			tabuleiro[i][j] = pecas[cor];
	// 		}
			
	// 	}
	// }
}

void movePeca(int xOrigin, int yOrigin, int xDest, int yDest){

	char peca;

	// input digita coord originais
	// verificar se movimento valido (range 0-MAX; peça da cor de quem esta jogando)
	// lidar com string obtem xOrigin e yOrigin
	// a partir da origem, retorna movimentos possíveis (ex: esq, dir)
	// comer peça é obrigatorio, mas pede confirmação para prosseguir.

	// deleta peca
	peca = tabuleiro[xOrigin][yOrigin];
	tabuleiro[xOrigin][yOrigin] = ' ';

	// coloca lugar novo
	tabuleiro[xDest][yDest] = peca;

	// arruma tabuleiro
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			if (tabuleiro[i][j] == ' '){
				tabuleiro[i][j] = tabuleiroLimpo[i][j];
			}
		}
	}

}

// INTERFACE

void mostrarMenu(){
	int opcao;

	printf("\nMENU");
	printf("\n1- novo jogo\n0- sair\n");
	printf("\nDigite opcao: ");
	scanf("%i", &opcao);

	switch(opcao){
		case 0:
			system("clear");
			break;
		case 1:
			esvaziarTabuleiro();
			colocaPecas();
			system("clear");
			imprimeTabuleiro();
			break;
		case 2:
			printf("a");
			break;
		default:
			printf("\nDigite opcao valida!");
	}
}