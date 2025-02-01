
#include <jo/jo.h>
#include "levels.h"
#include "globals.h"
#include "models3d.h"
#include "mechanics.h"
#include "ai.h"
#include "display.h"
#include "modelLoader.h"

#include "level1.h"





//Objects

obj menu[] = {
	
		{.x = 0, .y = 0, .z = 0, .rx = 0, .ry = 90, .rz = 90, .sx = 0, .h = 0, .frame=0, .spd=1, .kff=0},
	
};


obj player[] = {
	{.x = 0, .y = 0, .z = 0, .rx = 0, .ry = 0, .rz = 0, .sx = 0, .h = 0, .frame=0, .spd=1, .kff=0},
	{.x = 0, .y = 0, .z = 0, .rx = 0, .ry = 0, .rz = 0, .sx = 0, .h = 0, .frame=0, .spd=1, .kff=0}
};

obj baguette[] = {
		
	{.x = 0, .y = 0, .z = -875, .rx = 0, .ry = 0, .rz = 0, .sx = 25, .sz = 25, .h = 25, .frame=1, .spd=1, .aistate=1},
    {.x = -50, .y = 0, .z = -990, .rx = 0, .ry = 0, .rz = 0, .sx = 25, .sz = 25, .h = 25, .frame=1},
    {.x = 50, .y = 0, .z = -920, .rx = 0, .ry = 0, .rz = 0, .sx = 25, .sz = 25, .h = 25, .frame=1},
		
};

obj marcel[] = {
		
	{.x = 500, .y = 0, .z = -630, .rx = 0, .ry = 0, .rz = 0, .sx = 1200, .sz = 20, .h = 200, .spd = 0, .aistate = 0},
		
};

obj	chefs[] = {
	
	{.x = 500, .y = 0, .z = -630, .rx = 0, .ry = 0, .rz = 0, .sx = 35, .sz = 35, .h = 80},
	{.x = 400, .y = 0, .z = -630, .rx = 0, .ry = 0, .rz = 0, .sx = 35, .sz = 35, .h = 80},
	{.x = -200, .y = 0, .z = -850, .rx = 0, .ry = 0, .rz = 0, .sx = 35, .sz = 35, .h = 80},
	
	
};





	
	
	
	
	
	
	
	//Level 2
	
 
  obj	towers[] = {
	  
	{.x = 600, .y = 0, .z = 600, .rx = 0, .ry = 90, .rz = 0, .sx = 100, .sz = 100, .h = 200},
	{.x = -600, .y = 0, .z = 600, .rx = 0, .ry = 90, .rz = 0, .sx = 100, .sz = 100, .h = 200},
	{.x = -600, .y = 0, .z = -600, .rx = 0, .ry = 90, .rz = 0, .sx = 100, .sz = 100, .h = 200},
	{.x = 600, .y = 0, .z = -600, .rx = 0, .ry = 90, .rz = 0, .sx = 100, .sz = 100, .h = 200},
	  
	  
  };
  
    obj	castlewalls[] = {
	  
	
	{.x = -630, .y = 0, .z = 0, .rx = 0, .ry = 90, .rz = 0, .sx = 20, .sz = 1200, .h = 200},
	{.x = 630, .y = 0, .z = 0, .rx = 0, .ry = 270, .rz = 0, .sx = 20, .sz = 1200, .h = 200},
	{.x = 0, .y = 0, .z = 630, .rx = 0, .ry = 180, .rz = 0, .sx = 1200, .sz = 20, .h = 200},
	
	  
	  
  };
  
	obj	castlegates[] = {
		
		
		{.x = 0, .y = 0, .z = -630, .rx = 0, .ry = 0, .rz = 0, .sx = 1200, .sz = 20, .h = 200},
		
		
	};
	
	
	obj townhouses[] = {
    {.x = 0, .y = 0, .z = 480, .rx = 0, .ry = 180, .rz = 0, .sx = 120, .sz = 120, .h = 540},
	
		{.x = 480, .y = 0, .z = -50, .rx = 0, .ry = 270, .rz = 0, .sx = 120, .sz = 120, .h = 540},
	
	{.x = -480, .y = 0, .z = -50, .rx = 0, .ry = 90, .rz = 0, .sx = 120, .sz = 120, .h = 540},
};


	obj	lv2casks[] = {
		
		{.x = -600, .y = 0, .z = -130, .rx = 0, .ry = 180, .rz = 0, .sx = 45, .sz = 45, .h = 60},
		
	};



	


void	load_lv_2(void){
	
	dcpos[0] = 0;
	dcpos[1] = 0;
    dcpos[2] = -500;
	
	cam_angle[1] = 0;
	eventNo = 0;
	
	player->x = dcpos[0] >> 5;
    player->y = dcpos[1] >> 5;
    player->z = dcpos[2] >> 5;
	
	cam_pos[0] = player->x - jo_sin_mult(150, cam_angle[1]);
	cam_pos[1] = player->y + camh;
	cam_pos[2] = player->z - jo_cos_mult(150, cam_angle[1]);
	
	
	cam_tar[0] = player->x ;
	cam_tar[1] = player->y - 70;
	cam_tar[2] = player->z;


	
	    jo_img_8bits img;

    // Load the new floor texture
    img.data = JO_NULL;
    jo_tga_8bits_loader(&img, JO_ROOT_DIR, "COBFLR.TGA", JO_COLOR_Transparent);

    // Update the floor texture
    jo_background_3d_plane_a_img(&img, image_pal.id, true, true);

    // Free the image memory
    jo_free_img(&img);
	
	castle = ML_LoadMesh("CASTLE.TMF", JO_ROOT_DIR, castleNo);
	townhouse = ML_LoadMesh("TH.TMF", JO_ROOT_DIR, townhouseNo);
	cask = ML_LoadMesh("CASK.TMF", JO_ROOT_DIR, caskNo);
	miniferg = ML_LoadMesh("CHEF.TMF", JO_ROOT_DIR, fergNo);
	
	jo_audio_play_cd_track(2, 2, true);
	}







	
	
	
	
	
	


	
	
	
	void	level_2(void){
		
		draw_planes();
		
		
		draw_mesh(&ferg[0], player, 1);
		draw_mesh(&castle[0], towers, 4);
		draw_mesh(&castle[1], castlewalls, 3);
		draw_mesh(&castle[2], castlegates, 1);
		draw_mesh(&townhouse[0], townhouses, 3);
		draw_mesh(&miniferg[0], baguette, 1);
		draw_mesh(&cask[0], lv2casks, 1);
		
		colliding = false;
		
		tpwall_collision(towers, 4);
		tpwall_collision(castlewalls, 3);
		tpwall_collision(castlegates, 1);
		tpwall_collision(townhouses, 3);
		tpwall_collision(baguette, 1);
		tpwall_collision(lv2casks, 1);
		
		
				
		playerai();
		chefai();
		tpscontrols();
		debug_menu();
		
		
		}
	
	
void	levels(void){
	
		
	switch (level) {
		
		case 0:	
	
	    load_lv_1();
        level = 1;
	break;
		
		
		case 1:	
	if (level = 1){
		level_1();
	}
	break;
	

		case 2:
	if	(level = 2){
		level_2();
	}
	break;
	
}
}
	
	
	
