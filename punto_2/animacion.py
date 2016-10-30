import numpy as np
import matplotlib.pyplot as plt
import sys
import os

for i in range(0,352):
    data = np.loadtxt("cuerda%05d.dat" %(i));
    plt.plot(data[:,0],data[:,1])
    plt.ylim([0,1])
    plt.xlabel('x')
    plt.ylabel('Amplitude')
    plt.savefig('cuerda%05d.png' %(i), format='png')
    plt.close()


os.system('convert -delay 1 -loop 0 *png cuerda.gif')
os.system('rm *png *dat')
