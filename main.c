/*
    Jogo interativo Tetris implementado em linguagem C para uso 
    no console (terminal de comandos)

    Para executar:
        > start programa.exe

    Autor: Augusto Luengo Pereira Nunes
    Data: 28/08/2019

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

    //posicao inicial do personagem
    posI = 0;
    posJ = COLUMNS/2;
    //inicializando matriz
    init(matrix);


    //esconder cursor da tela
    ShowConsoleCursor(0);
    system("cls");
    while(1){
        gotoxy(0,0);

        matrix[posI][posJ] = '@';

        printMatrix(matrix);

        matrix[posI][posJ] = ' ';
        
        if(posI < ROWS) posI++;

       }
        if(posI==ROWS){
            posI = 0;
        }
    system("pause");

    return 0;
}