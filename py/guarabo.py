import serial
from time import sleep

def to_ms(tempo):
    return tempo*1000

class Guarabo(object):

    def __init__(self, porta):
        self.serial = serial.Serial(porta, 9600)
        self.serial.write("POWL 55\n\r")
        self.serial.write("POWR 47\n\r")

    def andar_pra_frente(self, tempo):
        t = to_ms(tempo)
        self.serial.write("SETFORWARD\n\r")
        self.serial.write("STEP\n\r")
        self.serial.write("SETTIME {}\n\r".format(t))
        sleep(tempo)

    def andar_pra_tras(self, tempo):
        t = to_ms(tempo)
        self.serial.write("SETREVERSE\n\r")
        self.serial.write("STEP\n\r")
        self.serial.write("SETTIME {}\n\r".format(t))
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
        
print "conectando"
g = Guarabo("COM8")
print "conectou"
g.andar_pra_frente(2)
g.andar_pra_tras(2)
g.virar_a_esquerda(2)
g.virar_a_direita(2)
