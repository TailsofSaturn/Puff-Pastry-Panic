/*
Camera must always point at player, therefore player is always centered at cam_tar
Player movement due to input is always relative to camera position and angle, not player (no tank controls)
Player must have walk, jump, action and attack animations 
camera position should move in straight line towards player if over a certain distance away 
Camera must be affected by collission the same as the player (Can the camera go up if near wall, is there a min cam distance?)
*/

#include "mechanics.h"
#include "globals.h"
#include "display.h"
#include "models3d.h"
#include "levels.h"








void	jump(void)
{
	jo_audio_play_sound(&hop);
	int jumpmax = jumpstart - 60;
	if (dcpos[1] < (jumpmax*32)){
	jumping = false;
	player->frame = 0;}
else{
delta[1] = -60;
}
}


void fpscontrols(void)
{
   
  	   
    if (!jo_is_pad1_available())
        return;
    
    // Movement
    if (jo_is_pad1_key_pressed(JO_KEY_C))
        delta[1] = 32;
	{
	if (jo_is_pad1_key_pressed(JO_KEY_L))
        delta[0] = -32;
	else if (jo_is_pad1_key_pressed(JO_KEY_R))
        delta[0] = 32;
	else delta[0] = 0;
	}
    {
	if (jo_is_pad1_key_pressed(JO_KEY_DOWN))
        delta[2] = -32;
	else if (jo_is_pad1_key_pressed(JO_KEY_UP))
        delta[2] = 32;
	else delta[2] = 0;
    }
	if (jo_is_pad1_key_pressed(JO_KEY_LEFT))
        cam_angle[1] -= 3;
    if (jo_is_pad1_key_pressed(JO_KEY_RIGHT))
        cam_angle[1] += 3;
    if (jo_is_pad1_key_pressed(JO_KEY_START)) {}



// Bound Camera Angle
    if (cam_angle[1] > 360)
        cam_angle[1] -= 360;
    else if (cam_angle[1] <= 0)
        cam_angle[1] += 360;
	
	if (camh < -150){
	camh = -150;}
	if (camh > -10){
	camh = -10;}
	
	   // Gravity
	   flrmin = 0;
    if(delta[1] < 50)
	delta[1] = (delta[1]+10);


	
	    // Rate of change of Camera Position multiplied by 32 for more precision
    dcpos[0] += jo_cos_mult(delta[0], cam_angle[1]) + jo_sin_mult(delta[2],cam_angle[1]);
	dcpos[1] += delta[1];
    dcpos[2] += jo_cos_mult(delta[2], cam_angle[1]) - jo_sin_mult(delta[0], cam_angle[1]);
	
	player->x = dcpos[0] >> 5;
    player->y = dcpos[1] >> 5;
    player->z = dcpos[2] >> 5;
	
	
	cam_pos[0] = player->x;
    cam_pos[1] = player->y - 75;
    cam_pos[2] = player->z;

    // Fix Camera Target/Orientation
    cam_tar[0] = (cam_pos[0]) + (100 * jo_sin(cam_angle[1]) >> 15);
    cam_tar[1] = cam_pos[1];
    cam_tar[2] = (cam_pos[2]) + (100 * jo_cos(cam_angle[1]) >> 15);
	
	
	
    // Targeting
     static unsigned int i = 1;
    if (jo_is_pad1_key_pressed(JO_KEY_Z))
    {
        cam_angle[1] = jo_atan2f(casks[i].x - cam_pos[0], casks[i].z - cam_pos[2]);
        if (jo_is_pad1_key_pressed(JO_KEY_LEFT))
            delta[0] = -32;
        if (jo_is_pad1_key_pressed(JO_KEY_RIGHT))
            delta[0] = 32;
        if (jo_is_pad1_key_down(JO_KEY_X))
            ++i;
        if (jo_is_pad1_key_down(JO_KEY_Y))
           --i;
	   //why does going above 3 or below 0 cycle me onto different object types?
	   //because an array is a memory address and all are declared in sequence, therefore sequential memory addresses are sent indefinitely
    }

	if (dcpos[1] > flrmin)
	dcpos[1] = flrmin;
	
}




