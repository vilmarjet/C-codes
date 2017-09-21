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
    We are using the Standard Containers <map> and <set>. The <map> help us to store/find words, and <set> is used at the end to rank our words. 
  -Compilation
    To compile on linux type: make WordCounter_make
  -Run
    There are two ways of running this application:
     a - By command line arguments:
        "./WordCounter myFile.something topList" 
        where "myFile" is the name of the file that you want to read, and "topList" is an integer number that infor to our application the         number of size of the top most used words to be printed on screen.
     b - Without command line:
        "./WordCounter"
        This way, the application will ask you the "file" and "topList" during the execution.
  
  
     
