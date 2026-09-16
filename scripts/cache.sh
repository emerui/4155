#!/bin/bash

#SBATCH --partition=Centaurus
#SBATCH --job-name=cache_info
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --time=1:00:00

lscpu