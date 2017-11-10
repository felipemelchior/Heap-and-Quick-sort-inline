#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

class Quick{
	public:
		Quick();
		~Quick();
		int getTamanho();
		void Leitor(string Nome);
		void QuickSort(int ini, int fim);
		void Imprime(string Nome);
	private:
		int tamanho;
		vector <int> vet;
};

Quick::Quick(){
}

Quick::~Quick(){
}

int Quick::getTamanho(){
	return vet.size();
}

void Quick::Leitor(string Nome){
	int aux;
	ifstream iFile;
	iFile.open(Nome.c_str());

	iFile >> tamanho;

	while(!iFile.eof()){
		iFile >> aux;
		vet.push_back(aux);
	}
	vet.pop_back();
}

/* 
	PSEUDOCODIGO INSPIRADO
	function quicksort(array)
    if length(array) > 1
        pivot := select any element of array
        left := first index of array
        right := last index of array
        while left ≤ right
            while array[left] < pivot
                left := left + 1
            while array[right] > pivot
                right := right - 1
            if left ≤ right
                swap array[left] with array[right]
                left := left + 1
                right := right - 1
        quicksort(array from first index to right)
        quicksort(array from left to last index)
*/

void Quick::QuickSort(int ini, int fim){
	int pivo = vet[(ini + fim)/2];
	int left = ini;
	int right = fim;
	int aux;

	while(left <= right){
 		while(vet[left] < pivo)	left++;
		while(vet[right] > pivo) right--;	

		if(left <= right){ 
			swap(vet[right], vet[left]);
			left++;
			right--;
		}
	}

	if(right > ini)
		QuickSort(ini, right);
	if(left < fim)
		QuickSort(left+1, fim);
}

void Quick::Imprime(string Nome){
	ofstream oFile;
	oFile.open(Nome.c_str());

	for(int i = 0; i < vet.size(); i++){
		oFile << vet[i] << endl;
	}

	oFile.close();
}

#endif