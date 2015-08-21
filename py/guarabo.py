import serial
from serial.tools.list_ports import comports
from time import sleep

def to_ms(tempo):
    return tempo*1000

class Guarabo(object):

  #  def __init__(self, porta):
   #     self.serial = serial.Serial(porta, 9600)
    #    self.serial.write("POWL 55\n\r")
     #   self.serial.write("POWR 47\n\r")
     
    def __init__(self): #Construtor da classe
        verifica = self.verifica_porta()
        print verifica
        if(verifica != None):
            print "aqui"
            self.serial = serial.Serial(verifica, 9600)
            self.serial.write("POWL 55\n\r")
            self.serial.write("POWR 47\n\r")
        else:
            print "Nao foi possivel conectar!"
                

    def verifica_porta(self):
        #p = "COM"
        lista = list(serial.tools.list_ports.comports())
        for i in range(len(lista)):
            #porta = p
            #porta+=str(i)
            print lista[i]
            try:
                self.s = serial.Serial(lista[i],9600,None,None,False,False,None,False,None)
                self.s.write("SETGIRO\n\r")
                sleep(1)
                retorno = self.s.read(2)
                retorno+='\0'
                if(strcmp(retorno,"OK") == 0):
                    print "here!!"
                    return lista[i]
                #else:
                    #retorno = self.s.read(2)
                    #retorno = "OK"
                    #print "help!!"
                    #print "Conectou!!!!!!!!!!!!!"
                    #porta+=str(i+1)
                    #return lista[i]
            except IOError:
                print "Ratunamatata"
        return None
    
    def andar_frente_tempo(self, tempo):
        t = to_ms(tempo)
        self.serial.write("SETFORWARD\n\r")
        #self.serial.write("STEP\n\r")
        self.serial.write("SETTIME {}\n\r".format(t))
        self.serial.write("STEP\n\r")
        sleep(tempo)

	def andar_frente_distancia(self, distancia):
		tempo = ((distancia+2.1667)/8.3036)
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
		
	def andar_tras_tempo_distancia(self, distancia):
		tempo = ((distancia-2)/7.2)
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

	def turn_right(sefl, angulo):
		tempo = ((grau-37.857)/(48.571))
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

	def turn_left(self, angulo):
		#Falta a regressão
		
    def get_distancia(self):
        self.serial.flushInput()
        a = self.seria000l.readline()
        b =  self.serial.readline()
        self.serial.write("SENGET\n\r")
        return self.serial.readline()

print "conectando"
gua = Guarabo() 
print "conectou"
gua.andar_pra_frente(2)

