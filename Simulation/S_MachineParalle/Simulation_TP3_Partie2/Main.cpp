
/**
Made in VISUAL STUDIO 12 ...
This is the main function of the application
Interpret the application data and apply the simulation in the system

This is a Simulation process of 3 machines.

The main idea of this problem is that we have 2 source of pruducts and two machines (Stations) with treatment time = S1 and S2
(each one of the stations receive their product (job) from a specific source (Entree) . )
This two machine sent their final products to a third machine "the Assembler".

All machines have a limited (or not) line (File) where product wait to be treated. Product that can not be fit in the line are lost !

Chart are used to show the avg of waitting time, lost of each machine and the number of products produced.

*/



#include "stdafx.h"
#include "Head.h"


int TEMPSMAX = 700;
double S1 = 4;
double S2 = 20;
double S3_1 = 10;
double S3_2 = 10;
double ProbQ = 1.0;
double ProbP = 1.0;
double DIA1 = 6;
double DIA2 = 3;
int Regle = 2;
const int GRANDE = 99999;
double ep = 0.00001;

int TYPE_SYSTEM = 2; // (0) si sans assemblage et (1) avec assemblage (2) Assemblagem sans file

//Main function (Read all the info from application)
void Simuler (RichTextBox^ text, int _TEMPSMAX, double _DIA1,double _DIA2,double _S1,double _S3_1,double _S2,double _S3_2,int _Regle,int _TYPE_SYSTEM,Chart^  chart1, Chart^  chart2, Chart^  chart3)
{

 TEMPSMAX = _TEMPSMAX; //Teps Max
 S1 = _S1;
 S2 = _S2;
 S3_1 = _S3_1;
 S3_2 = _S3_2;
 DIA1 = _DIA1;
 DIA2 = _DIA2;
 Regle = _Regle;
 TYPE_SYSTEM = _TYPE_SYSTEM;

  // declarations
    T_File Fila1;
    T_File Fila2;
    T_File Fila3;
    T_FileSortie Sortie;

    T_Machine Mach1;
    T_Machine Mach2;
    T_Machine Mach3;

    T_Entree Entree1;
    T_Entree Entree2;

    //Graph initializations
	Series^  Ent1 = (gcnew Series());
	Series^  Ent2 = (gcnew Series());
	Series^  Per1 = (gcnew Series());
	Series^  Per2 = (gcnew Series());
	Series^  Syst = (gcnew Series());
	Series^  Sta1 = (gcnew Series());
	Series^  Sta2 = (gcnew Series());
	Series^  Sta3 = (gcnew Series());
	Series^  Gamm1 = (gcnew Series());
	Series^  Gamm2 = (gcnew Series());
	Series^ Sort  = (gcnew Series());
	Series^  Sta3_1 = (gcnew Series());
	Series^  Sta3_2 = (gcnew Series());
	Series^  Syst_1 = (gcnew Series());
	Series^  Syst_2 = (gcnew Series());

	DataPoint^  dataPoint;


    double DS = 0.0;
    double temps;
    int vlr = 0;
    int seq = 0;
    int seq2 = 0;
    int PiecePerd_Sta1 = 0;
    int PiecePerd_Sta2 = 0;
    int nume = 0;
	int Gamme1 = 0;
	int Gamme2 = 0;
	int tipo = 0;
	int so = 0;
	String^ s;

// Inicialisations
    IncialiseFile (Fila1);
    IncialiseFile (Fila2);
    IncialiseFile (Fila3);
    IncialiseFileSortie (Sortie);
    IniciliseMachine (Mach1); // INICIALISE
    IniciliseMachine (Mach2);
    IniciliseMachine (Mach3);
    IniciliseEntree (Entree1,DIA1);
    IniciliseEntree (Entree2,DIA2);
	InicializarSeries (Ent1,Ent2,Per1,Per2,Syst,Sta1,Sta2,Sta3,Gamm1,Gamm2,Sort,Sta3_1,Sta3_2,Syst_1,Syst_2);

//Mettre les valeurs
    Mach1.DureeT = S1;
    Mach2.DureeT = S2;
    Mach3.DureeT = S3_1;
    Mach3.DureeT2 = S3_2;

// faire srand
    srand((unsigned)time(0));

    while (DS <= TEMPSMAX)
    {
        vlr = TrouverVLR (Entree1, Mach1, Mach2, Mach3, Entree2, DS); //find next task to be done

        switch (vlr)
        {
            case 1: // file station 1
                {
                    seq++;
                    FaireEntree (Fila1, Entree1, DS, Mach1, seq, PiecePerd_Sta1);
					//Donnes pour graphe:
					MettreCoordonne_en_Serie(Ent1,DS,double (seq));
					MettreCoordonne_en_Serie(Per1,DS,double(PiecePerd_Sta1));
                }
                break;
            case 5: // file station 2
                {
					seq2--;
                    FaireEntree (Fila2,Entree2, DS, Mach2,seq2, PiecePerd_Sta2);
					//Donnes pour graphe:
					MettreCoordonne_en_Serie(Ent2,DS,double(-1*seq2));
					MettreCoordonne_en_Serie(Per2,DS,double (PiecePerd_Sta2));
                }
                break;
            case 2: // mach 1
                    nume = 1; // numero de la machine
                    if ((Regle == 2) && (Mach1.Etat == 1) && (Mach2.DPE == DS) && (Mach2.Etat == 1)&& (TYPE_SYSTEM != 2))
                        Mach1.DPE  = Mach1.DPE + 0.0001;
                    else
                        FairePeice_MachineA (Fila1, Mach1, DS, Fila3, Mach3, nume, Mach2); // pensar ainda !!!
                break;

            case 3: // mach 2
                    nume = 2;
                    if ((Regle == 1) && (Mach2.Etat == 1) && (Mach1.DPE == DS) && (Mach1.Etat == 1)&& (TYPE_SYSTEM != 2))
                        Mach2.DPE  = Mach2.DPE  + 0.0001;
                    else
                        FairePeice_MachineA (Fila2, Mach2, DS, Fila3, Mach3, nume, Mach1);
                break;

            case 4: // mach 3
					tipo = 0;
					so = Sortie.ultimo;
                    if ((TYPE_SYSTEM == 0)&&(Mach3.Etat == 1))//sans assemblage et mach3 ocoupe
					 {
						if (Mach3.Atendendo.GammeDernier.ListeEtape[1].Station == 1)
							Gamme1++;
						else
							Gamme2++;
						MettreCoordonne_en_Serie (Gamm1,DS,Gamme1);
						MettreCoordonne_en_Serie (Gamm2,DS,Gamme2);
						tipo =1;
					 }
					 else // assemblage
						 if (Mach3.Etat == 1)
						 {
							dataPoint = (gcnew DataPoint(DS,Sortie.ultimo+1));
							Sort->Points->Add(dataPoint);
							tipo = 2;
						 }

					FairePeice_MachineAutre (Fila3, Mach3, DS, Sortie, Mach1, Mach2);

					if (((tipo == 1)||(tipo==2))&&(so < Sortie.ultimo))
						Faire_Series_Graphe_chart3 (tipo, Sortie.Liste[Sortie.ultimo],DS,Sta1,Sta2,Sta3,Syst,Sta3_1,Sta3_2,Syst_1,Syst_2); //Do chart
                break;
            default:
                cout << "\nERROR IN SWITCH \n";
        }
        temps = DS;
        if ((Mach3.DPE == GRANDE)&&(Mach1.DPE == GRANDE)&&(Mach2.DPE == GRANDE))
        {
            Entree1.DPE = GRANDE;
            Entree2.DPE = GRANDE;
			s = "\nProdution a arreté dans le temps égal à: " + Convert ::ToString (temps);
            text->AppendText(s);
        }
        DS = MenordeCinq (Entree1.DPE, Mach1.DPE, Mach2.DPE, Mach3.DPE, Entree2.DPE); // find when the next task will happen.
    }

    ordreFilaFila3 (Fila3);

    //Print in TEXT
    ImprimirResultatStations (Mach1, Mach2, Mach3, Fila1, Fila2, Fila3, seq, seq2,text,temps);
	ImprimirResutat_Sortie (Sortie, text);


//Fill chart info
	chart1->Series->Add(Ent1);
	chart1->Series->Add(Ent2);
	chart1->Series->Add(Per1);
	chart1->Series->Add(Per2);


	chart2->Series->Add(Sta1);
	chart2->Series->Add(Sta2);



	if (TYPE_SYSTEM == 0)
	{
		chart3->Series->Add(Gamm1);
		chart3->Series->Add(Gamm2);
		chart2->Series->Add(Syst_1);
		chart2->Series->Add(Sta3_1);
		chart2->Series->Add(Syst_2);
		chart2->Series->Add(Sta3_2);

	}
	else
	{
		chart3->Series->Add(Sort);
		chart2->Series->Add(Syst);
		chart2->Series->Add(Sta3);
	}


}
void Faire_Series_Graphe_chart3 (int tipo, Client &Piece,double DS, Series^ Sta1,Series^ Sta2,Series^ Sta3,Series^ Syst,Series^ Sta3_1,Series^ Sta3_2,Series^ Syst_1,Series^ Syst_2)
{
	double Temps;
	double duree = S3_1;
	if (tipo == 1)
	{
		//Temps dans station 1 ou station 2:
		Temps = Piece.GammeDernier.ListeEtape[1].DateSortie - Piece.T_Arri_Syst;
		if (Piece.GammeDernier.ListeEtape[1].Station == 1)
		{
			MettreCoordonne_en_Serie (Sta1, DS, Temps);
			// Temps dans station 3
			Temps = DS - Piece.GammeDernier.ListeEtape[1].DateSortie;
			MettreCoordonne_en_Serie (Sta3_1, DS, Temps);
			//Temps dans system
			Temps = DS - Piece.T_Arri_Syst;
			MettreCoordonne_en_Serie (Syst_1, DS, Temps);
		}
		else
		{
			MettreCoordonne_en_Serie (Sta2, DS, Temps);
			// Temps dans station 3
			Temps = DS - Piece.GammeDernier.ListeEtape[1].DateSortie;
			MettreCoordonne_en_Serie (Sta3_2, DS, Temps);
			//Temps dans system
			Temps = DS - Piece.T_Arri_Syst;
			MettreCoordonne_en_Serie (Syst_2, DS, Temps);
		}
	}
	else
	{
		// Station 1 ;
		Temps = Piece.GammeDernier.ListeEtape[1].DateSortie - Piece.GammeDernier.ListeEtape[1].DateArrive;
		MettreCoordonne_en_Serie (Sta1, DS, Temps);
		//station 2;
		Temps = Piece.GammeDernier.ListeEtape[2].DateSortie - Piece.GammeDernier.ListeEtape[2].DateArrive;
		MettreCoordonne_en_Serie (Sta2, DS, Temps);
		//Station 3;
		Temps = Piece.GammeDernier.ListeEtape[3].DateSortie - Piece.GammeDernier.ListeEtape[3].DateArrive;
		MettreCoordonne_en_Serie (Sta3, DS, Temps);

		// SYSTEM
		Temps = Piece.GammeDernier.ListeEtape[3].DateSortie - Piece.T_Arri_Syst;
		MettreCoordonne_en_Serie (Syst, DS, Temps);
	}

}
void ImprimirResutat_Sortie (T_FileSortie& Sortie, RichTextBox^ text)
{
    String^ s;
	double Moyenne_st1 = 0;
	double Moyenne_st2 = 0;
	double Moyenne_st3 = 0;
	double Moyenne_syst = 0;
	 int Gamme1 = 0;
	 int Gamme2 = 0;

	for (int i = 1; i <= Sortie.ultimo; i++)
    {
        if (Sortie.Liste[i].GammeDernier.ListeEtape[1].Station == 1)
            Gamme1 ++;
        else
            Gamme2++;

		Computing_TempsStation (Moyenne_st1, Moyenne_st2, Moyenne_st3, Moyenne_syst, Sortie.Liste[i]);
    }

	 if (TYPE_SYSTEM == 0)
	 {
		 if (Gamme1 > 0)
			Moyenne_st1 = Moyenne_st1/Gamme1;
		 if (Gamme2 > 0)
			Moyenne_st2 = Moyenne_st2/Gamme2;
		 Moyenne_st3 = Moyenne_st3/Sortie.ultimo;
		 Moyenne_syst = Moyenne_syst/Sortie.ultimo;

	 	 s = "\n\nQuantité de Pieces dans la Sortie: " + Convert::ToString(Sortie.ultimo);
		 text->AppendText(s);
		 s = "\nNb de Piece sorties de Gamme1: " + Convert::ToString(Gamme1);
		 text->AppendText(s);
		 s = "\nNb de Piece sorties de Gamme2: " + Convert::ToString(Gamme2);
		 text->AppendText(s);
		 s = "\nTemps moyen dans la Station 1: " + Convert::ToString (int (Moyenne_st1));
		 text->AppendText(s);
		 s = "\nTemps moyen dans la Station 2: " + Convert::ToString (int (Moyenne_st2));
		 text->AppendText(s);
		 s = "\nTemps moyen dans la Station 3: " + Convert::ToString (int (Moyenne_st3));
		 text->AppendText(s);
		 s = "\nTemps moyen dans le SYSTÈME: " + Convert::ToString (int (Moyenne_syst));
		 text->AppendText(s);
	 }
	 else
	 {
		 Moyenne_st1 = Moyenne_st1/Sortie.ultimo;
		 Moyenne_st2 = Moyenne_st2/Sortie.ultimo;
		 Moyenne_st3 = Moyenne_st3/Sortie.ultimo;
		 Moyenne_syst = Moyenne_syst/Sortie.ultimo;

		 s = "\n\nQuantité de Pieces dans la Sortie: " + Convert::ToString( Sortie.ultimo);
		 text->AppendText(s);
		 s = "\nTemps moyen dans la Station 1: " + Convert::ToString (int (Moyenne_st1));
		 text->AppendText(s);
		 s = "\nTemps moyen dans la Station 2: " + Convert::ToString (int (Moyenne_st2));
		 text->AppendText(s);
		 s = "\nTemps moyen dans la Station 3: " + Convert::ToString (int (Moyenne_st3));
		 text->AppendText(s);
		 s = "\nTemps moyen dans le SYSTÈME: " + Convert::ToString (int (Moyenne_syst));
		 text->AppendText(s);

	 }
}
void Computing_TempsStation (double &temps_st1, double &temps_st2, double &temps_st3, double &temps_syst, Client &Piece)
{
	if (TYPE_SYSTEM == 0)
	{
		if (Piece.GammeDernier.ListeEtape[1].Station == 1)
			temps_st1 = temps_st1 + Piece.GammeDernier.ListeEtape[1].DateSortie - Piece.GammeDernier.ListeEtape[1].DateArrive;
		else
			temps_st2 = temps_st2 + Piece.GammeDernier.ListeEtape[1].DateSortie - Piece.GammeDernier.ListeEtape[1].DateArrive;

		temps_st3 = temps_st3 + Piece.GammeDernier.ListeEtape[2].DateSortie - Piece.GammeDernier.ListeEtape[2].DateArrive;
		temps_syst = temps_syst + Piece.GammeDernier.ListeEtape[2].DateSortie - Piece.T_Arri_Syst;
	}
	else
	{
		temps_st1 = temps_st1 + Piece.GammeDernier.ListeEtape[1].DateSortie - Piece.GammeDernier.ListeEtape[1].DateArrive;
		temps_st2 = temps_st2 + Piece.GammeDernier.ListeEtape[2].DateSortie - Piece.GammeDernier.ListeEtape[2].DateArrive;
		temps_st3 = temps_st3 + Piece.GammeDernier.ListeEtape[3].DateSortie - Piece.GammeDernier.ListeEtape[3].DateArrive;
		temps_syst = temps_syst + Piece.GammeDernier.ListeEtape[3].DateSortie - Piece.T_Arri_Syst;
	}
}
void ImprimirResultatStations (T_Machine&Mach1, T_Machine&Mach2, T_Machine&Mach3, T_File& Fila1,T_File& Fila2 ,T_File& Fila3,int& seq, int& seq2,RichTextBox^ text, double &Temps)
{
	String^ s;
	s = "\nImprimir Resultat:\n  SORCE 1: a generee " + Convert::ToString(seq) + " pieces";
	text->AppendText(s);
	s = "\n  SORCE 1: a generee " + Convert::ToString(-1*seq2) + " pieces";
	text->AppendText(s);
	s = "\nDATE SIMULATION = " + Convert::ToString (Temps);
	text->AppendText(s);

// acabar de fazer
	s = "\n--------STATION 1 ----------";
	text->AppendText(s);
        ImprimirPieces_En_file_En_Machine (Fila1,Mach1,text);
	s = "\n--------STATION 2 ----------";
	text->AppendText(s);
        ImprimirPieces_En_file_En_Machine (Fila2,Mach2,text);
	s = "\n--------STATION 3 ----------";
	text->AppendText(s);
        ImprimirPieces_En_file_En_Machine (Fila3,Mach3,text);
}
void ImprimirPieces_En_file_En_Machine (T_File& fila,T_Machine& Mach,RichTextBox^ text)
{
    String^ s;
	s = "\n   La FILE contient: ";
	text->AppendText(s);
        int i = fila.premier;
        for (int j =1; j <= fila.fin ; j++)
        {
			s = Convert::ToString(fila.Liste[i].id)+ " ";
			text->AppendText(s);
            if (i == TAILLE)
                i = 1;
            else
                i++;
        }
		s = "\n   MACHINE: Contient la piece numero: " + Convert::ToString (Mach.Atendendo.id);
        text->AppendText(s);
}
void FaireEntree (T_File &Fila,T_Entree &Entree,double &DS, T_Machine &Mach,int &seq,int &PiecePerd_Sta)
{
    if (Fila.fin ==TAILLE)
        {
            PiecePerd_Sta ++;
            Entree.DPE = DS + Entree.DIA;
        }

    else
        {
            GererNouvellePiece (Entree, Fila, DS, seq);
            if (Mach.Etat == 0)
                Mach.DPE = DS;
        }
}
void FairePeice_MachineAutre (T_File& fila,T_Machine& mach,double DS, T_FileSortie& Sortie, T_Machine& Mach1, T_Machine& Mach2)
{
    float teste;
   // teste = Sortie.primeiro->id;
    if ((FileVide (fila))&& (TYPE_SYSTEM != 2))
    {
        mach.DPE = GRANDE;
        if (mach.Etat==1)
        {
            mach.Etat = 0;
			if (TYPE_SYSTEM == 0)
				mach.Atendendo.GammeDernier.ListeEtape[2].DateSortie = DS;

            MettreDansfilaSortie (Sortie, mach.Atendendo);
            InicilisePiece (mach.Atendendo);
        }
    } // fin file vide
    else
    {
        if (mach.Etat == 0)
            {
                mach.Etat = 1;
                if (Regle != 4) // sans regle
                    ordreFilaFila3 (fila);

                if (TYPE_SYSTEM == 0) // sans assemblage
                {
                    mach.Atendendo = fila.Liste[fila.premier];
                    fila.premier++;
                    if (fila.premier > TAILLE)
                        fila.premier = 1;
                    fila.fin --;

                   // mach.Atendendo.GammeDernier.ListeEtape[2].DateArrive = DS;

                    if (mach.Atendendo.GammeDernier.ListeEtape[1].Station == 1)
                        mach.DPE = DS + mach.DureeT; // alterar tempol de proximo evento
                    else
                        mach.DPE = DS + mach.DureeT2;

                    if ((Mach1.Etat == 2) || (Mach2.Etat == 2))
                        Reveiller_Les_Machines(Mach1,Mach2,fila,DS);
                }
                if (TYPE_SYSTEM == 1)
                {
                    FaireType1 (mach, fila, DS, Mach1, Mach2,Sortie);
                }
				if (TYPE_SYSTEM == 2)
				{
					if ((Mach1.Etat == 2)&&(Mach2.Etat == 2))
						FaireType2 (mach, DS, Mach1, Mach2,Sortie); // fazer
					else
					{
						mach.Etat = 0;
						mach.DPE = GRANDE;
					}
				}

            } // fin machine.ocoupe = 0
        else
        {
            mach.Etat = 0;
            mach.DPE = DS;
			if (TYPE_SYSTEM == 0)
				mach.Atendendo.GammeDernier.ListeEtape[2].DateSortie = DS;
            MettreDansfilaSortie (Sortie, mach.Atendendo);
            InicilisePiece (mach.Atendendo);
        }

    }
}

