#!/bin/bash
#SBATCH --partition=Centaurus
#SBATCH --job-name=prefix
#SBATCH --output=prefix-%j.out
#SBATCH --time=00:10:00

cd ~/4155/src

g++ -O0 prefixSum.cpp -o prefix

./prefix