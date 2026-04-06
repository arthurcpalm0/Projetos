#include <stdio.h>

void merge (float v1[],int n1,float v2[],int n2, float dest[]){
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
void merge_sort(float v[], int n){
    if (n<2){
        return;
    }
    int meio = n/2;
    int n1 = meio;
    float v1[n1];
    for (int i = 0;i<n1;i++){
        v1[i] = v[i];
    }
    int n2 = n-meio;
    float v2[n2];
    for (int i=0; i< n2; i++){
        v2[i]=v[meio + i];
    }
    merge_sort(v1,n1);
    merge_sort(v2,n2);
    merge(v1,n1,v2,n2,v);

}

float busca_binaria(float v[], int n, float chave){
    int inicio = 0;
    int fim = n-1;
    int meio;
    while (inicio<=fim){
        meio = (inicio + fim)/2;
        if (v[meio]>chave){
            fim = meio-1;
        }
        else if(v[meio]<chave){
            inicio = meio+1;
        }
        else{
            return v[meio];
        }
    }
    return -1;
}

int main(){
    float v[] = {76,66,23,45,5};
    for (int i=0; i<5; i++){
        printf("%f\t",v[i]);
    }
    float x, r1, r2;
    printf("\nIngresse um número:\n");
    scanf("%f", &x);
    merge_sort(v, 5);
    for(int i=0;i<5;i++){
        r1 = busca_binaria(v,5,x-v[i]);
        if (r1!=-1){
            r2 = v[i];
            break;
        }
    }
    if (r1 == -1){
        printf("Número inválido\n");
        return -1;
    }
    else{
        printf("%f + %f = %f(Seu numero)\n",r1,r2,x);
    }
    return 0;
}