# Description

This repository contains all the files used for running the Step 1.1 and Step 2.1 of the CNRS Benchmark described in Section III.B of [1]. The general description of the benchmark is given in [2].

This repository is divided into three folders. The *Nuclear_data* directory contains the neutronic input data of the problem and files to process this data for the computation of the problem. The *1.1* (resp. *2.1*) directory contains the files for running the Step 1.1 (resp. Step 2.1). Both also have a *data* folder which contains the outputs of the simulations.

## Nuclear data

The neutronic parameters (neutron flux, mean neutron generation time, delayed fractions and decay constants for the DNP groups) are provided in the files *kinetic_data.txt* and *Powershape.csv*. They are identical to those used in [3].

## Step 1.1 


## Step 2.1 

# References

[1] P. Pfahl, A. Chambon, J. Groth-Jensen, and B. Lauritzen. 2026. “Squirrel: A MOOSE-Based App for Solving Point Kinetics in Molten Salt Reactors.” Nuclear Science and Engineering 200 (sup1): S39–51. [doi:10.1080/00295639.2025.2494182.
](https://doi.org/10.1080/00295639.2025.2494182)

[2] Marco Tiberga, Rodrigo Gonzalez Gonzaga de Oliveira, Eric Cervi, Juan Antonio Blanco, Stefano Lorenzi, Manuele Aufiero, Danny Lathouwers, Pablo Rubiolo,
Results from a multi-physics numerical benchmark for codes dedicated to molten salt fast reactors,
Annals of Nuclear Energy,
Volume 142,
2020,
107428,
ISSN 0306-4549,
https://doi.org/10.1016/j.anucene.2020.107428.

[3] J. Groth-Jensen, A. Nalbandyan, E.B. Klinkby, B. Lauritzen, P. Sabbagh, A.V. Pedersen,
Verification of multiphysics coupling techniques for modeling of molten salt reactors,
Annals of Nuclear Energy,
Volume 164,
2021,
108578,
ISSN 0306-4549,
https://doi.org/10.1016/j.anucene.2021.108578.
