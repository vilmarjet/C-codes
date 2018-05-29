
#include "head.h"

int main ()
{
//Declaration variavel
    Operation Op;
    Problem Prob;
    string nomes;
    Solution Solu;
    Vec_SolutionsRealized VecSolu;
    srand((unsigned)time(0)); // random seed

    int exe = 0;
    int aux = 0;
    int teste = 0;


// Read file entrada1.txt
    Lire("Example.txt",Op, Prob);      //file job durations
    cout<< "Jobs :-> Operations - durations: "<<endl;
    ImprimirMatriz (Prob);

    // Initialize solutions
    InicializaSolucao(Prob, Solu); // set a random initial solution
    InicializaSolutionsRealized (VecSolu);

    EvaluarSolution(Prob, Solu);
    Solu.coup = MTempo(Solu, Prob);
    aux = MTempo(Solu, Prob); // necessario chamar a segunda vez.
    cout << endl << "Iteration -> Makespan (Best Solution)";
    cout << endl;
    cout << exe<< " ->";
    cout << Solu.coup;
    exe++;


    for (; exe < REPETICAO; exe++)
   {
        MetodoGraspe (Prob, Solu); // Heuristic Grasp
        teste = MTempo(Solu, Prob);
        teste = Solu.signature;
        //aux = MTempo(Solu, Prob);
        if (Teste_Double (Solu, VecSolu) == 0)
                exe --; //cout << "-";
                //
        // Print New solution:
        // Print New solution:
        if (Solu.coup != aux)
        {
            cout << endl;
            cout << exe << " ->";
            cout << Solu.coup; // voltar para : "cout << Solu.coup"
            aux = Solu.coup;
        }
    }
    cout << endl << "******** End of Grasp  ******";
    cout << endl << "Best (Min) Makespan found : (" << Solu.coup << ")";

    Imprimir_CaminhoCritico_Final (Solu);           //Print Critical path
    Imprimir_MelhorSolution_Finalle ( Solu, Prob); //Print Best solution

    cin.get();

    return 0;
}
/******************************FIN DU MAIN ***************************************************************/

