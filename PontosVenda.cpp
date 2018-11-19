#include <fstream>
#include "PontosVenda.h"

using namespace std;

/**
 * destrutor da classe
 */
PontosVenda::~PontosVenda(){

	for(unsigned i = 0; i < ptsVenda.size(); i++)
		delete ptsVenda.at(i);

	for(unsigned j= 0; j < utentes.size(); j++)
		delete utentes.at(j);

}


/**
 * metodo que imprime toda a informacao que possui sobre todos os pontos de venda da cidade
 */
void PontosVenda::imprime() const{

	if(ptsVenda.size() == 0){
		cout << "Nao ha nenhuma informacao para imprimir!" << endl;
		return;
	}

	for(unsigned i = 0; i < ptsVenda.size(); i++){

		ptsVenda.at(i)->imprimeInfoPDV();
		cout << "--------------" << endl;

	}
}

/**
 * metodo que imprime toda a informacao que possui sobre todas as maquinas da cidade
 */
void PontosVenda::imprimeSoMaquinas() const{

	bool haInfo = false;

	for(unsigned i = 0; i < ptsVenda.size(); i++){

		if(!ptsVenda.at(i)->eLoja()){ //o ponto de venda atual e uma maquina

			haInfo = true;
			ptsVenda.at(i)->imprimeInfoPDV();
			cout << "--------------" << endl;

		}
	}

	if(!haInfo)
		cout << "Nao ha nenhuma informacao relativa a maquinas para imprimir!" << endl;

}



/**
 * metodo que imprime toda a informacao que possui sobre todas as lojas da cidade
 */
void PontosVenda::imprimeSoLojas() const{

	bool haInfo = false;

	for(unsigned i = 0; i < ptsVenda.size(); i++){

		if(ptsVenda.at(i)->eLoja()){ //o ponto de venda atual e uma loja

			haInfo = true;
			ptsVenda.at(i)->imprimeInfoPDV();
			cout << "--------------" << endl;

		}
	}

	if(!haInfo)
		cout << "Nao ha nenhuma informacao relativa a lojas para imprimir!" << endl;

}


/**
 * metodo que imprime a informacao relativa aos utentes que possuem um bilhete assinatura
 */
void PontosVenda::imprimeAssinantes() const{

	if(utentes.size() == 0){
		cout << "Nao ha informacao relativa a assinantes!" << endl;
		return;
	}

	cout << "Informacao relativa a todos os assinantes:" << endl << endl;

	for(unsigned i = 0; i < utentes.size(); i++){

		utentes.at(i)->imprimeInfoUtente();
		cout << endl << endl;

	}
}


/**
 * metodo que imprime toda a informacao relativa a um ponto de venda, especificado pelo local onde se encontra (parte do principio que so ha uma maquina/loja em cada local)
 * @param local local onde se encontra o ponto de venda
 */
void PontosVenda::imprimePDV(string local) const{

	bool encontrou = false;

	for(unsigned i = 0; i < ptsVenda.size(); i++){

		if(ptsVenda.at(i)->getLocal() == local){

			cout << "Local encontrado:" << endl;
			encontrou = true;
			ptsVenda.at(i)->imprimeInfoPDV();
		}

	}

	if(!encontrou)
		throw LocalInexistente(local);
}


/**
 * metodo que extrai a informacao de um ficheiro, atualizando a informacao dos utentes e pontos de venda
 * @param ficheiro nome do ficheiro onde esta guardada a informacao
 * @return retorna 0 se executou sem problemas, 1 se ocorreu um erro (ex: ficheiro nao existente)
 */
