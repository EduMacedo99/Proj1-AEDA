#ifndef PONTOSVENDA_H_
#define PONTOSVENDA_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Maquina.h"
#include "Bilhete.h"
#include "Utente.h"

/**
 * classe utilizada para englobar toda a informacao referente aos pontos de venda da cidade
 */
class PontosVenda{

private:

	/**
	 * vetor com todos os pontos de venda da cidade
	 */
	vector<Maquina*> ptsVenda;

	/**
	 * vetor com todos os utentes que possuem um bilhete assinatura
	 */
	vector<Utente*> utentes;


public:

	/**
	 * destrutor da classe
	 */
	~PontosVenda();

	/**
	 * metodo que imprime toda a informacao que possui sobre todos os pontos de venda da cidade
	 */
	void imprime() const;

	/**
	 * metodo que imprime a informacao relativa aos utentes que possuem um bilhete assinatura
	 */
	void imprimeAssinantes() const;

	/**
	 * metodo que imprime toda a informacao relativa a um ponto de venda, especificado pelo local onde se encontra
	 * @param local local onde se encontra o ponto de venda
	 */
	void imprimePDV(string local) const;

	/**
	 * metodo que extrai a informacao de um ficheiro, atualizando a informacao dos utentes e pontos de venda
	 * @param ficheiro nome do ficheiro onde esta guardada a informacao
	 */
	void load_file(string ficheiro);

	/**
	 * metodo que guarda toda a informacao que possui num ficheiro de texto, para uso futuro
	 * @param ficheiro nome do ficheiro onde vai ser guardada a informacao
	 */
	void save_file(string ficheiro);

	/**
	 * metodo que procura por um determinado utente, dado o seu nome, e o retorna, se for encontrado
	 * @param nome nome do utente que se quer encontrar
	 * @return utente que se queria encontrar
	 */
	Utente* getUtente(string nome) const;


	/**
	 * retorna o vetor com todos os utentes que possuem um bilhete assinatura
	 * @return vetor com os utentes
	 */
	vector<Utente*> getUtentesAssinatura() const;


	/**
	 * metodo que pergunta ao utilizador que tipo de bilhete e que quer comprar, e em que local, adicionando esse bilhete a informacao da respetiva maquina/loja
	 */
	void comprarBilhete();

	/**
	 * metodo que tenta encontrar uma maquina que esteja num determinado local, retornando o indice dessa maquina no vetor dos pontos de venda (se ela existir)
	 * @param local local da maquina
	 * @return indice da maquina no vetor dos pontos de venda
	 */
	int findMaquina(string local) const;


	/**
	 * metodo que tenta encontrar uma loja que esteja num determinado local, retornando o indice dessa loja no vetor dos pontos de venda (se ela existir)
	 * @param local local da loja
	 * @return indice da loja no vetor dos pontos de venda
	 */
	int findLoja(string local) const;

	/**
	 * metodo que elimina um utente da base de dados, assim como a informacao relativa ao seu bilhete de assinatura
	 * @param nome nome do utente que se pretende eliminar
	 */
	void eliminaAssinatura(string nome);

	/**
	 * metodo que elimina uma loja ou maquina, com base no local onde se encontra
	 * @param local local onde o ponto de venda se encontra
	 */
	void eliminaPDV(string local);


	/**
	 * metodo que adiciona um novo ponto de venda a base de dados
	 * @param local local do novo ponto de venda
	 * @param loja parametro booleano para se saber se o ponto de venda e uma loja (true) ou uma maquina (false)
	 */
	void addPDV(string local, bool loja);


	/**
	 * metodo que adiciona um novo utente ao vetor de utentes
	 * @param u utente que ira ser adicionado
	 */
	void addUtente(Utente* u);

};


#endif /* PONTOSVENDA_H_ */
