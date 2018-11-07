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

		cout << "Precos para a zona " << i << ": bilhete unico, diario e assinatura, por esta ordem" << endl;
		cin >> valor_unico >> valor_diario >> valor_ass;	//extrai os valores dos precos relativos aos diferentes tipos de bilhetes, para cada uma das 4 zonas
		vector<float> p;
		p.push_back(valor_unico);
		p.push_back(valor_diario);
		p.push_back(valor_ass);
		precosZona.push_back(p);

		}

		Bilhete::setPrecosZona(precosZona);

}

int main() {
	vector<vector<float> > precosZona;
	vector<float> precosZ1, precosZ2, precosZ3, precosZ4;
	precosZ1.push_back(1.20); //unico
	precosZ1.push_back(4.20); //diario
	precosZ1.push_back(18.95); //assinatura
	precosZ2.push_back(1.30); //unico
	precosZ2.push_back(5.00); //diario
	precosZ2.push_back(20.85); //assinatura
	precosZ3.push_back(1.50); //unico
	precosZ3.push_back(5.50); //diario
	precosZ3.push_back(24.95); //assinatura
	precosZ4.push_back(1.85); //unico
	precosZ4.push_back(6.75); //diario
	precosZ4.push_back(28.95); //assinatura
	precosZona.push_back(precosZ1);
	precosZona.push_back(precosZ2);
	precosZona.push_back(precosZ3);
	precosZona.push_back(precosZ4);
	Bilhete::setPrecosZona(precosZona);
	precosZona = Bilhete::getPrecosZona();
	for(int i = 0; i < precosZona.size(); i++){
		cout << endl << "Zona " << i + 1 << ": " << endl;
		for(int j = 0; j < precosZona.at(i).size(); j++){
			cout << precosZona.at(i).at(j) << " ";
		}
	}
	cout << endl << "-----------" << endl;
	PontosVenda pv;
	/*if(pv.load_file("/Users/EduRibeiro/Desktop/AEDA/PROJ_1/src/file.txt") != 0)
		return 1;*/

	//if(pv.load_file("C:\\Users\\Eduardo Macedo\\eclipse-workspace\\projaeda\\src\\file.txt") != 0)
			//return 1;



	Utente* u1 = new UtenteEstudante("Antonio", 17, "0174014", "Ribadouro");
	Utente* u2 = new UtenteJunior("Rui Manel", 10, "908012");
	Utente* u3 = new UtenteSenior("Arlindo", 89, "129391");
	Utente* u4 = new UtenteJunior("Miguel", 16, "2874190");
	pv.addUtente(u1);
	pv.addUtente(u2);
	pv.addUtente(u3);
	pv.addUtente(u4);
	//pv.imprimeAssinantes();
	pv.sortUtentes();
	cout << endl;
	//pv.imprimeAssinantes();
	BilheteOcasional bo1("Z2", "diario");
	BilheteOcasional bo2("Z3", "diario");
	BilheteOcasional bo3("Z4", "unico");
	BilheteOcasional bo4("Z2", "diario");
	Maquina* m1 = new Maquina("campanha");
	m1->addBilheteO(bo1);
	m1->addBilheteO(bo2);
	m1->addBilheteO(bo3);
	Maquina* m2 = new Loja("s joao");
	Loja* l2 = dynamic_cast<Loja*>(m2);
	Maquina* m3 = new Loja("oleh");
	Loja* l3 = dynamic_cast<Loja*>(m3);


	/*BilheteAssinatura* b1 = new BilheteAssinatura("Z4", "senior", u3);
	BilheteAssinatura* b2 = new BilheteAssinatura("Z3", "estudante", u1);*/

	BilheteAssinatura b1("Z4", "senior", u3);
	BilheteAssinatura b2("Z3", "estudante", u1);
	BilheteAssinatura b3("Z2", "senior", u2);
	BilheteAssinatura b4("Z1", "estudante", u4);
	l2->addBilheteO(bo4);
	l2->addBilheteA(b1);
	l2->addBilheteA(b2);
	l3->addBilheteA(b3);
	l3->addBilheteA(b4);

	pv.addPDV(m1);
	pv.addPDV(m2);
	pv.addPDV(m3);

	pv.imprime();
	cout << "remove bilhete do miguel" << endl << "//////////////////////////////////////////" << endl;
	pv.eliminaAssinatura("Miguel");
	pv.imprime();
	cout << "remove oleh" << endl << "//////////////////////" << endl;
	pv.eliminaPDV("oleh");
	pv.imprime();
	pv.imprimeAssinantes();



	/*PontosVenda pv;
	pv.imprime();
	cout << endl << "||||||||||||||||||||||" << endl;
	pv.imprimeAssinantes();
	if(pv.load_file("/Users/EduRibeiro/Desktop/AEDA/PROJ_1/src/file1.txt") != 0)
		return 1;
	precosZona = Bilhete::getPrecosZona();
	for(int i = 0; i < precosZona.size(); i++){
		cout << endl << "Zona " << i + 1 << ": " << endl;
		for(int j = 0; j < precosZona.at(i).size(); j++){
			cout << precosZona.at(i).at(j) << " ";
		}
	}
	cout << endl << "-----------" << endl;
	pv.imprime();
	cout << endl << "||||||||||||||||||||||" << endl;
	pv.imprimeAssinantes();*/

	/*try{
		pv.imprimePDV("s joao");
		cout << endl << endl;
		pv.sortPDV("s joao", true);
		pv.imprimePDV("s joao");
		pv.sortPDV("s joao", false);
		pv.imprimePDV("s joao");
	}catch(LocalInexistente& lr){
		cout << "Nao ha nenhum ponto de venda no local " << lr.getLocal() << "!" << endl;
	}*/

	return 0;
}

/*
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
		cout << "p -> imprimir a informacao especifica a um ponto de venda, a especificar pelo seu local" << endl;
		cout << "u -> imprimir toda a informacao relativa aos utentes que possuem um bilhete assinatura" << endl;
		cout << "c -> comprar/adicionar um bilhete qualquer, num determinado ponto de venda" << endl;
		cout << "a -> apagar uma assinatura do sistema, eliminando o utente e o seu bilhete assinatura" << endl;
		cout << "r -> remover um ponto de venda qualquer do sistema, especificado pelo seu local" << endl;
		cout << "s -> sair do programa" << endl;
		cout << "Operacao: ";
		cin >> sndOp;
		cout << endl;

		if(sndOp == 'i'){

			pv.imprime();
			cout << endl << endl;

		}else if(sndOp == 'z'){

			pedePrecoZonas();
			cout << endl << endl;

		}else if(sndOp == 'p'){

			string local;
			char cresc;
			cout << "Insira o local do ponto de venda: ";
			getline(cin, local); //pode haver problemas com isto...
			cout << "Pretende a ordenacao crescente ou decrescente dos precos dos bilhetes?" << endl;
			cout << "c -> crescente" << endl << "d -> decrescente" << endl;

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

			//fazer
		}else if(sndOp == 'a'){

			//fazer
		}else if(sndOp == 'r'){

			//a
		}else if(sndOp != 's'){

			cout << "Operacao invalida." << endl << endl;
		}


	}while(sndOp != 's');

	//perguntar se quer guardar a informacao num ficheiro

	return 0;

}*/
