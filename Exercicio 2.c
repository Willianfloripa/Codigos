#include <stdio.h>

int main() {
    int num;
    int a = 0, b = 1, temp;

    // Solicita ao usuario que informe um numero
    printf("Informe um numero para verificar se pertence a sequencia de Fibonacci: ");
    scanf("%d", &num);

    // Verifica se o numero e 0 ou 1 (os primeiros numeros da sequencia de Fibonacci)
    if (num == 0 || num == 1) {
        printf("O numero %d pertence a sequencia de Fibonacci.\n", num);
        return 0;
    }

    // Calcula a sequuencia de Fibonacci ate o número ser encontrado ou até ultrapassa-lo
    while (b < num) {
        temp = a + b;
        a = b;
        b = temp;
    }

    // Verifica se o número informado pertence a sequênncia
    if (b == num) {
        printf("O numero %d pertence a sequencia de Fibonacci.\n", num);
    } else {
        printf("O numero %d Nao pertence a sequencia de Fibonacci.\n", num);
    }

    return 0;
}
