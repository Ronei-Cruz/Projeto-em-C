#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct colecao COLECAO;
struct colecao{
	int tipo;
	int caixa;
	char titulo_obra[50];
	char editora[20];
	char autor[30];
	int ano;
	long int isbn;
	int quantidade;
};

void cabecalho()
{
	system("cls");
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
	printf("\nRONEI DIEGO ALMEIDA CRUZ	-	RA:19146676-5\n");
	printf("CURSO: ENGENHARIA DE SOFTWARE\n");
	printf("ATIVIDADE MAPA\n");
	printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
}

void cadastrar();
void listarLivros();
void listarRevistas();
void listarCaixa();

int main(void)
{
	
	setlocale(LC_ALL,"Portuguese");
	int escolha;
	
	do
	{
		cabecalho();
		printf("[1] - Cadastrar Obras\n");
		printf("[2] - Livros Cadastrados\n");
		printf("[3] - Revistas Cadastradas\n");
		printf("[4] - Localizacao Livros/Revistas\n");
		printf("[5] - Sair\n\n");
		printf("Escolha uma opção: ");
		fflush(stdin);
		scanf("%d", &escolha);
		system("cls");
		
		switch (escolha)
		{	
			case 1:
			{
				cabecalho();
				cadastrar();
				break;
			}
			case 2: 
			{
				cabecalho();
				listarLivros();
				break;
			}
			case 3:
			{
				cabecalho();
				listarRevistas();
				break;
			}
			case 4:
			{
				cabecalho();
				listarCaixa();
				break;
			}
			
			default:
			{
		
				if (escolha == 5)
				{
					cabecalho();
					printf("\n\tPrograma FINALIZADO!\n");
					printf("\t     OBRIGADO!\n");
					continue;
				}
				cabecalho();
				printf("\n\tOpção Invalida!\n");
				printf("\nPressine uma tecla para voltar ao MENU!\n");
				getch();
			break;
			}
		}
	}while(escolha != 5);
	
	
	return 0;
}

void cadastrar()
{
	
	FILE *arquivo;
	
	int opcao;
	
	
	COLECAO ddsc;
	
	
	arquivo = fopen("Mapa.txt", "a+");
	if (arquivo == NULL)
	{
		cabecalho();
		printf("\nArquivo não encontardo!\n");
	}
	else if(arquivo != NULL);
	{
		do
		{
			cabecalho();
			do
			{
				cabecalho();
				printf("\nCadastrar como:\n[1]- Livros\n[2]- Revistas\n>>> ");
				fflush(stdin);
				scanf("%d", &ddsc.tipo);
				system("cls");
				if ((ddsc.tipo != 1) && (ddsc.tipo != 2))
				{
					cabecalho();
					printf("\n\t\tOPÇÃO INVÁLIDA!\n");
					printf("\n");
					system("Pause");
					system("cls");
				}
			}while((ddsc.tipo != 1) && (ddsc.tipo != 2));
			
			cabecalho();
			do
			{
				cabecalho();
				printf("Amazenar na CAIXA:\n[1] - [2] - [3]:\n>>> ");
				fflush(stdin);
				scanf("%d", &ddsc.caixa);
				system("cls");
				if ((ddsc.caixa !=1 ) && (ddsc.caixa != 2) && (ddsc.caixa !=  3))
				{
					cabecalho();
					printf("\n\t\tOPÇÃO INVÁLIDA!\n");
					printf("\n");
					system("Pause");
					system("cls");
				}				
			}while((ddsc.caixa !=1 ) && (ddsc.caixa != 2) && (ddsc.caixa !=  3));
			
			cabecalho();
			printf("AUTOR     : ");
			fflush(stdin);
			gets(ddsc.autor);
			
			printf("OBRA      : ");
			fflush(stdin);
			gets(ddsc.titulo_obra);			
			
			printf("EDITORA   : ");
			fflush(stdin);
			gets(ddsc.editora);			
			
			printf("EDIÇÃO    : ");
			fflush(stdin);
			scanf("%d", &ddsc.ano);
			
			ddsc.isbn = 0;
			printf("ISBN      : ");
			fflush(stdin);
			scanf("%ld", &ddsc.isbn);
			
			printf("QUANTIDADE: ");
			fflush(stdin);
			scanf("%d", &ddsc.quantidade);
			
			fwrite(&ddsc, sizeof(COLECAO), 1, arquivo);
			cabecalho();
			printf("Deseja continuar [S/N]?\n>>> ");	
		}while((getche () == 's')||(getche() =='S'));
		fclose(arquivo);
		system ("cls");
	}
}

void listarLivros()
{
	FILE *arquivo;
	
	COLECAO ddsc;
	
	arquivo = fopen("Mapa.txt","rb");
	
	cabecalho();	
	if (arquivo == NULL)
	{
		cabecalho();
		printf("\n\tArquivo não encontardo!\n");
	}
	else
	{
		printf("=============================================+\n");
		printf("\t\t  LIVROS\n");
		printf("=============================================+\n");
		int cont = 0;
		while(fread(&ddsc, sizeof(COLECAO), 1, arquivo)==1)
		{
			if(ddsc.tipo == 1)
			{
				printf("\t  CAIXA: [%d]\n", ddsc.caixa);
				printf("  OBRA      : %s\n", ddsc.titulo_obra);
				printf("  AUTOR     : %s\n", ddsc.autor);
				printf("  EDITORA   : %s\n", ddsc.editora);
				printf("  EDIÇÃO    : %d\n", ddsc.ano);
				printf("  ISBN      : %d\n", ddsc.isbn);
				printf("  QUANTIDADE: %d\n", ddsc.quantidade);
				printf("---------------------------------------------|\n");
				cont = cont + 1;
			}	
		}
		printf("\n\t* Contem %d LIVROS cadastrados\n", cont);
	}
	fclose(arquivo);
	printf("\n    Pressine uma tecla para voltar ao MENU!\n");
	getch();
}