//This function is the Heuritice GRASP for job-shop
void MetodoGraspe (Problem& Prob, Solution& sol) // constructor
{
    Solution SolutioOpInicial;
    VectorSolution vectorValor;
    Solution VectorRCL;
    VectorSolution VectorInicial;

    int z = 0;
    int aux = 0;
    int job, aus;
    int aleatorio; //random


   // inicalizations
    VectorRCL.ordem = new Operation [Prob.QtProd];
    InicializaVectorSolution (Prob, VectorInicial); //random solution
    InicializaSolucao (Prob, SolutioOpInicial);
    InicializaVectorSolution (Prob, vectorValor);


    // construction du grasp
    for (int i=1; i <= (Prob.QtMach*Prob.QtProd); i++) // comecar a construir
    {
        z = 0;
        // inicializar vetor RCL
        for (int y= 0; y < Prob.QtProd; y++) // inicializa vetor RCL com valores zeros em operacao
            InicializaOperation (VectorRCL.ordem[y]);
        job = (Prob.QtMach*Prob.QtProd) + 1;
        for (int y= 1; y <= (Prob.QtMach*Prob.QtProd); y++)// Select all the candidates and put them in RCL list
        {
           if ((SolutioOpInicial.ordem[y].produit != job) && (y != ((Prob.QtMach*Prob.QtProd)+1)))
               if (SolutioOpInicial.ordem[y].produit != 0) // check if job was aready fixed
                {
                   VectorRCL.ordem[z] = SolutioOpInicial.ordem[y];
                   job = SolutioOpInicial.ordem[y].produit;
                   z++;
                }
        }

        ordernarVetorRCLBuble (VectorRCL, Prob); // Buble Method to rank RCL
        aux = 0;
        while ((VectorRCL.ordem[aux].seq != 0) && (aux <= Prob.QtProd)) //Number of candidates in RCL
            aux ++;

        aux--;
        if (aux == Prob.QtProd) aux --;

        aus = aux*ALPHA; //size of RCL that can be selected
        if (aus != 0)   aleatorio = (rand()% (aus)); // random selection of a element in RCL
        else            aleatorio = 0;

        if (aleatorio > aux) aleatorio = aux; // avoid getttin out of aux
        //aleatorio = 0;
        if (VectorRCL.ordem[aleatorio].seq == 0)
            cout << "erro";

        sol.ordem[i] = VectorRCL.ordem[aleatorio]; // put selected candidate in positition i of soluiton
        aus = 1;
        while (SolutioOpInicial.ordem[aus].seq != sol.ordem[i].seq) // procurar na solution incial a opercao
                aus ++;

        // Change initial time of  queu
        int seq = 1;
        int tempoFinal;
        if (SolutioOpInicial.ordem[aus].proxObri != ((Prob.QtMach*Prob.QtProd)+1))
            {
                job = SolutioOpInicial.ordem[aus].produit;
                SolutioOpInicial.ordem[aus].produit = 0;
                while (SolutioOpInicial.ordem[seq].produit != job) // pesquisar qual operacao tem mesmo job
                    {
                        seq ++;
                    }
                tempoFinal = (SolutioOpInicial.ordem[aus].MenTInicio + SolutioOpInicial.ordem[aus].duree);

                if (SolutioOpInicial.ordem[seq].MenTInicio <= tempoFinal)
                    {
                        SolutioOpInicial.ordem[seq].MenTInicio = tempoFinal;
                        SolutioOpInicial.ordem[seq].anterior = SolutioOpInicial.ordem[aus].seq;
                    }
                SolutioOpInicial.ordem[aus].produit = job;
            }

        // Mudar tempo de inicio da operacao que utiliza a mesma maquina na sequencia
       seq = 1;
        job = SolutioOpInicial.ordem[aus].produit;
        SolutioOpInicial.ordem[aus].produit = 0;
        tempoFinal = (SolutioOpInicial.ordem[aus].MenTInicio + SolutioOpInicial.ordem[aus].duree); // nao acredito!!
        int maq = SolutioOpInicial.ordem[aus].machine;
        for (int zed = 0; zed < Prob.QtProd; zed++)
        {
            while (((SolutioOpInicial.ordem[seq].machine != maq) || (SolutioOpInicial.ordem[seq].produit == 0)) && (seq < ((Prob.QtMach*Prob.QtProd) +1)))
                    seq++;

            if ((SolutioOpInicial.ordem[seq].MenTInicio <= tempoFinal) && (seq < (Prob.QtMach*Prob.QtProd) +1))
                {
                    SolutioOpInicial.ordem[seq].MenTInicio = tempoFinal;
                    SolutioOpInicial.ordem[seq].anterior = SolutioOpInicial.ordem[aus].seq;
                }
            seq ++;
        }// fim

        // eliminate chosen job from list of available jobs.
        SolutioOpInicial.ordem[aus].produit = 0;
    } //end of GRASP


    //Local Search
    RechercheLocal_Complet (Prob, sol, VectorInicial); // en tran de implementar... // jah faz evaluar

   // liberar espaco de memoria
    delete [] SolutioOpInicial.ordem;
    delete [] SolutioOpInicial.VectorMelhorResulta;
    delete [] vectorValor.vector;
    delete [] VectorRCL.CheminCritique;
    delete [] VectorRCL.ordem;
    delete [] VectorRCL.VectorMelhorResulta;
    delete [] VectorInicial.vector;



}//end of function

void ordernarVetorRCLBuble (Solution& VectorRCL, Problem & Prob)
{
    int con = 0;
    Operation aux;
    int tempfin1 = 0;
    int tempfin2 = 0;
    int teste ;
    // contagem da qutidade de elementos no vetor
    while ((VectorRCL.ordem[con].seq != 0) && (con < Prob.QtProd))
    {
       teste = VectorRCL.ordem[con].seq;
       teste = VectorRCL.ordem[con].anterior;
       con ++;
    }

    for (int i = 0; i < con; i ++)
    {
        for (int y = i+1; y < con; y++)
        {
            tempfin1 = VectorRCL.ordem[i].duree + VectorRCL.ordem[i].MenTInicio;
            tempfin2 = VectorRCL.ordem[y].duree + VectorRCL.ordem[y].MenTInicio;
            if (tempfin1 > tempfin2)
                {
                   aux = VectorRCL.ordem[i];
                   VectorRCL.ordem[i] = VectorRCL.ordem[y];
                   VectorRCL.ordem[y] =  aux;
                }

        }

    }


}

