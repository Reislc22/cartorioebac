#include <stdio.h>  //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por regiao
#include <string.h> //biblioteca responsável por cuidar das strings



//criando funções
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
	system("pause");
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
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
//Consultando as informações dentro do arquivo e apresentando ao usuario 
        fclose(file);
        system("pause");
        
}


int deletar()
//deletar usuários do sistesma
{
	char cpf[40];
//variavel	
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
//Armazernando o CPF a ser excluido, 
	
	remove(cpf);
//excluindo o CPF
		
	FILE *file;
	file= fopen(cpf, "r");
//Abrindo o arquivo(CPF)
	
	if (file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
    }
//Informando que o usuário não se encontra mais no sistema
	
}
//fim das funçoes

int main()
//Função principal
{
    int opcao=0;
    int laco=1;
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
	    printf("\t3- Deletar nomes\n\n");
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
   	//Acabou de chamar as funções
   	
   	        default:
   	        printf("Está opção não esta disponivel!\n");
    	    system("pause");
    	    break;
    //Informando quando bota uma opção indisponivel	
       	}
	//Fim das opções 		        
	}
}
