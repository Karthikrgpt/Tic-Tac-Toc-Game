#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW_COLUMN 3

void game( char **ptr );
void read_name() ;
void print_titele();
void print_line();
void continue_key();
void print_game( char **ptr );
void user_one( char **ptr );
void user_two( char **ptr );
int validate_game( char **ptr );
void validate_data( int row, int column, char **ptr );

static int i, j, row1, column1, row2, column2, flag, count = 0;
static int pla_1_won = 0, pla_2_won = 0;
char player1[20], player2[20], symbol1, symbol2;

#endif