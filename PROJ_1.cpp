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

	if(pv.load_file("/Users/EduRibeiro/Desktop/AEDA/PROJ_1/src/file.txt") != 0)
		return 1;



	/*Utente* u1 = new UtenteEstudante("Antonio", 17, "0174014", "Ribadouro");
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

	Loja* l2 = dynamic_cast<Loja*>(m2);*/


	/*BilheteAssinatura* b1 = new BilheteAssinatura("Z4", "senior", u3);
	BilheteAssinatura* b2 = new BilheteAssinatura("Z3", "estudante", u1);*/

	/*BilheteAssinatura b1("Z4", "senior", u3);
	BilheteAssinatura b2("Z3", "estudante", u1);

	l2->addBilheteO(bo4);
	l2->addBilheteA(b1);
	l2->addBilheteA(b2);

	pv.addPDV(m1);
	pv.addPDV(m2);*/

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

	try{

		pv.imprimePDV("s joao");
		cout << endl << endl;

		pv.sortPDV("s joao", true);

		pv.imprimePDV("s joao");

		pv.sortPDV("s joao", false);

		pv.imprimePDV("s joao");



	}catch(LocalInexistente& lr){

		cout << "Nao ha nenhum ponto de venda no local " << lr.getLocal() << "!" << endl;

	}

	return 0;
}

/*int main(){

	cout << "---------GESTAO DE BILHETES NO METRO---------" << endl << endl;

	PontosVenda pv;
	char op;
	bool valid = false;

	do{
		cout << "Prentende carregar a informacao sobre os pontos de venda de algum ficheiro? (s -> sim; n -> nao)" << endl;

		cin >> op;

		if(op == 's'){

			string ficheiro;
			valid = true;
			cout << "indique o nome do ficheiro: ";
			cin >> ficheiro;

			if(pv.load_file(ficheiro) != 0){
				cout << "Houve problemas com a abertura deste ficheiro. Por favor escolha outro" << endl;
				valid = false;
			}

		}else if(op == 'n'){

			valid = true;
			cout << "Indique, entao, quais irao ser os precos dos bilhetes respetivos as diferentes zonas." << endl << endl;

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

			Bilhete::setPrecosZona(precosZona); //meter isto tudo numa funcao? em alguma classe?
		}


		if(!valid){
			cout << "Essa operacao nao e valida." << endl;

		}

	}while(!valid);


	return 0;

}*/
