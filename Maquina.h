#ifndef MAQUINA_H_
#define MAQUINA_H_

#include <iostream>
#include <vector>
#include "Bilhete.h"
#include "Utente.h"

 using namespace std;

 /**
  * Classe dos objetos Maquina
  */
 class Maquina {
 protected:
	 /**
	  * local da maquina
	  */
	 string local;

	 /**
	  * vetor de bilhetes ocasionais que contem todos os bilhetes ocasionais vendidos nesse ponto de venda
	  */
	 vector<BilheteOcasional> bilhetes;
 public:
	 /**
	  * Construtor da classe maquina
	  * @param local local da maquina
	  */
	 Maquina(string local);

	 /**
	  * retorna o local da maquina
	  */
	 string getLocal();

	 /**
	  * retorna o vetor de bilhetes da maquina
	  */
	 BilheteOcasional getBilhetes();

	 /**
	  * Imprime no ecra as informacoes da maquina
	  */
	 virtual void imprimeInfoPDV();

	 /**
	  * Acrescenta o bilhete ao vetor bilhetes
	  * @param bilhete bilhete que se pretende adicionar ao vetor bilhetes
	  */
	 void addBilhete(BilheteOcasional bilhete);
 };



 /**
  *Classe (derivada de Maquina) que caracteriza todas as lojas
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
		* @return vector que contem todos os bilhetes assinatura vendidos na loja
		**/
		vector<BilheteAssinatura> getBilhetesA() const;

		/**
		* metodo que devolve o Utente com um determinado nome
		* @param nome nome do utente que se quer encontrar
		* @return Utente com um determinado nome
		**/
		Utente findUtente(string nome) const;

		/**
		* metodo que imprime a informacao da loja
		**/
		void imprimeInfoPDV() const;

		/**
		* metodo que adiciona um bilhete assinatura ao vector bilhetes
		* @param bilhete bilhete assinatura que se deseja adicionar
		**/
		void addBilheteA(BilheteAssinatura bilhete);


};


#endif /* MAQUINA_H_ */
