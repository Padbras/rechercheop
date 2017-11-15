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

      int nbRun = atoi(argv[2]);
      sac.lireFichier(argv[1]);
     

      valeurResultat = sac.rechercheAlea(nbRun);
      std::cout << argv[3] << " " << nbRun << " " << valeurResultat << std::endl;
  
      return 0;
    }
}
