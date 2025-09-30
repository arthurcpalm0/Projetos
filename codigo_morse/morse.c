#include <stdio.h>   
#include <string.h>

char *morse[] = {  // Array de strings representando o código Morse das letras A-Z
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",  
    "..-", "...-", ".--", "-..-", "-.--", "--.."                           
};

char traduzir (char codigo[]){
    for (int i=0; i<26;i++){
        if (strcmp(morse[i],codigo)==0){
            return 'A'+i;
        }
    }
    return ' ';
}
void sugestao(char codigo[]){
    printf("[");
    for (int i=0;i<26;i++){
        if (strncmp(morse[i],codigo,strlen(codigo))==0){
            printf("%c", 'A'+i);
        }
    }
    printf ("]");
}
void separar_string(char v[], int n){
    char codigo[10];
    int cont = 0;
    int espacos = 0;
    for (int i=0;v[i]!='\0';i++){
        if (v[i]=='.'||v[i]=='-'){
            codigo[cont++]=v[i];
            codigo[cont]='\0';
            espacos = 0;
        }
        else if(v[i]=='*'){
            codigo[cont]='\0';
            sugestao(codigo);
            cont = 0;
            codigo[0]='\0';
        }
        else if(v[i]==' '){
            if (cont>0){
            printf("%c",traduzir(codigo));
            cont=0;
            codigo[0]='\0';
            }
        espacos++;
        if (espacos==2){
            printf(" ");
            espacos = 0;
        }
    }
    }
    if(cont>0){
        printf("%c",traduzir(codigo));
    }
}

int main(){
    char v[200];
    printf("Digite o codigo Morse (1 espaco = letra, 2 espacos = palavra):\n");
    fgets(v,sizeof(v),stdin);
    v[strcspn(v,"\n")]='\0';
    separar_string(v,200);
}