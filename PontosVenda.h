#ifndef PONTOSVENDA_H_
#define PONTOSVENDA_H_

#include "Maquina.h"
#include "Bilhete.h"
#include "Utente.h"




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
	string getLocal() const { return local; }

};

/**
 * classe que vai ser utilizada quando se procura um utente que nao existe (irao ser lancadas excecoes desta classe)
 */
class UtenteInexistente{

private:
	/**
	 * nome do utente nao existente
	 */
	string nome;

public:
	/**
	 * construtor da classe
	 * @param nome nome do utente nao existente
	 */
	UtenteInexistente(string nome): nome(nome){}

	/**
	 * metodo de acesso ao nome do utente que nao existe
	 * @return nome do utente nao existente
	 */
	string getNome() const {return nome; }

};


#endif /* PONTOSVENDA_H_ */
