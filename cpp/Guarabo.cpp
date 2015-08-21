#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include "Serial.h"
#include "Guarabo.h"
#include <math.h>
using namespace std;


Guarabo::Guarabo() { //construtor sem parâmetro que encontra a porta correta para conexão
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
void Guarabo::setMotor(){  //método de define a potência dos motores
	string com = "POWL 100\r";
	serial->Write((char*)com.c_str(), com.size());
	string com2 = "POWR 80\r";
	serial->Write((char*)com2.c_str(), com2.size());
}

string conv(int tempo){ //método de converter de int para string
		stringstream Valor;
		Valor << tempo;
		string time = Valor.str();
		return time;
}
void Guarabo::andarFrente_tempo(float tempo){ //método de andar para frente recebendo como parâmetro o tempo
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

void Guarabo::andarFrente_distancia(float dist){ // método de andar para frente recebendo como parâmetro a distância
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

void Guarabo::andarTras_tempo(float tempo){  //método de andar para trás recebendo o tempo como parâmetro
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

void Guarabo::andarTras_distancia(float dist){ // método de andar para trás recebendo a distância
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

void Guarabo::virarDireita(float grau){ // método de virar à direita recebendo como parâmetro o ângulo
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
void Guarabo::virarEsquerda(float grau){// método de virar à esquerda recebendo o ângulo como parâmetro
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

bool Guarabo::verificaPorta(){ // método que encontra a porta serial de conexão com o robô
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


int Guarabo::getDistancia(){ // método de encontrar a distância de um obstáculo
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
