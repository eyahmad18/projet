#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //Pour manipuler des images
#include <SDL/SDL_mixer.h> //Pour manipuler audio
#include <SDL/SDL_ttf.h> //Pour manipuler des textes
#include "fonction.h"

void initialiser_audio(Mix_Music *music)
{
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("%s",SDL_GetError());
	}
	music=Mix_LoadMUS("backgroundaudio.mp3");
	Mix_PlayMusic(music,-1);
	Mix_VolumeMusic(MIX_MAX_VOLUME/3.5);
}
void initBack(background * b)
{
    b->affichebackground=IMG_Load("background pr.png");
    if(b->affichebackground == NULL)
    {
        printf("Unable to load background image %s \n",SDL_GetError());
        return ;
    }
    b->camera_pos.x=0;
    b->camera_pos.y=0;
    b->camera_pos.w=2048;
    b->camera_pos.h=385;
    b->pos_ecran.x=0;
    b->pos_ecran.y=0;
    b->pos_ecran.h=385;
    b->pos_ecran.w=2048;
}
void initBack1(background * m)
{
    m->affichebackground=IMG_Load("background pr.png");
    if(m->affichebackground == NULL)
    {
        printf("Unable to load background image %s \n",SDL_GetError());
        return ;
    }
    m->camera_pos.x=0;
    m->camera_pos.y=0;
    m->camera_pos.w=2048;
    m->camera_pos.h=385;
    m->pos_ecran.x=0;
    m->pos_ecran.y=0;
    m->pos_ecran.h=2048;
    m->pos_ecran.w=385;
}
void aficherBack(background b, SDL_Surface * screen)
{
    SDL_BlitSurface(b.affichebackground,&(b.camera_pos),screen,&(b.pos_ecran));
}
void afficher1(SDL_Surface *screen, background imge){
    SDL_BlitSurface(imge.img, NULL, screen, &imge.camera_pos);
}
void initialiser1(background* b)
{
    b->url="with.png";
    b->img=IMG_Load(b->url);
    if(b->img == NULL){
        printf("Unable to load Button image %s \n",SDL_GetError());
        return ;
    }
   b->camera_pos.x=10;
   b->camera_pos.y=10; 
   b->pos_ecran.x=0;
   b->pos_ecran.y=0;
   b->pos_ecran.h=100;
    b->pos_ecran.w=100;
}
void initialiser2(background* b)
{
    b->url="without.png";
    b->img=IMG_Load(b->url);
    if(b->img == NULL){
        printf("Unable to load Button image %s \n",SDL_GetError());
        return ;
    }
   b->camera_pos.x=10;
   b->camera_pos.y=10; 
   b->pos_ecran.x=0;
   b->pos_ecran.y=0;
   b->pos_ecran.h=100;
   b->pos_ecran.w=100;
}
void scrolling (background * b, int direction )
{
	if(direction==-1&&b->camera_pos.x>=0 )
		b->camera_pos.x--;
	else
	
		if(direction==1){
			b->camera_pos.x++;}
		else 
		
			if(direction==2){
				b->camera_pos.y++;}
			else
			
				if(direction==-2){
				b->camera_pos.y--;
			}	
}

void init_animerBack (background* image,SDL_Surface * screen)
{
	image->img=NULL;
    image->url="butterfly.png";
    image->img=IMG_Load(image->url);  
    if(image->img == NULL)
    {
        printf("Unable to load background image %s \n",SDL_GetError());
        return ;
    }
    image->camera_pos.x=10;
    image->camera_pos.y=10;
    image->pos_ecran.x=0;
    image->pos_ecran.y=0;
    image->pos_ecran.h=image->img->h/1;
    image->pos_ecran.w=image->img->w/4;
    
    
 }
void animerBack(background * b,int * a)
{

     if (b->camera_pos.x <= 500 && (*a)==0) 
         b->camera_pos.x += 1;
     if(b->camera_pos.x == 500)
         (*a)=1;
     if (b->camera_pos.x <= 500 && (*a)==1)
     	b->camera_pos.x -= 1;
     if(b->camera_pos.x == 0)
         (*a)=0;
  
}
void animation2(background b1,background b, SDL_Surface * screen,int* cpt1)
{
	if((*cpt1)%30>=15)
		{
			afficher1( screen,b1);
			(*cpt1)++;
		}
		else
		{
			afficher1( screen,b);
			(*cpt1)++;
		}
}
 void affiche (background* image,SDL_Surface* screen)
 {
     SDL_BlitSurface(image->img,NULL,screen,&image->camera_pos);
 }
 
void savescore(scoreinfo s,char filename[])
 {
 	FILE* pf=NULL;
 	pf=fopen(filename,"a");
 	if (pf!=NULL)
 	{
 		fprintf(pf,"%s %d %d\n",s.playername,s.temps,s.score);
 		fclose(pf);
 	}
 }
void meilleur_score(char filename[],scoreinfo tab[],SDL_Surface *screen)
{
	char message[20];
	texte txte;
 	int n=0;
 	int permut,j,i; 
 	scoreinfo s,tmp;
 	FILE* pf=NULL;
 	pf=fopen(filename,"r");
 	if (pf!=NULL)
 	{
 		while (!feof(pf))
        	{
            		fscanf(pf,"%s  %d  %d \n",s.playername,&s.temps,&s.score);
            		strcpy(tab[n].playername,s.playername); 	
            		tab[n].temps=s.temps;
            		tab[n].score=s.score;
            		n++;
            	}
            	fclose(pf);
 	}
 	 for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (tab[j].score < tab[j+1].score) {
                tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;
           			 }
       		 }
    		}
	TTF_Init(); 
	txte.police = TTF_OpenFont("Ubuntu-B.ttf",46);
	txte.color_txt.r=255;
	txte.color_txt.g=0;
	txte.color_txt.b=0;
	txte.pos_txt.x=100;
	txte.pos_txt.y=100;
	strcpy (message,"1-");
	strcat(message,tab[0].playername);
	strcat(message,"/2-");
	strcat(message,tab[1].playername);
	strcat(message,"/3-");
	strcat(message,tab[2].playername);
	txte.txt=TTF_RenderText_Blended(txte.police,message,txte.color_txt);
	SDL_BlitSurface(txte.txt,NULL,screen,&txte.pos_txt);
	 SDL_WM_SetCaption(message, NULL);	
}
void liberer_image(background b){
    SDL_FreeSurface(b.img);
}
void liberer_Music(Mix_Music *music){
	Mix_FreeMusic(music);
}
void liberer_Texte(texte txt){
	TTF_CloseFont(txt.police);
	TTF_Quit();
}
