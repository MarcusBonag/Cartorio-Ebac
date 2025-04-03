#include <stdio.h> 									// biblioteca de comunicação com o usuário 
#include <stdlib.h>  								//biblioteca de alocação de espaço em memória
#include <locale.h> 								// biblioteca de alocações de texto por região 
#include <string.h> 								//biblioteca responsavel por cuidar das strings

int registro() 										//função responsável por cadastrar os usuários
{
													// início da criaão de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
													// final da criaão de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); 		// coletando informação do usuário
	scanf("%s",cpf);								//%s armazena o que foi digitado pelo usuário na string
	
	strcpy(arquivo, cpf);  							// responsável por copiar os valores da string
	
	FILE *file;  									//FILE (função pronta do sistema, estamos chamando ela), cria o arquivo na pasta
	file = fopen(arquivo, "w");						//Comando responsável por abrir o arquivo, e "w" para escrever dentro dele
	fprintf(file, cpf);								//salvo o valor da variavel no arquivo
	fclose(file); 									// fecha o arquivo
	
	file= fopen(arquivo, "a");						//abre o arquivo e "a" serve para atualizar uma escrita, no caso adicionar a , que separa as infornações 
	fprintf(file, ",");
	fclose(file);									//Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");		// coletando informação do usuário
	scanf("%s", nome);         
	
	file= fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", sobrenome);
	
	file= fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); // coletando informação do usuário  	
	scanf("%s", cargo);
	
	file= fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()										//função responsável por consultar os usuários
{
	setlocale(LC_ALL, "portuguese");				//definindo a linguagem para portugues 
	
	char cpf[40];									//criação da string cpf com 40 
	char conteudo[200];								//criação da string conteudo do arquivo 200 (para ser o arquivo total)
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);								
	
	FILE *file;
	file= fopen(cpf,"r");							//Comando responsável por abrir o arquivo, e "r" para escrever ler
	
	if(file == NULL)								//caso o usuário nao exista
	{
		printf("Não foi possível localizar o usuário!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)		//enquanto busca as informações do arquivo, coloca a informação na tela para o usuário (isso é um laço de repetição) 
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
	
	system("pause");
}

int deletar()										//função responsável por deletar o usuários 
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); // coletando informação do usuário
	scanf("%s", cpf);
	
	remove(cpf);	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)							
	{
		printf("Não foi possível localizar o usuário!\n");
		system("pause");
	}	
	//colocar a opção de "tem certeza que deseja deletar?"
}
	
int main () 										//função principal
	{
	int opcao=0; //definindo as variáveis 
	int laco=1;
	char senhadigitada [10]="a";
	int comparacao;
	
	printf ("\n\tLista de Alunos EBAC\n\n"); //início do menu
	printf ("Login de admninstrador\n\nDigite a sua Senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0 )
	{
			system("cls");
			for(laco=1;laco=1;)
		{
			setlocale(LC_ALL, "portuguese"); //definindo a linguagem 
			printf ("\n\tLista de Alunos EBAC\n\n"); //início do menu
			printf ("Selecione a opção desejada\n\n");
			printf ("\t1 - Cadastrar Nomes\n");
			printf ("\t2 - Consultar Nomes\n");
			printf ("\t3 - Deletar   Nomes\n"); 
			printf ("\t4 - Fechar Programa\n");
			printf("Opção:");//fim do menu

	
			scanf("%d", &opcao); // armazenando a escolha do usuário
	
			system("cls"); //comando para limpar a tela do programa
		
			switch(opcao) //forma conjunta do if para ganhar performace 
			{
				case 1:
				registro(); //chamada de funções 
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
				printf("Essa opção nao existe!\n");
				system("pause");
				break;		
				}
			}	 //final do for (fechando o ciclo)
	}
	else 
		printf("Senha Incorreta!");
		
		
	}


