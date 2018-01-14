# C-codes
This repository has some useful codes on c/c++. They were initialy coded on Linux.

In manner to help you to compile we created a Makefile. The instricution to compile each code follows:


Description of the work presented in this repository:
1) (WordCounter.cpp) 
  -Objective: 
    This application aims to rank the most used words in a file.
  -Headers:
    No headers used.
  -Classes:
    We are using the Standard Containers "map" and "set". The "map" help us to store/find words, and "set" is used at the end to rank our words. Moreover we created a classe named as aWORD that store the information of each word (string and counter), this class is useful to rank our words.
  -Compilation
    To compile on linux type: make WordCounter_make
  -Run
    There are two ways of running this application:
     a - By command line arguments:
        "./WordCounter myFile.something topList" 
        where "myFile" is the name of the file that you want to read, and "topList" is an integer number to the size of the top most used words to be printed on screen.
     b - Without command line:
        "./WordCounter"
        This way, the application will ask you the "file" and "topList" during the execution.
        
        
1) (JobShop_Heuristic) Is a directorty with a main file (JobShopGraspMain.cpp) and a header (head.h). 
    -Objective: This code aims to design a Grasp meta-heuristic to solve the Job shop scheduling problem. All function are in the file ".cpp" and declaration of function with used structs are in ".h". Moreover, a small intruduction of the problem and of the GRASP are in the  ".cpp". With the code a insert a instance "Example.txt" with 10 jobs and 5 machines.
    - Compilation: 
    Put ".h " and ".cpp" in same directory. 
    In linux just type in command line: g++ JobShopGraspMain.cpp -o JobShopGraspMain
    - Run:
    Set all files with Example.txt in same directory and execute "JobShopGraspMain"
    
    
      
  
  
     
