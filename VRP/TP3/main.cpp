#include "stdafx.h"
#include "head.h"

using namespace std;

int NT; //nombre de sommets de la instance
double alpha; //paramètre du coût pour le nombre de tournées
double beta; //paramètre du coût pour la kilométrage
int IntMAX; //nombre d'itérations génétiques
double ep = 0.001; //pour comparer les chiffres réels

void lire_instance(T_instance &instance, String^ nom){

    float xl;
    float yl;
    float xc;
    float yc;
    ifstream fichier;
    pin_ptr<const wchar_t> nome = PtrToStringChars(nom);
	fichier.open(nome);
    fichier >> instance.capacite;
    fichier >> instance.N;
    NT = instance.N;
    for (int i=1 ; i<=instance.N; i++){
        fichier >>xl;
        fichier >>instance.Liste[i].x;
        fichier >>instance.Liste[i].y;
        fichier >>instance.Liste[i].demande;
        fichier >>instance.Liste[i].date_tot;
        fichier >>instance.Liste[i].date_tard;
        fichier >>instance.Liste[i].duree;
    }
    for (int i = 1; i <= instance.N; i++){
        xl = instance.Liste[i].x;
        yl = instance.Liste[i].y;
        for (int j = 1; j <= instance.N; j++){
            xc = instance.Liste[j].x;
            yc = instance.Liste[j].y;
            instance.distance[i][j] = sqrt(((xl-xc)*(xl-xc)) + ((yl-yc)*(yl-yc)));
        }
    }
}

//génère un vecteur de l'ordre totalement aléatoire
void generer_ordre_aleatoire(T_solution &solution){
    int disp[n_max];
    int k = 1;
    int sort;

    for (int i=2; i<= NT; i++){
        disp[i]=1;
    }
    while(k<NT){
        sort = (rand()%(NT-1))+2;
        if(disp[sort]==1){
            solution.ordre[k].seq =  sort;
            disp[sort] = 0;
            k ++;
        }
    }
}

