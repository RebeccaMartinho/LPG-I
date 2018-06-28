#include <stdio.h>
#include <windows.h> 
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define MAX 300
struct cliente{
	char nome[50]; //campos
	char cpf[20];
	char sexo[10];
	char nasc[20];
	char email[45];
	char tel[15];
	int cod;
};

int indice =0; //contador
int indice2 = 0; //verifica se existe cadastros depois de exclusão
int i=0;
void cadastrar(); //funções
void alterar();
void listar();
void excluir();
void consultar();
struct cliente c[MAX];

main () {
		
	char op;

	setlocale(LC_ALL,"Portuguese");
	system("color F4");
	printf ("		Bem-vindo ao sistema de cadastro e controle da HyperSoft!\n");
	printf("\n");
	for (;;){
		printf ("\n Digite a opção desejada:\n\n");
		printf ("1 - Cadastro de cliente\n");
		printf ("2 - Alteração de dados do cliente\n");
		printf ("3 - Exclusão de clientes\n");
		printf ("4 - Consulta de clientes \n");
		printf ("5 - Listagem dos clientes \n");
		printf ("6 - Finalizar \n ");
		scanf ("%s", &op);
	
		if (op=='1'){
			cadastrar ();
		}
		else if (op=='2'){
			alterar();
		}
		else if (op=='3'){
			excluir();
		}
		else if (op=='4'){
			consultar();
		}
		else if (op=='5'){
			listar();
		}
		else if (op=='6'){
			system("cls");
			printf ("A sessão está sendo finalizada. Obrigada!\n");
			printf("\n");
			break;
		}
		else {
			system("cls");
			printf ("Opção inválida! Favor tentar novamente.\n");
			printf ("\n");
		}
	}
}

void cadastrar (){
	system("cls");
	printf ("             CADASTRO                       \n");
	printf ("\n");
	printf ("Insira o nome completo do cliente: ");
	scanf (" %[^\n]s", &c[indice].nome);
	
	printf ("\nInsira o CPF do cliente: ");
	scanf ("%s", &c[indice].cpf);
	
	printf ("\nInsira o telefone do cliente: ");
	scanf ("%s", &c[indice].tel);
	
	printf ("\nInsira o sexo do cliente: ");
	scanf ("%s", &c[indice].sexo);
	
	printf ("\nInsira a data de nascimento do cliente (modelo dd/mm/aaaa): ");
	scanf ("%s", &c[indice].nasc);
	
	printf ("\nInsira o email do cliente: ");
	scanf ("%s", &c[indice].email);
	
	c[indice].cod=indice+1;
	system("cls");
	printf ("Cliente %s cadastrado com sucesso! \n", c[indice].nome);
	Sleep(1700);
	system("cls");
	printf ("O código de %s é: %i\n\n", c[indice].nome, c[indice].cod); 
	indice++;
	indice2++;
	system("pause");
	system("cls");
	printf ("Voltando ao menu...\n");
	Sleep(1200);
	system("cls");
	
}

