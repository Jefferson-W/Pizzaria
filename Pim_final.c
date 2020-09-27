
/*

Nome: Jefferson Willian Santos Lopes da Silva --------> RA: N471590;  DS2P22
Nome: Mark Castro Soares -------------------------- >	RA: D94FDC1;  DS2Q22
Nome: Rafael de Almeida Gomes –--------------------- >	RA: N439JA-5; DS2P22
Nome: Rafaela Dantas Rodrigues Henrique ------------->  RA: F122G-7;  DS1P22
Nome: Sarah Naiane dos Santos –------------------ >		RA: N5318G7;  DS1P22 
Nome: Soraya Alvim Puraca De Nigris –-------------->    RA: F0033b4;  DS2Q22
====================================================================================
APRESENTAÇÃO: DIA 11/12/2019  -  HORA 21:10
====================================================================================
GRUPO Nº 11;
====================================================================================
CAMINHO DE ARQUIVOS:

"C:\\Users\\Iara\\Desktop\\arquivos\\gravarprodutos.bin"
"C:\\Users\\Iara\\Desktop\\arquivos\\gravarclientes.bin"
"C:\\Users\\Iara\\Desktop\\arquivos\\gravarpedidos.bin"
"C:\\Users\\Iara\\Desktop\\arquivos\\gravarcolaboradores.bin"

====================================================================================
SISTEMA PARA O CONTROLE DE UNIDADES DE UMA REDE DE PIZZARIA.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ======================================== PROTOTIPOS =============================================


int localiza_cliente(int idcliente);
void inicializafuncionarios();
void inicializaclientes();
void inicializaprodutos();
void inicializaarquivo();
void gravaprodutos();
int localiza_produto(int codigo);
void loginpizzaria();
void gravaclientes();
void tela001();
void texto1();
int localiza_pedidos(int codigopedido);
void inicializapedidos();
void gravapedidos();
void texto2();
void inicializacolaboradores();
int localiza_colaboradores(int codigocolaborador);
void gravacolaboradores();
void texto3();
void relatorio1();
void relatorio2();
void relatorio3();
void relatorio4();
void valortotal();
void valortotalunidade();
void menurelatorios();
void cancelapedido();



// ========================================== STRUCTS ==================================================



struct clientes
{
    int idcliente;
    char nomecliente[50];
    char fone[20];
    char cpf[12];
    char end[50];
}mClientes[100];


struct funcionarios
{
    char loginfuncionario[10];
    char senhafuncionario[7];
	int unidadefuncionario;
}mFuncionarios[4];



struct produtos
{
    int codigo;
    char nomeproduto[50];
    float qtdproduto;
    float precoproduto;
}mProdutos[100];



struct pedidos
{
	char nomecliente[50];
	int codigopedido;
	int unidade;
	char itens[50];
	int precototal;
}mPedidos[100];


struct colaboradores
{
	int codigocolaborador;
	char nomecolaborador[50];
	int unidadecolaborador;
	char funcao[20];
}mColaboradores[100];

 
// ----------------------------------FUNÇÃO PARA LIMPAR O BUFFER----------------------------------


void limpabuffer()

{
char c;
while ((c=getchar()) != '\n' && c!= EOF); // GETCHAR (PEGA O CARACTER DO BUFFER E JOGA FORA), '\N' QUANDO O USUÁRIO DIGITA ENTER
}



// ========================================== FUNCIONARIOS ==================================================


void inicializafuncionarios(){

strcpy(mFuncionarios[0].loginfuncionario,"pizzaria0");
strcpy(mFuncionarios[1].loginfuncionario,"pizzaria1");
strcpy(mFuncionarios[2].loginfuncionario,"pizzaria2");

strcpy(mFuncionarios[0].senhafuncionario,"123456");
strcpy(mFuncionarios[1].senhafuncionario,"123456");
strcpy(mFuncionarios[2].senhafuncionario,"123456");

mFuncionarios[0].unidadefuncionario = 1;
mFuncionarios[1].unidadefuncionario = 2;
mFuncionarios[2].unidadefuncionario = 3;

}

// ================================================= LOGIN UNIDADES ==================================================



void loginpizzaria(){

char comparalogin[10];
char comparasenha[7];


printf ("================================================================================");

printf ("\n\t *** BEM VINDO (A) A TELA DE LOGIN ***\n\n");
printf ("CASO NAO SAIBA SEUS DADOS DE ACESSO, ENTRAR EM CONTATO COM O ADM DA SUA UNIDADE\n\n");

printf ("================================================================================\n\n\n");

inicializafuncionarios();

fflush(stdin);
printf ("\n Digite o login da pizzaria: ");
fgets (comparalogin, 10, stdin);

fflush(stdin);
printf ("\n Digite a senha da pizzaria: ");
fgets (comparasenha, 7, stdin);


  if (strcmp (comparalogin,mFuncionarios[0].loginfuncionario) == 0)
  {
	  if (strcmp(comparasenha, mFuncionarios[0].senhafuncionario)==0)
	  {
        system ("cls");

		printf ("\n\t***** BEM VINDO PIZZARIA (0) *****\n\n"); 
		printf ("\n\t** Unidade acessada: %d **\n", mFuncionarios[0].unidadefuncionario);
		printf ("\n\t** Tecle ENTER para continuar!! **\n\n");
		
		system ("pause");
        tela001();
		system ("pause");
	  }
  }
	else if (strcmp (comparalogin,mFuncionarios[1].loginfuncionario)==0)
	{
		if (strcmp(comparasenha, mFuncionarios[1].senhafuncionario)==0)
		{
		system ("cls");

		printf ("\n\t***** BEM VINDO PIZZARIA (1) *****\n\n"); 
		printf ("\n\t** Unidade acessada: %d **\n", mFuncionarios[1].unidadefuncionario);
		printf ("\n\t** Tecle ENTER para continuar!! **\n\n");
		
		system ("pause");
		tela001();
		system ("pause");
		}
	}
    else if (strcmp (comparalogin,mFuncionarios[2].loginfuncionario) == 0)
	{
		if (strcmp(comparasenha, mFuncionarios[2].senhafuncionario)==0)
		{
        system ("cls");

		printf ("\n\t***** BEM VINDO PIZZARIA (2) *****\n\n"); 
		printf ("\n\t** Unidade acessada: %d **\n", mFuncionarios[2].unidadefuncionario);
		printf ("\n\t** Tecle ENTER para continuar!! **\n\n");
		
		system ("pause");
		tela001();
		system ("pause");

		}
	}

 else

	printf("\n*** CADASTRO INVALIDO!!***\n\n");
	system ("pause");

}


// ==================================================== CLIENTES ==================================================


void inicializaclientes(){

FILE* arqclientes = NULL;

int i=0;
for (i=0; i <  sizeof(mClientes) / sizeof(struct clientes); i++) {

	if (i==0)
		mClientes[i].idcliente = 1;
	else
		mClientes[i].idcliente = -1;


strcpy(mClientes[i].nomecliente, "------");
strcpy (mClientes[i].cpf, "0");
strcpy(mClientes[i].fone, "0");
strcpy(mClientes[i].end, "-");

    }

arqclientes = fopen ("C:\\Users\\Iara\\Desktop\\arquivos\\gravarclientes.bin","rb");

if (arqclientes != NULL)
{
		i = 0;
		while (!feof(arqclientes) && i < 100)

		{
			fread(&mClientes[i], sizeof(struct clientes), 1, arqclientes);
			i++;
		}
		fclose(arqclientes);
	}
}



int localiza_cliente(int idcliente){

int i=0;

while (i< sizeof (mClientes) / sizeof(struct clientes) && mClientes[i].idcliente != -1)

{
    if (mClientes[i].idcliente == idcliente)
        return i;
        i++;

}
    if (mClientes[i].idcliente == -1)
		return -i;

	return -32000; //Significa que a matriz de CLientes esta cheia e nao localizou o CPF pesquisado

}


void gravaclientes(){

FILE* arqclientes = NULL;

int idcliente;
int retorno;
char opcao;

system ("cls");

printf ("================================================================================");
printf ("\n Digite o ID  do cliente a ser pesquisado: ");
scanf ("%d", &idcliente);

retorno = localiza_cliente(idcliente); //RETORNO RECEBE, OU O CPF, OU -1 (NÃO ENCONTRANDO O CPF, RETORNANDO A POSIÇÃO A SER CADASTRADA)



if (retorno>0) //LOCALIZOU
{
    system ("cls");

    printf ("\n\t ** CLIENTE LOCALIZADO!! **");
    printf ("\n\n Nome: %s", mClientes[retorno].nomecliente);
    printf ("\n CPF: %s", mClientes[retorno].cpf);
    printf ("\n Fone: %s", mClientes[retorno].fone);
    printf ("\n Endereco: %s", mClientes[retorno].end);
    printf ("\n IDCliente: %d\n\n", mClientes[retorno].idcliente);
    system ("pause");

}

else
{
    do
    {
        char cadastro;
        //deseja cadastrar?

        fflush (stdin);
		printf("\n Cliente nao encontrado! Deseja cadastrar? (s/n): ");
		scanf("%c", &cadastro);
		if (cadastro == 's')
		{
			//caso positivo, entrar dados
            system ("cls");
			printf ("================================================================================");
            printf ("\nSera gravado na posicao: %d\n", retorno);
            
            fflush(stdin);
			printf("\n\nDigite o ID do novo Cliente: ");
			scanf ("%d", &mClientes[-retorno].idcliente);

            fflush(stdin);
            printf("\nDigite o Nome do novo Cliente: ");
			fgets(mClientes[-retorno].nomecliente, 50, stdin);

            fflush(stdin);
			printf("\nDigite o CPF do novo Cliente: ");
			fgets(mClientes[-retorno].cpf, 12, stdin);

            fflush(stdin);
			printf("\nDigite o Fone do novo Cliente: ");
			fgets (mClientes[-retorno].fone, 20, stdin);

            fflush(stdin);         
			printf("\nDigite Endereco do novo Cliente: ");
			fgets (mClientes[-retorno].end, 50, stdin);

			arqclientes = fopen("C:\\Users\\Iara\\Desktop\\arquivos\\gravarclientes.bin", "a+b");
			fwrite(&mClientes[-retorno], sizeof(struct clientes), 1, arqclientes);
			fclose(arqclientes);
            
			fflush (stdin);
            printf ("\n\nCONFIRMA OS DADOS? (s/n)");
            scanf ("%c", &opcao);
		}
else 
    tela001();

    } while (opcao == 'n');
  }
    
}

// =================================================== PRODUTOS ==================================================

void inicializaprodutos(){

FILE* arqprodutos = NULL;

int i=0;
for (i = 0; i < sizeof(mProdutos) / sizeof(struct produtos); i++) {
		if(i==0)
			mProdutos[i].codigo = 1;
		else
			mProdutos[i].codigo = -1;

strcpy(mProdutos[i].nomeproduto, "------");
mProdutos[i].qtdproduto = 0.0;
mProdutos[i].precoproduto = 0.0;
    }

arqprodutos = fopen ("C:\\Users\\Iara\\Desktop\\arquivos\\gravarprodutos.bin", "rb");
if (arqprodutos != NULL)
	{
		i = 0;
		while (!feof(arqprodutos) && i < 100)

		{
			fread(&mProdutos[i], sizeof(struct produtos), 1, arqprodutos);
			i++;
		}
		fclose(arqprodutos);
	}

}



int localiza_produto(int codigo)
{
	int i=0;
	while (i < sizeof(mProdutos)/sizeof(struct produtos) && mProdutos[i].codigo != -1)

	{
		if (mProdutos[i].codigo == codigo)
			return i;
		i++;
	}
	
	if (mProdutos[i].codigo == -1)
		return -i;

	return -32000; //Significa que a matriz de produtos esta cheia e nao localizou o produto pesquisado

}

void gravaprodutos(){

FILE* arqprodutos=NULL;

int retorno, cod_prod;
char opcao;
system ("cls");
texto1();
printf ("================================================================================");

printf("\n Digite o codigo produto a ser procurado: ");
scanf ("%d", &cod_prod);

retorno = localiza_produto (cod_prod);

if (retorno>0){ // localizou


system ("cls");

printf ("\n\t ** PRODUTO LOCALIZADO!! **");
printf ("\n\n Descricao: %s", mProdutos[retorno].nomeproduto);
printf ("\n Codigo: %d", mProdutos[retorno].codigo);
printf ("\n\n QTD Estoq: %2.f", mProdutos[retorno].qtdproduto);
printf ("\n\n Preco: %3.f\n\n", mProdutos[retorno].precoproduto);
system ("pause");
   
    } 
    
 else {

     do {
    
    char cadastro;
    //deseja cadastrar?
        fflush (stdin);
		printf("\n\n Produto nao encontrado. Deseja cadastrar? (s/n): ");
		scanf("%c", &cadastro);
		if (cadastro == 's')
		{
			//caso positivo, entrar dados
            system ("cls");
			limpabuffer();
            printf ("\nSera gravado na posicao: %d\n", retorno);
            
            fflush(stdin);
            printf("\nDigite o Codigo do novo Produto: ");
			scanf ("%d", &mProdutos[-retorno].codigo);

            fflush(stdin);
			printf("\n\nDigite o Nome do novo Produto: ");
			fgets(mProdutos[-retorno].nomeproduto, 50, stdin);

			printf("\nDigite a QTD do novo Produto em estoque: ");
			scanf("%f", &mProdutos[-retorno].qtdproduto);
            
			printf("\nDigite o Preco de venda: ");
			scanf("%f", &mProdutos[-retorno].precoproduto);

			arqprodutos = fopen("C:\\Users\\Iara\\Desktop\\arquivos\\gravarprodutos.bin", "a+b");
			fwrite(&mProdutos[-retorno], sizeof(struct produtos), 1, arqprodutos);
			fclose(arqprodutos);
            
            fflush (stdin);
            printf ("\n\nCONFIRMAR NOVO CADASTRO? (s/n)");
            scanf ("%s", &opcao);
		}
		else 
    tela001();
     }while (opcao == 'n');


    } 


}


// ======================================== PEDIDOS ===========================================

void inicializapedidos(){

FILE* arqpedidos = NULL;

int i=0;
for (i = 0; i < sizeof(mPedidos) / sizeof(struct pedidos); i++) {
		if(i==0)
			mPedidos[i].codigopedido = 1;
		else
			mPedidos[i].codigopedido = -1;

strcpy(mPedidos[i].nomecliente, "------");
strcpy(mPedidos[i].itens, "----");
mPedidos[i].precototal = 0;
mPedidos[i].unidade = 0;
    }

arqpedidos = fopen ("C:\\Users\\Iara\\Desktop\\arquivos\\gravarpedidos.bin", "rb");
if (arqpedidos != NULL)
	{
		i = 0;
		while (!feof(arqpedidos) && i < 100)

		{
			fread(&mPedidos[i], sizeof(struct pedidos), 1, arqpedidos);
			i++;
		}
		fclose(arqpedidos);
	}

}



int localiza_pedidos (int codigopedido){

int i=0;
	while (i < sizeof(mPedidos) / sizeof(struct pedidos) && mPedidos[i].codigopedido != -1)

	{
		if (mPedidos[i].codigopedido == codigopedido)
			return i;
		i++;
	}
	
	if (mPedidos[i].codigopedido == -1)
		return -i;

	return -32000; //Significa que a matriz de produtos esta cheia e nao localizou o produto pesquisado

}

void gravapedidos(){


FILE* arqpedidos = NULL;

int retorno, cod_pedido;
char opcao;
system ("cls");
texto2();
printf ("================================================================================");

printf("\n Digite o Codigo do Pedido a ser procurado: ");
scanf ("%d", &cod_pedido);

retorno = localiza_pedidos (cod_pedido);

printf ("Retorno: %d", retorno);

if (retorno>0){ // localizou

system ("cls");

printf ("\n\t ** PEDIDO ENCONTRADO!! **");
printf ("\n\n Codido do Pedido: %d", mPedidos[retorno].codigopedido);
printf ("\n\n Itens do Pedido: %s", mPedidos[retorno].itens);
printf ("\n\n Nome do Cliente: %s", mPedidos[retorno].nomecliente);
printf ("\n\n Preco Total: %d", mPedidos[retorno].precototal);
printf ("\n\n Unidade: %d\n", mPedidos[retorno].unidade);
system ("pause");
   
    } 


else{

		do
		{
	char cadastro;

	fflush(stdin);
	printf ("\n\n Pedido nao encontrado! Deseja cadastrar? (s/n)");
	scanf ("%c", &cadastro);

	if (cadastro == 's')
		{
			//caso positivo, entrar dados
            system ("cls");
			limpabuffer();
            printf ("\nSera gravado na posicao: %d\n", retorno);
            
            fflush(stdin);
            printf("\nDigite o Codigo do novo Pedido: ");
			scanf ("%d", &mPedidos[-retorno].codigopedido);

            fflush(stdin);
			printf("\n\nDigite a Unidade do novo Pedido: ");
			scanf ("%d", &mPedidos[-retorno].unidade);

			fflush(stdin);
			printf("\nDigite o Nome do Cliente: ");
			fgets (mPedidos[-retorno].nomecliente, 50, stdin);
			
			fflush(stdin);
			printf("\nDigite os Itens do Pedido: ");
			fgets (mPedidos[-retorno].itens, 50, stdin);
            
			printf("\nDigite o Preco Total do Pedido: ");
			scanf("%d", &mPedidos[-retorno].precototal);

			arqpedidos = fopen("C:\\Users\\Iara\\Desktop\\arquivos\\gravarpedidos.bin", "a+b");
			fwrite(&mPedidos[-retorno], sizeof(struct pedidos), 1, arqpedidos);
			fclose(arqpedidos);
            
            fflush (stdin);
            printf ("\n\nCONFIRMAR NOVO CADASTRO? (s/n)");
            scanf ("%s", &opcao);

		} 
		else 
    tela001();
		}while (opcao == 'n');
	}

}


// ========================================= COLABORADORES =======================================


void inicializacolaboradores(){

FILE* arqcolaboradores = NULL;

int i=0;

for (i=0; i < sizeof (mColaboradores) / sizeof (struct colaboradores); i++){

	if (i==0)
	mColaboradores[i].codigocolaborador = 1;
	else
	mColaboradores[i].codigocolaborador = -1;

strcpy (mColaboradores[i].nomecolaborador, "------");
strcpy (mColaboradores[i].funcao, "----");
mColaboradores[i].unidadecolaborador = 0;

}

arqcolaboradores = fopen("C:\\Users\\Iara\\Desktop\\arquivos\\gravarcolaboradores.bin", "rb");

if (arqcolaboradores != NULL)
	{
		int i=0;
		while (!feof(arqcolaboradores) && i<100)
		{
			fread (&mColaboradores[i], sizeof (struct colaboradores), 1, arqcolaboradores);
			i++;
		}
		
		fclose (arqcolaboradores);
	}
}



int localiza_colaboradores(int codigocolaborador){

int i=0;

while (i < sizeof (mColaboradores) / sizeof (struct colaboradores) && mColaboradores[i].codigocolaborador != -1) 
{
	if (mColaboradores[i].codigocolaborador == codigocolaborador)
		return i;
	i++;

}
	if (mColaboradores[i].codigocolaborador == -1)
		return -i;

	return -32000;

}

void gravacolaboradores(){

FILE* arqcolaboradores = NULL;

int retorno, cod_colab;
char opcao;

system ("cls");
texto3();

printf ("================================================================================");
printf("\n Digite o Codigo do Colaborador a ser procurado: ");
scanf ("%d", &cod_colab);

retorno = localiza_colaboradores (cod_colab);

if (retorno>0){ // localizou

system ("cls");

printf ("\n\t ** COLABORADOR ENCONTRADO!! **");
printf ("\n\n Codido do Colaborador: %d", mColaboradores[retorno].codigocolaborador);
printf ("\n\n Funcao: %s", mColaboradores[retorno].funcao);
printf ("\n\n Nome do Colaborador: %s", mColaboradores[retorno].nomecolaborador);
printf ("\n\n Unidade: %d\n", mColaboradores[retorno].unidadecolaborador);
system ("pause");
   
    } 


else{

		do

		{
	char cadastro;

	fflush(stdin);
	printf ("\n\n Colaborador nao encontrado! Deseja cadastrar? (s/n)");
	scanf ("%c", &cadastro);

if (cadastro == 's')
	{
		//caso positivo, entrar dados

        system ("cls");

		limpabuffer();

        printf ("\nSera gravado na posicao: %d\n", retorno);
            
        fflush(stdin);
        printf("\nDigite o Codigo do novo Colaborador: ");
		scanf ("%d", &mColaboradores[-retorno].codigocolaborador);

         fflush(stdin);
		printf("\n\nDigite a Unidade do Colaborador: ");
		scanf ("%d", &mColaboradores[-retorno].unidadecolaborador);

		fflush(stdin);
		printf("\nDigite o Nome do Colaborador: ");
		fgets (mColaboradores[-retorno].nomecolaborador, 50, stdin);
			
		fflush(stdin);
		printf("\nDigite a Funcao do Colaborador: ");
		fgets (mColaboradores[-retorno].funcao, 20, stdin);

		arqcolaboradores = fopen("C:\\Users\\Iara\\Desktop\\arquivos\\gravarcolaboradores.bin", "a+b");
		fwrite(&mColaboradores[-retorno], sizeof(struct colaboradores), 1, arqcolaboradores);
		fclose(arqcolaboradores);
            
        fflush (stdin);
        printf ("\n\nCONFIRMAR NOVO CADASTRO? (s/n)");
        scanf ("%s", &opcao);

	} 
	else 
    tela001();
	}while (opcao == 'n');

  }

}


// ======================================== INT MAIN =============================================


int main (){

// inicializafuncionarios();
 inicializacolaboradores();
 inicializapedidos();
 inicializaclientes();
 inicializaprodutos();

loginpizzaria();  // FUNCIONARIO IRÁ FAZER SEU LOGIN


 }

 
// =============================================== TELAS ================================================

void tela001(){
int opcao;

do {

system ("cls");

printf ("\n\t**** MENU PRINCIPAL **** \n\n\n");
printf ("\n1 - CADASTRO DE CLIENTE: \n\n");
printf ("\n2 - CADASTRO DE PRODUTO: \n\n");
printf ("\n3 - CADASTRO DE PEDIDOS: \n\n");
printf ("\n4 - CADASTRO DE COLABORADOR: \n\n");
printf ("\n5 - CANCELAR PEDIDO: \n\n");
printf ("\n6 - RELATORIOS: \n\n");
printf ("\n0 - SAIR: \n");

printf ("\nDigite a opcao desejada: \n");
scanf ("%d", &opcao);

switch (opcao)

    {
case 1: gravaclientes();break;
case 2: gravaprodutos();break;
case 3: gravapedidos();break;
case 4: gravacolaboradores();break;
case 5: cancelapedido();break;
case 6: menurelatorios();break;

    }

}while (opcao != 0);

}


void texto1(){

    printf ("\n\t ** PREZADO FUNCIONARIO (A) **");
    printf ("\nCASO O PRODUTO NAO ESTEJA CADASTRADO, O SISTEMA IRA");
    printf ("\nRETORNAR A PROXIMA POSICAO DISPONIVEL, EX: -3");
    printf ("\n\nASS: ADM\n\n");
    system ("pause");
    system ("cls");
}


void texto2(){
	
	printf ("\n\t ** PREZADO FUNCIONARIO (A) **");
    printf ("\nCASO O PEDIDO NAO ESTEJA CADASTRADO, O SISTEMA IRA");
    printf ("\nRETORNAR A PROXIMA POSICAO DISPONIVEL, EX: -3");
    printf ("\n\nASS: ADM\n\n");
    system ("pause");
    system ("cls");

}

void texto3(){

	printf ("\n\t ** PREZADO FUNCIONARIO (A) **");
    printf ("\nCASO O COLABORADOR NAO ESTEJA CADASTRADO, O SISTEMA IRA");
    printf ("\nRETORNAR A PROXIMA POSICAO DISPONIVEL, EX: -3");
    printf ("\n\nASS: ADM\n\n");
    system ("pause");
    system ("cls");

}


// =========================================== RELATÓRIOS ==========================================

void menurelatorios(){

	int opcao;
	system ("cls");

	do
	{
system ("cls");

printf ("\n\t   **** MENU RELATORIOS ****: \n\n\n");
printf ("\n 1 - RELATORIO DE CLIENTES: \n\n");
printf ("\n 2 - RELATORIO DE PRODUTOS: \n\n");
printf ("\n 3 - RELATORIO DE PEDIDOS: \n\n");
printf ("\n 4 - RELATORIO DE COLABORADORES: \n\n");
printf ("\n 5 - RELATORIO VALOR TOTAL DOS PEDIDOS: \n\n");
printf ("\n 6 - RELATORIO VALOR TOTAL DOS PEDIDOS (POR UNIDADE): \n\n");
printf ("\n 0 - SAIR: \n");

	printf ("\n Digite a opcao desejada: ");
	scanf ("%d", &opcao);

	switch (opcao)

	{
	case 1: relatorio1();break;
	case 2: relatorio2();break;
	case 3: relatorio3();break;
	case 4: relatorio4();break;
	case 5: valortotal();break;
	case 6: valortotalunidade();break;

	}

	} while (opcao != 0);
	

}

void relatorio1(){

	int i=0;
	system ("cls");
	printf ("\n\t ** RELATORIO DE CLIENTES CADASTRADOS!! **\n\n");

	while (i < sizeof (mClientes) / sizeof (struct clientes) && mClientes[i].idcliente != -1)

	{
    printf ("\n\n Nome: %s", mClientes[i].nomecliente);
    printf ("\n CPF: %s", mClientes[i].cpf);
    printf ("\n\n Fone: %s", mClientes[i].fone);
    printf ("\n Endereco: %s", mClientes[i].end);
    printf ("\n IDCliente: %d\n\n", mClientes[i].idcliente);
	printf ("\n=======================================\n");
	i++;

	}

	system ("pause");
}

void relatorio2(){

	int i=0;
	system ("cls");
	printf ("\n\t ** RELATORIO DE PRODUTOS!! **\n\n");

	while (i < sizeof (mProdutos) / sizeof (struct produtos) && mProdutos[i].codigo != -1)

	{
	printf ("\n Codigo: %d", mProdutos[i].codigo);
	printf ("\n\n Descricao: %s", mProdutos[i].nomeproduto);
	printf ("\n QTD Estoq: %2.f", mProdutos[i].qtdproduto);
	printf ("\n\n Preco: %3.f\n", mProdutos[i].precoproduto);
	printf ("\n=======================================\n");
	i++;

	}

	system ("pause");

}


void relatorio3(){

	int i=0;
	system ("cls");
	printf ("\n\t ** RELATORIO DE PEDIDOS!! **\n\n");

	while (i < sizeof (mPedidos) / sizeof (struct pedidos) && mPedidos[i].codigopedido != -1)

	{
	printf ("\n\n Codigo do Pedido: %d", mPedidos[i].codigopedido);
	printf ("\n\n Itens do Pedido: %s", mPedidos[i].itens);
	printf ("\n Nome do Cliente: %s", mPedidos[i].nomecliente);
	printf ("\n Unidade: %d", mPedidos[i].unidade);
	printf ("\n\n Preco Total: %d\n", mPedidos[i].precototal);

	printf ("\n=======================================\n");
	i++;

	}

	system ("pause");
}


void relatorio4(){

	int i=0;
	system ("cls");
	printf ("\n\t ** RELATORIO DE COLABORADORES!! **\n\n");

	while (i < sizeof (mColaboradores) / sizeof (struct colaboradores) && mColaboradores[i].codigocolaborador != -1)

	{
	
	printf ("\n\n Codido do Colaborador: %d", mColaboradores[i].codigocolaborador);
	printf ("\n\n Funcao: %s", mColaboradores[i].funcao);
	printf ("\n Nome do Colaborador: %s", mColaboradores[i].nomecolaborador);
	printf ("\n Unidade: %d\n", mColaboradores[i].unidadecolaborador);

	printf ("\n=======================================\n");
	i++;

	}

	system ("pause");

}

void valortotal(){

	// inicializapedidos();
	int i=0;
	int valor2=0, valor1;

	system ("cls");
	printf ("\n\t ** RELATORIO VALOR TOTAL DOS PEDIDOS!! **\n\n");


	for (i=0;i<100;i++)				

	{
		if (mPedidos[i].codigopedido != -1)

		{
			
	valor1 = mPedidos[i].precototal;
	valor2 = valor1+valor2;

printf ("\n\n Codido do Pedido: %d", mPedidos[i].codigopedido);
printf ("\n\n Itens do Pedido: %s", mPedidos[i].itens);
printf ("\n Nome do Cliente: %s", mPedidos[i].nomecliente);
printf ("\n Preco Total: %d", mPedidos[i].precototal);
printf ("\n\n Unidade: %d\n", mPedidos[i].unidade);

printf ("\n=======================================\n");


		}	

	}

	printf ("\n\n VALOR TOTAL DE TODOS PEDIDOS = %d\n\n", valor2);
	system ("pause");

}


void valortotalunidade(){

//	inicializapedidos();

	int i=0;
	int valor2=0, valor1;
	int uni;
	system ("cls");
	printf ("\n\t ** RELATORIO VALOR TOTAL DOS PEDIDOS (POR UNIDADE)!! **\n\n");

	// fflush(stdin);
	printf ("\n Digite a unidade desejada! (1, 2, ou 3): ");
	scanf ("%d", &uni);


	for (i=0;i<100;i++)			

	{
		if (mPedidos[i].unidade == uni)

		{

	valor1 = mPedidos[i].precototal;
	valor2 = valor1+valor2;

printf ("\n\n Codido do Pedido: %d", mPedidos[i].codigopedido);
printf ("\n\n Itens do Pedido: %s", mPedidos[i].itens);
printf ("\n Nome do Cliente: %s", mPedidos[i].nomecliente);
printf ("\n Preco Total: %d", mPedidos[i].precototal);
printf ("\n\n Unidade: %d\n", mPedidos[i].unidade);

printf ("\n=======================================\n");


		}	

	}



printf ("\n\n VALOR TOTAL DE TODOS PEDIDOS = %d\n\n", valor2);
system ("pause");

}


// ================================ CANCELA PEDIDO ======================================

void cancelapedido(){

inicializapedidos();

FILE* arqpedidos = NULL;

int retorno, cod_pedido;
char opcao;

system ("cls");
printf ("================================================================================");

printf ("\n\t ** CANCELAMENTO DE PEDIDOS!! **\n\n");

printf("\n Digite o Codigo do Pedido a ser procurado para o Cancelamento: ");
scanf ("%d", &cod_pedido);

retorno = localiza_pedidos (cod_pedido);

printf ("\n Posicao: %d\n", retorno);

if (retorno>0){ // localizou

// system ("cls");

printf ("\n\t ** PEDIDO ENCONTRADO!! **");
printf ("\n\n Codido do Pedido: %d", mPedidos[retorno].codigopedido);
printf ("\n\n Itens do Pedido: %s", mPedidos[retorno].itens);
printf ("\n\n Nome do Cliente: %s", mPedidos[retorno].nomecliente);
printf ("\n\n Preco Total: %d", mPedidos[retorno].precototal);
printf ("\n\n Unidade: %d\n", mPedidos[retorno].unidade);
system ("pause");

fflush(stdin);
printf ("\n\n CONFIRMA O CANCELAMENTO DO PEDIDO?? (s/n): ");
scanf ("%c", &opcao);

if (opcao == 's')

{

mPedidos[retorno].codigopedido = -1;
strcpy(mPedidos[retorno].nomecliente, "------");
strcpy(mPedidos[retorno].itens, "----");
mPedidos[retorno].precototal = 0;
mPedidos[retorno].unidade = 0;
    

		arqpedidos = fopen ("C:\\Users\\Iara\\Desktop\\arquivos\\gravarpedidos.bin", "a+b");
		fwrite(&mPedidos[retorno], sizeof(struct pedidos), 1, arqpedidos);
		fclose(arqpedidos);
	
  } 
  // sair do if
}

else {

	printf ("\n\n ** NAO ENCONTRADO!! **\n\n");
	system ("pause");
	}

}