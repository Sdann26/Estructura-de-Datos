import math

print ("\n\t\tMONTICULO BINARIO\n")

class MonticuloBinario: #Constructor del Monticulo Binario
	def __init__(self):
		self.listaMonticulo = [0]
		self.tamanoActual = 0

### INSERSION ###

	def insertar(self,k): # Metodo para insertar elemento en el monticulo
		self.listaMonticulo.append(k) # Agrega un elemento al final de la lista
		self.tamanoActual = self.tamanoActual + 1
		self.infiltArriba(self.tamanoActual) 

	def infiltArriba(self,i): # Metodo para poner en orden el elemento insertado
		while i // 2 > 0: # Verifica si la posicion del padre es 0 para salir del bucle
			if self.listaMonticulo[i] < self.listaMonticulo[i // 2]: # Compara el elemento con su padre y si el padre es mayor estos cambian de sitio
				tmp = self.listaMonticulo[i // 2]
				self.listaMonticulo[i // 2] = self.listaMonticulo[i]
				self.listaMonticulo[i] = tmp
			i = i // 2

### ELIMINACION ###

	def eliminarMin(self): # Metodo para eleminar el elemento minimo(Raiz)
		valorSacado = self.listaMonticulo[1]
		self.listaMonticulo[1] = self.listaMonticulo[self.tamanoActual] # Le da el valor del ultimo elemento de la lista(Monticulo) al primero
		self.tamanoActual = self.tamanoActual - 1
		self.listaMonticulo.pop() # Quita el ultimo elemento de la lista 
		self.infiltAbajo(1)
		return valorSacado

	def infiltAbajo(self,i): # Metodo para poner en orden luego de sacar el elemento
		while (i * 2) <= self.tamanoActual: # Verifica que el hijo sea menor que el padre(Este pasa a ser el ultimo elemento)
			hm = self.hijoMin(i) # Le pasamos el valor de la posicion del hijo
			if self.listaMonticulo[i] > self.listaMonticulo[hm]:
				tmp = self.listaMonticulo[i]
				self.listaMonticulo[i] = self.listaMonticulo[hm]
				self.listaMonticulo[hm] = tmp
			i = hm

	def hijoMin(self,i):
		if i * 2 + 1 > self.tamanoActual: 
			return i * 2
		else: #Nos devuelve la posicion del menor hijo
			if self.listaMonticulo[i*2] < self.listaMonticulo[i*2+1]:
				return i * 2 #Hijo Izquierdo
			else:
				return i * 2 + 1 #Hijo Derecho

### CONSTRUCCION ###

	def construirMonticulo(self,unaLista):
		i = len(unaLista) // 2
		self.tamanoActual = len(unaLista)
		self.listaMonticulo = [0] + unaLista[:]
		while (i > 0):
			self.infiltAbajo(i)
			i = i - 1

### IMPRIMIR ###

def imprimir():

	k = 1

	espacio = int(math.log(MonticuloBinario.tamanoActual,2))
	espacio = espacio + 1

	for i in range((espacio-1)**2):
		print (" ",end="")

	for i in range(1,MonticuloBinario.tamanoActual+1):

		for j in range(espacio**2):
			print(" ",end="")

		print(MonticuloBinario.listaMonticulo[i], end="  ")

		for j in range(espacio**2):
			print(" ",end="")

		if (i+1) % pow(2,k) == 0: # Realiza el salto de linea para bajar de nivel al arbol
			print("")
			k = k + 1
			espacio = espacio - 1
			for i in range((espacio-1)**2):
				print (" ",end="")

	print("")

### MENU ###

MonticuloBinario = MonticuloBinario()

print ("\t\tMenú de Opciones\n")

opc = 0

while opc != 6:

	print ("1. Construccion de un monticulo")
	print ("2. Insertar dato")
	print ("3. Eliminar el menor dato")
	print ("4. Incrementar una llave")
	print ("5. Decrementar una llave")
	print ("6. Salir\n")

	print ("Elige una opción: ",end="")
	opc = int(input())

	if opc == 1:
		lista = []
		n = int(input("Cuantos valores deseas agregar al arbol: "))
		for i in range(n):
			dato = int(input("Agregando valor "+str(i+1)+": "))
			lista.append(dato)
		MonticuloBinario.construirMonticulo(lista)
		print("")
		imprimir()
		print("")

	elif opc == 2:
		dato = int(input("Que dato desea insertar: ")) 
		MonticuloBinario.insertar(dato)
		print("")
		imprimir()
		print("")

	elif opc == 3:
		dato = MonticuloBinario.eliminarMin()
		print("")
		print("Se ha eliminado "+str(dato)+" del monticulo",end="\n\n")
		imprimir()
		print("")

	elif opc == 4:
		print("Que valor desea incrementar")

	elif opc == 5:
		print("Que valor desea decrementar")

	elif opc == 6:
		print("\t\tHasta pronto...")

	elif (opc <= 0) or (opc >= 7):
		print ("No ha insertado ninguna de las opciones\n")
