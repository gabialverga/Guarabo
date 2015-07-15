import serial
from time import sleep

def to_ms(tempo):
    return tempo*1000

class Guarabo(object):

    def __init__(self, porta):
        self.serial = serial.Serial(porta, 9600)
        self.serial.write("POWL 55\n\r")
        self.serial.write("POWR 47\n\r")

    #def __init__(self):
     #   verifica = verifica_porta()
      #  if(not verifica):
       #     raise Exception
        #self.serial.write("POWL 55\n\r")
        #self.serial.write("POWR 47\n\r")
            

    def andar_pra_frente(self, tempo):
        t = to_ms(tempo)
        self.serial.write("SETFORWARD\n\r")
        #self.serial.write("STEP\n\r")
        self.serial.write("SETTIME {}\n\r".format(t))
        self.serial.write("STEP\n\r")
        sleep(tempo)

    def andar_pra_tras(self, tempo):
        t = to_ms(tempo)
        self.serial.write("SETREVERSE\n\r")
        #self.serial.write("STEP\n\r")
        self.serial.write("SETTIME {}\n\r".format(t))
        self.serial.write("STEP\n\r")
        sleep(tempo)

    def virar_a_direita(self, tempo):
        t = to_ms(tempo)
        self.serial.write("SETREVERSE\n\r")
        #sleep(1000)
        self.serial.write("SETGIRO\n\r")
        #sleep(1000)
        self.serial.write("SETTIME {}\n\r".format(t))
        #sleep(1000)
        self.serial.write("STEP\n\r")
        sleep(tempo)
        self.serial.write("SETFORWARD\n\r")

    def virar_a_esquerda(self, tempo):
        t = to_ms(tempo)
        self.serial.write("SETforward\n\r")
        self.serial.write("SETGIRO\n\r")
        #sleep(1000)
        self.serial.write("SETTIME {}\n\r".format(t))
        #sleep(1000)
        self.serial.write("STEP\n\r")
        sleep(tempo)

    def get_distancia(self):
        self.serial.flushInput()
        a = self.serial.readline()
        b =  self.serial.readline()
        self.serial.write("SENGET\n\r")
        return self.serial.readline()
    def verifica_porta():
        p = "COM"
        for i in range(1,22):
            porta = p
            porta+=to_ms(i)
            try:
                self.s = s.Serial(porta, 9600)
                self.s.write("SETGIRO\n\r")
                sleep(2000)
                retorno = self.s.readline()
                retorno+='\0'
                if(strcmp (retorno,"OK") == 0):
                    print "Conectou!!!!!!!!!!!!!"
                    return True
            except ValueError as err:
                print "Ratunamatata"
        return False
                
    
print "conectando"
gua = Guarabo("COM8")
print "conectou"
print gua.get_distancia()
#g.andar_pra_tras(2)
#g.andar_pra_frente(2)
