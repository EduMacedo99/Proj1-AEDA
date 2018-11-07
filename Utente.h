#ifndef UTENTE_H_
#define UTENTE_H_

#include <iostream>
#include <string>
#include <algorithm>
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

	/**
	 * id do utente
	 */
	unsigned int id;

	/**
	 * variavel static que atribui aos utentes um id sequencial, nao repetido
	 */
	static unsigned int nextId;


public:

	/**
	 * construtor da classe
	 * @param nome nome do utente
	 */
	Utente(string nome): nome(nome), id(++nextId) {}

	/**
	 * destrutor virtual da classe (apenas declarado)
	 */
	virtual ~Utente(){}

	/**
	 * metodo que imprime no ecra a informacao do utente que invoca o metodo (declarado como virtual devido as classes derivadas)
	 */
	virtual void imprimeInfoUtente() const;

	/**
	 * metodo que retorna o nome do utente
	 * @return nome do utente
	 */
	string getNome() const;

	/**
	 * metodo que retorna o id do utente
	 * @return id do utente
	 */
	unsigned int getId() const;

	/**
	 * operador de insercao (utilizado para a escrita em ficheiros)
	 */
	friend ostream& operator<<(ostream &os, const Utente&u);

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
	 * destrutor virtual da classe (apenas declarado)
	 */
	~UtenteEstudante(){}

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
	 * metodo que imprime no ecra a informacao do utente estudante que invoca o metodo
	 */
	void imprimeInfoUtente() const;

	/**
	 * operador de insercao (utilizado para a escrita em ficheiros)
	 */
	friend ostream& operator<<(ostream &os, const UtenteEstudante&u);
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
	 * destrutor virtual da classe (apenas declarado)
	 */
	~UtenteSenior(){}

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
	 * metodo que imprime no ecra a informacao do utente senior que invoca o metodo
	 */
    void imprimeInfoUtente() const;

    /**
     * operador de insercao (utilizado para a escrita em ficheiros)
     */
   	friend ostream& operator<<(ostream &os, const UtenteSenior&u);

};



/**
 * classe utilizada para representar um utente junior que possui uma assinatura
 */
class UtenteJunior : public Utente{

private:
	/**
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
	 * destrutor virtual da classe (apenas declarado)
	 */
	~UtenteJunior(){}

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
	 * metodo que imprime no ecra a informacao do utente junior que invoca o metodo
	 */
    void imprimeInfoUtente() const;

    /**
     * operador de insercao (utilizado para a escrita em ficheiros)
     */
   	friend ostream& operator<<(ostream &os, const UtenteJunior&u);

};

/**
 * funcao utilizada para ordenacao de utentes, por ordem crescente do nome
 */
bool ordenaUtentes(const Utente* u1, const Utente* u2);


/**
 * funcao auxiliar para a leitura de ficheiros
 * @param s string com os underscores
 * @return string com os espacos
 */
string replaceUnderscoresWithSpaces(string s);


/**
 * funcao auxiliar para a escrita de ficheiros
 * @param s string com os espacos
 * @return string com os underscores
 */
string replaceSpacesWithUnderscores(string s);



/**
 * classe que vai ser utilizada quando se procura um utente que nao existe (irao ser lancadas excecoes desta classe)
 */
class UtenteInexistente{

private:
	/**
	 * id do utente nao existente
	 */
	unsigned int id;

public:
	/**
	 * construtor da classe
	 * @param id id do utente nao existente
	 */
	UtenteInexistente(unsigned int id): id(id){}

	/**
	 * metodo de acesso ao id do utente que nao existe
	 * @return id do utente nao existente
	 */
	unsigned int getId() {return id; }

};


/**
 * classe que vai ser utilizada quando se tenta adiciona um assinante que ja existe (irao ser lancadas excecoes desta classe)
 */
class UtenteRepetido{

private:
	/**
	 * nome do utente repetido
	 */
	unsigned int id;

public:
	/**
	 * construtor da classe
	 * @param id nome do utente repetido
	 */
	UtenteRepetido(unsigned int id): id(id){}

	/**
	 * metodo de acesso ao id do utente repetido
	 * @return id do utente repetido
	 */
	unsigned int getId() {return id; }

};
#endif /* UTENTE_H_ */
