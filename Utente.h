#ifndef UTENTE_H_
#define UTENTE_H_

#include <iostream>
#include <string>
using namespace std;

/**
 * classe usada para retratar um utente que possui um bilhete de assinatura
 */
class Utente{

protected:
	/**
	 * nome do utente
	 */
	string nome;


public:

	/**
	 * construtor da classe
	 * @param nome nome do utente
	 */
	Utente(string nome): nome(nome) {}

	/**
	 * destrutor virtual da classe (apenas declarado)
	 */
	virtual ~Utente(){}

	/**
	 * metodo que imprime no ecra a informacao do utente que invoca o metodo (declarado como virtual devido
	 * as classes derivadas)
	 */
	virtual void imprimeInfoUtente() const;

	/**
	 * metodo que retorna o nome do utente
	 * @return nome do utente
	 */
	string getNome() const;

};



/**
 * classe utilizada para representar um estudante que possui uma assinatura
 */
class UtenteEstudante : public Utente{

private:
	/**
	 * idade do utente
	 */
	int idade;

	/**
	 * numero do cartao de cidadao
	 */
	string cc;

	/**
	 * nome da escola que o estudante frequenta
	 */
	string escola;

public:
	/**
	 * construtor da classe
	 * @param nome nome do utente
	 * @param idade idade do utente
	 * @param cc numero do cartao de cidadao do utente
	 * @param escola nome da escola do utente
	 */
	UtenteEstudante(string nome, int idade, string cc, string escola): Utente(nome), idade(idade), cc(cc), escola(escola){}

	/**
	 * metodo que retorna a idade do utente
	 * @return idade do utente
	 */
	int getIdade() const;

	/**
	 * metodo que retorna o numero do cartao de cidadao do utente
	 * @return numero de cc do utente
	 */
	string getCC() const;

	/**
	 * metodo que retorna a escola do utente
	 * @return escola do utente
	 */
	string getEscola() const;

	/**
	 * metodo que imprime no ecra a informacao do utente que invoca o metodo (declarado como virtual devido
	 * as classes derivadas)
	 */
	virtual void imprimeInfoUtente() const;
};



/**
 * classe utilizada para representar um utente senior que possui uma assinatura
 */
class UtenteSenior : public Utente{

private:
	/*
	 * idade do utente
	 */
	int idade;

	/**
	 * numero do cartao de cidadao do utente
	 */
	string cc;

public:
	/**
	 * construtor da classe
	 * @param nome nome do utente
	 * @param idade idade do utente
	 * @param cc numero de cartao de cidadao do utente
	 */
	UtenteSenior(string nome, int idade, string cc): Utente(nome), idade(idade), cc(cc){}

	/**
	 * metodo que retorna a idade do utente
	 * @return idade do utente
	 */
	int getIdade() const;

	/**
	 * metodo que retorna o numero de cartao de cidadao do utente
	 * @return numero de cc do utente
	 */
	string getCC() const;

	/**
	* metodo que imprime no ecra a informacao do utente que invoca o metodo (declarado como virtual devido
	* as classes derivadas)
	*/
	virtual void imprimeInfoUtente() const;

};



/**
 * classe utilizada para representar um utente junior que possui uma assinatura
 */
class UtenteJunior : public Utente{

private:
	/*
	 * idade do utente
	 */
	int idade;

	/**
	 * numero do cartao de cidadao do utente
	 */
	string cc;

public:
	/**
	 * construtor da classe
	 * @param nome nome do utente
	 * @param idade idade do utente
	 * @param cc numero de cartao de cidadao do utente
	 */
	UtenteJunior(string nome, int idade, string cc): Utente(nome), idade(idade), cc(cc){}

	/**
	 * metodo que retorna a idade do utente
	 * @return idade do utente
	 */
	int getIdade() const;

	/**
	 * metodo que retorna o numero de cartao de cidadao do utente
	 * @return numero de cc do utente
	 */
	string getCC() const;

	/**
	* metodo que imprime no ecra a informacao do utente que invoca o metodo (declarado como virtual devido
	* as classes derivadas)
	*/
	virtual void imprimeInfoUtente() const;

};


/**
 * classe usada para tratar de excecoes causadas pela procura de um utente que nao existe
 */
class UtenteInexistente{

private:
	/*
	 * nome do utente que procuramos (e que nao existe)
	 */
	string nome;

public:
	/**
	 * construtor da classe
	 * @param nome nome do utente
	 */
	UtenteInexistente(string nome): nome(nome){}

	/**
	 * overload do operador de insercao para esta classe
	 * @param os stream de output
	 * @param ui1 objeto da classe
	 * @return stream de output
	 */
	friend ostream& operator << (ostream &os, const UtenteInexistente &ui1);
};


#endif /* UTENTE_H_ */
