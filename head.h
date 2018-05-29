
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#define REPETICAO 500 //Number of GRASP iterations
#define CONSTANT 10000

//#define VOISINS 1000


float ALPHA  = 0.7; //


typedef struct T_operation
{
    int seq; // utilizar na ordem obrigatorio de producao do produto
    int machine;
    int duree;
    int produit;
    int MenTInicio;
    int proxObri; // pegar a seguencia da operacao que e a seguinte
    int anterior;
}Operation;

typedef struct T_Problem
{
    int QtProd ;
    int QtMach ;
    Operation* AllOperation;
}Problem;

typedef struct T_Solution
{
    Operation* ordem; // VECTOR DE OPERACTIONS
    int cont;   // COMBIEN OPERATIONS
    int coup; // MELEUX VALUAR
    Operation* VectorMelhorResulta;
    int* CheminCritique;
    int signature;
}Solution;

typedef struct T_vectorsolucao
{
    int* vector;

}VectorSolution;

typedef struct T_SolutionsRealized
{
    int* solucao;
    int ultimo;

}Vec_SolutionsRealized;

void InicializaSolutionsRealized (Vec_SolutionsRealized& vs);

void InicializaVectorSolution (Problem& Prob, VectorSolution& vector);

void InicializaOperation(Operation& op);

void ZerarChemin(Solution& sol, Problem& Prob);

void InicializaSolucao (Problem & Prob, Solution & sol);




/*******************LIRE AFFICHIER ***********************/
void Lire(char* nome, Operation & Op, Problem & Prob);

void LirePremiereSoluction (char* nome, Problem & Prob, Solution & sol );

/**************************DEBUT DES FUNCTIONS POUR MODIFIER LA SOLUCTION DE JOB-SHOP************/
// CETTE FUNCTION CHANGERA LES VALUAR DE debut de operations
void Tempo_Inicio_fila_Obrigatoria2 (Solution& sol, int &aux, Problem & Prob);
void Muda_Tempo_Proxima_machine(Solution& sol, int &aux, Problem & Prob ); // acha maquina mais proxima na sequencia

void EvaluarSolution (Problem & Prob,Solution & sol); // evaluar
void FazerChemincritique (int maior, Solution& sol, Problem& Prob);

// CETTE FUNCTION CHERCHE LE CHEMIN PLUS GRAND EH DONNER COMME RESULTA CETTE VALUAR
int MTempo(Solution& sol, Problem & Prob);

int Teste_Double (Solution & sol, Vec_SolutionsRealized & VecSolu);
// CREE FUNCTIONS RANDONICAS
void PlusSolutionsRandom (Problem & Prob,Solution & sol,Vec_SolutionsRealized&);

/********************************** IMPRESSOES ************************/
void ImprimirMatriz (Problem & Prob);
void ImprimirCaminhoCriticoCadaResultado(int & maior, Solution& sol, Problem & Prob);
void Imprimir_CaminhoCritico_Final (Solution& sol);
void Imprimir_MelhorSolution_Finalle (Solution& sol, Problem& Prob);

/************************************METHODO GRASP *******************/
void MetodoGraspe (Problem& Prob, Solution& sol);
void RechercheLocal_Complet (Problem& Prob, Solution& sol, VectorSolution& vector);
void PreencheSoluctionAvecVector(VectorSolution& vectorValor2, Problem & Prob, Solution & sol);
void RechercheLocal_Random (Problem& Prob, Solution& sol, VectorSolution& vector, int Qtvoisin);
void ordernarVetorRCLBuble (Solution& VectorRCL, Problem & Prob);

