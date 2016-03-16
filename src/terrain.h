/**
   @file terrain.c
   @brief  Définit les fonctions et les structures du terrain
*/
#ifndef _TERRAIN
#define _TERRAIN

#define MAX_CHAR_NOM_TERRAIN 101
#define MAX_TAILLE_XY 1000

typedef struct MTerrain{
    int dimx, dimy;
    char nomTerrain[MAX_CHAR_NOM_TERRAIN];
	char grille[MAX_TAILLE_XY][MAX_TAILLE_XY];
    
} terrain;

/**
	@brief Edition de X et de Y dans la structure
	@param x Entier pour la largeur du terrain
	@param y Entier pour la hauteur du terrain
	@param leTerrain Pointeur sur la structure terrain a editer
*/
void setXY (int x, int y, terrain * leTerrain);
/**
	@brief Edition du nom du terrain dans sa structure
	@param nom Chaine de carractere ne pouvant dépasser les 101 carractere et definissant le nom du terrain
	@param leTerrain Pointeur sur la structure terrain a editer
*/
void setnomTerrain(char nom[MAX_CHAR_NOM_TERRAIN], terrain * leTerrain);
/**
	@brief Edition de la grille du terrain au coordonnées X/Y
	@param x Valeur ou le point de la grille doit etre edité en X
	@param y Valeur ou le point de la grille doit etre edité en Y
	@param leTerrain Pointeur sur la structure terrain a editer
	@param valeur Carractere definissant ce que serra la case
*/
void setgrilleXY (int x, int y, terrain * leTerrain, char valeur);
/**
	@brief Recupère la dimension en X de la structure terrain
	@param leTerrain Pointeur sur la structure terrain a editer
	@return Entier de la dimension en X du terrain
*/
int getX(terrain * leTerrain);
/**
	@brief Recupère la dimension en Y de la structure terrain
	@param leTerrain Pointeur sur la structure terrain a editer
	@return Entier de la dimension en Y du terrain
*/
int getY(terrain * leTerrain);
/**
	@brief Recupère le nom de la structure terrain
	@param leTerrain Pointeur sur la structure terrain a editer
	@return Chaine de carractere du nom du terrain pointé
*/
char * getnom(terrain * leTerrain);
/**
	@brief Recupere la valleur de la grille au point X/Y
	@param x Position en x a recuperer
	@param y poisition en u a récuperer 
	@param leTerrain Pointeur sur la structure terrain a editer
	@return Le carractere de la grille en X/Y
*/
char getgrilleXY (int x, int y,terrain * leTerrain);


/**
	@brief Sert a remplir la grille de terrain avec un valeur par défaut
	@param leTerrain Pointeur sur la structure terrain a editer
*/
void TerrainInitGrille (terrain * leTerrain);
/**
	@brief Creer un terrain avec les dimension et le nom choisi et initialise sa grille en appelant TerrainInitGrille
	@param dimx La largeur du terrain
	@param dimy La haueteur du terrain
	@param nomTerrain Nom du terrain a creer
	@return Pointeur vers le terrain nouvellement creer
*/
terrain * TerrainCreer (int dimx, int dimy, char nomTerrain[MAX_CHAR_NOM_TERRAIN]);
/**
	@brief Sauvegarde le terrain pointé dans un fichier (.terrain)
	@param leTerrain Pointeur sur la structure terrain a sauvegarder
*/
void TerrainCreerFichier (terrain * leTerrain);
/**
	@brief Li le fichier terrain de nom spécifié et le retourne par un pointeur
	@param nomTerrain Nom du fichier terrain à lire
	@return Pointeur vers la structure lu dans le fichier
*/
terrain * TerrainLireFichier (char nomTerrain[MAX_CHAR_NOM_TERRAIN]);



#endif