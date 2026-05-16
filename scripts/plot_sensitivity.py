import pandas as pd
import matplotlib.pyplot as plt

normal = pd.read_csv("results/normal.csv")
competitive = pd.read_csv("results/competitive.csv")
noncompetitive = pd.read_csv("results/noncompetitive.csv")

plt.figure(figsize=(8,5))

plt.plot(
    normal["Time"],
    normal["Substrate"],
    linewidth=2,
    label="Normal"
)

plt.plot(
    competitive["Time"],
    competitive["Substrate"],
    linewidth=2,
    label="Competitive"
)

plt.plot(
    noncompetitive["Time"],
    noncompetitive["Substrate"],
    linewidth=2,
    label="Noncompetitive"
)

plt.xlabel("Time")
plt.ylabel("Substrate Concentration")

plt.title("Sensitivity Analysis of Enzyme Inhibition")

plt.legend()

plt.tight_layout()

plt.savefig("plots/sensitivity_analysis.png")

plt.show()

print("Sensitivity analysis graph generated.")