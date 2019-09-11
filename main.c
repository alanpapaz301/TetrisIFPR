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
    int posI, posJ;
    char dir = 'A';
    int aux;
    int maxR = ROWS - 2;
    //posicao inicial do personagem
    posI = 1;
    posJ = COLUMNS/2;
    //inicializando matriz
    init(matrix);

    //esconder cursor da tela
    ShowConsoleCursor(0);
    for(aux=0;aux<9001;aux++){  
        if(aux==9000){
            gotoxy(0,0);
            matrix[posI][posJ] = '@';
            printMatrix(matrix);
            matrix[posI][posJ] = ' ';
            posI++;
            if(posI == maxR){
                mark(matrix,posI,posJ);
                posI = 1;
            }
            
            aux = 0;
        }
        //leitura da tecla pressionada
        if(kbhit()) dir=getch();
        //movimento a esquerda
        if(dir == 'A'){
            posJ--;
            dir = 'P';
            if(posJ == COLUMNS - (COLUMNS -1))posJ = 58;
             }
        //movimento a direita     
        if(dir == 'D'){
            posJ++;
            dir = 'P';
            if(posJ == COLUMNS - 1)posJ = 1;
            }
    }
    
    system("pause");
    return 0;
}