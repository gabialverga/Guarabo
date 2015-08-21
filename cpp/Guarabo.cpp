#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include "Serial.h"
#include "Guarabo.h"
#include <math.h>
using namespace std;


Guarabo::Guarabo() { //construtor sem par�metro que encontra a porta correta para conex�o
		string porta; 
		bool verifica = verificaPorta();
		if(!verifica){
			 throw
             	UnknownPortException("Nao foi possivel conectar!!");		
		}
		setMotor();
}
Guarabo::Guarabo(string porta){ //construtor recebendo o identificador da porta saerial para conectar
	serial = new Serial(porta);
	setMotor();	
}
void Guarabo::setMotor(){  //m�todo de define a pot�ncia dos motores
	string com = "POWL 100\r";
	serial->Write((char*)com.c_str(), com.size());
	string com2 = "POWR 80\r";
	serial->Write((char*)com2.c_str(), com2.size());
}

string conv(int tempo){ //m�todo de converter de int para string
		stringstream Valor;
		Valor << tempo;
		string time = Valor.str();
		return time;
}
void Guarabo::andarFrente_tempo(float tempo){ //m�todo de andar para frente recebendo como par�metro o tempo
		string time = conv(tempo*1000);
		string aux = "SETFORWARD\r",step="STEP\r",s="SETTIME ";
		serial->Write((char*)aux.c_str(), aux.size());
		Sleep(1000);
		s += time+'\r';
		serial->Write((char*)s.c_str(),s.size());
		Sleep(1000);			
		serial->Write((char*)step.c_str(),step.size());
		Sleep(tempo*1000+20);
}

void Guarabo::andarFrente_distancia(float dist){ // m�todo de andar para frente recebendo como par�metro a dist�ncia
		int tempo = ((dist+2.1667)/8.3036);//(0.1845*(dist*dist)+6.8274*dist+0.0476);  OK OK
		cout<<tempo<<endl;
		string time = conv(tempo);
		string aux = "SETFORWARD\r",step="STEP\r",s="SETTIME ";
		serial->Write((char*)aux.c_str(), aux.size());
		Sleep(1000);
		s += time+'\r';
		serial->Write((char*)s.c_str(),s.size());
		Sleep(1000);	
		serial->Write((char*)step.c_str(),step.size());
		Sleep(tempo+20);
}

void Guarabo::andarTras_tempo(float tempo){  //m�todo de andar para tr�s recebendo o tempo como par�metro
		string time = conv(tempo*1000);
		string aux = "SETREVERSE\r",step="STEP\r",s="SETTIME ";
		serial->Write((char*)aux.c_str(), aux.size());
	    Sleep(1000);
		s += time+'\r';
		serial->Write((char*)s.c_str(),s.size());
	    Sleep(1000);
		serial->Write((char*)step.c_str(),step.size());
		Sleep(tempo*1000+20);
}

void Guarabo::andarTras_distancia(float dist){ // m�todo de andar para tr�s recebendo a dist�ncia
		int tempo = ((dist-2)/(7.2)); // Ok Ok
		string time = conv(tempo);
		string aux = "SETREVERSE\r",step="STEP\r",s="SETTIME ";
		serial->Write((char*)aux.c_str(), aux.size());
	    Sleep(1000);
		s += time+'\r';
		serial->Write((char*)s.c_str(),s.size());
	    Sleep(1000);
		serial->Write((char*)step.c_str(),step.size());
		Sleep(tempo*1000+20);
}

void Guarabo::virarDireita(float grau){ // m�todo de virar � direita recebendo como par�metro o �ngulo
		float tempo = ((grau-37.857)/(48.571)); // Ok Ok 
		string time = conv(tempo*1000);
		string aux = "SETREVERSE\r", step = "STEP\r", s = "SETTIME ", giro = "SETGIRO\r";
		serial->Write((char*)aux.c_str(), aux.size());
		Sleep(1000);
		serial->Write((char*)giro.c_str(), giro.size());
		s += time+'\r';
		Sleep(1000);
		serial->Write((char*)s.c_str(),s.size());
		Sleep(1000);
		serial->Write((char*)step.c_str(),step.size());
		Sleep(tempo*1000+20);
}
void Guarabo::virarEsquerda(float grau){// m�todo de virar � esquerda recebendo o �ngulo como par�metro
		float tempo = grau;
		string time = conv(tempo*1000);
		cout<<"tempo "<<time<<endl;
		string aux = "SETFORWARD\r", step = "STEP\r", s = "SETTIME ", giro = "SETGIRO\r";
		serial->Write((char*)giro.c_str(), giro.size());
		Sleep(1000);
		s += time + '\r';
		serial->Write((char*)s.c_str(),s.size());
		Sleep(1000);
		serial->Write((char*)step.c_str(),step.size());
		Sleep(tempo*1000+20);
}

bool Guarabo::verificaPorta(){ // m�todo que encontra a porta serial de conex�o com o rob�
		string p = "COM", porta;
		char retorno[3];
		string comando_guarabo = "SETGIRO\r";
		for(int i=1;i<=22;i++){
			porta = p;
			porta += conv(i);
			try {
				serial = new Serial(porta);
				serial->Write((char*)comando_guarabo.c_str(),comando_guarabo.size());
				Sleep(2000);
				serial->Read(retorno,2);
				retorno[2]='\0';
				if(strcmp (retorno,"OK") == 0){
					cout<<"-->"<<porta<<endl;
					return true;
				}
			}
			catch (UnknownPortException &e) {
				
			}
		}
		return false;
}


int Guarabo::getDistancia(){ // m�todo de encontrar a dist�ncia de um obst�culo
	string sen = "SENGET\r";
	char distancia[3];
	int distancia_int;
	serial->Write((char*)sen.c_str(), sen.size());
	serial->Read(distancia, 3);
	distancia_int = atoi(distancia);
	return distancia_int;
}


Guarabo::~Guarabo() {
             
	delete serial;

}
