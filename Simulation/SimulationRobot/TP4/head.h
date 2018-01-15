#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Timers;



const int QtCuve = 12;
const int QtPieceMAX = 50;
const int QtGamme = 6;


typedef struct T_Operation{
	int cuve;
	int date_tot;
	int date_tard;
}T_Operation;

typedef struct T_Robot{
	int t_descendre;
	int t_monter;
	double deplacement[QtCuve+1][QtCuve+1];
	double DPE;
	int position;
}T_Robot;

typedef struct t_entree
{
	int id;
}t_entree;
typedef struct T_Ordre{
	int n_pieces;
	t_entree ordre[QtPieceMAX + 1];
}T_Ordre;

typedef struct T_Gamme{
	int Qt_Operation;
	T_Operation Liste_Operation[QtCuve+1];
}T_Gamme;

typedef struct T_Liste_Gamme{
	int Qt_Gamme;
	T_Gamme Liste[QtGamme + 1];
}T_Liste_Gamme;

typedef struct T_Piece{
	T_Gamme Gamme;
	int Type_gamme;
	int id;
	double delais;
	double d_entree;
	double d_sortie;
}T_Piece;

typedef struct T_Cuve{
	int etat;//0 vide, 1 pleine 
	double d_entree;
	double d_sortie_min;
	double d_sortie_max;
	T_Piece Piece;
}T_Cuve;
typedef struct T_File{
	int qt;
	T_Piece Piece[QtPieceMAX + 1];
}T_File;

typedef struct T_Solution
{
	T_File Sortie;
	T_Ordre Ordre;
	double Temps;
	double Retard;
}T_Solution;


void Inicialiser_Robot( T_Robot &Robot);
void Inicialiser_Cuves (T_Cuve *Cuves);
void inicialise_Piece (T_Piece& piece);
void Inicialise_Gamme (T_Gamme& gamme);
void Inicialise_Operation (T_Operation& op);
void inicialise_File(T_File &Sortie);
void Zero_Cuve (T_Cuve & cuve);
void Inicialise_VecteurRetard (double *Vec);
void Inicialise_Solution (T_Solution &Solution);


void Simuler(RichTextBox^ text, int _Qt_Max_Piece_Syst, int _type, int Qt_Pieces, int *_ordre, int, int);
double Rouler_Systeme (RichTextBox^ text, const T_Ordre &Ordre,const T_Liste_Gamme &Gammes,	T_File &Sortie, T_Cuve *Cuves, double *VecteurRetard);
void Faire_Entree_Nouvelle_Piece (const T_Liste_Gamme &Gammes,const T_Ordre &Ordre,T_Cuve *Cuves, double &DS, int &Piece_dans_Syst, int &Qt_piece_Util, T_Robot &Robot);
void Prendre_Piece_et_mettre_dans_Cuve(T_Cuve *Cuve, T_Robot &Robot, int &P_Syst, T_File &Sortie, int &aux);

void Generer_ordre (T_Ordre &Ordre);
void Chager_Ordre( T_Ordre &Ordre,int &con);
void Lire_Fichier(T_Liste_Gamme &Gammes, string &nom);
void Mettre_Dans_Solution (const T_File &Sortie, double &TempsFin, const T_Ordre &Ordre, T_Solution &Solution);


int Analyse_Prochaine_piece(T_Gamme &gamme,T_Cuve *Cuves);
void Temps_Moviment_Robot (T_Robot& Robot, int pos, int Orig, int destin);
int Cuve_Priorite (T_Cuve *Cuve, const T_Robot& Robot);
int Prochaine_Cuve (const int &num,const T_Piece& Piece);
void Analyse_Derniere_Cuve_MettreDansSortie (T_Cuve &Cuve,const T_Robot &Robot,T_File &Sortie, int &P_Syst);
void Ajouter_Piece_dans_Cuve (T_Cuve & cuve, T_Piece &Piece, const double& DS, const int& num);
double Donner_retard (T_File &Sortie, double *VecteurRetard);
void changerVecteur_Ordre_PourSolution (T_Solution &Solution, T_Ordre &Ordre);


void Imprimir_Order(const T_Ordre &Ordre, RichTextBox^ text);
void Imprimir_Soritie (const T_File &Sortie, RichTextBox^ text, const double &Temps);
void ImprimirCuves (T_Cuve *Cuves, RichTextBox^ text);
void Attender_Segunds (int temps, System::Windows::Forms::Timer^ timer1);