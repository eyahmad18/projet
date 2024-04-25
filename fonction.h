#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h> 	
#define SCREEN_H 416
#define SCREEN_W 2048

typedef struct 
{
    char *url;
    SDL_Rect camera_pos; 
    SDL_Rect pos_ecran; 
    SDL_Surface *affichebackground; 
    SDL_Surface *img; 
}background;
typedef struct
{
	SDL_Surface *txt;
	SDL_Rect pos_txt;
	SDL_Colour color_txt;
	TTF_Font *police;
}texte;
typedef struct
{
	Mix_Music *music;
	int vol;
}music;
typedef struct 
{
	int score;
	int temps;
	char playername[30];
}scoreinfo;

void initialiser_audio(Mix_Music *music);
void initBack(background * b);
void initialiser1(background *b);
void initialiser2(background *b);

void afficher1(SDL_Surface *screen, background imge);
void afficherBack(background b, SDL_Surface * screen);


void scrolling (background * b, int direction ); 
void animerBack (background* b,int* a) ;
void animation2(background b1,background b, SDL_Surface * screen,int* cpt1);
void afficher (background* imge,SDL_Surface* screen);

void savescore(scoreinfo s,char filename[]);
void meilleur_score(char filename[],scoreinfo tab[],SDL_Surface *screen);

void liberer_image(background b);
void liberer_Music(Mix_Music *music);
void liberer_Texte(texte txt);

