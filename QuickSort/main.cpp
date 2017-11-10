// FEITO POR FELIPE HOMRICH MELCHIOR //

#include <iostream>
#include <cstdlib>

#include "quicksort.hpp"

using namespace std;

int main(int argc, char **argv){
	Quick *quick = new Quick();

	if(argc < 3){
		cout << "Faltam Argumentos! Uso: " << argv[0] << " <ENTRADA> <SAIDA.TXT>" << endl;
		exit(1);
	}

	quick->Leitor(argv[1]);
	quick->QuickSort(0, quick->getTamanho());
	quick->Imprime(argv[2]);

	return 0;

}