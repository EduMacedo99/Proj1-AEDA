#include "Maquina.h"
#include <iostream>
 using namespace std;

/**
 * retorna o local da maquina
 */
string Maquina::getLocal() const{
	return local;
}

/**
* retorna o vetor de bilhetes ocasionais da maquina (ou loja)
* @return bilhetes ocasionais vendidos no ponto de venda
*/
vector<BilheteOcasional> Maquina::getBilhetesO() const{
	return bilhetesO;
}

/**
* Imprime no ecra as informacoes da maquina
*/
void Maquina::imprimeInfoPDV() const{

	cout << "Local: " << local << endl;
	cout << "Bilhetes Ocasionais:" << endl;

	for(unsigned i = 0; i < bilhetesO.size(); i++){

		bilhetesO.at(i).imprimeInfoBilhete();
		cout << endl << endl;

	}

}

/**
 * Acrescenta o bilhete ocasional ao vetor bilhetesO
 * @param bilhete bilhete ocasional que se pretende adicionar ao vetor bilhetesO
 */
void Maquina::addBilheteO(BilheteOcasional bilhete) {
	bilhetesO.push_back(bilhete);
}



/**
* metodo que devolve os bilhetes que ja foram vendidos na loja
* @return vetor que contem todos os bilhetes que ja foram vendidos na loja
**/
vector<BilheteAssinatura> Loja::getBilhetesA() const{
	return bilhetesA;
}


/**
 * metodo que devolve o Utente com um determinado nome
 * @param nome nome do utente que se quer encontrar
 * @return o utente com tal nome (se for encontrado)
 */
/*Utente* Loja::findUtente(string nome) const{




}*/


/**
* metodo que imprime a informacao da loja
**/
void Loja::imprimeInfoPDV() const{

	Maquina::imprimeInfoPDV();

	cout << "Bilhetes Assinatura:" << endl;

	for(unsigned i = 0; i < bilhetesA.size(); i++){

		bilhetesA.at(i).imprimeInfoBilhete();
		cout << endl << endl;

	}


}


/**
 * metodo que adiciona um bilhete assinatura ao vector bilhetes
 * @param bilhete bilhete assinatura que se deseja adicionar
 **/
void Loja::addBilheteA(BilheteAssinatura bilhete){
	bilhetesA.push_back(bilhete);
}