void FaireType2 (T_Machine &mach,double DS, T_Machine &Mach1, T_Machine &Mach2,T_FileSortie& Sortie)
{
    int num1 = 1;
    int num2 = 2;

    Client atendendo;
    InicilisePiece(atendendo);
	Change_Gamme_Atendendo (atendendo, num1, Mach1.Atendendo.T_Arri_Syst, DS);
    Change_Gamme_Atendendo (atendendo, num2, Mach2.Atendendo.T_Arri_Syst, DS);
	Change_Gamme_Atendendo (atendendo,3,DS,DS+ mach.DureeT);
    atendendo.id = Sortie.ultimo+1;


	atendendo.T_Arri_Syst = Mach1.Atendendo.T_Arri_Syst;
	if ( Mach2.Atendendo.T_Arri_Syst < atendendo.T_Arri_Syst)
			atendendo.T_Arri_Syst = Mach2.Atendendo.T_Arri_Syst;

	InicilisePiece (Mach1.Atendendo);
	Mach1.Etat = 0;
	Mach1.DPE = DS;

	InicilisePiece (Mach2.Atendendo);
	Mach2.Etat = 0;
	Mach2.DPE = DS;

    mach.Atendendo = atendendo;
    mach.DPE = DS + mach.DureeT;
	mach.Etat = 1;
}
void FaireType1 (T_Machine &mach,T_File& fila,double DS, T_Machine &Mach1, T_Machine &Mach2,T_FileSortie& Sortie)
{
    int teste = fila.premier;
    int num1 = fila.Liste[fila.premier].GammeDernier.ListeEtape[1].Station;
    if (num1 == 0) // pode deletar depois
        cout << "Erro na maquina - numero = 0 - olhar faire piece";
    int num2,seq;
    int aux = 0;
    //teste = fila.premier;
    int teste1 = fila.dernier;

    seq = fila.premier;
    do
    {
        seq ++;
        if (seq > TAILLE)
            seq=1;
        num2 = fila.Liste[seq].GammeDernier.ListeEtape[1].Station;
        if ((num2 != num1) && (num2 != 0))
        {
            aux = seq;
            seq = fila.dernier;
        }
    }while (seq != fila.dernier);

    if (aux == 0) // SE NAO ENCONTROU OUTRA PECA
        {
            mach.Etat = 0;
            mach.DPE = GRANDE;
        }
    else
    {
        Client atendendo;
        InicilisePiece(atendendo);
        Change_Gamme_Atendendo (atendendo, num1, fila.Liste[fila.premier].T_Arri_Syst, fila.Liste[fila.premier].GammeDernier.ListeEtape[1].DateSortie);
        Change_Gamme_Atendendo (atendendo, num2, fila.Liste[aux].T_Arri_Syst, fila.Liste[aux].GammeDernier.ListeEtape[1].DateSortie);
        double menor  = fila.Liste[fila.premier].GammeDernier.ListeEtape[1].DateSortie;
			if (fila.Liste[aux].GammeDernier.ListeEtape[1].DateSortie < menor)
					menor = fila.Liste[aux].GammeDernier.ListeEtape[1].DateSortie;
		Change_Gamme_Atendendo (atendendo,3,menor,DS+ mach.DureeT);
		//change temps d'arrive de la piece
		atendendo.T_Arri_Syst = fila.Liste[fila.premier].T_Arri_Syst;
		if ( fila.Liste[aux].T_Arri_Syst < atendendo.T_Arri_Syst)
				atendendo.T_Arri_Syst = fila.Liste[aux].T_Arri_Syst;
        atendendo.id = Sortie.ultimo+1;
        InicilisePiece(fila.Liste[aux]); // fazer todos voltarem.
        int zz;
        while (aux!= fila.dernier)
        {
            zz = aux+1;
            if (zz >TAILLE)
                zz = 1;
            fila.Liste[aux] = fila.Liste[zz];
            aux = zz;
        }
        if (fila.dernier == 1)
            fila.dernier = TAILLE;
        else
            fila.dernier--;

        InicilisePiece (fila.Liste[fila.premier]);
        while ((fila.premier != fila.dernier)&&(fila.Liste[fila.premier].id == 0)) // verifier si taille infinie est petit;
        {
            fila.premier++;
            if (fila.premier > TAILLE)
                fila.premier = 1;
        }
        fila.fin = fila.fin - 2;
        Reveiller_Les_Machines(Mach1,Mach2,fila,DS);
        mach.Atendendo = atendendo;
        mach.DPE = DS + mach.DureeT;
        teste = mach.DPE;
    }
}

