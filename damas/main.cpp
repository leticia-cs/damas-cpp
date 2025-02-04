#include <stdio.h>
#include <cstdlib>
#include "functions.h"

int main() {
	system("clear");

	int opcao = mostrarMenu();

	switch(opcao){
		case 1: // NOVO JOGO
			// config tabuleiro
			esvaziarTabuleiro();
			colocaPecas();
			system("clear");
			imprimeTabuleiro();
			movePeca(1);
			// move pecas, passa a vez, repete
			// escolhe peca pra mover, retorna movimentos possiveis
			// passa vez --> vezP1 = !vezP1 (P1 é boolean)
			// 
			break;
		default: // SAIR
			printf("\nSaindo...\n");
			system("clear");
	}

	return 0;
}