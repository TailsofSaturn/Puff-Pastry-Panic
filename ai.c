#include "ai.h"
#include "globals.h"
#include "models3d.h"
#include "mechanics.h"
#include "levels.h"



void movethenrotate(obj object[]) {
    static int state = 1;  // Initial state

    switch (state) {
        case 1:
            if (object[0].z != object[1].z ) {
			object[0].z += (object[1].z - object[2].z) / 600;}
			if (object[0].x != object[1].x){
				object[0].x += (object[1].x - object[2].x) / 300;
            }
			else {
                state = 2;  // Transition to turn around state
            }
            break;

        case 2:
            if (object[0].ry != object[1].ry) {
                ++object[0].ry;
            }
			else {
                state = 3;  // Transition to move backward state
            }
            break;

        case 3:
            if (object[0].z != object[2].z) {
			object[0].z += (object[2].z - object[1].z) / 600;}
			if (object[0].x != object[2].x){
				object[0].x += (object[2].x - object[1].x) / 300;
				
            }
			else {
                state = 4;  // Transition to reset state
            }
            break;

        case 4:
            if (object[0].ry != object[2].ry) {
                --object[0].ry;
            } 
			else {
                state = 1;  // Transition back to move forward state
            }
            break;
    }
}


void moveandrotate(obj object[]) {
   
	
	static int state = 1;  // Initial state

    switch (state) {
        case 1:
            if (object[0].y != object[2].y) {
			object[0].y += (object[2].y - object[1].y) / 6;}
			if (object[0].z != object[2].z) {
			object[0].z += (object[2].z - object[1].z) / 6;}
			if (object[0].rx != object[2].rx) {
			object[0].rx += (object[2].rx - object[1].rx) / 6;}
            else {
                state = 2;  // Transition to turn around state
            }
            break;

           case 2:
            if (object[0].y != object[3].y) {
			object[0].y += (object[3].y - object[2].y) / 6;}
			if (object[0].z != object[3].z) {
			object[0].z += (object[3].z - object[2].z) / 6;}
			if (object[0].rx != object[3].rx) {
			object[0].rx += (object[3].rx - object[2].rx) / 6;}
            else {
                state = 3;  // Transition to turn around state
            }
            break;

          case 3:
            if (object[0].y != object[4].y) {
			object[0].y += (object[4].y - object[3].y) / 6;}
			if (object[0].z != object[4].z) {
			object[0].z += (object[4].z - object[3].z) / 6;}
			if (object[0].rx != object[4].rx) {
			object[0].rx += (object[4].rx - object[3].rx) / 6;}
            else {
                state = 4;  // Transition to turn around state
            }
            break;

             case 4:
            if (object[0].y != object[1].y) {
			object[0].y += (object[1].y - object[4].y) / 6;}
			if (object[0].z != object[1].z) {
			object[0].z += (object[1].z - object[4].z) / 6;}
			if (object[0].rx != object[1].rx) {
			object[0].rx += (object[1].rx - object[4].rx) / 6;}
            else {
                state = 1;  // Transition to turn around state
            }
            break;
	}
}



void patrol(obj object[], int speed) {
    //object[0].aistate = 1;  // Initial state

	object[0].spd = speed;

    switch (object[0].aistate) {


        case 1:
	
		            if (object[0].z != object[1].z ) {
					object[0].ry = angleab((object[0].x - object[1].x), (object[0].z - object[1].z));	
			object[0].z += (object[0].spd * (object[1].z - object[0].z)) / (JO_ABS(object[1].z - object[0].z));}
			if (object[0].x != object[1].x){
				object[0].ry = angleab((object[0].x - object[1].x), (object[0].z - object[1].z));	
				object[0].x += (object[0].spd * (object[1].x - object[0].x)) / (JO_ABS(object[1].x - object[0].x));
            }
		

			else {
                object[0].aistate = 2;  // Transition to move backward state
            }
            break;


        case 2:

            if (object[0].z != object[2].z) {
				object[0].ry = angleab((object[0].x - object[2].x), (object[0].z - object[2].z));
			object[0].z += (object[0].spd * (object[2].z - object[0].z)) / (JO_ABS(object[2].z - object[0].z));}
			if (object[0].x != object[2].x){
				object[0].ry = angleab((object[0].x - object[2].x), (object[0].z - object[2].z));
				object[0].x += (object[0].spd * (object[2].x - object[0].x)) / (JO_ABS(object[2].x - object[0].x));
				
            }

			else {
                object[0].aistate = 1;  // Transition back to move forward state
            }
            break;
    }
	}




