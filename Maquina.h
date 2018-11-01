#ifndef MAQUINA_H_
#define MAQUINA_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Bilhete.h"
#include "Utente.h"

 using namespace std;

 /**
  * classe que retrata as maquinas de metro, que vendem bilhetes ocasionais (tem como subclasse a classe Loja)
  */
 class Maquina {

 protected:
	 /**
	  * local da maquina/loja
	  */
	 string local;

	 /**
	  * vetor de bilhetes ocasionais que contem todos os bilhetes ocasionais vendidos nesse ponto de venda
	  */
	 vector<BilheteOcasional> bilhetesO;


 public:
	 /**
	  * Construtor da classe maquina
	  * @param local local da maquina
	  */
	 Maquina(string local): local(local){}

	 /**
	  * destrutor virtual da classe (apenas declarado)
	  */
	 virtual ~Maquina(){};

	 /**
	  * retorna o local da maquina
	  */
	 string getLocal() const;

	 /**
	  * retorna o vetor de bilhetes ocasionais da maquina (ou loja)
	  * @return bilhetes ocasionais vendidos no ponto de venda
	  */
	 vector<BilheteOcasional> getBilhetesO() const;

	 /**
	  * Imprime no ecra as informacoes da maquina
	  */
	 virtual void imprimeInfoPDV() const;

	 /**
	  * Acrescenta o bilhete ocasional ao vetor bilhetesO
	  * @param bilhete bilhete ocasional que se pretende adicionar ao vetor bilhetesO
	  */
	 void addBilheteO(BilheteOcasional bilhete);

	 /**
	  * metodo virtual utilizado para se saber, tendo um apontador para Maquina (Maquina*), se este aponta para uma Maquina ou para uma Loja, para nao se recorrer a metodos mais complicados
	  * @return retorna falso se for uma maquina, verdadeiro se for uma loja
      */
	 virtual bool eLoja() const;

	 /**
	  * metodo que ordena os bilhetes de uma maquina, por ordem crescente de preco
	  */
	 //virtual void sortBilhetesCrescente();

	 /**
	  * metodo que ordena os bilhetes de uma maquina, por ordem decrescente de preco
	  */
	 //virtual void sortBilhetesDecrescente();
 };



/**
 *classe (derivada de Maquina) que caracteriza todas as lojas, em que se pode comprar os dois tipos de bilhetes
 */
class Loja : public Maquina{

private:

	/**
     * vector que contem todos os bilhetes de assinatura que ja foram vendidos na loja
     */
	vector<BilheteAssinatura> bilhetesA;

public:
		/**
		 * construtor da classe
		 * @param local local da loja
		 */
		Loja(string local): Maquina(local) {}

		/**
		 * destrutor da classe (apenas declarado)
		 */
		~Loja(){}


		/**
		 * metodo que devolve os bilhetes assinatura vendidos na loja
		 * @return vetor que contem todos os bilhetes assinatura vendidos na loja
		 */
		vector<BilheteAssinatura> getBilhetesA() const;

		/**
		 * metodo que devolve o Utente com um determinado nome
		 * @param nome nome do utente que se quer encontrar
		 * @return o utente com tal nome (se for encontrado)
		 */
		//Utente* findUtente(string nome) const;

		/**
		* metodo que imprime a informacao da loja
		**/
		void imprimeInfoPDV() const;

		/**
		* metodo que adiciona um bilhete assinatura ao vetor bilhetesA
		* @param bilhete bilhete assinatura que se deseja adicionar
		*/
		void addBilheteA(BilheteAssinatura bilhete);


		/**
		 * metodo virtual utilizado para se saber, tendo um apontador para Maquina (Maquina*), se este aponta para uma Maquina ou para uma Loja, para nao se recorrer a metodos mais complicados
		 * @return retorna falso se for uma maquina, verdadeiro se for uma loja
	     */
		bool eLoja() const;

		/**
		 * metodo que retorna os utentes associados a bilhetes assinatura, que foram comprados nessa loja
		 * @return vetor com os utentes/assinantes
		 */
		vector<Utente*> getAssinantes() const;

		/**
		 * metodo que ordena os bilhetes de uma loja, por ordem crescente de preco
		 */
		//void sortBilhetesCrescente();

		/**
		 * metodo que ordena os bilhetes de uma loja, por ordem decrescente de preco
		 */
		//void sortBilhetesDecrescente();
};


/**
 * classe que vai ser utilizada quando se procura uma maquina/loja num local que nao existe (irao ser lancadas excecoes desta classe)
 */
class LocalInexistente{

private:
	/**
	 * local nao existente
	 */
	string local;

public:
	/**
	 * construtor da classe
	 * @param local local nao existente
	 */
	LocalInexistente(string local): local(local){}

	/**
	 * metodo de acesso ao nome do local que nao existe
	 * @return local nao existente
	 */
	string getLocal() { return local; }

};


/**
 * classe que vai ser utilizada quando se tenta adicionar uma maquina/loja num local em que ja existe uma (irao ser lancadas excecoes desta classe)
 */
class LocalRepetido{

private:
	/**
	 * local repetido
	 */
	string local;

public:
	/**
	 * construtor da classe
	 * @param local local repetido
	 */
	LocalRepetido(string local): local(local){}

	/**
	 * metodo de acesso ao nome do local repetido
	 * @return local repetido
	 */
	string getLocal() { return local; }

};
#endif /* MAQUINA_H_ */
