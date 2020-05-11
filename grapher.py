import matplotlib.pyplot as plt
import numpy as np

plt.style.use('fivethirtyeight')

data = np.genfromtxt('results.csv', delimiter=',', names=['y', 'x1'])

n = data['y']
long_string = data['x1']

tc = n * 5.3

fig, ax = plt.subplots(figsize=(15,8))

ax.scatter(n, long_string, label="Long string")

plt.plot(n, tc, label="Trend (constant = n * 5.3", linewidth = 1)

plt.legend(loc="upper left")
ax.set_xlabel('n')
ax.set_ylabel('Runtime')
ax.set_title("Knuth-Morris-Pratt String Matching")

plt.savefig("results.png", dpi=96)

plt.show()