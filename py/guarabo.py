import serial
from serial.tools.list_ports import comports
from time import sleep

def to_ms(tempo):
    return tempo*1000

class Guarabo(object):

    def __init__(self, porta):
        self.serial = serial.Serial(porta, 9600)
        self.serial.write("POWL 100\n\r")
        self.serial.write("POWR 80\n\r")
     
    def andar_frente_tempo(self, tempo):
        t = to_ms(tempo)
        self.serial.write("SETFORWARD\n\r")
        #self.serial.write("STEP\n\r")
        self.serial.write("SETTIME {}\n\r".format(t))
        self.serial.write("STEP\n\r")
        sleep(tempo)

    def andar_frente_distancia(self, distancia):
        tempo = (0.12*distancia + 0.281)
        time = to_ms(tempo)
        self.serial.write("SETFORWARD\n\r")
        self.serial.write("SETTIME {}\n\r".format(time))
        self.serial.write("STEP\n\r")
        sleep(tempo+20)
		
    def andar_tras_tempo(self, tempo):
        t = to_ms(tempo)
        self.serial.write("SETREVERSE\n\r")
        #self.serial.write("STEP\n\r")
        self.serial.write("SETTIME {}\n\r".format(t))
        self.serial.write("STEP\n\r")
        sleep(tempo)
		
    def andar_tras_distancia(self, distancia):
	tempo = (0.138*distancia+0.285)
	time = to_ms(tempo)
	self.serial.write("SETREVERSE\n\r")
        self.serial.write("SETTIME {}\n\r".format(time))
        self.serial.write("STEP\n\r")
        sleep(tempo+20)
		
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

    def turn_right(self, angulo):
	tempo = (0.014*angulo+0.112)
	time = to_ms(tempo)
	self.serial.write("SETREVERSE\n\r")
	self.serial.write("SETGIRO\n\r")
	self.serial.write("SETTIME {}\n\r".format(time))
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

    #def turn_left(self, angulo):
	#Falta a regressao
		
    def get_distancia(self):
        self.serial.flushInput()
        a = self.serial.readline()
        b =  self.serial.readline()
        self.serial.write("SENGET\n\r")
        return self.serial.readline()
