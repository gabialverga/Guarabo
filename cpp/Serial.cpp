#include <iostream>
#include "Serial.h"

using namespace std;

Serial::Serial(string port_name) {
   
    bool test  = true; 
    
    test = test && Serial::Open(port_name.c_str());
    test = test && Serial::ConfigurePort();
    test = test && Serial::ConfigureTimeOuts();
    
    if(!test) {
    
        throw
            UnknownPortException("Invalid Port");
    
    }

}

Serial::~Serial() {
             
	Serial::Close();

}

//Abre a porta serial. São passados como parâmetro o identificador da porta (HANDLE) e o nome da porta (Ex: "COM1")
bool Serial::Open(string nome_porta) {
    
    hCom = CreateFile(nome_porta.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL,OPEN_EXISTING, 0, NULL);
    if(hCom == INVALID_HANDLE_VALUE) {
            return false;
    }
    else {
            return true;
    }
}

//Configura os parâmetros da comunicação com a serial. Apenas é passado o identificador como parametro.
bool Serial::ConfigurePort() {
     DCB dcb;
     
     if(!GetCommState(hCom, &dcb)) {
         return false;
     }

     dcb.BaudRate = CBR_9600;
     dcb.ByteSize = 8;
     dcb.Parity = NOPARITY;
     dcb.StopBits = ONESTOPBIT;
     
     if(SetCommState(hCom, &dcb) == 0) {
         return false;
     }
     else {
         return true;
     }

}
 /*Método para ler dados da porta serial. Recebe como parametros o identificador, o buffer onde serao coloocados os dados recebidos 
 e o tamanho do buffer */
int Serial::Read(char *buffer, int buffer_len) {
    
    DWORD bytes_lidos;
    ReadFile(hCom, buffer, buffer_len,&bytes_lidos, NULL);
    
    return bytes_lidos;

}

 /*Método para escrever dados na porta serial. Recebe como parametros o identificador, o buffer onde estao os dados a enviar
 e o tamanho do buffer */
int Serial::Write(char *buffer, int buffer_len) {
    DWORD bytes_escritos = 0;
  
    WriteFile(hCom, buffer, buffer_len, &bytes_escritos, NULL);
    
    return bytes_escritos;
}

bool Serial::ConfigureTimeOuts() {

   COMMTIMEOUTS CommTimeouts;
   
   if( GetCommTimeouts(hCom, &CommTimeouts) == 0 ) {
      return false;
   }
                                
   CommTimeouts.ReadIntervalTimeout = 2;
   CommTimeouts.ReadTotalTimeoutMultiplier = 0;
   CommTimeouts.ReadTotalTimeoutConstant = 2;
   CommTimeouts.WriteTotalTimeoutMultiplier = 5;
   CommTimeouts.WriteTotalTimeoutConstant = 5;

   if( SetCommTimeouts(hCom, &CommTimeouts) == 0 ) {
      return false;
   }
   
   return true;
}

void Serial::Close() {
     CloseHandle(hCom);
}
