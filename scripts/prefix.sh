#!/bin/bash
#SBATCH --partition=Centaurus
#SBATCH --job-name=prefix
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --time=00:10:00

echo "===== O0 ====="
./src/prefixSum-O0

echo "===== O2 ====="
./src/prefixSum-O2

echo "===== O3 ====="
./src/prefixSum-O3
