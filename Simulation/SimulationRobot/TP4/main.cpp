#include "stdafx.h"
#include "head.h"
#include <ctime>
#include <cstdlib>


int TempsDescendre = 1;
int TempsMontee = 1;
double TempMax = 9999;
int Qt_Max_Piece_Syst = 1;
int GRANDE = 999999;
int QtInterMax = 1000;
int QtPiece = 12;
int TypeSys = 0; // 0 = syst aletorio; 1 = syst Optimal; 2 = Syst Permit choisir ordre
int Type_Retard = 0; // 0 = solutions sans retard de pieces; 1 = Permettre retard
int Type_Bloq = 0; //0 = sans bloque; 1 = permettre bloque

void Simuler(RichTextBox^ text, int _Qt_Max_Piece_Syst, int _type, int Qt_Pieces, int *_ordre, int _Type_Bloq, int _type_Retard){
	
	srand((unsigned)time(0));
	T_Ordre Ordre;
	T_Liste_Gamme Gammes;
	T_File Sortie;
	T_Cuve Cuves[QtCuve + 1];
	T_Solution Solution;
	double *VecteurRetard; 
	String^ Evolution_Processus;

// inicialisations 
	TypeSys = _type;
	Type_Bloq = _Type_Bloq;
	Type_Retard = _type_Retard;



	for (int i =0; i<=QtGamme; i++)
		Inicialise_Gamme (Gammes.Liste[i]);
	if ((_Qt_Max_Piece_Syst>0)&&(_Qt_Max_Piece_Syst <= QtPiece))
		Qt_Max_Piece_Syst = _Qt_Max_Piece_Syst;
	if ((Qt_Pieces>0)&&(Qt_Pieces<=50)) // si qtité donne par utilisateur est correcty// si non QtPiece =12;
		QtPiece = Qt_Pieces;
	
	if (TypeSys == 1){
		Qt_Max_Piece_Syst = QtPiece;
		Type_Retard = 0;
		Type_Bloq = 0;
	}
	if (TypeSys!= 1) // si sistème n'est pas optimal
		QtInterMax = 1;
	if (TypeSys == 2) // system qui est permis choisir ordre
	{
		QtPiece = 6;
		for (int i =1; i<=QtPiece; i++)
			Ordre.ordre[i].id = _ordre[i];
	}
	Ordre.n_pieces = QtPiece; // changer quantite de pieces dans vecteur ordre
	VecteurRetard = new double [QtPiece+1];
	Inicialise_VecteurRetard (VecteurRetard);

//Lecture et Plus inicializations
	Inicialise_Solution (Solution);
	string nom = "teste.txt";
	Lire_Fichier(Gammes, nom);
	double temps1 ;
	double temps2;
	for (int ite = 0; ite<QtInterMax; ite++){ // iterations pour systeme de l'algorithme de descente
		if (TypeSys != 2) // si système n'est pas pour choisir ordre
			Generer_ordre (Ordre);
		temps1 = Solution.Temps;
		int con = 0;
		while (con < QtPiece){ // trouver le voisin 
			Inicialise_VecteurRetard (VecteurRetard);
			double TempsFin = Rouler_Systeme (text, Ordre, Gammes, Sortie, Cuves,VecteurRetard);
			double Retard = Donner_retard (Sortie, VecteurRetard);
			int cont = 0;
			if (Type_Retard == 0){
				while ((Retard != 0)&&(cont <100)){
					TempsFin = Rouler_Systeme (text, Ordre, Gammes, Sortie, Cuves,VecteurRetard);
					Retard = Donner_retard (Sortie, VecteurRetard);
					cont++;
				}
			}
			double temp = Solution.Temps;
			Mettre_Dans_Solution (Sortie, TempsFin, Ordre, Solution);
			if (temp != Solution.Temps){// si est arrive quelconque amelioration.
				con = 0;
				changerVecteur_Ordre_PourSolution (Solution, Ordre);
				if (TypeSys != 1)// suelement le system 1 que fera l'heuristique
					con = GRANDE;
			}
			else{

				Chager_Ordre(Ordre,con);
				
			}
		}//fin While
		temps2 = Solution.Temps;
		if (temps1 != temps2)
			Evolution_Processus += "\n Itération: " + Convert::ToString (ite) + " Temps Processus: " + Convert::ToString(Solution.Temps);
	}//fin for
	
	Imprimir_Order(Solution.Ordre, text);
	if (TypeSys == 1){
		text->AppendText("\n\n++++ Convergence du processus ++++++ ");
		text->AppendText(Evolution_Processus);
	}
	Imprimir_Soritie (Solution.Sortie, text, Solution.Temps);
	ImprimirCuves (Cuves, text);
	
}
void Chager_Ordre( T_Ordre &Ordre, int &con){
	if (con > 0){ // retourner pour ordre precedente
		int p = Ordre.ordre[con].id;
		Ordre.ordre[con].id = Ordre.ordre[con+1].id;
		Ordre.ordre[con+1].id = p;
	}
	con ++;
	if (con < QtPiece){ // changer deux position
		int p = Ordre.ordre[con].id;
		Ordre.ordre[con].id = Ordre.ordre[con+1].id;
		Ordre.ordre[con+1].id = p; 
	}	
}

