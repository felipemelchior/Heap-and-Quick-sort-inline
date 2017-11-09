#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

class Quick{
	public:
		Quick();
		~Quick();
		void Leitor(string Nome);
		void QuickSort();
		void Imprime(string Nome);
	private:
		int tamanho;
		vector <int> vet;
};

Quick::Quick(){
}

Quick::~Quick(){
}

void Quick::Leitor(string Nome){
	int aux;
	ifstream iFile;
	iFile.open(Nome.c_str());

	if(!iFile.is_open){
		cout << "Erro ao ler o arquivo!" << endl;
		exit(1);
	}

	iFile >> tamanho;

	while(!iFile.eof()){
		iFile >> aux;
		vet.push_back(aux);
	}
	vet.pop_back();
}

void Quick::QuickSort(){
	
}

void Quick::Imprime(string Nome){
	ofstream oFile;
	oFile.open(Nome.c_str());

	for(int i = 0; i < vet.size(); i++){
		oFile >> vet[i] << endl;
	}

	oFile.close;
}

#endif