#include <stdio.h>

void merge (int v1[],int n1,int v2[],int n2, int dest[]){
    int i1=0;
    int i2=0;
    int i=0;
    while(i1<n1&&i2<n2){
        if (v1[i1]<v2[i2]){
            dest[i] = v1[i1];
            i1++;
        }
        else {
            dest [i] = v2[i2];
            i2++;
        }
        i++;
    }
    while (i1<n1){
        dest[i] = v1[i1];
        i1++;
        i++;
    }
    while (i2<n2){
        dest[i] = v2[i2];
        i2++;
        i++;
    }
}
void merge_sort(int v[], int n){
    if (n<2){
        return;
    }
    int meio = n/2;
    int n1 = meio;
    int v1[n1];
    for (int i = 0;i<n1;i++){
        v1[i] = v[i];
    }
    int n2 = n-meio;
    int v2[n2];
    for (int i=0; i< n2; i++){
        v2[i]=v[meio + i];
    }
    merge_sort(v1,n1);
    merge_sort(v2,n2);
    merge(v1,n1,v2,n2,v);

}
void print_array(int v[], int n){
    for (int i=0;i<n;i++){
        printf("%d\t",v[i]);
    }
}
int main(){
    int v[]= {22,64,37,51,25,88,19,2,34,67};
    merge_sort(v,10);
    print_array(v,10);
    return 0;
}