void alterar(){
	int cod; // Recebe o código que terá os dados alterados
	int flag;
	int op2; //Recebe o dado que a pessoa quer alterar  
	int op3; // Recebe a opção: se irá pesquisar por código ou nome;
	char nome3[50]; //Recebe o nome do cliente que terá os dados alterados
	
	system ("cls");
	printf ("           ALTERAÇÃO\n");
	printf ("\n");
	
	if (indice==0){
		printf ("Não há clientes cadastrados.\n");
		system("pause");
		system("cls");
		printf ("Voltando para o menu...\n");
		Sleep(1200);
		system ("cls");
	}
	else{
		printf ("Deseja realizar a pesquisa por código(1) ou por nome(2)? \n");
		scanf ("%i", &op3);
		if ((op3>2) || (op3<1)){
			printf ("Desculpe, opção inválida.");
			system("pause");
			system("cls");
			printf ("Voltando para o menu...");
			Sleep(1200);
			system("cls");
		}
		else if (op3==1){
			system("cls");
			printf ("		ALTERAÇÃO\n");
			printf("\n");
			printf ("Digite o código do cadastro que deseja alterar: ");
			scanf ("%i", &cod);
			system("cls");
		}
		else if (op3==2){
			system("cls");
			printf ("		ALTERAÇÃO\n");
			printf("\n");
			printf ("Digite o nome do cliente que deseja alterar: ");
			scanf (" %[^\n]s", &nome3);
			system("cls");	
		}
		if (op3==1 || op3==2){
			for (i=0;i<indice;i++){
				flag=0;
					if (op3==1){
						if (cod==c[i].cod){
							flag=1;
							system ("cls");
						}
					}
					else if (op3==2){
						if(!strcmp(nome3,c[i].nome)){
							flag=1;
						}
					}
					
					if(flag==1){							
						printf ("		ALTERAÇÃO\n");
						printf ("\n");
						printf ("Selecione o dado que deseja alterar:\n");
						printf ("1- Nome: %s\n",c[i].nome);
						printf ("2- Sexo: %s\n",c[i].sexo);
						printf ("3- Data de nascimento: %s\n",c[i].nasc);
						printf ("4- CPF: %s\n",c[i].cpf);
						printf ("5- Telefone: %s\n",c[i].tel);
						printf ("6- Email: %s\n",c[i].email);
						scanf ("%i", &op2);
						system("cls");			
				
					if (op2==1){
						system ("cls");
						printf ("		ALTERAÇÃO DE NOME\n");
						printf ("\n");
						printf ("Insira o novo nome: ");
						scanf (" %[^\n]s", &c[i].nome);
						system ("cls");
						printf ("		ALTERAÇÃO DE NOME\n");
						printf ("\n");
						printf ("Alteração de nome realizada com sucesso!\n");
						system("pause");
						system("cls");
						printf ("\n");
						printf ("Voltando para o menu...");
						Sleep(1200);
						system("cls");
						break;
					}
					else if(op2==2){
						system("cls");
						printf ("		ALTERAÇÃO DE SEXO\n");
						printf ("\n");
						printf ("Insira o novo sexo: ");
						scanf ("%s", &c[i].sexo);
						system("cls");
						printf ("       ALTERAÇÃO DE SEXO\n");
						printf ("\n");
						printf ("Alteração de sexo realizada com sucesso!\n");
						system("pause");
						system("cls");
						printf ("\n");
						printf ("Voltando para o menu...");
						Sleep(1200);
						system("cls");
						break;
					}
					else if (op2==3){
						system("cls");
						printf ("		ALTERAÇÃO DE DATA DE NASCIMENTO\n");
						printf ("\n");
						printf ("Insira a nova data de nascimento (dd/mm/aaaa): ");
						scanf ("%s", &c[i].nasc);
						system("cls");
						printf ("		ALTERAÇÃO DE DATA DE NASCIMENTO\n");
						printf ("\n");
						printf ("Alteração de data de nascimento realizada com sucesso!\n");
						system("pause");
						system("cls");
						printf ("\n");
						printf ("Voltando para o menu...");
						Sleep(1200);
						system("cls");
						break;
					}
					else if (op2==4){
						system("cls");
						printf ("		ALTERAÇÃO DE CPF\n");
					    printf ("\n");
						printf ("Insira o novo CPF: ");
						scanf ("%s", &c[i].cpf);
						system("cls");
						printf ("		ALTERAÇÃO DE CPF\n");
					    printf ("\n");
						printf ("Alteração de CPF realizada com sucesso!\n");
						system("pause");
						system("cls");
						printf ("\n");
						printf ("Voltando para o menu...");
						Sleep(1200);
						system("cls");
						break;
					}	
					else if (op2==5){
						system("cls");
						printf ("           ALTERAÇÃO DE TELEFONE\n");
						printf ("\n");
						printf ("Insira um novo telefone: ");
						scanf ("%s", &c[i].tel);
						system("cls");
						printf ("\n");
					 	printf ("           ALTERAÇÃO DE TELEFONE\n");
						printf ("Alteração realizada com sucesso!\n");
						system("pause");
						system("cls");
						printf ("\n");
						printf ("Voltando para o menu...");
						Sleep(1200);
						system("cls");
						break;
					}
					else if (op2==6){
						system("cls");
						printf ("			ALTERAÇÃO DE EMAIL\n");
						printf ("Insira o novo email: ");
						scanf ("%s", &c[i].email);
						system("cls");
						printf ("           ALTERAÇÃO DE EMAIL\n");
						printf ("\n");
						printf ("Alteração realizada com sucesso!\n");
						system("pause");
						system("cls");
						printf ("\n");
						printf ("Voltando para o menu...");
						Sleep(1200);
						system("cls");
						break;	
					
					}else if((op2>6) || (op2<1)){
						system("cls");
						printf ("Desculpe, opção invalida\n");
						printf ("Voltando ao menu...\n");
						Sleep(1200);
						system("cls");
					}
				}				
			}
		}
	}
}

