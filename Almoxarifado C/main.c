#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Este projeto tem o propósito realizar um programa para o setor de Almoxarifado de uma empresa, realizando cadastro de produtos, atualização de registros, vizualização de produtos com pouca quantidade disponível para uso e vizualização de todos os produtos, armazenando os dados em um arquivo .csv*/

typedef struct produto 
{
	 char nome[30];
	 int codigo;
	 int quant_atual;
	 int quant_max;
	 int quant_min;
} prod;

int main(int argc, char *argv[]) 
{
	int i, j, proxCodigo, iCodigo=0, iSelecao=0, iSelecao2 = 0, iSelecao3 = 0, codigoValido = 0;
	FILE *arquivo;
	char selecao = 'a', selecao2 = 'a', codigo = 'a', selecao3 = 'a';
	
	do
	{
		printf("Bem vindo ao setor de Almoxarifado. Qual caminho deseja seguir?\n\t1- Cadastrar novo Produto.\n\t2- Cadastrar Uso/Adicao.\n\t3- Visualizar Todos os Produtos.\n\t4- Visualizar Produto em Falta.\n\t5- Sair.\n\nDigite 1, 2, 3, 4 ou 5: ");
		scanf("%c", &selecao);
		while(isdigit(selecao) == 0)
		{
			fflush(stdin);
			printf("Escolha: %c", selecao);
			printf("\nPor favor digite a opcao novamente: ");
			scanf("%c", &selecao);	
		}
		iSelecao = selecao - '0';
		proxCodigo=0;
		arquivo = fopen("produtos.txt", "r");
		if(arquivo == NULL)
		{
			printf("Arquivo não encontrado! O arquivo produtos.txt está sendo criado.\n\n");
			arquivo = fopen("produtos.txt", "w");
			if(arquivo == NULL) 
			{
				printf("Erro ao criar o arquivo! Por favor contate um desenvolvedor.\n\n");
				break;
			} 
			else 
			{
				proxCodigo++;
				fclose(arquivo);
			}
		}
		else 
		{
			prod a1;
			while(fread(&a1, sizeof(prod), 1, arquivo) == 1) 
			{		
				proxCodigo = proxCodigo + 1;
			}
			proxCodigo++;
		}
		fclose(arquivo);	
		
		if(iSelecao == 1)
		{
			//1- Cadastrar novo Produto.
			printf("Escolha: %i\n\n", iSelecao);
			while (iSelecao2 != 2)
			{
				arquivo = fopen("produtos.txt", "a");
				if(arquivo == NULL)
				{
					printf("Erro ao tentar encontrar o arquivo produtos.txt! Por favor contate um desenvolvedor.\n\n");
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
						fflush(stdin);
						printf("\nPor favor digite uma opcao valida: ");
						scanf("%c", &selecao2);
						printf("Escolha: %c\n", selecao2);
					}
					iSelecao2 = selecao2 - '0';
				}			
			}
			printf("\nVoltando ao Menu Principal!\n\n");
			fclose(arquivo);
		} 
		else 
		{
			if(iSelecao == 2 || iSelecao == 3)
			{
				//2- Cadastrar Uso/Adicao || Vizualizar todos os produtos				
				printf("\nEscolha: %i\n\n", iSelecao);
				prod v[(proxCodigo-1)];
				arquivo = fopen("produtos.txt", "r");
				if(arquivo == NULL)
				{
					printf("Erro ao tentar encontrar o arquivo produtos.txt! Por favor contate um desenvolvedor.\n\n");
					break;
				}
				else 
				{
					printf("\tId\tNome\t\tQuant. Atual\tQuant. Maxima\tQuant. Minima\n");
					fread(&v, sizeof(prod), (proxCodigo-1), arquivo);
					for(i=0; i<(proxCodigo-1); i++)
					{
						printf("\t%i\t%s\t\t%i\t\t%i\t\t%i\n", v[i].codigo, v[i].nome, v[i].quant_atual, v[i].quant_max, v[i].quant_min);
					}
				}
				printf("\n");
				fclose(arquivo);
				if (iSelecao == 2) 
				{
					while (iSelecao3 != 2)
					{			
						fflush(stdin);
						printf("Digite o numero de Id do produto que deseja atualizar: ");
						scanf("%c", &codigo);
						while(codigoValido == 0)
						{
							while(isdigit(codigo) == 0)
							{	
								fflush(stdin);
								printf("\nPor favor digite um Id valido: ");
								scanf("%c", &codigo);
								printf("Escolha: %c\n", codigo);	
							}
							iCodigo = codigo - '0';
							if(iCodigo <= 0 || iCodigo > (proxCodigo-1)) 
							{
								printf("\nNao existe um produto com esse Id!\n");
								iCodigo = 0;
								codigo = 'a';
							} 
							else 
							{
								printf("\n\n\tId\tNome\t\tQuant. Atual\tQuant. Maxima\tQuant. Minima\n");
								printf("\t%i\t%s\t\t%i\t\t%i\t\t%i\n", v[(iCodigo-1)].codigo, v[(iCodigo-1)].nome, v[(iCodigo-1)].quant_atual, v[(iCodigo-1)].quant_max, v[(iCodigo-1)].quant_min);
								
								// inserir atualização de produto
								// inserir atualização de produto
								// inserir atualização de produto
								// inserir atualização de produto
								// inserir atualização de produto
								// inserir atualização de produto
								// inserir atualização de produto
								// inserir atualização de produto
								// inserir atualização de produto
								// inserir atualização de produto
								
								codigoValido = 1;
							}
						}
						fflush(stdin);
						printf("Deseja atualizar mais um arquivo?\n\t1- Sim.\n\t2- Nao\nDigite 1 ou 2: ");
						scanf("%c", &selecao3);
						while(isdigit(selecao3) == 0 || (isdigit(selecao3) != 0 && (selecao3 != '1' && selecao3 != '2')))
						{
							fflush(stdin);
							printf("\nPor favor digite uma opcao valida: ");
							scanf("%c", &selecao3);	
							printf("Escolha: %c\n", selecao3);
						}
						iSelecao3 = selecao3 - '0';
						if(iSelecao3 == 1) codigoValido = 0;
					}
				}
				printf("\nVoltando ao Menu Principal!\n\n");
			} 
			else if(iSelecao == 4)
			{
				//4- Visualizar Produto em Falta.
				printf("\nEscolha: %i\n\n", iSelecao);
				printf("Voltando ao Menu Principal!\n\n");
			} 
			else if(iSelecao == 5)
			{
				//5- Sair.
				printf("\nEscolha: %i\n\n", iSelecao);
			} 
			else 
			{
				printf("\nPor favor digite uma opcao valida: ");
				selecao = 'a';				
			}
		}
	}
	while(iSelecao != 5);
		
	printf("\nObrigado por utilizar nosso programa!\n");
	
	return 0;
}