//génère un vecteur de l'ordre basée sur le methode du plus proche voisin avec une petite aléatoire
void generer_ordre_distance(T_instance &instance, T_solution &solution){
    float c[n_max];
    int c_ordre[n_max];
    int disp[n_max];
    int actuel= 1;
    int find;
    int find2;
    int fin;
    int k = 1;
    int sort;
    int disponible = instance.N - 1;
    int a;
    for (int i=2; i<= instance.N; i++){
        disp[i]=1;
    }
    disp[1] = 0;

    while(k<instance.N){
        a=1;
        find2 = 0;
        fin = 1;
        c[1]=9999;
        c_ordre[1]=1;
        for(int i = 2; i<=instance.N; i++){
            find = 0;
            if(disp[i]==1 && i != actuel){
            c[i]= instance.distance[actuel][i];
            }
            else{c[i] = 9999;}
            for(int j=1; j<=fin; j++){
                if(c[i]<=c[c_ordre[j]]+ep){
                    for(int l = fin; l>=j; l--){
                        c_ordre[l+1] = c_ordre[l];
                    }
                    c_ordre[j] = i;
                    fin = fin + 1;
                    j = fin+1;
                    find = 1;
                }
            }
            if(find=!1){
                c_ordre[fin+1]=i;
                fin = fin + 1;
            }
        }
        while(find2==0){
            sort = (rand()%10);
            if(sort < 8){ //Une probabilité de 80% pour choisir chaque sommet mudar para 8 depois 
                actuel=c_ordre[a];
                solution.ordre[k].seq = actuel;
                disponible = disponible - 1;
                k = k+1;
                disp[actuel] = 0;
                find2 = 1;
            }
            else{
                if(a < disponible){ a++;}
                else{a =1;}
            }
        }
    }
}
//reçoit un vecteur de ordre,  et met les sommets dans les tournées
void generer_sol(T_solution &solution, T_instance &instance, int type){
    if(type == 1){
        generer_ordre_distance(instance, solution);
    }
    else if(type == 2){
        generer_ordre_aleatoire(solution);
    }

    int alloue = 1;
    int insere;
    int y;
    solution.qteToune = 1;
    solution.Km_total = 0;
    initialiser_tourne(instance, solution);
    while(alloue < instance.N){
        insere = 0;
        insere = insertion(instance, solution, solution.qteToune, solution.ordre[alloue].seq);
        if(insere == 0){
            solution.qteToune= solution.qteToune + 1;
            solution.ordre[alloue].tourne = solution.qteToune;
            new_tourne(instance, solution, solution.ordre[alloue].seq);
            solution.Tournees[solution.qteToune].Km = instance.distance[1][solution.ordre[alloue].seq]+ instance.distance[solution.ordre[alloue].seq][1];
            solution.Tournees[solution.qteToune].capacite = instance.Liste[solution.ordre[alloue].seq].demande;
            alloue = alloue + 1;
        }
        else{
            solution.ordre[alloue].tourne = solution.qteToune;
            y = solution.Tournees[solution.qteToune].qte;
            solution.Tournees[solution.qteToune].Liste[y].seq = solution.ordre[alloue].seq;
            solution.Tournees[solution.qteToune].Liste[y].arrive = solution.Tournees[solution.qteToune].Liste[y-1].fin + instance.distance[solution.Tournees[solution.qteToune].Liste[y-1].seq][solution.ordre[alloue].seq];
            solution.Tournees[solution.qteToune].Liste[y].debut = (solution.Tournees[solution.qteToune].Liste[y].arrive>instance.Liste[solution.ordre[alloue].seq].date_tot) ? solution.Tournees[solution.qteToune].Liste[y].arrive : instance.Liste[solution.ordre[alloue].seq].date_tot;
            solution.Tournees[solution.qteToune].Liste[y].fin = solution.Tournees[solution.qteToune].Liste[y].debut + instance.Liste[solution.ordre[alloue].seq].duree;
            solution.Tournees[solution.qteToune].Liste[y].folga = instance.Liste[solution.ordre[alloue].seq].date_tard - solution.Tournees[solution.qteToune].Liste[y].arrive;
            solution.Tournees[solution.qteToune].Liste[y+1].seq = 1;
			solution.Tournees[solution.qteToune].Liste[y+1].arrive = solution.Tournees[solution.qteToune].Liste[y].fin + instance.distance[solution.Tournees[solution.qteToune].Liste[y].seq][1];
            solution.Tournees[solution.qteToune].Liste[y+1].debut = solution.Tournees[solution.qteToune].Liste[y+1].arrive;
            solution.Tournees[solution.qteToune].Liste[y+1].fin = solution.Tournees[solution.qteToune].Liste[y+1].arrive;
            solution.Tournees[solution.qteToune].Liste[y+1].folga = instance.Liste[1].date_tard - solution.Tournees[solution.qteToune].Liste[y+1].arrive;
            for(int l = solution.Tournees[solution.qteToune].qte + 1; l>1; l--){
                if(solution.Tournees[solution.qteToune].Liste[l].folga<solution.Tournees[solution.qteToune].Liste[l-1].folga){
                    solution.Tournees[solution.qteToune].Liste[l-1].folga = solution.Tournees[solution.qteToune].Liste[l].folga;
                }
            }
        solution.Tournees[solution.qteToune].Km = solution.Tournees[solution.qteToune].Km - instance.distance[solution.Tournees[solution.qteToune].Liste[y-1].seq][1] + instance.distance[solution.Tournees[solution.qteToune].Liste[y-1].seq][solution.ordre[alloue].seq] + instance.distance[solution.ordre[alloue].seq][1];
        solution.Tournees[solution.qteToune].capacite = solution.Tournees[solution.qteToune].capacite + instance.Liste[solution.ordre[alloue].seq].demande;
        alloue = alloue + 1;
        solution.Tournees[solution.qteToune].qte = solution.Tournees[solution.qteToune].qte + 1;
        }
    }
    for(int j = 1; j<=solution.qteToune; j++){
            solution.Km_total = solution.Km_total + solution.Tournees[j].Km;
    }
    solution.cout = alpha*solution.qteToune + beta*solution.Km_total; //le calcul du coût en fonction des paramètres d'entrée alpha e beta
}

