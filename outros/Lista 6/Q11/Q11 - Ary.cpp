#include <stdio.h>
#include <stdlib.h>
#define MAX 10 // máximo do vetor de células (ver na função main)


/*
	Estrutura célula contendo os seguintes campos:
		- valor
		- linha e coluna (posição da célula)
		- ponteiro para o próximo elemento
		- ponteiro para o elemento anterior
*/
typedef struct celula
{
	int valor;
	int lin, col;
	struct celula *prox;
	struct celula *ant;
} t_celula;


// variáveis globais
t_celula *primeiro; // primeiro elemento da lista
t_celula *ultimo; // último elemento da lista


// protótipos de funções
t_celula* criar_celula(int lin, int col, int valor);
void inserir(t_celula *novo);
void deletar(int lin, int col);
int vazia();
t_celula* existe_celula(int lin, int col);
void imprimir_elementos();
void imprimir_matriz();


/* Função que cria uma nova celula passando a linha e coluna */
t_celula* criar_celula(int lin, int col, int valor)
{
	t_celula * novo;

	// aloca espaço em memória
	novo = (t_celula*)malloc(sizeof(t_celula));

	// testa se houve falha na alocação
	if(!novo)
	{
		printf("Erro ao alocar memoria!!\n");
		exit(1);
	}

	// atribuição de variáveis
	novo->valor = valor;
	novo->lin = lin;
	novo->col = col;

	return novo;
}


/*
	Função que insere um novo elemento (célula) na matriz esparsa
	A lista é ordenada de acordo com o nome da célula
*/
void inserir(t_celula *novo)
{
	/*
		obtém uma célula passando a linha e coluna do novo elemento
		para verificar se a posição já está ocupada
	*/
	t_celula* cel = existe_celula(novo->lin, novo->col);

	if(!cel) // verifica se não existe
	{
		if(!ultimo)
		{
			/*
				Se o "ultimo" é NULL, então a lista está vazia, o "novo"
				será o primeiro elemento a ser inserido
			*/

			// o próximo e o anterior apontam para NULL
			novo->prox = NULL;
			novo->ant = NULL;

			// faz o "ultimo" e "primeiro" apontarem para "novo"
			ultimo = novo;
			primeiro = novo;
		}
		else
		{
			// "p" serve para percorrer a lista
			// "ant" aponta para o anterior de "p"
			t_celula *p, *ant;


			p = primeiro; // começa do topo da lista
			ant = p->ant; // "ant" é o anterior ao "p", ou seja, NULL

			// poderia fazer também: ant = NULL;

			// percorre a lista
			while(p) // enquanto "p" diferente de NULL
			{
				/*
					Se a célula corrente "p" precede a
					célula "novo", então continua percorrendo
				*/
				if((p->lin < novo->lin) || ((p->lin == novo->lin) && (p->lin + p->col) < (novo->lin + novo->col)))
				{
					ant = p; // guarda o anterior
					p = p->prox; // aponta para o próximo
				}
				else
				{
					/*
						Se cair aqui é porque encontramos
						onde inserir a nova célula
					*/

					/*
						Se p->ant é diferente de NULL, então trata-se
						de um elemento intermediário
					*/
					if(p->ant)
					{
						/*
							p->ant é a célula que contém um nome imediatamente
							anterior à nova célula que será invetserida.
							Então dizemos que o próximo de p->ant irá apontar
							para essa nova célula
						*/
						p->ant->prox = novo;

						/*
							Se p->ant é a célula imediatamente anterior à
							célula "novo", então "p" é a célula imediatamente
							posterior à célula "novo", por isso dizendos que o
							próximo de "novo" aponta para "p'.
						*/
						novo->prox = p;

						// novo->ant tem que apontar para o p->ant
						novo->ant = p->ant;

						// faz p->ant apontar para o novo
						p->ant = novo; // correção de: novo->avetnt = i;

						return; // sai da função
					}

					/*
						Se chegar aqui é porque p->ant é NULL, então
						iremos inserir o novo elemento no início, ou seja,
						o "novo" será o novo primeiro da lista
					*/

					novo->prox = p; // o próximo do novo aponta para "p"
					novo->ant = NULL; // o anterior aponta para NULL (primeiro da lista)
					p->ant = novo; // faz o anterior de "p" apontar para o novo
					primeiro = novo; // "primeiro" aponta para "novo"

					return; // sai da função
				}
			}

			/*
				Se chegou aqui, então insere no final, agora preciso
				da variável "ant".
			*/

			// faz o próx. do antigo último apontar para "novo"
			ant->prox = novo;

			// como o "novo" agora é o último, então o próximo dele
			// aponta para NULL
			novo->prox = NULL;

			// o anterior ao "novo" aponta para o "ant"
			novo->ant = ant;

			// atualiza o último elemento da lista
			ultimo = novo;
		}
	}
	else
	{
		// se já existe então sobrescreve o valor
		cel->valor = novo->valor;
	}
}


