#ifndef MAQUINA_H_
#define MAQUINA_H_

#include <iostream>
#include <vector>
#include <string>
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


};

#endif /* MAQUINA_H_ */
