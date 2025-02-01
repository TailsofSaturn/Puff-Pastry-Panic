#ifndef CONTROLS_H
#define CONTROLS_H

#include <jo/jo.h>
#include "globals.h"
//#include "display.h"
#include "models3d.h"

void controls(void);

void	fpscontrols(void);

void	tpscontrols(void);

void	wall_collision(obj walls[], int numobj);

void	tpwall_collision(obj walls[], int numobj);

void	terrain_collision(obj mounds[], int numobj);

void	modelview (jo_3d_mesh *mesh);

void	jump(void);


void	npc_wall_collision(obj npc[], obj walls[], int numobj);
void	npc_terrain_collision(obj npc[], obj mounds[], int numobj);



#endif // CONTROLS_H
