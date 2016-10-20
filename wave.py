import numpy as np
import matplotlib.pyplot as plt
import sys

data = np.loadtxt(sys.argv[1])

plt.plot(data)
plt.savefig('wave.pdf', format='pdf')
