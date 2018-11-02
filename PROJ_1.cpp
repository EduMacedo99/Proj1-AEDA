#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

	PontosVenda pv;

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
	pv.imprimeAssinantes();

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


	/*BilheteAssinatura* b1 = new BilheteAssinatura("Z4", "senior", u3);
	BilheteAssinatura* b2 = new BilheteAssinatura("Z3", "estudante", u1);*/

	BilheteAssinatura b1("Z4", "senior", u3);
	BilheteAssinatura b2("Z3", "estudante", u1);

	l2->addBilheteO(bo4);
	l2->addBilheteA(b1);
	l2->addBilheteA(b2);

	pv.addPDV(m1);
	pv.addPDV(m2);

	pv.imprime();



	try{

		pv.imprimePDV("s joao");
		cout << endl << endl;

		Maquina* m = pv.findPDV("s joao");
		m->sortBilhetesCrescente();

		pv.imprimePDV("s joao");

		m->sortBilhetesDecrescente();
		pv.imprimePDV("s joao");



	}catch(LocalInexistente& lr){

		cout << "Nao ha nenhum ponto de venda no local " << lr.getLocal() << "!" << endl;

	}

	return 0;
}
