#include <stdio.h> 									// biblioteca de comunica��o com o usu�rio 
#include <stdlib.h>  								//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> 								// biblioteca de aloca��es de texto por regi�o 
#include <string.h> 								//biblioteca responsavel por cuidar das strings

int registro() 										//fun��o respons�vel por cadastrar os usu�rios
{
													// in�cio da cria�o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
													// final da cria�o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); 		// coletando informa��o do usu�rio
	scanf("%s",cpf);								//%s armazena o que foi digitado pelo usu�rio na string
	
	strcpy(arquivo, cpf);  							// respons�vel por copiar os valores da string
	
	FILE *file;  									//FILE (fun��o pronta do sistema, estamos chamando ela), cria o arquivo na pasta
	file = fopen(arquivo, "w");						//Comando respons�vel por abrir o arquivo, e "w" para escrever dentro dele
	fprintf(file, cpf);								//salvo o valor da variavel no arquivo
	fclose(file); 									// fecha o arquivo
	
	file= fopen(arquivo, "a");						//abre o arquivo e "a" serve para atualizar uma escrita, no caso adicionar a , que separa as inforna��es 
	fprintf(file, ",");
	fclose(file);									//Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");		// coletando informa��o do usu�rio
	scanf("%s", nome);         
	
	file= fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", sobrenome);
	
	file= fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); // coletando informa��o do usu�rio  	
	scanf("%s", cargo);
	
	file= fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()										//fun��o respons�vel por consultar os usu�rios
{
	setlocale(LC_ALL, "portuguese");				//definindo a linguagem para portugues 
	
	char cpf[40];									//cria��o da string cpf com 40 
	char conteudo[200];								//cria��o da string conteudo do arquivo 200 (para ser o arquivo total)
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);								
	
	FILE *file;
	file= fopen(cpf,"r");							//Comando respons�vel por abrir o arquivo, e "r" para escrever ler
	
	if(file == NULL)								//caso o usu�rio nao exista
	{
		printf("N�o foi poss�vel localizar o usu�rio!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)		//enquanto busca as informa��es do arquivo, coloca a informa��o na tela para o usu�rio (isso � um la�o de repeti��o) 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
	
	system("pause");
}

int deletar()										//fun��o respons�vel por deletar o usu�rios 
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf);
	
	remove(cpf);	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)							
	{
		printf("N�o foi poss�vel localizar o usu�rio!\n");
		system("pause");
	}	
	//colocar a op��o de "tem certeza que deseja deletar?"
}
	
int main () 										//fun��o principal
	{
	int opcao=0; //definindo as vari�veis 
	int laco=1;
	char senhadigitada [10]="a";
	int comparacao;
	
	printf ("\n\tLista de Alunos EBAC\n\n"); //in�cio do menu
	printf ("Login de admninstrador\n\nDigite a sua Senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0 )
	{
			system("cls");
			for(laco=1;laco=1;)
		{
			setlocale(LC_ALL, "portuguese"); //definindo a linguagem 
			printf ("\n\tLista de Alunos EBAC\n\n"); //in�cio do menu
			printf ("Selecione a op��o desejada\n\n");
			printf ("\t1 - Cadastrar Nomes\n");
			printf ("\t2 - Consultar Nomes\n");
			printf ("\t3 - Deletar   Nomes\n"); 
			printf ("\t4 - Fechar Programa\n");
			printf("Op��o:");//fim do menu

	
			scanf("%d", &opcao); // armazenando a escolha do usu�rio
	
			system("cls"); //comando para limpar a tela do programa
		
			switch(opcao) //forma conjunta do if para ganhar performace 
			{
				case 1:
				registro(); //chamada de fun��es 
				break;
			
				case 2:
				consulta();
				break;
			
				case 3: 
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o nosso sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa op��o nao existe!\n");
				system("pause");
				break;		
				}
			}	 //final do for (fechando o ciclo)
	}
	else 
		printf("Senha Incorreta!");
		
		
	}