void	tpscontrols (void)
{
				
		if (jo_is_pad1_key_pressed(JO_KEY_C) && (dcpos[1] - flrmin > -320)){
		//revertfixedverts(Pointfergus, fergusstand,202, &fergus, player);
		jumpstart = player->y;
		player->frame = 0;
		jumping = true;
	}
	
	if (jumping == true){
	jump();}
	
	
	{
	if (jo_is_pad1_key_pressed(JO_KEY_DOWN)){
	delta[2] = -32*spd;}
	else if (jo_is_pad1_key_pressed(JO_KEY_UP)){
	delta[2] = 32*spd;}
	else {delta[2] = 0;}
	}
	{
    if (jo_is_pad1_key_pressed(JO_KEY_LEFT)){
	delta[0] = -32*spd;}
	else if (jo_is_pad1_key_pressed(JO_KEY_RIGHT)){
	delta[0] = 32*spd;}
	else {delta[0] = 0;}
	}
	if (jo_is_pad1_key_pressed(JO_KEY_R))
        cam_angle[1] += 1;
	if (jo_is_pad1_key_pressed(JO_KEY_L))
        cam_angle[1] -= 1;
	if (jo_is_pad1_key_pressed(JO_KEY_Z))
        camh += 1;
	if (jo_is_pad1_key_pressed(JO_KEY_Y))
        camh -=1;
	
	{
	if (jo_is_pad1_key_pressed(JO_KEY_B)){
	spd= 3 + caffeine;}
	else {spd=2;}
	}
	



	

	
    // Bound Camera Angle
    if (cam_angle[1] > 180)
        cam_angle[1] -= 360;
    else if (cam_angle[1] <= -180)
        cam_angle[1] += 360;
	
	if (camh < -150){
	camh = -150;}
	if (camh > -10){
	camh = -10;}
	
	   // Gravity
	
    if(delta[1] < 80)
	delta[1] = (delta[1]+10);


	
	    // Rate of change of Camera Position multiplied by 32 for more precision
    dcpos[0] += jo_cos_mult(delta[0], cam_angle[1]) + jo_sin_mult(delta[2],cam_angle[1]);
	dcpos[1] += delta[1];
    dcpos[2] += jo_cos_mult(delta[2], cam_angle[1]) - jo_sin_mult(delta[0], cam_angle[1]);
	
	player->x = dcpos[0] >> 5;
    player->y = dcpos[1] >> 5;
    player->z = dcpos[2] >> 5;
	
	cam_pos[0] = player->x - jo_sin_mult(150, cam_angle[1]);
	cam_pos[1] = player->y + camh;
	cam_pos[2] = player->z - jo_cos_mult(150, cam_angle[1]);

	
	cam_tar[0] = player->x ;
	cam_tar[1] = player->y - 70;
	cam_tar[2] = player->z;
	if (delta[0] != 0 || delta[2]!=0)
	{	
	player->ry = cam_angle[1] + angleab(delta[0], delta[2]);
	}
	
if (dcpos[1] > flrmin)
	dcpos[1] = flrmin;

}





//Collision

//Walls


void	wall_collision(obj walls[], int numobj){
	flrmin = 0;
int i;
for(i=0; i < numobj; i++)
{
	
if (((cam_pos[0]) >= (walls[i].x - walls[i].sx)) && ((cam_pos[0]) <= (walls[i].x - (walls[i].sx-10))) && ((cam_pos[2]) <= ((walls[i].z)+(walls[i].sz-10))) && ((cam_pos[2]) >= ((walls[i].z)-(walls[i].sz-10))))
{dcpos[0] = ((walls[i]).x - walls[i].sx)<<4;}

if (((cam_pos[0]) <= ((walls[i]).x + walls[i].sx)) && ((cam_pos[0]) >= ((walls[i].x) + (walls[i].sx-10))) && ((cam_pos[2]) <= ((walls[i].z)+(walls[i].sz-10))) && ((cam_pos[2]) >= ((walls[i].z)-(walls[i].sz-10))))
{dcpos[0] = ((walls[i]).x + walls[i].sx)<<4;}

if (((cam_pos[2]) <= ((walls[i]).z + walls[i].sz)) && ((cam_pos[2]) >= ((walls[i].z) + (walls[i].sz-10))) && ((cam_pos[0]) <= ((walls[i].x)+(walls[i].sx-10))) && ((cam_pos[0]) >= ((walls[i].x)-(walls[i].sx-10))))
{dcpos[2] = ((walls[i]).z + walls[i].sz)<<4;}

if (((cam_pos[2]) >= ((walls[i]).z - walls[i].sz)) && ((cam_pos[2]) <= ((walls[i].z) - (walls[i].sz-10))) && ((cam_pos[0]) <= ((walls[i].x)+(walls[i].sx-10))) && ((cam_pos[0]) >= ((walls[i].x)-(walls[i].sx-10))))
{dcpos[2] = ((walls[i]).z - walls[i].sz)<<4;}
}
}







