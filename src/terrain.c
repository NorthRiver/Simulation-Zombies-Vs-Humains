/**
   @file terrain.c
   @brief  Implémente les fonctions de manipulation du Terrain
*/

#include "terrain.h"

//////////////////////////////////////////////////////////////////////////////
//ACCESSEURS//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void setXY_terr (int x, int y, Terrain * pTerrain){
	pTerrain->dimX = x;
	pTerrain->dimY = y;
}


void setnomTerrain_terr(char * nom, Terrain * pTerrain){
	int i;
	for (i=0; i<MAX_CHAR_NOM_TERRAIN; i++){
		pTerrain->nomTerrain[i] = nom[i];
	}
}

void setgrilleXY_terr (int x, int y, Terrain * pTerrain, caseDeplacement caseDep){
	pTerrain->grille[x][y] = caseDep;
}

int getX_terr(Terrain * pTerrain){
	return pTerrain->dimX;
}

int getY_terr(Terrain * pTerrain){
    return pTerrain->dimY;
}

char * getnom_terr(Terrain * pTerrain){
    return pTerrain->nomTerrain;
}

caseDeplacement * getgrilleXY_terr (int x, int y,Terrain * pTerrain){
    return &(pTerrain->grille[x][y]);
}

//////////////////////////////////////////////////////////////////////////////
//CREATION////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void terrainInitGrille_terr (Terrain * pTerrain){
	int i,j;
	caseDeplacement X;
	setPersoCase(&X, NULL);
	setEnvCase(&X, VIDE);
	for(i=0; i < (pTerrain->dimX); i++){
		for(j=0; j < (pTerrain->dimY); j++){
			setgrilleXY_terr(i, j, pTerrain, X);
		}
	}

}

Terrain * terrainCreer_terr (int dimX, int dimY, char nomTerrain[MAX_CHAR_NOM_TERRAIN]){
	Terrain * pTerrain = NULL;
        pTerrain = malloc(sizeof(Terrain));
	setXY_terr(dimX,dimY, pTerrain);
	setnomTerrain_terr(nomTerrain, pTerrain);
	terrainInitGrille_terr(pTerrain);
	return pTerrain;
}

/////////////////////////////////////////////////////////////////////////////
//TESTS SPECIFIQUES//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

char estDansTerrain_terr(Terrain * pTerrain, Coordonnees * pCoord){
    int xCoord = getXCoord_Coord(pCoord);
    int yCoord = getYCoord_Coord(pCoord);

    return (xCoord >= 0 && xCoord < getX_terr(pTerrain) && \
	    yCoord >= 0 && yCoord < getY_terr(pTerrain));
}

/////////////////////////////////////////////////////////////////////////////
//DEPLACEMENT PERSONNAGES////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
char verifDeplacementBas_perso(Perso * pPerso, Terrain * pTerrain){
    Coordonnees * pCoordPerso = getCoordonneesPerso_perso(pPerso);

    setYCoord_Coord(getYCoord_Coord(pCoordPerso) - 1, pCoordPerso);
    
    return estDansTerrain_terr(pTerrain, pCoordPerso);
}

char verifDeplacementHaut_perso(Perso * pPerso, Terrain * pTerrain){
    Coordonnees * pCoordPerso = getCoordonneesPerso_perso(pPerso);

    setYCoord_Coord(getYCoord_Coord(pCoordPerso) + 1, pCoordPerso);
    
    return estDansTerrain_terr(pTerrain, pCoordPerso);
}

char verifDeplacementGauche_perso(Perso *  pPerso, Terrain * pTerrain){
    Coordonnees * pCoordPerso = getCoordonneesPerso_perso(pPerso);

    setXCoord_Coord(getXCoord_Coord(pCoordPerso) - 1, pCoordPerso);
    
    return estDansTerrain_terr(pTerrain, pCoordPerso);
}

char verifDeplacementDroite_perso(Perso * pPerso, Terrain * pTerrain){
    Coordonnees * pCoordPerso = getCoordonneesPerso_perso(pPerso);

    setXCoord_Coord(getXCoord_Coord(pCoordPerso) + 1, pCoordPerso);
    
    return estDansTerrain_terr(pTerrain, pCoordPerso);
}

void deplacementHaut_perso(Perso * pPerso, Terrain * pTerrain){
    assert(verifDeplacementHaut_perso(pPerso, pTerrain));

    int xPerso = getXPerso_perso(pPerso);
    int yPerso = getYPerso_perso(pPerso);
    
    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), NULL);

    yPerso++;
    setYPerso_perso(pPerso, yPerso);

    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), pPerso);
}

void deplacementBas_perso(Perso * pPerso, Terrain * pTerrain){
    assert(verifDeplacementHaut_perso(pPerso, pTerrain));

    int xPerso = getXPerso_perso(pPerso);
    int yPerso = getYPerso_perso(pPerso);
    
    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), NULL);

    yPerso--;
    setYPerso_perso(pPerso, yPerso);

    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), pPerso);
}

