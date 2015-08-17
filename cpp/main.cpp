#include <cstdlib>
#include <iostream>
#include <windows.h>
#include "Guarabo.h"
using namespace std;

int main(){
	Guarabo *t;
	try {	
		t = new Guarabo();
		delete t;
	}
	catch (UnknownPortException &e) {
		cout << "Tente novamente!";
	}
	return 0;
}
