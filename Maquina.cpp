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
 */
void Loja::addBilheteA(BilheteAssinatura bilhete){
	bilhetesA.push_back(bilhete);
}

/**
 * metodo virtual utilizado para se saber, tendo um apontador para Maquina (Maquina*), se este aponta para uma Maquina ou para uma Loja, para nao se recorrer a metodos mais complicados
 * @return retorna falso se for uma maquina, verdadeiro se for uma loja
 */
bool Maquina::eLoja() const{

	return false;
}

/**
 * metodo virtual utilizado para se saber, tendo um apontador para Maquina (Maquina*), se este aponta para uma Maquina ou para uma Loja, para nao se recorrer a metodos mais complicados
 * @return retorna falso se for uma maquina, verdadeiro se for uma loja
 */
bool Loja::eLoja() const{

	return true;
}


/**
 * metodo que retorna os utentes associados a bilhetes assinatura, que foram comprados nessa loja
 * @return vetor com os utentes/assinantes
 */
vector<Utente*> Loja::getAssinantes() const{

	vector<Utente*> utentes;

	for(int i = 0; i < bilhetesA.size(); i++)
		utentes.push_back(bilhetesA.at(i).getAssinante());

	return utentes;
}

/**
 * metodo que ordena os bilhetes de uma maquina, por ordem crescente de preco
 */
/*void Maquina::sortBilhetesCrescente(){

	sort(bilhetesO.begin(), bilhetesO.end());
}*/

/**
 * metodo que ordena os bilhetes de uma loja, por ordem crescente de preco
 */
/*void Loja::sortBilhetesCrescente(){

	Maquina::sortBilhetesCrescente();

	sort(bilhetesA.begin(), bilhetesA.end());
}*/


/**
 * metodo que ordena os bilhetes de uma maquina, por ordem decrescente de preco
 */
/*void Maquina::sortBilhetesDecrescente(){

	sort(bilhetesO.begin(), bilhetesO.end(), ordenaBilhetesODecrescente);

}*/

/**
 * metodo que ordena os bilhetes de uma loja, por ordem decrescente de preco
 */
/*void Loja::sortBilhetesDecrescente(){

	Maquina::sortBilhetesDecrescente();

	sort(bilhetesA.begin(), bilhetesA.end(), ordenaBilhetesADecrescente);

}*/