void RechercheLocal_Complet (Problem& Prob, Solution& sol, VectorSolution& vector) // O(n2)
{
    VectorSolution VectorInicial;
    VectorSolution VectorTeste;

    InicializaVectorSolution (Prob, VectorInicial);
    InicializaVectorSolution (Prob, VectorTeste);

   // int z = sol.coup;
    int teste =  0;
    int aux = 0;
    int Maximo = sol.coup;

    for (int i=1; i <= (Prob.QtMach*Prob.QtProd); i++) // vetor inicial recebe jobs segundo vetor solucao
        VectorInicial.vector[i] = sol.ordem[i].produit;

    for (int i=1; i <= (Prob.QtMach*Prob.QtProd); i++) // debut de mudancas
    {
         for (int y=i; y < (Prob.QtMach*Prob.QtProd); y++)
        {
            for (int z=1; z <= (Prob.QtMach*Prob.QtProd); z++)
                    VectorTeste.vector[z] = VectorInicial.vector[z];
            teste = sol.coup;
            // swap
            aux = VectorTeste.vector[i];
            VectorTeste.vector[i] = VectorTeste.vector[y+1];
            VectorTeste.vector[y+1] = aux;
            if (VectorTeste.vector[i] != VectorTeste.vector[y+1]) // se nao sao do mesmo job
                {
                    // ver se sol.coup mudou
                    PreencheSoluctionAvecVector(VectorTeste, Prob, sol);
                    EvaluarSolution (Prob, sol);

                    if (teste != sol.coup) // se nao teve melhora no resultado voltar para o melhor voisin
                        {
                            for (int z = 1; z <= (Prob.QtMach*Prob.QtProd); z++)
                            vector.vector[z] = VectorTeste.vector[z]; // doidera
                        }
                }
        }
    }
        // preencher com melhor solucao
        if (Maximo != sol.coup)
        {
            PreencheSoluctionAvecVector(vector, Prob, sol);
            EvaluarSolution (Prob, sol);
        }
        else
        {
            PreencheSoluctionAvecVector(VectorInicial, Prob, sol);
            EvaluarSolution (Prob, sol);
        }

    delete [] VectorInicial.vector;
    delete [] VectorTeste.vector;

}
void PreencheSoluctionAvecVector(VectorSolution& vectorValor2, Problem & Prob, Solution & sol)
{
    Solution SolutioOpInicial;


    InicializaSolucao (Prob, SolutioOpInicial);

     for (int i = 1; i <= (Prob.QtMach*Prob.QtProd); i++)
    {
        int w = 1;
        int z = vectorValor2.vector[i];
        while (SolutioOpInicial.ordem[w].produit != z)
        {
            w ++;
        }
        sol.ordem[i] = SolutioOpInicial.ordem[w];
        SolutioOpInicial.ordem[w].produit = 0;
    }

    // liberar memoria
    delete [] SolutioOpInicial.CheminCritique;
    delete [] SolutioOpInicial.ordem;
    delete [] SolutioOpInicial.VectorMelhorResulta;
}
void InicializaSolutionsRealized (Vec_SolutionsRealized& vs)
{
    vs.solucao = new int [REPETICAO];
    vs.ultimo = 0;

    for (int i=0; i < REPETICAO; i++) // inicializar com zero em todos os vetores
        vs.solucao[i] = 0;
}

void InicializaVectorSolution (Problem& Prob, VectorSolution& vetor)
{
    vetor.vector = new int [(Prob.QtMach*Prob.QtProd)+1];
    for (int i=1; i <= (Prob.QtMach*Prob.QtProd); i++)
        vetor.vector[i] = 0;
}

void InicializaOperation(Operation& op)
{
    op.seq = 0;
    op.machine = 0;
    op.duree = 0;
    op.produit = 0;
    op.proxObri = 0;
    op.anterior = 0;
    op.MenTInicio = 0;
}
void ZerarChemin(Solution& sol, Problem& Prob)
{
    for (int i=1; i <= (Prob.QtMach*Prob.QtProd); i++)
        sol.CheminCritique[i] = 0;
}

void InicializaSolucao (Problem & Prob, Solution & sol)
{
    sol.ordem = new Operation [(Prob.QtMach*Prob.QtProd)+1]; // alocacao de memoria
    sol.CheminCritique = new int [(Prob.QtMach*Prob.QtProd)+1];
    sol.VectorMelhorResulta = new Operation [(Prob.QtMach*Prob.QtProd)+1];

    sol.cont = (Prob.QtMach*Prob.QtProd)+1; // combien operacion plus 1
    sol.coup = 0;
    sol.signature = 0;
    for (int i=1; i <= (Prob.QtMach*Prob.QtProd); i++) // inicializa os processos en solution
        InicializaOperation(sol.ordem[i]);
    for (int i=1; i <= (Prob.QtMach*Prob.QtProd); i++) // valor debut des processos
        sol.ordem[i] = Prob.AllOperation[i];
    ZerarChemin(sol, Prob);


}



