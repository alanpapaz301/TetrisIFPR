
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
void DownRow(char matrix[ROWS][COLUMNS]){
    int i,j;

    for(i = ROWS-2; i>1;i--){
        for(j = 1;j<COLUMNS-1;j++){
            if(i>1) matrix[i][j] = matrix[i-1][j];



        }

    }

}
int FullRow(char matrix[ROWS][COLUMNS],int row,int col,char symbol,int speedControl){
    int j,i,cont,n;
       
    for(i=ROWS; i>1; i--){
        cont = 0;   
        for(j=1; j<COLUMNS - 1; j++){
            if(matrix[i][j]==symbol)cont++;
            
        }
        if(cont >= COLUMNS - 2){  
			if(speedControl>1500)speedControl -=500;
            for(n = 1; n<COLUMNS -1; n++){
            matrix[i][n] = ' ';
            }
           DownRow(matrix);
        }
    }
	return speedControl;
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