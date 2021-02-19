//---------------------------------------------------------------------------

#ifndef UMatrizvectorcoordenadoH
#define UMatrizvectorcoordenadoH
//---------------------------------------------------------------------------
//#include <iostream>
#include <string>
using namespace std;

typedef int indice;
typedef int elemento;

class MatrizCOO{
	private:
		int* vf; //puntero
		int* vc;
		int* vd;
		int df,dc;
		int repe;
		int nt;
		indice posicion(int f, int c);
	public:
		MatrizCOO();
		void dimensionar(int nf,int nc);
		int dimension_Fila();
		int dimension_columna();
		void poner(indice f,indice c,elemento valor);
		int Elemento(indice f,indice c);
		void definir_valor_repetido(elemento valor);
		string mostrar();
};
#endif
