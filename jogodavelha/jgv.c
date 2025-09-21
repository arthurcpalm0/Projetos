#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void preencher_matriz(char m[3][3]){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            m[i][j]='.';
        }
    }
}
void print_matriz(char m[3][3], int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%c\t",m[i][j]);
        }
        printf("\n");
    }
}
int vencedor(char m[3][3]);
int verificação(int fil, int col, char simb, char m[3][3]){
    if ((fil>2||col>2)||(m[fil][col]!='.')||(simb!='x'&&simb!='o')){
        return -1;
    }
    else{
        return 0;
    }
}
int jogador(int fil, int col, char simb, char m[3][3]){
    while (verificação(fil,col,simb,m)!=0){
        printf("Ingresse a posição(fila-coluna)\n");
        scanf("%d%d",&fil,&col);
    }
    m[fil][col]=simb;
    if (vencedor(m)==1){
        return 1;
    }
    else{
        return 0;
    }
}
int oponente(int fil, int col, char simb, char m[3][3]){
    srand(time(NULL));
    while (verificação(fil,col,simb,m)!=0){
        fil=rand()%3;
        col=rand()%3;
    }
    m[fil][col]=simb;
    if (vencedor(m)==1){
        return 1;
    }
    else{
        return 0;
    }
}
int vencedor(char m[3][3]){
    // Verificar linhas
    for (int i=0; i<3; i++){
        if (m[i][0] != '.' && m[i][0] == m[i][1] && m[i][1] == m[i][2])
            return 1;
    }
    // Verificar colunas
    for (int j=0; j<3; j++){
        if (m[0][j] != '.' && m[0][j] == m[1][j] && m[1][j] == m[2][j])
            return 1;
    }
    // Verificar diagonais
    if (m[0][0] != '.' && m[0][0] == m[1][1] && m[1][1] == m[2][2])
        return 1;
    if (m[0][2] != '.' && m[0][2] == m[1][1] && m[1][1] == m[2][0])
        return 1;

    return 0;
}
int main(){
    srand(time(NULL));
    int c = 0;
    char m[3][3];
    preencher_matriz(m);
    for (int i=0;i<9;i++){
        c++;
        print_matriz(m,3);
        int fil, col;
        printf("Ingresse a posição(fila-coluna)\n");
        scanf("%d%d",&fil,&col);
        int gj = jogador(fil,col,'x',m);
        if (gj==1){
            printf("Jogador ganhou\n");
            print_matriz(m,3);
            break;
        }
        int go = oponente(rand()%3,rand()%3,'o',m);
        if (go==1){
            printf("Computador ganhou\n");
            print_matriz(m,3);
            break;
        }
        if (c>8){
            printf("Empate\n");
        }
    }
    return 0;
}