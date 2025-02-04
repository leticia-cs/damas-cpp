// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <cstdlib>

// Declarar funcoes
int showMenu();
void showBoard();
void clearBoard();
void putPiece(int turnNumber);
bool checkWin(int player);

#endif // FUNCTIONS_H