//vérifier la possibilité de inserér un nouveau sommets dans la tournée
int insertion(T_instance &instance, T_solution &solution, int tournee, int sommet){

    int insere = 0;
    int i= tournee;
    int j = sommet;
    int l = solution.Tournees[i].qte;
    float debut_j, arrive_pos;

    if(solution.Tournees[i].capacite + instance.Liste[j].demande <= instance.capacite + ep){
        debut_j= (instance.Liste[j].date_tot > (solution.Tournees[i].Liste[l-1].fin + instance.distance[solution.Tournees[i].Liste[l-1].seq][j])) ? instance.Liste[j].date_tot : (solution.Tournees[i].Liste[l-1].fin + instance.distance[solution.Tournees[i].Liste[l-1].seq][j]);
        arrive_pos =debut_j + instance.Liste[j].duree + instance.distance[j][solution.Tournees[i].Liste[l].seq];
        if((solution.Tournees[i].Liste[l].folga + ep >= arrive_pos - solution.Tournees[i].Liste[l].arrive) && (debut_j<= instance.Liste[j].date_tard)){
            insere = 1;
        }
    }
    return insere;
}

//générer une solution basée sur la méthode de Clarke & Wright
void generer_sol_CW(T_solution &solution, T_instance &instance){

    int k = 1;
    int w;
    T_gain temp;
    T_gain gain[n_max*n_max];
    gain[1].g = 0;

    for (int i = 2; i<=NT; i++){
        for(int j=2; j<=NT; j++){
            if(i!=j){
                gain[k].sommet1 = i;
                gain[k].sommet2 = j;
                gain[k].g = instance.distance[i][1]+ instance.distance[1][j] - instance.distance[i][j];
                w = k -1;
                while(w >0 && gain[k].g + ep > gain[w].g){
                    w --;
                }
                copie_gain(temp,gain[k]);
                for(int l = k; l>=w+2; l--){
                    copie_gain(gain[l], gain[l-1]);
                }
                copie_gain(gain[w+1], temp);
                k++;
            }
        }
    }
    solution.qteToune = 0;
    solution.Km_total = 0;

    for(int i=2; i<=NT; i++){
        solution.qteToune ++;
        new_tourne(instance, solution, i);
        solution.Tournees[solution.qteToune].Km = instance.distance[1][i]+ instance.distance[i][1];
        solution.Tournees[solution.qteToune].capacite = instance.Liste[i].demande;
    }
    int sort;
    int insere;
    int utilise[n_max*n_max];
    int util = 0;
    for(int i =1; i<k; i++){
        utilise[i] = 0;
    }
    while(util != (k-1)){
        for(int i = 1; i<k; i++){
            sort = (rand()%10);
            if(sort < 8 && utilise[i]==0){ //Une probabilité de 80% pour choisir chaque gain 
                for(int j=1; j<=solution.qteToune; j++){
                    if(solution.Tournees[j].Liste[2].seq == gain[i].sommet2 && solution.Tournees[j].qte != 0){
                        for(int l=1; l<=solution.qteToune; l++){
                            if(solution.Tournees[l].Liste[solution.Tournees[l].qte-1].seq==gain[i].sommet1 && solution.Tournees[l].qte!=0){
                                insere = tester_insertion(instance, solution, j, l);
                                if(insere == 1){fusionner_tournee(instance, solution, j, l);}
                                l = solution.qteToune + 1;
                            }
                        }
                    j = solution.qteToune + 1;
                    }
                }
                utilise[i] = 1;
                util++;
                if(util == k-1){i = k+1;}
            }
        }
    }

    T_solution temp_sol;
    temp_sol.Km_total = 0;
    int b = 1;
    int a = 1;
    for(int i=1; i<=solution.qteToune; i++){
        if (solution.Tournees[i].qte != 0){
			temp_sol.Tournees[b].qte = solution.Tournees[i].qte; 
			temp_sol.Tournees[b].capacite = solution.Tournees[i].capacite;
            temp_sol.Tournees[b].Km = solution.Tournees[i].Km;
            temp_sol.Km_total = temp_sol.Km_total + temp_sol.Tournees[b].Km;
            for(int j = 1; j<=solution.Tournees[i].qte ; j++){
                temp_sol.Tournees[b].Liste[j].arrive = solution.Tournees[i].Liste[j].arrive;
                temp_sol.Tournees[b].Liste[j].debut = solution.Tournees[i].Liste[j].debut;
                temp_sol.Tournees[b].Liste[j].fin = solution.Tournees[i].Liste[j].fin;
                temp_sol.Tournees[b].Liste[j].folga = solution.Tournees[i].Liste[j].folga;
                temp_sol.Tournees[b].Liste[j].seq = solution.Tournees[i].Liste[j].seq;
                if(temp_sol.Tournees[b].Liste[j].seq != 1){
                    temp_sol.ordre[a].seq = temp_sol.Tournees[b].Liste[j].seq;
                    temp_sol.ordre[a].tourne = b;
                    a++;
                }
            }
        b++;
        }
    }
    temp_sol.qteToune = b-1;
    copie_solution(solution, temp_sol);
    solution.cout = alpha*solution.qteToune + beta*solution.Km_total; //le calcul du coût en fonction des paramètres d'entrée alpha e beta
}