/*******************LIRE AFFICHIER ***********************/
void Lire(char* nome, Operation & Op, Problem & Prob)
{
    int w = 1;
    ifstream Myfile (nome, ios :: in);
    // pega
    Myfile >> Prob.QtProd;
    Myfile >> Prob.QtMach;

     // faze a colocarao do produito da operacao
    Prob.AllOperation = new Operation [(Prob.QtMach*Prob.QtProd)+1]; // iniciar a contagem em 1 nao em 0

    for (int i=1; i <= (Prob.QtMach*Prob.QtProd); i++) // Commencer de 1 pas de 0
    {
        InicializaOperation (Prob.AllOperation[i]);
        //Il va prendre donée du affichier
        Myfile >> Prob.AllOperation[i].machine;
        Myfile >> Prob.AllOperation[i].duree;
        // doner seq de les operrations
        Prob.AllOperation[i].seq = i;

        // ce fait la liaison obligatoire - proximo obrigatorio e colocar produit
            if (i % Prob.QtMach != 0)
            {
                Prob.AllOperation[i].proxObri = i + 1;
                Prob.AllOperation[i].produit = w;
            }

            else
            {
                Prob.AllOperation[i].produit = w;
                Prob.AllOperation[i].proxObri = (Prob.QtMach*Prob.QtProd)+1; // ultimo da fila aponta para o termino
                w++;
            }


            // colocar os antecessores da fila obrigatoria
            if (i % Prob.QtMach != 1)
                {
                    Prob.AllOperation[i].anterior = i - 1;
                    Prob.AllOperation[i].MenTInicio = (Prob.AllOperation[i-1].duree + Prob.AllOperation[i-1].MenTInicio);
                }

            else
                Prob.AllOperation[i].anterior = 0; // ultimo da fila aponta para o termino
    }

}

void LirePremiereSoluction (char* nome, Problem & Prob, Solution & sol )
{
    int* vectorValor2;
    Solution SolutioOpInicial;
    ifstream Myfile (nome, ios :: in);


    vectorValor2 = new int [(Prob.QtMach*Prob.QtProd)+1];
    InicializaSolucao (Prob, SolutioOpInicial);

    for (int i = 1; i <= (Prob.QtMach*Prob.QtProd); i++)
         Myfile >> vectorValor2[i];


    for (int i = 1; i <= (Prob.QtMach*Prob.QtProd); i++)
    {
        int w = 1;
        int z = vectorValor2[i];
        while (SolutioOpInicial.ordem[w].produit != z)
        {
            w ++;
        }
        sol.ordem[i] = SolutioOpInicial.ordem[w];
        SolutioOpInicial.ordem[w].produit = 0;
    }
    //liberar espaco memoria
    delete [] SolutioOpInicial.CheminCritique;
    delete [] SolutioOpInicial.ordem;
    delete [] SolutioOpInicial.VectorMelhorResulta;
}

/**************************DEBUT DES FUNCTIONS POUR MODIFIER LA SOLUCTION DE JOB-SHOP************/
// CETTE FUNCTION CHANGERA LES VALUAR DE
void Tempo_Inicio_fila_Obrigatoria2 (Solution& sol, int &aux, Problem & Prob)
{
    int z = aux;
    int w = z+1;

    while (w < (Prob.QtMach*Prob.QtProd)+1)
    {
        if (sol.ordem[z].proxObri == sol.ordem[w].seq)
        {
            if ((sol.ordem[z].duree + sol.ordem[z].MenTInicio)>= sol.ordem[w].MenTInicio)
            {
                 sol.ordem[w].MenTInicio = (sol.ordem[z].duree + sol.ordem[z].MenTInicio);
                sol.ordem[w].anterior = sol.ordem[z].seq;
                z = w;
                w++;
            }
            else
            {
                w++;
            }
        }
        else
        {
            w++;
        }


    }
}

