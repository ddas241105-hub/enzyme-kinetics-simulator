import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("results/normal.csv")

data = data[data["Substrate"] > 0]

inverse_s = 1 / data["Substrate"]
inverse_v = 1 / (data["Substrate"].diff().abs() + 1e-6)

plt.figure(figsize=(8,5))

plt.plot(inverse_s[1:], inverse_v[1:])

plt.xlabel("1 / [S]")
plt.ylabel("1 / V")
plt.title("Lineweaver-Burk Plot (Normal)")

plt.savefig("plots/lineweaver_normal.png")

lineweaver = pd.DataFrame({
    "1/S": inverse_s[1:],
    "1/V": inverse_v[1:]
})

lineweaver.to_csv("results/lineweaver_normal.csv", index=False)

print("Lineweaver normal graph generated.")