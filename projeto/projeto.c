// Arthur Candido Palma RA: 10743580
// Kauê Cordeiro Abreu RA: 10741435
// Gabriel Pereira de Souza RA: 10440766
// Link do Video: https://youtu.be/YlpGj-bjlVI

#include <stdio.h>
#include <string.h>

#define LARGURA_MAX 1024
#define ALTURA_MAX 768
int img[ALTURA_MAX][LARGURA_MAX];


//-----------------------------------------------------
// Exibe o menu de ajuda
//-----------------------------------------------------
void menu() {
    printf("Uso: ImageEncoder [-? | -m | -f ARQ]\n");
    printf("Codifica imagens binárias dadas em arquivos PBM ou por dados informados manualmente.\n\n");
    printf("Argumentos:\n");
    printf("  -?, --help   : apresenta essa orientação na tela.\n");
    printf("  -m, --manual : ativa o modo de entrada manual, em que o usuário fornece todos os dados da imagem informando-os através do teclado.\n");
    printf("  -f, --file   : considera a imagem representada no arquivo PBM (Portable Bitmap).\n");
}

//-----------------------------------------------------
// Verifica se a subimagem é homogênea (toda 0 ou toda 1)
//-----------------------------------------------------
int imagemHomogenea(int img[ALTURA_MAX][LARGURA_MAX],
                    int x0, int y0, int largura, int altura) {
    int cor = img[y0][x0];
    for (int i = y0; i < y0 + altura; i++) {
        for (int j = x0; j < x0 + largura; j++) {
            if (img[i][j] != cor)
                return 0; // misturada
        }
    }
    return 1; // homogênea
}

//-----------------------------------------------------
// Função recursiva que codifica os quadrantes
//-----------------------------------------------------
void codificar(int img[ALTURA_MAX][LARGURA_MAX],
               int x0, int y0, int largura, int altura) {
    if (imagemHomogenea(img, x0, y0, largura, altura)) {
        if (img[y0][x0] == 1)
            printf("P");
        else
            printf("B");
        return;
    }

    printf("X"); // imagem mista, precisa dividir

    int meioL = largura / 2;
    int meioA = altura / 2;
    int largEsq = meioL + (largura % 2);
    int altSup = meioA + (altura % 2);

    // 1º quadrante – superior esquerdo
    codificar(img, x0, y0, largEsq, altSup);

    // 2º quadrante – superior direito
    codificar(img, x0 + largEsq, y0, largura - largEsq, altSup);

    // 3º quadrante – inferior esquerdo
    codificar(img, x0, y0 + altSup, largEsq, altura - altSup);

    // 4º quadrante – inferior direito
    codificar(img, x0 + largEsq, y0 + altSup, largura - largEsq, altura - altSup);
}

//-----------------------------------------------------
// Leitura manual da imagem
//-----------------------------------------------------
int lerManual(int img[ALTURA_MAX][LARGURA_MAX],
               int *largura, int *altura) {
    printf("Digite a largura da imagem (max 1024): ");
    scanf("%d", largura);
    printf("Digite a altura da imagem (max 768): ");
    scanf("%d", altura);

    printf("\nPreencha a imagem (0 = branco, 1 = preto)\n");
    for (int i = 0; i < *altura; i++) {
        for (int j = 0; j < *largura; j++) {
            printf("Pixel [%d][%d]: ", i, j);
            scanf("%d", &img[i][j]);
            if (img[i][j] != 0 && img[i][j] != 1) {
                printf("Erro: só é permitido 0 ou 1.\n");
                return 1;
            }
        }
    }

    printf("\nImagem digitada:\n");
    for (int i = 0; i < *altura; i++) {
        for (int j = 0; j < *largura; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

//-----------------------------------------------------
// Leitura de imagem a partir de arquivo PBM (modo texto P1)
//-----------------------------------------------------
int lerArquivoPBM(int img[ALTURA_MAX][LARGURA_MAX],
                  int *largura, int *altura, const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo '%s'.\n", nomeArquivo);
        return 1;
    }

    char tipo[3];
    fscanf(file, "%2s", tipo);

    if (strcmp(tipo, "P1") != 0) {
        printf("Arquivo inválido: formato não é P1.\n");
        fclose(file);
        return 1;
    }

    // Ignora linhas de comentários começando com '#'
    int c = fgetc(file);
    while (c == '#') {
        while (fgetc(file) != '\n');
        c = fgetc(file);
    }
    ungetc(c, file);

    fscanf(file, "%d %d", largura, altura);

    for (int i = 0; i < *altura; i++) {
        for (int j = 0; j < *largura; j++) {
            fscanf(file, "%d", &img[i][j]);
        }
    }

    fclose(file);
    return 0;
}

//-----------------------------------------------------
// Função principal
//-----------------------------------------------------
int main(int argc, char *argv[]) {
    
    int largura = 0, altura = 0;

    if (argc == 1) {
        menu();
        return 0;
    }

    if (strcmp(argv[1], "-?") == 0 || strcmp(argv[1], "--help") == 0) {
        menu();
        return 0;
    }

    else if (strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "--manual") == 0) {
        if (lerManual(img, &largura, &altura) == 0) {
            printf("\nCódigo gerado: ");
            codificar(img, 0, 0, largura, altura);
            printf("\n");
        }
    }

    else if (strcmp(argv[1], "-f") == 0 || strcmp(argv[1], "--file") == 0) {
        if (argc < 3) {
            printf("Erro: faltou informar o nome do arquivo após -f.\n");
            return 1;
        }
        if (lerArquivoPBM(img, &largura, &altura, argv[2]) == 0) {
            printf("\nCódigo gerado: ");
            codificar(img, 0, 0, largura, altura);
            printf("\n");
        }
    }

    else {
        printf("Erro: parâmetro inválido '%s'. Use -? para ajuda.\n", argv[1]);
    }

    return 0;
}