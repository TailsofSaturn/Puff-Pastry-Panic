
#include <jo/jo.h>

#include "globals.h"
#include "models3d.h"
#include "mechanics.h"
#include "ai.h"
#include "modelLoader.h"
#include "levels.h"
#include "display.h"
#include "level1.h"


obj houses[] = {

    {.x = -400, .y = 0, .z = 300, .rx = 0, .ry = 180, .rz = 0, .sx = 200, .sz = 200, .h = 200},
    {.x = 600, .y = 0, .z = 250, .rx = 0, .ry = 0, .rz = 0, .sx = 200, .sz = 200, .h = 200},
    {.x = 130, .y = 0, .z = 920, .rx = 0, .ry = -90, .rz = 0, .sx = 200,.sz = 200, .h = 200, .frame=0},

};

obj mounds[] = {
    {.x = 0, .y = 0, .z = -875, .rx = 0, .ry = 0, .rz = 0, .sx = 25, .sz = 25, .h = 25, .frame=1, .spd=1, .aistate=1},
    {.x = -50, .y = 0, .z = -990, .rx = 0, .ry = 0, .rz = 0, .sx = 25, .sz = 25, .h = 25, .frame=1},
    {.x = 50, .y = 0, .z = -920, .rx = 0, .ry = 0, .rz = 0, .sx = 25, .sz = 25, .h = 25, .frame=1},
};


obj casks[] = {

    {.x = -580, .y = -60, .z = 95, .rx = 0, .ry = 60, .rz = 0, .sx = 45, .sz = 45, .h = 120, .frame=0},
    {.x = -580, .y = 0, .z = 92, .rx = 0, .ry = 0, .rz = 0, .sx = 45, .sz = 45, .h = 60, .frame=0},
    {.x = -500, .y = 0, .z = -1125, .rx = 0, .ry = 30, .rz = 0, .sx = 45, .sz = 45, .h = 60, .frame=0},
};


obj females[] = {
    {.x = -180, .y = 0, .z = 600, .rx = 0, .ry = -135, .rz = 0, .sx = 35, .sz = 35, .h = 80, .frame=0, .spd=1, .aistate=1},
    {.x = -180, .y = 0, .z = 600, .rx = 0, .ry = -225, .rz = 0, .sx = 35, .sz = 35, .h = 80, .frame=0, .spd=1},
    {.x = 180, .y = 0, .z = 0, .rx = 0, .ry = -45, .rz = 0, .sx = 35, .sz = 35, .h = 80, .frame=0, .spd=1},
};

obj croissants[] = {
    {.x =-520, .y = -100, .z = -1700, .rx = 0, .ry = 135, .rz = 0, .sx = 35, .sz = 35, .h = 80, .frame=0, .spd=1, .aistate=1},
};

obj keyfs[] = {
    {.x = 10, .y = -22, .z = 0, .rx = 0, .ry = 0, .rz = 0, .sx = 35, .h = 60, .frame=0},
    {.x = 10, .y = -22, .z = 0, .rx = 0, .ry = 0, .rz = 0, .sx = 35, .h = 60, .frame=0}, // mid up
    {.x = 10, .y = -18, .z = 10, .rx = 30, .ry = 0, .rz = 0, .sx = 35, .h = 60, .frame=0}, // forward
    {.x = 10, .y = -20, .z = 0, .rx = 0, .ry = 0, .rz = 0, .sx = 35, .h = 60, .frame=0}, // mid down
    {.x = 10, .y = -18, .z = -10, .rx = -30, .ry = 0, .rz = 0, .sx = 35, .h = 60, .frame=0}, // back
};

obj trees[] = {
	{.x = 505, .y = 0, .z = 630, .rx = 0, .ry = 0, .rz = 0, .sx = 50, .sz = 50, .h = 400, .frame=0},
	{.x = 405, .y = 0, .z = -1550, .rx = 0, .ry = 37, .rz = 0, .sx = 50, .sz = 50, .h = 400, .frame=0},
	{.x = 125, .y = 0, .z = -680, .rx = 0, .ry = 112, .rz = 0, .sx = 50, .sz = 50, .h = 400, .frame=0},
};

