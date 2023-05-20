def recur_fibo (n):
    if n <= 1:
        return 
    else:
        return (recur_fibo(n-1)+ recur_fibo(n-2))

nterms = 13

if nterms <= 0:
    print("Ingrese un entero positivo")
else:
    print("secuencia fibonacci:")
    for i in range(nterms):
        print(recur_fibo(i))
