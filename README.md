# Enzyme Kinetics Simulator

A C++-based simulation tool for studying enzyme kinetics under different inhibition conditions using Michaelis–Menten kinetics and Lineweaver–Burk analysis.

The simulator allows users to:
- simulate enzyme-substrate reactions by asking for requied inputs,
- compare inhibition mechanisms,
- generate CSV datasets,
- and automatically visualize kinetic behavior using Python-generated plots.

---

## Features

- Interactive terminal-based simulation
- Michaelis–Menten kinetics implementation
- Competitive inhibition simulation
- Noncompetitive inhibition simulation
- Combined comparison of all models
- Automatic CSV generation
- Automatic graph generation using Python
- Lineweaver–Burk plot generation
- User-defined kinetic parameters

---

## Technologies Used

- C++
- Python
- Matplotlib
- Pandas
- Git & GitHub

---

## Project Structure

enzyme-kinetics-simulator/

├── include/                  
├── src/                      

├── results/                  
├── plots/                    

├── plot_normal.py
├── plot_competitive.py
├── plot_noncompetitive.py
├── plot_combined.py

├── plot_lineweaver_normal.py
├── plot_lineweaver_competitive.py
├── plot_lineweaver_noncompetitive.py
├── plot_lineweaver_combined.py

├── README.md
├── .gitignore
└── LICENSE

---

## Models Implemented

### Michaelis–Menten Kinetics

v = (Vmax × [S]) / (Km + [S])

### Competitive Inhibition

v = (Vmax × [S]) / (Km(1 + [I]/Ki) + [S])

### Noncompetitive Inhibition

v = ((Vmax / (1 + [I]/Ki)) × [S]) / (Km + [S])

---

## How to Run

### Compile

```bash
g++ src/*.cpp -o simulator
```
---

## Author

Debopriya Das
Developed as a computational bioengineering and simulation project integrating biochemical kinetics with software engineering principles.
