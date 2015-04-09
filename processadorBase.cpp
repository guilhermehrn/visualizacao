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

void imprimir(Grafo graf[]) {
	char aux;
	for (int i = 0; i < 1; i++) {
		cout << "grafo: " << graf[i].id << endl;

		for (int j = 1; j < 7; j++) {
			cout << "pessoa: " << graf[i].pessoas[j].idPessoa << endl;
			for (int l = 0; l < 26; l++) {

				aux = l + 65;

				cout <<" "<< aux << ":" << graf[i].pessoas[j].quantLocalVis[l];
			}
			cout<<endl;

		}

	}

}
/*
void lerArquivo(char *caminho, Grafo *graf) {
	ifstream entrada;
	string rotulo = "*";

	int idGrafo = 0, idPessoa = 0, idPessoa2 = -1, idLocal = 0;
	int local;

	Grafo grafo;

	Local auxLocal;
	Pessoa auxPessoa;
	auxPessoa.idPessoa = -1;
	for (int i = 1; i < 26; i++) {
		auxPessoa.quantLocalVis[i] = 0;
	}

	entrada.open(caminho);
	entrada >> rotulo;
	while (!entrada.eof()) {
		if (rotulo == "graph") {
			entrada >> idGrafo;
		}
		entrada >> rotulo;

		if (rotulo == "edige") {
			entrada >> idPessoa;

			if (idPessoa != idPessoa2 && auxPessoa.idPessoa != -1) {
				graf->pessoas.push_back(auxPessoa);

			} else {

				auxPessoa.idPessoa = idPessoa;

				entrada >> local;
				auxPessoa.quantLocalVis[local - 65]++;
				entrada >> idLocal;

			}
		}
	}

	imprimir(graf);

}
*/


void lerArquivo(char *caminho, Grafo graf[]){
	ifstream entrada;
	Pessoa auxPessoa;
	string logo;
	int idgraf;
	int idpes;
	char tipoloc;
	int idloc;
	int aux;

	entrada.open(caminho);

	for (int i = 0; i < 26; i++) {
			auxPessoa.quantLocalVis[i] = 0;
		}

	auxPessoa.idPessoa = -1;

	while (!entrada.eof()){

		entrada>>logo;

		if(logo == "graph"){
			entrada>>idgraf;
			graf[idgraf].id = idgraf;
		}
		if(logo == "edge"){

			entrada>>idpes;

			if(idpes != auxPessoa.idPessoa && auxPessoa.idPessoa != -1){
				graf[idgraf].pessoas.push_back(auxPessoa);
				for (int i = 0; i < 26; i++) {
							auxPessoa.quantLocalVis[i] = 0;
						}
			}
			entrada>>tipoloc;
			entrada>>idloc;

			aux =tipoloc;
			auxPessoa.quantLocalVis[aux-65]++;
			auxPessoa.idPessoa = idpes;
		}



	}

	imprimir(graf);

}



























