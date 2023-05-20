def MostrarBiblioteca(catalogo):
    if catalogo:
        print("Los libros que están en la biblioteca son:")
        for libro in catalogo.keys():
            print(libro)
    else:
        print("La biblioteca está vacía")

def Alfabeticamente(catalogo):
    libros = list(catalogo.keys())
    n = len(libros)
    for i in range(n-1):
        for j in range(0, n-i-1):
            if libros[j] > libros[j+1]:
                libros[j], libros[j+1] = libros[j+1], libros[j]
    nuevo_catalogo = {}
    for libro in libros:
        nuevo_catalogo[libro] = catalogo[libro]
    print("\n\tYa ordenados alfabéticamente")
    MostrarBiblioteca(nuevo_catalogo)

def eliminar(catalogo):
    if catalogo:
        MostrarBiblioteca(catalogo)
        eliminacion = input("Ingrese el libro que desea eliminar: ")
        if eliminacion in catalogo:
            del catalogo[eliminacion]
            print(f"\n\tEl libro {eliminacion} ha sido eliminado con éxito\n ")
            MostrarBiblioteca(catalogo)
        else:
            print(f"El libro {eliminacion} no se encuentra en la biblioteca")
    else:
        print("La biblioteca está vacía")

def AgregarLib(catalogo):
    libro = input("Ingrese el título del libro: ")
    catalogo[libro] = None

catalogo = {}

while True:
    opcion = int(input("""
    \t\tBienvenido a la biblioteca, puede realizar las siguientes operaciones:
    1 Agregar libro
    2 Eliminar libro
    3 Ordenar alfabeticamente la biblioteca
    4 Ver biblioteca
    5 Salir

    Ingrese la opción: """))

    if opcion == 1:
        AgregarLib(catalogo)
    elif opcion == 2:
        eliminar(catalogo)
    elif opcion == 3:
        Alfabeticamente(catalogo)
    elif opcion == 4:
        MostrarBiblioteca(catalogo)
    elif opcion == 5:
        break
    else:
        print("Opción inválida")
