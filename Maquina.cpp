#include "Maquina.h"
#include <iostream>
#include <vector>
 using namespace std;

/**
 * Construtor da classe maquina
 * @param local local da maquina
 */
Maquina::Maquina(string local): local(local){
	this->bilhetes = 0;
}

/**
 * retorna o local da maquina
 */
Maquina::getLocal(){
	return local;
}

/**
 * retorna o vetor de bilhetes da maquina
 */
Maquina::getBilhetes(){
	return bilhetes;
}

/**
 * Imprime no ecra as informacoes da maquina: local e bilhetes vendidos
 */
Maquina::imprimeInfoMaquina(){
	cout << "Local: " << local << endl;
	imprimeInfoBilhete();
}

/*
 * Acrescenta o bilhete ao vetor bilhetes
 * @param bilhete bilhete que se pretende adicionar ao vetor bilhetes
 */
Maquina::addBilhete(BilheteOcasional bilhete) {
	bilhetes.push_back(bilhete);
}



/**
* metodo que devolve os bilhetes que ja foram vendidos na loja
* @return vector que contem todos os bilhetes que ja foram vendidos na loja
**/
vector<BilheteAssinatura> Loja::getBilhetesA() const{
	return bilhetesA;
}


/**
* metodo que devolve o Utente com um determinado nome
* @param nome nome do utente que se quer encontrar
* @return Utente com um determinado nome
**/
Utente Loja::findUtente(string nome) const{


	// a ser implementado
}


/**
* metodo que imprime a informacao da loja
**/
void Loja::imprimeInfoPDV() const{
	cout<< "Local: "<< local;
	//imprimir bilhetes assinatura , a implementar

}


/**
* metodo que adiciona um bilhete assinatura ao vector bilhetes
* @param bilhete bilhete assinatura que se deseja adicionar
**/
void Loja::addBilheteA(BilheteAssinatura bilhete){
	bilhetesA.push_back(bilhete);
}
