#include <stdio.h>

typedef struct {
    char estado;
    char codigo[5];
    char nome_cidade[100];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

void registrarCarta(Carta *c) {
    printf("\nDigite os dados da carta:\n");

    /* Estado validado (A-H) */
    do {
        printf("Estado (A-H): ");
        scanf(" %c", &c->estado);
    } while (c->estado < 'A' || c->estado > 'H');

    /* Limite de leitura para evitar overflow */
    printf("Código da Carta (ex: A01): ");
    scanf("%4s", c->codigo);

    printf("Nome da Cidade: ");
    scanf(" %99[^\n]", c->nome_cidade);

    printf("População: ");
    scanf("%d", &c->populacao);
    if (c->populacao < 0) c->populacao = 0;

    printf("Área (em km²): ");
    scanf("%f", &c->area);
    if (c->area < 0) c->area = 0;

    printf("PIB: ");
    scanf("%f", &c->pib);
    if (c->pib < 0) c->pib = 0;

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c->pontos_turisticos);
    if (c->pontos_turisticos < 0) c->pontos_turisticos = 0;
}

void exibirCarta(const Carta *c) {
    printf("\nInformações da carta:\n");
    printf("Estado: %c\n", c->estado);
    printf("Código da Carta: %s\n", c->codigo);
    printf("Nome da Cidade: %s\n", c->nome_cidade);
    printf("População: %d\n", c->populacao);
    printf("Área: %.2f km²\n", c->area);
    printf("PIB: %.2f\n", c->pib);
    printf("Número de Pontos Turísticos: %d\n", c->pontos_turisticos);
}

int main() {
    Carta cartas[2];

    for (int i = 0; i < 2; i++) {
        printf("\nRegistrando carta %d:\n", i + 1);
        registrarCarta(&cartas[i]);
    }

    printf("\nExibindo as cartas registradas:\n");
    for (int i = 0; i < 2; i++) {
        printf("\nCarta %d:\n", i + 1);
        exibirCarta(&cartas[i]);
    }

    return 0;
}
