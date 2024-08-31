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

    // Calcula a sequuencia de Fibonacci ate o n�mero ser encontrado ou at� ultrapassa-lo
    while (b < num) {
        temp = a + b;
        a = b;
        b = temp;
    }

    // Verifica se o n�mero informado pertence a sequ�nncia
    if (b == num) {
        printf("O numero %d pertence a sequencia de Fibonacci.\n", num);
    } else {
        printf("O numero %d Nao pertence a sequencia de Fibonacci.\n", num);
    }

    return 0;
}
