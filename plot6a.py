import numpy as np
import matplotlib.pyplot as plt

file1='6adatap64.txt'
data1=np.genfromtxt(file1, delimiter=',')
data1=data1.T
#print(data[2])

file2='6adatap1.txt'
data2=np.genfromtxt(file2, delimiter=',')
data2=data2.T

data3=data1.copy()
data3[1]=data2[1]/data3[1]

data4=data3.copy()
data4[1]=data4[1]/64
#print(data2[1], data1[1], data3[1])

plt.figure(1)
plt.title('$S_{p}$ vs n at P=64')
plt.xlabel('n')
plt.ylabel('$S_{p}$')
plt.loglog(data3[0],data3[1])
plt.grid(True)
plt.savefig('Q6a.png')

plt.figure(2)
plt.title('$E_{p}$ vs n at P=64')
plt.xlabel('n')
plt.ylabel('$E_{p}$')
plt.loglog(data4[0],data4[1])
plt.grid(True)
plt.savefig('Q6a-efficiency.png')
