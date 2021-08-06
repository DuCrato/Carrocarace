#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

#define COLUNA 11
#define LINHA 15
#define HORIZOTE 90
#define VERTICAL 25

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
                printf("%c",220);

            }else if(j == 0){

                gotoxy(j, i);
                printf("%c",219);

            }else if(j == HORIZOTE - 1){

                gotoxy(j, i);
                printf("%c",219);

            }else if(i == VERTICAL - 1){

                gotoxy(j, i);
                printf("%c",220);

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

static char pista[LINHA][COLUNA];
static int mover = 0, lado, cimaBaixo = 0, contador = 0;

void movimentacao()
{
	mover = getch();
	if(mover == 119){ //W

        if(cimaBaixo != LINHA - 4){
            ++cimaBaixo;
            void carregaPista();
        }
	}
	else if(mover == 97){ //A

        if(lado != -4){
            --lado;
            void carregaPista();
        }
	}
	else if(mover == 115){ // S

        if(cimaBaixo != 0){
            --cimaBaixo;
            void carregaPista();
        }
	}
	else if(mover == 100){ //D

			if(lado != COLUNA - 7){
            ++lado;
            void carregaPista();
        }
    }
}

void carregaPista(){

    int i, j;

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){pista[i][j] = ' ';}
    }
}

void carroUsuario(){

    pista[LINHA - 1 - cimaBaixo][4 + lado] = 219;
    pista[LINHA - 1 - cimaBaixo][6 + lado] = 219;
    pista[LINHA - 2 - cimaBaixo][5 + lado] = 219;
    pista[LINHA - 3 - cimaBaixo][4 + lado] = 219;
    pista[LINHA - 3 - cimaBaixo][6 + lado] = 219;
    pista[LINHA - 4 - cimaBaixo][5 + lado] = 219;
}

void oponente1(){

    pista[-4 + contador][1] = 219;
    pista[-1 + contador][0] = 219;
    pista[-1 + contador][2] = 219;
    pista[-2 + contador][1] = 219;
    pista[-3 + contador][0] = 219;
    pista[-3 + contador][2] = 219;
}
void oponente2(){

    pista[-4 + contador][5] = 219;
    pista[-1 + contador][4] = 219;
    pista[-1 + contador][6] = 219;
    pista[-2 + contador][5] = 219;
    pista[-3 + contador][4] = 219;
    pista[-3 + contador][6] = 219;
}

void imprime(){

    int i, j;

    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){

            printf("%c",pista[i][j]);
        }
        puts(" ");
    }
}

void placar(){ // PLACAR a ideia é usar arquivo STTS Zero

    printf("\n\n\tPLACAR EM CONSTRUCAO\n\n");
}

void instrucao(){ // Como jogar!!! *** OK ***

    int opcao;

    tela();

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

void load(){

    int i;

    for(i = 0; i < 10; i++){

        sleep(1);
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
    sleep(1);
    printf("CARREGANDO ");
    load();
}

int main(){

    int i;

    for(i = 1; i != 0; i++){

        system("cls");
        carregaPista();
        oponente1();
        oponente2();
        carroUsuario();
        imprime();
        movimentacao();
        if(contador != 16){contador++;
        }else{contador = 0;}

    }
    return 0;
}