#include <stdio.h>
#include <cstdlib>
#include "functions.h"

int main() {

	int option = showMenu();

	switch(option){
		case 1: // 2 PLAYERS
			printf("\nVamos Jogar\n\n");
			clearBoard();
			showBoard();
			putPiece(1);
			// coloca peca, passa a vez, repete
			break;
		default: // SAIR
			printf("\nSaindo...\n");
			system("clear");
	}
	printf("\n");
	return 0;
}