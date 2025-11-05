#include <stdio.h>
#include <string.h>

int main(){
    FILE *file;
    file = fopen("exemplo.pbm","r");
    char tipo[3];
    fscanf(file,"%s",tipo);
    if (file==NULL||strcmp(tipo,"P1")!=0){
        printf("Arquivo Invalido\n");
        return 1;
    }
    int parametros[2];
    for (int i=0;i<2;i++){
        fscanf(file,"%d", &parametros[i]);
    }
    int matriz[parametros[1]][parametros[0]];
    for (int i=0;i<parametros[1];i++){
        for (int j=0;j<parametros[0];j++){
        fscanf(file,"%d",&matriz[i][j]);
        }
    }
    for (int i=0;i<parametros[1];i++){
        for (int j=0;j<parametros[0];j++){
        printf("%d\t",matriz[i][j]);
        }
        printf("\n");
    }
    fclose(file);
    return 0;
}