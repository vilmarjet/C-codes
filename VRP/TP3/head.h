#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include<time.h>
#include <vcclr.h>
using namespace std;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

const int n_max = 102;

typedef struct T_ordre{
    int tourne;
    int seq;
}T_ordre;

typedef struct T_sommet{
    float x;
    float y;
    float demande;
    float date_tot;
    float date_tard;
    float duree;
} T_sommet;

typedef struct T_instance{
    int N;
    float capacite;
    T_sommet Liste[n_max];
    float distance[n_max][n_max];
} T_instance;

typedef struct T_Cell{
    int seq;
    float arrive;
    float debut;
    float fin;
    float folga;
}T_Cell;

typedef struct T_Tourne{
    int qte;
    float Km;
    float capacite;
    T_Cell Liste[n_max];
}T_Tourne;

typedef struct T_solution{
    int qteToune;
    float Km_total;
    T_ordre ordre[n_max];
    T_Tourne Tournees[n_max];
    float cout;
}T_Solution;

typedef struct T_population{
    int N;
    T_solution solutions[51];
}T_population;

typedef struct T_gain{
    int sommet1;
    int sommet2;
    float g;
}T_gain;


void lire_instance(T_instance &instance, String^ nom);
void initialiser_tourne(T_instance &instance, T_solution &solution);
void new_tourne(T_instance &instance, T_solution &solution, int alloue);
int insertion(T_instance &instance, T_solution &solution, int tournee, int sommet);
void generer_sol(T_solution &solution, T_instance &instance, int type);
void generer_ordre_distance(T_instance &instance, T_solution &solution);
void generer_ordre_aleatoire(T_solution &solution);
void creer_pop_initiale(T_instance &instance, T_population &POP);
void copie_solution(T_solution &recoit, T_solution &source);
void copie_liste(T_solution &solution, int tourne, int pos1, int pos2);
void simuler(RichTextBox^  text, TextBox^ nom, TextBox^ _alpha, TextBox^ _beta, TextBox^ _intMAX);
void generer_sol_CW(T_solution &solution, T_instance &instance);
void copie_gain(T_gain &recoit, T_gain &source);
int tester_insertion(T_instance &instance, T_solution &solution, int tournee1, int tournee2);
void fusionner_tournee(T_instance &instance, T_solution &solution, int tournee1, int tournee2);
void recherche_deux_opt(T_instance &instance, T_solution &solution);
void recherche_or_opt(T_instance &instance, T_solution &solution);
void recherche_shift(T_instance &instance, T_solution &solution);
void genetique(T_population &POP, T_instance &instance);
void choisir_parent(int &P1, int &P2);
void croisement(T_solution &P1, T_solution &P2, T_solution &F);
