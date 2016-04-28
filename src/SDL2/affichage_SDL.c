#include "affichage_SDL.h"
#include "../defs.h"
#include "input.h"


void delay(unsigned int frameLimit)
{
    // Gestion des 60 fps (images/stories/seconde)
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}
SDL_Texture *loadImage(char *name)
{

    /* Charge les images avec SDL Image dans une SDL_Surface */

    SDL_Surface *loadedImage = NULL;
    SDL_Texture *texture = NULL;
    loadedImage = IMG_Load(name);

    assert(loadedImage != NULL);
    if (loadedImage != NULL)
    {
    // Conversion de l'image en texture
    texture = SDL_CreateTextureFromSurface(getrenderer(), loadedImage);

    // On se d�barrasse du pointeur vers une surface
    SDL_FreeSurface(loadedImage);
    loadedImage = NULL;
    }
    else
    printf("L'image n'a pas pu �tre charg�e! SDL_Error : %s\n", SDL_GetError());

    return texture;

}
void drawImage(SDL_Texture *image, int x, int y)
{

    SDL_Rect dest;

    /* R�gle le rectangle � dessiner selon la taille de l'image source */
    dest.x = x;
    dest.y = y;

    /* Dessine l'image enti�re sur l'�cran aux coordonn�es x et y */
    SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(getrenderer(), image, NULL, &dest);

}
void afficherParamFenetre(Simulation * pSim){

    Terrain * pTerrain = getTerrain_sim(pSim);

    SDL_Texture *zombieText;
    SDL_Texture *citoyenText;
    SDL_Texture *policierText;

    zombieText = loadImage("../data/Graphics/Zombie.png");
    citoyenText = loadImage("../data/Graphics/Citoyen.png");
    policierText = loadImage("../data/Graphics/Policier.png");

    for(int i = 0; i < getDimY_terr(pTerrain); i++){
        for (int j = 0; j < getDimX_terr(pTerrain); j++) {
            if(getPersoCase(getGrilleByXY_terr(j, i, pTerrain)) != NULL){
                if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == ZOMBIE){
                    drawImage(zombieText,j*50,i*50);
                }
                else if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == CITOYEN){
                    drawImage(citoyenText,j*50,i*50);
                }
                else if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == POLICIER){
                    drawImage(policierText,j*50,i*50);

                }
            }


	    }
	}

   SDL_RenderPresent(getrenderer());

    // D�lai pour laisser respirer le proc
    SDL_Delay(200);
}

void affichageFenetre(Simulation *pSim)
{

    Terrain * pTerrain = getTerrain_sim(pSim);
    SDL_Texture *fond;
    SDL_Texture *murText;


    fond = loadImage("../data/Graphics/Case.png");
    murText = loadImage("../data/Graphics/Mur.png");

    int i,j;
    i=0; j=0;
    while(i<SCREEN_WIDTH){
            while(j<SCREEN_HEIGHT){
                drawImage(fond,i,j);
                j=j+50;
            }
            i=i+50;
            j=0;
    }


    for(int i = 0; i < getDimY_terr(pTerrain); i++){
        for (int j = 0; j < getDimX_terr(pTerrain); j++) {
            if(getEnvCase(getGrilleByXY_terr(j, i, pTerrain)) == MUR){
                    drawImage(murText,j*50,i*50);

                }


	    }
	}




     // Affiche l'�cran
    SDL_RenderPresent(getrenderer());

    // D�lai pour laisser respirer le proc
    SDL_Delay(1);

    // D�lai pour laisser respirer le proc
    SDL_Delay(1);
}



