import numpy as np
import matplotlib.pyplot as plt

file='data.txt'
data=np.genfromtxt(file, delimiter=',')
data=data.T
#print(data[2])

spdat=data.copy()
spdat[2]=data[2,0]/data[2]
#print (spdat[2])

edat=spdat.copy()
edat[2]=spdat[2]/spdat[1]
#print(edat[2])

plt.figure(1)
plt.title('P vs $T_{P}$ at n=1E8')
plt.xlabel('P')
plt.ylabel('$T_{P}$')
plt.plot(data[1],data[2])
plt.xscale('log',basex=2)
plt.grid(True)
plt.savefig('Q1.png')

plt.figure(2)
plt.title('P vs  $S_{p}$ at n=1E8')
plt.xlabel('P')
plt.ylabel('$S_{p}$')
plt.plot(spdat[1],spdat[2])
plt.xscale('log',basex=2)
plt.grid(True)
plt.savefig('Q2.png')

plt.figure(3)
plt.title('P vs $E_{p}$ at n=1E8')
plt.xlabel('P')
plt.ylabel('$E_{p}$')
plt.plot(edat[1],edat[2])
plt.xscale('log',basex=2)
plt.grid(True)
plt.savefig('Q3.png')