void deplacementGauche_perso(Perso * pPerso, Terrain * pTerrain){
    assert(verifDeplacementHaut_perso(pPerso, pTerrain));

    int xPerso = getXPerso_perso(pPerso);
    int yPerso = getYPerso_perso(pPerso);
    
    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), NULL);

    xPerso--;
    setXPerso_perso(pPerso, xPerso);

    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), pPerso);
}

void deplacementDroite_perso(Perso * pPerso, Terrain * pTerrain){
    assert(verifDeplacementHaut_perso(pPerso, pTerrain));

    int xPerso = getXPerso_perso(pPerso);
    int yPerso = getYPerso_perso(pPerso);
    
    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), NULL);

    xPerso++;
    setXPerso_perso(pPerso, xPerso);

    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), pPerso);
}

void deplacementAleatoire_perso(Perso * pPerso, Terrain * pTerrain){
    srand(time(NULL));

    char direction = rand()%4;

    assert(direction < 4 && direction >= 0);

    if(direction == 0){
	deplacementBas_perso(pPerso, pTerrain);
    }

    else if(direction == 1){
	deplacementHaut_perso(pPerso, pTerrain);
    }

    else if(direction == 2){
	deplacementDroite_perso(pPerso, pTerrain);
    }

    else{
	deplacementGauche_perso(pPerso, pTerrain);
    }
}

/////////////////////////////////////////////////////////////////////////////
//SPECIFIQUE ZOMBIE//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
char humainEnHaut(Terrain * pTerrain, Coordonnees * coordZombie){
    caseDeplacement * caseHaut = getgrilleXY_terr(getXCoord_Coord(coordZombie), getYCoord_Coord(coordZombie) + 1, pTerrain);
    
    if(getTypePerso(getPersoCase(caseHaut)) == CITOYEN || getTypePerso(getPersoCase(caseHaut)) == POLICIER){
	return 1;
    }
    else{
	return 0; 
    }
}

char humainEnBas(Terrain * pTerrain, Coordonnees * coordZombie){
    caseDeplacement * caseBas = getgrilleXY_terr(getXCoord_Coord(coordZombie), getYCoord_Coord(coordZombie) - 1, pTerrain);
    
    if(getTypePerso(getPersoCase(caseBas)) == CITOYEN || getTypePerso(getPersoCase(caseBas)) == POLICIER){
	return 1;
    }
    else{
	return 0; 
    }
}

char humainAGauche(Terrain * pTerrain, Coordonnees * coordZombie){
    caseDeplacement * caseGauche = getgrilleXY_terr(getXCoord_Coord(coordZombie)-1, getYCoord_Coord(coordZombie), pTerrain);
    
    if(getTypePerso(getPersoCase(caseGauche)) == CITOYEN || getTypePerso(getPersoCase(caseGauche)) == POLICIER){
	return 1;
    }
    else{
	return 0; 
    }
}

char humainADroite(Terrain * pTerrain, Coordonnees * coordZombie){
    caseDeplacement * caseDroite = getgrilleXY_terr(getXCoord_Coord(coordZombie)+1, getYCoord_Coord(coordZombie), pTerrain);
    
    if(getTypePerso(getPersoCase(caseDroite)) == CITOYEN || getTypePerso(getPersoCase(caseDroite)) == POLICIER){
	return 1;
    }
    else{
	return 0; 
    }

}

void * zombieComtamineHumain(Perso * pZombie, Terrain * pTerrain){
    int xZombie, yZombie;
    
    if(humainEnHaut(pTerrain, pZombie -> coord)){
	xZombie = pZombie -> coord -> xCoord;
	yZombie = pZombie -> coord -> yCoord;
    }

    else if(humainEnBas(pTerrain, pZombie -> coord)){
	xZombie = pZombie -> coord -> xCoord;
	yZombie = pZombie -> coord -> yCoord;
    }

    else if(humainAGauche(pTerrain, pZombie -> coord)){
	xZombie = pZombie -> coord -> xCoord;
	yZombie = pZombie -> coord -> yCoord;
    }

    else if(humainAGauche(pTerrain, pZombie -> coord)){
	xZombie = pZombie -> coord -> xCoord;
	yZombie = pZombie -> coord -> yCoord;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////
//ENTREES-SORTIES///////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

void afficherGrilleConsole(Terrain * pTerrain){
    for(int i = 0; i < (pTerrain -> dimX); i++){
	for (int j = 0; j < (pTerrain -> dimY); j++) {
	    if((pTerrain -> grille)[i][j].envCase == VIDE){
		printf("v");
	    }
	}
	printf("\n");
    }
}



void terrainCreerFichier_terr (Terrain * pTerrain){
	FILE * pFichier;

	pFichier = fopen("../data/test.ter","w");

	assert(pFichier != NULL);
	
	int i, j;
	for(i = (pTerrain -> dimY) - 1; i >= 0; i--){
	    for(j = 0; j < (pTerrain -> dimX); j++){
		if((pTerrain -> grille)[i][j].envCase == VIDE)
		    fputc('v', pFichier);
		}
	    fprintf(pFichier, "\n");
	}
}


/*
Terrain * terrainLireFichier (char nomTerrain[MAX_CHAR_NOM_TERRAIN]);
A CODER QUAND LE FONCTION DU DESSUS MARCHERA
*/
