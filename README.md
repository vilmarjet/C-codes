# C-codes
This repository has some useful codes on c/c++. They were initialy coded on Linux.

In manner to help you to compile we created a Makefile. The instricution to compile each code follows:


Description of the work presented in this repository:
1) (SimplePrograms): Set of small and simple programs in C that can be used to learn some properties of this beautiful language. This directory contains the programs:
    
      - Word Counter: Counts the number of times that each word is used in a file
      
      - Graph info: Print some useful informations of a directed graph G = (V,E).
      
2) (Simulations) Is a directorty with three simulation problems:

    - S_BankAtt: Simulates a cashier attendence with limite on total time and queue size. 
  
    - S_MachineParalle: is a VC++ code and  simulates a Treatment of some piece in a manufacture with 2 machines in parallel and 1 to assembler. 
  
    - SimulationRobot: is a VC++ code and simulates an automatic production line. 
        
        
3) (JobShop_Heuristic) Is a directorty with a main file (JobShopGraspMain.cpp) and a header (head.h). 

    - Objective: This code aims to design a Grasp meta-heuristic to solve the Job shop scheduling problem. All functions are in the file ".cpp" and declaration of function with used structs are in ".h". Moreover, a small intro of the problem and of the GRASP are in the  ".cpp". An example instance "Example.txt" with 10 jobs and 5 machines follows the codes.
    
    - Compilation: 
    Put ".h " and ".cpp" in same directory. 
    In linux just type in command line: g++ JobShopGraspMain.cpp -o JobShopGraspMain.
    
    - Run:
    Set all files with Example.txt in same directory and execute "JobShopGraspMain".

4) (VRP) is a VC++ code of a Genetic algorithm to find feasible solution for the Vehicle Routing Problem with Time Windows - VRPTW. 
This file contains all the source codes and Documentation in french. It is a join work with Julia Couto in 2012. In Directory TP3 you find the main.cpp (There is no main() but is them most important file) that contains the implementation of all functions. In "head.h" the functions are declared and the structs are developed.     

    



      
  
  
     
