import matplotlib.pyplot as plt
import csv

n = []
rate = []
plt.xlabel('Matrix size (MxKxN)')
plt.ylabel('Rate (Operations/s)')
with open('../data/matrixMult.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'IJK'):
            n.append(row[1])
            rate.append(float(row[2]))
plt.plot(n, rate, color = 'g', linestyle = 'dotted', marker = 'o', label='IJK')

n = []
rate = []
with open('../data/matrixMult.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'IKJ'):
            n.append(row[1])
            rate.append(float(row[2]))
plt.plot(n, rate, color = 'r', linestyle = 'dotted', marker = 'o', label='IKJ')

n = []
rate = []
with open('../data/matrixMult.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'JIK'):
            n.append(row[1])
            rate.append(float(row[2]))
plt.plot(n, rate, color = 'b', linestyle = 'dotted', marker = 'o', label='JIK')

n = []
rate = []
with open('../data/matrixMult.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'JKI'):
            n.append(row[1])
            rate.append(float(row[2]))
plt.plot(n, rate, color = 'c', linestyle = 'dotted', marker = 'o', label='JKI')

n = []
rate = []
with open('../data/matrixMult.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'KIJ'):
            n.append(row[1])
            rate.append(float(row[2]))
plt.plot(n, rate, color = 'm', linestyle = 'dotted', marker = 'o', label='KIJ')

n = []
rate = []
with open('../data/matrixMult.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'KJI'):
            n.append(row[1])
            rate.append(float(row[2]))
plt.plot(n, rate, color = 'y', linestyle = 'dotted', marker = 'o', label='KJI')

plt.grid()
plt.legend()
plt.show()