
#include "tetris.h"

/*
    Inicializa a matriz principal com 'espaços vazios'
*/
void init(char matrix[ROWS][COLUMNS]){
    int i,j;

    for(i=0; i<ROWS; i++){
        
        for(j=0; j<COLUMNS; j++){
            matrix[i][j] = ' ';

        }
    }
}
void printMatrix(char matrix[ROWS][COLUMNS]){
    int i,j;

    printf("\t\t\t\t\t");
    //Linha de cima
    for(j=0; j<COLUMNS+2; j++){
        printf("*");
    }
    printf("\n");

    //Matriz do jogo
    for(i=0; i<ROWS; i++){        
        printf("\t\t\t\t\t*");
        for(j=0; j<COLUMNS; j++){
            printf("%c", matrix[i][j]);
        }
        printf("*\n");
    }

    printf("\t\t\t\t\t");
    //Linha de baixo
    for(j=0; j<COLUMNS+2; j++){
        printf("*");
    }
    printf("\n");

}
//Desenha os blocos 
void drawBlock(char matrix[ROWS][COLUMNS],char symbol,int count,Block bloco){
	//count determina se deve ser feito desenho ou chamada função para apagar blocos
	if(count == 2 ){
		if(bloco.tipo == TIPO_O ){
			if(bloco.i - 1>=1)matrix[bloco.i-1][bloco.j] = symbol;
			if(bloco.i - 1>=1)matrix[bloco.i-1][bloco.j+1] = symbol;
			if(bloco.i - 1>=1)matrix[bloco.i][bloco.j] = symbol;
			if(bloco.i - 1>=1)matrix[bloco.i][bloco.j+1] = symbol;
		}	
		if(bloco.tipo == TIPO_I ){
			switch(bloco.orientacao){
				case ORIENTACAO_DOWN:
				case ORIENTACAO_UP:
					if(bloco.i-4>=1) matrix[bloco.i-4][bloco.j] = symbol;
					if(bloco.i-3>=1) matrix[bloco.i-3][bloco.j] = symbol;
					if(bloco.i-2>=1) matrix[bloco.i-2][bloco.j] = symbol;
					if(bloco.i-1>=1) matrix[bloco.i-1][bloco.j] = symbol;
					matrix[bloco.i][bloco.j] = symbol;
					break;
				case ORIENTACAO_LEFT:
				case ORIENTACAO_RIGHT:
						matrix[bloco.i][bloco.j+2] = symbol;
						matrix[bloco.i][bloco.j+1] = symbol;
						matrix[bloco.i][bloco.j-2] = symbol;
						matrix[bloco.i][bloco.j-1] = symbol;
						matrix[bloco.i][bloco.j] = symbol;
						matrix[bloco.i][bloco.j] = symbol;
					break;

			}
		}
	}
	else eraseBlock(matrix,bloco);
		
}
//Apaga os blocos
void eraseBlock(char matrix[ROWS][COLUMNS],Block bloco){
		
		
		if(bloco.tipo == TIPO_O){
				matrix[bloco.i][bloco.j] = ' ';
				matrix[bloco.i][bloco.j+1] = ' ';
				matrix[bloco.i-1][bloco.j] = ' ';
				matrix[bloco.i-1][bloco.j+1] = ' ';
		}
		if(bloco.tipo = TIPO_I){
			switch(bloco.orientacao){
				case ORIENTACAO_DOWN:
				case ORIENTACAO_UP:
					if(bloco.i-3>=0) matrix[bloco.i-4][bloco.j] = ' ';
					if(bloco.i-3>=0) matrix[bloco.i-3][bloco.j] = ' ';
					if(bloco.i-2>=0) matrix[bloco.i-2][bloco.j] = ' ';
					if(bloco.i-1>=0) matrix[bloco.i-1][bloco.j] = ' ';
					matrix[bloco.i][bloco.j] = ' ';
					break;
				case ORIENTACAO_LEFT:
				case ORIENTACAO_RIGHT:
						matrix[bloco.i][bloco.j+2] = ' ';
						matrix[bloco.i][bloco.j+1] = ' ';
						matrix[bloco.i][bloco.j-2] = ' ';
						matrix[bloco.i][bloco.j-1] = ' ';
						matrix[bloco.i][bloco.j] = ' ';
					matrix[bloco.i][bloco.j] = ' ';
					break;

			}
		}
}
Block checkCollision(char matrix[ROWS][COLUMNS],char symbol,Block bloco){

	
	if(bloco.tipo == TIPO_O){
		if(matrix[bloco.i+1][bloco.j] == symbol || matrix[bloco.i+1][bloco.j+1] == symbol || bloco.i == ROWS-1){
			mark(matrix,symbol,bloco); 
			bloco.i = 1;
			bloco.j = COLUMNS/2;
		}
	}
	if(bloco.tipo == TIPO_I){
		if(bloco.orientacao == ORIENTACAO_DOWN |  bloco.orientacao == ORIENTACAO_UP){
				if(matrix[bloco.i+1][bloco.j] == symbol  || bloco.i == ROWS-1){
					//printf("Marcando\n");
					mark(matrix,symbol,bloco);
					bloco.i = 1;
					bloco.j = COLUMNS/2;
				}
		}
		if(bloco.orientacao == ORIENTACAO_LEFT |  bloco.orientacao == ORIENTACAO_RIGHT){	
				if(bloco.i == ROWS - 1|| matrix[bloco.i + 1][bloco.j -2] == symbol || matrix[bloco.i + 1][bloco.j - 1] == symbol
					|| matrix[bloco.i + 1][bloco.j] == symbol|| matrix[bloco.i + 1][bloco.j + 1] == symbol|| matrix[bloco.i + 1][bloco.j + 2] == symbol){
						mark(matrix,symbol,bloco);
						bloco.i = 1;
						bloco.j = COLUMNS/2;		
					}
		}
		
	}
	return bloco;
}
//marca peças no final da matriz ou ao baterem em outra peça
void mark(char matrix[ROWS][COLUMNS],char symbol,Block bloco){
		
		
		if(bloco.tipo == TIPO_O){
			matrix[bloco.i][bloco.j] = symbol;
			matrix[bloco.i][bloco.j+1] = symbol;
			matrix[bloco.i-1][bloco.j] = symbol;
			matrix[bloco.i-1][bloco.j+1] = symbol;
		}
		if(bloco.tipo == TIPO_I){
			switch(bloco.orientacao){
				case ORIENTACAO_DOWN:
				case ORIENTACAO_UP:
					matrix[bloco.i-4][bloco.j] = symbol;
					matrix[bloco.i-3][bloco.j] = symbol;
					matrix[bloco.i-2][bloco.j] = symbol;
					matrix[bloco.i-1][bloco.j] = symbol;
					matrix[bloco.i][bloco.j] = symbol;
					break;
				case ORIENTACAO_LEFT:
				case ORIENTACAO_RIGHT:
					matrix[bloco.i][bloco.j+2] = symbol;
					matrix[bloco.i][bloco.j+1] = symbol;
					matrix[bloco.i][bloco.j-2] = symbol;
					matrix[bloco.i][bloco.j-1] = symbol;
					matrix[bloco.i][bloco.j] = symbol;
					break;
			}
		}
		FullRow(matrix,bloco.i,bloco.j,symbol);
}


//Limpa fileira após preenchida
void FullRow(char matrix[ROWS][COLUMNS],int row,int col,char symbol){
    int j,i,cont,n;
       
    for(i=ROWS; i>1; i--){
        cont = 0;   
        for(j=1; j<COLUMNS - 1; j++){
            if(matrix[i][j]==symbol)cont++;
            
        }
        if(cont >= COLUMNS - 2){  
            for(n = 0; n<COLUMNS; n++){
            matrix[i][n] = ' ';
            }
			//Manda as peças para baixo após limpeza da fileira
			for(i = ROWS-1; i>1;i--){
				for(j = 0;j<=COLUMNS-1;j++){
					if(i>1) matrix[i][j] = matrix[i-1][j];



				}

			}
        }
    }
}
