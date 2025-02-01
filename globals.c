
#include "globals.h"

int titlesprite = -1;


// 3D Variables
int cam_pos[3] = {0, 0, 0};
int cam_angle[3] = {0, 0, 0};
int cam_tar[3] = {0, 0, 0};
int dcpos[3] = {0, 0, 0}; 
int delta[3] = {0, 0, 0};
int camh = -80;
int flrmin = 0;
bool jumping = false;
bool colliding = false;
int jumpstart = 0;
int spd = 1;
int quadNo;


// Audio
jo_sound     hop;
jo_sound     step;


// Levels and events

bool textup = false;

int	level = 0;
int eventNo = 0;
bool nextLv = false;

bool pastry;
int caffeine;
int nicotine;