// Função que deleta um elemento pela posição (linha e coluna)
void deletar(int lin, int col)
{
	// verifica se existe a célula (elemento)
	if(existe_celula(lin, col))
	{
		// remove do começo
		if(primeiro->lin == lin && primeiro->col == col)
		{
			// pego o apontador para o próximo
			t_celula *prox = primeiro->prox;

			free(primeiro); // libera memória

			// verifico se o próximo existe
			if(prox)
				prox->ant = NULL; // atualizo o anterior

			// faz o "primeiro" ser o "prox"
			primeiro = prox;

			return; // sai da função
		}

		/*
			Se chegou aqui é porque NÃO irá remover do início e
			existe mais de 1 elemento
		*/
		t_celula *p = primeiro->prox;

		// percorre a lista
		while(p)
		{
			if(p->lin == lin && p->col == col)
			{
				if(p->prox) // testa se NÃO é o último elemento
				{
					/*
						Faço o próximo do anterior de "p" apontar
						para o próximo de "p"
					*/
					p->ant->prox = p->prox;

					/*
						Faço o anterior do proximo de "p" apontar
						para o anterior de "p"
					*/
					p->prox->ant = p->ant;
				}
				else
				{
					// se chegou aqui, é porque é o último elemento

					// faz o proximo do anterior de "p" apontar para NULL
					p->ant->prox = NULL;

					// faz o anterior de "p" ser o "ultimo"
					ultimo = p->ant;
				}

				free(p); // libera o "p"
				return; // sai da função
			}
			p = p->prox;
		}
	}
}


// Função que verifica se a lista está vazia
int vazia()
{
	if(!ultimo) // se o último for NULL, então a lista está vazia
		return 1;
	return 0;
}


// Função que verifica se um elemento existe pela posição (linha e coluna)
t_celula* existe_celula(int lin, int col)
{
	t_celula* p = primeiro;

	while(p) // percorre a lista
	{
		// verifica a linha e a coluna
		if(lin == p->lin && col == p->col)
			return p; // retorna a célula
		p = p->prox;
	}
	return NULL;
}


// Função que imprime os lementos da lista
void imprimir_elementos()
{
	t_celula* p = primeiro;

	while(p) // percorre a lista
	{
		printf("(%d,%d)\n", p->lin, p->col);
		p = p->prox;
	}
}


// Função para imprimir a matriz convencional
// "X" indica o elemento repetido da matriz esparsa (pode ser um 0 por exemplo)
void imprimir_matriz()
{
	if(!vazia()) // verifica se a lista NÃO está vazia
	{
		/*
			Obtendo a maior linha, basta saber a do último
			porque está ordenado pela linha
		*/
		int total_linhas = ultimo->lin;

		// obtendo o total de colunas
		int total_colunas = -1;
		t_celula* p = primeiro;
		while(p) // percorre a lista para obter o total de colunas
		{
			if(p->col > total_colunas)
				total_colunas = p->col;
			p = p->prox;
		}

		for(int i = 0; i < total_linhas; i++)
		{
			for(int j = 0; j < total_colunas; j++)
			{
				// busca por um elemento passando a linha e coluna
				t_celula* cel = existe_celula(i + 1, j + 1);

				if(cel) // testa se encontrou o elemento
					printf("%d\t", cel->valor);
				else // se não existe o elemento, então imprime 'X'
					printf("X\t");
			}
			printf("\n");
		}
	}
	else
		printf("\nLista vazia!!\n");
}


int main(int argc, char * argv[])
{
	t_celula *vet[MAX]; // vetor de células

	// passa a linha e coluna da célula
	vet[0] = criar_celula(2, 1, 10);
	vet[1] = criar_celula(1, 2, 20);
	vet[2] = criar_celula(10, 3, 30);
	vet[3] = criar_celula(1, 1, 40);
	vet[4] = criar_celula(3, 2, 50);
	vet[5] = criar_celula(2, 8, 60);
	vet[6] = criar_celula(3, 1, 70);
	vet[7] = criar_celula(4, 2, 80);
	vet[8] = criar_celula(3, 3, 90);
	vet[9] = criar_celula(1, 6, 100);

	if(vazia()) // verifica se a lista está vazia
		printf("\nLista vazia!!\n");
	else
		printf("\nLista NAO vazia!!\n");

	// insere os elementos (células)
	for(int i = 0; i < MAX; i++)
		inserir(vet[i]);

	if(vazia()) // verifica se a lista está vazia
		printf("\nLista vazia!!\n");
	else
		printf("\nLista NAO vazia!!\n");

	printf("\nImprimindo os elementos da lista:\n");
	imprimir_elementos(); // imprime a matriz

	printf("\nImprimindo a matriz esparsa (X eh o elemento que se repete):\n");
	imprimir_matriz(); // imprime a matriz

	deletar(10, 3); // deletando a célula da posição (10,3)

	printf("\nImprimindo a matriz esparsa (X eh o elemento que se repete):\n");
	imprimir_matriz(); // imprime a matriz

	return 0;
}
