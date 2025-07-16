# Sandpile_cpp
Sandpile collapse simulation in C++

# Sandpile — Sandpile Collapse Simulation in C++

## Overview

This project implements a cellular automaton to simulate the collapse of sandpiles on a 2D grid. Inspired by self-organized criticality (SOC), the model illustrates how simple local rules lead to complex, fractal-like global behavior through toppling (avalanches).

---

## Features

- Customizable 2D grid dimensions and initial height
- Automatic toppling of unstable cells (height ≥ 4)
- Full stabilization of the grid
- ASCII visualization of the current configuration
- Random grain addition with automatic stabilization
- Tracking of total topplings
- Overloaded `+` operator to combine configurations

---

## Project Structure

Sandpile_Cpp/

├── include/

│ └── sandpile.hpp # Sandpile class declaration

├── src/

│ └── sandpile.cpp # Method implementations

├── test/

│ └── test_sandpile.cpp # Example usage and output

├── README.md 

├── .gitignore 

