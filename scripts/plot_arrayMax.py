import matplotlib.pyplot as plt
import csv

n = []
rate = []
plt.xlabel('N size')
plt.ylabel('Rate (bytes/s)')
with open('../data/arrayMax.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'random' and row[1] == 'int' and row[2] == 'A'):
            n.append(int(row[3]))
            rate.append(float(row[4]))
plt.scatter(n, rate, color = 'g', label='int A')
n=[]
rate=[]
with open('../data/arrayMax.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'random' and row[1] == 'int' and row[2] == 'B'):
            n.append(int(row[3]))
            rate.append(float(row[4]))
plt.scatter(n, rate, color = 'b',  label='int B')
n=[]
rate=[]
with open('../data/arrayMax.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'random' and row[1] == 'double' and row[2] == 'A'):
            n.append(int(row[3]))
            rate.append(float(row[4]))
plt.scatter(n, rate, color = 'r',  label='double A')
n=[]
rate=[]
with open('../data/arrayMax.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'random' and row[1] == 'double' and row[2] == 'B'):
            n.append(int(row[3]))
            rate.append(float(row[4]))
plt.scatter(n,rate,color='y',  label='double B')
plt.legend()


plt.title('Random sort rate against n.', fontsize = 20)
plt.xscale('log')
plt.show()

##increasing
plt.figure()
n = []
rate = []
plt.xlabel('N size')
plt.ylabel('Rate (bytes/s)')
with open('../data/arrayMax.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'increasing' and row[1] == 'int' and row[2] == 'A'):
            n.append(int(row[3]))
            rate.append(float(row[4]))
plt.scatter(n, rate, color = 'g', label='int A')
n=[]
rate=[]
with open('../data/arrayMax.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'increasing' and row[1] == 'int' and row[2] == 'B'):
            n.append(int(row[3]))
            rate.append(float(row[4]))
plt.scatter(n, rate, color = 'b',  label='int B')
n=[]
rate=[]
with open('../data/arrayMax.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'increasing' and row[1] == 'double' and row[2] == 'A'):
            n.append(int(row[3]))
            rate.append(float(row[4]))
plt.scatter(n, rate, color = 'r',  label='double A')
n=[]
rate=[]
with open('../data/arrayMax.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'increasing' and row[1] == 'double' and row[2] == 'B'):
            n.append(int(row[3]))
            rate.append(float(row[4]))
plt.scatter(n,rate,color='y',  label='double B')

plt.legend()
plt.title('Increasing sort rate against n.', fontsize = 20)
plt.xscale('log')
plt.show()

###reverse
plt.figure()

n = []
rate = []
plt.xlabel('N size')
plt.ylabel('Rate (bytes/s)')
with open('../data/arrayMax.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'reverse' and row[1] == 'int' and row[2] == 'A'):
            n.append(int(row[3]))
            rate.append(float(row[4]))
plt.scatter(n, rate, color = 'g', label='int A')
n=[]
rate=[]
with open('../data/arrayMax.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'reverse' and row[1] == 'int' and row[2] == 'B'):
            n.append(int(row[3]))
            rate.append(float(row[4]))
plt.scatter(n, rate, color = 'b',  label='int B')
n=[]
rate=[]
with open('../data/arrayMax.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'reverse' and row[1] == 'double' and row[2] == 'A'):
            n.append(int(row[3]))
            rate.append(float(row[4]))
plt.scatter(n, rate, color = 'r',  label='double A')
n=[]
rate=[]
with open('../data/arrayMax.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'reverse' and row[1] == 'double' and row[2] == 'B'):
            n.append(int(row[3]))
            rate.append(float(row[4]))
plt.scatter(n,rate,color='y',  label='double B')


plt.legend()
plt.title('Reverse sort rate against n.', fontsize = 20)
plt.xscale('log')
plt.show()

##bandwidth
n = []
bandwidth = []
plt.xlabel('Array size bytes')
plt.ylabel('Bandwidth (bytes/s)')
with open('../data/arrayMax.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        if (row[0] == 'bandwidth' and row[1] == 'double' and row[2] == 'B'):
            n.append(int(row[3]) * 8)
            bandwidth.append(float(row[4]))
plt.scatter(n, bandwidth, color = 'g')
plt.title('Bandwidth against array size n.', fontsize = 20)
plt.xscale('log')
plt.show()



