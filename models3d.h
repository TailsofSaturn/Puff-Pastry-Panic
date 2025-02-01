#ifndef MODELS3D_H
#define MODELS3D_H

#include <jo/jo.h>
#include "globals.h"

	const enum texid{
		BUBBLE
		
	};
	

	
void	loadHUD(void);


void	loadsfx(void);

extern	int* numverts;

extern	jo_3d_mesh*   car;
extern int* carNo;

extern jo_3d_mesh*    boulder;
extern int* boulderNo;

extern jo_3d_mesh*    house;
extern int* houseNo;

extern jo_3d_mesh*    female;
extern int* femaleNo;

extern jo_3d_mesh*    ferg;
extern int* fergNo;

extern jo_3d_mesh*   tree;
extern int* treeNo;

extern jo_3d_mesh*    cliff;
extern int* cliffNo;

extern jo_3d_mesh*    croissant;
extern int* croissantNo;

extern jo_3d_mesh*    treewall;
extern int* treewallNo;

extern jo_3d_mesh*    townhouse;
extern int* townhouseNo;

extern	jo_3d_mesh*         cask;
extern int* caskNo;

extern	jo_3d_mesh*   castle;
extern int* castleNo;

extern	jo_3d_mesh*   castle2;
extern int* castle2No;

extern jo_3d_mesh*    miniferg;
extern int* minifergNo;


extern jo_3d_mesh*    chef;

extern jo_3d_mesh*   titlescreen;


extern jo_img* bg;


void    unload_mesh(jo_3d_mesh* mesh, int meshNo);



#endif