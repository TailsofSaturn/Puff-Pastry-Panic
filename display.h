#ifndef DISPLAY_H
#define DISPLAY_H

#include <jo/jo.h>
#include "globals.h"





int distance(int x1, int x2, int z1, int z2); 
int distancesqr(int x1, int x2, int z1, int z2);
int angleab(int distx, int distz);
jo_fixed interpolate(jo_fixed v1, jo_fixed v2, jo_fixed t);


// Animation

   bool sameint(int verts1[][3], int verts2[][3], int numverts);

   bool samefixed(jo_fixed verts1[][3], jo_fixed verts2[][3], int numverts);


	
	
		void	interpolate_intverts(int verts[][3],int verts1[][3],int verts2[][3],int verts3[][3],int verts4[][3], int frames, int numverts, jo_3d_mesh *mesh);

		void	interpolate_fixedverts(jo_fixed verts[][3],jo_fixed verts1[][3], jo_fixed verts2[][3], jo_fixed verts3[][3], jo_fixed verts4[][3], jo_fixed interval, int numverts, jo_3d_mesh *mesh, obj object[]);

		void 	revertfixedverts(jo_fixed verts[][3],jo_fixed verts1[][3],int numverts, jo_3d_mesh *mesh, obj object[]);





//Display



void debug_menu(void);
void draw_mesh(jo_3d_mesh *mesh, obj position[], int numobj);
jo_palette *my_tga_palette_handling(void);
void init_3d_planes(const char* floor_tga_filename, const char* sky_tga_filename);

void            title();
void	loadTitle(void);



#endif
