#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//Configuração das dimensões da matriz principal do jogo
#define COLUMNS 20
#define ROWS 25


#define LEFT 97
#define RIGHT 100
#define LEFT_C 65
#define RIGHT_C 68
#define DOWN 73
#define DOWN_C 53
#define SPACE 32
#define CHANGE_ORIENTATION 46
//Criando as orientações para as peças
#define ORIENTACAO_UP 1
#define ORIENTACAO_RIGHT 2
#define ORIENTACAO_DOWN 3
#define ORIENTACAO_LEFT 4
//Criando os tipos de peças
#define TIPO_L 1
#define TIPO_L_R 2 // L reverso
#define TIPO_T 3
#define TIPO_Z 4
#define TIPO_Z_R 5 // Z reverso
#define TIPO_O 6   // Quadrado
#define TIPO_I 7


typedef struct{
    int i;  //posicao nas linhas da matriz
    int j; //posicao nas colunas da matriz
    int orientacao; //orientacao da peça
    int tipo; //o tipo de peça (7 possíveis)
    int width; //largura da peça
    int height; //altura da peça
}Block;
//Inicializa a matriz principal com 'espaços vazios'
void init(char matrix[ROWS][COLUMNS]);
//Desenho de bloco
void drawBlock(char matrix[ROWS][COLUMNS],char symbol,int count,Block bloco);
void eraseBlock(char matrix[ROWS][COLUMNS],Block bloco);
int checkCollision(char matrix[ROWS][COLUMNS],char symbol,Block bloco);
//Marcação de peças ao chegarem na ultima fileira ou encontrarem outra peça
void mark(char matrix[ROWS][COLUMNS],char symbol,Block bloco);
//Manda as peças para baixo após esvaziar a fileira
void DownRow(char matrix[ROWS][COLUMNS]);
//Limpa a ultima linha quando é preenchida,aumenta a velocidade da animação, faltando trazer as peças de cima para baixo
void FullRow(char matrix[ROWS][COLUMNS],int row,int col,char symbol);
//Mostra o conteúdo da matriz principal na tela do computador.
void printMatrix(char matrix[ROWS][COLUMNS]);