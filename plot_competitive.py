import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("results/competitive.csv")

plt.figure(figsize=(8,5))

plt.plot(data["Time"], data["Substrate"])

plt.xlabel("Time")
plt.ylabel("Substrate Concentration")
plt.title("Competitive Inhibition Kinetics")
plt.tight_layout()
plt.savefig("plots/competitive_plot.png")
plt.show()

print("Competitive graph generated.")