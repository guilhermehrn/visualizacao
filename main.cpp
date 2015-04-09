/*
 * main.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: guilherme
 */

#include "processadorBase.hpp"

int main(int arc, char *argv[]) {

	string caminho;

	Grafo graf[1];
	cout << "agora";
	lerArquivo(argv[1], graf);

	string a;
	int b;
	int c;
	char d;
	ifstream et;

	et.open(argv[1]);
/*
	et>>a;
	cout<<endl<<a;
	et>>b;
	cout<<endl<<b;
	et>>a;
	et>>c;
	cout<<endl<<c;
	et>>d;
	cout<<endl<<d;
*/
	return 0;

}