void changerVecteur_Ordre_PourSolution (T_Solution &Solution, T_Ordre &Ordre){
	for (int i = 0; i<= QtPiece; i++)
		Ordre.ordre[i].id = Solution.Ordre.ordre[i].id; 
}

double Donner_retard (T_File &Sortie, double *VecteurRetard){
	double Retar = 0;
	for (int i =1; i<=Sortie.qt; i++){
		Retar += Sortie.Piece[i].delais;
		VecteurRetard[Sortie.Piece[i].id] += Sortie.Piece[i].delais;
	}
	return Retar;
}
		
void Inicialise_VecteurRetard (double *Vec){
	for (int i =1; i<=QtPiece; i++)
		Vec[i] = 0;
}
void Mettre_Dans_Solution (const T_File &Sortie, double &TempsFin, const T_Ordre &Ordre, T_Solution &Solution){
	
	double Retar = 0;
	for (int i =1; i<=Sortie.qt; i++)
		Retar += Sortie.Piece[i].delais;
	if (((TempsFin!= 0)&&(Retar <= Solution.Retard))||(TypeSys!=1)) // dans systeme optimal seulement solutions sans delait
		if (TempsFin < Solution.Temps){
			Solution.Retard = Retar;
			Solution.Temps = TempsFin;
			Solution.Sortie.qt = Sortie.qt;
			for (int i = 0; i<= QtPiece; i++){
				Solution.Sortie.Piece[i].d_entree = Sortie.Piece[i].d_entree;
				Solution.Sortie.Piece[i].d_sortie =	Sortie.Piece[i].d_sortie;
				Solution.Sortie.Piece[i].delais = Sortie.Piece[i].delais;
				Solution.Sortie.Piece[i].id =	Sortie.Piece[i].id;
				Solution.Sortie.Piece[i].Type_gamme =	Sortie.Piece[i].Type_gamme;
			}
			Solution.Ordre.n_pieces = QtPiece;
			for (int i = 0; i<= QtPiece; i++)
				Solution.Ordre.ordre[i].id = Ordre.ordre[i].id;
		}

}

