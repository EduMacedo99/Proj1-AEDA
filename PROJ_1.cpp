#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Bilhete.h"
#include "Utente.h"
#include "Maquina.h"
#include "PontosVenda.h"
using namespace std;

/**
 * funcao que pede ao utilizador do programa que insira os precos desejados para os bilhetes (unico, diario e assinatura), para cada zona
 */
void pedePrecoZonas(){

	float valor_unico, valor_diario, valor_ass;
	vector<vector<float> >	precosZona;

	for(unsigned i = 1; i <= 4; i++){

		do{
			cout << "Precos para a zona " << i << ": bilhete unico, diario e assinatura, por esta ordem" << endl;
			cin >> valor_unico >> valor_diario >> valor_ass;	//extrai os valores dos precos relativos aos diferentes tipos de bilhetes, para cada uma das 4 zonas

			if((valor_unico <= 0) || (valor_diario <= 0) || (valor_ass <= 0)){

				cout << "Valor(es) invalido(s). Tem de ser valores positivos " << endl;
			}

		}while((valor_unico <= 0) || (valor_diario <= 0) || (valor_ass <= 0));

		vector<float> p;
		p.push_back(valor_unico);
		p.push_back(valor_diario);
		p.push_back(valor_ass);
		precosZona.push_back(p);

		}

		Bilhete::setPrecosZona(precosZona);

}

/**
 * funcao auxiliar que permite ao utilizador do programa a compra de um bilhete
 */
void compraBilhete(PontosVenda& pv){

	string local, nome;
	char r;

	do{
		cout << endl << "O bilhete e ocasional ou de assinatura?" << endl;
		cout << endl << "o -> Ocasional";
		cout << endl << "a -> assinatura" << endl;
		cin >> r;

		if(r == 'o'){  //se for bilhete ocasional

			string categoria, duracao;

			//pede categoria e duracao
			do{

				cout << endl;
				cout << "Categoria: "; cin >> categoria;
				cout << "Duracao: "; cin >> duracao;

				//verifica se os inputs sao validos
				if( ((categoria != "Z1") && (categoria != "Z2") && (categoria != "Z3") && (categoria != "Z4")) || ((duracao != "unico") && (duracao != "diario"))){

					cout << "Valor(es) invalido(s). Insira novamente." << endl << endl;
				}

			}while( ((categoria != "Z1") && (categoria != "Z2") && (categoria != "Z3") && (categoria != "Z4")) || ((duracao != "unico") && (duracao != "diario")));


			BilheteOcasional b1(categoria, duracao);


			cout << "Insira o local do ponto de venda: ";
			cin.ignore(10, '\n');
			getline(cin, local);

			try{

				pv.comprarBilheteOcasional(local, b1);
				cout << endl << "---------" << endl << "Operacao efetuada com sucesso!" << endl << "---------" << endl;

			}catch(LocalInexistente &li){

				cout << "Nao existe nenhum ponto de venda no local " << li.getLocal() << "!" << endl << endl;
			}


		}else if(r == 'a'){ //se for bilhete assinatura

			string categoria, tipo;

			//pede categoria e tipo
			do{
				cout << "Categoria: "; cin >> categoria;
				cout << "Tipo: "; cin >> tipo;

				if( ((categoria != "Z1") && (categoria != "Z2") && (categoria != "Z3") && (categoria != "Z4")) || ((tipo != "normal") && (tipo != "junior") && (tipo != "senior") && (tipo != "estudante"))){

					cout << "Valor(es) invalido(s). Insira novamente." << endl << endl;
				}

			}while( ((categoria != "Z1") && (categoria != "Z2") && (categoria != "Z3") && (categoria != "Z4")) || ((tipo != "normal") && (tipo != "junior") && (tipo != "senior") && (tipo != "estudante")));

			Utente* u;
			cout << endl;
			cout << "Nome: ";
			cin.ignore(10, '\n');
			getline(cin, nome);

			if(tipo == "normal"){

				u = new Utente(nome);


			}else{ //se tipo diferente de normal, pede - se idade e CC


				int idade;
				string cc;

				cout << "Idade: "; cin >> idade;
				cout << "CC: "; cin >> cc;

				if(tipo == "estudante"){

					string escola;
					cout << "Escola: ";
					cin.ignore(10, '\n');
					getline(cin, escola);

					u = new UtenteEstudante(nome, idade, cc, escola);

				}
				else if(tipo == "senior"){

					u = new UtenteSenior(nome, idade, cc);

				}else u = new UtenteJunior(nome, idade, cc);

			}

			BilheteAssinatura b2(categoria, tipo, u);

			cout << "Insira o local do ponto de venda: ";


			if((tipo == "junior") || (tipo == "senior")){
				cin.ignore(10, '\n');
			}

			getline(cin, local);

			try{


				if(!pv.comprarBilheteAssinatura(local, b2))
					cout << endl << "O local introduzido e uma maquina! Nao e possivel comprar bilhetes assinatura." << endl << endl;
				else cout << endl << "---------" << endl << "Operacao efetuada com sucesso!" << endl << "---------" << endl;


			}catch(LocalInexistente &li){

				cout << "Nao existe nenhum ponto de venda no local " << li.getLocal() << "!" << endl << endl;

				//esta excecao, na verdade, nunca ira ser lancada, pois nesta funcao e criado um novo utente, com um novo id.
				//No entanto, achamos boa pratica adicionar o tratamento desta excecao, de qualquer das maneiras.
			}catch(UtenteRepetido & ur){

				cout << "Ja existe um assinante com id " << ur.getId() << "!" << endl << endl;
			}


		}else{

			cout << "Operacao invalida." << endl << endl;
		}


	}while((r != 'o') && (r != 'a'));



}


