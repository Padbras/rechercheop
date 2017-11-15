#include "Sacados.hpp"

Sacados::Sacados()
{
  
}

void Sacados::lireFichier(std::string fichier)
{
  int tmp = 0;
  std::fstream ifs(fichier.c_str(), std::ios::in);
  if(ifs)
    {
      ifs >> nbObjets; // RECUP NB OBJET POUR CREER TABLEAUX

      for (int i = 0; i<nbObjets; i++) // RECUP DES PROFITS
	{
	  ifs >> tmp;
	  tabProfit.push_back(tmp);
	}
      for (int j = 0; j<nbObjets; j++) // RECUP DES POIDS
	{
	  ifs >> tmp;
	  tabPoids.push_back(tmp);
	}
	
      ifs >> capaMax; // RECUP CAPA MAX

      beta = calculCoeff();

    }
  else std::cout << "Erreur de lecture du fichier" << std::endl;


   
}

void Sacados::toString()
{
  std::cout << "Nombre d'objets: " << nbObjets << std::endl;
  std::cout << "Valeurs des objets: " << std::endl;
      
  for (int k = 0; k<nbObjets; k++) // RECUP DES PROFITS
    {
      std::cout << "Objet numéro" << k << " Profit: " << tabProfit[k] << " Poids: " << tabPoids[k] << std::endl;
    }
      
  std::cout << "Capacité maximale du sac: " << capaMax << std::endl;
  
}

float Sacados::calculCoeff()
{
  float coefficient;
  float coeff_tempo;
  
  for(int i = 0; i < tabPoids.size(); i++)
    {
      
      coeff_tempo = tabProfit[i] / tabPoids[i];
      if(coeff_tempo > coefficient)
	{
	  coefficient = coeff_tempo;  
	}
    }
  return coefficient;
}



double Sacados::evaluation(std::vector<int> & x)
{
  double z = 0;
  double w = 0;

  for(int i = 0; i < tabProfit.size(); i++)
    {
      z += x[i]*tabProfit[i];
      w += x[i]*tabPoids[i];
    }

  if(w <= capaMax)
    return z;
  else return z - beta * (w - capaMax);
  
}

int Sacados::get_nb_objets()
{
  return nbObjets;
}

std::vector<int> Sacados::rand_x()
{
  std::vector<int> x ;
  for (int i = 0; i < nbObjets; i++)
    {
      x.push_back(rand()%2);
    }
  return x;
}


double Sacados::rechercheAlea(int nbIteration){

  srand(time(NULL));
  
  std::vector<int> x = rand_x();
  double sBest = evaluation(x);
  double sprime = 0;
 
  for (int i =0; i<nbIteration; i++){
    x = rand_x();
    sprime = evaluation(x);

    if(sprime > sBest)
      {
	sBest = sprime;
      }
 
  }
  

  return sBest;
}
