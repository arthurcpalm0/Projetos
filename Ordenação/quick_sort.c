#include <stdio.h>

int particionar(int v[], int inicio, int fim, int ip){
    int pivo = v[ip];
    int esq = inicio;
    int dir = fim - 1;
    while (esq<=dir){
        while (esq<=dir && v[esq]<=pivo){
            ++esq;
        }
        while (esq <= dir && v[dir]>=pivo){
            --dir;
        }
        if (esq<dir){
            int temp = v[dir];
            v[dir] = v[esq];
            v[esq] = temp;
        }
    }
    int nova_posicao_pivo = esq;
    int temp = v[ip];
    v[ip] = v[nova_posicao_pivo];
    v[nova_posicao_pivo] = temp;
    return nova_posicao_pivo;
}

void quick_sort(int v[], int inicio, int fim){
    if (inicio>=fim){
        return;
    }
    int ip = fim;
    ip = particionar(v, inicio, fim, ip);
    quick_sort(v,inicio,ip-1);
    quick_sort(v,ip+1,fim);
}
void print_array(int v[], int n){
    for (int i=0;i<n;i++){
        printf("%d\t",v[i]);
    }
}
int main(){
    int v[]= {22,64,37,51,25,88,19,2,34,67};
    quick_sort(v,0,9);
    print_array(v,10);
    return 0;
}