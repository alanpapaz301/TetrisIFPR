/*
    Jogo interativo Tetris implementado em linguagem C para uso 
    no console (terminal de comandos)

    Para executar:
        > start programa.exe


*/
#include "display.h"
#include "tetris.h"

/*
    Parte principal do programa, responsável por iniciar e 
    chamar as funções auxiliares.
*/
int main(){
    char matrix[ROWS][COLUMNS];
    int posI, posJ,aux;
    char dir = 'A';
    char symbol = 254;
    int frames = 9000;
    int maxR = ROWS - 2;
    //posicao inicial do personagem
    posI = 1;
    posJ = COLUMNS/2;
    //inicializando matriz
    init(matrix);

    //esconder cursor da tela
    ShowConsoleCursor(0);
    for(aux=0;aux<=frames;aux++){  
        if(aux==frames){
            gotoxy(0,0);
            matrix[posI][posJ] = symbol;
            printMatrix(matrix);
            matrix[posI][posJ] = ' ';
            posI++;
            if(posI == maxR | matrix[posI + 1][posJ] == symbol){
                mark(matrix,posI,posJ,symbol);
                posI = 1;
                if(frames>1500)frames -=500;
                

            }
            aux = 0;
        }
        //leitura da tecla pressionada
        if(kbhit()) dir=getch();
        //movimento a esquerda
        if(dir == 'a' | dir == 'A'){
            posJ--;
            dir = ' ';
            if(posJ == COLUMNS - (COLUMNS -1))posJ = 58;
             }
        //movimento a direita     
        if(dir == 'd' | dir=='D'){
            posJ++;
            dir = ' ';
            if(posJ == COLUMNS - 1)posJ = 1;
            }
        if(dir == 's' |dir == 'S'){
            int framesBackup = frames;
            frames = 1500;
            dir = ' ';           
            frames = framesBackup;
        }   
    
    }
    
    system("pause");
    return 0;
}