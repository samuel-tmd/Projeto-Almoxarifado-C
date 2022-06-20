#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* 
	Este projeto tem o propósito realizar um programa para o setor de Almoxarifado de uma empresa, 
	realizando cadastro de produtos, atualização de registros, vizualização de produtos com pouca quantidade disponível para uso e vizualização de todos os produtos 
	e por fim armazenando os dados em um arquivo .txt
*/

typedef struct produto 
{
	 char nome[30];
	 int codigo;
	 int quant_atual;
	 int quant_max;
	 int quant_min;
} prod;

void atualizarProduto(prod v[], int iCodigo, int proxCodigo)
{
	printf("\nDigite o Nome do produto: ");
	fflush(stdin);
	gets(v[(iCodigo-1)].nome);						
	printf("Digite a Quantidade Atual do produto: ");
	fflush(stdin);
	scanf("%i",&v[(iCodigo-1)].quant_atual);				
	printf("Digite a Quantidade Maxima do produto: ");
	fflush(stdin);
	scanf("%i",&v[(iCodigo-1)].quant_max);								
	printf("Digite a Quantidade Minima do produto: ");
	fflush(stdin);
	scanf("%i",&v[(iCodigo-1)].quant_min);
	fflush(stdin);
	
	FILE *arquivo;
	arquivo = fopen("produtos.txt", "w");
	if(arquivo == NULL)
	{
		printf("Erro ao tentar encontrar o arquivo produtos.txt! Por favor contate um desenvolvedor.\n\n");
	} 
	else 
	{
		fwrite(v, sizeof(prod), (proxCodigo-1), arquivo);
	}
	fclose(arquivo);
}

void cadastrarProduto(int proxCodigo) 
{
	FILE *arquivo;
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
	
	arquivo = fopen("produtos.txt", "a");
	if(arquivo == NULL)
	{
		printf("Erro ao tentar encontrar o arquivo produtos.txt! Por favor contate um desenvolvedor.\n\n");
	} 
	else 
	{
		fwrite(produto, sizeof(prod), 1, arquivo);
	}
	fclose(arquivo);
}

int main(int argc, char *argv[]) 
{
	int i, j, proxCodigo, iCodigo=0, iSelecao=0, iSelecao2 = 0, iSelecao3 = 0, codigoValido = 0, emFalta;
	FILE *arquivo;
	char selecao = 'a', selecao2 = 'a', codigo = 'a', selecao3 = 'a';
	
	do
	{
		fflush(stdin);
		printf("Bem vindo ao setor de Almoxarifado. Qual caminho deseja seguir?\n\t1- Cadastrar novo Produto.\n\t2- Atualizar Produto.\n\t3- Visualizar Todos os Produtos.\n\t4- Visualizar Produto em Falta.\n\t5- Sair.\n\nDigite 1, 2, 3, 4 ou 5: ");
		scanf("%c", &selecao);
		while(isdigit(selecao) == 0)
		{
			fflush(stdin);
			printf("Escolha: %c", selecao);
			printf("\nPor favor digite uma opcao valida: ");
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
			printf("\nEscolha: %i\n\n", iSelecao);
			while (iSelecao2 != 2)
			{
					cadastrarProduto(proxCodigo);
					proxCodigo++;	
										
					printf("\nDeseja cadastrar mais um produto?\n\t1- Sim.\n\t2- Nao\nDigite 1 ou 2: ");
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
			printf("\nVoltando ao Menu Principal!\n\n");
		} 
		else 
		{
			prod v[(proxCodigo-1)];
			arquivo = fopen("produtos.txt", "r");
			if(arquivo == NULL)
			{
				printf("Erro ao tentar encontrar o arquivo produtos.txt! Por favor contate um desenvolvedor.\n\n");
				break;
			}
			else 
			{
				fread(&v, sizeof(prod), (proxCodigo-1), arquivo);
			}
			fclose(arquivo);
			if(iSelecao == 2 || iSelecao == 3)
			{
				//2- Atualizar Produto || Vizualizar todos os produtos				
				printf("\nEscolha: %i\n\n", iSelecao);
				printf("\tId\tNome\t\tQuant. Atual\tQuant. Maxima\tQuant. Minima\n");
				for(i=0; i<(proxCodigo-1); i++)
				{
					printf("\t%i\t%s\t\t%i\t\t%i\t\t%i\n", v[i].codigo, v[i].nome, v[i].quant_atual, v[i].quant_max, v[i].quant_min);
				}	
				if (iSelecao == 2) 
				{
					while (iSelecao3 != 2)
					{			
						fflush(stdin);
						printf("\nDigite o numero de Id do produto que deseja atualizar: ");
						scanf("%c", &codigo);
						printf("\nEscolha: %c\n", codigo);
						while(codigoValido == 0)
						{
							while(isdigit(codigo) == 0)
							{	
								fflush(stdin);
								printf("\nPor favor digite um Id valido: ");
								scanf("%c", &codigo);
								printf("\nEscolha: %c\n", codigo);	
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
								printf("\n\tId\tNome\t\tQuant. Atual\tQuant. Maxima\tQuant. Minima\n");
								printf("\t%i\t%s\t\t%i\t\t%i\t\t%i\n", v[(iCodigo-1)].codigo, v[(iCodigo-1)].nome, v[(iCodigo-1)].quant_atual, v[(iCodigo-1)].quant_max, v[(iCodigo-1)].quant_min);
								
								atualizarProduto(v,iCodigo, proxCodigo);
								codigoValido = 1;
							}
						}
						fflush(stdin);
						printf("\nDeseja atualizar mais um produto?\n\t1- Sim.\n\t2- Nao\nDigite 1 ou 2: ");
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
				emFalta = 0;
				for(i=0; i<(proxCodigo-1); i++)
				{
					if(v[i].quant_atual<=v[i].quant_min)
					{
						printf("O produto %s, de Id: %i esta acabando!\n", v[i].nome, v[i].codigo);
						emFalta++;
					}
				}
				if(emFalta<=0) printf("Nao existem produtos com a quantidade atual menor ou igual à quantidade minima!\n\n");
				printf("\nVoltando ao Menu Principal!\n\n");
			} 
			else if(iSelecao == 5)
			{
				//5- Sair.
				printf("\nEscolha: %i\n\n", iSelecao);
			} 
			else 
			{
				printf("\nPor favor digite uma opcao valida!\n\n");
				selecao = 'a';				
			}
		}
	}
	while(iSelecao != 5);
		
	printf("Obrigado por utilizar nosso programa!\n");
	
	return 0;
}
