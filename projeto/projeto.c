#include <stdio.h>

#include <stdio.h>
#include <string.h>

int entrada_pbm(int parametros[]){
    FILE *file;
    file = fopen("exemplo.pbm","r");
    char tipo[3];
    fscanf(file,"%s",tipo);
    if (file==NULL||strcmp(tipo,"P1")!=0){
        printf("Arquivo Invalido\n");
        return 1;
    }
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
    return matriz;
}
char verificação(int parametros[],int matriz[parametros[1]][parametros[0]]){
    int cont=0;
    for (int i=0;i<parametros[1];i++){
        for (int j=0;j<parametros[0];j++){
            cont = cont + matriz[i][j];
        }
    }
    if (cont==0){
        return 'B';
    }
    else if (cont == parametros[1]*parametros[0]){
        return 'P';
    }
    else{
        return 'X';
    }
}
int recursao(int parametros[], int matriz[parametros[1]][parametros[0]]){
    if (parametros[0]%2==0&&parametros[1]%2==0){
        
    }
}
int main(){
    int parametros[2];
    if (entrada_pbm(parametros)==1){
        return 1;
    }
    else{
        return 0;
    }
    verificação(parametros,entrada_pbm);
    if (verificação=='X'){
        recursao(parametros,entrada_pbm);
    }
    return 0;
}