void	tpwall_collision(obj walls[], int numobj){

	
int i;
for(i=0; i < numobj; i++)
{
	if (((player->y) > walls[i].y - walls[i].h)){
	
if (((player->x) > (walls[i].x - walls[i].sx)) && ((player->x) < (walls[i].x - (walls[i].sx-10))) && ((player->z) < ((walls[i].z)+(walls[i].sz-10))) && ((player->z) > ((walls[i].z)-(walls[i].sz-10))))
{
dcpos[0] = ((walls[i]).x - walls[i].sx)<<5;
}

if (((player->x) < ((walls[i]).x + walls[i].sx)) && ((player->x) > ((walls[i].x) + (walls[i].sx-10))) && ((player->z) < ((walls[i].z)+(walls[i].sz-10))) && ((player->z) > ((walls[i].z)-(walls[i].sz-10))))
{
dcpos[0] = ((walls[i]).x + walls[i].sx)<<5;
}

if (((player->z) < ((walls[i]).z + walls[i].sz)) && ((player->z) > ((walls[i].z) + (walls[i].sz-10))) && ((player->x) < ((walls[i].x)+(walls[i].sx-10))) && ((player->x) > ((walls[i].x)-(walls[i].sx-10))))
{
dcpos[2] = ((walls[i]).z + walls[i].sz)<<5;
}

if (((player->z) > ((walls[i]).z - walls[i].sz)) && ((player->z) < ((walls[i].z) - (walls[i].sz-10))) && ((player->x) < ((walls[i].x)+(walls[i].sx-10))) && ((player->x) > ((walls[i].x)-(walls[i].sx-10))))
{
dcpos[2] = ((walls[i]).z - walls[i].sz)<<5;
}
}
}

if (colliding == false){
	int j;
for(j=0; j < numobj; j++){
if (((player->x) >= (walls[j].x - walls[j].sx + 30)) && ((player->x) <= (walls[j].x + walls[j].sx - 30)) && ((player->z) <= ((walls[j].z)+walls[j].sz - 30)) && ((player->z) >= ((walls[j].z)-walls[j].sz + 30)) )
{	
	flrmin = (walls[j].y - walls[j].h)<<5;
	if (dcpos[1] > flrmin)
	dcpos[1] = flrmin;
	colliding = true;
	break;}
	else {
	flrmin = 0;}
}
}
}


