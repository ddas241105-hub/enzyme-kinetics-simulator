import pandas as pd
import matplotlib.pyplot as plt

normal = pd.read_csv("results/normal.csv")
competitive = pd.read_csv("results/competitive.csv")
noncompetitive = pd.read_csv("results/noncompetitive.csv")

normal_velocity = normal["Substrate"].diff().abs()
competitive_velocity = competitive["Substrate"].diff().abs()
noncompetitive_velocity = noncompetitive["Substrate"].diff().abs()

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

plt.xlabel("Substrate Concentration [S]")
plt.ylabel("Reaction Velocity V")

plt.title("Velocity vs Substrate Concentration")

plt.legend()

plt.savefig("plots/velocity_vs_substrate.png")

print("Velocity vs Substrate graph generated.")