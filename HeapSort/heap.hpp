#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

class Heap{
	public:
		Heap();
		~Heap();
		int getTamanho();
		void Leitor(string Nome);
		void HeapSort();
		void CriaHeap(int ini, int fim);
		void imprime(string Nome);
	private:
		int tamanho;
		vector<int> vetor;
};

Heap::Heap(){
}

Heap::~Heap(){
}

int Heap::getTamanho(){
	return tamanho;
}

void Heap::Leitor(string Nome){
	int aux;
	ifstream iFile;
	iFile.open(Nome.c_str());

	if(!iFile.is_open()){
		cout << "Falha ao abrir o arquivo!" << endl;
		exit(1);
	}

	iFile >> tamanho;

	while(!iFile.eof()){
		iFile >> aux;
		vetor.push_back(aux);
	}

	vetor.pop_back();
}

void Heap::HeapSort(){
	int aux;

	for(int i = (vetor.size() - 1) /2; i >= 0; i--){
		CriaHeap(i, tamanho-1);
	}

	for(int i = tamanho-1; i >= 1; i--){
		aux = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = aux;
		CriaHeap(0, i-1);
	}
}

void Heap::CriaHeap(int ini, int fim){
	int pai = vetor[ini]; //pai recebe o valor inicial
	int filho = 2 * ini + 1; //calculado o filho desse pai

	while(filho <= fim){ //enquanto filho estiver no vetor
		if(filho < fim){ 
			if(vetor[filho] < vetor[filho + 1]){ //verifica qual dos filhos eh maior
				filho++; //muda o filho somando um
			}
		}
		if(pai < vetor[filho]){ //se o filho for maior que o pai
			vetor[ini] = vetor[filho]; //os dois sao trocados
			ini = filho;
			filho = 2 * ini + 1; //e o novo filho eh calculado
		}else{
			filho = fim + 1; //se o filho for menor que o pai, apenas eh calculado o proximo filho	
		}
	}
	vetor[ini] = pai; //no final de tudo, o vetor na posicao inicial recebe o pai calculado
}

void Heap::imprime(string Nome){
	ofstream oFile;
	oFile.open(Nome.c_str());

	for(int i = 0; i < vetor.size(); i++){
		oFile << vetor[i] << endl;
	}

	oFile.close();
}

#endif