void	npc_wall_collision(obj npc[], obj walls[], int numobj){
	
int i;
for(i=0; i < numobj; i++)
{
	if (((npc[0].y) > walls[i].y - walls[i].h)){
	
if (((npc[0].x) > (walls[i].x - walls[i].sx)) && ((npc[0].x) < (walls[i].x - (walls[i].sx-10))) && ((npc[0].z) < ((walls[i].z)+(walls[i].sz-10))) && ((npc[0].z) > ((walls[i].z)-(walls[i].sz-10))))
{
npc[0].x = ((walls[i]).x - walls[i].sx);
}

if (((npc[0].x) < ((walls[i]).x + walls[i].sx)) && ((npc[0].x) > ((walls[i].x) + (walls[i].sx-10))) && ((npc[0].z) < ((walls[i].z)+(walls[i].sz-10))) && ((npc[0].z) > ((walls[i].z)-(walls[i].sz-10))))
{
npc->x = ((walls[i]).x + walls[i].sx);
}

if (((npc[0].z) < ((walls[i]).z + walls[i].sz)) && ((npc[0].z) > ((walls[i].z) + (walls[i].sz-10))) && ((npc[0].x) < ((walls[i].x)+(walls[i].sx-10))) && ((npc[0].x) > ((walls[i].x)-(walls[i].sx-10))))
{
npc[0].z = ((walls[i]).z + walls[i].sz);
}

if (((npc[0].z) > ((walls[i]).z - walls[i].sz)) && ((npc[0].z) < ((walls[i].z) - (walls[i].sz-10))) && ((npc[0].x) < ((walls[i].x)+(walls[i].sx-10))) && ((npc[0].x) > ((walls[i].x)-(walls[i].sx-10))))
{
npc[0].z = ((walls[i]).z - walls[i].sz);
}
}
}



}


// Terrain

void	terrain_collision(obj mounds[], int numobj){
	
if (colliding == false){
	if (dcpos[1] > flrmin)
	dcpos[1] = flrmin;
	
	int i;
for(i=0; i < numobj; i++)
if (((player->x) >= (mounds[i].x - mounds[i].sx)) && ((player->x) <= (mounds[i].x + mounds[i].sx)) && ((player->z) <= ((mounds[i].z)+mounds[i].sz)) && ((player->z) >= ((mounds[i].z)-mounds[i].sz)))
{	

	flrmin = ((mounds[i].y - mounds[i].h))<<5;
	if (dcpos[1] > flrmin)
	dcpos[1] = flrmin;
break;
}
else flrmin = 0;
}
}






void	npc_terrain_collision(obj npc[], obj mounds[], int numobj){
	

	
	int i;
for(i=0; i < numobj; i++){
if (((npc[0].x) >= (mounds[i].x - mounds[i].sx)) && ((npc[0].x) <= (mounds[i].x + mounds[i].sx)) && ((npc[0].z) <= ((mounds[i].z)+mounds[i].sz)) && ((npc[0].z) >= ((mounds[i].z)-mounds[i].sz)))
{	

npc[0].y = ((mounds[i].y - mounds[i].h));

break;
}
else
{
	npc[0].y = 0;
}
}
}



void	modelview (jo_3d_mesh *mesh)
{
	unsigned int facecount = mesh->data.nbPolygon;
	jo_fixed cam_tar[3] = {player->x, player->y, player->z};
	jo_3d_camera_set_viewpoint(&cam, 0, 0, -50);
	
	

if (jo_is_pad1_key_down(JO_KEY_L)){
if(quadNo>0)
--quadNo;

}
if (jo_is_pad1_key_down(JO_KEY_R)){
	if (quadNo < (facecount-1)){
++quadNo;}}

if (jo_is_pad1_key_pressed(JO_KEY_UP))
++player->rx;
if (jo_is_pad1_key_pressed(JO_KEY_DOWN))
--player->rx;
if (jo_is_pad1_key_pressed(JO_KEY_X))
++player->z;
if (jo_is_pad1_key_pressed(JO_KEY_A))
--player->z;
if (jo_is_pad1_key_pressed(JO_KEY_Y))
--player->x;
if (jo_is_pad1_key_pressed(JO_KEY_B))
--player->y;
if (jo_is_pad1_key_pressed(JO_KEY_Z))
++player->y;
if (jo_is_pad1_key_pressed(JO_KEY_C))
++player->x;
if (jo_is_pad1_key_pressed(JO_KEY_RIGHT))
++player->ry;
if (jo_is_pad1_key_pressed(JO_KEY_LEFT))
--player->ry;

	jo_3d_set_mesh_polygon_screen_doors(&mesh[0], true, quadNo);

	if (quadNo > 0){
	jo_3d_set_mesh_polygon_screen_doors(&mesh[0], false, quadNo-1);}
	if (quadNo < (facecount-1)){
		jo_3d_set_mesh_polygon_screen_doors(&mesh[0], false, quadNo+1);}

jo_printf(0, 2, "Polygon No: %4d", quadNo);

}