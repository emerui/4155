#!/bin/bash
#SBATCH --job-name=array_max
#SBATCH --partition=Centaurus
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --time=00:05:00
#SBATCH --output=data/part1_results.out

lscpu
./src/array_max