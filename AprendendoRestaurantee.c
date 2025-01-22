#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída, necessária para usar funções como printf e scanf
#include <stdlib.h> // Inclui a biblioteca padrão de funções utilitárias como system e malloc
#include <locale.h> // Inclui a biblioteca para configurar as informações regionais, permitindo o uso de caracteres especiais
#include <string.h> // Manipulação de string; fornecem funções como printf, gets, strlen, strcpy etc

#define NUM_DIAS 4
#define MAX_RESERVAS 40

typedef struct {
	char nome[50];
	char cpf[15];
	int dia;
	int numPessoas;
} Reserva;

// Declaração das funções
void fazerReserva(Reserva reservas[], int *totalReservas);
void listarReservas(Reserva reservas[], int totalReservas);
void totalPessoasPorDia(Reserva reservas[], int totalReservas);
void mostrarMenu();

int main() {
	
	setlocale(LC_ALL, "Portuguese"); // Configura a localidade do programa para Português, permitindo seus respectivos caracteres
	
	Reserva reservas[MAX_RESERVAS];
	int totalReservas = 0;
	int opcao;
	
	do {
		mostrarMenu();
		printf("\nEscolha uma opção: ");
		scanf("%d", &opcao);
		fflush(stdin);
		
		switch(opcao) {
			case 1:
				fazerReserva(reservas, &totalReservas);
				break;
			case 2: 
				listarReservas(reservas, totalReservas);
				break;
			case 3:
				totalPessoasPorDia(reservas, totalReservas);
				break;
			case 4:
				printf("\nSaindo do programa...\n");
				break;
			default:
				printf("\nOpção inválida! Tente novamente.\n");
		}
		
		printf("\n");
		system("pause");
		system("cls");
	
	} while(opcao != 4);
	
	return 0;	
}

void fazerReserva(Reserva reservas[], int *totalReservas) {
	
	if (*totalReservas < MAX_RESERVAS) {	
		printf("Digite o nome do responsável: ");
		fgets(reservas[*totalReservas].nome, 50, stdin);
		reservas[*totalReservas].nome[strcspn(reservas[*totalReservas].nome, "\n")] = '\0';
		fflush(stdin);
	
		printf("Digite o CPF: ");
		fgets(reservas[*totalReservas].cpf, 15, stdin);
		reservas[*totalReservas].cpf[strcspn(reservas[*totalReservas].cpf, "\n")] = '\0';
		fflush(stdin);
	
		do {
			printf("Digite o dia da reserva (1 - Quinta, 2 - Sexta, 3 - Sábado, 4 - Domingo): ");
			scanf("%d", &reservas[*totalReservas].dia);
			fflush(stdin);
			if (reservas[*totalReservas].dia < 1 || reservas[*totalReservas].dia > NUM_DIAS) {
				printf("\nReserva digitada não corresponde aos dias disponíveis. Tente novamente!\n\n");
			}
		} while (reservas[*totalReservas].dia < 1 || reservas[*totalReservas].dia > NUM_DIAS);
	
		printf("Digite a quantidade de pessoas: ");
		scanf("%d", &reservas[*totalReservas].numPessoas);
		fflush(stdin);
		
		(*totalReservas)++;
	} else {
		printf("\nNúmero máximo de reservas atingido!\n");
	}
}

void listarReservas(Reserva reservas[], int totalReservas) {
	
	if (totalReservas == 0) {
		printf("Nenhuma reserva encontrada.\n");
	} else {
		int i;
		for (i = 0; i < totalReservas; i++) {
			printf("Nome: %s\n", reservas[i].nome);
			printf("CPF: %s\n", reservas[i].cpf);
			printf("Dia: %d\n", reservas[i].dia);
			printf("Número de Pessoas: %d\n", reservas[i].numPessoas);
			printf("===============================\n");
		}
	}
}

void totalPessoasPorDia(Reserva reservas[], int totalReservas) {
	
	int dia, i, totalPessoasPorDia = 0;
	
	printf("Digite o dia da reserva (1 - Quinta, 2 - Sexta, 3 - Sábado, 4 - Domingo): ");
	scanf("%d", &dia);
	fflush(stdin);
	
	for (i = 0; i < totalReservas; i++) {
		if (reservas[i].dia == dia) {
			totalPessoasPorDia += reservas[i].numPessoas;
		}
	}
	printf("Total de pessoas correspondente ao dia %d: %d\n", dia, totalPessoasPorDia);
}

void mostrarMenu() {
	
	printf("1 - Fazer Reserva\n");
	printf("2 - Listar Reservas\n");
	printf("3 - Total de Pessoas Por Dia\n");
	printf("4 - Sair\n");
}
