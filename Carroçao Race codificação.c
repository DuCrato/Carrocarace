#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"wsol.h"

#define COLUNA 11
#define LINHA 120
#define HORIZOTE 90
#define VERTICAL 26
#define BORDAJ 23
#define USUARIO 219
#define OPONENTE 178

int pista[LINHA][COLUNA];
int mover, lado = 0, cimaBaixo = 0, ladeira = 0, ladeira2 = 0, ladeira3 = 0, ladeira4 = 0, pontuacao;
int ale1, ale2, ale3, ale4;
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

            }
        }
        puts("");
    }
}
int menu(){

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
    gotoxy(36,19);
    printf("1 - Novo Jogo");
    gotoxy(37,20);
    printf("2 - Placar");
    gotoxy(38,21);
    printf("3 - Instrucoes");
    gotoxy(39,22);
    printf("4 - Sair");
    gotoxy(36,23);
        scanf("%d",&opcao);

    return opcao;
}
void ponto(){

    gotoxy(5,13);
    wsol_fontcolor(WSOL_WHITE,WSOL_BLACK);
    printf("Pontua%c%co = %d",135, 132, pontuacao);
    pontuacao++;

}
void movimentacao(){

    if(kbhit()){

        mover = getch();

        if(mover == 119){ //W

            if(cimaBaixo != 20) cimaBaixo += 2;

        }else if(mover == 97){ //A

            if(lado != -4) lado -= 2;

        }else if(mover == 115){ // S

            if(cimaBaixo != 0) cimaBaixo -= 2;

        }else if(mover == 100){ //D

            if(lado != COLUNA - 7) lado += 2;
        }
    }
}
void carroUsuario(){

    pista[65 - cimaBaixo][4 + lado] = USUARIO;
    pista[65 - cimaBaixo][6 + lado] = USUARIO;
    pista[64 - cimaBaixo][5 + lado] = USUARIO;
    pista[63 - cimaBaixo][6 + lado] = USUARIO;
    pista[63 - cimaBaixo][4 + lado] = USUARIO;
    pista[62 - cimaBaixo][5 + lado] = USUARIO;
}
void oponente1(){

    pista[0 + ladeira][1] = OPONENTE;
    pista[1 + ladeira][0] = OPONENTE;
    pista[1 + ladeira][2] = OPONENTE;
    pista[2 + ladeira][1] = OPONENTE;
    pista[3 + ladeira][0] = OPONENTE;
    pista[3 + ladeira][2] = OPONENTE;

}
void oponente2(){

    pista[0 + ladeira][5] = OPONENTE;
    pista[1 + ladeira][4] = OPONENTE;
    pista[1 + ladeira][6] = OPONENTE;
    pista[2 + ladeira][5] = OPONENTE;
    pista[3 + ladeira][4] = OPONENTE;
    pista[3 + ladeira][6] = OPONENTE;
}
void oponente3(){

    pista[0 + ladeira][9]  = OPONENTE;
    pista[1 + ladeira][8]  = OPONENTE;
    pista[1 + ladeira][10] = OPONENTE;
    pista[2 + ladeira][9]  = OPONENTE;
    pista[3 + ladeira][8]  = OPONENTE;
    pista[3 + ladeira][10] = OPONENTE;
}
void oponente4(){

    pista[13 + ladeira2][1] = OPONENTE;
    pista[14 + ladeira2][0] = OPONENTE;
    pista[14 + ladeira2][2] = OPONENTE;
    pista[15 + ladeira2][1] = OPONENTE;
    pista[16 + ladeira2][0] = OPONENTE;
    pista[16 + ladeira2][2] = OPONENTE;

}
void oponente5(){

    pista[13 + ladeira2][5] = OPONENTE;
    pista[14 + ladeira2][4] = OPONENTE;
    pista[14 + ladeira2][6] = OPONENTE;
    pista[15 + ladeira2][5] = OPONENTE;
    pista[16 + ladeira2][4] = OPONENTE;
    pista[16 + ladeira2][6] = OPONENTE;
}
void oponente6(){

    pista[13 + ladeira2][9]  = OPONENTE;
    pista[14 + ladeira2][8]  = OPONENTE;
    pista[14 + ladeira2][10] = OPONENTE;
    pista[15 + ladeira2][9]  = OPONENTE;
    pista[16 + ladeira2][8]  = OPONENTE;
    pista[16 + ladeira2][10] = OPONENTE;
}
void oponente7(){

    pista[26 + ladeira3][1] = OPONENTE;
    pista[27 + ladeira3][0] = OPONENTE;
    pista[27 + ladeira3][2] = OPONENTE;
    pista[28 + ladeira3][1] = OPONENTE;
    pista[29 + ladeira3][0] = OPONENTE;
    pista[29 + ladeira3][2] = OPONENTE;

}
void oponente8(){

    pista[26 + ladeira3][5] = OPONENTE;
    pista[27 + ladeira3][4] = OPONENTE;
    pista[27 + ladeira3][6] = OPONENTE;
    pista[28 + ladeira3][5] = OPONENTE;
    pista[29 + ladeira3][4] = OPONENTE;
    pista[29 + ladeira3][6] = OPONENTE;
}
void oponente9(){

    pista[26 + ladeira3][9]  = OPONENTE;
    pista[27 + ladeira3][8]  = OPONENTE;
    pista[27 + ladeira3][10] = OPONENTE;
    pista[28 + ladeira3][9]  = OPONENTE;
    pista[29 + ladeira3][8]  = OPONENTE;
    pista[29 + ladeira3][10] = OPONENTE;
}
void oponente10(){

    pista[39 + ladeira4][1] = OPONENTE;
    pista[40 + ladeira4][0] = OPONENTE;
    pista[40 + ladeira4][2] = OPONENTE;
    pista[41 + ladeira4][1] = OPONENTE;
    pista[42 + ladeira4][0] = OPONENTE;
    pista[42 + ladeira4][2] = OPONENTE;

}
void oponente11(){

    pista[39 + ladeira4][5] = OPONENTE;
    pista[40 + ladeira4][4] = OPONENTE;
    pista[40 + ladeira4][6] = OPONENTE;
    pista[41 + ladeira4][5] = OPONENTE;
    pista[42 + ladeira4][4] = OPONENTE;
    pista[42 + ladeira4][6] = OPONENTE;
}
void oponente12(){

    pista[39 + ladeira4][9]  = OPONENTE;
    pista[40 + ladeira4][8]  = OPONENTE;
    pista[40 + ladeira4][10] = OPONENTE;
    pista[41 + ladeira4][9]  = OPONENTE;
    pista[42 + ladeira4][8]  = OPONENTE;
    pista[42 + ladeira4][10] = OPONENTE;
}
void carroAleatorio1(){

    int i;

    srand(time(NULL));

    for(i = 1; i != 0; i++){

        ale1 = rand() % 3;
        ale2 = rand() % 3;

        if(ale1 != ale2) break;
    }
}
void carroAleatorio2(){

    int i;

    for(i = 1; i != 0; i++){

        ale3 = rand() % 3;
        ale4 = rand() % 3;

        if(ale3 != ale4) break;
    }
}
void imprimeOponente1(){

    if(ale1 == 0){oponente1();
    }else if(ale1 == 1){oponente2();
    }else{oponente3();}

    if(ale2 == 0){oponente1();
    }else if(ale2 == 1){oponente2();
    }else{oponente3();}
}
void imprimeOponente2(){

    if(ale1 == 0){oponente6();
    }else if(ale1 == 1){oponente5();
    }else{oponente4();}

    if(ale2 == 0){oponente6();
    }else if(ale2 == 1){oponente5();
    }else{oponente4();}
}
void imprimeOponente3(){

    if(ale3 == 0){oponente8();
    }else if(ale3 == 1){oponente9();
    }else{oponente7();}

    if(ale4 == 0){oponente8();
    }else if(ale4 == 1){oponente9();
    }else{oponente7();}
}
void imprimeOponente4(){

    if(ale3 == 0){oponente12();
    }else if(ale3 == 1){oponente10();
    }else{oponente11();}

    if(ale4 == 0){oponente12();
    }else if(ale4 == 1){oponente10();
    }else{oponente11();}
}
int colisao(){

    int i, j, bateu = 0;

    for(i = 42; i < 66; i++){
        for(j = 0; j < COLUNA; j++){

            if(pista[i][j] == 219 && pista[i - 1][j] == 178) bateu = 1;
        }
    }
    return bateu;
}
void fimCorrida(int pontoSave){

    ladeira  = 0;
    ladeira2 = 0;
    ladeira3 = 0;
    ladeira4 = 0;

    cimaBaixo = 0;
    lado = 0;

    gotoxy(60,13);
    wsol_fontcolor(WSOL_WHITE,WSOL_BLACK);
    printf("Sua Pontua%c%co = %d",135, 132, pontoSave);
    Sleep(15);

    FILE *arquivo;
    arquivo = fopen("Placar.txt","a");

    if(arquivo == NULL){

        criarPlacar();

        gotoxy(60,14);
        printf("Pontua%c%co n%o salva",135, 132, 132);
    }else{

        inserirPlacar(pontoSave);
    }
    fclose(arquivo);
}
void carregaPista(){

    int i, j, x = 1;

    for(i = 42; i < 66; i++)
        for(j = 0; j < COLUNA; j++) pista[i][j] = ' ';

}
void imprime(){

    int i, j;

    for(i = 42; i < 66; i++){
        for(j = 0; j < COLUNA; j++){

            gotoxy(j + 36, (i - 42) + 1);
            wsol_fontcolor(0,8);
            printf("%c ",pista[i][j]);
        }
        puts(" ");
    }
}
void criarPlacar(){

    FILE *arquivo;

    if((arquivo = fopen("Placar.txt", "w")) == NULL){

        printf("Arquivo nao pode ser criado");
        exit(1);
    }
    fclose(arquivo);
}
void lerPlacar(){

    int contador = 0, percorrer = 0;

    FILE *arquivo;

    if((arquivo = fopen("Placar.txt", "r")) == NULL){

        printf("Arquivo nao encontrado");
        criarPlacar();
        exit(1);
    }
    while((percorrer = fgetc(arquivo)) != EOF){

        if(percorrer == '\n') contador++;
    }
    fclose(arquivo);

    encheVetor(contador);
}
void encheVetor(int tamanho){

    int vetor[tamanho], i = 0, valor;

    FILE *arquivo;

    if((arquivo = fopen("Placar.txt", "r")) == NULL){

        printf("Arquivo nao encontrado!!!");
        exit(1);
    }

    while(fscanf(arquivo, "%d", &valor) != EOF){

        vetor[i] = valor;
        i++;
    }
    fclose(arquivo);
    ordenar(vetor, tamanho);
}
void ordenar(int vetor[], int tam){

    int i, j, aux, temp = 0;

    for(i = 0; i < tam; i++){
        for(j = i; j < tam; j++){

            if(temp < vetor[j]){

                temp = vetor[j];
                aux = j;
            }
        }
        vetor[aux] = vetor[i];
        vetor[i] = temp;
        temp = 0;
    }

    tela();

    for(i = 0; i < tam; i++){

        if(i != 12){

            gotoxy(40,10 + i);
            printf("%d - %d\n",i + 1, vetor[i]);
        }else{break;}
    }
    gotoxy(30,23);
    system("pause");
}
void inserirPlacar(int valor){

    FILE *arquivo;

    if((arquivo = fopen("Placar.txt", "a")) == NULL){

        printf("Arquivo nao encontrado");
        exit(1);
    }else{

        fprintf(arquivo, "%d\n", valor);
    }

    fclose(arquivo);
}
void instrucao(){

    gotoxy(0,8);

    printf("\n\n\t\tTeclas para movimentacao W, A, S e M.\n"
            "\t\tTambem pode ser usadas as setas do teclado.\n"
            "\t\tO objetivo do JOGO eh passar a maior quantidade de tempo.\n\n");

    gotoxy(35,20);
    printf("Qualquer teclas para SAIR\n");
    getch();

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
    imprimiBorda(beira);
}
void imprimiBorda(char beira[][BORDAJ]){

    int i, j;

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

        sleep(1);
        printf("%c",219);
    }
}
void sair(){

    tela();

    gotoxy(30,12);
    printf("SAINDO ");
    load();
    gotoxy(0,30);

}
void carregando(){

    tela();

    gotoxy(30,12);
    printf("CARREGANDO ");
    load();
}

