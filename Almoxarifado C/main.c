#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct produto {
	 char nome[30];
	 int codigo;
	 int quant_atual;
	 int quant_max;
	 int quant_min;
} prod;

int main(int argc, char *argv[]) 
{
	int i, j, selecao = 0, selecao2 = 0;
	FILE *arquivo;
	char virgula[1] = ",", final[150], temp[3];

	do
	{
		printf("Bem vindo ao setor de Almoxarifado. Qual caminho deseja seguir?\n\t1- Cadastrar novo Produto.\n\t2- Cadastrar Uso.\n\t3- Visualizar Todos os Produtos.\n\t4- Visualizar Produto em Falta.\n\t5- Sair.\n\nDigite 1, 2, 3, 4 ou 5: ");
		scanf("%i", &selecao);
		if(selecao != 5)
		{
			if(selecao == 1)
			{
				
				while (selecao2 != 2)
				{
					printf("1\n");
					arquivo = fopen("produtos.csv", "a");
					if(arquivo == NULL)
					{
						printf("Erro na abertura de Arquivo! Voltando ao Menu Principal...\n\n");	
					} 
					else 
					{
						prod produto;
						fflush(stdin);						
						printf("Digite o Nome do produto: ");
						gets(produto.nome);
						fflush(stdin);						
						printf("Digite a Quantidade Atual do produto: ");
						scanf("%i",&produto.quant_atual);
						fflush(stdin);						
						printf("Digite a Quantidade Maxima do produto: ");
						scanf("%i",&produto.quant_max);
						fflush(stdin);												
						printf("Digite a Quantidade Minima do produto: ");
						scanf("%i",&produto.quant_min);
						
						strcpy(final,"\n");
						strcat(final, produto.nome);			
						strcat(final, virgula);						
						sprintf(temp, "%i", produto.quant_atual);
						strcat(final, temp);
						strcat(final, virgula);						
						sprintf(temp, "%i", produto.quant_max);
						strcat(final, temp);
						strcat(final, virgula);						
						sprintf(temp, "%i", produto.quant_min);
						strcat(final,temp);
						printf("%s\n", final);
						
						fprintf(arquivo, final);
						fclose(arquivo);						
						printf("Deseja Cadastrar mais um arquivo?\n\t1- Sim.\n\t2- Nao");
						scanf("%i", &selecao2);
					}			
				}
			} 
			else if(selecao == 2)
			{
				printf("2\n");
				printf("Voltando ao Menu Principal!\n\n");
			} 
			else if(selecao == 3)
			{
				printf("3\n");
				printf("Voltando ao Menu Principal!\n\n");
			} 
			else if(selecao == 4)
			{
				printf("4\n");
				printf("Voltando ao Menu Principal!\n\n");
			}
		}
		else 
		{
			printf("\nObrigado por utilizar nosso programa!\n");
		}
	}
	while(selecao != 5);
		
	return 0;
}
