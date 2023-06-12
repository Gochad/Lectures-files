import numpy as np
from scipy.stats import chi2_contingency


X = np.random.binomial(20, 0.5, 50)
Y = np.random.binomial(10, 0.25, 50)

S = X + Y
Z = X - Y

observed = np.array([[sum((S == i) & (Z == j)) for j in np.unique(Z)] for i in np.unique(S)])

print(observed)
chi2, p_value, _, _ = chi2_contingency(observed)

print("Wyniki testu chi-kwadrat:")
print(f"Statystyka chi-kwadrat: {chi2}")
print(f"p-value: {p_value}")

if p_value > 0.01:
    print("nie odrzuca się hipotezy H0, że S i Z są niezależne")
else:
    print("odrzuca się hipotezę H0, że S i Z są niezależne")