/* 
** ARBRE BICOLORE WIKIPEDIA (FRANÇAIS): NE MARCHE PAS À DE MULTIPLE ENDROIT
** https://fr.wikipedia.org/wiki/Arbre_bicolore
*/

#include <unistd.h>
#include "../../../colors.h"
#include <iostream>
#define NOIR 0
#define ROUGE 1
#define FEUILLE NULL

struct noeud {
  struct noeud *gauche; //Pointeur vers fils gauche
  struct noeud *droit; //Pointeur vers fils droit 
  struct noeud *parent; //Pointeur vers père
  int couleur; // ROUGE ou NOIR
  int key; // Peut être n'importe quel type, tant que les opérations de comparaison (<, = , > ) sont définies
};

struct noeud* parent(struct noeud* n);
struct noeud* grandparent(struct noeud* n);
struct noeud* frere(struct noeud* n);
struct noeud* oncle(struct noeud* enfant);
void rotation_gauche(struct noeud* x);
void rotation_droite(struct noeud* x);
struct noeud *insertion(struct noeud *racine, struct noeud *n);
void insertion_recursif(struct noeud *racine, struct noeud *n);
void insertion_repare_arbre(struct noeud *n);
void insertion_cas1(struct noeud *n);
void insertion_cas2(struct noeud *n);
void insertion_cas3(struct noeud *n);
void insertion_cas4(struct noeud *n);
void insertion_cas5(struct noeud *n);

struct noeud* parent(struct noeud* n) {
  return n->parent;
}

struct noeud* racine(struct noeud* n) {
  while (parent(n) != NULL){std::cout << "search root\n";
	n = parent(n);}
}

struct noeud* grandparent(struct noeud* n) {
  struct noeud* p = parent(n);
  if (p == NULL)
	return NULL; // Un noeud sans parent n'a pas de grand-parent
  return parent(p);
}

struct noeud* frere(struct noeud* n) {
  struct noeud* p = parent(n);
  if (p == NULL)
	return NULL; // Un noeud sans parent n'a pas de frere
  if (n == p->gauche)
	return p->droit;
  else
	return p->gauche;
}

//Renvoie le frère du père
struct noeud* oncle(struct noeud* enfant) {
  struct noeud* p = parent(enfant);
  struct noeud* g = grandparent(enfant);
  if (g == NULL)
	return NULL; // Pas de grand parent, donc pas d'oncle
  return frere(p);
}

void rotation_gauche(struct noeud* x) {
  struct noeud* y = x->droit;
  //le fils droit de x devient le fils gauche de y
  x->droit = y->gauche;
  if (y->gauche != FEUILLE)
	y->gauche->parent = x;
 
  y->parent = x->parent;
  //Si x est la racine, y devient la racine
  if (x->parent == NULL)
	x = y; // <- ça capote 9 ligne plus bas si x est la racine

  //Sinon, on remplace x par y
  else if (x == x->parent->gauche)
	x->parent->gauche = y;
  else
	x->parent->droit = y;

  //On attache x à gauche de y
  y->gauche = x;
  x->parent = y;
}

void rotation_droite(struct noeud* x) {
	struct noeud* y = x->gauche;
	//le fils gauche de x devient le fils droit de y
	x->gauche = y->droit;
	if (y->droit != FEUILLE)
		y->droit->parent = x;
 
	y->parent = x->parent;
	//Si x est la racine, y devient la racine
	if (x->parent == NULL)
	x = y;

	//Sinon, on remplace x par y
	else if (x == x->parent->droit)
		x->parent->droit = y;
	else
		x->parent->gauche = y;

	//On attache x à droite de y
	y->droit = x;
	x->parent = y;
}

struct noeud *insertion(struct noeud *racine, struct noeud *n) {
  // Insertion d'un nouveau nœud dans l'arbre
  insertion_recursif(racine, n);

  // Réparation de l'arbre au cas où les propriétés rouge-noir seraient violées
  insertion_repare_arbre(n);// <- problem si on insert 1 2 3 à la suite searchRoot est une boucle infini

  // Recherche de la nouvelle racine à renvoyer
  racine = n;
   
  while (parent(racine) != NULL){std::cout << "search root\n";
	racine = parent(racine);}
	
