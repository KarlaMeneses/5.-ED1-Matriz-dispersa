//---------------------------------------------------------------------------

#pragma hdrstop

#include "UMatrizvectorcomprimido.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <iostream>
#include <string>
///////
int MatrizCSR::existe_elemento(indice f,indice c){
	int lug_antes = 0;
	for(int i = 0;i < (f - 1); i++){
		lug_antes =lug_antes + (vf[i+1] - vf[i]);
	}
	int max_elem_fila = vf[f] - vf[f - 1];
	for(int i = 0;i < max_elem_fila; i++){
		if(vc[lug_antes + i] == c)
			return lug_antes + i;
	}
	return -1;
}
int MatrizCSR::donde_insertar(indice f,indice c){
	int lug_antes = 0;
	for(int i = 0;i < (f - 1); i++){
		lug_antes += (vf[i+1] - vf[i]);
	}
	int nuevo_lugar = lug_antes;
    int lugar = lug_antes;
	int max_elem = vf[f] - vf[f - 1];
    for(int i = 0; i < max_elem; i++){
		lugar = lug_antes + i;
		if(c == vc[lugar])
//			return nuevo_lugar + 1;
			nuevo_lugar = lugar;
	}
//	return -1;
	return nuevo_lugar;
}

MatrizCSR::MatrizCSR(){
	df = dc = repe = nt = 0;
	vd = new int[df * dc];
	vc = new int[df * dc];
	vf = new int[df + 1];
	for(int i = 0; i < df + 1; i++)
		vf[i] = 1;
}
void MatrizCSR::dimensionar(int f, int c){
	df = f;
	dc = c;
	vd = new int[df * dc];
	vc = new int[df * dc];
	vf = new int[df + 1];
	for(int i = 0; i < df + 1; i++)
		vf[i] = 1;
}
int MatrizCSR::dimension_Fila(){
	return df;
}
int MatrizCSR::dimension_columna(){
	return dc;
}

void MatrizCSR::poner(indice f, indice c, elemento valor){
   if (f >= 1 && f <= df && c >= 1 && c <= dc) {
        int lugar = existe_elemento(f, c);
		if(lugar != -1){
            vd[lugar] = valor;
            //Analizar si valor == repe
            if(valor == repe){
                for(int i = lugar; i < nt;i ++){
                    vd[i] = vd[i+1];
                    vc[i] = vc[i+1];
                }
                for(int i = f; i < df + 1; i++)
                   vf[i]--;
                nt--;
            }
        }else{
			int pos = donde_insertar(f, c);
			for(int i = nt; i > pos; i--){
				vd[i] = vd[i - 1];
				vc[i] = vc[i - 1];
			}
			vd[pos] = valor;
			vc[pos] = c;
			nt++;
			for(int i = f; i < df + 1; i++)
                vf[i]++;
        }
    }

}
int MatrizCSR::Elemento(indice f, indice c){
    if (f >= 1 && f <= df && c >= 1 && c <= dc) {
        int lugar = existe_elemento(f, c);
		if(lugar == -1)
			return repe;
		else
            return vd[lugar];
	}else
		cout<<"ERROR DE RANGO\n";
}
void MatrizCSR::definir_valor_repetido(elemento valor){
    repe = valor;
    int i = 0;
	while (i < nt) {
		if (vd[i] == valor) {
			for (int j = i; j < nt; j++) {
				vc[j] = vc[j + 1];
				vd[j] = vd[j + 1];
			}
            int f = fila(i);
            for(int i = f;i < df + 1; i++)
                vf[i]--;
			nt--;
		}else
			i++;
	}
}
string MatrizCSR::mostrar(){
/*
	if (nt==0) {
		cout<<"VD [ ]"<<endl;
		cout<<"VC [ ]"<<endl;
		for (int i = 1; i <=(df+1) ; i++) {
			 if (i==1) {
				 cout<<"VF [ ";
			 }

			 if (i>=1 && i<(df+1)) {
				   cout<<vf[i]<<" , ";
			 }

			 if (i==(df+1)) {
				  cout<<vf[i]<<" ]"<<endl;
			 }

		}

	}else{
		for (int i = 1; i <=nt ; i++) {
			 if (i==1) {
				 cout<<"VD [ ";
			 }

			 if (i>=1 && i<nt) {
				   cout<<vd[i]<<" , ";
			 }

			 if (i==nt) {
				  cout<<vd[i]<<" ]"<<endl;
			 }

		}

		for (int i = 1; i <=nt ; i++) {
			 if (i==1) {
				 cout<<"VC [ ";
			 }

			 if (i>=1 && i<nt) {
				   cout<<vc[i]<<" , ";
			 }

			 if (i==nt) {
				  cout<<vc[i]<<" ]"<<endl;
			 }

		}

		for (int i = 1; i <=(df+1) ; i++) {
			 if (i==1) {
				 cout<<"VF [ ";
			 }

			 if (i>=1 && i<(df+1)) {
				   cout<<vf[i]<<" , ";
			 }

			 if (i==(df+1)) {
				  cout<<vf[i]<<" ]"<<endl;
			 }

		}

	}

		cout<<endl<<endl;

		int ele;
		for (int f = 1; f <=df ; f++) {
			for (int c = 1; c <= dc; c++) {
				 ele=Elemento(f,c);
					 if (c==1) {
						cout<<"| ";
					 }
					 if (c>=1 && c<dc) {
						 cout<< ele <<"  ";
					 }
					 if (c==dc) {
						  cout<< ele <<" |"<<endl;
					 }
			}
		}
		cout<<endl<<endl;
		*/
    string r = "";
	for (int i = 1; i <= df; i++) {
		r += "| ";
		for (int j = 1; j <= dc; j++) {
			int e = Elemento(i, j);
			r += to_string(e) + "  ";
		}
		r += "|\n";
	}
	int max = df * dc;
	r += "vd: ";
	for (int i = 0; i < max; i++)
		r += to_string(vd[i]) + ",";
	r += "\nvc: ";
	for (int i = 0; i < max; i++)
		r += to_string(vc[i]) + ",";
	r += "\nvf: ";
	for (int i = 0; i < df+ 1; i++)
		r += to_string(vf[i]) + ",";
	return r;
}