int PontosVenda::load_file(string ficheiro){

	ifstream f;
	f.open(ficheiro);

	if(!f.is_open()){	//nao conseguiu abrir o ficheiro
		return 1;
	}


	//primeiros valores no ficheiro sao os precos de cada zona; sao extraidos no inicio
	float valor_unico, valor_diario, valor_ass;
	vector<vector<float> >	precosZona;

	for(unsigned i = 1; i <= 4; i++){

		f >> valor_unico >> valor_diario >> valor_ass;	//extrai os valores dos precos relativos aos diferentes tipos de bilhetes, para cada uma das 4 zonas
		vector<float> p;
		p.push_back(valor_unico);
		p.push_back(valor_diario);
		p.push_back(valor_ass);
		precosZona.push_back(p);

	}

	Bilhete::setPrecosZona(precosZona);

	string linha;

	while(!f.eof()){

		f >> linha;

		if(linha == "MAQUINA"){ //informacao sobre uma maquina

			f >> linha; //vai extrair o local

			linha = replaceUnderscoresWithSpaces(linha);

			Maquina* m = new Maquina(linha); //cria uma nova maquina com o local extraido


			while(1){
				f >> linha; //tenta extrair um bilhete (se existir)

				if(linha == "*****"){ //acabou a informacao sobre essa maquina
					this->addPDV(m);
					break;
				}
				else if(linha == "Ocasional"){ //informacao sobre bilhete ocasional

					string categoria, duracao;
					float preco;
					f >> categoria >> preco >> duracao;
					BilheteOcasional b1(categoria, preco, duracao); //cria o novo bilhete
					m->addBilheteO(b1); //adiciona o bilhete a maquina

				}
			}
		}else if(linha == "LOJA"){ //informacao sobre uma loja

			f >> linha; //vai extrair o local

			linha = replaceUnderscoresWithSpaces(linha);

			Loja* l = new Loja(linha); //cria uma nova loja com o local extraido


			while(1){

				f >> linha; //tenta extrair um bilhete (se existir)

				if(linha == "*****"){ //acabou a informacao sobre essa loja

					Maquina* w = dynamic_cast<Maquina*>(l);
					this->addPDV(w);
					break;
				}
				else if(linha == "Ocasional"){//informacao sobre bilhete ocasional

					string categoria, duracao;
					float preco;
					f >> categoria >> preco >> duracao;
					BilheteOcasional b2(categoria, preco, duracao); //cria o novo bilhete
					l->addBilheteO(b2); //adiciona o bilhete a loja


				}else if(linha == "Assinatura"){ //informacao sobre bilhete assinatura

					string categoria, tipo;
					float preco;
					f >> categoria >> preco >> tipo;

					//se bilhete for do tipo normal
					if(tipo == "normal"){

						string nome;

						f >> nome; //extrai o nome do utente
						nome = replaceUnderscoresWithSpaces(nome);

						Utente* u = new Utente(nome); //cria um novo utente normal

						BilheteAssinatura b3(categoria, preco, tipo, u); //cria um bilhete, associado a esse utente
						l->addBilheteA(b3);
						this->addUtente(u);
						//adiciona o bilhete a loja, e adiciona o utente ao vetor de utentes


					} //se bilhete for do tipo junior
					else if(tipo == "junior"){

						string nome, cc;
						int idade;

						f >> nome >> idade >> cc; //extrai nome, idade e CC do utente

						nome = replaceUnderscoresWithSpaces(nome);

						Utente* u = new UtenteJunior(nome, idade, cc); //cria um novo utente junior

						BilheteAssinatura b4(categoria, preco, tipo, u); //cria um bilhete, associado a esse utente
						l->addBilheteA(b4);
						this->addUtente(u);
						//adiciona o bilhete a loja, e adiciona o utente ao vetor de utentes


					//se bilhete for do tipo senior
					}else if(tipo == "senior"){

						string nome, cc;
						int idade;

						f >> nome >>idade >> cc; //extrai nome, idade e CC do utente

						nome = replaceUnderscoresWithSpaces(nome);

						Utente* u = new UtenteSenior(nome, idade, cc); //cria um novo utente senior
						BilheteAssinatura b5(categoria, preco, tipo, u); //cria um bilhete, associado a esse utente
						l->addBilheteA(b5);
						this->addUtente(u);
						//adiciona o bilhete a loja, e adiciona o utente ao vetor de utentes


					//se bilhete for do tipo estudante
					}else if(tipo == "estudante"){

						string nome, cc, escola;
						int idade;

						f >> nome >> idade >> cc >> escola; //extrai nome, idade, CC e escola do utente

						nome = replaceUnderscoresWithSpaces(nome);
						escola = replaceUnderscoresWithSpaces(escola);

						Utente* u = new UtenteEstudante(nome, idade, cc, escola); //cria um novo utente senior
						BilheteAssinatura b6(categoria, preco, tipo, u); //cria um bilhete, associado a esse utente
						l->addBilheteA(b6);
						this->addUtente(u);
						//adiciona o bilhete a loja, e adiciona o utente ao vetor de utentes

					}else{
					}

				}

			}

		}


	}

	f.close();
	return 0;
}


