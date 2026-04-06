#include <stdio.h>

int main(){
    float v[] = {1,2,3,4,5,6,7,8,9,10};
    for (int i=0; i<10; i++){
        printf("%f\t",v[i]);
    }
    float x, r1, r2;
    printf("\nIngresse um número:\n");
    scanf("%f",&x);
    int inicio = 0;
    int fim = 9;
    while (inicio<=fim){
        float soma = v[inicio] + v[fim];
        if (soma == x) {
        printf("%f + %f = %f\n", v[inicio], v[fim], x);
        return 0;
        }
        if (soma < x) inicio++;
        else fim--;
    }
    return 0;
}