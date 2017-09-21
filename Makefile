#
# This Makefile can be used to automatically build the entire package.  
#
# If you make changes in the "Makefile" under any subdirectory, you can
# rebuild the system with "make clean" followed by "make all".
#
#
# Generic. On most systems, this should handle everything.
#
	

#
# Clean out all of the directories.
# 
clean:
	rm -f *.o
	rm -f WordCounter
	rm -f *~
	rm -f *.out



WordCounter_make:
	g++  WordCounter.cpp -o WordCounter



all:
	WordCounter_make
	






