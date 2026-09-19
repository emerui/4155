#!/bin/bash
#SBATCH --job-name=matrix_mult
#SBATCH --partition=Centaurus
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --time=00:45:00

lscpu
./src/matrixMult