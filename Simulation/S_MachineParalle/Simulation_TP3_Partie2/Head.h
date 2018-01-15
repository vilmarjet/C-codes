#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Windows::Forms::DataVisualization::Charting;

const int N_Etapes = 2;
const int TAILLE = 8;
const int TAILLEsortir = 500;

typedef struct T_Etape
{
    int Station;
    double DateArrive;
    double DateSortie;
}T_Etape;

typedef struct T_Gamme T_Gamme;
struct T_Gamme
{
    T_Etape ListeEtape [N_Etapes +2];
    double ProbQ;
    double ProbP;
};


typedef struct T_Client Client;
struct T_Client
{
    int id;
    double T_Arri_Syst;
    T_Gamme GammeDernier;
};

typedef struct T_Machine
{
    Client Atendendo;
    int Etat; // se 1 est occupe, se 0 non, si 2 elle est bloquee;
    double DureeT;
    double DureeT2;
    double DPE;
}T_Machine;
typedef struct T_File // FilaInfinita
{
    Client Liste [TAILLE+1]; // Definir quantidade de clientes na fila externa
    int premier; // Apontar para primeiro cliente
    int dernier;
    int fin;

}T_File;

typedef struct T_FileSortie // FilaInfinita
{
    Client Liste [TAILLEsortir]; // Definir quantidade de clientes na fila externa
    int ultimo;
    int qte;

}T_FileSortie;

typedef struct T_Entree
{
    double DPE;
    double DIA;
}T_Entree;

void Simuler (RichTextBox^ , int , double ,double ,double ,double ,double ,double ,int ,int ,Chart^  chart1, Chart^  chart2, Chart^  chart3);
void FairePeice_MachineA (T_File& fila, T_Machine& mach, double ds,T_File& filaB, T_Machine& machB, int numero, T_Machine& MachConc);
void FairePeice_MachineAutre (T_File& fila,T_Machine& mach,double DS, T_FileSortie& Sortie, T_Machine& Mach1, T_Machine& Mach2);
void FaireEntree (T_File &Fila,T_Entree &Entree,double &DS, T_Machine &Mach,int &seq,int &PiecePerd_Sta);
void AnaliseRegraEtMettreFila3 (T_Machine &mach, T_Machine &machB, T_File& filaB,int numero, double ds, T_Machine& MachConc);
void Analyse_ReveillerMachine (T_Machine &Mach1, T_Machine &Mach2, double DS, T_File& fila);
void Reveiller_Les_Machines(T_Machine &Mach1, T_Machine &Mach2, T_File&fila,double DS);
void GererNouvellePiece (T_Entree& Entree, T_File& fila,double tempArrive, int seq);
void MettreDansfila (T_File& fila, Client& atendendo);
void MettreDansfilaSortie (T_FileSortie& fila, Client& atendendo);
double MenordeCinq (double a, double b, double c, double d, double e);

void InicilisePiece (T_Client& pc);
void IniciliseMachine (T_Machine& Mach);
void IncialiseFile (T_File& Fila);
void IncialiseFileSortie (T_FileSortie& Fila);
void IniciliseGamme(T_Gamme& Gamme);
void IniciliseEntree (T_Entree& entre, double Arrive);
void InicialiseSerieDonneGeneraux (Series^ series1);
void InicializarSeries (Series^ Ent1, Series^ Ent2,Series^ Per1,Series^ Per2,Series^ Syst,Series^ Sta1,Series^ Sta2, Series^Sta3,Series^ Gamm1, Series^ Gamm2, Series^ Sort,Series^ Sta3_1,Series^ Sta3_2,Series^ Syst_1,Series^ Syst_2);
bool FileVide (T_File& Fila);
void ordreFilaFila3 (T_File& fila);
void ordreFilaFila3Regle1et2 (T_File& fila, int regra);
int TrouverVLR (T_Entree& Entree1,T_Machine& Mach1,T_Machine& Mach2,T_Machine& Mach3, T_Entree& Entree2, double);
void FaireType1 (T_Machine &mach,T_File& fila,double DS, T_Machine &Mach1, T_Machine &Mach2,T_FileSortie& Sortie);
void FaireType2 (T_Machine &mach,double DS, T_Machine &Mach1, T_Machine &Mach2,T_FileSortie& Sortie);
void Change_Gamme_Atendendo (Client &atendendo, int seq, double TempoArriveMac, double TempSortiMach);
void MettreCoordonne_en_Serie (Series^ serie, double X, double Y);

void ImprimirPieces_En_file_En_Machine (T_File& fila,T_Machine& Mach,RichTextBox^ text);
void ImprimirResutat_Sortie (T_FileSortie& Sortie, RichTextBox^ text);
void ImprimirResultatStations (T_Machine&Mach1, T_Machine&Mach2, T_Machine&Mach3, T_File& Fila1,T_File& Fila2 ,T_File& Fila3,int& seq, int& seq2,RichTextBox^ text, double &Temps);

void Faire_Series_Graphe_chart3 (int tipo, Client &Piece,double DS, Series^ Sta1,Series^ Sta2,Series^ Sta3,Series^ Syst,Series^ Sta3_1,Series^ Sta3_2,Series^ Syst_1,Series^ Syst_2);
void Computing_TempsStation (double &temps_st1, double &temps_st2, double &temps_st3, double &temps_syst, Client &Piece);
