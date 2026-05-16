import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Load experimental data

data = pd.read_csv("experimental_data.csv")

S = data["Substrate"]
V = data["Velocity"]

# Michaelis-Menten equation

def michaelis_menten(S, Vmax, Km):
    return (Vmax * S) / (Km + S)

# Fit parameters

params, covariance = curve_fit(
    michaelis_menten,
    S,
    V,
    bounds=(0, np.inf)
)

Vmax_fit, Km_fit = params

print(f"Estimated Vmax = {Vmax_fit:.4f}")
print(f"Estimated Km = {Km_fit:.4f}")

# Generate smooth curve

S_smooth = np.linspace(min(S), max(S), 200)
V_fit = michaelis_menten(S_smooth, Vmax_fit, Km_fit)

# Plot

plt.figure(figsize=(8,5))

plt.scatter(S, V, label="Experimental Data", s=40)

plt.plot(
    S_smooth,
    V_fit,
    linewidth=2,
    label="Fitted Michaelis-Menten Curve"
)

plt.xlabel("Substrate Concentration [S]")
plt.ylabel("Reaction Velocity V")

plt.title("Experimental Data Fitting")

plt.legend()

plt.tight_layout()

plt.savefig("plots/parameter_fit.png")

plt.show()

print("Parameter fitting graph generated.")