#ifndef BILHETE_H_
#define BILHETE_H_

#include <iostream>
#include <string>
#include <vector>
#include "Utente.h"
using namespace std;

class Bilhete{

protected:
	/**
	 * categoria do bilhete
	 */
	string categoria;

	/**
	* preco do bilhete
	*/
	float preco;

	/**
    * vector que relaciona cada zona com os precos de cada tipo de bilhete
    */
	static vector<vector<float> > pZonas;



public:

	/**
	 * construtor da classe
	 * @param categoria categoria do bilhete
	 * @param preco preco do bilhete
	 */
	Bilhete(string categoria, float preco): categoria(categoria), preco(preco) {}

	/**
	 * destrutor virtual da classe (apenas declarado)
	 */
	virtual ~Bilhete(){}

	/**
     * metodo que devolve a categoria do bilhete
     * @return categoria do bilhete
	 **/
	string getCategoria() const;


	/**
	 * metodo que devolve o preco do bilhete
	 * @return preco do bilhete
	 */
	float getPreco() const;


	/**
	 * metodo que devolve o vetor contendo os precos de cada zona
	 * @return o vetor com todos os precos relativos a cada zona
	 */
	static vector<vector<float> > getPrecosZona();

	/**
	 * metodo que determina o preco para um bilhete de uma determianda categoria e especificacao (diario, unico ou tipo de assinatura (junior, estudante etc.)
	 * @param categoria categoria do bilhete
	 * @param especificacao especificacao do bilhete
	 * @return preco do bilhete determinado
	 */
	float makePreco(string categoria,string especificacao) const;

	/**
	 * metodo que imprime no ecra a informacao do bilhete que invoca o metodo (declarado como virtual devido
	 * as classes derivadas; metodo virtual abstrato pois nao ha a necessidade de criar objetos do tipo Bilhete,
	 * mas sim dos tipos BilhetesAssinatura e BilheteOcasional)
	 */
	virtual void imprimeInfoBilhete() const = 0;

	/**
	 * metodo que insere o valor dos precos de cada zona na variavel pZonas
	 * @param precos vetor com todos os precos
	 */
	static void setPrecosZona(vector<vector<float> > precos);

};


class BilheteOcasional : public Bilhete{

private:
	/**
	 * sendo que pode ser um bilhete unico ou diario
	 */
	string duracao;

public:

	/**
	 * Construtor da classe bilhete ocasional
	 * @param categoria categoria do bilhete
	 * @param preco preco do bilhete
	 * @param duracao duracao da viagem
	 */
	BilheteOcasional(string categoria, float preco,  string duracao): Bilhete(categoria, preco), duracao(duracao){}

	/**
	 * destrutor da classe (apenas declarado)
	 */
	 ~BilheteOcasional(){}


	/**
	 * metodo que devolve a duracao da viagem
	 * @return duracao da viagem
	 */
	string getDuracao();

	/**
	 * metodo que imprime no ecra a informacao do bilhete que invoca o metodo (declarado como virtual devido
	 * as classes derivadas)
	 */
	virtual void imprimeInfoBilhete() const;

};



class BilheteAssinatura : public Bilhete{

private:
	/**
	 * tipo da assinatura
	 */
	string tipo;

	/**
	 * dados do assinante
	 */
	Utente* assinante;

public:


	/**
	 * Construtor da classe bilhete assinatura
	 * @param categoria categoria do bilhete
	 * @param preco preco do bilhete
	 * @param tipo tipo do bilhete
	 * @asinante dados do assinante
	 */
	BilheteAssinatura(string categoria, float preco,  string tipo, Utente* assinante): Bilhete(categoria, preco), tipo(tipo), assinante(assinante){}

	/**
	 * destrutor da classe (para lidar com alocacao dinamica de memoria)
	 */
	~BilheteAssinatura() {delete assinante;}


	/**
	 * metodo que devolve o tipo de assinatura
	 * @return tipo da assinatura
	 */
	string getTipo();

	/**
	* metodo que devolve os dados assinante
	* @return dados do assinante
    */
	Utente* getAssinante();


	/**
	 * metodo que imprime no ecra a informacao do bilhete que invoca o metodo (declarado como virtual devido
	 * as classes derivadas)
	 */
	virtual void imprimeInfoBilhete() const;


};


























#endif /* BILHETE_H_ */