void Inicialise_Solution (T_Solution &Solution){
	Solution.Temps = GRANDE;
	Solution.Retard = GRANDE;
}
void Generer_ordre (T_Ordre &Ordre)
{
	/*for (int i = 1; i<=QtPiece; i++)
		Ordre.ordre[i].id = i;
	Ordre.n_pieces = QtPiece;*/
	
	T_Ordre HoldingList;

	for (int i = 1; i<=QtPiece; i++)
		HoldingList.ordre[i].id = i;

	int aleatorio;
	int aus = QtPiece;
	for (int i = 1; i<=QtPiece; i++)
	{
		aleatorio = (rand()% (aus))+1;
		Ordre.ordre[i].id = HoldingList.ordre[aleatorio].id;
		HoldingList.ordre[aleatorio].id = HoldingList.ordre[aus].id;
		aus--;
	}
	Ordre.n_pieces = QtPiece;
	
}
double Rouler_Systeme (RichTextBox^ text, const T_Ordre &Ordre,const T_Liste_Gamme &Gammes,	T_File &Sortie, T_Cuve *Cuves, double *VecteurRetard)
{
	T_Robot Robot;

	double DS = 0;
	double TempsFin = 0;
	int Qt_piece_Util = 0;
	int Piece_dans_Syst = 0;
	int aux;

	inicialise_File(Sortie);
	Inicialiser_Robot(Robot);
	Inicialiser_Cuves (Cuves);
	int iter = 0;
	int ItMax = 3000;
	while ((DS <= TempMax)&&(iter < ItMax))
	{
		aux = 0;
		if ((Qt_piece_Util < QtPiece)&&(Piece_dans_Syst < Qt_Max_Piece_Syst)&& (Cuves[1].etat == 0))
		{
			if ((Type_Retard == 1)||(Piece_dans_Syst==0))
			{
				T_Gamme gamme;
				int ga = Ordre.ordre[Qt_piece_Util+1].id % QtGamme;
					if (ga == 0)
						ga = QtGamme;
				gamme =  Gammes.Liste[ga];
				aux = Analyse_Prochaine_piece(gamme, Cuves);
				if (Type_Bloq == 1)
					aux = 1;
				if (aux==1)
					Faire_Entree_Nouvelle_Piece (Gammes,Ordre,Cuves,DS,Piece_dans_Syst, Qt_piece_Util, Robot);
			}
			else
			{
				if ((Type_Retard == 0)&&(Qt_piece_Util != QtPiece))
				{
					T_Gamme gamme;
					int ga = Ordre.ordre[Qt_piece_Util+1].id % QtGamme;
						if (ga == 0)
							ga = QtGamme;
					gamme =  Gammes.Liste[ga];
					aux = Analyse_Prochaine_piece(gamme, Cuves);
					if (Type_Bloq == 1)
						aux = 1;
					double Ds = DS + VecteurRetard[Ordre.ordre[Qt_piece_Util+1].id];
					if (aux==1)
						Faire_Entree_Nouvelle_Piece (Gammes,Ordre,Cuves,Ds,Piece_dans_Syst, Qt_piece_Util, Robot);
				}
			}
		}//fin de 
		if (aux == 0)
		{
			if ((Piece_dans_Syst == 1)&&(Cuves[1].etat==1))
				Robot.DPE = Cuves[1].d_sortie_min;
			Prendre_Piece_et_mettre_dans_Cuve(Cuves, Robot,Piece_dans_Syst,Sortie,aux);
		}
		DS = Robot.DPE;
		iter++;
		if ((Sortie.qt == QtPiece)||(iter == ItMax))
		{
			DS = GRANDE;
			TempsFin = Robot.DPE;
		}

	}

	return TempsFin;
}
int Analyse_Prochaine_piece(T_Gamme &gamme,T_Cuve *Cuves)
{
	for (int i =2; i<QtCuve; i++)// on a commencé du 2ème puis le premiere eh le egale a tous et se il y 
	{							// a quelque piece dans la cuve 1 la piece ne peut pas entre... ça est 
		if (Cuves[i].etat!=0)	// dejá evite avant de entre dans cette fonction.
		{
			int z = 1;
			while (Cuves[i].Piece.Gamme.Liste_Operation[z].cuve != i)
				z++;

			for (int y = z+1; y<Cuves[i].Piece.Gamme.Qt_Operation;y++)// ne compte pas le derniere 
			{
				for (int j = 2; j < gamme.Qt_Operation; j++)
					if (Cuves[i].Piece.Gamme.Liste_Operation[y].cuve == gamme.Liste_Operation[j].cuve)
						return 0;
			}
		}
	}
	return 1;
}
void Faire_Entree_Nouvelle_Piece (const T_Liste_Gamme &Gammes,const T_Ordre &Ordre,T_Cuve *Cuves, double &DS, int &Piece_dans_Syst, int &Qt_piece_Util, T_Robot &Robot)
{
	T_Piece Piece;

	Qt_piece_Util++;
	Piece_dans_Syst++;
	inicialise_Piece(Piece);
	Piece.d_entree = DS;
	Piece.id = Ordre.ordre[Qt_piece_Util].id;
	Piece.Type_gamme = Piece.id % QtGamme;
		if (Piece.Type_gamme == 0)
			Piece.Type_gamme = 6;
	Piece.Gamme = Gammes.Liste[Piece.Type_gamme];

	Ajouter_Piece_dans_Cuve (Cuves[1],Piece, DS, 1); // 1 = numero da cuve

		if (Piece_dans_Syst - 1 == 0) // ANALISAR SE EH PRECISO COLOCAR ISSO AQUI ... ACHO QUE NAO
		{
			Robot.DPE = Cuves[1].d_sortie_min;
		}
}

