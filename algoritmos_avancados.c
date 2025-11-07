#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.

//Struct Sala
typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

Sala* criarSala(char* nome) {
    Sala* nova = (Sala*)malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

void conectarSalas(Sala* origem, Sala* esquerda, Sala* direita) {
    if (origem == NULL) return;
    origem->esquerda = esquerda;
    origem->direita = direita;
}

void explorarSalas(Sala* sala) {
    if (sala == NULL) return;

    printf("\nVocê entrou na sala: %s\n", sala->nome);

    // Se for folha, não há para onde ir
    if (sala->esquerda == NULL && sala->direita == NULL) {
        printf("Fim do caminho.\n");
        return;
    }

    char opcao;
    do {
        printf("Escolha uma direção (e = esquerda, d = direita, s = sair): ");
        scanf(" %c", &opcao);

        if (opcao == 'e' && sala->esquerda != NULL) {
            explorarSalas(sala->esquerda);
            break;
        } else if (opcao == 'd' && sala->direita != NULL) {
            explorarSalas(sala->direita);
            break;
        } else if (opcao == 's') {
            printf("Saindo da exploração desta sala...\n");
            break;
        } else {
            printf("Opção inválida ou caminho não disponível!\n");
        }
    } while (1);
}



int main() {

    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    //
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

    //Criando salas
    Sala* hall = criarSala("Hall de Entrada");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* cozinha = criarSala("Cozinha");
    Sala* sotao = criarSala("Sótão");
    Sala* jardim = criarSala("Jardim");

    //Conectando salas
    conectarSalas(hall, biblioteca, cozinha);
    conectarSalas(biblioteca, sotao, NULL);
    conectarSalas(cozinha, NULL, jardim);

    //Início da exploração
    printf("Bem-vindo ao Detective Quest - Mansão Misteriosa!\n");
    explorarSalas(hall);

    printf("Exploração finalizada.\n");

    // Liberar memória
    free(sotao);
    free(jardim);
    free(biblioteca);
    free(cozinha);
    free(hall);


    return 0;
}

