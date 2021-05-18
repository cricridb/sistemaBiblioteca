#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 100

typedef struct Cadastro{
	int tipo;
	int codigo;
	char isbn[100];
	char titulo[100];
	char edicao[100];
	char nomeAutor[100];
	char editora[100];
	int quantidade;
	int caixa;
	int ano;
}CadastroObras;

int i = 0;

void identificacao();
void cadastrarObras (CadastroObras obras[MAX]);
int contarRegistro(CadastroObras obras[MAX]);
void ListarObrasCaixa(int buscaCaixa, CadastroObras obras[MAX]);
void ListarLivros(int buscaLivro, CadastroObras obras[MAX]);
void ListarRevistas(int buscaRevista, CadastroObras obras[MAX]);

int main(){
	setlocale(LC_ALL,"Portuguese");
	int(op), buscaCaixa, buscaLivro, buscaRevista;
	char resp;
	
	CadastroObras obras[MAX];
	
	do{
		identificacao();
		printf("\n        Menu de opções:              \n");
		printf("\n[1] - Cadastrar obras");
		printf("\n[2] - Listar todos os Livros");
		printf("\n[3] - Listar todas as Revistas");
		printf("\n[4] - Listar as Obras por Caixa ");
		printf("\n[0] - Sair");
		printf("\n");
		printf("\nEscolha uma opção do menu para continuar: ");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				resp='s';
				while((resp=='S')||(resp=='s')){
					system("cls");
					cadastrarObras(obras);
					printf("\nDeseja cadastrar uma nova obra? [s][n] ");
					fflush(stdin);
					scanf("%c",&resp);
					system("cls");
				}
				break;
			case 2:
				system("cls");
				ListarLivros(buscaLivro,obras);
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				ListarRevistas(buscaRevista,obras);
				system("pause");
				system("cls");
				break;
			case 4:
				printf("Informe o número da caixa que deseja acessar ([1] | [2]| [3]): ");;
				fflush(stdin);
				scanf("%d",&buscaCaixa);
				system("cls");
				ListarObrasCaixa(buscaCaixa, obras);
				system("pause");
				system("cls");
				break;
			case 0:
				printf("\nSaindo do sistema...");
				break;
			default:
				printf(">>Opção inválida...<<\n");
				system("pause");
				system("cls");
				break; 	
		}
	}while (op!=0);
	return 0;
}

void identificacao(){
	int t;
	for(t=0; t<80; t++) printf("*");
	printf ("\n");
	for(t=0; t<80; t++) printf("*");
	printf ("\n");
	printf("\n>>>> RA: 20022175-5 <<<<");
	printf("\n>>>> Aluna: Dayane Cristina Batista Leal <<<<");
	printf("\n>>>> Curso: Engenharia de Software <<<<\n");	
	printf ("\n");
	for(t=0; t<80; t++) printf("*");
	printf ("\n");

}

int contarRegistro(CadastroObras obras[MAX])
{
	FILE * arq = fopen("arquivo.txt", "r");
	if(arq != NULL)
	{
		int contador = 0;
		while(1)
		{
			CadastroObras p;
		
		
			int registro = fread(&p, sizeof(CadastroObras), 1, arq);
			
		
			if(registro < 1)
				break;
			else
				obras[contador] = p;
			contador++;
		}
		fclose(arq); 
		return contador;
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); 
	}
}

void cadastrarObras(CadastroObras obras[MAX])
{
	identificacao();
	FILE * arq;
 
	arq = fopen("arquivo.txt", "a+");

	if(arq != NULL)
	{
		printf("\nInforme o Tipo da Obra - [1] Livros | [2] Revistas: ");
		fflush(stdin);
		scanf("%d", &obras[i].tipo);
		fflush(stdin);
		printf("\nInforme o Código da Obra: ");
		scanf("%d", &obras[i].codigo);
		fflush(stdin);
		printf("\nInforme o Título: ");
		fflush(stdin);
		gets(obras[i].titulo);
		printf("\nInforme o Autor: ");
		fflush(stdin);
		gets(obras[i].nomeAutor);
		printf("\nInforme a Editora: ");
		fflush(stdin);
		gets(obras[i].editora);
		printf("\nInforme o ISBN: ");
		fflush(stdin);
		gets(obras[i].isbn);
		printf("\nInforme a Edição: ");
		fflush(stdin);
		gets(obras[i].edicao);
		printf("\nInforme o Ano: ");
		fflush(stdin);
		scanf("%d",&obras[i].ano);
		printf("\nInforme a quantidade de exemplares: ");
		fflush(stdin);
		scanf("%d",&obras[i].quantidade);
		printf("\nInforme a caixa que deseja cadastrar [1] | [2] | [3]: ");
		fflush(stdin);
		scanf("%d",&obras[i].caixa);
		fwrite(&obras[i], sizeof(CadastroObras), 1, arq);
		fclose(arq); 
	}else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); 
	}
}


void ListarObrasCaixa (int buscaCaixa, CadastroObras obras[MAX]){	
	identificacao();
	
	int quantidadeobras = contarRegistro(obras);
	int j,t;
	
	printf("\n>>>> Lista de Produtos por categoria <<<< \n");
	if (buscaCaixa == 1) {
		printf("Caixa 1 \n");	
	}else if (buscaCaixa == 2) {
		printf("Caixa 2 \n");	
	}else if (buscaCaixa == 3) {
		printf("Caixa 3 \n");	
	}
	
	for(j = 0; j < quantidadeobras; j++){
		if(obras[j].caixa == buscaCaixa){
		printf("\n\t Código: %d \t Título: %s \n\t Autor: %s\t Editora: %s \n\t ISBN:%s \t Edição:%s \tAno:%d \t Quantidade:%d\n", obras[j].codigo, obras[j].titulo, obras[j].nomeAutor, obras[j].editora, obras[j].isbn, obras[j].edicao, obras[j].ano, obras[j].quantidade);
		for(t=0; t<80; t++) printf("-");
		printf("\n");	
		}
	}
}

void ListarLivros (int buscaLivro, CadastroObras obras[MAX]){	
	identificacao();
	
	int quantidadeobras = contarRegistro(obras);
	int j,t;
	buscaLivro=1;
	
	for(j = 0; j < quantidadeobras; j++){
		if(obras[j].tipo == buscaLivro){
		printf("\n\t Código: %d \t Título: %s \n\t Autor: %s\t Editora: %s \t ISBN:%s \n\t Edição:%s \tAno:%d \t Quantidade:%d \t Caixa:%d\n", obras[j].codigo, obras[j].titulo, obras[j].nomeAutor, obras[j].editora, obras[j].isbn, obras[j].edicao, obras[j].ano, obras[j].quantidade,obras[j].caixa);
		for(t=0; t<80; t++) printf("-");
		printf("\n");	
		}
	}
}

void ListarRevistas (int buscaRevista, CadastroObras obras[MAX]){	
	identificacao();
	
	int quantidadeobras = contarRegistro(obras);
	int j,t;
	buscaRevista=2;
	
	for(j = 0; j < quantidadeobras; j++){
		if(obras[j].tipo == buscaRevista){
		printf("\n\t Código: %d \t Título: %s \n\t Autor: %s\t Editora: %s \n\t ISBN:%s \t Edição:%s \tAno:%d \t Quantidade:%d \t Caixa:%d\n", obras[j].codigo, obras[j].titulo, obras[j].nomeAutor, obras[j].editora, obras[j].isbn, obras[j].edicao, obras[j].ano, obras[j].quantidade,obras[j].caixa);
		for(t=0; t<80; t++) printf("-");
		printf("\n");	
		}
	}
}
