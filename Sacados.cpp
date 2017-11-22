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

void Sacados::voisinAlea(std::vector<int> &x){

  int indice = rand()%x.size();
  if(x[indice] ==0)
    x[indice] =1;
  else x[indice] = 0;

}

void Sacados::voisin(std::vector<int> &x, int indice)
{
  if(x[indice] ==0)
    x[indice] = 1;
  else x[indice] = 0;

}

double Sacados::marcheAlea(int nbIteration){

  std::vector<int> x = rand_x();
  double sBest = evaluation(x);
  double sprime = 0;
  std::vector<int> xprime;
 
  for (int i =0; i<nbIteration; i++){
    xprime = voisinAlea(x);
    sprime = evaluation(x);

    if(sprime > sBest)
      {
	sBest = sprime;
	x = xprime;
      }
    
  }

  return sBest;
}


double Sacados::hillClimberBest(int nbEvalMax)
{

  std::vector<int> x = rand_x();
  double sBest = evaluation(x);
  double sprime = 0;
  int indiceTrouve = 0;
  double fbestN;
  bool stop = false;
  int nbEval = 1;
  
  while (!stop && nbEval < nbEvalMax) {

      fbestN = -1;
      
      for(int j = 0; j<x.size(); j++)
	{
	  voisin(x, j);
	  sprime = evaluation(x);
	  nbEval++;
	  if (sprime > fbestN)
	    {
	      fbestN = sprime;
	      indiceTrouve = j; 
	    }
	   voisin(x, j);

	}

      if (sBest < fbestN) {
	voisin(x, indiceTrouve);
	sBest = fbestN;
      } else {
	stop = true;
      }
    }

  return sBest;
}

double Sacados::hillClimberFirst(int nbEvalMax){

  std::vector<int> x = rand_x();
  double sBest = evaluation(x);
  double sprime = 0;
  int indiceTrouve = 0;
  double fbestN;
  bool stop = false;
  int nbEval = 1;
  std::vector<int> dejaVisite ;
  
  while(!stop && nbEval < nbEvalMax){
    voisinAlea(x);
    evaluation(x);
    nbEval++;
  
    
    while(fbestN >= sprime && nbEval<=nbEvalMax && !x.empty()){
      voisinAlea(x);
      evaluation(sprime);
      nbEval++;
      dejaVisite.push_back(sprime);
      x.erase(x.begin()+sprime);
    }

    if (sBest < fbestN) {
      voisin(x, indiceTrouve);
      sBest = fbestN;
    } else {
      stop = true;
    }
        
  }
  
  return sBest

    }

