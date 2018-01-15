/****

 This program Performes:

You are given a graph G=(V,E), wherein:
a.  V is the set of nodes 
b.  Eis the set of edges 
i.  There are no loops,
ii.  Edges are directed,

Implement a helper class to perform the following:
a.  Given a node ID 	[0..N] print the node’s in and out degrees.
b.  Print the ID of the hub node (the node with maximum number of in + out degrees)
c.  Print the ID of the isolated nodes (the nodes with zero in and out degrees)
d.  Print the ID of the in-star-shaped nodes (the nodes with in degree N+1)
e.  Print the ID of the out-star-shaped nodes (the nodes with out degree N+1


*/




#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string.h>	//string
#include <algorithm>



using namespace std;


int COUNTER = 0;
class C_Node{
    public:
        int ID,
	    in_size,
	    out_size;
	
	
    C_Node(){in_size = 0; out_size = 0;}
    C_Node(int id){ID = id; in_size = 0; out_size = 0;}
    void Set_in_node(){in_size ++;} 
    void Set_out_node(){out_size ++;}
};


//The class C_graph will store the graph infromation and will performe the print
class C_Graph{
    public:
        int Size;
        std::vector<C_Node> Nodes;

    C_Graph(){Nodes.clear();}
    C_Graph(const int &n){Nodes.resize(n);}
    void Set_N(const int &n){Nodes.resize(n);}
    void Set_a_node(const int &in, const int &out){Nodes[in].Set_out_node(); Nodes[out].Set_in_node();}
    
    //Answer of the question 
      // Question a)
      void Print_in_out_degree(const int &id); // print in nodes 
      // Question b)
      void Print_hub(); // print in nodes 
      // Question c)
      void Print_isolated(); // print in nodes 
      
      // Question d)
      void Print_in_start_shaped(); // print in nodes 
      
      void Print_out_start_shaped(); // print in nodes 
   
};


//This function print in and out degree of node id 
void C_Graph::Print_in_out_degree(const int &id)
{
  cout << "Printing info of node (" << id << "): "<< endl;
  cout << "IN degre " << Nodes[id].in_size;
  cout << "OUT degre " << Nodes[id].out_size;
}



//This function print hub
void C_Graph::Print_hub()
{
  int totalDegree, max_d = 0, max_id = -1;;
 
  for (unsigned i=0; i<Nodes.size(); i++)
  {
    totalDegree = Nodes[i].in_size + Nodes[i].out_size;// total degree of node
    
    if (max_d <= totalDegree){
      max_id = i;
      max_d   = totalDegree;
    }
      
  }
  cout << "An hub node is (" << max_id << "): "<< endl;
  cout << "With total number of in + out = " << max_d;
}






//This function print Print_isolated nodes 
void C_Graph::Print_isolated()
{
  int totalDegree;
 
  
  cout << "Printing all the isolated nodes  = [";
  for (unsigned i=0; i<Nodes.size(); i++)
  {
    totalDegree = Nodes[i].in_size + Nodes[i].out_size;// total degree of node
    
    if (totalDegree == 0){
      cout << i << ",";
    }
      
  }
  cout << "]. "<< endl;
}



//This function print Print_in_start_shaped nodes 
void C_Graph::Print_in_start_shaped()
{
  int totalDegree;
 
  
  cout << "Printing all in-start-shaped nodes  = [";
  for (unsigned i=0; i<Nodes.size(); i++)
  {
    totalDegree = Nodes[i].in_size;// total degree of node
    
    if (totalDegree == Nodes.size() -1){
      cout << i << ",";
    }
      
  }
  cout << "]. "<< endl;
}


//This function print Print_out_start_shaped nodes 
void C_Graph::Print_out_start_shaped()
{
  int totalDegree;
 
  
  cout << "Printing all in-start-shaped nodes  = [";
  for (unsigned i=0; i<Nodes.size(); i++)
  {
    totalDegree = Nodes[i].out_size;// total degree of node
    
    if (totalDegree == Nodes.size() -1){
      cout << i << ",";
    }
      
  }
  cout << "]. "<< endl;
}


void Read_Graph(char* namefile, C_Graph &Graph);


//Main function
int main (int argc,char *argv[]) 
{
    clock_t     start =clock(); // start time
    C_Graph Graph;
    
    
    
    if (argv[1] != NULL )
    {
        Read_Graph(argv[1], Graph); //Function to read
    }
    else
    {
        //ask user to type name of file;
        string stri = "";
        cout <<  "Please, inform file's name (after, type enter) \n"; cin >> stri;
        
        char* File = new char[stri.length() + 1];
        strcpy(File, stri.c_str());
        Read_Graph(File, Graph); //Function to read
    }
    
    
    // Question a)
      int a_id =  1;
      Graph.Print_in_out_degree(a_id); // print in nodes 
      // Question b)
      Graph.Print_hub(); // print in nodes 
      // Question c)
      Graph.Print_isolated(); // print in nodes 
      
      // Question d)
      Graph.Print_in_start_shaped(); // print in nodes 
      
      // Question e)
      Graph.Print_out_start_shaped(); // print in nodes 
   
    
    
    cout <<  endl << " CPU-Time to finish :" << (double) (clock()-start)/CLOCKS_PER_SEC <<" seconds";

    cin.get();
    return 1;
}

//The file must infrome at first the dimention (N)
//The next function is implemented to read a file that contain the info the Graph
void Read_Graph(char* namefile, C_Graph &Graph)
{
  map<string, int>::iterator it;
  int Dim, in, out;
  
  string lastchar;
  ifstream file(namefile, ios::in);  // reading open
  string word;

  if(!file) //si le fichier n'est existe pas
    {
      cout<<"The file does not exist\n ";
      exit(1);
    }
    
    file >> Dim; 
  Graph.Set_N(Dim);
    
    cout << "We are reading the file... please, be patient.\n ";
   while (!file.eof())
   { 
       file >> in; 
       file >> out; 
       Graph.Set_a_node(in, out);
 
   }//end of while
    
}//end of Lire_Instance_map


/*
 * 
 * 
 * 	The algorighm: 1) Read the graph and increase the degree of each node when it appears 
 * 		       2) The nodes of the graph are stored on vector, thus it easy to get the information needed of each time.
 *	 
 * 
 * 	Firtly, it stores the graph information (V, E ) on a class that is called C_Graph that uses the classe C_Node.
 * 	 The classe C_Node stores the degree in and out separately on constant complexity time;
 * 	To answer the questions b) to e) it searchs on all the nodes of the graph that are stores in stl vector. 
 * 	Thus, for each one one of the 5 questoins the complexity is O(n).
 *
 * 
 *	 
 * 
 * 
 * */

