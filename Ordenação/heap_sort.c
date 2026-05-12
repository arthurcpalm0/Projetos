#include <stdio.h>

void heapify(int v[], int n, int i){
    int raiz = i;
    int esq = 2*i + 1;
    int dir = 2*i + 2;

    if (esq < n && v[esq] > v[raiz]){
        raiz = esq;
    }

    if (dir < n && v[dir] > v[raiz]){
        raiz = dir;
    }

    if (raiz != i){
        int temp = v[i];
        v[i] = v[raiz];
        v[raiz] = temp;

        heapify(v, n, raiz);
    }
}

void heap_sort(int v[], int n){
    for (int i = n/2 - 1; i >= 0; i--){
        heapify(v, n, i);
    }
    for (int i = n - 1; i > 0; i--){
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;

        heapify(v, i, 0);
    }
}

void print_array(int v[], int n){
    for (int i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

int main(){
    int v[10] = {9,8,7,6,5,4,3,2,1,0};
    print_array(v, 10);
    heap_sort(v, 10);
    printf("Vetor ordenado: \n");
    print_array(v,10);
    return 0;
}