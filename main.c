/*
    Jogo interativo Tetris implementado em linguagem C para uso 
    no console (terminal de comandos)

    Para executar:
        > start tetris.exe


*/
#include "display.h"
#include "tetris.h"

/*
    Parte principal do programa, responsável por iniciar e 
    chamar as funções runTimeiliares.
*/
int main(){
	Block bloco;
    char matrix[ROWS][COLUMNS];
    int runTime,symbolWidth,i,j,count;
    char dir = 'A';
    char symbol = '#';
    int speedControl = 6000;
    //bloco.icao inicial do personagem
    bloco.i = 1;
    bloco.j = COLUMNS/2;
    bloco.tipo = 7;
    bloco.orientacao = 4;
    bloco.width = 1;
    bloco.height = 4;
	count = 2;
    //inicializando matriz
    init(matrix);

    //esconder cursor da tela
    ShowConsoleCursor(0);
	
    for(runTime=0;runTime<=speedControl;runTime++){  
        if(runTime==speedControl){
            gotoxy(0,0);
			selectPiece(matrix,symbol,bloco.tipo,count,bloco);
			count++;
            printMatrix(matrix);
            selectPiece(matrix,symbol,bloco.tipo,count,bloco);
			count++;
            bloco.i++;
			
			//Marcação das peças no final da matriz
            if(bloco.i == ROWS - 2 || checkCollision(matrix,symbol,bloco) == 1){
                mark(matrix,symbol,bloco);
                bloco.i = 1;
				bloco.j = COLUMNS/2;
            }
            runTime = 0;
        }
			FullRow(matrix,bloco.i,bloco.j,symbol,speedControl);
		//Aumenta a velocidade a cada fileira preenchida
		speedControl = FullRow(matrix,bloco.i,bloco.j,symbol,speedControl);
        //leitura da tecla pressionada
        if(kbhit()) dir=getch();
			//Mudança de orientação
			if(dir == 'f'){
				if (bloco.orientacao == 4) bloco.orientacao = 1;
				else bloco.orientacao++;
				dir = ' ';
			}
        //movimento a esquerda
            if(matrix[bloco.i][bloco.j-1]!=symbol && bloco.j>1){
                if(dir == LEFT | dir == LEFT_C){
                    bloco.j--;
                    dir = ' ';
                }
            }
        //movimento a direita     
            if(matrix[bloco.i][bloco.j+1] !=symbol && bloco.j<COLUMNS-2){
                if(dir == RIGHT | dir== RIGHT_C){
                    bloco.j++;
                    dir = ' ';
				}   
			}
        //aumenta a velocidade da desçida da peça   
        if(dir == DOWN |dir == DOWN_C){
            int speedControlBackup = speedControl;
            speedControl = 500;
            dir = ' ';           
            speedControl = speedControlBackup;
        }   
    
    }
    
    system("pause");
    return 0;
	}