/**
 * metodo que guarda toda a informacao que possui num ficheiro de texto, para uso futuro
 * @param ficheiro nome do ficheiro onde vai ser guardada a informacao
 * @return retorna 0 se executou sem problemas, 1 se ocorreu um erro
 */
int PontosVenda::save_file(string ficheiro){

	ofstream f;
	f.open(ficheiro, ofstream::out | ofstream::trunc); //apaga o conteudo do ficheiro, se existir

	if(!f.is_open()){	//nao conseguiu abrir o ficheiro
		cerr << "Nao foi possivel abrir o ficheiro!";
		return 1;
	}

	vector<vector<float> > precosZona = Bilhete::getPrecosZona();

	//insere no ficheiro os precos relativos as zonas e aos tipos de bilhete
	for(unsigned i = 0; i < precosZona.size(); i++){

		f << precosZona.at(i).at(0) << " " << precosZona.at(i).at(1) << " " << precosZona.at(i).at(2);

		if(i < (precosZona.size() - 1))
			f << endl;
	}


	for(unsigned i = 0; i < ptsVenda.size(); i++){

		//verifica se o PDV atual e uma loja ou nao
		if(ptsVenda.at(i)->eLoja())
			f << endl << "LOJA" << endl;
		else f << endl << "MAQUINA" << endl;

		//insere o local no ficheiro
		f << replaceSpacesWithUnderscores(ptsVenda.at(i)->getLocal()) << endl;

		for(unsigned j = 0; j < ptsVenda.at(i)->getBilhetesO().size(); j++){ //info sobre bilhetes ocasionais

			f << "Ocasional" << endl;
			f << ptsVenda.at(i)->getBilhetesO().at(j).getCategoria() << endl;
			f << ptsVenda.at(i)->getBilhetesO().at(j).getPreco() << endl;
			f << ptsVenda.at(i)->getBilhetesO().at(j).getDuracao() << endl;

		}


		if(ptsVenda.at(i)->eLoja()){

			Loja* l = dynamic_cast<Loja*>(ptsVenda.at(i)); //info sobre bilhetes assinatura (se for loja)

			if(l != NULL){


				for(unsigned k = 0; k < l->getBilhetesA().size(); k++){

					f << "Assinatura" << endl;
					f << l->getBilhetesA().at(k).getCategoria() << endl;
					f << l->getBilhetesA().at(k).getPreco() << endl;

					string tipo = l->getBilhetesA().at(k).getTipo();
					f << tipo << endl;
					Utente* u = l->getBilhetesA().at(k).getAssinante();


					//insere no ficheiro a info do utente associado ao bilhete assinatura atual

					if(tipo == "normal"){

						f << *u << endl;

					}else if(tipo == "estudante"){

						UtenteEstudante *u1 = dynamic_cast<UtenteEstudante *>(u);

						if(u1 != NULL){
						f << *u1 << endl;

						}

					}else if(tipo == "senior"){

						UtenteSenior *u1 = dynamic_cast<UtenteSenior *>(u);

						if(u1 != NULL){
							f << *u1 << endl;

						}

					}else if(tipo == "junior"){

						UtenteJunior *u1 = dynamic_cast<UtenteJunior *>(u);

						if(u1 != NULL){
						f << *u1 << endl;

						}
					}else{
						cerr << "um ou mais utentes nao foram definidos corretamente!";
						return 1; //encontrado um tipo invalido
					}

			}

			}
		}


		f << "*****"; //usado para sinalizar o fim da informacao relativa a esse PDV
	}



	f.close();

	return 0;
}


