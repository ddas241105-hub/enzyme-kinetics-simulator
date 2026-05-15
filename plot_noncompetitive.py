import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("results/noncompetitive.csv")

plt.figure(figsize=(8,5))

plt.plot(data["Time"], data["Substrate"])

plt.xlabel("Time")
plt.ylabel("Substrate Concentration")
plt.title("Noncompetitive Inhibition Kinetics")
plt.tight_layout()
plt.savefig("plots/noncompetitive_plot.png")
plt.show()
print("Noncompetitive graph generated.")