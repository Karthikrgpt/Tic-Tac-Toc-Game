#include "header.h"

extern int round_game;

void user_one( char **ptr ) {
    flag = 0;
    print_titele();
    printf("\033[1;37mRound = %d\033[0m\n\n", round_game );
    print_game( ptr );
    printf("Enter the Row and Column [ 0 to 2 ]:\n");
    while ( !flag ) {
        printf("%-15s : ", player1 );
        scanf("%d%d", &row1, &column1 );
        validate_data( row1, column1, ptr );
    }
    ptr[row1][column1] = symbol1;
}

void user_two( char **ptr ) {
    flag = 0;
    print_titele();
    printf("\033[1;37mRound = %d\033[0m\n\n", round_game );
    print_game( ptr );
    printf("Enter the Row and Column [ 0 to 2 ]:\n");
    while ( !flag ) {
        printf("%-15s : ", player2 );
        scanf("%d%d", &row2, &column2 );
        validate_data( row2, column2, ptr );
    }
    ptr[row2][column2] = symbol2;
}

void validate_data( int row, int column, char **ptr ) {
    if (row < 0 || row > 2 || column < 0 || column > 2) {
        if (row < 0 || row > 2)
            printf("\033[0;31mInvalid row!!\033[0m\n");
        if (column < 0 || column > 2)
            printf("\033[0;31mInvalid column!!\033[0m\n");
        flag = 0;
        return;
    }

    if (ptr[row][column] != ' ') {
        printf("\033[0;31mOops, already filled!\033[0m\n");
        flag = 0;
        return;
    }

    flag = 1;
}

int validate_game( char **ptr ) {
    for (i = 0; i < ROW_COLUMN; i++) {
        if (ptr[i][0] == symbol1 && ptr[i][1] == symbol1 && ptr[i][2] == symbol1)
            return 1;
        if (ptr[i][0] == symbol2 && ptr[i][1] == symbol2 && ptr[i][2] == symbol2)
            return 2;

        if (ptr[0][i] == symbol1 && ptr[1][i] == symbol1 && ptr[2][i] == symbol1)
            return 1;
        if (ptr[0][i] == symbol2 && ptr[1][i] == symbol2 && ptr[2][i] == symbol2)
            return 2;
    }

    if ((ptr[0][0] == symbol1 && ptr[1][1] == symbol1 && ptr[2][2] == symbol1) || (ptr[0][2] == symbol1 && ptr[1][1] == symbol1 && ptr[2][0] == symbol1))
        return 1;

    if ((ptr[0][0] == symbol2 && ptr[1][1] == symbol2 && ptr[2][2] == symbol2) || (ptr[0][2] == symbol2 && ptr[1][1] == symbol2 && ptr[2][0] == symbol2))
        return 2;

    return 0;

}

void print_titele() {
    system("clear");
    print_line();
    printf("\033[1;37m\t   TIC TAC TOC\033[0m\n");
    print_line();
}

void print_line() {
    for ( i = 0; i < 35; i++ ) {
        printf("\033[1;37m-\033[0m");
    }
    printf("\n");
}

void print_game( char **ptr ) {
    printf(" \033[0;30m\t0\t1\t2\033[0m\n\n");
    for ( i = 0; i < ROW_COLUMN; i++ ) {
        printf("\033[0;30m  %d     \033[0m", i);
        for ( j = 0; j < ROW_COLUMN; j++ ) {
            printf("%c\t", ptr[i][j] );
        }
        printf("\n\n");
    }
}

void read_name() {
    print_titele();
    printf("\nEnter the first Player name : ");
    scanf(" %[^\n]", player1 );
    flag = 0;
    while ( !flag ) {
        printf("Select your symbol 'X' or 'O' : ");
        scanf(" %c", &symbol1 );
        if (symbol1 == 'X' || symbol1 == 'x') {
            flag = 1;
            symbol1 = 'X';
        } else if (symbol1 == 'o' || symbol1 == 'O') {
            flag = 1;
            symbol1 = 'O';
        }
        else printf("\033[0;31mInvalid symbol!!!!\033[0m\n");
    }
    symbol2 = ( symbol1 == 'X' )? 'O' : 'X';
    printf("Enter the Second Player name : ");
    scanf(" %[^\n]", player2 );
    print_titele();
    printf("\n\"\033[1;32m%s\033[0m\" your symbol is \"\033[1;32m%c\033[0m\"\n", player1, symbol1 );
    printf("\"\033[1;32m%s\033[0m\" your symbol is \"\033[1;32m%c\033[0m\"\n", player2, symbol2 );
    continue_key();
}

void continue_key() {
    printf("\n\033[1;34mPress Enter Key to continue\033[0m ");
    getchar();
    getchar();
}