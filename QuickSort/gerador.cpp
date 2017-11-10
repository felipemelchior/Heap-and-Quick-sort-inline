#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char **argv){
	int tamanho, aux, x, y;
	vector <int> vetor;
	ofstream oFile;
	oFile.open("saidagerada.txt");

	cin >> tamanho;

	for(int i = 0; i < tamanho; i++){
		vetor.push_back(i);
	}

	srand(time(NULL));
	for(int i = 0; i < tamanho; i++){
		x = rand()%tamanho;
		y = rand()%tamanho;

		aux = vetor[x];
		vetor[x] = vetor[y];
		vetor[y] = aux;
	}


	oFile << tamanho << endl;
	for(int i = 0; i < tamanho; i++){
		oFile << vetor[i] << endl;
	}

	oFile.close();
}