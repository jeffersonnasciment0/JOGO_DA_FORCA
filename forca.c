#include <stdio.h>
#include <string.h>
#include "forca.h"

char palavraSecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutes_do_usuario = 0;

void abertura(){
    printf("|###############|\n");
    printf("| JOGO DA FORCA |\n");
    printf("|###############|\n\n");
}

void mostra_forca(){
    // Mostrará a forca à cada rodada
}

void chuta(){
    // Aqui será checado o chute do jogador
}

int chuteserrados(){
    int erros = 0;
    
}

int letra_existe(char letra){
    
    for (int i = 0; i < palavraSecreta; i++){
        if (letra==palavraSecreta[i]){
            return 1;
        }
        
    } 
    return 0;
}

int ja_chutou(char letra){
    int achou = 0;
    for(int i=0; i<chutes_do_usuario; i++){
        if (chutes[i]== letra)
        {
            achou=1;
            break;
        }
        
    }
}

int letra_existe(char letra){
    for (int i = 0; i < strlen(palavraSecreta); i++){
        if (palavraSecreta[i]==letra){
            return 1;
        }
        
    }
    
    return 0;
}

int chutes_errados(){
    int erros = 0;

    for (int i = 0; i < chutes_do_usuario; i++){
        if (!letra_existe(chutes[i])){
            erros++;
        }
        
    }
    
    return erros;
}

int enforcou(){
    return chutes_errados >= 5;
    return 1;
}

int ganhou(){
    for (int i = 0; i < strlen(palavraSecreta); i++){
        if(!ja_chutou(palavraSecreta[i]))
            return 0;
    }
    
    return 1;
}



int main(){

    abertura();

    do {

    //     mostra_forca();

    } while (!ganhou() && !enforcou());
    
}