void Change_Gamme_Atendendo (Client &atendendo, int seq, double TempoArriveMac, double TempSortiMach)
{
    atendendo.GammeDernier.ListeEtape[seq].Station = seq;
    atendendo.GammeDernier.ListeEtape[seq].DateArrive = TempoArriveMac;
    atendendo.GammeDernier.ListeEtape[seq].DateSortie = TempSortiMach;
}

void ordreFilaFila3 (T_File& fila)
{
    if (Regle != 3)
        ordreFilaFila3Regle1et2 (fila, Regle);
    else
        if (fila.fin <= 4)
            ordreFilaFila3Regle1et2 (fila, 2);
        else
            ordreFilaFila3Regle1et2 (fila, 1);


}
void ordreFilaFila3Regle1et2 (T_File& fila, int regra)
{
    Client aux;
    int cont = 0;
    int contj = 0;
    int i = 0;
    int teste;
    int num = 1;
    int mult = 1;
    if (regra == 1)
        num = 2;
    else
    {
        num = 1;
        mult = -1;
    }

    i = fila.premier;
    for (int j =1; j <= fila.fin ; j++)
        {
            //teste = fila.Liste[i].GammeDernier.Etapes[1];
            teste = fila.Liste[i].id;
            if ((fila.Liste[i].GammeDernier.ListeEtape[1].Station == num)&&(cont ==0))
                {
                    aux = fila.Liste[i];
                    cont = i;
                    contj = j;
                        if (i == TAILLE)
                            i = 1;
                        else
                            i++;
                }
            else
                {
                if ((fila.Liste[i].GammeDernier.ListeEtape[1].Station == regra) && (cont !=0))
                    {
                        fila.Liste[cont] = fila.Liste[i];
                        fila.Liste[i] = aux;
                        i = cont;
                        j = contj-1;
                        cont = 0;
                    }
                else
                    {
                       if (i == TAILLE)
                            i = 1;
                        else
                            i++;
                    }
                }
          }
    int j = fila.premier;
    cont = 1;
    teste = fila.dernier;
    while (j != fila.dernier )
    {
        teste = fila.Liste[j].id;
        if (fila.Liste[j].GammeDernier.ListeEtape[1].Station == num)
        {
            contj = cont;
                i = j;
            while (contj <= fila.fin)
            {
                teste = fila.Liste[i].id;
                if( mult*fila.Liste[j].id < mult*fila.Liste[i].id)
                    {
                        aux = fila.Liste[j];
                        fila.Liste[j] = fila.Liste[i];
                        fila.Liste[i] = aux;
                    }
                    if ((i == TAILLE)&&(fila.dernier != TAILLE))
                        i = 1;
                    else
                        i++;
                    contj++;
            }

        }
        if (j == TAILLE)
            j = 1;
        else
            j++;
        cont ++;
    }
}
void Reveiller_Les_Machines(T_Machine &Mach1, T_Machine &Mach2, T_File&fila,double DS)
{
    if ((TYPE_SYSTEM == 0)&&(Regle !=4))
    {
        if ((Mach1.Etat == 2) && (Mach2.Etat == 2))
            Analyse_ReveillerMachine (Mach1, Mach2, DS, fila);
        else
        {
            if ((Mach1.Etat == 2) && (Mach2.Etat != 2))
                {
                    Mach1.Etat = 1;
                    Mach1.DPE = DS;
                }
            else
            {
                if ((Mach1.Etat != 2) && (Mach2.Etat == 2))
                {
                    Mach2.Etat = 1;
                    Mach2.DPE = DS;
                }
            }
        }
    }
    if ((TYPE_SYSTEM == 1)||(Regle == 4))
    {
        if (Mach1.Etat == 2)
            {
                Mach1.Etat = 1;
				Mach1.Atendendo.GammeDernier.ListeEtape[1].DateSortie = DS;
                Mach1.DPE = DS;
            }
        if (Mach2.Etat == 2)
            {
                Mach2.Etat = 1;
                Mach2.DPE = DS;
            }
    }

}
void Analyse_ReveillerMachine (T_Machine &Mach1, T_Machine &Mach2, double DS, T_File& fila)
{
    if (Regle ==1)
        {
            Mach1.Etat = 1;
            Mach1.DPE = DS;
        }
    else
        if (Regle ==2)
            {
                Mach2.Etat = 1;
                Mach2.DPE = DS;
            }
        else
            {
                if (fila.fin < 4)
                    {
                        Mach2.Etat = 1;
                        Mach2.DPE = DS;
                    }
                if (fila.fin >= 4)
                    {
                        Mach1.Etat = 1;
                        Mach1.DPE = DS;
                    }

            }
}
void FairePeice_MachineA (T_File& fila, T_Machine& mach, double ds,T_File& fila3, T_Machine& mach3, int numero, T_Machine& MachConc)
{
    if (FileVide (fila))
    {
        mach.DPE = GRANDE;
        if ((mach.Etat==1)&&(TYPE_SYSTEM!= 2)) // etat 1 = machine ocoupe
        {
            mach.Etat = 0; // analisar
			mach.Atendendo.GammeDernier.ListeEtape[1].DateSortie = ds;
            mach.Atendendo.GammeDernier.ListeEtape[2].Station = 3;
			mach.Atendendo.GammeDernier.ListeEtape[2].DateArrive = ds;
            AnaliseRegraEtMettreFila3 (mach, mach3, fila3, numero, ds,MachConc);
        }
		if ((TYPE_SYSTEM == 2)&&(mach.Etat==1))
		{
			mach.Etat = 2;
			if (mach3.Etat ==0)
				mach3.DPE = ds;
		}

    }
    else
    {
        if (mach.Etat == 0) // machine non-ocoupee
            {
                T_Gamme Gamme;
                IniciliseGamme(Gamme);

                mach.Etat = 1;
                mach.Atendendo = fila.Liste[fila.premier];
                if (fila.premier == TAILLE)
                    fila.premier = 1;
                else
                    fila.premier++;

                fila.fin --;

                Gamme.ListeEtape[1].Station = numero;
				Gamme.ListeEtape[1].DateArrive = mach.Atendendo.T_Arri_Syst;
                Gamme.ListeEtape[1].DateSortie = ds + mach.DureeT;

                mach.Atendendo.GammeDernier= Gamme;
                mach.DPE = ds + mach.DureeT; // alterar tempol de proximo evento
            }
        else
            {
                if ((mach.Etat == 2)||(TYPE_SYSTEM == 2))
				{
                    mach.DPE = GRANDE;
					mach.Etat = 2;
					if ((TYPE_SYSTEM == 2)&&(mach3.Etat ==0))
						mach3.DPE = ds;
				}
                else
                {
                    mach.Etat = 0; // analisar
                    mach.DPE = ds;
                    mach.Atendendo.GammeDernier.ListeEtape[1].DateSortie = ds;
					mach.Atendendo.GammeDernier.ListeEtape[2].Station = 3;
					mach.Atendendo.GammeDernier.ListeEtape[2].DateArrive = ds;
                    AnaliseRegraEtMettreFila3 (mach, mach3, fila3, numero, ds,MachConc);
                }

            }
    }
}
void AnaliseRegraEtMettreFila3 (T_Machine &mach, T_Machine &mach3, T_File& fila3,int numero, double ds, T_Machine& MachConc)
{
    int aux = 0;
    if (Regle == 3)
            {
             if ((numero ==1) && (fila3.fin < TAILLE) && ((fila3.fin >=4)||(MachConc.Etat != 2)))
                {
                        aux++;
                        MettreDansfila (fila3, mach.Atendendo);
                        InicilisePiece (mach.Atendendo);
                        if (mach3.Etat ==0)
                            mach3.DPE = ds;
                }
            else
                {
                   if ((fila3.fin < TAILLE) && ((fila3.fin <4)||(MachConc.Etat != 2)))
                    {
                        aux ++;
                        MettreDansfila (fila3, mach.Atendendo);
                        InicilisePiece (mach.Atendendo);
                        if (mach3.Etat ==0)
                            mach3.DPE = ds;
                    }
                }
            }

        else
            {
               if (fila3.fin < 8)
                {
                    aux ++;
                    MettreDansfila (fila3, mach.Atendendo);
                    InicilisePiece (mach.Atendendo);
                    if (mach3.Etat ==0)
                        mach3.DPE = ds;
                }
            }

    if (aux==0)
    {
       mach.Etat = 2; // bloque
       mach.DPE = GRANDE;
    }

}
void GererNouvellePiece (T_Entree& Entree, T_File& fila,double tempArrive, int seq)
{
    Client traitement;  // criar novo endereco
    InicilisePiece (traitement);
    traitement.id = seq;
    traitement.T_Arri_Syst = tempArrive;

    MettreDansfila (fila, traitement);

    Entree.DPE = tempArrive + Entree.DIA;
}
void MettreDansfilaSortie (T_FileSortie& fila, Client& atendendo)
{
    if (fila.ultimo == 0)
        {
            fila.ultimo = 1;
            fila.Liste[fila.ultimo] = atendendo;
            fila.qte = 1;
        }
    else
        {
            if (fila.ultimo == (TAILLEsortir-1))
            {
                cout << "\n[ERRO] Devez augmenter le TAILLEsortir, parce que il est trop petit";
                fila.Liste[fila.ultimo] = atendendo;
            }

            else
            {
                fila.ultimo++;
                fila.qte++;
                fila.Liste[fila.ultimo] = atendendo;
            }
        }

}
void MettreDansfila (T_File& fila, Client& atendendo)
{
        if (FileVide (fila))
        {
            fila.premier = 1;
            fila.dernier= 1;
            fila.Liste[fila.dernier] = atendendo;
            fila.fin ++;
        }
    else
        {
            if (fila.dernier == TAILLE)
                fila.dernier = 1;
            else
                fila.dernier++;
            fila.Liste[fila.dernier] = atendendo;
            fila.fin ++;
        }
}

