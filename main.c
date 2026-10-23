#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparEntrada() {
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }
}

int lerQuantidade() {
    int quantidade;
    while (1) {
        printf("Quantidade de estudantes (1 a 10): ");
        if (scanf("%d", &quantidade) != 1) {
            printf("Digite um numero inteiro.\n");
            limparEntrada();
        } else {
            limparEntrada();
            if (quantidade >= 1 && quantidade <= 10) {
                return quantidade;
            }
            printf("Quantidade invalida. Digite de 1 a 10.\n");
        }
    }
}

void lerNome(char nome[50]) {
    int valido;
    int i;
    while (1) {
        printf("Nome do estudante: ");
        if (fgets(nome, 50, stdin) == NULL) {
            exit(1);
        }
        if (strchr(nome, '\n') == NULL) {
            limparEntrada();
        }
        nome[strcspn(nome, "\n")] = '\0';

        valido = 0;
        for (i = 0; nome[i] != '\0'; i++) {
            if (nome[i] != ' ' && nome[i] != '\t') {
                valido = 1;
            }
        }
        if (valido == 1) {
            return;
        }
        printf("O nome nao pode ficar vazio.\n");
    }
}

float lerNota(int numero) {
    float nota;
    while (1) {
        printf("Nota %d (0 a 10): ", numero);
        if (scanf("%f", &nota) != 1) {
            printf("Digite um numero valido.\n");
            limparEntrada();
        } else {
            limparEntrada();
            if (nota >= 0 && nota <= 10) {
                return nota;
            }
            printf("Nota invalida. Digite de 0 a 10.\n");
        }
    }
}

void calcularMedias(float notas[10][3], float *medias, int quantidade) {
    int i, j;
    float soma;
    for (i = 0; i < quantidade; i++) {
        soma = 0;
        for (j = 0; j < 3; j++) {
            soma = soma + notas[i][j];
        }
        medias[i] = soma / 3.0f;
    }
}

void mostrarBoletim(char nomes[10][50], float notas[10][3], float *medias, int quantidade) {
    int i;
    float somaTurma = 0;
    float maiorMedia = medias[0];
    char *situacao;

    printf("\n================ BOLETIM DA TURMA ================\n");
    printf("%-20s %6s %6s %6s %7s  %s\n", "Nome", "Nota 1", "Nota 2", "Nota 3", "Media", "Situacao");
    for (i = 0; i < quantidade; i++) {
        if (medias[i] >= 6) {
            situacao = "Atingiu a meta";
        } else {
            situacao = "Abaixo da meta";
        }
        printf("%-20s %6.1f %6.1f %6.1f %7.2f  %s\n",
               nomes[i], notas[i][0], notas[i][1], notas[i][2], medias[i], situacao);
        somaTurma = somaTurma + medias[i];
        if (medias[i] > maiorMedia) {
            maiorMedia = medias[i];
        }
    }

    printf("\nMedia geral da turma: %.2f\n", somaTurma / quantidade);
    printf("Maior media: %.2f\n", maiorMedia);
    printf("Estudante(s) com maior media:\n");
    for (i = 0; i < quantidade; i++) {
        if (medias[i] == maiorMedia) {
            printf("- %s\n", nomes[i]);
        }
    }
}

int main() {
    int quantidade, i, j;
    float notas[10][3];
    char nomes[10][50];
    float *medias;

    printf("PROJETO: BOLETIM DE UMA PEQUENA TURMA\n\n");
    quantidade = lerQuantidade();

    medias = malloc(quantidade * sizeof(float));
    if (medias == NULL) {
        printf("Erro ao reservar memoria.\n");
        return 1;
    }
    for (i = 0; i < quantidade; i++) {
        medias[i] = 0;
    }

    for (i = 0; i < quantidade; i++) {
        printf("\nEstudante %d de %d\n", i + 1, quantidade);
        lerNome(nomes[i]);
        for (j = 0; j < 3; j++) {
            notas[i][j] = lerNota(j + 1);
        }
    }

    calcularMedias(notas, medias, quantidade);
    mostrarBoletim(nomes, notas, medias, quantidade);
    free(medias);
    return 0;
}
