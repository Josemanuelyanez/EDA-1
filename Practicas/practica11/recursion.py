#Funcion conversion
def Conversion(numero):
    if numero == 0:
        return ""
    else:
        return Conversion(numero//2) + str(numero % 2) 
    
        
    
#Funcion invertir
def invertir(dic,numero):
    for x in range (numero,0,-1):
        memoria2[x] = dic.get(x)



#Funcion Fibonacci
def Fibonacci(numero):
    if numero in memoria:
        return memoria[numero]
    memoria[numero] = Fibonacci(numero-1) + Fibonacci(numero-2)
    return memoria[numero]


#Funcion imprimir
def imprimir(dic,numero):
    print(f"\nEntrada : {numero} \nSalida  : {' '.join(str(x) for x in dic.values())}")




#principal
while True:
    
    memoria= {1:0, 2:1, 3:1}
    memoria2={}


    opcion=int(input("""
    \t\tBienvenido , puede realizar las siguientes operaciones :
    1 Conversion de bases
    2 Serie de Fibonacci
    3 Salir
    
    Ingrese la opcion: """))
    if opcion == 1:
        numero=int(input("\nIngrese el numero: "))
        Conversion(numero)
        print(f"Entrada : {numero}\nSalida : {Conversion(numero)}")

    elif opcion == 2:
        numero=int(input("\nIngrese el numero: "))
        Fibonacci(numero)
        invertir(memoria,numero)
        imprimir(memoria2,numero)

        
    elif opcion == 3:
        break
    else:
        print("\n\tOpción inválida")