# Enzyme Kinetics Simulator

A C++-based scientific simulation project for modeling enzyme kinetics under different biochemical conditions.
The simulator implements Michaelis–Menten kinetics and Lineweaver- Burk plot analysis, competitive inhibition, noncompetitive inhibition, temperature-dependent enzyme activity, enzyme denaturation effects, automated graph generation, and parameter fitting using Python visualization tools.

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
- Lineweaver–Burk plot generation
- Velocity vs substrate concentration analysis
- User-defined kinetic parameters
- Temperature-dependent enzyme activity
- Enzyme denaturation modeling
- Experimental noise simulation
- Sensitivity analysis
- Parameter fitting for Km and Vmax
- Python-based scientific visualization

---

## Technologies Used

### C++
- Object-Oriented Programming (OOP)
- Numerical simulation
- File handling
- Scientific computation
  
### Python
- pandas
- matplotlib
- scipy
- numpys
  
---

## Models Implemented

### Michaelis–Menten Kinetics

v = (Vmax × [S]) / (Km + [S])

### Competitive Inhibition

v = (Vmax × [S]) / (Km(1 + [I]/Ki) + [S])

### Noncompetitive Inhibition

v = ((Vmax / (1 + [I]/Ki)) × [S]) / (Km + [S])

### Temperature-Dependent Denaturation Model
	​
Vmax(T) = Vopt * exp(-((T - Topt)^2) / (2 * sigma^2))

---

## Project Structure

- `src/` → source files  
- `include/` → header files  
- `results/` → generated CSV datasets  
- `plots/` → generated graphs and visualizations  
- `experimental_data.csv` → sample experimental dataset

---

## How to Run

### Compile

```bash
g++ src/*.cpp -o simulator
```

### Run

./simulator

---

## Demo Video 

A quick walkthrough of the banking system:

https://drive.google.com/file/d/1ZgPSnRRaVodg9V0TSb0Ithe5Y8dfRnyV/view?usp=drive_link

---

## Author

Debopriya Das