  return racine;
}

void insertion_recursif(struct noeud *racine, struct noeud *n) {
  // Descente récursive dans l'arbre jusqu'à atteindre une feuille
  if (racine != NULL && n->key < racine->key)
  {
	if (racine->gauche != FEUILLE) {
		insertion_recursif(racine->gauche, n);
		return;
	}
	else
		racine->gauche = n;
  } 
  else if (racine != NULL) {
	if (racine->droit != FEUILLE) {
		insertion_recursif(racine->droit, n);
		return;
	}
	else
		racine->droit = n;
  }
std::cout << "insertion_recursif\n";

  // Insertion du nouveau noeud n
  n->parent = racine;
  n->gauche = FEUILLE; // NIL
  n->droit = FEUILLE; // NIL
  n->couleur = ROUGE;
}

void insertion_repare_arbre(struct noeud *n) { //std::cout << "insertion_repare_arbre\n";
	if (parent(n) == NULL)
		insertion_cas1(n);
	else if (parent(n)->couleur == NOIR)
		insertion_cas2(n);
	else if (oncle(n) && oncle(n)->couleur == ROUGE)
		insertion_cas3(n);
	else
		insertion_cas4(n);
std::cout << "arbre repair\n";
 }

void insertion_cas1(struct noeud *n) {
   if (parent(n) == NULL) {
	  std::cout << "cas pas de parent" << std::endl;
	  n->couleur = NOIR;
	}
 }

void insertion_cas2(struct noeud *n) {
   return; /* Ne rien faire puisque l'arbre est bien un arbre rouge-noir */
 }

void insertion_cas3(struct noeud *n) {
   parent(n)->couleur = NOIR;
   oncle(n)->couleur = NOIR;
   
   struct noeud *g = grandparent(n);
   g->couleur = ROUGE;
   insertion_repare_arbre(g);
 }

 void insertion_cas4(struct noeud *n) {
   struct noeud *p = parent(n);
   struct noeud *g = grandparent(n);
std::cout << "case4\n";
   if (g && g->gauche && n == g->gauche->droit) {
	  rotation_gauche(p);
	  n = n->gauche;
   } else if (g && g->droit && n == g->droit->gauche) {
	  rotation_droite(p);
	  n = n->droit; 
   }

   insertion_cas5(n);
 }

 void insertion_cas5(struct noeud *n) {
   struct noeud *p = parent(n);
   struct noeud *g = grandparent(n);
std::cout << "case5\n";
   if (n == p->gauche)
	  rotation_droite(g);
   else
	  rotation_gauche(g);

   p->couleur = NOIR;
   g->couleur = ROUGE;
 }

	void print2dTree(struct noeud *n, int space) {
		if (n == NULL)
			return ;
		space += 5;
		print2dTree(n->droit, space);
		std::cout << std::endl;
		for (int i = 5; i < space; ++i)
			std::cout << " ";
		n->couleur ? std::cout << RED << n->key << RESET << std::endl : std::cout << n->key << std::endl;
		print2dTree(n->gauche, space);
	}

void print_node(noeud a)
{
	std::cout << "a.parent : " << a.parent << ", a.gauche : " << a.gauche <<  ", a.droite : " << a.droit
	<<  ", a.key : " << a.key <<  ", a.color : " << a.couleur << std::endl;
}

 int main(int argc, char const *argv[])
 {
	noeud *racine;
	noeud a{NULL, NULL, NULL, 1, 1};
	noeud b{NULL, NULL, NULL, 1, 2};
	noeud c{NULL, NULL, NULL, 1, 3};
	noeud d{NULL, NULL, NULL, 1, -1};
	noeud e{NULL, NULL, NULL, 1, 1};
	
	print_node(a);
	print_node(b);
	print_node(c);
	print_node(d);
	print_node(e);

	racine = insertion(NULL ,&a);
	racine = insertion(racine, &b); // <- problem si mis ici
	racine = insertion(racine, &c);
	// racine = insertion(racine, &d);
	// racine = insertion(racine, &b);
	// racine = insertion(racine, &e);
 
	print2dTree(racine, 0);
	// insertion(&a, &c);
	// std::cout << a.key << std::endl;
	return 0;
 }