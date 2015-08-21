#include <cstdlib>
#include <iostream>
#include <windows.h>
#include "Guarabo.h"
using namespace std;

int main(){
	Guarabo *t;
	//t = new Guarabo();
//	cout<<"\t\tDescrição dos métodos\n\n--> andarFrente_tempo: método de andar para frente de acordo com o tempo (tipo float) recebido como parâmetro em segundos.\n\n--> andarFrente_distancia: método de andar para frente de acordo com a distância (tipo float) recebida como parâmetro em centímetros.\n\n--> andarTras_tempo: método de andar para trás de acordo com o tempo (tipo float) recebido como parâmetro em segundos.\n\n--> andarTras_distancia: método de andar para trás de acordo com a distância (tipo float) recebida como parâmetro em centímetros.\n\n--> virarDireita: método de girar à direita de acordo com o grau (tipo float) recebido como parâmetro.\n\n--> virarEsquerda: método de girar à esquerda de acordo com o grau (tipo float) recebido como parâmetro.\n\n--> getDistancia: método que calcula a distântia entre o Guarabô e um objeto a sua frente, este método não recebe parametros.\n\n";
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


