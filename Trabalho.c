#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char titulo[100];
    char tipo[20];
    int ano;
    char genero[50];
    char classificacao[10];
    int duracao;
    int likes;
    int dislikes;
} Registro;

void cadastrar(Registro registros[], int *contador);
void consultar(Registro registros[], int contador);
void alterar(Registro registros[], int contador);
void remover(Registro registros[], int *contador);
void exibir(Registro registros[], int contador);

int main() {
    Registro registros[100];
    int contador = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar\n");
        printf("2. Consultar\n");
        printf("3. Alterar\n");
        printf("4. Remover\n");
        printf("5. Exibir\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar(registros, &contador);
                break;
            case 2:
                consultar(registros, contador);
                break;
            case 3:
                alterar(registros, contador);
                break;
            case 4:
                remover(registros, &contador);
                break;
            case 5:
                exibir(registros, contador);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
void cadastrar(Registro registros[], int *contador) {
    printf("Cadastrar um novo registro:\n");
    printf("Codigo: ");
    scanf("%d", &registros[*contador].codigo);
    printf("Titulo: ");
    scanf("%s", registros[*contador].titulo);
    printf("Tipo (serie ou filme): ");
    scanf("%s", registros[*contador].tipo);
    printf("Ano: ");
    scanf("%d", &registros[*contador].ano);
    printf("Genero: ");
    scanf("%s", registros[*contador].genero);
    printf("Classificacao indicativa: ");
    scanf("%s", registros[*contador].classificacao);
    printf("Duracao (minutos): ");
    scanf("%d", &registros[*contador].duracao);
    printf("Likes: ");
    scanf("%d", &registros[*contador].likes);
    printf("Dislikes: ");
    scanf("%d", &registros[*contador].dislikes);
    (*contador)++;
}
void consultar(Registro registros[], int contador) {
    int codigo;
    printf("Digite o codigo do registro a ser consultado: ");
    scanf("%d", &codigo);

    for (int i = 0; i < contador; i++) {
        if (registros[i].codigo == codigo) {
            printf("Titulo: %s\n", registros[i].titulo);
            printf("Tipo: %s\n", registros[i].tipo);
            printf("Ano: %d\n", registros[i].ano);
            printf("Genero: %s\n", registros[i].genero);
            printf("Classificacao indicativa: %s\n", registros[i].classificacao);
            printf("Duracao: %d minutos\n", registros[i].duracao);
            printf("Likes: %d\n", registros[i].likes);
            printf("Dislikes: %d\n", registros[i].dislikes);
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}
void alterar(Registro registros[], int contador) {
    int codigo;
    printf("Digite o codigo do registro a ser alterado: ");
    scanf("%d", &codigo);

    for (int i = 0; i < contador; i++) {
        if (registros[i].codigo == codigo) {
            printf("Digite os novos dados para o registro:\n");
            printf("Titulo: ");
            scanf("%s", registros[i].titulo);
            printf("Tipo (serie ou filme): ");
            scanf("%s", registros[i].tipo);
            printf("Ano: ");
            scanf("%d", &registros[i].ano);
            printf("Genero: ");
            scanf("%s", registros[i].genero);
            printf("Classificacao indicativa: ");
            scanf("%s", registros[i].classificacao);
            printf("Duracao (minutos): ");
            scanf("%d", &registros[i].duracao);
            printf("Likes: ");
            scanf("%d", &registros[i].likes);
            printf("Dislikes: ");
            scanf("%d", &registros[i].dislikes);
            printf("Registro alterado com sucesso.\n");
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}
void remover(Registro registros[], int *contador) {
    int codigo;
    printf("Digite o codigo do registro a ser removido: ");
    scanf("%d", &codigo);

    for (int i = 0; i < *contador; i++) {
        if (registros[i].codigo == codigo) {
            for (int j = i; j < *contador - 1; j++) {
                registros[j] = registros[j + 1];
            }
            (*contador)--;
            printf("Registro removido com sucesso.\n");
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}

void exibir(Registro registros[], int contador) {
    printf("Exibindo todos os registros:\n");
    for (int i = 0; i < contador; i++) {
        printf("Codigo: %d\n", registros[i].codigo);
        printf("Titulo: %s\n", registros[i].titulo);
        printf("Tipo: %s\n", registros[i].tipo);
        printf("Ano: %d\n", registros[i].ano);
        printf("Genero: %s\n", registros[i].genero);
        printf("Classificacao indicativa: %s\n", registros[i].classificacao);
        printf("Duracao: %d minutos\n", registros[i].duracao);
        printf("Likes: %d\n", registros[i].likes);
        printf("Dislikes: %d\n", registros[i].dislikes);
        printf("\n");
    }
}
