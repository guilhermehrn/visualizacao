/*
 * processadorBase.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: guilherme
 */

#include"processadorBase.hpp"

float calculaSimilaridad(Pessoa pessoa1, Pessoa pessoa2, int tamanhoVet) {

	float aux = 0;

	for (int i = 0; i < tamanhoVet; i++) {
		aux = aux
				+ pow((pessoa1.quantLocalVis[i] - pessoa2.quantLocalVis[i]), 2);

	}
	return sqrt(aux);
}

void imprimir(Grafo graf[], int quant) {
	char aux;
	for (int i = 0; i < quant; i++) {
		cout << "grafo: " << graf[i].id << endl;

		for (int j = 0; j < (int) graf->pessoas.size(); j++) {
			cout << "pessoa: " << graf[i].pessoas[j].idPessoa << endl;
			for (int l = 0; l < 26; l++) {

				aux = l + 65;

				cout << " " << aux << ":"
						<< graf[i].pessoas[j].quantLocalVis[l];
			}
			cout << endl;

		}

	}

}

void determinarSimilares(Grafo graf[], int quant, int tolerancia) {
float simil;
	for (int graf1 = 0; graf1 < quant; graf1++) {
		for (int pes1 = 0; pes1 < (int) graf->pessoas.size(); pes1++) {
			for (int graf2 = 0; graf2 < quant; graf2++) {
				for (int pes2 = 0; pes2< (int) graf->pessoas.size(); pes2++){

					simil = calculaSimilaridad(graf[graf1].pessoas[pes1], graf[graf2].pessoas[pes2],26);
					/**add onde e como tem que sair os dados tem que sair os dados*/

				}

			}
		}
	}
}

void imprimirArquivo(Grafo graf[], int quant) {
	ofstream saida;
	char aux;

	saida.open("arquivos/saida.txt");

	for (int i = 0; i < quant; i++) {
		saida << "grafo:" << graf[i].id << endl;

		for (int j = 0; j < (int) graf->pessoas.size(); j++) {
			saida << "pessoa: " << graf[i].pessoas[j].idPessoa << endl;
			for (int l = 0; l < 26; l++) {

				aux = l + 65;

				saida << " " << aux << ":"
						<< graf[i].pessoas[j].quantLocalVis[l];
			}
			saida << endl;

		}

	}

	saida.close();
}

void lerArquivo(char *caminho, Grafo graf[]) {
	ifstream entrada;
	Pessoa auxPessoa;
	string logo;
	int idgraf;
	int idpes;
	char tipoloc;
	int idloc;
	int aux;
	int auxidgraf = -1;
	Local local;

	entrada.open(caminho);

	for (int i = 0; i < 26; i++) {
		auxPessoa.quantLocalVis[i] = 0;
	}

	auxPessoa.idPessoa = -1;

	while (!entrada.eof()) {

		entrada >> logo;
		if (logo == "graph") {
			entrada >> idgraf;
			graf[idgraf].id = idgraf;
			if (auxidgraf != idgraf && auxidgraf != -1) {

				graf[auxidgraf].pessoas.push_back(auxPessoa);
				for (int i = 0; i < 26; i++) {
					auxPessoa.quantLocalVis[i] = 0;
				}
				auxPessoa.idPessoa = -1;
			}

		}

		if (logo == "edge") {

			entrada >> idpes;

			if (idpes != auxPessoa.idPessoa && auxPessoa.idPessoa != -1) {
				graf[idgraf].pessoas.push_back(auxPessoa);
				for (int i = 0; i < 26; i++) {
					auxPessoa.quantLocalVis[i] = 0;
				}

			}
			entrada >> tipoloc;
			entrada >> idloc;

			//colocar aqui o codigo para armazenar as ids dos locais

			aux = tipoloc;
			auxPessoa.quantLocalVis[aux - 65]++;
			auxPessoa.idPessoa = idpes;
		}

		auxidgraf = idgraf;

	}
	graf[idgraf].pessoas.push_back(auxPessoa);

	entrada.close();
}

