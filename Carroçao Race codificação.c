#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include"wsol.h"

#define COLUNA 11
#define LINHA 40
#define HORIZOTE 90
#define VERTICAL 26
#define BORDAJ 23

static char pista[LINHA][COLUNA];
static int mover, lado, cimaBaixo, contador = 0, pontuacao = 0;

void gotoxy(int x, int y){

    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void tela(){

    int i, j;

    system("cls");

    for(i = 0; i < VERTICAL; i++){
        for(j = 0; j < HORIZOTE; j++){

            if(i == 0){

                gotoxy(j, i);
                printf("%c",219);

            }else if(j == 0){

                gotoxy(j, i);
                printf("%c",219);

            }else if(j == HORIZOTE - 1){

                gotoxy(j, i);
                printf("%c",219);

            }else if(i == VERTICAL - 1){

                gotoxy(j, i);
                printf("%c",219);

            }else{

                gotoxy(i, j);
                printf(" ");
            }
        }
        puts("");
    }
}

int menu(){ // MENU Inicial

    int opcao;

    tela();
    gotoxy(0,3);
    printf("\t||||||||||\n"
           "\t||             ||      ||||||||  ||||||||  ||||||||   ||||||||      ||\n"
           "\t||            ||||     ||    ||  ||    ||  ||    ||   ||           ||||\n"
           "\t||           ||||||    ||||||    ||||||    ||    ||   ||          ||||||\n"
           "\t||          ||    ||   ||    ||  ||    ||  ||    ||   ||         ||    ||\n"
           "\t|||||||||| ||      ||  ||    ||  ||    ||  ||||||||   |||??|||  ||      ||\n\n");

    printf("\t\t\t\t\t ||||||||\n"
           "\t\t\t\t\t ||    ||      ||     |||||||| ||||||||\n"
           "\t\t\t\t\t ||    ||     ||||    ||       ||\n"
           "\t\t\t\t\t ||||||      ||||||   ||       ||||||||\n"
           "\t\t\t\t\t ||    ||   ||    ||  ||       ||\n"
           "\t\t\t\t\t ||    ||  ||      || |||||||| ||||||||\n\n");

    printf("\t\t\t\t\t1 - Novo Jogo\n\t\t\t\t\t2 - Placar\n\t\t\t\t\t3 - Instrucoes\n\t\t\t\t\t4 - Sair\n\n");
    printf("\t\t\t\t\tDigite a opcao: ");
        scanf("%d",&opcao);

    return opcao;
}

void ponto(){

    pontuacao++;

    gotoxy(8,5);
    wsol_fontcolor(WSOL_WHITE,WSOL_BLACK);
    printf("Pontua%c%co: %d",135, 198, pontuacao);
}

void placar(){

    FILE *placar;
    placar = fopen("Placar.txt","w");
    fprintf(placar, "20 30 40");
    fclose(placar);
}

void lerPlacar(){

    int i, j, valor, valorfor;

    FILE *placar;
    placar = fopen("placar.txt", "r");

    fscanf(placar,"%d %d",&valor, &valorfor);

    int matriz[valorfor][2];

    for(i = 1; i < valorfor; i++)
        for(j = 0; j < 2; j++)fscanf(placar,"%d",&matriz[i][j]);

    ordenar(matriz, valorfor);

    for(i = 1; i != valorfor; i++){
        for(j = 0; j < 2; j++){

            printf("%d ",matriz[i][j]);
        }
        puts("");
    }
}

void ordenar(int matriz[][2], int cont){

    int i, j, aux, help;

    for(i = 1; i < cont; i++){

        for(j = 1 + i - 1; j < cont; j++){
             if(aux < matriz [j][1]){

                aux = matriz[j][1];
                help = j;
            }
        }
        matriz[help][1] = matriz[i][1];
        matriz[i][1] = aux;
        aux = 0;
    }
}

void movimentacao(){

        mover = getch();

        if(mover == 119){ //W

            if(cimaBaixo != LINHA - 20) ++cimaBaixo;

        }else if(mover == 97){ //A

            if(lado != -4) --lado;

        }else if(mover == 115){ // S

            if(cimaBaixo != 0) --cimaBaixo;

        }else if(mover == 100){ //D

            if(lado != COLUNA - 7)++lado;
        }
}

void carroUsuario(){

    pista[LINHA - 7  - cimaBaixo][4 + lado] = 219;
    pista[LINHA - 7  - cimaBaixo][6 + lado] = 219;
    pista[LINHA - 8  - cimaBaixo][5 + lado] = 219;
    pista[LINHA - 9  - cimaBaixo][4 + lado] = 219;
    pista[LINHA - 9  - cimaBaixo][6 + lado] = 219;
    pista[LINHA - 10 - cimaBaixo][5 + lado] = 219;
}

void oponente1(){

    pista[0 + contador][1] = 219;
    pista[1 + contador][0] = 219;
    pista[1 + contador][2] = 219;
    pista[2 + contador][1] = 219;
    pista[3 + contador][0] = 219;
    pista[3 + contador][2] = 219;
}
void oponente2(){

    pista[0 + contador][5] = 219;
    pista[1 + contador][4] = 219;
    pista[1 + contador][6] = 219;
    pista[2 + contador][5] = 219;
    pista[3 + contador][4] = 219;
    pista[3 + contador][6] = 219;
}

void oponente3(){

    pista[0 + contador][9]  = 219;
    pista[1 + contador][8]  = 219;
    pista[1 + contador][10] = 219;
    pista[2 + contador][9]  = 219;
    pista[3 + contador][8]  = 219;
    pista[3 + contador][10] = 219;
}

int colisao(){

    int i, j;

    for(i = 10; i < LINHA - 6; i++){
        for(j = 0; j < COLUNA; j++){

            printf("%c",pista[i][j]);
        }
        puts(" ");
    }
}

void carregaPista(){

    int i, j;

    for(i = 0; i < LINHA; i++)
        for(j = 0; j < COLUNA; j++) pista[i][j] = ' ';

}

void imprime(){

    int i, j;

    for(i = 10; i < LINHA - 6; i++){
        for(j = 0; j < COLUNA; j++){

            gotoxy(j + 36, (i - 10) + 1);
            wsol_fontcolor(0,8);
            printf("%c",pista[i][j]);
        }
        puts(" ");
    }
}

void instrucao(){ // Como jogar!!! *** OK ***

    int opcao;

    gotoxy(0,8);

    printf("\n\n\t\tTeclas para movimentacao W, A, S e M.\n"
            "\t\tTambem pode ser usadas as setas do teclado.\n"
            "\t\tO objetivo do JOGO eh passar a maior quantidade de tempo.\n\n");

    gotoxy(0,20);

    printf("\t\t\tJogar [1] ou Menu pricipal [0]\n");
    printf("\t\t\tDigite a Opcao: ");
        scanf("%d",&opcao);

    return opcao;
}

void borda(){

    int i, j;
    char beira[24][BORDAJ];

    for(i = 0; i < 24; i++){
        for(j = 0; j < BORDAJ; j++){
            if(j == 0 || j == 1 || j == 2 || j == BORDAJ - 1 || j == BORDAJ - 2 || j == BORDAJ - 3){beira[i][j] = 219;
            }else{beira[i][j] = ' ';}
        }
    }

    for(i = 0; i < 24; i++){
        for(j = 0; j < BORDAJ; j++){

            gotoxy(j + 30,i + 1);
            if(j == 0 || j == BORDAJ - 1){
                if(i % 2 == 0){

                    wsol_fontcolor(WSOL_WHITE,WSOL_BLACK);
                    printf("%c",beira[i][j]);

                }else{

                    wsol_fontcolor(WSOL_RED,WSOL_BLACK);
                    printf("%c",beira[i][j]);
                }
            }else if(j == 0 || j == 1 || j == 2 || j == BORDAJ - 1 || j == BORDAJ - 2 || j == BORDAJ - 3){

                wsol_fontcolor(WSOL_GREEN,WSOL_BLACK);
                printf("%c",beira[i][j]);

            }else{

                wsol_fontcolor(WSOL_BLACK,8);
                printf("%c",beira[i][j]);
            }
        }
        puts(" ");
    }

}

void load(){

    int i;

    for(i = 0; i < 10; i++){

        printf("%c",219);
    }
}
void sair(){

    tela();

    gotoxy(30,12);
    printf("SAINDO ");
    load();
}
void carregando(){ //

    tela();

    gotoxy(30,12);
    printf("CARREGANDO ");
    load();
}

int main(){

    int i, colide;

    tela();
    borda();

    for(i = 1; i != 0; i++){

        carregaPista();
        oponente1();
        oponente2();
        oponente3();
        carroUsuario();
        imprime();
        ponto();
        //colisao();
        movimentacao();

        if(contador != 35){contador++;
        }else{contador = 0;}
    }

    return 0;
}
