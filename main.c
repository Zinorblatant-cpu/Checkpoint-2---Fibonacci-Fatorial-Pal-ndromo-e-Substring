#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
 
 
void SequenciaDeFibonacci() {
    printf("1 - Sequência de Fibonacci;\n");
    int i;
    int termo_anterior1;
    int termo_anterior2;
    int termo_atual;
    int vetor_fibonacci[50];
    int numero_termo;
 
    termo_anterior1 = 1;
    termo_anterior2 = 0;
 
    printf("Digite o numero de termos da sequencia de Fibonacci (1 a 50): ");
    scanf("%d", &numero_termo);
 
    if (numero_termo < 1 || numero_termo > 50){
        printf("Erro, Digite um numero entre 1 e 50.\n");
        return;
    }
    vetor_fibonacci[0] = termo_anterior2;
    if (numero_termo > 1){
    vetor_fibonacci[1] = termo_anterior1;
    }
 
    for (i = 2; i < numero_termo; i++){
        termo_atual = termo_anterior2 + termo_anterior1;
        vetor_fibonacci[i] = termo_atual;
        termo_anterior2 = termo_anterior1;
        termo_anterior1 = termo_atual;
 
    }
    printf("\nSequencia de Fibonacci: ");
    for (i = 0; i < numero_termo; i++){
        printf("%d ", vetor_fibonacci[i]);
    }
    printf("\n");
    return;
}
 
void Fatoriais() {
    int num;
    int vetor[21];  // índice vai até 20, então precisa de espaço suficiente
    int i;
    vetor[0] = 1;
 
    printf("2 - Fatoriais;\n");
    printf("Digite um número entre 1 a 20: \n");
 
    scanf("%d", &num);
 
    if (num < 1 || num > 20) {
        printf("Erro, Digite um numero entre 1 e 20.\n");
        return;
    }
 
    for (i = 1; i <= num; ++i){
        vetor[i] = vetor[i - 1] * i;
    }
 
    printf("Fatoriais: \n");
    for (i = 1; i <= num; ++i){
        printf("%d! = %d\n", i, vetor[i]);
    }
 
    printf("\n");
}

void VerificarPalindromo() {
    char texto[80], texto_invertido[80];
    int i, j, fim;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
 
    printf("3 - Verificar Palíndromo;\n");
    printf("Insira uma palavra: ");
    fgets(texto, 80, stdin);
    texto[strcspn(texto, "\n")] = '\0'; // remove o \n da entrada
 
    fim = strlen(texto); // calcula o tamanho real da string
 
    i = fim - 1;
    j = 0;
    while (j < fim) {
        texto_invertido[j] = texto[i];
        i--;
        j++;
    }
 
    texto_invertido[fim] = '\0'; // finaliza string invertida
    printf("Inverso: %s\n", texto_invertido);
    if (strcmp(texto, texto_invertido) == 0) {
        printf("É um palíndromo!\n");
    } else {
        printf("Não é um palíndromo.\n");
    }
}
 

 
int menu() {
    int x;
    printf("===== MENU DE EXERCÍCIOS =====\n");
    printf("1 - Sequência de Fibonacci;\n");
    printf("2 - Fatoriais;\n");
    printf("3 - Verificar Palíndromo;\n");
    printf("4 - Verificar Substring.\n");
    scanf("%d", &x);
 
    switch (x) {
        case 1:
            SequenciaDeFibonacci();
            break;
 
        case 2:
            Fatoriais();
            break;
 
        case 3:
            VerificarPalindromo();
            break;
        case 4:
            VerificarSubstring();
            break;
 
        default:
            printf("Opção inválida.\n");
            break;
    }
    return 0;
 
}
 
int main() {
    setlocale(LC_ALL, "");
    menu();
    return 0;
 
}