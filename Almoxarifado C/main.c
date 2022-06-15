#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
	int i, j, linhas;
	FILE *arquivo;
	char virgula[1] = ",",conta, final[150], temp[3], letra = "\n", selecao = "0", selecao2 = "0";

	do
	{
		label:
		printf("Bem vindo ao setor de Almoxarifado. Qual caminho deseja seguir?\n\t1- Cadastrar novo Produto.\n\t2- Cadastrar Uso.\n\t3- Visualizar Todos os Produtos.\n\t4- Visualizar Produto em Falta.\n\t5- Sair.\n\nDigite 1, 2, 3, 4 ou 5: ");
		scanf("%c", &selecao);
		
		if(!isdigit(selecao)){
			printf("Nop");
		}
		
		if(selecao != 5)
		{
			arquivo = fopen("produtos.csv", "r");
			if(arquivo == NULL)
			{
				printf("Erro ao tentar encontrar o arquivo Produtos.csv! Por favor contate um desenvolvedor\n\n");
				break;
			}
			else 
			{
				while((conta=fgetc(arquivo))!=EOF)
				{
			        if(conta=='\n')
					{
			        	linhas++;
			        }
			    }
			}
			fclose(arquivo);
			
			if(linhas==1)
			{
				arquivo = fopen("produtos.csv", "w");
				if(arquivo == NULL)
				{
					printf("Erro ao tentar encontrar o arquivo Produtos.csv! Por favor contate um desenvolvedor\n\n");
					break;	
				} 
				else 
				{
					fprintf(arquivo, "Nome, Codigo, Quantidade Atual, Quantidade Maxima, Quantidade Minima\n");
					fclose(arquivo);
				}
			}
			
			if(selecao == 1)
			{
				while (selecao2 != 2)
				{
					printf("\n1\n\n");
					arquivo = fopen("produtos.csv", "a");
					if(arquivo == NULL)
					{
						printf("Erro na abertura de Arquivo! Voltando ao Menu Principal...\n\n");
						break;
					} 
					else 
					{
						prod produto;												
						printf("Digite o Nome do produto: ");
						fflush(stdin);
						gets(produto.nome);						
						printf("Digite a Quantidade Atual do produto: ");
						fflush(stdin);
						scanf("%i",&produto.quant_atual);				
						printf("Digite a Quantidade Maxima do produto: ");
						fflush(stdin);
						scanf("%i",&produto.quant_max);								
						printf("Digite a Quantidade Minima do produto: ");
						fflush(stdin);
						scanf("%i",&produto.quant_min);
						fflush(stdin);
						
						strcpy(final,produto.nome);			
						strcat(final, virgula);						
						sprintf(temp, "%i", produto.quant_atual);
						strcat(final, temp);
						strcat(final, virgula);						
						sprintf(temp, "%i", produto.quant_max);
						strcat(final, temp);
						strcat(final, virgula);						
						sprintf(temp, "%i", produto.quant_min);
						strcat(final,temp);
						strcat(final,"\n");
						printf("%s\n", final);
						
						fprintf(arquivo, final);
						fclose(arquivo);						
						printf("Deseja Cadastrar mais um arquivo?\n\t1- Sim.\n\t2- Nao\nDigite 1 ou 2: ");
						scanf("%i", &selecao2);
					}			
				}
			} 
			else if(selecao == 2)
			{
				printf("\n2\n\n");
				printf("Voltando ao Menu Principal!\n\n");
			} 
			else if(selecao == 3)
			{
				printf("\n3\n\n");
				printf("Voltando ao Menu Principal!\n\n");
			} 
			else if(selecao == 4)
			{
				printf("\n4\n\n");
				printf("Voltando ao Menu Principal!\n\n");
			} 
			else 
			{
				printf("\nPor favor digite a opção novamente: ");
				scanf("%i", &selecao);
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
