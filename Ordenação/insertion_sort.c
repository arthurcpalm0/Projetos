#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int v[], int n){
    for
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
    selection_sort(v,10);
    print_array(v,10);
}