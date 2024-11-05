#include "header.h"

int round_game = 1;

int main() {
    char **arr;

    arr = (char **)malloc( ROW_COLUMN * sizeof(char*));
    
    for ( i = 0; i < ROW_COLUMN; i++ ) {
        arr[i] = (char*)malloc(ROW_COLUMN * sizeof(char));
    }
    
    game( arr );
    
    free(arr);
    
    return 0;
}

void game( char **ptr ) {
    read_name();

    while ( round_game <= ROW_COLUMN ) { 

        for ( i = 0; i < ROW_COLUMN; i++ ) 
            for ( j = 0; j < ROW_COLUMN; j++ )
                ptr[i][j] = ' ';

        count = 0;

        while ( 1 ) {
            user_one( ptr );
            if ( validate_game( ptr ) == 1 ) {
                print_titele();
                printf("\033[1;37mRound = %d\033[0m\n\n", round_game );
                print_game( ptr );
                print_line();
                printf("\033[1;32mWinner at round %d: %s\033[0m\n", round_game, player1);
                pla_1_won++;
                round_game++;
                print_line();
                continue_key();
                break;
            }
            count++;
            if ( count == 9 ) {
                print_titele();
                printf("\033[1;37mRound = %d\033[0m\n\n", round_game );
                print_game( ptr );
                print_line();
                printf("\033[1;32m\t   GAME OVER\033[0m\n");
                round_game++;
                print_line();
                continue_key();
                break;
            }
            user_two( ptr );
            if ( validate_game( ptr ) == 2 ) {
                print_titele();
                printf("\033[1;37mRound = %d\033[0m\n\n", round_game );
                print_game( ptr );
                print_line();
                printf("\033[1;32mWinner at round %d: %s\033[0m\n", round_game, player2);
                pla_2_won++;
                round_game++;
                print_line();
                continue_key();
                break;
            }
            count++;
        }
    }
    print_titele();
    printf("Score:\n\n%-17s : %d\n%-17s : %d\n", player1, pla_1_won, player2, pla_2_won );
    if ( pla_1_won > pla_2_won ) {
        print_line();
        printf("\033[1;32m%-17s: %s\033[0m\n", "Winner", player1);
        print_line();
    } else if ( pla_1_won < pla_2_won ) {
        print_line();
        printf("\033[1;32m%-17s: %s\033[0m\n", "Winner", player1);
        print_line();
    } else {
        print_line();
        printf("\033[1;32m\t\tTie\033[0m\n");
        print_line();
    }
}