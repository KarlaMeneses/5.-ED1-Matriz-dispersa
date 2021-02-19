//---------------------------------------------------------------------------

#ifndef UMatrizvectorcomprimidoH
#define UMatrizvectorcomprimidoH
//---------------------------------------------------------------------------
#include <string>
using namespace std;

typedef int indice;
typedef int elemento;

//int MAX;
class MatrizCSR {
private:
	int* vf;
	int* vc;
	int* vd;
	int df, dc;
	int repe;
	int nt;

	int fila(int indiceVC);

	int existe_elemento(indice f,indice c);
	// busca en vd,vc y vf si existe el elemento
	int donde_insertar(indice f,indice c);
	// determina donde insertar en vd,vc y vf

public:
	MatrizCSR();
	void dimensionar(int f, int c);
	int dimension_Fila();
	int dimension_columna();
	void poner(indice f, indice c, elemento valor);
	int Elemento(indice f, indice c);// be carefull with elemn and Elemn
	void definir_valor_repetido(elemento valor);
	string mostrar();
};
#endif
