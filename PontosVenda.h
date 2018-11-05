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
	 * @return retorna 0 se executou sem problemas, 1 se ocorreu um erro (ex: ficheiro nao existente)
	 */
	int load_file(string ficheiro);

	/**
	 * metodo que guarda toda a informacao que possui num ficheiro de texto, para uso futuro
	 * @param ficheiro nome do ficheiro onde vai ser guardada a informacao
	 * @return retorna 0 se executou sem problemas, 1 se ocorreu um erro
	 */
	int save_file(string ficheiro);

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
	 * metodo que "compra" um bilhete ocasional num ponto de venda especificado pelo seu local
	 * @param local local do ponto de venda
	 * @param bo bilhete que se pretende comprar
	 */
	void comprarBilheteOcasional(string local, BilheteOcasional& bo);

	/**
	 * metodo que "compra" um bilhete assinatura numa loja especificada pelo seu local
	 * @param local local da loja
	 * @param ba bilhete que se pretende comprar
	 */
	void comprarBilheteAssinatura(string local, BilheteAssinatura& ba);

	/**
	 * metodo que tenta encontrar uma loja que esteja num determinado local, retornando o indice dessa loja no vetor dos pontos de venda (se ela existir)
	 * @param local local da loja
	 * @return indice da loja no vetor dos pontos de venda (-1 se nao existir)
	 */
	int findLoja(string local) const;


	/**
	 * metodo que tenta encontrar um ponto de venda que esteja num determinado local, retornando o indice desse elemento no vetor dos pontos de venda (se existir)
	 * @param local local onde queremos procurar o ponto de venda
	 * @return indice no vetor (-1 se nao existir)
	 */
	int findPDV(string local) const;

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
	 * metodo que adiciona um novo ponto de venda a base de dados (lanca uma excecao se ja existe um ponto de venda nesse local)
	 * @param m nova maquina/loja a ser adicionada
	 */
	void addPDV(Maquina* m);

	/**
	 * metodo que adiciona um novo ponto de venda a base de dados (lanca uma excecao se ja existe um ponto de venda nesse local)
	 * @param local local do novo ponto de venda
	 * @param loja indica se o ponto de venda a adicionar e uma loja ou nao
	 */
	void addPDV(string local, bool loja);


	/**
	 * metodo que adiciona um novo utente ao vetor de utentes
	 * @param u utente que ira ser adicionado
	 */
	void addUtente(Utente* u);

	/**
	 * metodo que ordena os elementos do vetor de utentes por ordem alfabetica
	 */
	void sortUtentes();

};


#endif /* PONTOSVENDA_H_ */
