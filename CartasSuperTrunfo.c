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
    
    printf("Estado (A-H): ");
    scanf(" %c", &c->estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", c->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c->nome_cidade);

    printf("População: ");
    scanf("%d", &c->populacao);

    printf("Área (em km²): ");
    scanf("%f", &c->area);

    printf("PIB: ");
    scanf("%f", &c->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c->pontos_turisticos);
}

void exibirCarta(Carta c) {
    printf("\nInformações da carta:\n");
    printf("Estado: %c\n", c.estado);
    printf("Código da Carta: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.nome_cidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f\n", c.pib);
    printf("Número de Pontos Turísticos: %d\n", c.pontos_turisticos);
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
        exibirCarta(cartas[i]);
    }

    return 0;
}
