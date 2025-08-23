#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
    int m[10][10],i,j,l,p=0,d,f,m1[10][10]={0}; //Criação de variáveis.
    srand(time(NULL)); //Definição de semente de número pseudo aleatório.
    for (i=0;i<10;i++){ //Imprimir e definir valores da matriz.
        for (j=0;j<10;j++){
            l = rand()%4+1;
            switch (l){ //Seleciono o simbolo a partir da tabela ascii.
                case 1: m[i][j]=36;
                break;
                case 2: m[i][j]=35;
                break;
                case 3: m[i][j]=38;
                break;
                case 4: m[i][j]=37;
                break;
            }

            printf("%c",m[i][j]);
            }
            printf("\n");
        }
        printf("Selecione fila e coluna com 3 simbolos iguais."); 
        scanf("%d%d",&d,&f); //Usuário coloca a coluna e fila.
        d=d-1;
        f=f-1;
        if ((d+2<10) && (m[d][f]==m[d+1][f] && m[d][f]==m[d+2][f])){ //Procurando se tem 3 iguais na vertical de cima para baixo.
            p=p+1; //soma de pontos
            for (i=d;i<=d+2;i++){ //transforma os simbolos em "@"
                m1[i][f]=64;
            }
        }
        if ((d-2>=0)&&(m[d][f]==m[d-1][f] && m[d][f]==m[d-2][f])){ //Procurando se tem 3 iguais na vertical de baixo para cima.
            p=p+1;
            for (i=d;i>=d-2;i--){
                m1[i][f]=64;
            }
        }
        if((f+2<10)&&(m[d][f]==m[d][f+1] && m[d][f]==m[d][f+2])){ //Procura se tem 3 iguais na horizontal, da esquerda para a direita.
            p=p+1;
            for (j=f;j<=f+2;j++){
                m1[d][j]=64;
            }
        }
        if((f-2>=0)&&(m[d][f]==m[d][f-1] && m[d][f]==m[d][f-2])){ //Procura se tem 3 iguais na horizontal, da direita para a esquerda.
            p=p+1;
            for (j=f;j>=f-2;j--){
                m1[d][j]=64;
            }
        //Passo os valores para a matriz original.
        } 
        for (i=0;i<10;i++){
            for (j=0;j<10;j++){
                if (m1[i][j]==64){
                    m[i][j]=64;
                }
            }
        //Imprimo a matriz.
        }
        for (i=0;i<10;i++){
            for (j=0;j<10;j++){
                printf("%c",m[i][j]);
                }
                printf("\n");
            }
        printf("Pontos: %d\n",p); //Imprimo os pontos.
    return 0;
}