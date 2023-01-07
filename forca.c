#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "forca.h"

char palavraSecreta[TAMANHO_PALAVRA];
char chutes[26];
char chutes_errados[26];
int chutes_do_usuario = 0;
int chute_errado = 0;


void abertura(){
    printf("|###############|\n");
    printf("| JOGO DA FORCA |\n");
    printf("|###############|\n\n");
}

void mostra_forca(){

    int erros = quantidade_chutes_errados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros >= 1? '(' : ' '), (erros >= 1? '_':' '), (erros>=1? ')':' '));
    printf(" |      %c%c%c  \n", (erros>=3? '\\':' '), (erros>=2? '|': ' '), (erros>=3? '/':' '));
    printf(" |       %c     \n",(erros>=2? '|' : ' '));
    printf(" |      %c %c   \n",(erros>=4? '/':' '), (erros>=4? '\\': ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for (int i = 0; i < strlen(palavraSecreta); i++){
        if (ja_chutou(palavraSecreta[i])){
            printf("%c ", palavraSecreta[i]);
        }else{
            printf("_ ");
        }
        
    }
    printf("\n");  

}

void trofeu(char* palavra){
    printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

        printf("PALAVRA SECRETA: [ %s ]\n", palavra);
}

void caveira(char* palavra){
    printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavra);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
}

void escolha_a_palavra(){
    FILE* f;

    f = fopen("palavrasSecretas.txt", "r");
    if (f == 0){
        printf("Banco de palavras não disponível !!\n\n");
        exit(1);
    }
    
    int quantidade_de_palavras;
    fscanf(f, "%d", &quantidade_de_palavras);

    srand(time(0));
    int randomizar = rand() % quantidade_de_palavras;

    for (int i = 0; i <= randomizar; i++){
        fscanf(f, "%s", palavraSecreta);
    }
    fclose(f);
}

void letras_chutadas(){
    printf("\nLETRAS CHUTADAS ERRADAS:\n");
    for(int i=0; i<strlen(chutes_errados); i++){
        printf("%c ", chutes_errados[i]);
    }
}

void chuta(){
    char chute;
    printf("\n\nQual a letra? ");
    scanf(" %c", &chute);

    if(letra_existe(chute)){
        printf("\nVocê acertou !!!! A palavra tem a letra %c\n\n", chute);
    }else{
        printf("\nVocê errou !! A palavra NÃO tem a letra %c\n\n", chute);
        chutes_errados[chute_errado]=chute;
        chute_errado++;
    }

    chutes[chutes_do_usuario] = chute;
    chutes_do_usuario++;    
}

int ja_chutou(char letra){
    int achou = 0;
    for(int i=0; i<chutes_do_usuario; i++){
        if (chutes[i]== letra){
            achou=1;
            break;
        }
    }

    return achou;
}

int letra_existe(char letra){
    for (int i = 0; i < strlen(palavraSecreta); i++){
        if (palavraSecreta[i]==letra){
            return 1;
        }
        
    }
    
    return 0;
}

int quantidade_chutes_errados(){
    int erros = 0;

    for (int i = 0; i < chutes_do_usuario; i++){
        if (!letra_existe(chutes[i])){
            erros++;
        }
        
    }
    
    return erros;
}

int enforcou(){
    return quantidade_chutes_errados() >= 5;
}

int ganhou(){
    for (int i = 0; i < strlen(palavraSecreta); i++){
        if(!ja_chutou(palavraSecreta[i])){
            return 0;
        }
    }
    
    return 1;
}

int main(){

    abertura();
    escolha_a_palavra();

    do {

        mostra_forca();
        letras_chutadas();
        chuta();


    } while (!ganhou() && !enforcou());

    if(ganhou()){
        trofeu(palavraSecreta);
    }else{
        caveira(palavraSecreta);
    }
}