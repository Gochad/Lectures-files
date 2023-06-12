import random
from scipy.stats import chi2

n = 1000

values = [random.uniform(0, 1) for _ in range(n)]

number_of_ranges = 100
ranges = [0] * number_of_ranges # 100 przedzialow: [0, 0.01) , [0.01, 0.02) , [0.02, 0.03) .....  [0.99, 1]
for value in values:
    ranges[int(value * number_of_ranges)] += 1
    
p = n / number_of_ranges # oczekujemy ze w kazdy przedzial wpadnie po rowno wartosci
chi = 0 # suma do testu
for i in range(0, number_of_ranges):
    chi += (ranges[i] - p) ** 2 / p

print(chi)

alfa = 0.001

quantile = chi2.ppf(1 - alfa, number_of_ranges - 1)
print(quantile)

if chi < quantile:
    print("nie ma podstaw do odrzucenia H0")
else:
    print("odrzucamy H0")

