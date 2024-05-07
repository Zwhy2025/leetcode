import numpy as np
import matplotlib.pyplot as plt

# Defining the range for n
n = np.linspace(1, 10, 10)

# Defining the functions
o_n = n
o_logn_logn = np.log2(n) * np.log2(n)

# Creating the plot
plt.figure(figsize=(10, 6))
plt.plot(n, o_n, label="O(n)", color="blue")
plt.plot(n, o_logn_logn, label="O(logn * logn)", color="red")
plt.xlabel("n")
plt.ylabel("Operations")
plt.title("Comparison of O(n) and O(logn * logn)")
plt.legend()
plt.grid(True)
plt.show()
