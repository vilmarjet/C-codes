#include "Structur.h"

/**
This file has the main function of the program.
This program simulate a bank or store attendance with ONE cashier
 - See structu.h to definitions of time of arrival, attendence and maximal size of queue -

This program shows the number of clients served , and the number of lost.
Moreover, we show the average waitting time in queue.

This program was created by Vilmar in 2012 as part of a task to Simulation cours at ISIMA
*/

int main ()
{
// DECLARACOES
    File Fila;
    FileExt FilaExterna;
    Client Cli;
    Serveur Serv;
    Sorti Sai;
    int temp = 0;
    int desistiu = 0;
    int teste = 0;

// INICIALIZACOES - Client sera inicialized inside "while"
    Inicialize_File (Fila);
    Inicialize_File2 (FilaExterna);
    Inicialize_Serveur (Serv);
    Inicialize_Sortie(Sai);


    cout << "Data of problem:";
    cout << endl <<  "Maximum size of queue = " << Taille;
    cout << endl <<  "Maximum time of operation= " << MAX << " (s)" ;
    cout << endl <<  "Frequency of client's arrival= " << T_ArriveCliente << " (s)"  ;
    cout << endl <<  "Frequency of attendance = " << T_Traitement  << " (s)"  ;
    cout << endl  << endl ;


    while ( temp <= MAX)
    {
        if (teste_File_Pleine(Fila) == 0) // Test if queue is full
        {
            if ((temp % T_ArriveCliente) == 0)
            {
                Inicialize_Client (Cli);
                Cli.numero = (temp/T_ArriveCliente + 1);
                Cli.T_Arri_Syst = temp;
                        // ajouter client
                Ajouter (Fila, FilaExterna, Cli);
                //EntrarEmServisse (Fila,Serv , temp, Sai);
            }
        }
        else if ((temp % T_ArriveCliente) == 0)
                desistiu++;         //lost client

    if (Serv.TempOccupe != 0)
    {
      Serv.TempOccupe--; // retirar menos um tempo de atendimento do serveur
    }

    if ((Fila.fin > 0))
        EntrarEmServisse (Fila,Serv , temp, Sai);


        temp++;

    } // end while

    temp --;
    //cout << "Elapsed time" << temp <<endl;


    cout << endl << "****Printing Results******* " << endl;

    cout << "Lost clients : "<< desistiu ;


// FAIRE ANALISE AVEC SORTIE.
    cout << endl << "Number of served clients:" << Sai.fin ;
    Client* pont;
    pont = Sai.primeiro;
/*
    for (int i = 0; i < Sai.fin; i++)
    {
        cout << pont->numero << "-" << pont->T_Arri_Syst << " " << (pont->T_Arri_Serveur + T_Traitement);
        cout << endl;
        pont = pont->prox;
    }
*/
    teste = Sai.fin;
    //cout << endl << "To print Average waitting time in queue:"<< endl;
    int med = 0;
    pont = Sai.primeiro;
    for (int i = 0; i < Sai.fin; i++)
    {
        med =  med + (pont->T_Arri_Serveur - pont->T_Arri_Syst);
        pont = pont->prox;
    }
    teste = med;
    float avg;
    avg = (float (med)/Sai.fin);

    cout << endl << "AVG waitting time: "<< avg;
     cout << endl <<  "   *************     ";


/************Clean memory ************/
    pont = Sai.primeiro;
    Client* aux;
    for (int i = 0; i < Sai.fin; i++)
    {
        aux = pont;
        free(pont);
        pont = aux->prox;
    }

    cout << endl << "Type anything to continue ..." ; cin.get(); //stop to see results
    return 0;
}


