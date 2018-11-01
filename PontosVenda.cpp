#include "PontosVenda.h"

using namespace std;

/**
 * destrutor da classe
 */
PontosVenda::~PontosVenda(){

	for(unsigned i = 0; i < ptsVenda.size(); i++)
		delete ptsVenda.at(i);

	for(unsigned j= 0; j < utentes.size(); j++)
		delete utentes.at(j);

}


/**
 * metodo que imprime toda a informacao que possui sobre todos os pontos de venda da cidade
 */
void PontosVenda::imprime() const{

	//a implementar
}


/**
 * metodo que imprime a informacao relativa aos utentes que possuem um bilhete assinatura
 */
void PontosVenda::imprimeAssinantes() const{

	cout << "Informacao relativa a todos os assinantes:" << endl << endl;

	for(unsigned i = 0; i < utentes.size(); i++){

		utentes.at(i)->imprimeInfoUtente();
		cout << endl << endl;

	}
}


/**
 * metodo que imprime toda a informacao relativa a um ponto de venda, especificado pelo local onde se encontra
 * @param local local onde se encontra o ponto de venda
 */
void PontosVenda::imprimePDV(string local) const{

	//a implementar
}


/**
 * metodo que extrai a informacao de um ficheiro, atualizando a informacao dos utentes e pontos de venda
 * @param ficheiro nome do ficheiro onde esta guardada a informacao
 */
void PontosVenda::load_file(string ficheiro){

	//a implementar
}


/**
 * metodo que guarda toda a informacao que possui num ficheiro de texto, para uso futuro
 * @param ficheiro nome do ficheiro onde vai ser guardada a informacao
 */
void PontosVenda::save_file(string ficheiro){

	//a implementar
}


/**
 * metodo que procura por um determinado utente, dado o seu nome, e o retorna, se for encontrado
 * @param nome nome do utente que se quer encontrar
 * @return utente que se queria encontrar
 */
Utente* PontosVenda::getUtente(string nome) const{

	for(unsigned i = 0; i < utentes.size(); i++){

		if(utentes.at(i)->getNome() == nome)
			return utentes.at(i);

	}

	throw UtenteInexistente(nome);
}


/**
 * retorna o vetor com todos os utentes que possuem um bilhete assinatura
 * @return vetor com os utentes
 */
vector<Utente*> PontosVenda::getUtentesAssinatura() const{
	return utentes;
}


/**
 * metodo que pergunta ao utilizador que tipo de bilhete e que quer comprar, e em que local, adicionando esse bilhete a informacao da respetiva maquina/loja
 */
void PontosVenda::comprarBilhete(){

	//a implementar
}


/**
 * metodo que tenta encontrar uma maquina que esteja num determinado local, retornando o indice dessa maquina no vetor dos pontos de venda (se ela existir)
 * @param local local da maquina
 * @return indice da maquina no vetor dos pontos de venda
 */
int PontosVenda::findMaquina(string local) const{

	//a implementar
	return 0;
}


/**
 * metodo que tenta encontrar uma loja que esteja num determinado local, retornando o indice dessa loja no vetor dos pontos de venda (se ela existir)
 * @param local local da loja
 * @return indice da loja no vetor dos pontos de venda
 */
int PontosVenda::findLoja(string local) const{

	//a implementar
	return 0;
}


/**
 * metodo que elimina um utente da base de dados, assim como a informacao relativa ao seu bilhete de assinatura
 * @param nome nome do utente que se pretende eliminar
 */
void PontosVenda::eliminaAssinatura(string nome){

	//a implementar
}


/**
 * metodo que elimina uma loja ou maquina, com base no local onde se encontra
 * @param local local onde o ponto de venda se encontra
 */
void PontosVenda::eliminaPDV(string local){

	//a implementar
}


/**
 * metodo que adiciona um novo ponto de venda a base de dados
 * @param local local do novo ponto de venda
 * @param loja parametro booleano para se saber se o ponto de venda e uma loja (true) ou uma maquina (false)
 */
void PontosVenda::addPDV(string local, bool loja){

	//a implementar
}

/**
 * metodo que adiciona um novo utente ao vetor de utentes
 * @param u utente que ira ser adicionado
 */
void PontosVenda::addUtente(Utente* u){

	utentes.push_back(u);
}
