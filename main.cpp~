#include "Sacados.hpp"

 

int main(int argc, char ** argv)
{

  if(argc < 4)
    std::cout << "Pas assez d'arguments, utilisez " << argv[0] << " NOMDUFICHIER" << std::endl;
  else
    {
      srand(atoi(argv[3]));
      Sacados sac;
      double valeurResultat = 0;
      double valeurMarcheAlea = 0;
      double valeurHillBest = 0;
      double valeurHillFirst = 0;

      int nbRun = atoi(argv[2]);
      sac.lireFichier(argv[1]);

      //valeurHillBest = sac.hillClimberBest(nbRun);
      valeurHillFirst = sac.hillClimberFirst(nbRun);

      
      //std::cout << nbRun <<" " << valeurHillBest<<" "<<30000 << std::endl;
      std::cout << nbRun <<" "<<valeurHillFirst<<" "<<30000<<std::endl;
      
      return 0;
    }
}
