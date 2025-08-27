#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void def_matriz(int m[10][10]){
    srand(time(NULL));
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            int l=rand()%4+1;
            switch (l){
                case 1: m[i][j]=35;
                break;
                case 2: m[i][j]=36;
                break;
                case 3: m[i][j]=37;
                break; 
                case 4: m[i][j]=38;
                break;
            }
        }
    }
}

void print_matriz(int m[10][10]){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            printf("%c",m[i][j]);
        }
        printf("\n");
    }
}
void val_matriz(int m[10][10]){
    int a,b,m1[10][10];
    scanf("%d%d",&a,&b);
    if (m[a][b]==m[a+1][b]&&m[a][b]==m[a+2][b]){
    }
}

int main(){
    int m[10][10];
    def_matriz(m);
    print_matriz(m);
}