void Prendre_Piece_et_mettre_dans_Cuve(T_Cuve *Cuve, T_Robot &Robot, int &P_Syst, T_File &Sortie, int &aux)
{
	int CuvPrio;
	int CuvDest = Cuve[1].Piece.Gamme.Liste_Operation[2].cuve;
	Analyse_Derniere_Cuve_MettreDansSortie (Cuve[QtCuve], Robot,Sortie, P_Syst);
	if ((Cuve[1].etat == 1)&&(Cuve[1].d_sortie_min <= Robot.DPE)&&(Cuve[CuvDest].etat == 0))
	{
		aux = 1;
		int z = 0;
		if (Robot.position == 1) // idea pra evitar perda de tempo na descida
				Robot.DPE -= TempsDescendre;
		Temps_Moviment_Robot (Robot, Robot.position, 1, CuvDest); // robot, position, origem, destin
		Ajouter_Piece_dans_Cuve (Cuve[CuvDest],Cuve[1].Piece, Robot.DPE - Robot.t_monter, CuvDest); // Cuv2 = numero da cuve
		Zero_Cuve(Cuve[1]);
	}
	else
	{
		
		CuvPrio = Cuve_Priorite (Cuve,Robot);
		if (CuvPrio != 1)
		{
			aux =1;
			//anaylse si temps d'arriver du robot
			if ((Robot.DPE + Robot.deplacement[Robot.position][CuvPrio] + Robot.t_descendre) <  Cuve[CuvPrio].d_sortie_min)
				Robot.DPE = Cuve[CuvPrio].d_sortie_min - Robot.deplacement[Robot.position][CuvPrio] - Robot.t_descendre;
			//analyse si robot est arrive en retard 
			double t_arrive = Robot.DPE + Robot.deplacement[Robot.position][CuvPrio] + Robot.t_descendre;
			if (t_arrive > Cuve[CuvPrio].d_sortie_max) /// ALGUM PROBLEMA AKI ... NAO SEI O QUE ??!!!
				Cuve[CuvPrio].Piece.delais += t_arrive - Cuve[CuvPrio].d_sortie_max;

			CuvDest = Prochaine_Cuve (CuvPrio, Cuve[CuvPrio].Piece);
			Temps_Moviment_Robot (Robot, Robot.position, CuvPrio, CuvDest); // robot, position, origem, destin
			Ajouter_Piece_dans_Cuve (Cuve[CuvDest],Cuve[CuvPrio].Piece, (Robot.DPE - Robot.t_monter), CuvDest);
			Zero_Cuve(Cuve[CuvPrio]);
		}
	}

	if ((aux == 0)&&(Cuve[12].etat ==1))
	{
		Robot.DPE = Cuve[12].d_sortie_min;
		aux = 1;
	}
	if ((aux==0)&&(Cuve[1].etat == 1))
		Robot.DPE = Cuve[1].d_sortie_min;
}
int Cuve_Priorite (T_Cuve *Cuve, const T_Robot& Robot)
{
	int c = 1;
	int cuvDest = 0;
	double Priorite = (-1)*GRANDE;
	double Calc_prio = 0;

	for (int i=c+1; i<QtCuve;i++)
		if (Cuve[i].etat==1)
		{
			cuvDest = Prochaine_Cuve (i, Cuve[i].Piece); //identifie prochaine cuve da la piece qui est dans cuve 
			Calc_prio = ((Robot.DPE - Cuve[i].d_sortie_min)/(Cuve[i].d_sortie_max - Cuve[i].d_sortie_min));
			if ((Cuve[cuvDest].etat==0)&&(Priorite < Calc_prio))
			{
				Priorite = Calc_prio;
				c = i;
			}
		}
	return c;
}
int Prochaine_Cuve (const int &numCuve,const T_Piece& Piece)
{
	int aux = 0;
	int z = 0;
	while (aux!= numCuve)
	{
		z++;
		aux  = Piece.Gamme.Liste_Operation[z].cuve;
	}
	aux  = Piece.Gamme.Liste_Operation[++z].cuve;
	return aux;

}
void Analyse_Derniere_Cuve_MettreDansSortie (T_Cuve &Cuve,const T_Robot &Robot,T_File &Sortie, int &P_Syst)
{
	if ((Cuve.d_sortie_min <= Robot.DPE)&&(Cuve.etat == 1))
		{
			Sortie.qt++;
			Sortie.Piece[Sortie.qt] = Cuve.Piece;
			Sortie.Piece[Sortie.qt].d_sortie = Cuve.d_sortie_min;
			if (P_Syst != 0)
				P_Syst --;

			Zero_Cuve(Cuve);
		}
}
void Temps_Moviment_Robot (T_Robot& Robot, int pos, int Orig, int destin)
{
	Robot.DPE += Robot.deplacement[pos][Orig] + Robot.t_descendre + Robot.t_monter;
	Robot.DPE += Robot.deplacement[Orig][destin] + Robot.t_descendre + Robot.t_monter;
	Robot.position = destin;
}

