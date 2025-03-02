#include <stdio.h>
#include <time.h>

// Definido estrutura para armazenar os dados da carta
struct Carta {
    char estado; // Colocar de A ate H
    char codigo[4]; // Exemplo: "A01"
    char nomeCidade[50];
    int populacao; 
    float area; // em km²
    float pib; // em bilhões
    int pontosTuristicos;
};

int main() {
    // Array para armazenar duas cartas
    struct Carta cartas[2];
    time_t t;
    struct tm *tm_info;
    
   // Configurar fuso horário UTC -3 (Brasília)
   #ifdef _WIN32
   _putenv("TZ=UTC-3");
#else
   setenv("TZ", "America/Sao_Paulo", 1);
#endif
tzset(); // Atualiza o fuso horário

// Captura a data e a hora atuais
time(&t);
tm_info = localtime(&t);
    

    // Criando Loop para capturar os dados das duas cartas
    for (int i = 0; i < 2; i++) {
        printf("\n=== Cadastro da Carta %d ===\n", i + 1);

        // Captura do estado
        printf("Digite a letra do estado (A-H): ");
        scanf(" %c", &cartas[i].estado);

        // Captura do código da carta
        printf("Digite o código da carta (Ex: A01): ");
        scanf("%s", cartas[i].codigo);

        // Captura do nome da cidade
        printf("Digite o nome da cidade: ");
        scanf(" %[^\n]", cartas[i].nomeCidade);// Lendo espaços 

        // Captura da população
        printf("Digite a populacao da cidade: ");
        scanf("%d", &cartas[i].populacao);

        // Captura da área
        printf("Digite a area da cidade(km²): ");
        scanf("%f", &cartas[i].area);

        // Captura do PIB
        printf("Digite o PIB da cidade (em bilhões): ");
        scanf("%f", &cartas[i].pib);

        // Captura do número de pontos turísticos
        printf("Digite o número de pontos turisticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);
    }

    // Exibição dos dados cadastrados
    printf("\n======= Cartas Cadastradas =======\n");
    for (int i = 0; i < 2; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Código: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].nomeCidade);
        printf("População: %d habitantes\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões de reais\n", cartas[i].pib);
        printf("Número de Pontos Turísticos: %d\n", cartas[i].pontosTuristicos);
    }
    
    // Exibição da data e hora no formato brasileiro
    printf("\nData: %02d/%02d/%d\n", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900);
    printf("Hora: %02d:%02d\n", tm_info->tm_hour, tm_info->tm_min);
    
    return 0;
}
