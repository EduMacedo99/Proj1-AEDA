#include "Utente.h"

/**
* overload do operador de insercao para a classe UtenteInexistente
* @param os stream de output
* @param ui1 objeto da classe
* @return stream de output
*/
ostream& operator << (ostream &os, const UtenteInexistente &ui1){

	os << "Utente nao existente: " << ui1.nome;
	return os;
}

/**
* metodo que imprime no ecra a informacao do utente que invoca o metodo (declarado como virtual devido
* as classes derivadas)
*/
void Utente::imprimeInfoUtente() const{

	cout << "Nome: " << nome << endl;
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
string getEscola() const{

	return escola;
}

/**
* metodo que imprime no ecra a informacao do utente que invoca o metodo (declarado como virtual devido
* as classes derivadas)
*/
void UtenteEstudante::imprimeInfoUtente() const{

	cout << "Nome: " << nome << endl;
	cout << "Idade: " << idade << endl;
	cout << "CC: " << cc << endl;
	cout << "Escola: " << escola << endl;
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
* metodo que imprime no ecra a informacao do utente que invoca o metodo (declarado como virtual devido
* as classes derivadas)
*/
void UtenteSenior::imprimeInfoUtente() const{

	cout << "Nome: " << nome << endl;
	cout << "Idade: " << idade << endl;
	cout << "CC: " << cc << endl;
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
* metodo que imprime no ecra a informacao do utente que invoca o metodo (declarado como virtual devido
* as classes derivadas)
*/
void UtenteJunior::imprimeInfoUtente() const{

	cout << "Nome: " << nome << endl;
	cout << "Idade: " << idade << endl;
	cout << "CC: " << cc << endl;
}
