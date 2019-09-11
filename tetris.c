/*
    Jogo interativo Tetris implementado em linguagem C para uso 
    no console (terminal de comandos)

    Autor: Augusto Luengo Pereira Nunes
    Data: 28/08/2019

*/

#include "tetris.h"

/*
    Inicializa a matriz principal com 'espaços vazios'
*/
void init(char matrix[ROWS][COLUMNS]){
    int i,j;

    for(i=0; i<ROWS; i++){
        
        for(j=0; j<COLUMNS; j++){
            matrix[i][j] = ' ';
           matrix[i][0] = '*';
           matrix[0][j] = '*';
            matrix[ROWS-1][j] = '*';
            matrix[i][COLUMNS-1] = '*';
        }
    }
}
void mark(char matrix[ROWS][COLUMNS],int row,int col){
    matrix[row][col] = '@';
}
/*
    Mostra o conteúdo da matriz principal na tela 
    do computador.
*/
void printMatrix(char matrix[ROWS][COLUMNS]){
    int i,j;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            printf("%c", matrix[i][j]);
        }

        printf("\n");
    }
}