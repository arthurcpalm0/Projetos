#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int v[], int n){
    for (int i=1;i<n;i++){
        int chave = v[i];
        int j = i-1;
        while (j>=0 && chave<v[j]){
            if (v[j]>chave){
                v[j+1] = v[j];
            }
            j--;
        }
        v[j+1] = chave;
    }
}

void print_array(int v[], int n){
    for (int i=0;i<n;i++){
        printf("%d\t",v[i]);
    }
}

int main(){
    srand(time(NULL));
    int v[10];
    for (int i=0;i<10;i++){
        v[i]=rand()%50+1;
    }
    insertion_sort(v,10);
    print_array(v,10);
}