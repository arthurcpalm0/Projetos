#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubble_sort(int v[], int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if (v[j]>v[j+1]){
                int temp;
                temp = v[j];
                v[j] = v[j+1];
                v[j+1]=temp;
            }
        }
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
    bubble_sort(v,10);
    print_array(v,10);
}