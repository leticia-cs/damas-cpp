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
char pecas[3] = "OX";
char casas[3] = "-=";

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
	int cor, corAdver;

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

	cor == 1 ? corAdver = 0 : corAdver = 1;

	// pecas adv.
	for(int i = 0; i < MAX-5; i++){
		for(int j = 0; j < MAX; j++){
			if(tabuleiro[i][j] == casas[cor]){
				tabuleiro[i][j] = pecas[corAdver];
			}
			
		}
	}
}

// void perguntaPeca(){
// 	int xOrigin, yOrigin, xDest, yDest;

// 	printf("\nDigite coord. de peca a mover.");
// 	printf("\nEixo X (horiz.): ");
// 	scanf("%i", &xOrigin);
// 	printf("\nEixo Y (vert.): ");
// 	scanf("%i", &yOrigin);

// 	printf("\nDigite coord. do destino da peca.");
// 	printf("\nEixo X (horiz.): ");
// 	scanf("%i", &xDest);
// 	printf("\nEixo Y (vert.): ");
// 	scanf("%i", &yDest);
// }

void movePeca(int corPeca){
	int xOrigin, yOrigin, xDest, yDest, corAdver;
	char peca;

	bool podeMover = false;
	bool podeMoverEsquerda = false;
	bool podeMoverDireita = false;
	bool podeComer = false;

	// OK | input digita coord originais
	// verificar se movimento valido (range 0-MAX; peça da cor de quem esta jogando)
	// OK | a partir da origem, retorna movimentos possíveis (ex: esq, dir)
	// comer peça é obrigatorio, mas pede confirmação para prosseguir.
	
	while (podeMover == false){

		printf("\nDigite coord. de peca a mover.");

		do {
			printf("\nEixo X (horiz.): ");
			scanf("%i", &xOrigin);
		} while (xOrigin < 1 || xOrigin > MAX);

		printf("\nX OK");

		do {
			printf("\nEixo Y (vert.): ");
			scanf("%i", &yOrigin);
		} while (yOrigin < 1 || yOrigin > MAX);

		printf("\nY OK");

		// ajuste para lidar com array
		xOrigin -= 1;
		yOrigin -= 1;
		

		// VERIFICA MOVIMENTOS POSSIVEIS

		corPeca == 1 ? corAdver = 0 : corAdver = 1;

		for (int i = xOrigin-1; i <= xOrigin+2; i++){
			if (tabuleiro[yOrigin+1][i] == casas[0]){
				if (i < xOrigin){
					podeMoverEsquerda = true;
				}
				if (i > xOrigin){
					podeMoverDireita = true;
				}
			} else if (tabuleiro[yOrigin+1][i] == pecas[corAdver]){
				podeComer = true;
				yDest = yOrigin + 1;
				xDest = i;
			} else {
				podeMover = false;
				printf("\nNao ha movimentos possiveis para essa peca. Tente outra.\n");
				// system("clear");
				imprimeTabuleiro();
			}

		}
	}
	

	// PEDE ESCOLHER DESTINO
	if(podeMoverEsquerda) {
		printf("\nPode mover para Esquerda.");
	} else if (podeMoverDireita) {
		printf("\nPode mover para Direita.");
	} else if (podeMoverDireita && podeMoverEsquerda) {
		printf("\nPode mover tanto para Esquerda quanto para Direita.");
	}

	// IF MOVIMENTO PERMITIDO

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

int mostrarMenu(){
	int opcao;

	while(1){
		system("clear");
		printf("MENU");
		printf("\n1- novo jogo\n0- sair\n");
		printf("\nDigite opcao: ");
		scanf("%i", &opcao);

		if (opcao < 0 || opcao > 1){
			printf("\nOpcao invalida! Digite novamente.\n");
		} else if (opcao == 0) {
			int confirma;
			printf("\nDeseja realmente sair? (1 confirma, 0 cancela)\n");
			scanf("%i", &confirma);
			if (confirma == 1){break;}
		} else {break;}
	}

	return opcao;
}