//vérifier la possibilité de fusion de deux tournées
int tester_insertion(T_instance &instance, T_solution &solution, int tournee1, int tournee2){
    float debut_j, arrive_pos;
    int k=2;
    int j = solution.Tournees[tournee2].Liste[k].seq;
    int l = solution.Tournees[tournee1].qte;
    int insere = 1;
    float fin_ant = solution.Tournees[tournee1].Liste[l-1].fin;
    int ant = solution.Tournees[tournee1].Liste[l-1].seq;
    float folga_pos = solution.Tournees[tournee1].Liste[l].folga;
    float dernier_arrive = solution.Tournees[tournee1].Liste[l].arrive;

    if(solution.Tournees[tournee1].capacite + solution.Tournees[tournee2].capacite + ep <= instance.capacite){
        while(insere == 1 && k<= solution.Tournees[tournee2].qte - 1){
            debut_j= (instance.Liste[j].date_tot > (fin_ant + instance.distance[ant][j])) ? instance.Liste[j].date_tot : (fin_ant + instance.distance[ant][j]);
            arrive_pos =debut_j + instance.Liste[j].duree + instance.distance[j][1];
            if((folga_pos >= arrive_pos - dernier_arrive + ep) && (debut_j + ep<= instance.Liste[j].date_tard)){
                fin_ant = debut_j + instance.Liste[j].duree;
                ant = j;
                folga_pos = instance.Liste[1].date_tard - arrive_pos;
                dernier_arrive = arrive_pos;
                insere = 1;
                k++;
            }
            else{insere = 0;}
        }
    }
	else{insere = 0;}
    return insere;
}

