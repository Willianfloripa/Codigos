#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define MAX_DIAS 31

typedef struct {
    double valor;
} Faturamento;

Faturamento faturamentos[MAX_DIAS];
int total_dias = 0;

void ler_faturamento(const char *arquivo) {
    FILE *file = fopen(arquivo, "r");
    if (!file) {
        perror("Nao foi possivel abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        // Verificar se a linha contém a tag <valor>
        char *start = strstr(linha, "<valor>");
        if (start) {
            start += 7;  // Pular a tag <valor>
            char *end = strstr(start, "</valor>");
            if (end) {
                *end = '\0';  // Terminar a string no fim da tag
                faturamentos[total_dias].valor = atof(start);
                total_dias++;
            }
        }
    }

    fclose(file);
}

void calcular_faturamento(double *menor_valor, double *maior_valor, int *dias_acima_media) {
    double soma = 0.0;
    int dias_validos = 0;

    *menor_valor = DBL_MAX;
    *maior_valor = -DBL_MAX;

    for (int i = 0; i < total_dias; i++) {
        if (faturamentos[i].valor > 0) {
            if (faturamentos[i].valor < *menor_valor) {
                *menor_valor = faturamentos[i].valor;
            }
            if (faturamentos[i].valor > *maior_valor) {
                *maior_valor = faturamentos[i].valor;
            }
            soma += faturamentos[i].valor;
            dias_validos++;
        }
    }

    if (dias_validos == 0) {
        fprintf(stderr, "Nao ha¡ dados validos de faturamento.\n");
        exit(EXIT_FAILURE);
    }

    double media_mensal = soma / dias_validos;
    *dias_acima_media = 0;

    for (int i = 0; i < total_dias; i++) {
        if (faturamentos[i].valor > media_mensal) {
            (*dias_acima_media)++;
        }
    }
}

int main() {
    double menor_valor, maior_valor;
    int dias_acima_media;

    ler_faturamento("faturamento.xml");
    calcular_faturamento(&menor_valor, &maior_valor, &dias_acima_media);

    printf("Menor valor de faturamento: R$%.2f\n", menor_valor);
    printf("Maior valor de faturamento: R$%.2f\n", maior_valor);
    printf("Numero de dias com faturamento acima da media: %d\n", dias_acima_media);

    return 0;
}
