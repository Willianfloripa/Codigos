#include <stdio.h>
#include <string.h>

void inverterString(char str[]) {
    int inicio = 0;
    int fim = strlen(str) - 1;
    char temp;

    // Troca os caracteres de início e fim até o meio da string
    while (inicio < fim) {
        // Troca os caracteres
        temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;
        
        // Move os índices
        inicio++;
        fim--;
    }
}

int main() {
    char str[100];  // Buffer para a string

    // Leitura da string do usuário
    printf("Digite a um nome ou conjunto de numerio ex. 12345 ou Target para a string inverter: ");
    fgets(str, sizeof(str), stdin);

    // Remove o caractere de nova linha, se presente
    str[strcspn(str, "\n")] = '\0';

    // Inverte a string
    inverterString(str);

    // Exibe a string invertida
    printf("String invertida: %s\n", str);

    return 0;
}