void Ajouter_Piece_dans_Cuve (T_Cuve & cuve, T_Piece &Piece, const double& DS, const int& num)
{																			// num = numero da cuve
	int aux = 0;
	int z = 0;
	while (aux!= num)
	{
		z++;
		aux  = Piece.Gamme.Liste_Operation[z].cuve;
	}

	cuve.d_entree = DS;
	cuve.d_sortie_max = Piece.Gamme.Liste_Operation[z].date_tard + DS;
	cuve.d_sortie_min = Piece.Gamme.Liste_Operation[z].date_tot + DS;
	cuve.etat = 1;
	cuve.Piece = Piece;
}

void Lire_Fichier(T_Liste_Gamme &Gammes, string &nom){

    ifstream fichier;
    fichier.open(nom.c_str());
	fichier >> Gammes.Qt_Gamme;
	
	for (int i=1 ; i<=QtGamme; i++){
		fichier >> Gammes.Liste[i].Qt_Operation;
		for(int j=1; j<=Gammes.Liste[i].Qt_Operation; j++){
			fichier >> Gammes.Liste[i].Liste_Operation[j].cuve;
			fichier >> Gammes.Liste[i].Liste_Operation[j].date_tot;
			fichier >> Gammes.Liste[i].Liste_Operation[j].date_tard;
		}
	}	
}
void Zero_Cuve (T_Cuve & cuve)
{
		cuve.d_entree = 0;
		cuve.d_sortie_max = 0;
		cuve.d_sortie_min = 0;
		cuve.etat = 0;
		inicialise_Piece (cuve.Piece);
}

void Inicialiser_Cuves (T_Cuve *cuves){
	for (int i=0; i <= QtCuve; i++)
	{
		cuves[i].d_entree = 0;
		cuves[i].d_sortie_max = 0;
		cuves[i].d_sortie_min = 0;
		cuves[i].etat = 0;
		inicialise_Piece (cuves[i].Piece);
	}
}
void Inicialise_Gamme (T_Gamme& gamme)
{
	gamme.Qt_Operation = 0;
	for (int i = 0; i<=QtCuve; i++)
		Inicialise_Operation (gamme.Liste_Operation[i]);
}

