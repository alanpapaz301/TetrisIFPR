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
void mark(char matrix[ROWS][COLUMNS],int row,int col,char symbol){
    matrix[row][col] = symbol;
    
}
void FullRow(char matrix[ROWS][COLUMNS],int row,int col,char symbol){
    int j,i,cont,n;
       
    for(i=ROWS; i>1; i--){
        cont = 0;   
        for(j=1; j<COLUMNS - 2; j++){
            if(matrix[i][j]==symbol)cont++;
            
        }
        if(cont >= COLUMNS - 3){    
            for(n = 1; n<COLUMNS -2; n++){
            matrix[i][n] = ' ';
            }
        }
    }   
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