int TrouverVLR (T_Entree& Entree1,T_Machine& Mach1,T_Machine& Mach2,T_Machine& Mach3, T_Entree& Entree2, double DS)
{
    int vlr = 0;

    if (DS == Mach3.DPE)
            vlr = 4;
    else
        if (DS == Mach2.DPE)
            vlr = 3;
        else
            if (DS == Mach1.DPE)
                vlr = 2;
            else
                if (DS == Entree1.DPE)
                    vlr = 1;
                else
                    if(DS == Entree2.DPE)
                        vlr = 5;
                    else
                        vlr = 6;

    return vlr;
}
double MenordeCinq (double a, double b, double c, double d, double e)
{
    double menor = a;
    if (b < menor)
        menor =b;
    if (c < menor)
        menor = c;
    if (d < menor)
        menor = d;
    if (e < menor)
        menor = e;

    return menor;
}
void InicilisePiece (T_Client& pc)
{
    pc.id = 0;
    pc.T_Arri_Syst = 0;
    IniciliseGamme (pc.GammeDernier);
}

void IniciliseMachine (T_Machine& Mach)
{
    InicilisePiece (Mach.Atendendo);
    Mach.Etat = 0; // se 1 est occupe, se 0 non, si 2 elle est bloquee;;
    Mach.DureeT = 0;
    Mach.DPE = GRANDE;
}
void IncialiseFileSortie (T_FileSortie& Fila)
{
    Fila.ultimo = 0;
    for (int i =0; i <=TAILLEsortir; i++)
        InicilisePiece(Fila.Liste[i]);
}
void IncialiseFile (T_File& Fila)
{
    Fila.fin = 0; // Definir quantidade de clientes na fila externa
    Fila.premier = 0; // Apontar para primeiro cliente
    Fila.dernier = 0;
    for (int i =0; i <=TAILLE; i++)
        InicilisePiece(Fila.Liste[i]);
}

