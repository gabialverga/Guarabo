#include <iostream>
#include "Serial.h"
using namespace std;

class Guarabo{
	public:
		Guarabo();
		
		void setMotor();
		
		void andarFrente_tempo(int tempo);
		
		void andarFrente_distancia(int dist);
		
		void andarTras_tempo(int tempo);
		
		void andarTras_distancia(int dist);
		
		void virarDireita(int grau);
		
		void virarEsquerda(int grau);
		
		bool verificaPorta();
		
		int getDistancia();
		
		Guarabo(string porta);
		
		virtual ~Guarabo();
		
	private:
		
		Serial *serial;
};