/**
 * metodo que procura por um determinado utente, dado o seu id, e o retorna, se for encontrado
 * @param id id do utente que se quer encontrar
 * @return utente que se queria encontrar
 */
Utente* PontosVenda::getUtente(unsigned int id) const{

	for(unsigned i = 0; i < utentes.size(); i++){

		if(utentes.at(i)->getId() == id)
			return utentes.at(i);

	}

	throw UtenteInexistente(id);
}


/**
 * retorna o vetor com todos os utentes que possuem um bilhete assinatura
 * @return vetor com os utentes
 */
vector<Utente*> PontosVenda::getUtentesAssinatura() const{
	return utentes;
}


/**
 * metodo que "compra" um bilhete ocasional num ponto de venda especificado pelo seu local
 * @param local local do ponto de venda
 * @param bo bilhete que se pretende comprar
 */
void PontosVenda::comprarBilheteOcasional(string local, BilheteOcasional& bo){

	if(findPDV(local) != -1)
		ptsVenda[findPDV(local)]->addBilheteO(bo);
	else throw LocalInexistente(local);

}

/**
 * metodo que "compra" um bilhete assinatura numa loja especificada pelo seu local (lanca uma excecao se nao existir nenhum PDV no local)
 * @param local local da loja
 * @param ba bilhete que se pretende comprar
 * @return true se conseguiu comprar, false caso contrario (PDV e uma maquina)
 */
bool PontosVenda::comprarBilheteAssinatura(string local, BilheteAssinatura& ba){


	addUtente(ba.getAssinante()); //lanca uma excecao se o utente for repetido!!

	if(findLoja(local) != -1){

		Loja* l = dynamic_cast<Loja*>(ptsVenda[findLoja(local)]);
		if(l != NULL){
			l->addBilheteA(ba);
			return true;
			}
	}
	else if(findPDV(local) != -1){ //verifica se ha uma maquina nesse local

		return false;
	}
	else throw LocalInexistente(local);

}


/**
 * metodo que tenta encontrar um ponto de venda que esteja num determinado local, retornando o indice desse elemento no vetor dos pontos de venda (se existir)
 * @param local local onde queremos procurar o ponto de venda
 * @return indice no vetor (-1 se nao existir)
 */
int PontosVenda::findPDV(string local) const{

	for(unsigned i = 0; i < ptsVenda.size(); i++){
		if(ptsVenda[i]->getLocal() == local)
			return i;
	}
	return -1;
}


/**
 * metodo que tenta encontrar uma loja que esteja num determinado local, retornando o indice dessa loja no vetor dos pontos de venda (se ela existir)
 * @param local local da loja
 * @return indice da loja no vetor dos pontos de venda (-1 se nao existir)
 */
int PontosVenda::findLoja(string local) const{

	for(unsigned i = 0; i < ptsVenda.size(); i++){
		if((ptsVenda[i]->getLocal() == local) && (ptsVenda[i]->eLoja()))
			return i;
	}
	return -1;
}


/**
 * metodo que elimina um utente da base de dados, assim como a informacao relativa ao seu bilhete de assinatura
 * @param id id do utente que se pretende eliminar
 */
void PontosVenda::eliminaAssinatura(unsigned int id){
	bool bexiste = false;
	bool existe = false;
	for(unsigned i = 0; i < utentes.size() ; i++){
		if(utentes[i]->getId() == id){
			utentes.erase(utentes.begin() + i);
			existe = true;
		}
	}
	if(existe){
		for(unsigned i = 0; i < ptsVenda.size(); i++){
			if(ptsVenda[i]->eLoja()){

				Loja* l = dynamic_cast<Loja*>(ptsVenda.at(i));
				if(l != NULL){
				if(l->eraseBilheteA(id))
					bexiste = true;

				}
			}
		}

	}
	else throw UtenteInexistente(id);

	if(!bexiste)
		throw BilheteInexistente();


}