void IniciliseGamme(T_Gamme& Gamme)
{
    for (int i =0; i <= N_Etapes; i++)
    {
        Gamme.ListeEtape[i].DateArrive = 0;
        Gamme.ListeEtape[i].Station = 0;
        Gamme.ListeEtape[i].DateSortie = 0;
    }

    Gamme.ProbQ = 0;
    Gamme.ProbP = 0;
    //Gamme.prox = NULL;
}

bool  FileVide (T_File& Fila)
{
    if (Fila.fin == 0)
        return true;
    else
        return false;
}

void IniciliseEntree (T_Entree& entre, double Arrive)
{
    entre.DIA = Arrive;
    entre.DPE= 0;
    //entre.Piece = NULL;
}

void InicializarSeries (Series^ Ent1, Series^ Ent2,Series^ Per1,Series^ Per2,Series^ Syst,Series^ Sta1,Series^ Sta2, Series^Sta3,Series^ Gamm1, Series^ Gamm2, Series^ Sort,Series^ Sta3_1,Series^ Sta3_2,Series^ Syst_1,Series^ Syst_2)
{
	InicialiseSerieDonneGeneraux (Ent1);
	Ent1->Name = L"Ent1";

	InicialiseSerieDonneGeneraux (Ent2);
	Ent2->Name = L"Ent2";

	InicialiseSerieDonneGeneraux (Per1);
	Per1->Name = L"Per1";

	InicialiseSerieDonneGeneraux (Per2);
	Per2->Name = L"Per2";

	InicialiseSerieDonneGeneraux (Syst);
	Syst->Name = L"Syst";

	InicialiseSerieDonneGeneraux (Sta1);	;
	Sta1->Name = L"Sta1";

	InicialiseSerieDonneGeneraux (Sta2);
	Sta2->Name = L"Sta2";

	InicialiseSerieDonneGeneraux (Sta3);
	Sta3->Name = L"Sta3";

	InicialiseSerieDonneGeneraux (Gamm1);
	Gamm1->Name = L"Gamm1";

	InicialiseSerieDonneGeneraux (Gamm2);
	Gamm2->Name = L"Gamm2";

	InicialiseSerieDonneGeneraux (Sort);
	Sort->Name = L"Sort";

	InicialiseSerieDonneGeneraux (Sta3_1);
	Sta3_1->Name = L"Sta3_1";

	InicialiseSerieDonneGeneraux (Sta3_2);
	Sta3_2->Name = L"Sta3_2";

	InicialiseSerieDonneGeneraux (Syst_1);
	Syst_1->Name = L"Syst_1";

	InicialiseSerieDonneGeneraux (Syst_2);
	Syst_2->Name = L"Syst_2";
}

void InicialiseSerieDonneGeneraux (Series^ series1)
{
	series1->Legend = L"Legend1";
	series1->ChartArea = L"ChartArea1";
	series1->ChartType = SeriesChartType::Spline;
}

void MettreCoordonne_en_Serie (Series^ serie, double X, double Y)
{
	DataPoint^  dataPoint;
	dataPoint = (gcnew DataPoint(X,Y));
	serie->Points->Add(dataPoint);
}
