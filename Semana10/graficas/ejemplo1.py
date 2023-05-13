import matplotlib.pyplot as plt 
import numpy as np 

x = np.linspace(0,5,20)
print(x)

fig, ax = plt.subplots(facecolor = 'w', edgecolor= 'k')
ax.plot(x, np.sin(x), marker='o', color='r', linestyle='None')

ax.grid(True)
ax.set_xlabel('X')
ax.set_xlabel('Y')
ax.grid(True)
ax.legend("y= sen(x)")

plt.title ("Funciòn senoidal")
plt.show