//fusionner deux tournées
void fusionner_tournee(T_instance &instance, T_solution &solution, int tournee1, int tournee2){
     int n_seq;
     int y;
     for(int i = 2; i<=solution.Tournees[tournee2].qte-1; i++){
        n_seq  = solution.Tournees[tournee2].Liste[i].seq;
        y = solution.Tournees[tournee1].qte;
        solution.Tournees[tournee1].Liste[y].seq = n_seq;
        solution.Tournees[tournee1].Liste[y].arrive = solution.Tournees[tournee1].Liste[y-1].fin + instance.distance[solution.Tournees[tournee1].Liste[y-1].seq][n_seq];
        solution.Tournees[tournee1].Liste[y].debut = (solution.Tournees[tournee1].Liste[y].arrive>instance.Liste[n_seq].date_tot) ? solution.Tournees[tournee1].Liste[y].arrive : instance.Liste[n_seq].date_tot;
        solution.Tournees[tournee1].Liste[y].fin = solution.Tournees[tournee1].Liste[y].debut + instance.Liste[n_seq].duree;
        solution.Tournees[tournee1].Liste[y].folga = instance.Liste[n_seq].date_tard - solution.Tournees[tournee1].Liste[y].arrive;

        solution.Tournees[tournee1].Km = solution.Tournees[tournee1].Km - instance.distance[solution.Tournees[tournee1].Liste[y-1].seq][1] + instance.distance[solution.Tournees[tournee1].Liste[y-1].seq][n_seq] + instance.distance[n_seq][1];
        solution.Tournees[tournee1].capacite = solution.Tournees[tournee1].capacite + instance.Liste[n_seq].demande;
        solution.Tournees[tournee1].qte++;
    }
    y = solution.Tournees[tournee1].qte;
    solution.Tournees[tournee1].Liste[y].seq = 1;
    solution.Tournees[tournee1].Liste[y].arrive = solution.Tournees[tournee1].Liste[y-1].fin + instance.distance[solution.Tournees[tournee1].Liste[y-1].seq][1];
    solution.Tournees[tournee1].Liste[y].debut = solution.Tournees[tournee1].Liste[y].arrive;
    solution.Tournees[tournee1].Liste[y].fin = solution.Tournees[tournee1].Liste[y].arrive;
    solution.Tournees[tournee1].Liste[y].folga = instance.Liste[1].date_tard - solution.Tournees[tournee1].Liste[y].arrive;

    for(int l = solution.Tournees[tournee1].qte; l>1; l--){
        if(solution.Tournees[tournee1].Liste[l].folga<solution.Tournees[solution.qteToune].Liste[l-1].folga){
            solution.Tournees[tournee1].Liste[l-1].folga = solution.Tournees[tournee1].Liste[l].folga;
        }
    }
    solution.Tournees[tournee2].qte = 0;
}

void copie_gain(T_gain &recoit, T_gain &source){
    recoit.sommet1 = source.sommet1;
    recoit.sommet2 = source.sommet2;
    recoit.g = source.g;
}

//initialiser nouvelle tournée
void new_tourne(T_instance &instance, T_solution &solution, int alloue){
    solution.Tournees[solution.qteToune].capacite = 0;
    solution.Tournees[solution.qteToune].Km = 0;
    solution.Tournees[solution.qteToune].Liste[1].seq = 1;
    solution.Tournees[solution.qteToune].Liste[1].arrive = 0;
    solution.Tournees[solution.qteToune].Liste[1].debut = 0;
    solution.Tournees[solution.qteToune].Liste[1].fin = 0;
    solution.Tournees[solution.qteToune].Liste[1].folga = instance.Liste[1].date_tard;
    solution.Tournees[solution.qteToune].Liste[2].seq = alloue;
    solution.Tournees[solution.qteToune].Liste[2].arrive = instance.distance[1][alloue];
    solution.Tournees[solution.qteToune].Liste[2].debut = (solution.Tournees[solution.qteToune].Liste[2].arrive>instance.Liste[alloue].date_tot) ? solution.Tournees[solution.qteToune].Liste[2].arrive : instance.Liste[alloue].date_tot;
    solution.Tournees[solution.qteToune].Liste[2].fin = solution.Tournees[solution.qteToune].Liste[2].debut + instance.Liste[alloue].duree;
    solution.Tournees[solution.qteToune].Liste[2].folga = instance.Liste[alloue].date_tard - solution.Tournees[solution.qteToune].Liste[2].arrive;
    solution.Tournees[solution.qteToune].Liste[3].seq = 1;
    solution.Tournees[solution.qteToune].Liste[3].arrive = solution.Tournees[solution.qteToune].Liste[2].fin + instance.distance[alloue][1];
    solution.Tournees[solution.qteToune].Liste[3].folga = instance.Liste[1].date_tard - solution.Tournees[solution.qteToune].Liste[3].arrive;
    solution.Tournees[solution.qteToune].Liste[3].fin = solution.Tournees[solution.qteToune].Liste[3].arrive;
    solution.Tournees[solution.qteToune].Liste[3].debut = solution.Tournees[solution.qteToune].Liste[3].arrive;
    if(solution.Tournees[solution.qteToune].Liste[2].folga > solution.Tournees[solution.qteToune].Liste[3].folga){
        solution.Tournees[solution.qteToune].Liste[2].folga =  solution.Tournees[solution.qteToune].Liste[3].folga;
    }
    solution.Tournees[solution.qteToune].qte = 3;
}

