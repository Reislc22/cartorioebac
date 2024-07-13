#include <stdio.h>  //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regiao
#include <string.h> //biblioteca respons�vel por cuidar das strings

//criando fun��es
int menureg()
//Fun��o para perguntar se o usu�rio deseja voltar ao menu ou cadastrar mais nomes!
{
	system("cls");
//Limpando a tela
    int opcao=0;
//Variavel
	setlocale(LC_ALL, "portuguese");
//Botando em portugu�s

//Perguntando se deseja continuar ou voltar ao menu
	printf("Escolha a op��o desejada:\n\n");
	printf("1- Voltar ao menu\n");
	printf("2- Continuar registrando\n");
	printf("Op��o:");
//Fim

	scanf("%d", &opcao);
//Armazendo escolha do usu�rio

//Definindo oque cada op��o vai fazer
	switch (opcao)
	{
		case 1:
		main();
		break;
		case 2:
		registro();
		break;
		default:
		system("cls");
		printf("essa op��o n�o est� disponivel\n");
		system("pause");
		menureg();
		break;
	}
//Fim
}


int menucon()
//Fun��o para perguntar se o usu�rio deseja voltar ao menu ou consultar mais nomes!
{
	system("cls");
//Limpando a tela

	int opcao=0;
//Variavel

	setlocale(LC_ALL, "portuguese");
//Botando em portugu�s

//Perguntando se deseja continuar ou voltar ao menu
	printf("Escolha a op��o desejada:\n\n");
	printf("1- Voltar ao menu\n");
	printf("2- Consultar mais nomes\n");
	printf("Op��o:");
//Fim

	scanf("%d", &opcao);
//Armazenando escolha do usu�rio	

//Definindo oque cada op��o vai fazer	
	switch (opcao)
	{
		case 1:
		main();
		break;
		case 2:
		consulta();
		break;
		default:
		system("cls");
		printf("essa op��o n�o est� disponivel\n");
		system("pause");
		menucon();
		break;
	}
//fim
}


int menudel()
//Fun��o para perguntar se o usu�rio deseja voltar ou deletar mais nomes!
{
	system("cls");
//Limpando a tela
    int opcao=0;
//variavel
	setlocale(LC_ALL, "portuguese");
//Botando em portugu�s

//Perguntando se deseja continuar ou voltar ao menu
	printf("Escolha a op��o desejada:\n\n");
	printf("1- Voltar ao menu\n");
	printf("2- Deletar mais nomes\n");
	printf("Op��o:");
//Fim

	scanf("%d", &opcao);
//Armazendo escolha do usu�rio

//Definindo oque cada op��o vai fazer
	switch (opcao)
	{
		case 1:
		main();
		break;
		case 2:
		deletar();
		break;
		default:
		system("cls");
		printf("essa op��o n�o est� disponivel\n");
		system("pause");
		menudel();
		break;
	}
//fim
}

int registro()
//Cadastrar usu�rios no sitema
{
//criando variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
//fim das variaveis/string

    system("cls");
//limpando a tela	

	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
//Perguntando o CPF e armazendo a resposta

	strcpy(arquivo, cpf);
//responsavel por copiar os valores das strings
    
    FILE *file;
//cria o arquivo
    file = fopen(arquivo, "w");
//cria o arquivo
    fprintf(file,cpf);
//salvo o valor da variavel
    fclose(file); // fecha o arquivo
// Criando o arquivo principal(cpf)
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
//Adicionando a virgula

	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
//Salvando os dados dentro do arquivo (nome)
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
//Adicionando a virgula	

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
//Salvando os dados dentro do arquivo (sobrenome)
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
//Adicionando a virgula
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
//Salvando os dados dentro do arquivo (Cargo)

menureg();
//Pergunta se deseja continuar registrando ou voltar ao menu

system("pause");

}

int consulta()
//Consultar os usu�rios dentro do sistema
{
	setlocale(LC_ALL, "portuguese");
//Definindo a linguagem

//Variaveis/strings
    char cpf[40]; 
    char conteudo[200];
//variaveis/strings

    system("cls");
//Limpando a tela

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
//armazenando a resposta do cliente
    
    FILE *file;
    file = fopen(cpf, "r");
//consultando o CPF
  
    if(file == NULL)
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
//Informando caso o CPF for inexistente 
    
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
//Consultando as informa��es dentro do arquivo e apresentando ao usuario 

    fclose(file);
    system("pause");
//Fechando o Arquivo

    menucon(); 
//Pergunta se deseja continuar Consultando ou voltar ao menu     
        
}


int deletar()
//deletar usu�rios do sistesma
{
	char cpf[40];
//Variavel	
	
	system("cls");
//limpando a tela
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
//Armazernando o CPF a ser excluido, 
	
	remove(cpf);
//excluindo o CPF
		
	FILE *file;
	file= fopen(cpf, "r");
//Abrindo o arquivo(CPF)
	
	if (file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
    }
//Informando que o usu�rio n�o se encontra mais no sistema

    menudel();
//Pergunta se deseja continuar deletando ou voltar ao menu
	
}
//fim das fun�oes

int main()
//Fun��o principal
{
    int opcao=0;
    int laco=1;
    char senhadigitada[10]="a";
    int comparacao;
    //Definindo variaveis
    
    //Perguntando senha
    printf("### Cart�rio da EBAC ###\n\n");
    printf("Login de Adminstrador\n\n");
    printf("Digite sua senha:");
        
    scanf("%s", senhadigitada);
    //armazendo a senha digitada pelo usu�rio
    
    comparacao = strcmp(senhadigitada, "admin");
    //Comparando se a senha digitada � igual
    
    //Definindo de que a senha for correta abre o menu
    if(comparacao == 0)
    {    	  
    
        for(laco=1;laco=1;)
       { 
  
            system("cls");
        //limpando a op��o escolhida
        
    	    setlocale(LC_ALL, "portuguese");
        //Definindo a linguagem
    
        //Inicio do menu
    	    printf("### Cart�rio da EBAC ###\n\n");
        	printf("Escolher a op��o desejada do menu:\n\n");
    	    printf("\t1- Registras nomes\n");
    	    printf("\t2- Consultar nomes\n");
    	    printf("\t3- Deletar nomes\n");
    	    printf("\t4- Sair do progama\n\n");
    	    printf("op��o: ");
        //Final do menu
	
    	    scanf("%d", &opcao);
        //Armazenando a escolha do usuario
	
            system("cls");
        //Limpando o menu    

        //Indo para dentro das op��es
            switch(opcao)
            {
        //Chamando fun��es  
    	    	case 1:
                registro();
    	        break;
	        
    	        case 2:
    	        consulta();
    	        break;
	        
    			case 3:	
    			deletar();
        	    break;
   	        
     	        case 4:
    	        printf("Obrigado por utilizar o sistema\n");
    	        return 0;
    	        break;
   	        
    	//Acabou de chamar as fun��es
   	
     	        default:
    	        printf("Est� op��o n�o esta disponivel!\n");
        	    system("pause");
        	    break;
        //Informando quando bota uma op��o indisponivel	
       	   }
	    //Fim das op��es 		        
	    }
	}
	//fim
	
	else
	     printf("senha incorreta!");
    //Informando que a senha est� incorreta
}
