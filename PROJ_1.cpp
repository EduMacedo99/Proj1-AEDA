#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Bilhete.h"
#include "Utente.h"
#include "Maquina.h"
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


	Utente* u1 = new UtenteEstudante("Antonio", 17, "0174014", "Ribadouro");
	BilheteAssinatura b1("Z1", "estudante", u1);
	b1.imprimeInfoBilhete();


	return 0;
}