//initialiser tournée avec le première sommet
void initialiser_tourne(T_instance &instance, T_solution &solution){
    solution.Tournees[solution.qteToune].capacite = 0;
    solution.Tournees[solution.qteToune].Km = 0;
    solution.Tournees[solution.qteToune].qte = 2;
    solution.Tournees[solution.qteToune].Liste[1].seq = 1;
    solution.Tournees[solution.qteToune].Liste[2].seq = 1;
    solution.Tournees[solution.qteToune].Liste[1].arrive = 0;
    solution.Tournees[solution.qteToune].Liste[2].arrive = 0;
    solution.Tournees[solution.qteToune].Liste[1].debut = 0;
    solution.Tournees[solution.qteToune].Liste[2].debut = 0;
    solution.Tournees[solution.qteToune].Liste[1].fin = 0;
    solution.Tournees[solution.qteToune].Liste[2].fin = 0;
    solution.Tournees[solution.qteToune].Liste[1].folga = instance.Liste[1].date_tard;
    solution.Tournees[solution.qteToune].Liste[2].folga = instance.Liste[1].date_tard;
}

void creer_pop_initiale(T_instance &instance, T_population &POP){
    for(int i=1; i<=20; i++){
        generer_sol(POP.solutions[i], instance, 1);
        recherche_deux_opt(instance, POP.solutions[i]);
        recherche_or_opt(instance, POP.solutions[i]);
        recherche_shift(instance, POP.solutions[i]);
        POP.N++;
    }
    for(int i=21; i<=40; i++){
        generer_sol_CW(POP.solutions[i], instance);
        recherche_deux_opt(instance, POP.solutions[i]);
        recherche_or_opt(instance, POP.solutions[i]);
        recherche_shift(instance, POP.solutions[i]);
        POP.N++;
    }
    for(int i=41; i<=50; i++){
        generer_sol(POP.solutions[i], instance, 2);
        recherche_deux_opt(instance, POP.solutions[i]);
        recherche_or_opt(instance, POP.solutions[i]);
        recherche_shift(instance, POP.solutions[i]);
        POP.N++;
    }
}

void TRIER(T_population &POP){
    T_solution temp;
    int j;
    for(int i = 2; i<=POP.N; i++){
        j = i-1;
        while(j >=1 && POP.solutions[i].cout + ep<POP.solutions[j].cout){
            j --;
        }
        copie_solution(temp,POP.solutions[i]);
        for(int l = i-1; l>j; l--){
            copie_solution(POP.solutions[l+1], POP.solutions[l]);
        }
        copie_solution(POP.solutions[j+1], temp);
    }
}

