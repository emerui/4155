#!/bin/bash
#SBATCH --partition=centaurus
#SBATCH --job-name=prefix
#SBATCH --output=prefix-%j.out

cd ~/4155/src

g++ -O0 prefixSum.cpp -o prefix

./prefix