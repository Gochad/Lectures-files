import random
from numpy import std, percentile, mean

oryginal_sample = [10, 20, 11, 23, 15, 17, 14]  
samples_len = 7 
samples_count = 100 

bootstrap_samples = [random.choices(oryginal_sample, k=samples_len) for _ in range(samples_count)]

bootstrap_std_devs = [std(sample) for sample in bootstrap_samples]

lower_quantile = percentile(bootstrap_std_devs, 5)
upper_quantile = percentile(bootstrap_std_devs, 95)

std_average = mean(bootstrap_std_devs)

print(f"Przybliżona wartość odchylenia standardowego: {std_average}")
print(f"90% przedział ufności dla odchylenia standardowego {(lower_quantile, upper_quantile)}")