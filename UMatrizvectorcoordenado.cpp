//---------------------------------------------------------------------------

#pragma hdrstop

#include "UMatrizvectorcoordenado.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//added
#include <iostream>
#include <string>

//METODO PRIVADO
indice MatrizCOO::posicion(int f, int c){
	for (int i = 0; i < nt; i++) {
		if (vf[i] == f && vc[i] == c)
			return i;
	}
	return -1;
}
//METODOS PUBLICOS
MatrizCOO::MatrizCOO(){
	df = dc = repe = nt = 0;
	vf = new int[0];  //inicializando los punteros
	vc = new int[0];
	vd = new int[0];
}
void MatrizCOO::dimensionar(int nf,int nc){
	df=nf;
	dc=nc;
	vf = new int[df * dc];
	vc = new int[df * dc];
	vd = new int[df * dc];
}
int MatrizCOO::dimension_Fila(){
	return df;
}
int MatrizCOO::dimension_columna(){
	return dc;
}
void MatrizCOO::poner(indice f,indice c,elemento valor){
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		int lug = posicion(f, c);
		if (lug == -1 && valor != repe && nt < (df * dc))//nt<MAX_MV
		{ // insertar a lo ultimo
			vd[nt] = valor;
			vf[nt] = f;
			vc[nt] = c;
			nt++;
		}
		else {
			vd[lug] = valor;
			if (valor == repe) {//[1,2,3,4]
				for (int i = lug; i < nt; i++) {
					vf[i] = vf[i + 1];
					vc[i] = vc[i + 1];
					vd[i] = vd[i + 1];
				}
				nt--;
			}
		}
	}
}
int MatrizCOO::Elemento(indice f,indice c){
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		int lug = posicion(f, c);
		if (lug >= 0)
			return vd[lug];
		else
			return repe;
	}
	else
		cout << "ERROR FUERA DE RANGO\n";
}
void MatrizCOO::definir_valor_repetido(elemento valor){
	repe=valor;
	int i = 0;
	while (i < nt) {
		if (vd[i] == valor) {
			for (int j = i; j < nt; j++) {
				vf[j] = vf[j + 1];
				vc[j] = vc[j + 1];
				vd[j] = vd[j + 1];
			}
			nt--;
		}else
			i++;
	}
}
string MatrizCOO::mostrar(){
	/*{ MOSTRANDO MATRIZ }*/
	string m = "";
	for (int i = 1; i <= df; i++) {
		m += "|  ";
		for (int j = 1; j <= dc; j++) {
			int e = Elemento(i, j);
			m += to_string(e) + "  ";
		}
		m += " |\n";
	}
	/*{ MOSTRANDO VECTORES }*/
	int i=0;
	string cadd="vd=[";
	string cadf="vf=[";
	string cadc="vc=[";
	while (i<nt){
		char d1 = vd[i];
		int d2=d1;
		cadd=cadd+to_string(d2);

		char f1 = vf[i];
		int f2=f1;
		cadf=cadf+to_string(f2);

		char c1 = vc[i];
		int c2=c1;
		cadc=cadc+to_string(c2);

		if (i<nt-1) {
			cadd=cadd+",";
			cadf=cadf+",";
			cadc=cadc+",";
		}
		i++;
	}
	cout<<m<<endl;
	cout<<cadd+"]"<<endl;
	cout<<cadf+"]"<<endl;
	cout<<cadc+"]"<<endl;
	cout<<"nt= "+to_string(nt)<<endl;
	cout<<"repe= "+to_string(repe)<<endl;
	cout<<"df= "+to_string(df)<<endl;
	return "dc= "+to_string(dc);
}
