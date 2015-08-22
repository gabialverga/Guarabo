import serial
from time import sleep

class Guarabo(object):

    def __init__(self):
        x = self.verificar_porta()
        if(not x):
            print "nao foi possivel conectar, tente novamente!"
        else:
            print "Conectado com sucesso!!"
    
    def verificar_porta(self):
        for i in range(22):
            COM = "COM"
            porta = COM+str(i+1)
            try:
                self.serial = serial.Serial(porta, 9600, timeout=0)
                self.serial.write("SETGIRO\n\r")
                retorno = self.serial.readline()
                if(retorno == "OK"):
                    return True
                sleep(1)
                print "Porta - " + porta + " - encontrada"
            except self.serial.SerialTimeoutException:
                print porta + "Nao conectou"
        return False

print "aqui"
try:
    guara = Guarabo()
    print "acabou"
except:
    print "Tente novamente!!"