int main(){

    int i, j, colide, valor, menos, pontoFinal;

    for(j = 1; j != 0; j++){

        valor = menu();

        switch(valor){

            case 1:

                tela();
                carregando();
                borda();

                pontuacao = 0;
                menos = 0;

                for(i = 1; i != 0; i++){

                    Sleep(200 - menos);
                    carregaPista();
                    if(ladeira == 0) carroAleatorio1();
                    if(ladeira2 == 0) carroAleatorio2();
                    imprimeOponente1();
                    imprimeOponente2();
                    imprimeOponente3();
                    imprimeOponente4();
                    carroUsuario();
                    imprime();
                    colide = colisao();
                    ponto();
                    movimentacao();

                    if(pontuacao % 10 == 0 && menos < 190)menos += 10;

                    if(colide){

                        fimCorrida(pontuacao);
                        sleep(2);

                        break;
                    }
                    if(ladeira != 63){ladeira++;
                    }else{ladeira = 0;}

                    if(ladeira2 != 63){ladeira2++;
                    }else{ladeira2 = 0;}

                    if(ladeira3 != 63){ladeira3++;
                    }else{ladeira3 = 0;}

                    if(ladeira4 != 63){ladeira4++;
                    }else{ladeira4 = 0;}
                }
                break;

            case 2:

                lerPlacar();
                break;

            case 3:

                tela();
                instrucao();
                break;

            case 4:

                sair();
                j = -1;
                break;
        }
    }
    return 0;
}
