#include <stdio.h>  //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por regiao
#include <string.h> //biblioteca responsável por cuidar das strings

//criando funções

int menuprincipal()
{
    int opcao=0;
    int laco=1;
    int exit=0;
    //Definindo variaveis
    
   
    for(laco=1;laco=1;)
    { 
  
        system("cls");
    //limpando a opção escolhida
        
        setlocale(LC_ALL, "portuguese");
    //Definindo a linguagem
    
    //Inicio do menu
    	printf("### Cartório da EBAC ###\n\n");
        printf("Escolher a opção desejada do menu:\n\n");
    	printf("\t1- Registras nomes\n");
    	printf("\t2- Consultar nomes\n");
    	printf("\t3- Deletar nomes\n");
    	printf("\t4- Sair do progama\n\n");
    	printf("opção: ");
    //Final do menu
	
    	scanf("%d", &opcao);
    //Armazenando a escolha do usuario
	
        system("cls");
        //Limpando o menu    

        //Indo para dentro das opções
        switch(opcao)
        {
        //Chamando funções  
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
    	    
   	    //Acabou de chamar as funções
   	
     	    default:
    	    printf("Está opção não esta disponivel!\n");
        	system("pause");
        	break;
        //Informando quando bota uma opção indisponivel	
       }
	    //fim das funções		        
	}
}
		
int menureg()
//Função para perguntar se o usuário deseja voltar ao menu ou cadastrar mais nomes!
{
	system("cls");
//Limpando a tela
    int opcao=0;
//Variavel
	setlocale(LC_ALL, "portuguese");
//Botando em português

//Perguntando se deseja continuar ou voltar ao menu
	printf("Escolha a opção desejada:\n\n");
	printf("1- Voltar ao menu\n");
	printf("2- Continuar registrando\n");
	printf("Opção:");
//Fim

	scanf("%d", &opcao);
//Armazendo escolha do usuário

//Definindo oque cada opção vai fazer
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
		printf("essa opção não está disponivel\n");
		system("pause");
		menureg();
		break;
	}
//Fim
}


int menucon()
//Função para perguntar se o usuário deseja voltar ao menu ou consultar mais nomes!
{
	system("cls");
//Limpando a tela

	int opcao=0;
//Variavel

	setlocale(LC_ALL, "portuguese");
//Botando em português

//Perguntando se deseja continuar ou voltar ao menu
	printf("Escolha a opção desejada:\n\n");
	printf("1- Voltar ao menu\n");
	printf("2- Consultar mais nomes\n");
	printf("Opção:");
//Fim

	scanf("%d", &opcao);
//Armazenando escolha do usuário	

//Definindo oque cada opção vai fazer	
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
		printf("essa opção não está disponivel\n");
		system("pause");
		menucon();
		break;
	}
//fim
}


int menudel()
//Função para perguntar se o usuário deseja voltar ou deletar mais nomes!
{
	system("cls");
//Limpando a tela
    int opcao=0;
//variavel
	setlocale(LC_ALL, "portuguese");
//Botando em português

//Perguntando se deseja continuar ou voltar ao menu
	printf("Escolha a opção desejada:\n\n");
	printf("1- Voltar ao menu\n");
	printf("2- Excluir outro nome\n");
	printf("Opção:");
//Fim

	scanf("%d", &opcao);
//Armazendo escolha do usuário

//Definindo oque cada opção vai fazer
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
		printf("essa opção não está disponivel\n");
		system("pause");
		menudel();
		break;
	}
//fim
}

int registro()
//Cadastrar usuários no sitema
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
//Mostrando que é o cpf	

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
//Mostrando que é o nome
	
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
//Mostrando que é o sobrenome
	
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
//Mostrando que é o cargo
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
//Salvando os dados dentro do arquivo (Cargo)

menureg();
//Pergunta se deseja continuar registrando ou voltar ao menu

}

int consulta()
//Consultar os usuários dentro do sistema
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
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
//Informando caso o CPF for inexistente 
    
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
//Consultando as informações dentro do arquivo e apresentando ao usuario 

    fclose(file);
//Fechando o Arquivo
    printf("\n");
//Pulando uma linha para não ficar colado
    system("pause");


    menucon(); 
//Pergunta se deseja continuar Consultando ou voltar ao menu     
        
}


int deletar()
//deletar usuários do sistesma
{
	char cpf[40];
	int confirmacao=0;
//Variaveis
	
	system("cls");
//limpando a tela
    setlocale(LC_ALL,"portuguese");
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);	
//Armazernando o CPF a ser excluido,
    FILE *file;
	file = fopen(cpf, "r");// "r" = ler arquivo
	fclose (file);
//Checando se o CPF é existente
     
     if (file== NULL)
     {
     	printf("Erro, CPF não encontrado\n");
     	system("pause");
     	menudel();
	 }
    //Informando caso o cpf seja inexistente


    else
    {
    //Confirmação se realmente deseja excluir o CPF
        printf("Deseja excluir o CPF:");
        printf(cpf);
        printf("\n");
        printf("1- Sim\n");
        printf("2- Não\n");
        printf("Excluir:");
    //Confirmação se realmente deseja excluir o CPF
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
		   printf("Opção indisponivel\n");
		   system("pause");
		   menudel();
		   break;	
	   } 
    system("pause");
    menudel();
//Pergunta se deseja continuar deletando ou voltar ao menu
    }	
}
//fim das funçoes

int main()
//Função principal
{
    char senhadigitada[10]="a";
    int comparacao;
    //Definindo variaveis
    
    
    setlocale(LC_ALL, "portuguese");
    //Botando em português
    
    //Perguntando senha
    printf("### Cartório da EBAC ###\n\n");
    printf("Login de Adminstrador\n\n");
    printf("Digite sua senha:");
        
    scanf("%s", senhadigitada);
    //armazendo a senha digitada pelo usuário
    
    comparacao = strcmp(senhadigitada, "admin");
    //Comparando se a senha digitada é igual
    
    //Definindo de que a senha for correta abre o menu
    if(comparacao == 0)
    {   
        menuprincipal();
    }
    
        else
	        printf("senha incorreta!");    
    //Informando que a senha está incorreta
}