void Muda_Tempo_Proxima_machine(Solution& sol, int &aux, Problem & Prob ) // acha maquina mais proxima na sequencia
{
    if (aux == (Prob.QtMach*Prob.QtProd)+1)
        return;
    else
    {
        int z;
        z = aux+1;
        while ( (sol.ordem[aux].machine != sol.ordem[z].machine)&& (z != (Prob.QtMach*Prob.QtProd)+1)) // procurar se tem operacao
        {                                                                                   // com mesma maquina mais pra frente
            z++;
        }
        if (z == (Prob.QtMach*Prob.QtProd)+1) return ;
        else
        {
            if ((sol.ordem[aux].MenTInicio + sol.ordem[aux].duree) > sol.ordem[z].MenTInicio) //
            {
                sol.ordem[z].MenTInicio = (sol.ordem[aux].MenTInicio + sol.ordem[aux].duree);
                sol.ordem[z].anterior = sol.ordem[aux].seq;
            }

        }

    }
}


void EvaluarSolution (Problem & Prob,Solution & sol)
{
    int z;
    for (int i=1; i <= (Prob.QtMach*Prob.QtProd); i++)
    {
        Tempo_Inicio_fila_Obrigatoria2 (sol, i, Prob) ;
        Muda_Tempo_Proxima_machine(sol, i, Prob );
    }

    z = MTempo(sol, Prob);

}

void FazerChemincritique (int maior, Solution& sol, Problem& Prob)
{
    ZerarChemin(sol, Prob);

    int ceq = 1;
    int z = 0;
    while (maior != (sol.ordem[ceq].MenTInicio + sol.ordem[ceq].duree))
    {
            ceq ++;
    }

    while (ceq != 0)
    {

        sol.CheminCritique[z] =  sol.ordem[ceq].seq ;
        z++;
        if (sol.ordem[ceq].anterior != 0)
        {
            for (int i = 1; i<= (Prob.QtMach*Prob.QtProd); i++)
            {
                if (sol.ordem[i].seq == sol.ordem[ceq].anterior)
                    ceq = i;
            }
        }
        else ceq = 0;
    }

}


// CETTE FUNCTION CHERCHE LE CHEMIN PLUS GRAND EH DONNER COMME RESULTA CETTE VALUAR
int MTempo(Solution& sol, Problem & Prob)
{
    int maior = 0;
    int signat = 0;
    int aux = 0;
    int teste = 0;
    for (int i = 1; i<= (Prob.QtMach*Prob.QtProd); i++)
    {
       if (maior <= (sol.ordem[i].MenTInicio + sol.ordem[i].duree))
            maior = sol.ordem[i].MenTInicio + sol.ordem[i].duree;
        aux = sol.ordem[i].MenTInicio + sol.ordem[i].duree;
        signat = signat + (aux*aux);
    }
    teste = signat;
    aux = CONSTANT;
   // if (CONSTANT < REPETICAO)
     //    aux = REPETICAO;

    sol.signature = signat % aux;

    // achar o maior:
    int ceq = 1;
    while (maior != (sol.ordem[ceq].MenTInicio + sol.ordem[ceq].duree)) // selecionar maior valor = temp d caminha critio
    {
            ceq ++;
    }
// modifier plus grand valuar de soluction
    if ((sol.coup >= (sol.ordem[ceq].MenTInicio + sol.ordem[ceq].duree)) || (sol.coup == 0))
    {
        sol.coup = (sol.ordem[ceq].MenTInicio + sol.ordem[ceq].duree);
        FazerChemincritique (sol.coup,sol, Prob);
        for (int i = 1; i<= (Prob.QtMach*Prob.QtProd); i++)
            sol.VectorMelhorResulta[i] = sol.ordem[i];
    }

    return (sol.ordem[ceq].MenTInicio + sol.ordem[ceq].duree); // "maior" nao tava dando para colocar aki ... logo foi unico jeito
}


// suprimer les chemins que deja etais utilise retorna 1 se ok e 0 se encontrou outra solucao igual a proposta
int Teste_Double (Solution & sol, Vec_SolutionsRealized & VecSolu)
{
    int aux = 0;

    for (int i = 0; i <= VecSolu.ultimo; i++) // VecSolu.ultimo inicia em zero
        {
            if (sol.signature == VecSolu.solucao[i]) // se igual retorna
                    return 0;

            else aux ++;
        }
    if (aux == (VecSolu.ultimo + 1))
        {
            VecSolu.solucao [VecSolu.ultimo] = sol.signature;
            VecSolu.ultimo++;
            return 1;
        }
    else
    {
        cout << "Erro no Teste-double";
        return 0;
    }


}

