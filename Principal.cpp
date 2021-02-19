#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
//added
#include <iostream> //for system pause
#include "UMatrizvectorcoordenado.h"
#include "UMatrizvectorcomprimido.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   /*
	MatrizCOO* m;
	m = new MatrizCOO();
	m->definir_valor_repetido(1);
	m->dimensionar(5,7);
	cout << m->mostrar() << endl;
	m->poner(1,1,20);
	m->poner(3,4,21);
	cout << m->mostrar() << endl;
	m->definir_valor_repetido(0);
	cout << m->mostrar() << endl;   */
	//////////
	MatrizCSR* m;
	m = new MatrizCSR();
	m->dimensionar(5,5);
	m->poner(1,1,1);
	m->poner(1,4,2);
	m->poner(2,1,3);
	m->poner(2,2,4);
	m->poner(2,4,5);
	m->poner(3,1,6);
	m->poner(3,3,7);
	m->poner(3,4,8);
	m->poner(3,5,9);
	m->poner(4,3,10);
	m->poner(4,4,11);
	m->poner(5,5,12);

	cout << m->mostrar() << endl;

	system("pause");
	return 0;
}
