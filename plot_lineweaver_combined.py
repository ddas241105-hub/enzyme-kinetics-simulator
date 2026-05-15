import pandas as pd
import matplotlib.pyplot as plt

normal = pd.read_csv("results/normal.csv")
competitive = pd.read_csv("results/competitive.csv")
noncompetitive = pd.read_csv("results/noncompetitive.csv")

normal = normal[normal["Substrate"] > 0]
competitive = competitive[competitive["Substrate"] > 0]
noncompetitive = noncompetitive[noncompetitive["Substrate"] > 0]

normal_x = 1 / normal["Substrate"]
normal_y = 1 / (normal["Substrate"].diff().abs() + 1e-6)

competitive_x = 1 / competitive["Substrate"]
competitive_y = 1 / (competitive["Substrate"].diff().abs() + 1e-6)

noncompetitive_x = 1 / noncompetitive["Substrate"]
noncompetitive_y = 1 / (noncompetitive["Substrate"].diff().abs() + 1e-6)

plt.figure(figsize=(8,5))

plt.plot(normal_x[1:], normal_y[1:], label="Normal")
plt.plot(competitive_x[1:], competitive_y[1:], label="Competitive")
plt.plot(noncompetitive_x[1:], noncompetitive_y[1:], label="Noncompetitive")

plt.xlabel("1 / [S]")
plt.ylabel("1 / V")

plt.title("Combined Lineweaver-Burk Plot")

plt.legend()
plt.tight_layout()
plt.savefig("plots/lineweaver_combined.png")
plt.show()

print("Combined Lineweaver-Burk graph generated.")