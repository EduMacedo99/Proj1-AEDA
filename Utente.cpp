#include "Utente.h"

/**
* metodo que imprime no ecra a informacao do utente que invoca o metodo (declarado como virtual devido as classes derivadas)
*/
void Utente::imprimeInfoUtente() const{

	cout << "Nome: " << nome;
}


/**
* metodo que retorna o nome do utente
* @return nome do utente
*/
string Utente::getNome() const{

	return nome;
}

/**
* metodo que retorna a idade do utente
* @return idade do utente
*/
int UtenteEstudante::getIdade() const{

	return idade;
}


/**
* metodo que retorna o numero do cartao de cidadao do utente
* @return numero de cc do utente
*/
string UtenteEstudante::getCC() const{

	return cc;
}


/**
* metodo que retorna a escola do utente
* @return escola do utente
*/
string UtenteEstudante::getEscola() const{

	return escola;
}

/**
 * metodo que imprime no ecra a informacao do utente estudante que invoca o metodo
 */
void UtenteEstudante::imprimeInfoUtente() const{

	cout << "Nome: " << nome << endl;
	cout << "Idade: " << idade << endl;
	cout << "CC: " << cc << endl;
	cout << "Escola: " << escola;
}

/**
* metodo que retorna a idade do utente
* @return idade do utente
*/
int UtenteSenior::getIdade() const{

	return idade;
}

/**
* metodo que retorna o numero de cartao de cidadao do utente
* @return numero de cc do utente
*/
string UtenteSenior::getCC() const{

	return cc;
}


/**
 * metodo que imprime no ecra a informacao do utente senior que invoca o metodo
 */
void UtenteSenior::imprimeInfoUtente() const{

	cout << "Nome: " << nome << endl;
	cout << "Idade: " << idade << endl;
	cout << "CC: " << cc;
}


/**
 * metodo que retorna a idade do utente
 * @return idade do utente
 */
int UtenteJunior::getIdade() const{

	return idade;
}


/**
 * metodo que retorna o numero de cartao de cidadao do utente
 * @return numero de cc do utente
 */
string UtenteJunior::getCC() const{

	return cc;
}


/**
 * metodo que imprime no ecra a informacao do utente junior que invoca o metodo
 */
void UtenteJunior::imprimeInfoUtente() const{

	cout << "Nome: " << nome << endl;
	cout << "Idade: " << idade << endl;
	cout << "CC: " << cc;
}
