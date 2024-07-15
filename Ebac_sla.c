#include <stdio.h>  //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regiao
#include <string.h> //biblioteca respons�vel por cuidar das strings

//criando fun��es

int menuprincipal()
{
    int opcao=0;
    int laco=1;
    int exit=0;
    //Definindo variaveis
    
   
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
    	    
   	    //Acabou de chamar as fun��es
   	
     	    default:
    	    printf("Est� op��o n�o esta disponivel!\n");
        	system("pause");
        	break;
        //Informando quando bota uma op��o indisponivel	
       }
	    //fim das fun��es		        
	}
}
		
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
		return 0;
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
		return 0;
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
	printf("2- Excluir outro nome\n");
	printf("Op��o:");
//Fim

	scanf("%d", &opcao);
//Armazendo escolha do usu�rio

//Definindo oque cada op��o vai fazer
	switch (opcao)
	{
		case 1:
		return 0;
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
//Armazenando o CPF

	strcpy(arquivo, cpf);
//responsavel por copiar os valores das strings

//cria o arquivo    
    FILE *file;
//cria o arquivo
    file = fopen(arquivo, "w");//"w"= Criar
	fprintf(file,"CPF:");
	fclose(file);
//Mostrando que � o cpf	

    file = fopen(arquivo,"a");//"a"= Atualizar
    fprintf(file,cpf);
//salvo o valor da variavel
    fclose(file); // fecha o arquivo
// Criando o arquivo principal(cpf)
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
//Armazendando o nome
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nNome:");
	fclose(file);
//Mostrando que � o nome
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
//Salvando os dados dentro do arquivo (nome)
	

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
//Armazenando o sobrenome
	
    file = fopen(arquivo, "a");
	fprintf(file,"\nSobrenome:");
	fclose(file);
//Mostrando que � o sobrenome
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
//Salvando os dados dentro do arquivo (sobrenome)
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
//Armazendo o cargo
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo:");
	fclose(file);
//Mostrando que � o cargo
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
//Salvando os dados dentro do arquivo (Cargo)

menureg();
//Pergunta se deseja continuar registrando ou voltar ao menu

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
		printf("%s", conteudo);
	}
//Consultando as informa��es dentro do arquivo e apresentando ao usuario 

    fclose(file);
//Fechando o Arquivo
    printf("\n");
//Pulando uma linha para n�o ficar colado
    system("pause");


    menucon(); 
//Pergunta se deseja continuar Consultando ou voltar ao menu     
        
}


int deletar()
//deletar usu�rios do sistesma
{
	char cpf[40];
	int confirmacao=0;
//Variaveis
	
	system("cls");
//limpando a tela
    setlocale(LC_ALL,"portuguese");
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);	
//Armazernando o CPF a ser excluido,
    FILE *file;
	file = fopen(cpf, "r");// "r" = ler arquivo
	fclose (file);
//Checando se o CPF � existente
     
     if (file== NULL)
     {
     	printf("Erro, CPF n�o encontrado\n");
     	system("pause");
     	menudel();
	 }
    //Informando caso o cpf seja inexistente


    else
    {
    //Confirma��o se realmente deseja excluir o CPF
        printf("Deseja excluir o CPF:");
        printf(cpf);
        printf("\n");
        printf("1- Sim\n");
        printf("2- N�o\n");
        printf("Excluir:");
    //Confirma��o se realmente deseja excluir o CPF
        scanf("%d", &confirmacao);
    //armazenando escolha do usuario
    
        switch(confirmacao)
       {                  
       	
    	   case 1:
    	   remove(cpf);
           FILE *file;
           file= fopen(cpf, "r");
           break;
    	
           case 2:
           menudel();
           break;
		   
		   default:
		   printf("Op��o indisponivel\n");
		   system("pause");
		   menudel();
		   break;	
	   } 
    system("pause");
    menudel();
//Pergunta se deseja continuar deletando ou voltar ao menu
    }	
}
//fim das fun�oes

int main()
//Fun��o principal
{
    char senhadigitada[10]="a";
    int comparacao;
    //Definindo variaveis
    
    
    setlocale(LC_ALL, "portuguese");
    //Botando em portugu�s
    
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
        menuprincipal();
    }
    
        else
	        printf("senha incorreta!");    
    //Informando que a senha est� incorreta
}
