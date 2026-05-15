import pandas as pd
import matplotlib.pyplot as plt

normal = pd.read_csv("results/normal.csv")
competitive = pd.read_csv("results/competitive.csv")
noncompetitive = pd.read_csv("results/noncompetitive.csv")

plt.figure(figsize=(8,5))

plt.plot(normal["Time"], normal["Substrate"], label="Normal")
plt.plot(competitive["Time"], competitive["Substrate"], label="Competitive")
plt.plot(noncompetitive["Time"], noncompetitive["Substrate"], label="Noncompetitive")

plt.xlabel("Time")
plt.ylabel("Substrate Concentration")
plt.title("Enzyme Kinetics Simulation")

plt.legend()
plt.tight_layout()
plt.savefig("plots/combined_kinetics.png")
plt.show()

print("Graph generated successfully.")