// CREE FUNCTIONS RANDONICAS
void PlusSolutionsRandom (Problem & Prob,Solution & sol, Vec_SolutionsRealized & VecSolu)
{
    Solution SolutioOpInicial;
    VectorSolution vectorValor;
    int* vectorValor2;
    int aleatorio;
    int aus = (Prob.QtMach*Prob.QtProd); // pensamentos bons


    InicializaVectorSolution (Prob, vectorValor);
    //vectorValor = new int [(Prob.QtMach*Prob.QtProd)+1];
    vectorValor2 = new int [(Prob.QtMach*Prob.QtProd)+1];
    InicializaSolucao (Prob, SolutioOpInicial);

    // preencher vetor com dados da solucao
    for (int i = 1; i<= (Prob.QtMach*Prob.QtProd); i++)
        vectorValor.vector[i] = sol.ordem[i].produit; // preencher ordem do produit da ultima solucao


    // gerar vector aleatorio dos processos de producao
    srand((unsigned)time(0));
    aleatorio = (rand()% (aus))+1; // gerar random de 1 ate qtidade de operacoes

        // modifica vetor colocando tudo como aleatorio
        for (int i = 1; i<= (Prob.QtMach*Prob.QtProd); i++) // MODIFIQUER LE VECTOR
        {
            if (vectorValor.vector[aleatorio] != 0)
            {
                vectorValor2[i] = vectorValor.vector[aleatorio];
                vectorValor.vector[aleatorio] = vectorValor.vector[aus];
                aus--;
            }
            if (aus != 0)
                aleatorio = (rand()% aus)+1;
            else
                aleatorio = 1;
        }

        for (int i = 1; i<= (Prob.QtMach*Prob.QtProd); i++)
            vectorValor.vector[i] = vectorValor2[i];


       // z = Teste_Double ( Prob, sol, VecSolu, vectorValor );
    //}



    // gerar a solucao
    for (int i = 1; i <= (Prob.QtMach*Prob.QtProd); i++)
    {
        int w = 1;
        int z = vectorValor2[i];
        while (SolutioOpInicial.ordem[w].produit != z)
        {
            w ++;
        }
        sol.ordem[i] = SolutioOpInicial.ordem[w];
        SolutioOpInicial.ordem[w].produit = 0;
    }

    delete [] SolutioOpInicial.CheminCritique;
    delete [] SolutioOpInicial.ordem;
    delete [] SolutioOpInicial.VectorMelhorResulta;
    delete [] vectorValor.vector;

}

/********************************** IMPRESSOES ************************/

void ImprimirMatriz (Problem & Prob)
{
    int j = 1;
    cout << "Job_"<< j << " :-> ";
    for (int i=1; i <= (Prob.QtMach*Prob.QtProd); i++)
    {

        cout  << Prob.AllOperation[i].seq << "-";
        cout << Prob.AllOperation[i].duree<< " ";
        if (i % Prob.QtMach == 0)
        {
            cout << endl;
            if (j < Prob.QtProd)
            {
                j++;
                cout << "Job_"<< j << " :-> ";
            }
        }

    }

}

void ImprimirCaminhoCriticoCadaResultado(int & maior, Solution& sol, Problem & Prob)
{
    cout << "Critical Path: ";
    int ceq = 1;
    while (maior != (sol.ordem[ceq].MenTInicio + sol.ordem[ceq].duree))
    {
            ceq ++;
    }

    while (ceq != 0)
    {
        cout << "-" << sol.ordem[ceq].seq ;
        if (sol.ordem[ceq].anterior != 0)
        {
            for (int i = 1; i<= (Prob.QtMach*Prob.QtProd); i++)
            {
                if (sol.ordem[i].seq == sol.ordem[ceq].anterior)
                    ceq = i;
            }
        }
        else ceq = 0;
    }

}

void Imprimir_CaminhoCritico_Final (Solution& sol)
{
    int z = 0;
    cout << endl << endl ;
    cout << "Critical path of our best feasible solution: ";
    while (sol.CheminCritique[z] != 0)
    {
        cout << " - "<< sol.CheminCritique[z] ;
        z++;
    }
}

void Imprimir_MelhorSolution_Finalle (Solution& sol, Problem& Prob)
{
        int z = 0;
    cout << endl << endl ;
    cout << "Order of operations: ";
    for (int i = 1; i<= (Prob.QtMach*Prob.QtProd); i++)
    {
        cout << " - " << sol.VectorMelhorResulta[i].seq;
        z++;
    }
}



