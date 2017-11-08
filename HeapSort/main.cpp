/* 
   //								    //
  // FEITO POR FELIPE HOMRICH MELCHIOR //
 //									  // */

#include <iostream>
#include <cstdlib>

#include "heap.hpp"

using namespace std;

int main(int argc, char **argv){	
	Heap* heap = new Heap();
	double elapsed, start, end;
	if(argc < 3){
		cout << "Faltam Argumentos!" << endl << "Uso: " << argv[0] << " <ENTRADA> <SAIDA.TXT>" << endl;
		exit(1);
	}

	heap->Leitor(argv[1]);
	heap->HeapSort();
	heap->imprime(argv[2]);

	return 0;
}
