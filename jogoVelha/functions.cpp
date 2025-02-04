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
#include <cmath>

#define MAX 3

char board[3][3];
char pieces[3] = "XO";

// OPERATIONAL

void clearBoard(){
	for (int i = 0; i < MAX; i++){
		for (int j = 0; j < MAX; j++){
			board[i][j] = ' ';
		}
	}
}

void showBoard(){
	printf("\n");
	for (int i = 0; i < MAX; i++){
		for (int j = 0; j < MAX; j++){
			j == 1 ? printf("| %c |", board[i][j]) : printf(" %c ", board[i][j]);
		}

		if (i != 2){
			printf("\n-----------\n");
		}
	}
	printf("\n");
	printf("\n");
}

bool checkWin(int player){
	for (int i = 0; i<MAX; i++){
		for (int j = 0; j < MAX; j++){

			// colunas
			if(board[0][j] == pieces[player] && board[1][j] == pieces[player] &&board[2][j] == pieces[player]){
				return true;
			}
			// linhas
			if(board[i][0] == pieces[player] && board[i][1] == pieces[player] &&board[i][2] == pieces[player]){
				return true;
			}
			// diagonal principal
			if(board[0][0] == pieces[player] && board[1][1] == pieces[player] &&board[2][2] == pieces[player]){
				return true;
			}
			// diagonal reversa
			if(board[2][0] == pieces[player] && board[1][1] == pieces[player] &&board[0][2] == pieces[player]){
				return true;
			}
		}
	}

	return false;
}

int showMenu(){
	int option, confirm;

	system("clear");

	printf("JOGO DA VELHA");
	printf("\n\n1-Multiplayer\n0-SAIR");
	printf("\n\nDigite sua escolha: ");
	scanf("%i", &option);

	if (option < 0 || option > 1) {
		return showMenu();
	}

	if (option == 0) {
		printf("\nDeseja realmente sair? (1-SIM; 0-NAO)\n");
		scanf("%i", &confirm);

		if (confirm == 1) {
			return option;
		} else {
			return showMenu();
		}
	}

	return option;
}

void putPiece(int turnNumber){
	// anuncia vez
	int player = (turnNumber%2) + 1;
	char piece = pieces[player-1];

	system("clear");
	printf("\nRODADA No: %i", turnNumber);
	printf("\nVEZ DE: Jogador %i.\n", player);

	showBoard();

	// seleciona onde colocar
	float coordinates;
	printf("\nDigite as coordenadas (x.y) para colocar: ");
    scanf("%f", &coordinates);
    int xCoord = (int) floor(coordinates);
    int yCoord = (int) ((coordinates - xCoord) * 10);

    // coloca
    if (board[yCoord][xCoord] == ' '){
    	board[yCoord][xCoord] = piece;
    } else {
    	printf("\nPosicao invalida!");
    	putPiece(turnNumber);
    }

	// vê se ganhou. se não, passa a vez e continua.
	if (checkWin(player-1)){
		showBoard();
		printf("\nJOGADOR No %i VENCEU! PARABENS", player);
	} else {
		turnNumber++;
		putPiece(turnNumber);
	}

	
}

// TABULEIRO

//    |   |  
// -----------
//    |   |  
// -----------
//    |   |  
