/*
 * processadorBase.hpp
 *
 *  Created on: Apr 7, 2015
 *      Author: guilherme
 */

#ifndef PROCESSADORBASE_HPP_
#define PROCESSADORBASE_HPP_


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

struct Local{
	char tipo;
	int quantVisitas;
	vector<int> idLocal;
};


struct Pessoa{
	int idPessoa;
	int quantLocalVis[26];
	vector<Local>localvisitado;
};


struct Grafo{
	int id;
	vector<Pessoa> pessoas;
};

float calculaSimilaridad(Pessoa pessoa1, Pessoa pessoa2, int tamanhoVet);

float calculaSimilaridadNormalizado(Pessoa pessoa1, Pessoa pessoa2, int tamanhoVet);

void imprimir(Grafo graf[], int quant);

void imprimirArquivo(Grafo graf[], int quant);

void determinarSimilares(Grafo graf[], int quant);

void imprlimirArquivoSimilaridade(Grafo graf[], int quant);

void lerArquivo(char *caminho, Grafo *graf);

void retornaTabFrequencia();



#endif /* PROCESSADORBASE_HPP_ */