obj boulders[] = {
	{.x = -680, .y = 0, .z = -640, .rx = 0, .ry = 0, .rz = 0, .sx = 125, .sz = 125, .h = 100, .frame=0},
	{.x = 680, .y = 0, .z = -660, .rx = 0, .ry = 0, .rz = 0, .sx = 125, .sz = 125, .h = 100, .frame=0},
	{.x = -520, .y = 0, .z = -1700, .rx = 0, .ry = 0, .rz = 0, .sx = 125, .sz = 125, .h = 100, .frame=0},
	{.x = -520, .y = 0, .z = -1250, .rx = 0, .ry = 0, .rz = 0, .sx = 125, .sz = 125, .h = 100, .frame=0},
};


obj cars[] = {
	{.x = -90, .y = 0, .z = 920, .rx = 0, .ry = 0, .rz = 0, .sx = 65, .sz = 125, .h = 100, .frame=0},
	};
	

obj cliffs[] = {
		{.x = 0, .y = 0, .z = -1950, .rx = 0, .ry = -90, .rz = 0, .sx = 600, .sz = 120, .h = 400, .frame=0},
		{.x = 660, .y = 0, .z = -1340, .rx = 0, .ry = 180, .rz = 0, .sx = 120, .sz = 600, .h = 400, .frame=0},
		{.x = -660, .y = 0, .z = -1340, .rx = 0, .ry = 0, .rz = 0, .sx = 120, .sz = 600, .h = 400, .frame=0},
		{.x = -1380, .y = 0, .z = -750, .rx = 0, .ry = -90, .rz = 0, .sx = 120, .sz = 600, .h = 400, .frame=0},
		{.x = 1380, .y = 0, .z = -750, .rx = 0, .ry = -90, .rz = 0, .sx = 120, .sz = 600, .h = 400, .frame=0},
	};
	
	
obj treewalls[] = {
	{.x = 730, .y = 0, .z = -430, .rx = 0, .ry = 180, .rz = 0, .sx = 10, .sz = 190, .h = 400, .frame=0},
	{.x = -615, .y = 0, .z = -390, .rx = 0, .ry = 0, .rz = 0, .sx = 10, .sz = 190, .h = 400, .frame=0},
	{.x = -615, .y = 0, .z = -40, .rx = 0, .ry = 0, .rz = 0, .sx = 10, .sz = 190, .h = 400, .frame=0},
	{.x = 730, .y = 0, .z = -80, .rx = 0, .ry = 180, .rz = 0, .sx = 10, .sz = 190, .h = 400, .frame=0},
	{.x = 600, .y = 0, .z = 600, .rx = 0, .ry = 180, .rz = 0, .sx = 10, .sz = 190, .h = 400, .frame=0},
	{.x = 600, .y = 0, .z = 940, .rx = 0, .ry = 180, .rz = 0, .sx = 10, .sz = 190, .h = 400, .frame=0},
	{.x = 450, .y = 0, .z = 1110, .rx = 0, .ry = 90, .rz = 0, .sx = 190, .sz = 10, .h = 400, .frame=0},
	{.x = -550, .y = 0, .z = 630, .rx = 0, .ry = 0, .rz = 0, .sx = 10, .sz = 190, .h = 400, .frame=0},
	{.x = -550, .y = 0, .z = 970, .rx = 0, .ry = 0, .rz = 0, .sx = 10, .sz = 190, .h = 400, .frame=0},

	
	};




// Level 1 Initialise

	void	load_lv_1(void){
	
	loadHUD();
	loadsfx();

	eventNo = 0;
	pastry == false;
	caffeine = 0;
	nicotine = 0;
	
	jo_set_tga_palette_handling(my_tga_palette_handling);
	init_3d_planes("GRASS.TGA", "SKY.TGA");
	
	ferg = ML_LoadMesh("FERG.TMF", JO_ROOT_DIR, fergNo);
	miniferg = ML_LoadMesh("MINIFERG.TMF", JO_ROOT_DIR, fergNo);
	house = ML_LoadMesh("HOUSE.TMF", JO_ROOT_DIR, houseNo);
	treewall = ML_LoadMesh("TREEWALL.TMF", JO_ROOT_DIR, treewallNo);
	boulder = ML_LoadMesh("BOULDER.TMF", JO_ROOT_DIR, boulderNo);
	croissant = ML_LoadMesh("CRSNT.TMF", JO_ROOT_DIR, croissantNo);
	cliff = ML_LoadMesh("CLIFF.TMF", JO_ROOT_DIR, cliffNo);
	car = ML_LoadMesh("CAR.TMF", JO_ROOT_DIR, carNo);
	tree = ML_LoadMesh("TREE.TMF", JO_ROOT_DIR, treeNo);
	female = ML_LoadMesh("NPC.TMF", JO_ROOT_DIR, femaleNo);
	cask = ML_LoadMesh("CASK.TMF", JO_ROOT_DIR, caskNo);
	chef =  ML_LoadMesh("CHEF.TMF", JO_ROOT_DIR, caskNo);
	
	jo_audio_play_cd_track(2, 2, true);
	
			
	}
	
	
	
	// Level 1 De-Initialise
	
	void	unload_Lv_1(void){
	
	//unload_mesh(miniferg, 4);
	unload_mesh(house, 1);
	unload_mesh(treewall, 1);
	unload_mesh(boulder, 1);
	unload_mesh(croissant, 1);
	unload_mesh(cliff, 1);
	unload_mesh(car, 1);
	unload_mesh(tree, 1);
	unload_mesh(female, 4);
	unload_mesh(cask, 1);
	unload_mesh(miniferg, 4);
			}
			
			
			
			