bool	inrange(obj subject[], obj target[], int range)
{
	bool in_range;
	int dist = distance(target[0].x, subject[0].x, target[0].z, subject[0].z);
	if ( dist < range)
	in_range = true;
	else
	in_range = false;
return in_range;
	
}


void	follow(obj subject[], obj target[], int speed, int stopdist){
	
	int dist = distance(target[0].x, subject[0].x, target[0].z, subject[0].z);
		if (dist >= stopdist){
		subject->spd = speed;
		subject->ry = angleab((subject[0].x-target[0].x), (subject[0].z - target[0].z));
		subject[0].x -= (subject[0].spd * (subject[0].x - target[0].x)) / (JO_ABS(subject[0].x - target[0].x));
		subject[0].z -= (subject[0].spd * (subject[0].z - target[0].z)) / (JO_ABS(subject[0].z - target[0].z));
	}
	else if (dist < stopdist){
	subject->spd = 0;	
	subject->ry = angleab((subject[0].x-target[0].x), (subject[0].z - target[0].z));}
}


void	flee(obj subject[], obj target[], int speed, int stopdist){
	
	int dist = distance(target[0].x, subject[0].x, target[0].z, subject[0].z);
		if (dist <= stopdist){
		subject->spd = speed;
		subject->ry = angleab((target[0].x - subject[0].x), (target[0].z - subject[0].z));
		subject[0].x -= (subject[0].spd * (subject[0].x - target[0].x)) / (JO_ABS(subject[0].x - target[0].x));
		subject[0].z -= (subject[0].spd * (subject[0].z - target[0].z)) / (JO_ABS(subject[0].z - target[0].z));
	}
	else if (dist < stopdist){
	subject->spd = 0;	
	subject->ry = angleab((subject[0].x-target[0].x), (subject[0].z - target[0].z));}
}


void	speechbubble(void){

jo_sprite_draw3D(BUBBLE, 100, -60, 50);
textup = true;

}

void	cleartext(void){
	if(textup == true){
	jo_clear_screen();
	}
}



	
	void	pickupai(void)
{
	
	if(inrange(croissants, player, 70) == true){
	pastry = true;
	eventNo = 3;
	}
	if (pastry == true){
	croissants[0].x = player[0].x; 
	croissants[0].z = player[0].z; 
	croissants[0].y = player[0].y-150; 
	croissants[0].ry +=1;}
}
	
	
	void	playerai(void){
	 
	if (jumping == true){
		interpolate_fixedverts(ferg[0].data.pntbl, ferg[4].data.pntbl, ferg[5].data.pntbl, ferg[4].data.pntbl, ferg[5].data.pntbl, 6, 202, &ferg, player);
		}
		
	if (player->y >= flrmin){
			
	if (delta[0] != 0 || delta[2] != 0){
	jo_audio_play_sound(&step);
	interpolate_fixedverts(ferg[0].data.pntbl, ferg[1].data.pntbl, ferg[2].data.pntbl, ferg[1].data.pntbl, ferg[3].data.pntbl, 4, 202, &ferg, player);}
	else if (delta[0] == 0 && delta[2] == 0){
	revertfixedverts(ferg[0].data.pntbl, ferg[1].data.pntbl,202, &ferg, player);
	}

	}
	
	}
	
