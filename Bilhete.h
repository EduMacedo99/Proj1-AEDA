#ifndef BILHETE_H_
#define BILHETE_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Utente.h"
using namespace std;

/**
 * classe utilizada para retratar bilhetes de metro (possui duas subclasses)
 */
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
    * vector que relaciona cada zona com os precos de cada tipo de bilhete (vetor externo contem os vetores
    * com os precos relativos as zonas Z1, Z2, Z3 e Z4, respetivamente, e cada subvetor de zona contem os precos
    * relativos a um bilhete unico, diario, ou de assinatura normal, respetivamente)
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
	 * construtor da classe (variavel preco ira ser inicializada pelas subclasses, quando se souber a especificacao)
	 * @param categoria categoria do bilhete
	 */
	Bilhete(string categoria): categoria(categoria), preco(0){}

	/**
	 * destrutor virtual da classe (apenas declarado)
	 */
	virtual ~Bilhete(){}

	/**
     * metodo que devolve a categoria do bilhete
     * @return categoria do bilhete
	 */
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
	 * metodo que determina o preco para um bilhete de uma determianda categoria e especificacao (diario, unico ou tipo de assinatura (junior, estudante etc.).
	 * Se categoria ou especificacao sao invalidos, retorna com preco igual a 0
	 * @param categoria categoria do bilhete
	 * @param especificacao especificacao do bilhete
	 * @return preco do bilhete determinado
	 */
	float makePreco(string categoria,string especificacao) const;

	/**
	 * metodo que inicializa/muda o valor da variavel preco
	 * @param preco preco que queremos dar ao bilhete
	 */
	void setPreco(float preco);

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



/**
 * classe utilizada para retratar bilhetes de metro do tipo ocasional
 */
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
	 * @param duracao duracao da validade do bilhete
	 */
	BilheteOcasional(string categoria, float preco,  string duracao): Bilhete(categoria, preco), duracao(duracao){}

	/**
	 * construtor da classe bilhete ocasional (o preco e calculado em funcao da categoria e duracao)
	 * @param categoria categoria do bilhete
	 * @param duracao duracao da validade do bilhete
	 */
	BilheteOcasional(string categoria, string duracao): Bilhete(categoria), duracao(duracao){ this->setPreco(makePreco(categoria, duracao));}

	/**
	 * destrutor da classe (apenas declarado)
	 */
	 ~BilheteOcasional(){}


	/**
	 * metodo que devolve a duracao da viagem
	 * @return duracao da viagem
	 */
	string getDuracao() const;

	/**
	 * metodo que imprime no ecra a informacao do bilhete ocasional que invoca o metodo
	 */
	void imprimeInfoBilhete() const;


	/**
	 * overload do operador menor para esta classe
	 * @param b bilhete a comparar com o objeto que chama o metodo
	 * @return se e menor ou nao
	 */
    bool operator<(const BilheteOcasional& b) const;
};


/**
 * classe utilizada para retratar bilhetes de metro do tipo assinatura
 */
class BilheteAssinatura : public Bilhete{

private:
	/**
	 * tipo da assinatura (se e normal, estudante, junior ou senior)
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
	 * construtor da classe bilhete assinatura (o preco e calculado em funcao da categoria e duracao)
	 * @param categoria categoria do bilhete
	 * @param tipo tipo do bilhete
	 */
	BilheteAssinatura(string categoria, string tipo, Utente* assinante): Bilhete(categoria), tipo(tipo), assinante(assinante){ this->setPreco(makePreco(categoria, tipo));}

	/**
	 * destrutor da classe (para lidar com alocacao dinamica de memoria)
	 */
	~BilheteAssinatura() {delete assinante;}


	/**
	 * metodo que devolve o tipo de assinatura
	 * @return tipo da assinatura
	 */
	string getTipo() const;

	/**
	* metodo de acesso ao assinante de um bilhete assinatura especifico
	* @return apontador para o assinante do bilhete
    */
	Utente* getAssinante() const;


	/**
	 * metodo que imprime no ecra a informacao do bilhete assinatura que invoca o metodo
	 */
	void imprimeInfoBilhete() const;

	/**
	 * overload do operador menor para esta classe
	 * @param b bilhete a comparar com o objeto que chama o metodo
	 * @return se e menor ou nao
	 */
    //bool operator<(const BilheteAssinatura& b) const;
};


/**
 * funcao para ordenar bilhetes ocasionais por ordem decrescente de preco
 */
/*bool ordenaBilhetesODecrescente(const BilheteOcasional &b1, const BilheteOcasional &b2){

	return b1.getPreco() > b2.getPreco();
}*/

/**
 * funcao para ordenar bilhetes assinatura por ordem decrescente de preco
 */
/*bool ordenaBilhetesADecrescente(const BilheteAssinatura &b1, const BilheteAssinatura &b2){

	return b1.getPreco() > b2.getPreco();
}*/


/**
 * classe utilizada para lancar excecoes em caso de procura de um bilhete que nao existe (nao tem atributos/metodos, apenas indica que nao existe)
 */
class BilheteInexistente{};
























#endif /* BILHETE_H_ */
