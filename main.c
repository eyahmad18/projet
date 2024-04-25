#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include "fonction.h"
#include "string.h"
int main()
{
	SDL_Surface *screen;
	SDL_Event event;
	texte txte;
	int s=0;
	int state=1;
	Mix_Music *music;
	background b,image,m,b2,b1,bp;
	int boucle=1;
	int a=0,cpt1=0;
	int direction=0;
	TTF_Init();	
	char* fichier="filescore";
	scoreinfo tab[3];
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
	{
		printf("Could not initialize SDL : %s.\n",SDL_GetError());
		return -1;
	}
	screen=SDL_SetVideoMode(2048,385,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
	initialiser_audio(music);
	initBack(&b);
	initialiser2(&b1);
	initialiser1(&b2);
	init_animerBack (& image, screen);
		while(boucle)
	{
	if(state==1)
	{
		afficherBack( b, screen);
		animation2(b1,b2,screen,& cpt1);
		animerBack( &image,&a);
		
		while(SDL_PollEvent(&event))
		{    	
		 
			switch(event.type)
			{
				case SDL_KEYDOWN:
				    switch(event.key.keysym.sym)
				    {
				        case SDLK_RIGHT:
				            direction= 1;
				            break;
				            
				        case SDLK_LEFT:
				            direction= -1;
				            break;
				        case (SDLK_q):
					boucle=0;
					break;
					case SDLK_DOWN:
				            direction= 2;
				            break;
				        case SDLK_UP:
				            direction = -2;
				            break;
				           case SDLK_x:
				            state=2;
				            break;
				    }
				    
				    break;
				    
				
				  
				case SDL_QUIT:
				boucle=0;
				break;	
			
			}
			
		}
		scrolling(&b,direction);
		}
		else if (state==2)
		{
			afficherBack( m, screen);
			meilleur_score(fichier,tab,screen);
			while(SDL_PollEvent(&event))
			{
				switch(event.type)
				{
					case SDL_KEYDOWN:
					if (event.key.keysym.sym==SDLK_ESCAPE) 
					{
					state=1;
					}
						break;
			}}
		}
		SDL_Flip(screen);
	}
	
	liberer_image( b);
	liberer_image( b1);
	liberer_image( b2);
	liberer_image( image);
	liberer_Music( music);
	liberer_Texte( txte);
	SDL_QUIT;



return 0;
}
