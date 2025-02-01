#ifndef AI_H
#define AI_H

#include <jo/jo.h>
#include "globals.h"
#include "models3d.h"
#include "mechanics.h"



// Behaviours
void patrol(obj object[], int speed);
void movethenrotate(obj object[]);
void moveandrotate(obj object[]);
void	follow(obj subject[], obj target[], int speed, int stopdist);
void	flee(obj subject[], obj target[], int speed, int stopdist);
void	speechbubble(void);
void	cleartext(void);


// condition check variables
bool	inrange(obj subject[], obj target[], int range);




// NPC Behaviours
void	femaleai(void);
void	pickupai(void);
void	playerai(void);


#endif



