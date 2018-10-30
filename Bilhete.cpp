#include "Bilhete.h"

using namespace std;

vector<vector<float> > Bilhete::pZonas;

/**
 * metodo que devolve o preco do bilhete;
 * @return preco do bilhete
 */
float Bilhete::getPreco() const{
	return preco;
}

/**
 * metodo que devolve a categoria do bilhete
 * @return categoria do bilhete
 */
string Bilhete::getCategoria() const{
	return categoria;
}

/**
 * metodo que devolve a duracao da viagem
 * @return duracao da viagem
 */
string BilheteOcasional::getDuracao() const{
	return duracao;
}


/**
 * metodo de acesso ao assinante de um bilhete assinatura especifico
 * @return apontador para o assinante do bilhete
 */
Utente* BilheteAssinatura::getAssinante() const{
	return assinante;
}

/**
 * metodo que devolve o tipo de assinatura
 * @return tipo da assinatura
 */
string BilheteAssinatura::getTipo() const{
	return tipo;
}

/**
 * metodo que devolve o vetor contendo os precos de cada zona
 * @return o vetor com todos os precos relativos a cada zona
 */
vector<vector<float> > Bilhete::getPrecosZona(){
	return pZonas;
}


/**
 * metodo que determina o preco para um bilhete de uma determianda categoria e especificacao (diario, unico ou tipo de assinatura (junior, estudante etc.).
 * Se categoria ou especificacao sao invalidos, retorna com preco igual a 0
 * @param categoria categoria do bilhete
 * @param especificacao especificacao do bilhete
 * @return preco do bilhete determinado
 */
float Bilhete::makePreco(string categoria,string especificacao) const{

	unsigned int catIndice; //indice para aceder a categoria correta

	if(categoria == "Z1")
		catIndice = 0;
	else if(categoria == "Z2")
		catIndice = 1;
	else if(categoria == "Z3")
		catIndice = 2;
	else if(categoria == "Z4")
		catIndice = 3;
	else return 0;



	if(especificacao == "unico")
		return pZonas.at(catIndice).at(0);
	else if(especificacao == "diario")
		return pZonas.at(catIndice).at(1);
	else if(especificacao == "normal")
		return pZonas.at(catIndice).at(2);
	else if((especificacao == "estudante") || (especificacao == "junior") || (especificacao == "senior"))
		return pZonas.at(catIndice).at(2) * 0.75; //25% de desconto
	else return 0;

}


/**
 * metodo que inicializa/muda o valor da variavel preco
 * @param preco preco que queremos dar ao bilhete
 */
void Bilhete::setPreco(float preco){

	this->preco = preco;
}

/**
 * metodo que insere o valor dos precos de cada zona na variavel pZonas
 * @param precos vetor com todos os precos
 */
void Bilhete::setPrecosZona(vector<vector<float> > precos){
	pZonas = precos;
}


/**
 * metodo que imprime no ecra a informacao do bilhete ocasional que invoca o metodo
 */
void BilheteOcasional::imprimeInfoBilhete() const{
	cout << "Bilhete: Ocasional" << endl;
	cout << "Categoria: " << categoria << endl;
	cout << "Preco: " << preco;
	cout << "Duracao: " << duracao << endl;
}

/**
 * metodo que imprime no ecra a informacao do bilhete assinatura que invoca o metodo
 */
void BilheteAssinatura::imprimeInfoBilhete() const{
	cout << "Bilhete: Assinatura" << endl;
	cout << "Categoria: " << categoria << endl;
	cout << "Preco: " << preco << endl;
	cout << "Tipo: " << tipo << endl;
	cout << "Assinante: " << endl;
	assinante->imprimeInfoUtente();
}

/**
 * overload do operador menor para esta classe
 * @param b bilhete a comparar com o objeto que chama o metodo
 * @return se e menor ou nao
 */
/*bool BilheteOcasional::operator<(const BilheteOcasional& b) const{

	return preco < b.getPreco();
}*/

/**
 * overload do operador menor para esta classe
 * @param b bilhete a comparar com o objeto que chama o metodo
 * @return se e menor ou nao
 */
/*bool BilheteAssinatura::operator<(const BilheteAssinatura& b) const{

	return preco < b.getPreco();
}*/
