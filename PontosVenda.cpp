#include "PontosVenda.h"

using namespace std;

/**
 * destrutor da classe
 */
PontosVenda::~PontosVenda(){

	for(unsigned i = 0; i < ptsVenda.size(); i++)
		delete ptsVenda.at(i);

	/*for(unsigned j= 0; j < utentes.size(); j++)
		delete utentes.at(j);*/

}


/**
 * metodo que imprime toda a informacao que possui sobre todos os pontos de venda da cidade
 */
void PontosVenda::imprime() const{

	if(ptsVenda.size() == 0){
		cout << "Nao ha nenhuma informacao para imprimir!" << endl;
		return;
	}

	for(unsigned i = 0; i < ptsVenda.size(); i++){

		ptsVenda.at(i)->imprimeInfoPDV();
		cout << endl << "--------------" << endl;

	}
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
 * metodo que imprime toda a informacao relativa a um ponto de venda, especificado pelo local onde se encontra (parte do principio que so ha uma maquina/loja em cada local)
 * @param local local onde se encontra o ponto de venda
 */
void PontosVenda::imprimePDV(string local) const{

	bool encontrou = false;

	for(unsigned i = 0; i < ptsVenda.size(); i++){

		if(ptsVenda.at(i)->getLocal() == local){

			cout << "Local encontrado:" << endl;
			encontrou = true;
			ptsVenda.at(i)->imprimeInfoPDV();
		}

	}

	if(!encontrou)
		throw LocalInexistente(local);
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
 * metodo que "compra" um bilhete ocasional num ponto de venda especificado pelo seu local
 * @param local local do ponto de venda
 * @param bo bilhete que se pretende comprar
 */
void PontosVenda::comprarBilheteOcasional(string local, BilheteOcasional& bo){

	//no outro metodo de comprar bilhetes assinatura, ver se no local ha uma loja (implementar findLoja)
}

/**
 * metodo que "compra" um bilhete assinatura numa loja especificada pelo seu local
 * @param local local da loja
 * @param ba bilhete que se pretende comprar
 */
void PontosVenda::comprarBilheteAssinatura(string local, BilheteAssinatura& ba){

	//nao esquecer de adicionar o assinante ao vetor de utentes!
}

/**
 * metodo que tenta encontrar uma maquina que esteja num determinado local, retornando o indice dessa maquina no vetor dos pontos de venda (se ela existir)
 * @param local local da maquina
 * @return indice da maquina no vetor dos pontos de venda
 */
/*int PontosVenda::findMaquina(string local) const{

	//a implementar
	return 0;
}*/


/**
 * metodo que tenta encontrar uma loja que esteja num determinado local, retornando o indice dessa loja no vetor dos pontos de venda (se ela existir)
 * @param local local da loja
 * @return indice da loja no vetor dos pontos de venda
 */
/*int PontosVenda::findLoja(string local) const{

	//a implementar
	return 0;
}*/

/**
 * metodo que tenta encontrar um ponto de venda que esteja num determinado local, retornando o indice desse PDV no vetor dos pontos de venda (se existir)
 * @param local local onde queremos procurar o ponto de venda
 */
Maquina* PontosVenda::findPDV(string local) const{

	for(unsigned i = 0; i < ptsVenda.size(); i++){

		if(ptsVenda.at(i)->getLocal() == local)
			return ptsVenda.at(i);

	}

	throw LocalInexistente(local);
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
 * metodo que adiciona um novo ponto de venda a base de dados (lanca uma excecao se ja existe um ponto de venda nesse local)
 * @param m nova maquina/loja a ser adicionada
 */
void PontosVenda::addPDV(Maquina* m){

	for(unsigned i = 0; i < ptsVenda.size(); i++){

		if(ptsVenda.at(i)->getLocal() == m->getLocal())
			throw LocalRepetido(m->getLocal());

	}

	ptsVenda.push_back(m);
}

/**
 * metodo que adiciona um novo ponto de venda a base de dados (lanca uma excecao se ja existe um ponto de venda nesse local)
 * @param local local do novo ponto de venda
 * @param loja indica se o ponto de venda a adicionar e uma loja ou nao
 */
void PontosVenda::addPDV(string local, bool loja){

	for(unsigned i = 0; i < ptsVenda.size(); i++){

		if(ptsVenda.at(i)->getLocal() == local)
			throw LocalRepetido(local);

	}

	Maquina* m;

	if(loja)
		m = new Loja(local);
	else m = new Maquina(local);

	ptsVenda.push_back(m);

}

/**
 * metodo que adiciona um novo utente ao vetor de utentes
 * @param u utente que ira ser adicionado
 */
void PontosVenda::addUtente(Utente* u){

	for(unsigned i = 0; i < utentes.size(); i++){

		if(utentes.at(i)->getNome() == u->getNome())	//nao deixa haver dois utentes com o mesmo nome!!
			throw UtenteRepetido(u->getNome());

	}

	utentes.push_back(u);
}


/**
 * metodo que ordena os elementos do vetor de utentes por ordem alfabetica
 */
void PontosVenda::sortUtentes(){

	sort(utentes.begin(), utentes.end(), ordenaUtentes);
}
