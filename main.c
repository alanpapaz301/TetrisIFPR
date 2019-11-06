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
	Block backup;
    char matrix[ROWS][COLUMNS];
    int runTime,symbolWidth,i,j,score,aux;
    char dir = 'K';
    char symbol = '#';
    int speedControl = 5;
	score = 0;
    bloco.i = 1;
    bloco.j = COLUMNS/2;
    bloco.tipo = 6;
    bloco.orientacao = 3;
    //inicializando matriz
    init(matrix);

    //esconder cursor da tela
    ShowConsoleCursor(0);
	
    for(runTime=0;runTime<=speedControl;runTime++){
		//CONFIGURAÇÃO DE ALTURA E LARGURA BASEADO NA PEÇA
		if(bloco.tipo == TIPO_O){
			bloco.width = 3;
			bloco.height = 3;
		}
		if(bloco.tipo == TIPO_I){
			if(bloco.orientacao == ORIENTACAO_DOWN |  bloco.orientacao == ORIENTACAO_UP){
				bloco.width = 1;
				bloco.height = 5;
			}
			if(bloco.orientacao == ORIENTACAO_LEFT |  bloco.orientacao == ORIENTACAO_RIGHT){
				bloco.width = 5;
				bloco.height = 1;
			}
		}
		//-------------------------------------------------
        
		gotoxy(0,0);
		drawBlock(matrix,symbol,2,bloco);
        printMatrix(matrix);
        drawBlock(matrix,symbol,1,bloco);
		bloco = checkCollision(matrix,symbol,bloco);
		printf("%d",speedControl);
		if(runTime==speedControl){
			bloco.i++;
            runTime = 0;
        }

        //leitura da tecla pressionada
        if(kbhit()) dir=getch();
			//Mudança de orientação
			if(dir == 'f'){
				if (bloco.orientacao == 4) bloco.orientacao = 1;
				else bloco.orientacao++;
				
				aux = bloco.width;
				bloco.width = bloco.height;
				bloco.height = aux;
				if(bloco.j<(bloco.width/2)) bloco.j = bloco.width/2;
				else if(bloco.j>COLUMNS-(bloco.width/2) - 1 )bloco.j = COLUMNS - (bloco.width/2) - 1;


				dir = ' ';
			}
        //movimento a esquerda
		if(dir == LEFT | dir == LEFT_C){
            if(matrix[bloco.i][bloco.j - (bloco.width / 2)] !=symbol && bloco.j-(bloco.width/2)>0){
                
                bloco.j--;
                dir = ' ';
            }
        }
        //movimento a direita  
		if(dir == RIGHT | dir== RIGHT_C){		
			if(matrix[bloco.i][bloco.j + (bloco.width/2)] !=symbol && bloco.j+(bloco.width/2)<COLUMNS-1){
                
                bloco.j++;
                dir = ' ';
			}   
		}
        //aumenta a velocidade da desçida da peça   
        if(dir == 'S' |dir == 's'){
            int speedControlBackup = speedControl;
            speedControl = 1;
            dir = ' ';           
            speedControl = speedControlBackup;
        }   
    
    }
    
    system("pause");
    return 0;
	}