void excluir(){ //Somente aceita códigos
	int flag=0;
	int cod;
	int codd; //Recebe o código que será excluido
	if (indice==0){
		system("cls");
		printf("Não há clientes cadastrados!\n");
		system("pause");
		system("cls");
		printf("Voltando ao menu...\n");
		printf ("\n");
		Sleep(1200);
		system("cls");
	}
	else{
		system("cls");
		printf ("		EXCLUSÃO DE CLIENTES\n");
		printf ("\n");
		printf ("Digite o código do cliente que será excluído: ");
		scanf ("%i", &codd);
		printf ("Tem certeza que deseja excluir o cadastro de codigo %i ? (1-SIM 2-NÃO)",codd);
		scanf ("%i", &cod);
		
		if(cod==1){
		
			for (i=0;i<indice;i++){
				flag=0;
				if (c[i].cod==codd){
					flag++;
					c[i].cod=0;
					strcpy(c[i].cpf,"");
					strcpy(c[i].nasc,"");
					strcpy(c[i].nome,"");
					strcpy(c[i].tel,"");
					strcpy(c[i].email,"");
					strcpy(c[i].sexo,"");
					system("cls");		
					printf ("Cadastro excluído com sucesso!\n");
					system("pause");
					system("cls");
					printf ("Voltando ao menu...");
					Sleep(1200);
					system("cls");
					indice2 --;
					break;	
				}
			}
		}
		else if(cod==2){
			system("cls");
			printf("Opção cancelada \n");
			system("pause");
			system("cls");
			printf ("Voltando ao menu...");
			Sleep(1200);
			system("cls");
			
		}
		if ((flag==0)&&(cod==1)) {
			system("cls");
			printf ("		EXCLUSÃO DE CLIENTES\n");
			printf ("\n");
			printf ("Desculpe, código não encontrado no sistema.\n");
			system("pause");
			system("cls");
			printf ("Voltando ao menu...");
			Sleep(1200);
			system("cls");
		}
	}
}

void listar(){
if (indice2==0){
		system("cls");
		printf("Não há clientes cadastrados!\n");
		system("pause");
		system("cls");
		printf("Voltando ao menu...\n");
		printf ("\n");
		Sleep(1200);
		system("cls");
	}
	
	else{
		system("cls");
		printf ("		CLIENTES CADASTRADOS\n");
		for (i=0;i<indice;i++){
			if(c[i].cod>0){
			printf ("\n");
			printf ("Cliente de código %i\n", c[i].cod);	
			printf ("Nome: %s\n", c[i].nome);
			printf ("CPF: %s\n", c[i].cpf);
			printf ("Telefone: %s\n", c[i].tel);
			printf ("Sexo: %s \n", c[i].sexo);
			printf ("Data de nascimento: %s \n", c[i].nasc);
			printf ("Email: %s\n", c[i].email);
			printf ("\n");
			}
		}
		system("pause");
		system("cls");
		printf("Voltando ao menu...");
		Sleep(1200);
		system("cls");	
	}
}

void consultar (){
	int cons; //Recebe a opção de culsuta: código ou nome
	int cod1; //Recebe o código que será consultado
	int flagg=0; 
	char nome1[40]; //Recebe o nome que será consultado
	
	if (indice==0){
		system("cls");
		printf("Não há clientes cadastrados!\n");
		system("pause");
		system("cls");
		printf("Voltando ao menu...\n");
		printf ("\n");
		Sleep(1200);
		system("cls");
	}
	else{
		system("cls");
		printf("Deseja realizar a consulta por código(1) ou nome(2)? ");
		scanf ("%i", &cons);
		system("cls");
		if ((cons<1) || (cons>2)){
			printf("Opção inválida. Tente novamente.\n");
			system("pause");
			system("cls");
		}
		else if (cons==1){
			printf("Digite o código que deseja consultar: ");
			scanf("%i",&cod1);
			system("cls");
			
			if (cod1==c[cod1-1].cod){
				system("cls");
				printf("Cliente de código %i\n",c[cod1-1].cod);
				printf("Nome: %s\n",c[cod1-1].nome);
				printf("Sexo: %s\n",c[cod1-1].sexo);
				printf("Data de nascimento: %s\n",c[cod1-1].nasc);
				printf("CPF: %s\n",c[cod1-1].cpf);
				printf("Telefone: %s\n",c[cod1-1].tel);
				printf("E-mail: %s\n",c[cod1-1].email);
				system("pause");
				system("cls");
				printf("Voltando ao menu...");
				Sleep(1200);
				system("cls");
			}
			else{
				printf("Desculpe, cadastro não encontrado no sistema.\n");
				system("pause");
				system("cls");
				printf("Voltando ao menu...");
				Sleep(1300);
				system("cls");
			}				
		}
		else{
			printf ("Digite o nome que deseja consultar: ");
			scanf(" %[^\n]s",&nome1);
			system("cls");
			for (i=0;i<indice;i++){
				flagg=0;
				if(!strcmp(nome1,c[i].nome)){
					system("cls");
					printf("Cliente de código %i\n",c[i].cod);
					printf("Nome: %s\n",c[i].nome);
					printf("Sexo: %s\n",c[i].sexo);
					printf("Data de nascimento: %s\n",c[i].nasc);
					printf("CPF: %s\n",c[i].cpf);
					printf("Telefone: %s\n",c[i].tel);
					printf("E-mail: %s\n",c[i].email);
					system("pause");
					system("cls");
					printf("Voltando ao menu...");
					Sleep(1200);
					system("cls");
					flagg=1;
					break;						
				}
			}
			if(flagg==0){
				printf("Desculpe, cadastro não encontrado no sistema.\n");
				system("pause");
				system("cls");
				printf("Voltando ao menu...");
				Sleep(1300);
				system("cls");
			}
		}
	}
}

