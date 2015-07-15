#ifndef SERIAL_H
#define SERIAL_H

/* Interface da camada de aquisi��o de dados. Essa camada � respons�vel pela comunica��o com o hardware AIRVIEW/EXT 
   e aquisi��o dos valores de pot�ncia do espectro */
   
/* Autor: Ruan Delgado Gomes
   Data: 02/06/2010 */

#include "UnknownPortException.h" 

//#include "socklib.h"

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Serial {
public:
        
       Serial(string port_name);  
       int Read(char *buffer, int buffer_len);
       int Write(char *buffer, int buffer_len);
       virtual ~Serial();
       
private:
       HANDLE hCom;
       bool Open(string port_name);
       bool ConfigurePort();
       bool ConfigureTimeOuts();
       void Close();      

};

#endif // SERIAL_H
