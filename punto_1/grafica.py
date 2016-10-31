import matplotlib.pyplot as plt
import numpy as np

potential = np.loadtxt('potential.dat')
fieldx = np.loadtxt('fieldx.dat')
fieldy = np.loadtxt('fieldy.dat')

x = np.linspace(-2.5,2.5,250)
y = np.linspace(-2.5,2.5,250)

plt.imshow(potential,extent=[-2.5,2.5,-2.5,2.5])
plt.colorbar()
plt.streamplot(x,y,fieldx,fieldy)
plt.title('Electric potential and electric field in capacitor')
plt.savefig('placas.pdf',format = 'pdf')
