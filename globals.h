#ifndef GLOBALS_H
#define GLOBALS_H

#include <jo/jo.h>


typedef struct {
    int x;
    int y;
    int z;
    int rx;
    int ry;
    int rz;
    int sx;
	int sz;
	int h;
	int frame;
	int spd;
	int aistate;
	int kff;
	} obj;


extern int titlesprite;



//Objects
extern obj menu[];

extern obj player[];
extern obj chefs[];
extern obj baguette[];

extern obj houses[];
extern obj mounds[];
extern obj casks[];
extern obj females[];
extern obj keyfs[];
extern obj trees[];
extern obj boulders[];
extern obj cars[];
extern obj cliffs[];
extern obj croissants[];
extern obj treewalls[];
extern obj	towers[];
extern obj	castlewalls[];
extern obj	castlegates[];

extern obj	townhouses[];
extern obj	lferg[];
extern obj	lv2casks[];



//3D Variables
extern jo_camera cam;
extern jo_palette image_pal;

extern int cam_pos[3];
extern int cam_angle[3];
extern int cam_tar[3];
extern int dcpos[3];
extern int delta[3];
extern int camh;

extern int flrmin;
extern bool jumping;
extern bool colliding;
extern int jumpstart;
extern int spd;


//Audio

extern jo_sound     hop;
extern jo_sound     step;
extern int quadNo;


// Levels and events

extern bool textup;

extern int level;
extern int eventNo;
extern bool nextLv;

extern bool pastry;
extern int caffeine;
extern int nicotine;


#endif