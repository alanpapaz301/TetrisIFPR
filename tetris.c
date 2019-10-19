
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
//Desenha blocos tipo I
void drawBlock(char matrix[ROWS][COLUMNS],char symbol,int count,Block bloco){
	if(count == 2 ){
		switch(bloco.tipo){
			case TIPO_O:
			if(bloco.i - 1>=1)matrix[bloco.i][bloco.j] = symbol;
			if(bloco.i - 1>=1)matrix[bloco.i][bloco.j+1] = symbol;
			if(bloco.i - 1>=1)matrix[bloco.i+1][bloco.j] = symbol;
			if(bloco.i - 1>=1)matrix[bloco.i+1][bloco.j+1] = symbol;
			break;
			
		case TIPO_I:
			switch(bloco.orientacao){
				case ORIENTACAO_DOWN:
				case ORIENTACAO_UP:
					if(bloco.i-3>=1) matrix[bloco.i-4][bloco.j] = symbol;
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
	else eraseBlock(matrix,symbol,count,bloco);
		
}
//Apaga blocos tipoI
void eraseBlock(char matrix[ROWS][COLUMNS],char symbol,int count,Block bloco){
		
		
		if(bloco.tipo == TIPO_O){
				if(bloco.i - 1>=1)matrix[bloco.i][bloco.j] = ' ';
				if(bloco.i - 1>=1)matrix[bloco.i][bloco.j+1] = ' ';
				if(bloco.i - 1>=1)matrix[bloco.i+1][bloco.j] = ' ';
				if(bloco.i - 1>=1)matrix[bloco.i+1][bloco.j+1] = ' ';
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
int checkCollision(char matrix[ROWS][COLUMNS],char symbol,Block bloco){
	int i;
	
	
	if(bloco.tipo == TIPO_O){
		if(matrix[bloco.i+1][bloco.j] == symbol || matrix[bloco.i+1][bloco.j+1] == symbol || bloco.i == ROWS - 2){
			mark(matrix,symbol,bloco); 
			return 1;
		}
	}
	if(bloco.tipo == TIPO_I){
		switch(bloco.orientacao){
				case ORIENTACAO_DOWN:
				case ORIENTACAO_UP:
				if(matrix[bloco.i+1][bloco.j] == symbol)return 1; break;
					
				case ORIENTACAO_LEFT:
				case ORIENTACAO_RIGHT:
				for(i = -2; i<bloco.width / 2;i++){
					if(matrix[bloco.i + 1][bloco.j] ==ROWS - 2 || matrix[bloco.i + 1][bloco.j + i] == symbol){
						mark(matrix,symbol,bloco);
						return 1;
						break;				
					}
				break;
				
				}
		}
	}
	return 0;
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
//Manda as peças para baixo após limpeza da fileira
void DownRow(char matrix[ROWS][COLUMNS]){
    int i,j;

    for(i = ROWS-2; i>1;i--){
        for(j = 1;j<COLUMNS-1;j++){
            if(i>1) matrix[i][j] = matrix[i-1][j];



        }

    }

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
            for(n = 1; n<COLUMNS -1; n++){
            matrix[i][n] = ' ';
            }
           DownRow(matrix);
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