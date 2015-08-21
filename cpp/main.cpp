#include <cstdlib>
#include <iostream>
#include <windows.h>
#include "Guarabo.h"
using namespace std;

int main(){
	Guarabo *t;
	//t = new Guarabo();
//	cout<<"\t\tDescri��o dos m�todos\n\n--> andarFrente_tempo: m�todo de andar para frente de acordo com o tempo (tipo float) recebido como par�metro em segundos.\n\n--> andarFrente_distancia: m�todo de andar para frente de acordo com a dist�ncia (tipo float) recebida como par�metro em cent�metros.\n\n--> andarTras_tempo: m�todo de andar para tr�s de acordo com o tempo (tipo float) recebido como par�metro em segundos.\n\n--> andarTras_distancia: m�todo de andar para tr�s de acordo com a dist�ncia (tipo float) recebida como par�metro em cent�metros.\n\n--> virarDireita: m�todo de girar � direita de acordo com o grau (tipo float) recebido como par�metro.\n\n--> virarEsquerda: m�todo de girar � esquerda de acordo com o grau (tipo float) recebido como par�metro.\n\n--> getDistancia: m�todo que calcula a dist�ntia entre o Guarab� e um objeto a sua frente, este m�todo n�o recebe parametros.\n\n";
	try {	
		float a;

		while(cin>>a){
			
			//t->virarDireita(a);
			t->andarFrente_distancia(a);
		}

		delete t;
	}
	catch (UnknownPortException &e) {
		cout << "Tente novamente!";
	}
	return 0;
}


