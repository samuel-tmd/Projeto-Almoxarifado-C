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
	int i, j, proxCodigo, iSelecao=0, iSelecao2 = 0;
	FILE *arquivo;
	char selecao = 'a', selecao2 = 'a';
	
	do
	{
		printf("Bem vindo ao setor de Almoxarifado. Qual caminho deseja seguir?\n\t1- Cadastrar novo Produto.\n\t2- Cadastrar Uso.\n\t3- Visualizar Todos os Produtos.\n\t4- Visualizar Produto em Falta.\n\t5- Sair.\n\nDigite 1, 2, 3, 4 ou 5: ");
		scanf("%c", &selecao);
		while(isdigit(selecao) == 0)
		{
			fflush(stdin);
			printf("Escolha: %c", selecao);
			printf("\nPor favor digite a opcao novamente: ");
			scanf("%c", &selecao);	
		}
		
		iSelecao = selecao - '0';
		
		arquivo = fopen("produtos.csv", "r");
		if(arquivo == NULL)
		{
			printf("Erro ao tentar encontrar o arquivo Produtos.csv! Por favor contate um desenvolvedor\n\n");
			break;
		}
		else 
		{
			prod a1;
			proxCodigo=0;
			while(fread(&a1, sizeof(prod), 1, arquivo) == 1) 
			{		
				proxCodigo = proxCodigo + 1;
			}
			proxCodigo++;
		}
		fclose(arquivo);
			
		if(iSelecao == 1)
		{
			printf("Escolha: %i\n\n", iSelecao);
			while (iSelecao2 != 2)
			{
				arquivo = fopen("produtos.csv", "a");
				if(arquivo == NULL)
				{
					printf("Erro na abertura de Arquivo! Voltando ao Menu Principal...\n\n");
					break;
				} 
				else 
				{
					prod produto[1];												
					printf("Digite o Nome do produto: ");
					fflush(stdin);
					gets(produto[0].nome);						
					printf("Digite a Quantidade Atual do produto: ");
					fflush(stdin);
					scanf("%i",&produto[0].quant_atual);				
					printf("Digite a Quantidade Maxima do produto: ");
					fflush(stdin);
					scanf("%i",&produto[0].quant_max);								
					printf("Digite a Quantidade Minima do produto: ");
					fflush(stdin);
					scanf("%i",&produto[0].quant_min);
					fflush(stdin);
					produto[0].codigo = proxCodigo;
					
					fwrite(produto, sizeof(prod), 1, arquivo);
					proxCodigo++;	
										
					printf("Deseja Cadastrar mais um arquivo?\n\t1- Sim.\n\t2- Nao\nDigite 1 ou 2: ");
					scanf("%c", &selecao2);
					while(isdigit(selecao2) == 0 || (isdigit(selecao2) != 0 && (selecao2 != '1' && selecao2 != '2')))
					{					
						printf("\n\nisdigit: %i\n", isdigit(selecao2));
						fflush(stdin);
						printf("Escolha: %c\n", selecao2);
						printf("\nPor favor digite uma opcao valida: ");
						scanf("%c", &selecao2);	
					}
					iSelecao2 = selecao2 - '0';
					printf("Escolha: %i\n", iSelecao2);
				}			
			}
			printf("\nVoltando ao Menu Principal!\n\n");
			fclose(arquivo);
		} 
		else if(iSelecao == 2)
		{
			printf("\nEscolha: %i\n\n", iSelecao);
			printf("Voltando ao Menu Principal!\n\n");
		} 
		else if(iSelecao == 3)
		{
			printf("\nEscolha: %i\n\n", iSelecao);
			printf("Voltando ao Menu Principal!\n\n");
		} 
		else if(iSelecao == 4)
		{
			printf("\nEscolha: %i\n\n", iSelecao);
			printf("Voltando ao Menu Principal!\n\n");
		} 
		else if(iSelecao == 5)
		{
			printf("\nEscolha: %i\n\n", iSelecao);
		} 
		else 
		{
			printf("\nPor favor digite uma opcao valida: ");
			selecao = 'a';				
		}
	}
	while(iSelecao != 5);
		
	printf("\nObrigado por utilizar nosso programa!\n");
	
	return 0;
}
