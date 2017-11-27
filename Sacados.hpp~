#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>

class Sacados
{
private:
  int capaMax;
  int nbObjets;
  std::vector<int> tabProfit;
  std::vector<int> tabPoids;
  double beta;

public:
  Sacados();
  void lireFichier(std::string );
  void toString();
  float calculCoeff();
  double evaluation(std::vector<int> & );
  int get_nb_objets();
  double rechercheAlea(int);
  double marcheAlea(int);
  double hillClimberBest(int);
  double hillClimberFirst(int);
  void voisin(std::vector<int> &, int);
  std::vector<int> voisinAlea(std::vector<int> &);
  std::vector<int> rand_x();
};
