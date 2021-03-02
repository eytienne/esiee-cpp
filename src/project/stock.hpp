typedef char elem;
// Constantes
const int MAX_SORTES = 5;
const int MAX_QUANTITE = 10;
const int ERR_INCONNU = -1;
const int ERR_INTERVALLE = 0;
const int OK = 0;
const int ERR_PLEIN = 1;
const int ERR_VIDE = 2;
const int ERR_DEP = 3;
// Initialisateur
void init_stock();
// Accesseurs
int nb_sortes();
int nb_unites(int);
elem *ieme(int);
// Fonctions d'etat
int est_vide(int);
int est_limite();
// Autres fonctions
int stocker(elem *, int);
int retirer(int);
int traite_vide(int);
// fonctions utilitaires
int est_plein(int);
int rechercher(elem *);
// Donnees
extern int index;
extern int quantites[MAX_SORTES];
extern elem *rails[MAX_SORTES];