void RETRIER(T_population &POP, int pos){
    T_solution temp;
    int j;
    if(POP.solutions[pos].cout<POP.solutions[pos-1].cout){
        j = pos-1;
        while(j >=1 && POP.solutions[pos].cout + ep<POP.solutions[j].cout){
            j --;
        }
        copie_solution(temp,POP.solutions[pos]);
        for(int l = pos-1; l>j; l--){
            copie_solution(POP.solutions[l+1], POP.solutions[l]);
        }
        copie_solution(POP.solutions[j+1], temp);
    }
    else if(POP.solutions[pos].cout>POP.solutions[pos+1].cout + ep){
        j = pos+1;
        while(j <=POP.N && POP.solutions[pos].cout>POP.solutions[j].cout + ep){
            j ++;
        }
        copie_solution(temp,POP.solutions[pos]);
        for(int l = pos+1; l>j; l++){
            copie_solution(POP.solutions[l-1], POP.solutions[l]);
        }
        copie_solution(POP.solutions[j-1], temp);
    }
}

void copie_solution(T_solution &recoit, T_solution &source){
    recoit.qteToune = source.qteToune;
    recoit.Km_total = source.Km_total;
    recoit.cout = source.cout;
    for(int i = 1; i<= NT-1; i++){
        recoit.ordre[i].seq = source.ordre[i].seq;
        recoit.ordre[i].tourne = source.ordre[i].tourne;
    }
    for(int i = 1; i<=source.qteToune; i++){
        recoit.Tournees[i].capacite = source.Tournees[i].capacite;
        recoit.Tournees[i].Km = source.Tournees[i].Km;
        recoit.Tournees[i].qte = source.Tournees[i].qte;
        for(int j = 1; j<=source.Tournees[i].qte; j++){
			recoit.Tournees[i].Liste[j].arrive = source.Tournees[i].Liste[j].arrive;
			recoit.Tournees[i].Liste[j].debut = source.Tournees[i].Liste[j].debut;
			recoit.Tournees[i].Liste[j].fin = source.Tournees[i].Liste[j].fin;
			recoit.Tournees[i].Liste[j].folga = source.Tournees[i].Liste[j].folga;
			recoit.Tournees[i].Liste[j].seq = source.Tournees[i].Liste[j].seq;
		}
    }
}

void copie_liste(T_solution &solution, int tourne, int pos1, int pos2){
    solution.Tournees[tourne].Liste[pos1].arrive = solution.Tournees[tourne].Liste[pos2].arrive;
    solution.Tournees[tourne].Liste[pos1].debut = solution.Tournees[tourne].Liste[pos2].debut;
    solution.Tournees[tourne].Liste[pos1].fin = solution.Tournees[tourne].Liste[pos2].fin;
    solution.Tournees[tourne].Liste[pos1].folga = solution.Tournees[tourne].Liste[pos2].folga;
    solution.Tournees[tourne].Liste[pos1].seq = solution.Tournees[tourne].Liste[pos2].seq;
}

void choisir_parent(int &P1, int &P2){
    P1 = (rand()%40)+ 11; //pere aleatoire
    P2 = (rand()%10)+ 1; //parent dans le top 10
}

void croisement(T_solution &P1, T_solution &P2, T_solution &F){
    int sort;
    int disp[n_max];
    for(int i =2; i<=NT; i++){
        disp[i] = 1;
    }
    sort = (rand()%(NT-1)) + 1;

    for(int i = 1; i<=sort; i++){
        F.ordre[i].seq = P1.ordre[i].seq;
        disp[F.ordre[i].seq] = 0;
    }
    for(int i = 1; i<=NT; i++){
        if(disp[P2.ordre[i].seq]==1){
            F.ordre[sort+ 1].seq = P2.ordre[i].seq;
            sort ++;
        }
        if(sort>NT){i = NT+1;}
    }
}

