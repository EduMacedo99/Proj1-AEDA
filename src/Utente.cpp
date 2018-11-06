#include "Utente.h"

/**
 * funcao auxiliar para a leitura de ficheiros
 * @param s string com os underscores
 * @return string com os espacos
 */
string replaceUnderscoresWithSpaces(string s){

	string sFinal = s;

	for(unsigned i = 0; i < sFinal.length(); i++){

		if(sFinal.at(i) == '_')
			sFinal.at(i) = ' ';
	}

	return sFinal;
}

/**
 * funcao auxiliar para a escrita de ficheiros
 * @param s string com os espacos
 * @return string com os underscores
 */
string replaceSpacesWithUnderscores(string s){

	string sFinal = s;

	for(unsigned i = 0; i < sFinal.length(); i++){

		if(sFinal.at(i) == ' ')
			sFinal.at(i) = '_';
	}

		return sFinal;

}

/**
 * operador de insercao (utilizado para a escrita em ficheiros)
 */
ostream& operator<<(ostream &os, const UtenteSenior&u){

	os << replaceSpacesWithUnderscores(u.nome) << endl << u.idade << endl << u.cc;
	return os;

}

/**
 * operador de insercao (utilizado para a escrita em ficheiros)
 */
ostream& operator<<(ostream &os, const UtenteJunior&u){

	os << replaceSpacesWithUnderscores(u.nome) << endl << u.idade << endl << u.cc;
	return os;

}

/**
 * operador de insercao (utilizado para a escrita em ficheiros)
 */
ostream& operator<<(ostream &os, const UtenteEstudante&u){

	os << replaceSpacesWithUnderscores(u.nome) << endl << u.idade << endl << u.cc << endl << replaceSpacesWithUnderscores(u.escola);
	return os;

}

/**
 * operador de insercao (utilizado para a escrita em ficheiros)
 */
ostream& operator<<(ostream &os, const Utente&u){

	os << replaceSpacesWithUnderscores(u.nome);
	return os;

}

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


/**
 * funcao utilizada para ordenacao de utentes, por ordem crescente do nome
 */
bool ordenaUtentes(const Utente* u1, const Utente* u2){

	return u1->getNome() < u2->getNome();
}
