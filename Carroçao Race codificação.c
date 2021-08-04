#include<stdio.H>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

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

void jogo_pista(){

    int pista[15][11];
    int i, j;

    tela();

    for(i = 0; i < LINHA; i++){

        gotoxy(35, 8 + i);

        for(j = 0; j < COLUNA; j++){
           
            if(j == 0 || j == COLUNA - 1){
                
                textcolor(1);
                printf("%c",219);
            }else{printf(" ");}
        }
         puts("");
    }
}

void placar(){ // PLACAR a ideia é usar arquivo STTS Zero

    printf("\n\n\tPLACAR EM CONSTRUCAO\n\n");
}

void instrucao(){ // Como jogar!!!

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
void carregando(){

    tela();

    gotoxy(30,12);
    sleep(1);
    printf("CARREGANDO ");
    load();
}

int main(){

    jogo_pista();

    return 0;
}