void Inicialise_Operation (T_Operation& op)
{
	op.cuve = 0;
	op.date_tard = 0;
	op.date_tot = 0;
}

void inicialise_Piece (T_Piece& piece){
	piece.d_entree = 0;
	piece.d_sortie = 0;
	piece.delais = 0;
	piece.id = 0;
	piece.Type_gamme = 0;
	Inicialise_Gamme(piece.Gamme);
}

void Inicialiser_Robot(T_Robot &Robot){
	Robot.t_descendre = TempsDescendre;
	Robot.t_monter = TempsMontee;
	Robot.DPE = 0;
	Robot.position = 1;
	//Robot.etat = 0;
	for(int i = 1; i<= QtCuve; i++){
		for(int j = 1; j<=QtCuve; j++){
			if (i==j)
				Robot.deplacement[i][j] = 0;
			else
				Robot.deplacement[i][j] = ((double)(i+j))/4;
		}
	}
}

void inicialise_File(T_File &Sortie){
	Sortie.qt = 0;
	for (int i =0; i<= QtPiece; i++)
		inicialise_Piece(Sortie.Piece[i]);
}

void Imprimir_Soritie (const T_File &Sortie, RichTextBox^ text, const double &Temps)
{
	String^ s;
	double Retar = 0;
	s= "\n\nRESULTAT:";
	s += "\n  Quantité de Pieces:" + Convert::ToString(Sortie.qt);
	s += "\n  Donnés Pieces dans Sortie:";
	for (int i =1; i<=Sortie.qt; i++)
	{
		s += "\n    Piece: (" + Convert::ToString(Sortie.Piece[i].id)+ ") Retard: " + Convert::ToString(Sortie.Piece[i].delais);
		s += "     Date Sortie: " + Convert::ToString(Sortie.Piece[i].d_sortie);
		Retar += Sortie.Piece[i].delais;
	}
	s += "\n  Quantité total de retard du processus: " + Convert::ToString(Retar);
	s += "\n  Temps de processus: " + Convert::ToString(Temps); 

	text->AppendText(s);
}
void Imprimir_Order(const T_Ordre &Ordre, RichTextBox^ text)
{
	String^ s;
	text->AppendText("\nORDRE DE PIECES DU SYSTÈME:");
	s = "\n   Numero (Piece-Gamme):    ";
	for (int i=1; i<=Ordre.n_pieces; i++)
	{
		s += "(" + Convert::ToString (Ordre.ordre[i].id)+") ";
		//s += Convert::ToString (Ordre.ordre[i].gamme)+ ") ";
	}
	text->AppendText(s);

}

void ImprimirCuves (T_Cuve *Cuves, RichTextBox^ text)
{
	String^ s;
	int CuvDest;
	s  = "\n\nPièces qui sont encore dans les cuves, puis c'est impossible les finir";
	for (int i =1; i<=QtCuve; i++)
	{
		if (Cuves[i].etat == 1)
		{
			s += "\n  Cuve: " + Convert::ToString(i) + " a la pièce: (" + Convert::ToString (Cuves[i].Piece.id);
			CuvDest = Prochaine_Cuve (i, Cuves[i].Piece);
			s += ") qui a comme destin la cuve -> " + Convert::ToString(CuvDest)+ ";";  
		}
	}
	if (s != "\n\nPièces qui sont encore dans les cuves, puis c'est impossible les finir")
		text->AppendText(s);
}

void Attender_Segunds (int temps, System::Windows::Forms::Timer^  timer1){
	int temp1;
	int temp2;
	
	temp1 = (DateTime::Now.Second + (DateTime::Now.Minute)*60);
	temp2 = (DateTime::Now.Second + (DateTime::Now.Minute)*60);
	while (temp1 + temps > temp2)
		temp2 = (DateTime::Now.Second + (DateTime::Now.Minute)*60);
}
