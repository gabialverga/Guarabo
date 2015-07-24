#include <cstdlib>
#include <iostream>
#include <windows.h>
#include "Guarabo.h"
using namespace std;

int main(){
	Guarabo *t;
	try {	
		t = new Guarabo();//"COM8"
	/*	t->andarFrente_tempo(2.3);//2.2
		t->virarEsquerda(70);
		t->andarFrente_tempo(1);
		t->virarDireita(70);
		t->andarFrente_tempo(1);
		t->virarEsquerda(70);
		t->andarFrente_tempo(1.2);
		t->virarEsquerda(72);
		t->andarFrente_tempo(1.2);	
		t->virarDireita(70); */
	/*	t->andarFrente_tempo(2);
		t->virarDireita(70);	
		t->andarFrente_tempo(2.3);
		t->virarDireita(70);
		t->andarFrente_tempo(1);*/
		
		delete t;
	}
	catch (UnknownPortException &e) {
		cout << "Tente novamente!";
	}
	return 0;
}
