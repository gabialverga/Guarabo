#include <cstdlib>
#include <iostream>
#include <windows.h>
#include "Guarabo.h"
using namespace std;

int main(){
	Guarabo *t;
	//Serial *s;
	try {	
		t = new Guarabo();//"COM8"
		int grau;
		while(cin>>grau){
		t->andarTras_distancia(grau);
	//	t->virarEsquerda(grau);
		}
		delete t;
	}
	catch (UnknownPortException &e) {
		cout << "Tente novamente!";
	}
	return 0;
}
