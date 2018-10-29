#include "PontosVenda.h"

/**
* overload do operador de insercao para a classe LocalInexistente
* @param os stream de output
* @param li1 objeto da classe
* @return stream de output
*/
ostream& operator << (ostream &os, const LocalInexistente &li1){

	os << "Local nao existente: " << li1.getLocal();
	return os;
}


/**
* overload do operador de insercao para a classe UtenteInexistente
* @param os stream de output
* @param ui1 objeto da classe
* @return stream de output
*/
ostream& operator << (ostream &os, const UtenteInexistente &ui1){

	os << "Utente nao existente: " << ui1.getNome();
	return os;
}
