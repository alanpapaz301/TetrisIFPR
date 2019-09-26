#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//Configuração das dimensões da matriz principal do jogo
#define COLUMNS 20
#define ROWS 10


//Inicializa a matriz principal com 'espaços vazios'
void init(char matrix[ROWS][COLUMNS]);
//Marcação de peças ao chegarem na ultima fileira ou encontrarem outra peça
void mark(char matrix[ROWS][COLUMNS],int row,int col,char symbol);
//Limpa a ultima linha quando é preenchida,aumenta a velocidade da animação, faltando trazer as peças de cima para baixo
int FullRow(char matrix[ROWS][COLUMNS],int row,int col,char symbol,int speedControl);
//Mostra o conteúdo da matriz principal na tela do computador.
void printMatrix(char matrix[ROWS][COLUMNS]);