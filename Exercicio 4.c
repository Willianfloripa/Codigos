#include <stdio.h>

int main() {
    // Valores de faturamento por estado
    double faturamento_SP = 67836.43;
    double faturamento_RJ = 36678.66;
    double faturamento_MG = 29229.88;
    double faturamento_ES = 27165.48;
    double faturamento_Outros = 19849.53;

    // Calcula o faturamento total
    double total_faturamento = faturamento_SP + faturamento_RJ + faturamento_MG + faturamento_ES + faturamento_Outros;

    // Calcula e exibe o percentual de representação de cada estado
    printf("Percentual de Representacao por Estado:\n");
    printf("SP: %.2f%%\n", (faturamento_SP / total_faturamento) * 100);
    printf("RJ: %.2f%%\n", (faturamento_RJ / total_faturamento) * 100);
    printf("MG: %.2f%%\n", (faturamento_MG / total_faturamento) * 100);
    printf("ES: %.2f%%\n", (faturamento_ES / total_faturamento) * 100);
    printf("Outros: %.2f%%\n", (faturamento_Outros / total_faturamento) * 100);

    return 0;
}