//AI
	void	femaleai(void){
	
	//always do
	// animation
	{
	if(females[0].spd != 0){
		interpolate_fixedverts(female[0].data.pntbl, female[3].data.pntbl, female[2].data.pntbl, female[3].data.pntbl, female[2].data.pntbl, 5, 129, female, females);}
	else 
	revertfixedverts(female[0].data.pntbl, female[1].data.pntbl, 129, &female, females);
	}
	
	//colission
	{
	npc_wall_collision(females, houses, 3);
	npc_wall_collision(females, casks, 3);
	npc_wall_collision(females, boulders, 4);
	npc_wall_collision(females, trees, 3);
	npc_wall_collision(females, treewalls, 9);
	npc_wall_collision(females, cliffs, 3);
	}
	
	//movement
	{
	if(inrange(females, player, 200) == true){
	follow(females, player, 1, 70); 
	}
	else{
	patrol(females, 1);}
	}

	
	//events
	
	
	
	if(eventNo == 0){
	if (inrange(females, player, 400)){
	if(inrange(females, player, 70) == true){
		speechbubble();
		jo_printf(25, 2, "Hello Jean.Your");
		jo_printf(25, 3, "froglets were");
		jo_printf(25, 4, "arguing in the");
		jo_printf(25, 5, "meadow. Then");
		jo_printf(25, 6, "one ran off.");
	}
	else {
	cleartext();
	}}}
	
	else if (eventNo == 1){
	if (inrange(females, player, 400)){
	if(inrange(females, player, 70) == true){
		speechbubble();
		jo_printf(25, 2, "You look tired.");
		jo_printf(25, 3, "Drink some   ");
		jo_printf(25, 4, "coffe and have");
		jo_printf(25, 5, "a cigarette.");
		jo_printf(25, 6, " [A]         ");
		
		if (jo_is_pad1_key_pressed(JO_KEY_A)){
		caffeine += 1;
		nicotine += 1;
		cleartext();}
		}
	}
	else {
	cleartext();
	}}
	}
	
	

	
	void	minifergAI(void){
	// collission and animation
	{
	if(baguette[0].spd != 0){
		interpolate_fixedverts(miniferg[0].data.pntbl, miniferg[2].data.pntbl, miniferg[3].data.pntbl, miniferg[2].data.pntbl, miniferg[3].data.pntbl, 5, 88, miniferg, baguette);}
	else 
	{revertfixedverts(miniferg[0].data.pntbl, miniferg[1].data.pntbl, 88, &miniferg, baguette);}
	}

	//collissions 
	{
	npc_wall_collision(baguette, houses, 3);
	npc_wall_collision(baguette, casks, 3);
	npc_wall_collision(baguette, boulders, 4);
	npc_wall_collision(baguette, trees, 3);
	npc_wall_collision(baguette, treewalls, 9);
	npc_wall_collision(baguette, cliffs, 3);
	npc_wall_collision(baguette, females, 1);
	npc_wall_collision(baguette, chefs, 1);
	}
	
	//events
	
	if (eventNo==0){
	
	if (!inrange(baguette, player, 400)){
	patrol(baguette, 1);
	}
	if(inrange(baguette, player, 400)){
	if(inrange(baguette, player, 100) == true){
	speechbubble();
	jo_printf(25, 1, "Papa! I 'ave ");
	jo_printf(25, 2, "lost eet!");
	jo_printf(25, 3, "Ze croissant");
	jo_printf(25, 4, "eess up on ze");
	jo_printf(25, 5, "bouldaire!");
	jo_printf(25, 6, "...can you get");
	jo_printf(25, 7, "eet back?");
	}
	else {
	cleartext();
	}}}
		
	if (eventNo==1){
	
	if (!inrange(baguette, player, 400)){
	patrol(baguette, 1);
	}
	if(inrange(baguette, player, 400)){
	if(inrange(baguette, player, 100) == true){
	speechbubble();
	jo_printf(25, 1, "Cant you make");
	jo_printf(25, 2, "zat jump?");
	jo_printf(25, 3, "per'aps you ");
	jo_printf(25, 4, "need a coffee");
	jo_printf(25, 5, "to wek you");
	jo_printf(25, 6, "up a beet.    ");
	jo_printf(25, 7, "         ");
	}
	else {
	cleartext();
	}}}
		
	else if (eventNo == 2){
		
	if(inrange(baguette, chefs, 300) == true){
	flee(baguette, chefs, -3, 500); 
	}	
	else if(inrange(baguette, player, 300) == true){
	follow(baguette, player, 3, 70); 
	}}}
	
	
	
		void	chefai(void){
		
	//always
	
	//animation
	if(chefs[0].spd > 0){
	interpolate_fixedverts(chef[0].data.pntbl, chef[2].data.pntbl, chef[3].data.pntbl, chef[2].data.pntbl, chef[3].data.pntbl, 5, 129, chef, chefs);	
	}
	
	//colission
	npc_wall_collision(chefs, houses, 3);
	npc_wall_collision(chefs, casks, 3);
	npc_wall_collision(chefs, boulders, 4);
	npc_wall_collision(chefs, trees, 3);
	npc_wall_collision(chefs, treewalls, 9);
	npc_wall_collision(chefs, cliffs, 3);
	npc_wall_collision(chefs, females, 1);
	npc_wall_collision(chefs, baguette, 1);
	
	
	//events
	
	if (eventNo == 2){
	if(inrange(chefs, player, 400) == true){
	follow(chefs, player, 3, 40); 
	}
	else{
	patrol(chefs, 1);}
	}
	}
	
	
	
	
		//Level 1 Draw objects	
	
	void	level_1(void){
		
		
	
		//Draw
	
	if (nextLv){

		unload_Lv_1();
		load_lv_2();
		level = 2;
	}
	else {
	
	

	
	
	
	draw_planes();

	draw_mesh(&ferg[0], player, 1);
    draw_mesh(&house[0], houses, 3);
    draw_mesh(&cask[0], casks, 3);
    draw_mesh(&female[0], females, 1);
	draw_mesh(&miniferg[0], baguette, 1);
	draw_mesh(&tree[0], trees, 3);
	draw_mesh(&boulder[0], boulders, 4);
	draw_mesh(&car[0], cars, 1);
	draw_mesh(&cliff[0], cliffs, 5);
	draw_mesh(&croissant[0], croissants, 1);
	draw_mesh(&treewall[0], treewalls, 9);
	draw_mesh(&chef[0], chefs, 1);
		

		
		//Colission
		
	colliding = false;
	
	tpwall_collision(houses, 3);
	tpwall_collision(casks, 3);
	tpwall_collision(females, 1);
	tpwall_collision(trees, 3);
	tpwall_collision(boulders, 4);
	tpwall_collision(cars, 1);
	tpwall_collision(cliffs, 3);
	tpwall_collision(treewalls, 9);
	tpwall_collision(baguette, 1);
	tpwall_collision(chefs, 1);
		
		
		//Behaviours
	femaleai();
	minifergAI();
	chefai();
	pickupai();
	playerai();
	tpscontrols();
	
	
			// event triggers
			{
	if (eventNo == 0){ 
	if (colliding == true){
	eventNo += 1;}}

	else if (eventNo == 1){ 
	if(caffeine > 0){
	eventNo = 2;}}
		
	else if (eventNo == 2){
	if(pastry == 1){
	eventNo = 3;}}
	
	
	
	if(eventNo == 3){
	if (inrange(player, cars, 100)){
		
	nextLv = true;
	}}
	
	}
			
			
	
	debug_menu();
	
	}
	}