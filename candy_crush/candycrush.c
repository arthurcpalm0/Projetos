#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
    int m[10][10],i,j,l;
    char lt;
    srand(time(NULL));
    for (i=0;i<10;i++){
        for (j=0;j<10;j++){
            l = rand()%4+1;
            switch (l){
                case 1: lt=36;
                break;
                case 2: lt=35;
                break;
                case 3: lt=38;
                break;
                case 4: lt=37;
                break;
            }
            printf("%c",lt);
            }
            printf("\n");
        }
    return 0;
}