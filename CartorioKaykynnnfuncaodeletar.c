#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h>> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //fun��o responsavel por cadastrar usuarios no sistema
{
	//inicio criacao de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criacao de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informacao do usuario
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
	
	file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
	
	printf("Digite o Sobrenome a ser Cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");    
    
    
	
	
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Linguagem para Portugues
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser Consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o Arquivo!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
  
	
	
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
        printf("O usuario n�o se encontra no Sistema!\n");
        system("pause");
        
	}
	

}

int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
 	for(laco=1;laco=1;)
	{
		
		system("cls");
	
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
	printf("### Cart�rio do Kaykyn ###\n\n"); //inicio do menu
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n"); 
	printf("Opcao: "); //fim do menu
	
 	scanf("%d", &opcao); //armazenando a escolha do usuario
	
    system("cls"); //responsavel por limpar a tela
    
    
    switch(opcao) //inicio da selecao do menu
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
		
		
		
		default:
		printf("Op��o Indisponivel!\n");
		system("pause");
		break;
    	
	}
    
    
   
	

}	
}
