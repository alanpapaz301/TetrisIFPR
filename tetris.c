
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
//Desenha e apaga bloco tipo I
void drawBlock(char matrix[ROWS][COLUMNS],char symbol,int count,Block bloco){
	if(count%2 == 0 ){
		switch(bloco.orientacao){
			case ORIENTACAO_DOWN:
            case ORIENTACAO_UP:
                if(bloco.i-3>=1) matrix[bloco.i-3][bloco.j] = symbol;
                if(bloco.i-2>=1) matrix[bloco.i-2][bloco.j] = symbol;
                if(bloco.i-1>=1) matrix[bloco.i-1][bloco.j] = symbol;
                matrix[bloco.i][bloco.j] = symbol;
                break;
			case ORIENTACAO_LEFT:
			case ORIENTACAO_RIGHT:
				if(bloco.j-3>=1) matrix[bloco.i][bloco.j-3] = symbol;
                if(bloco.j-2>=1) matrix[bloco.i][bloco.j-2] = symbol;
                if(bloco.j-1>=1) matrix[bloco.i][bloco.j-1] = symbol;
                matrix[bloco.i][bloco.j] = symbol;
		}
	}
	else{
		switch(bloco.orientacao){
            case ORIENTACAO_UP:
                if(bloco.i-3>=0) matrix[bloco.i-3][bloco.j] = ' ';
                if(bloco.i-2>=0) matrix[bloco.i-2][bloco.j] = ' ';
                if(bloco.i-1>=0) matrix[bloco.i-1][bloco.j] = ' ';
                matrix[bloco.i][bloco.j] = ' ';
                break;
			case ORIENTACAO_LEFT:
				if(bloco.j-3>=0) matrix[bloco.i][bloco.j-3] = ' ';
                if(bloco.j-2>=0) matrix[bloco.i][bloco.j-2] = ' ';
                if(bloco.j-1>=0) matrix[bloco.i][bloco.j-1] = ' ';
                matrix[bloco.i][bloco.j] = ' ';
		}
	}
}
void selectPiece(char matrix[ROWS][COLUMNS],int row,int col,char symbol,int piece){
	
	
	
	
}
void mark(char matrix[ROWS][COLUMNS],int row,int col,char symbol,Block bloco){
		if(bloco.tipo == TIPO_I){
			switch(bloco.orientacao){
				case ORIENTACAO_UP:
					matrix[bloco.i-3][bloco.j] = symbol;
					matrix[bloco.i-2][bloco.j] = symbol;
					matrix[bloco.i-1][bloco.j] = symbol;
					matrix[bloco.i][bloco.j] = symbol;
					break;
				case ORIENTACAO_LEFT:
					matrix[bloco.i][bloco.j-3] = symbol;
					matrix[bloco.i][bloco.j-2] = symbol;
					matrix[bloco.i][bloco.j-1] = symbol;
					matrix[bloco.i][bloco.j] = symbol;
			}
		}
    
}
//Manda as peças para baixo após limpeza da fileira
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