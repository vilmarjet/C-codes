

/**************************** (WordCounter.cpp) ****************************/

The (WordCounter.cpp) objective is to rank the most used words in a file. There is no headers. 
-Classes: We are using the Standard Containers "map" and "set". The "map" help us to store/find words, and "set" 
is used at the end to rank our words. Moreover we created a classe named as aWORD that store the information of 
each word (string and counter), this class is useful to rank our words. 
-Compilation: In linux, open a terminal on directory and type g++ WordCounter.cpp -o WordCounter
-Run: There are two ways of running this application: 
a) By command line arguments: "./WordCounter myFile.something topList" where "myFile" is the name of the file that you want to read, 
and "topList" is an integer number to the size of the top most used words to be printed on screen. 
b) Without command line arguments: "./WordCounter" This way, the application will ask you the "file" and "topList" during the execution.



/**************************** (GraphInfo.cpp) ****************************/

The (GraphInfo.cpp).  Given a graph G=(V,E) this program implements a helper class to perform the following:
a.  Given a node ID 	[0..N] print the node’s in and out degrees.
b.  Print the ID of the hub node (the node with maximum number of in + out degrees)
c.  Print the ID of the isolated nodes (the nodes with zero in and out degrees)
d.  Print the ID of the in-star-shaped nodes (the nodes with in degree N+1)
e.  Print the ID of the out-star-shaped nodes (the nodes with out degree N+1.
-Classes: We are using the Standard Containers "vector" to store graph nodes informantion. 
Moreover, we code two classes C_Node and C_Graph to store nodes information and to store nodes, respectively.  

-Compilation: In linux, open a terminal on directory and type g++ GraphInfo.cpp -o GraphInfo

-Run: For linux just type on terminal: ./GraphInfo
