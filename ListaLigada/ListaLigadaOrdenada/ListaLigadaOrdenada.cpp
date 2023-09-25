#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL; 

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	// Se a lista estiver vazia
	if (primeiro == NULL)
	{
		primeiro = novo;
	}

	// Verifica se o elemento digitado já existe na lista
	else {
		int busca = 0;
		NO* aux = primeiro;
		while (aux != NULL) {
			if (aux->valor == novo->valor) {
				busca = 1;
				break;
			}
			aux = aux->prox;
		}
		if (busca == 1) {
			cout << "Esse elemento já existe na lista!" << endl;
			return;
		}

		else {
			// Se o elemento digitado for menor que o primeiro
			NO* aux = primeiro;
			if (aux == primeiro && novo->valor < aux->valor)
			{
				novo->prox = aux;
				primeiro = novo;
			}

			else { // Percorrer a lista para achar a posição onde deve ser inserido
				NO* aux = primeiro;
				while (aux->prox != NULL && novo->valor > aux->prox->valor) {
					aux = aux->prox;
				}

				novo->prox = aux->prox;
				aux->prox = novo;

			}
		}
	}
}

void excluirElemento()
{
	NO* excluir = NULL;
	int elemento;
	cout << "Qual elemento deseja excluir? " << endl;
	cin >> elemento;

	NO* aux = primeiro;
	// Verificando se o elemento a excluir é o primeiro da lista
	if (aux == primeiro && aux->valor == elemento) {
		excluir = aux;
		primeiro = aux->prox;
	}
	// Senão percorremos a lista para acha-lo, o anterior e o proximo
	else {
		NO* ant = primeiro;
		while (aux != NULL) {
			if (aux->valor == elemento) {
				excluir = aux;
				ant->prox = excluir->prox;
			}
			ant = aux;
			aux = aux->prox;
		}
	}

	if (excluir) {
		free(excluir);
		cout << "Elemento excluido com sucesso! \n";
	}
	else {
		cout << "Elemento nao encontrado!\n";
	}



}

void buscarElemento()
{
	int elemento, busca = 0;
	cout << "Digite o valor que deseja buscar: " << endl;
	cin >> elemento;

	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == elemento) {
			//cout << "Elemento encontrado!" << endl;
			busca = 1;
			break;
		}
		aux = aux->prox;
	}
	if (busca == 1) {
		cout << "Elemento encontrado!" << endl;
	}
	else {
		cout << "Elemento nao encontrado na lista!" << endl;
	}

}