void recherche_deux_opt(T_instance &instance, T_solution &solution){
    T_solution temp;
    int i = NT-1;
    int j = i;
    while(i>1){
        j = i-1;
        while(j>0){
            if(solution.ordre[i].tourne!=solution.ordre[j].tourne){
                copie_solution(temp, solution);
                temp.ordre[j].seq = solution.ordre[i].seq;
                temp.ordre[i].seq = solution.ordre[j].seq;
                generer_sol(temp, instance, 0);
                if(temp.cout + ep<solution.cout){
                    copie_solution(solution, temp);
                    i = NT-1;//si la solution a été changé, revenir au fin 
                    j = i-1;
                }
                else{
                    while(solution.ordre[j].tourne == solution.ordre[j-1].tourne && j>1){
                        j--;
                    }
                    j = j -1;
                }
            }
            else{j--;}
        }
        while(solution.ordre[i].tourne == solution.ordre[i-1].tourne && i>2){
            i--;
        }
        i = i - 1;
    }
}

void recherche_or_opt(T_instance &instance, T_solution &solution){
    T_solution temp;
    int i = 1;
    int j = i;
    while(i<NT-1){
        j = i+1;
        while(j<NT){
            if(solution.ordre[i].tourne!=solution.ordre[j].tourne){
                copie_solution(temp, solution);
                for(int l =i+1; l<=j; l++){
                    temp.ordre[l-1].seq = temp.ordre[l].seq;
                }
                temp.ordre[j].seq = solution.ordre[i].seq;
                generer_sol(temp, instance, 0);
                if(temp.cout + ep<solution.cout){
                    copie_solution(solution, temp);
                    i = 1;//si la solution a été changé, revenir au début
                    j = i+1;
                }
                else{
                    while(solution.ordre[j].tourne == solution.ordre[j+1].tourne && j<NT-2){
                        j++;
                    }
                    j = j + 1;
                }
            }
            else{j++;}
        }
         while(solution.ordre[i].tourne == solution.ordre[i+1].tourne && i<NT-3){
            i++;
        }
        i = i + 1;
    }
}

void recherche_shift(T_instance &instance, T_solution &solution){
    T_solution temp;
    int i = 1;
    int j = i+1;
    while(i <NT-1){
		while(j<NT){
			if(solution.ordre[i].tourne==solution.ordre[j].tourne){
				copie_solution(temp, solution);
				temp.ordre[j].seq = solution.ordre[i].seq;
				temp.ordre[i].seq = solution.ordre[j].seq;
				generer_sol(temp, instance, 0);
				if(temp.cout +  ep <solution.cout){
					copie_solution(solution, temp);
					i = 1;//si la solution a été changé, revenir au début
					j = i+1;
				}
				else{j++;}
			}
			else{
				i ++;
				j = i + 1;
			}
		}
	i++;
	j = i+1;
	}
}

void genetique(T_population &POP, T_instance &instance){
	int Pere1;
    int Pere2;
	T_solution new_sol;
	int cont=0;

	while(cont<IntMAX){
		choisir_parent(Pere1, Pere2);
		croisement(POP.solutions[Pere1],POP.solutions[Pere2], new_sol);
		generer_sol(new_sol, instance, 0);
		recherche_deux_opt(instance, new_sol);
		recherche_or_opt(instance, new_sol);
		recherche_shift(instance, new_sol);
		copie_solution(POP.solutions[Pere1], new_sol);
		RETRIER(POP, Pere1);
		
	cont++;
	}
}

void simuler(RichTextBox^  text, TextBox^ nom, TextBox^ _alpha, TextBox^ _beta, TextBox^ _intMAX){
    srand(time(NULL));
    String ^n = nom->Text;
	alpha = Convert::ToDouble(_alpha->Text);
	beta = Convert::ToDouble(_beta->Text);
	IntMAX = Convert::ToInt32(_intMAX->Text);
	T_instance instance;
    T_population POP;
    	
    lire_instance(instance, n);
    creer_pop_initiale(instance, POP);
    TRIER(POP);

	genetique(POP, instance);
    
	String ^s = "Kilométrage: " + Convert::ToString(POP.solutions[1].Km_total) + "    Nombre de Tournees: " + Convert::ToString(POP.solutions[1].qteToune) ;
	text->AppendText(s);
}