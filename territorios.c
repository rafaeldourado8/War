#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes Globais ----

#define MAX_TERRITORIOS 5
#define TAMANHO_STRING 20 

// -- Territorio --
struct territorios
{
    char nome[TAMANHO_STRING];
    char cor[TAMANHO_STRING];
    int tropa;
};

// --- limpando o buffer ---
void ClearBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

// --- Funcao para cadastrar os territorios ---
void cadastrar_territorios(struct territorios novo_territorio[], int max_territorios) {
    printf("============================================================\n");
    printf("  Vamos cadastrar os %d territorios iniciais no nosso mundo. \n", max_territorios);
    printf("============================================================\n\n");

    for (int i = 0; i < max_territorios; i++) {
        printf("---- Cadastro Territorio %d de %d ----\n", i + 1, max_territorios);

        // Nome
        printf("Nome do Territorio (max %d caracteres): ", TAMANHO_STRING - 1);
        // fgets é mais seguro que scanf para strings, mas exige tratamento para remover o '\n'
        if (fgets(novo_territorio[i].nome, TAMANHO_STRING, stdin) != NULL) {
            // Remove o newline (caractere de nova linha) lido por fgets
            novo_territorio[i].nome[strcspn(novo_territorio[i].nome, "\n")] = 0;
        }

        // Cor
        printf("Cor do Exercito (ex: Azul, Verde, max %d caracteres): ", TAMANHO_STRING - 1);
        if (fgets(novo_territorio[i].cor, TAMANHO_STRING, stdin) != NULL) {
            novo_territorio[i].cor[strcspn(novo_territorio[i].cor, "\n")] = 0;
        }

        // Tropas
        printf("Numero de Tropas: ");
        if (scanf("%d", &novo_territorio[i].tropa) != 1) {
            printf("Erro na leitura das tropas. Usando 0.\n");
            novo_territorio[i].tropa = 0;
        }
        ClearBuffer(); // Limpa o buffer após o scanf

        printf("--- Territorio %d Cadastrado ---\n\n", i + 1);
    }
}

// --- Funcao para exibir os territorios ---
void exibir_territorios(const struct territorios novo_territorio[], int total_territorios) {
    printf("\n============================================================\n");
    printf("             Territorios Cadastrados                        \n");
    printf("============================================================\n");
    for (int i = 0; i < total_territorios; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("  Nome: %s\n", novo_territorio[i].nome);
        printf("  Cor: %s\n", novo_territorio[i].cor);
        printf("  Tropas: %d\n", novo_territorio[i].tropa);
        printf("------------------------------------------------------------\n");
    }
}

// --- Funcao principal ---

int main(void) {
    struct territorios novo_territorio[MAX_TERRITORIOS];
    int total_territorio = MAX_TERRITORIOS; 
    
    // Chama a função de cadastro
    cadastrar_territorios(novo_territorio, MAX_TERRITORIOS);
    
    // Chama a função para exibir os resultados
    exibir_territorios(novo_territorio, total_territorio);

    return 0; 
}