#include "personnage.h"

////////////////////////////////////////////////////////////////////////////
//ACCESSEURS////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

Coordonnees * getCoordonneesPerso_perso(Perso * pPerso){
  return pPerso -> pCoord;
}

int getXPerso_perso(Perso * pPerso){
  return getXCoord_Coord(getCoordonneesPerso_perso(pPerso));
}

int getYPerso_perso(Perso * pPerso){
  return getYCoord_Coord(getCoordonneesPerso_perso(pPerso));
}

void setXPerso_perso(Perso * pPerso, int xPerso){
  setXCoord_Coord(xPerso, getCoordonneesPerso_perso(pPerso));
}

void setYPerso_perso(Perso * pPerso, int yPerso){
  setYCoord_Coord(yPerso, getCoordonneesPerso_perso (pPerso));
}

void setCoordPerso_perso(Coordonnees * pCoord, Perso * pPerso){
  pPerso -> pCoord = pCoord;
}

Coordonnees * getCoordPerso(Perso * pPerso){
  return pPerso -> pCoord;
}

enum typePerso getTypePerso(Perso * pPerso){
  return pPerso -> type;
}

void setTypePerso_perso(enum typePerso typePerso, Perso * pPerso){
  pPerso -> type = typePerso;
}

void setIdPerso(int idPerso, Perso * pPerso){
  pPerso -> id = idPerso;
}

int getIdPerso(Perso * pPerso){
  return pPerso -> id;
}


////////////////////////////////////////////////////////////////////////////
//CREATION PERSO////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

Perso * initPerso(Coordonnees * pCoord, enum typePerso typePerso, int idPerso){
  Perso * pPerso = (Perso *)malloc(sizeof(Perso));

  setCoordPerso_perso(pCoord, pPerso);
  setTypePerso_perso(typePerso, pPerso);
  setIdPerso(idPerso, pPerso);

  return pPerso;
}

void testamentPerso(Perso * pPerso){
  testamentCoord(getCoordPerso(pPerso));

  free(pPerso);

  pPerso = NULL;
}
////////////////////////////////////////////////////////////////////////////
//NON REGRESSION////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void testFonctions_perso(){
    /*
  Coordonnees * coordPerso = initCoordonnees_coord(3, 4);

  Perso * pPerso = initPerso(coordPerso, ZOMBIE, 0);

  assert(getTypePerso(pPerso) == ZOMBIE && sontEgale_Coord(getCoordonneesPerso_perso(pPerso), coordPerso));

  testamentCoord(coordPerso);

  printf("Execution du module coordonnees et de ses fonctions sans erreurs... \n");
  */
}
