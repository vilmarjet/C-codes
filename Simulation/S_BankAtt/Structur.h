
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


#define Taille 10 // max lenght of queue inside store -- TEM QUE ARRUMAR O STRUCT DA FILA (T_FILE)
#define MAX  2000 // Total time to be 
#define T_ArriveCliente 3 //Freq of clients 
#define T_Traitement 4 // traitement time = atendimentob (tempo de atendimento)

typedef struct T_Client Client;
struct T_Client
{
    int numero;		//Client number
    int T_Arri_Syst;	//Arrival to system 	
    int T_Arri_Serveur; // data que client est arrive dans server
    Client* prox; // e necessario para entrar na Fila_2 fila fora do estabelecimento e no sortir
};

//It is the queue
typedef struct T_File
{
    int debut;		//begin of queue 
    int fin;		//end of queue 
    Client InfClient[Taille+1]; // Arrumar uma maneira de delarar taille lah em cima e dar certo

}File;

/*Structur for server*/
typedef struct T_Serveur 
{
    Client Atendendo;	//
    int ocupado; // se 1 est occupe, se 0 nao;
    int TempOccupe;
}Serveur;

//exit 
typedef struct T_Sorti 
{
    int fin; // Define exit of clints
    Client* primeiro; // First Client to exit
    Client* ultimo;
}Sorti;

typedef struct Fila_2 // FILA FORA DO BANCO
{
    int fin; // Definir quantidade de clientes na fila externa
    Client* primeiro; // Apontar para primeiro cliente
    Client* ultimo;

}FileExt;

/*************************************Beging of FUNCTIONS ***************/

/****** Functions de inicialization ************/
void Inicialize_Client (Client& C)
{
    C.numero = 0;
    C.T_Arri_Syst = 0;
    C.T_Arri_Serveur = 0; // data que client est arrive dans server
    C.prox = NULL;
}

void Inicialize_File (File& Une_File)
{
    Une_File.debut = 0;
    Une_File.fin = 0;
    for (int w = 0; w <= (Taille); w++)
        Inicialize_Client(Une_File.InfClient[w]);
}

void Inicialize_File2 (FileExt& Une_File)
{
    Une_File.fin = 0;
    Une_File.primeiro = NULL;
}

void Inicialize_Serveur(Serveur& serve)
{
    serve.ocupado = 0; // se 1 est occupe, se 0 nao;
    serve.TempOccupe = 0;
}

void Inicialize_Sortie(Sorti & saida)
{
    saida.fin = 0;
    saida.primeiro = NULL;
}

/*********** FUNCTION DE TEST *****************/

int teste_File_Pleine  (File & Une_File)
{
    if (Une_File.fin == Taille)
        return 1;
    else
        return 0;
}

/*************** IL FAUT ANALISER SI CETTE FUNCTION EH NECESSER - FUNCTION POUR FILE EXTERNA *****/
void AjouterFileExt(FileExt& Une_File, Client& cli)
{
    if (Une_File.fin == 0)
    {
        Une_File.primeiro = &cli;
        Une_File.ultimo = &cli;
        Une_File.fin ++;
    }
    else
    {
        Une_File.ultimo->prox = &cli;
        Une_File.ultimo = &cli;
        Une_File.fin ++;
    }
}


/**************FUNCTION POUR AJOUTER CLIENT EN FILE *************/
void Ajouter (File& Une_File, FileExt& d_file, Client& cli)
{
    if (teste_File_Pleine (Une_File) == 0) // Se fila esta cheia o valor serah 1
    {
        Une_File.fin ++;
        Une_File.InfClient[Une_File.fin] = cli; // analisar
    }
    else
        AjouterFileExt(d_file, cli);
}
/******************* mettre client apres traitement en la estrutur sortir ************/
void Sortie (Sorti& Saida, Client Clientela)
{
   Client* atendendo;                              // criar novo endereco
    atendendo = (Client*) malloc(sizeof(Client)); /******** criacao de um novo endereco a cada vez que eh chamado*******/
   *atendendo = Clientela;

   if (Saida.fin == 0)
   {
       Saida.primeiro = atendendo;
       Saida.ultimo = atendendo;
       Saida.fin ++;
   }
   else
   {
       Saida.ultimo->prox = atendendo;
       Saida.ultimo = atendendo;
       Saida.fin ++;
   }

}

/******************* mettre client au traitement en la estrutur serveur ************/
void EntrarEmServisse (File& Une_File, Serveur & serve , int t, Sorti& saida) // int t = tempo da funcao main
{
    if (serve.TempOccupe <= 0)
    {
        serve.ocupado = 0;
        serve.TempOccupe = 0;
    }

    else
        serve.ocupado = 1;

    if (serve.ocupado == 0)
    {
        Client Atendido;
        serve.Atendendo = Une_File.InfClient[1];
        serve.TempOccupe = T_Traitement;
        serve.Atendendo.T_Arri_Serveur = t;
        Atendido = serve.Atendendo;
        serve.ocupado = 1;
        Sortie (saida, Atendido);

        if (Une_File.fin > 1)
        {
            for (int w =1; w < Une_File.fin; w++)
                Une_File.InfClient[w] = Une_File.InfClient[w+1];
            Une_File.fin--;
            serve.ocupado = 1;
        }
        else
        {
            Inicialize_File(Une_File);
        }

    }

}

;

