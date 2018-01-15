/* 
	This code will count the number of times that each word appear in a File, then it is going to rank by their numbers.
(Analyze the algorithmic complexity)

In the function Lire_Instance_map(char* namefile, map<string, int> &Storage) we are building our map.
Then, for each word in the file of "n" words we are calling the function Storage.find(word) to verify if a similar word was already detected. 
This function and  insert(pair) are logarithmic in size. Thus, we have nlog(n).

After, for each word on our map (Storage) we are ranking using the "set" container of c++. The set is again logarithmic in size. 

In conclusion, our method has complexity n*log(n) 
*/




#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string.h>	//string
#include <algorithm>



using namespace std;


int COUNTER = 0;

//This classe store the info of each word of the FILE
class aWORD{
    public:
        int qt;
        std::string word;
    aWORD(){};
    aWORD(const string &w, const int &_qt){qt =_qt; word = w;}
    void set(const string &w, const int &_qt){qt =_qt; word = w;}
    bool operator< (const aWORD& r) const { return (qt > r.qt);}
};

//funciton to read a file
// it is implemented after main function
void Lire_Instance_map(char* nomFichier, map<string, int> &Storage);


int main (int argc,char *argv[]) 
{
  //Declarations
  clock_t     start =clock(); // cpu time 
  int k;  
  set <aWORD> ranked;  //to rank wods
  map<string, int> Storage; // our map
  aWORD inst;
  map<string, int>::iterator it;
  set<aWORD>::iterator it3;
  
  
  //File to read !
    if (argv[1] != NULL )
    {
        Lire_Instance_map(argv[1], Storage); //Function to read
    }
    else
    {
        //ask user to type name of file;
        string stri = "";
        cout <<  "Please, inform file's name (after, type enter) \n"; cin >> stri;
        
        char* File = new char[stri.length() + 1];
        strcpy(File, stri.c_str());
        Lire_Instance_map(File, Storage); //Function to read
    }
    
   //top list
    if (argv[2] != NULL ) // it is a parameter
    {
        istringstream ss (argv[2]);
        ss >> k;
    }else 
    {
        //user should type
       cout <<  "Please, type the number words to appear on our top list\n"; 
        cin >> k;
    }
 
    
    //to fill the set ... to rank the words
    for (it=Storage.begin(); it != Storage.end(); ++it){
        inst.set(it->first,it->second );
        it3 = ranked.find(inst);
        ranked.insert(inst);
        
        if (it3 != ranked.end()){
            inst.set((*it3).word +  ", " + it->first,it->second );
            ranked.erase(it3);
            ranked.insert(inst);
        }   
    }
    
    
    //Printing final result
    cout << endl << endl << " The Original File has (" <<  COUNTER << ") words. \n";
    cout << endl << " ************************************\n";
    cout << " The TOP " << k << " words in file are: \n";
    cout << " ************************************\n";
    int count = 0;
    for (it3=ranked.begin(); (it3 != ranked.end()) && (count < k); ++it3){
        cout << count+1 << " --> " <<  (*it3).word<< " (" << (*it3).qt<<") times" << endl;
        count ++;
    }
    
    
    
    cout <<  endl << " CPU-Time to finish :" << (double) (clock()-start)/CLOCKS_PER_SEC <<" seconds";

    cin.get(); //just stop (type any thing to end)
    return 1;  //starndar end
}

inline bool issignal(const string &lastchar)
{
    if (lastchar.compare(",") == 0)
        return true ;
    
    if (lastchar.compare(".") == 0)
        return true ;
    
    if (lastchar.compare("!") == 0)
        return true ;
    
    if (lastchar.compare("?") == 0)
        return true ;
    
    return false;
}//end function issignal


//this function read the file and fill the map
void Lire_Instance_map(char* namefile, map<string, int> &Storage)
{
  map<string, int>::iterator it;
  
  string lastchar;
  ifstream file(namefile, ios::in);  // reading open
  string word;

  if(!file) //si le fichier n'est existe pas
    {
      cout<<"The file does not exist\n ";
      exit(1);
    }
    
    cout << "We are reading the file... please, be patient.\n ";
   while (!file.eof())
   {
       
       file >> word; 
       
       //Catch words with special characters like (, . ? ! )
       lastchar = word[(word.length()-1)];
       if ((word.length() > 1 ) && ( issignal(lastchar)))
       {
           word.erase(word.end() -1);
           
           it = Storage.find(lastchar);
           if (it == Storage.end())
               Storage.insert(pair<string, int>(lastchar, 1));
           else
               it->second = it->second +1;
           COUNTER++;
           
       }

           it = Storage.find(word);

           if (it == Storage.end())
               Storage.insert(pair<string, int>(word, 1));
           else
               it->second = it->second +1;
       
       
       COUNTER++;
   }//end of while
    
    
    /*
    for (it =Storage.begin(); it != Storage.end(); ++it)
        cout << it->first << it->second << endl;
    cin.get();
    */
     
}//end of Lire_Instance_map