int main(){

	cout << "---------GESTAO DE BILHETES NO METRO---------" << endl << endl;

	PontosVenda pv;
	char op;
	bool valid = false;

	do{

		valid = false;

		cout << "Prentende carregar a informacao sobre os pontos de venda de algum ficheiro? (s -> sim; n -> nao)" << endl;

		cin >> op;

		if(op == 's'){

			bool good_file;
			do{

			good_file = true;
			string ficheiro;
			valid = true;
			cout << "indique o nome do ficheiro: ";
			cin >> ficheiro;

			if(pv.load_file(ficheiro) != 0){
				cout << "Houve problemas com a abertura deste ficheiro. Por favor escolha outro" << endl;
				good_file = false;
			}

			}while(!good_file);

		}else if(op == 'n'){

			valid = true;
			cout << "Indique, entao, quais irao ser os precos dos bilhetes respetivos as diferentes zonas." << endl << endl;

			pedePrecoZonas();
		}


		if(!valid){
			cout << "Essa operacao nao e valida." << endl;

		}

	}while(!valid);

	cout << endl << endl;
	char sndOp;

	do{

		//podem faltar algumas operacoes
		cout << "Indique qual a operacao que pretende efetutar:" << endl;
		cout << "i -> imprimir a informacao toda sobre o sistema de pontos de venda" << endl;
		cout << "z -> modificar os valores dos precos dos bilhetes, para cada zona" << endl;
		cout << "d -> imprimir os valores dos precos dos bilhetes, para cada zona" << endl;
		cout << "p -> imprimir a informacao especifica a um ponto de venda (maquina ou loja), a especificar pelo seu local" << endl;
		cout << "u -> imprimir toda a informacao relativa aos utentes que possuem um bilhete assinatura" << endl;
		cout << "c -> comprar/adicionar um bilhete qualquer, num determinado ponto de venda" << endl;
		cout << "a -> apagar uma assinatura do sistema, eliminando o utente e o seu bilhete assinatura" << endl;
		cout << "r -> remover um ponto de venda qualquer do sistema, especificado pelo seu local" << endl;
		cout << "n -> adicionar um novo ponto de venda (maquina ou loja) ao sistema" << endl;
		cout << "s -> sair do programa" << endl;
		cout << "Operacao: ";
		cin >> sndOp;
		cout << endl;

		if(sndOp == 'i'){

			pv.imprime();
			cout << endl << endl;

		}else if(sndOp == 'z'){

			pedePrecoZonas();
			cout << endl << "---------" << endl << "Operacao efetuada com sucesso!" << "---------" << endl;

		}else if(sndOp == 'd'){

		cout << endl;
		Bilhete::imprimePrecosZona();
		cout << endl;

		}else if(sndOp == 'p'){

			string local;
			char cresc;
			cout << "Insira o local do ponto de venda: ";
			cin.ignore(10, '\n');
			getline(cin, local);
			cout << "Pretende a ordenacao crescente ou decrescente dos precos dos bilhetes?" << endl;
			cout << "c -> crescente" << endl << "d -> decrescente" << endl;
			cin >> cresc;

			if(cresc == 'c'){

				try{
					pv.sortPDV(local, true);
					pv.imprimePDV(local);


				}catch(LocalInexistente &li){
					cout << "Nao existe nenhum ponto de venda no local " << li.getLocal() << "!" << endl << endl;
				}

			}else if(cresc == 'd'){

				try{
					pv.sortPDV(local, false);
					pv.imprimePDV(local);

				}catch(LocalInexistente &li){
					cout << "Nao existe nenhum ponto de venda no local " << li.getLocal() << "!" << endl << endl;
				}


			}else cout << "Operacao invalida." << endl << endl;


		}else if(sndOp == 'u'){

			cout << "Ordenando os utentes por ordem alfabetica:" << endl;
			pv.sortUtentes();
			pv.imprimeAssinantes();
			cout << endl << endl;

		}else if(sndOp == 'c'){


			compraBilhete(pv);


		}else if(sndOp == 'a'){

			unsigned int id;
			cout << "Indique o id do assinante a eliminar: ";
			cin >> id;

			try{

				pv.eliminaAssinatura(id);
				cout << endl << "---------" << endl << "Operacao efetuada com sucesso!" << endl << "---------" << endl;

			}catch(UtenteInexistente& ui){

				cout << "Nao existe nenhum utente com id " << ui.getId() << "!" << endl << endl;

			}catch(BilheteInexistente& bi){

				cout << "Ocorreu um erro no sistema; o utente existe, mas nao possui bilhete na base de dados!" << endl << endl;
			}

		}else if(sndOp == 'r'){

			string local;
			cout << "Insira o local do ponto de venda: ";
			cin.ignore(10, '\n');
			getline(cin, local);


			try{

				pv.eliminaPDV(local);
				cout << endl << "---------" << endl << "Operacao efetuada com sucesso!" << endl << "---------" << endl;


			}catch(LocalInexistente & li){

				cout << "Nao existe nenhum ponto de venda no local " << li.getLocal() << "!" << endl << endl;
			}



		}else if(sndOp == 'n'){

			string local;
			char l;
			cout << "Insira o local do ponto de venda: ";
			cin.ignore(10, '\n');
			getline(cin, local);
			Maquina* m;

			do{
				cout << endl << "O ponto de venda sera uma maquina ou loja?" << endl;
				cout << endl << "m -> maquina";
				cout << endl << "l -> loja" << endl;
				cin >> l;

				if(l == 'm'){

					m = new Maquina(local);

				}else if(l == 'l'){

					m = new Loja(local);

				}else{

					cout << "Operacao invalida." << endl << endl;
				}


			}while((l != 'm') && (l != 'l'));


			try{

				pv.addPDV(m);
				cout << endl << "---------" << endl << "Operacao efetuada com sucesso!" << endl << "---------" << endl;

			}catch(LocalRepetido& lr){

				cout << "Ja existe um ponto de venda no local " << lr.getLocal() << "!" << endl << endl;
			}


		}else if(sndOp != 's'){

			cout << "Operacao invalida." << endl << endl;
		}


	}while(sndOp != 's');

	char trdOp;
	bool validExit;

	do{

		validExit = false;
		cout << endl << endl;
		cout << "Pretende guardar a informacao modificada dos pontos de venda num ficheiro?" << endl;
		cout << "s -> guardar" << endl << "n -> nao guardar" << endl;
		cout << "Operacao: ";
		cin >> trdOp;

		if(trdOp == 's'){

			bool good_saveFile;
			string ficheiro;

			do{

				good_saveFile = true;
				cout << endl << "Qual o nome do ficheiro? ";
				cin >> ficheiro;

			if(pv.save_file(ficheiro) != 0){

				cout << "Ocorreu um erro com um ficheiro. Por favor tente novamente.";
				good_saveFile = false;
			}


			}while(! good_saveFile);

			validExit = true;

		}
		else if(trdOp == 'n'){

			validExit = true;

		}
		else{

			cout << "Operacao invalida.";

		}


	}while(! validExit);


	cout << "Desligando o programa..." << endl;
	cout << "Obrigado!";

	return 0;

}