/**
 * metodo que elimina uma loja ou maquina, com base no local onde se encontra
 * @param local local onde o ponto de venda se encontra
 */
void PontosVenda::eliminaPDV(string local){
	int pos;
	pos = findPDV(local);
	if(pos != -1){

			if(ptsVenda[pos]->eLoja()){

				Loja* l = dynamic_cast<Loja*>(ptsVenda.at(pos));

			if(l != NULL){
				for(unsigned j = 0; j < l->getAssinantes().size(); j++)

					for(unsigned k = 0; k < utentes.size(); k++){

						if(l->getAssinantes()[j] == utentes[k]) //apontador de utente no bilhete assinatura aponta para o mesmo endereco que o apontador de utente no vetor utentes!
						utentes.erase(utentes.begin() + k);
				}
			}
			}
			ptsVenda.erase(ptsVenda.begin() + pos);
}
	else throw LocalInexistente(local);
}


/**
 * metodo que adiciona um novo ponto de venda a base de dados (lanca uma excecao se ja existe um ponto de venda nesse local)
 * @param m nova maquina/loja a ser adicionada
 */
void PontosVenda::addPDV(Maquina* m){

	for(unsigned i = 0; i < ptsVenda.size(); i++){

		if(ptsVenda.at(i)->getLocal() == m->getLocal())
			throw LocalRepetido(m->getLocal());

	}

	ptsVenda.push_back(m);
}

/**
 * metodo que adiciona um novo ponto de venda a base de dados (lanca uma excecao se ja existe um ponto de venda nesse local)
 * @param local local do novo ponto de venda
 * @param loja indica se o ponto de venda a adicionar e uma loja ou nao
 */
void PontosVenda::addPDV(string local, bool loja){

	for(unsigned i = 0; i < ptsVenda.size(); i++){

		if(ptsVenda.at(i)->getLocal() == local)
			throw LocalRepetido(local);

	}

	Maquina* m;

	if(loja)
		m = new Loja(local);
	else m = new Maquina(local);

	ptsVenda.push_back(m);

}

/**
 * metodo que adiciona um novo utente ao vetor de utentes
 * @param u utente que ira ser adicionado
 */
void PontosVenda::addUtente(Utente* u){

	for(unsigned i = 0; i < utentes.size(); i++){

		if(utentes.at(i)->getId() == u->getId())	//nao deixa haver dois utentes com o mesmo id!!
			throw UtenteRepetido(u->getId());

	}

	utentes.push_back(u);
}


/**
 * metodo que ordena os elementos do vetor de utentes por ordem alfabetica
 */
void PontosVenda::sortUtentesNome(){

	sort(utentes.begin(), utentes.end(), ordenaUtentesNome);
}

/**
 * metodo que ordena os elementos do vetor de utentes por ordem crescente de id
 */
void PontosVenda::sortUtentesId(){

	sort(utentes.begin(), utentes.end(), ordenaUtentesId);
}


/**
 * metodo que ordena os elementos do vetor de PDVs por ordem crescente de local
 */
void PontosVenda::sortPDVsPorLocal(){

	sort(ptsVenda.begin(), ptsVenda.end(), ordenaPorLocal);
}


/**
 * metodo que ordena os bilhetes num determinado ponto de venda
 * @param local local do ponto de venda
 * @param crescente indica se a ordem desejada e a ordem crescente ou decrescente do preco dos bilhetes
 */
void PontosVenda::sortPDV(string local, bool crescente){

	if(findPDV(local) != -1){

		if(crescente)
			ptsVenda.at(findPDV(local))->sortBilhetesCrescente();
		else ptsVenda.at(findPDV(local))->sortBilhetesDecrescente();


	}else throw LocalInexistente(local);


}
