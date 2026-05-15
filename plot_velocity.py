import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

normal = pd.read_csv("results/normal.csv")
competitive = pd.read_csv("results/competitive.csv")
noncompetitive = pd.read_csv("results/noncompetitive.csv")

normal_velocity = normal["Substrate"].diff().abs()
competitive_velocity = competitive["Substrate"].diff().abs()
noncompetitive_velocity = noncompetitive["Substrate"].diff().abs()

noise1 = np.random.normal(0, 0.01, len(normal_velocity))
noise2 = np.random.normal(0, 0.01, len(competitive_velocity))
noise3 = np.random.normal(0, 0.01, len(noncompetitive_velocity))

normal_velocity = normal_velocity + noise1
competitive_velocity = competitive_velocity + noise2
noncompetitive_velocity = noncompetitive_velocity + noise3

plt.figure(figsize=(8,5))

plt.plot(normal["Substrate"][1:], normal_velocity[1:], label="Normal")

plt.plot(
    competitive["Substrate"][1:],
    competitive_velocity[1:],
    label="Competitive"
)

plt.plot(
    noncompetitive["Substrate"][1:],
    noncompetitive_velocity[1:],
    label="Noncompetitive"
)

plt.scatter(
    normal["Substrate"][1:],
    normal_velocity[1:],
    s=12
)

plt.scatter(
    competitive["Substrate"][1:],
    competitive_velocity[1:],
    s=12
)

plt.scatter(
    noncompetitive["Substrate"][1:],
    noncompetitive_velocity[1:],
    s=12
)

plt.xlabel("Substrate Concentration [S]")
plt.ylabel("Reaction Velocity V")

plt.title("Velocity vs Substrate Concentration")

plt.legend()
plt.tight_layout()
plt.savefig("plots/velocity_vs_substrate.png")
plt.show()
print("Velocity vs Substrate graph generated.")