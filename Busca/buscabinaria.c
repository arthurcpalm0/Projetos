#include <stdio.h>

int busca_binaria (int v[],int n, int c){
    int inicio = 0;
    int fim = n-1;
    int meio;
    while(inicio<=fim){
        meio = (inicio+fim)/2;
        if (v[meio]==c){
            return meio;
        }
        else if (v[meio]<c){
            inicio = meio+1;
        }
        else if (v[meio]>c){
            fim = meio-1;
        }
    }
    return -1;
}

int main(){
    int v[10]= {10,11,12,13,14,15,16,17,18,19};
    int chave;
    scanf("%d",&chave);
    int p = busca_binaria(v,10,chave);
    printf("%d", p);
}