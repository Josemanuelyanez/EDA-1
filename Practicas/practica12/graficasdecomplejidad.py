import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import random
from time import time

times=0
times1=0
times2=0


def insertionSort_graph(n_lista):
    global times
    for index in range(1, len(n_lista)):
        times+=1
        actual = n_lista[index]
        poscion = index
        while(poscion>0 and n_lista[poscion-1]>actual):
            times+=1
            n_lista[poscion]=n_lista[poscion-1]
            poscion=poscion-1
        n_lista[poscion]=actual
    return n_lista

TAM=101
eje_x = list(range(1, TAM, 1))
eje_y = []
lista_variable = []

for num in eje_x:
    lista_variable = random.sample(range(0,1000),num)
    print(lista_variable)
    times=0
    lista_variable = insertionSort_graph(lista_variable)
    eje_y.append(times)
    
print(lista_variable)

fig, ax=plt.subplots(facecolor='w', edgecolor='k')
ax.plot(eje_x, eje_y, marker="o", color="b", linestyle='None')

ax.set_xlabel("x")
ax.set_ylabel("y")
ax.grid(True)
ax.legend(["Insertion Sort"])

plt.title("Insertion sort")
plt.show()


def Quick_sort(lista):
    global times1
    times1+=1
    quicksort_aux(lista,0,len(lista)-1)

def quicksort_aux(lista,inicio, fin):
    global times1
    if inicio < fin:

        pivote = particion_time(lista,inicio,fin)

        times1+=1
        quicksort_aux(lista, inicio, pivote-1)
        times1+=1
        quicksort_aux(lista, pivote+1, fin)
	
def particion_time(lista, inicio, fin):
    pivote = lista[inicio]
    global times1
    izquierda = inicio+1
    derecha = fin
    bandera = False
    while not bandera:
        times1+=1
        while izquierda <= derecha and lista[izquierda] <= pivote:
            times1+=1
            izquierda = izquierda + 1
        while lista[derecha] >= pivote and derecha >=izquierda:
            times1+=1
            derecha = derecha -1
        if derecha < izquierda:
            bandera= True
        else:
            # swap places
            temp=lista[izquierda]
            lista[izquierda]=lista[derecha]
            lista[derecha]=temp
    # swap inicio with lista[derecha]
    temp=lista[inicio]
    lista[inicio]=lista[derecha]
    lista[derecha]=temp
    return derecha

TAM=101
eje_x1 = list(range(1, TAM, 1))
eje_y1 = []
lista1_variable = []

for num1 in eje_x1:
    lista1_variable = random.sample(range(0,1000),num1)
    print(lista1_variable)
    times1=0
    lista1_variable = Quick_sort(lista1_variable)
    eje_y1.append(times1)
    
print(lista1_variable)

fig, ax=plt.subplots(facecolor='w', edgecolor='k')
ax.plot(eje_x1, eje_y1, marker="o", color="b", linestyle='None')

ax.set_xlabel("x")
ax.set_ylabel("y")
ax.grid(True)
ax.legend(["Quick Sort"])

plt.title("Quick Sort")
plt.show()



def merge(arr, l, m, r):
    global times2
    n1 = m - l + 1
    n2 = r - m
 

    L = [0] * (n1)
    R = [0] * (n2)
 

    for i in range(0, n1):
        times2+=1
        L[i] = arr[l + i]
 
    for j in range(0, n2):
        times2+=1
        R[j] = arr[m + 1 + j]

    i = 0     
    j = 0     
    k = l
 
 
    while i < n1 and j < n2:
        times2+=1
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1
 

    while i < n1:
        times2+=1
        arr[k] = L[i]
        i += 1
        k += 1
 

    while j < n2:
        times2+=1
        arr[k] = R[j]
        j += 1
        k += 1
 
 
def Merge_Sort(lista):
    global times2
    times2+=1
    mergeSort(lista,0,len(lista)-1) 

def mergeSort(arr, l, r):
    global times2
    if l < r:
 
        m = l+(r-l)//2
 
        mergeSort(arr, l, m)
        global times2
        mergeSort(arr, m+1, r)
        global times2
        merge(arr, l, m, r)
        global times2


TAM=101
eje_x2 = list(range(1, TAM, 1))
eje_y2 = []
lista2_variable = []

for num2 in eje_x2:
    lista2_variable = random.sample(range(0,1000),num2)
    print(lista2_variable)
    times2=0
    lista2_variable = Merge_Sort(lista2_variable)
    eje_y2.append(times2)
    
print(lista2_variable)

fig, ax=plt.subplots(facecolor='w', edgecolor='k')
ax.plot(eje_x2, eje_y2, marker="o", color="b", linestyle='None')

ax.set_xlabel("x")
ax.set_ylabel("y")
ax.grid(True)
ax.legend(["Merge Sort"])

plt.title("Merge Sort")
plt.show()


#Tamaños de la lista de números aleatorios a generar
datos = [ii*100 for ii in range(1,21)] 

tiempo_is = []  #Lista para guardar el tiempo de ejecución de insert sort
tiempo_qs = []  #Lista para guardar el tiempo de ejecución de quick sort
tiempo_ms = []  #Lista para guardar el tiempo de ejecución de merge sort

for ii in datos:
    lista_is = random.sample(range(0, 10000000), ii)
    #Se hace una copia de la lista para que se ejecute el algoritmo con los mismo números
    lista_qs = lista_is.copy() 
    lista_ms = lista_is.copy() 

    t0 = time()  #Se guarda el tiempo inicial
    insertionSort_graph(lista_is)
    tiempo_is.append(round(time()-t0, 6))   #Se le resta al tiempo actual, el tiempo inicial
    
    t0 = time()    
    Quick_sort(lista_qs)
    tiempo_qs.append(round(time()-t0, 6))

    t0 = time()    
    Merge_Sort(lista_ms)
    tiempo_ms.append(round(time()-t0, 6))

#Imprimiendo tiempos parciales de ejecución
print("Tiempos parciales de ejecución en INSERT SORT {} [s] \n".format(tiempo_is))
print("Tiempos parciales de ejecución en QUICK SORT {} [s]".format(tiempo_qs))
print("Tiempos parciales de ejecución en MERGE SORT {} [s]".format(tiempo_ms))

#Imprimiendo tiempos totales de ejecución
#Para calcular el tiempo total se aplica la función sum() a las listas de tiempo
print("Tiempo total de ejecución en insert sort {} [s]".format(sum(tiempo_is)))
print("Tiempo total de ejecución en quick sort {} [s]".format(sum(tiempo_qs)))
print("Tiempo total de ejecución en merge sort {} [s]".format(sum(tiempo_ms)))


#Generando la gráfica
fig, ax = plt.subplots()
ax.plot(datos, tiempo_is, label="insert sort", marker="*",color="r")
ax.plot(datos, tiempo_qs, label="quick sort", marker="o",color="b")
ax.plot(datos, tiempo_ms, label="merge sort", marker="s",color="g")
ax.set_xlabel('Datos') 
ax.set_ylabel('Tiempo') 
ax.grid(True)
ax.legend(loc=2); 

plt.title('Tiempo de ejecución [s] (insert vs. quick vs merge)')
plt.show()