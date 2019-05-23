#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 60     //Define constante máxima

//Estrutura da ficha do aluno
typedef struct
{
	char  nome[MAX];
	int   matricula;
	char  dtNasc[MAX];
	float nota1;
	float nota2;
	float media;
	int   ativo;
}  aluno;

/*Vetor Alunos é do tipo estrutura aluno (até 60)*/
aluno Alunos[MAX];
int cont = 0; /*Variável contadora global, registra a quantidade de alunos cadastrados.*/

/*Inicialização das funções*/
void  menu();
void cadastrar();
void consultar();
void imprimir();
void situacao();

/*Função principal: chamará a função do menu, que por
	 sua vez chamará as funções das opções*/
int main()
{
	setlocale(LC_ALL, "Portuguese");
	menu();
	return 0;
}

/*Declaração do menu*/
void menu()
{
	system("cls"); /*Limpa tela*/
	int op;
	do
	{
		printf("====== Curso de Biologia - Turma 825 ======\n");
		printf("\n  [1] Cadastrar alunos\n");
		printf("  [2] Consultar dados de um aluno\n");
		printf("  [3] Imprimir dados da turma\n");
		printf("  [4] Situação dos alunos\n");
		printf("  [5] Sair\n");
		printf("\n=================================================\n");
		scanf("%d", &op);
		getchar();
		switch (op)
		{	/*Pede para o usuário escolher qual opção do menu ele quer.	Selecionando, a função será chamada.*/
		case 1:
			cadastrar();
			break;

		case 2:
			consultar();
			break;

		case 3:
			imprimir();
			break;

		case 4:
			situacao();
			break;
		}
	} while ((op > 0) && (op < 5));
}

/*Declaração do menu 1 - Cadastrar*/
void cadastrar()
{
	system("cls");
	int op;
	do
	{
		if (cont >= MAX)
		{
			printf("\nMáximo de cadastros atingidos!\n");
			break;
		}
		else
		{
			system("cls");
			printf("\nNome: ");
			scanf("%s", &Alunos[cont].nome);
			printf("\nMatrícula: ");
			scanf("%d", &Alunos[cont].matricula);
			printf("\nData de nascimento: ");
			scanf("%s", &Alunos[cont].dtNasc);
			printf("\nNota 1: ");
			scanf("%f", &Alunos[cont].nota1);
			printf("\nNota 2: ");
			scanf("%f", &Alunos[cont].nota2);
			Alunos[cont].media = (Alunos[cont].nota1 + Alunos[cont].nota2) / 2;
			cont++;//Conta mais um sempre que um aluno é cadastrado

			//Menu 1 repete até usuário escolher sair ou ter 60 itens (alunos)
			if (cont >= MAX)
			{
				printf("\nMáximo de cadastros atingidos!\n");
				break;
			}
			else
			{
				printf("\nAluno registrado\n");
			}
		}
		printf("\nGostaria de cadastrar um novo aluno? ");
		printf("\n1- sim\n0- não\n");
		scanf("%d", &op);

	} while (op != 0);
	system("cls");
}

//Declaração do menu 2 - Consultar
void consultar()
{
	system("cls");
	int op, sucesso = 0; //Variável "sucesso" serve como teste (false or true).
	do
	{
		printf("\nDigite [1] para pesquisar através da matrícula");
		printf("\nDigite [2] para pesquisar através do nome\n");
		scanf("%d", &op);
		system("cls");
		if (op == 1)
		{
			int i = 0;
			int matricula;
			printf("\nDigite o número da matrícula: ");
			scanf("%d", &matricula);
			for (i = 0; i < cont; i++) /*Utilização da variável global "CONT". Possuirá quantidade de alunos cadastrados*/
			{
				if (matricula == (Alunos[i].matricula))
				{
					sucesso = 1;
					break;
				}
			}
			if (sucesso == 1)
			{ /*se 1 (true), imprima os dados do aluno da posição i.*/
				printf("\nAluno %d: \n", i + 1);
				printf("Nome: %s\n", Alunos[i].nome);
				printf("Matrícula: %d\n", Alunos[i].matricula);
				printf("Data de nascimento: %s\n", Alunos[i].dtNasc);
				printf("Nota 1: %.1f\n", Alunos[i].nota1);
				printf("Nota 2: %.1f\n", Alunos[i].nota2);
			}
			else
			{ //senão 0, (false).
				printf("Matrícula não encontrada\n");
				break;
			}
		}

		else if (op == 2)
		{
			int j = 0;
			sucesso = 0;
			char nome[MAX];
			system("cls");
			printf("\nDigite o nome do aluno para pesquisar: ");
			scanf("%s", &nome);
			for (j = 0; j < cont; j++)
			{
				if (strstr(Alunos[j].nome, nome) != NULL) //função "strstr" serve para busca de strings
				{
					sucesso = 1;
					break;
				}
			}
			if (sucesso == 1)
			{
				printf("\nAluno %d: \n", j + 1);
				printf("Nome: %s\n", Alunos[j].nome);
				printf("Matrícula: %d\n", Alunos[j].matricula);
				printf("Data de nascimento: %s\n", Alunos[j].dtNasc);
				printf("Nota 1: %.1f\n", Alunos[j].nota1);
				printf("Nota 2: %.1f\n", Alunos[j].nota2);
			}
			else
			{
				printf("Nome não encontrado\n");
				break;
			}
		}
		printf("\nDigite 1 se quiser continuar pesquisando ou 0 se quiser sair: \n");
		scanf("%d", &op);
		system("cls");

	} while (op != 0);
	system("cls");
}

//Declaração do menu 3 - Imprimir
void imprimir()
{
	int op, i;
	system("cls");
	printf("\n=====Imprimindo=====\n");  //Criar método para informar que não há cadastro, caso opção 3 for selecionada sem ter aluno no sistema
	do
	{
		for (i = 0; i < cont; i++)
		{
			printf("\nAluno %d: \n", i + 1);
			printf("Matrícula: %d\n", Alunos[i].matricula);
			printf("Nome: %s\n", Alunos[i].nome);
			printf("Data de nascimento: %s\n", Alunos[i].dtNasc);
			printf("Nota 1: %.1f\n", Alunos[i].nota1);
			printf("Nota 2: %.1f\n", Alunos[i].nota2);
		}
		printf("\nDigite 0 para retornar: \n");
		scanf("%d", &op);
		system("cls");

	} while (op != 0);
	system("cls");
}

//Declaração do menu 4 - Situação
void situacao()
{
	system("cls");
	int s, op;
	// -------------------------------------------------------------------
	do
	{
		for (s = 0; s < cont; s++)
		{
			//------------------------------------------------------------------------
			if (Alunos[s].media >= 7)
			{
				printf("\n%s, Média: %.1f, Situação: Aprovado\n", Alunos[s].nome, Alunos[s].media);
			}
			//---------------------------------------------------------------------------
			else
				if ((Alunos[s].media >= 3) && (Alunos[s].media < 7))
				{
					printf("\n%s, Média: %.1f, Situação: Prova Final\n", Alunos[s].nome, Alunos[s].media);
				}
			//------------------------------------------------------------------------------------
				else
					if (Alunos[s].media < 3)
					{
						printf("\n%s, Média: %.1f, Situação: Reprovado\n", Alunos[s].nome, Alunos[s].media);
					}
		}
		printf("\n\nDigite 0 para retornar: \n");
		scanf("%d", &op);

	} while (op != 0);
	system("cls");
	// ----------------------------------------------------------------------------
}