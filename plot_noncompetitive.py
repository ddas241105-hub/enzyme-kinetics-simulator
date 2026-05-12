import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("results/noncompetitive.csv")

plt.figure(figsize=(8,5))

plt.plot(data["Time"], data["Substrate"])

plt.xlabel("Time")
plt.ylabel("Substrate Concentration")
plt.title("Noncompetitive Inhibition Kinetics")

plt.savefig("plots/noncompetitive_plot.png")

print("Noncompetitive graph generated.")