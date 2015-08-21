import guarabo

print "conectando"
gua = guarabo.Guarabo("COM8") 
print "conectou"
y = gua.get_distancia()
print y
print "ACABOU"