void listarRevistas()
{
	FILE *arquivo;
	
	COLECAO ddsc;
	
	arquivo = fopen("Mapa.txt","rb");
	
	cabecalho();
	if (arquivo == NULL)
	{
		cabecalho();
		printf("\n\tArquivo não encontardo!\n");	
	}
	else
	{
		printf("=============================================+\n");
		printf("\t\t  REVISTAS\n");
		printf("=============================================+\n");
		int cont =0;
		while(fread(&ddsc, sizeof(COLECAO),1, arquivo)==1)
		{
			if(ddsc.tipo == 2)
			{
				printf("\t  CAIXA:[%d]\n", ddsc.caixa);
				printf("  OBRA      : %s\n", ddsc.titulo_obra);
				printf("  AUTOR     : %s\n", ddsc.autor);
				printf("  EDITORA   : %s\n", ddsc.editora);
				printf("  EDIÇÃO    : %d\n", ddsc.ano);
				printf("  ISBN      : %d\n", ddsc.isbn);
				printf("  QUANTIDADE: %d\n", ddsc.quantidade);
				printf("---------------------------------------------|\n");
				cont = cont + 1;
			}
		}
		printf("\n\t* Contem %d REVISTAS cadastrados\n", cont);
	}
	fclose(arquivo);
	printf("\n    Pressine uma tecla para voltar ao MENU!\n");
	getch();
}

void listarCaixa()
{
	FILE *arquivo;
	
	int j;
	char tipo;
	
	COLECAO ddsc;
	
	arquivo = fopen("Mapa.txt", "rb");
	
	j = 1;
	
	
	cabecalho();
	if(arquivo == NULL)
	{
		cabecalho();
		printf("\n\tArquivo não encontardo!\n");
	}
	else if (arquivo != NULL)
	{
		printf("Listar qual caixa?\n[1] - [2] - [3]:\n>>> ");
		fflush(stdin);
		scanf("%d", &j);
		system("cls");
		
		if(j == 1)
		{
			cabecalho();
			printf("\n=============================================+");
			printf("\n\t\t  CAIXA - 1\n");
			printf("=============================================+\n");
			int cont1, cont2 = 0;
			while(fread(&ddsc, sizeof(COLECAO), 1, arquivo)== 1)
			{
				if(ddsc.caixa == 1)
				{	
					printf(" > OBRA      : %s\n", ddsc.titulo_obra);
					printf(" > AUTOR     : %s\n", ddsc.autor);
					printf(" > EDIÇÃO    : %d\n", ddsc.ano);
					printf(" > QUANTIDADE: %d\n", ddsc.quantidade);
					int tipo = ddsc.tipo;
					if (tipo == 1)
					{
						cont1 = cont1 + 1;
						printf(" > TIPO      : LIVRO\n");
					}
					else
					{
						cont2 = cont2 + 1;
						printf(" > TIPO      : REVISTA\n");
					}
					printf("---------------------------------------------|\n");
				}
			}
			printf("\n - A CAIXA 1 contem:\n - %d LIVROS\n - %d REVISTAS\n", cont1, cont2);	
		}
		else if(j == 2)
		{
			cabecalho();
			printf("\n=============================================+");
			printf("\n\t\t  CAIXA - 2\n");
			printf("=============================================+\n");
			int cont1, cont2 = 0;
			while(fread(&ddsc, sizeof(COLECAO), 1, arquivo)==1)
			{
				if(ddsc.caixa == 2)
				{
					printf(" > OBRA      : %s\n", ddsc.titulo_obra);
					printf(" > AUTOR     : %s\n", ddsc.autor);
					printf(" > EDIÇÃO    : %d\n", ddsc.ano);
					printf(" > QUANTIDADE: %d\n", ddsc.quantidade);
					int tipo = ddsc.tipo;
					if (tipo == 1)
					{
						cont1 = cont1 + 1;
						printf(" > TIPO      : LIVRO\n");
					}
					else
					{
						cont2 = cont2 + 1;
						printf(" > TIPO      : REVISTA\n");
					}
					printf("---------------------------------------------|\n");
				}
			}
			printf("\n - A CAIXA 2 contem:\n - %d LIVROS\n - %d REVISTAS\n", cont1, cont2);
		}
		else if(j == 3)
		{
			cabecalho();
			printf("\n=============================================+");
			printf("\n\t\t  CAIXA - 3\n");
			printf("=============================================+\n");
			int cont1, cont2 = 0;
			while(fread(&ddsc, sizeof(COLECAO), 1, arquivo)==1)
			{
				if(ddsc.caixa == 3)
				{
					printf(" > OBRA      : %s\n", ddsc.titulo_obra);
					printf(" > AUTOR     : %s\n", ddsc.autor);
					printf(" > EDIÇÃO    : %d\n", ddsc.ano);
					printf(" > QUANTIDADE: %d\n", ddsc.quantidade);
					int tipo = ddsc.tipo;
					if (tipo == 1)
					{
						cont1 = cont1 + 1;
						printf(" > TIPO      : LIVRO\n");
					}
					else
					{
						cont2 = cont2 + 1;
						printf(" > TIPO      : REVISTA\n");
					}
					printf("---------------------------------------------|\n");
				}
			}
			printf("\n - A CAIXA 3 contem:\n - %d LIVROS\n - %d REVISTAS\n", cont1, cont2);
		}
		else
		{
			cabecalho();
			printf("\n\tOPÇÃO INVÁLIDA!!");
			getch();
		}
	}
	fclose(arquivo);
	printf("\n    Pressine uma tecla para voltar ao MENU!\n");
	getch();
}
