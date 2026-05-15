import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("results/normal.csv")

plt.figure(figsize=(8,5))

plt.plot(data["Time"], data["Substrate"])

plt.xlabel("Time")
plt.ylabel("Substrate Concentration")
plt.title("Normal Michaelis-Menten Kinetics")
plt.tight_layout()
plt.savefig("plots/normal_plot.png")
plt.show()
print("Normal graph generated.")