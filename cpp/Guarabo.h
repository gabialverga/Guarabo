#include <iostream>
#include "Serial.h"
using namespace std;

class Guarabo{
	public:
		Guarabo();
		
		void setMotor();
		
		void andarFrente_tempo(float tempo);
		
		void andarFrente_distancia(float dist);
		
		void andarTras_tempo(float tempo);
		
		void andarTras_distancia(float dist);
		
		void virarDireita(float grau);
		
		void virarEsquerda(float grau);
		
		bool verificaPorta();
		
		int getDistancia();
		
		Guarabo(string porta);
		
		virtual ~Guarabo();
		
	private:
		
		Serial *serial;
};


