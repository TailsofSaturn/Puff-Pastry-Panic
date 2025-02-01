#include "display.h"
#include "models3d.h"


//geometry math  

int distance(int x1, int x2, int z1, int z2) {
    int dist = jo_sqrt(((x2 - x1) * (x2 - x1)) + ((z2 - z1) * (z2 - z1)));
    return dist;
}

int distancesqr(int x1, int x2, int z1, int z2) {
    int dist = ((x2 - x1) * (x2 - x1)) + ((z2 - z1) * (z2 - z1));
    return dist;
}


int angleab(int distx, int distz){
 int ang =  jo_atan2f(distx, distz);
 return ang;
}

jo_fixed interpolate(jo_fixed v1, jo_fixed v2, jo_fixed t){
	
	jo_fixed v = v1 + jo_fixed_mult((v2-v1), t);
	return v;
	}
	
	

	

// Animations



   bool sameint(int verts1[][3], int verts2[][3], int numverts) {
    for (int i = 0; i < numverts; i++) {
        for (int j = 0; j < 3; j++) {
            if (verts1[i][j] - verts2[i][j] > 1 || verts1[i][j] - verts2[i][j] < -1) {
                return false;

            }
        }
    }
    return true;
}

   bool samefixed(jo_fixed verts1[][3], jo_fixed verts2[][3], int numverts) {
	   
	bool same = true;
    for (int i = 0; i < numverts; i++) {
        for (int j = 0; j < 3; j++) {
            if (verts1[i][j] - verts2[i][j] >= 300000 || verts1[i][j] - verts2[i][j] <= -300000) {
                same = false;
				break;
            }
        }
    }
    return same;
}


	enum State {
    first,
    second,
    third,
    fourth
}state;
	
		void	interpolate_intverts(int verts[][3],int verts1[][3],int verts2[][3],int verts3[][3], int verts4[][3], int frames, int numverts, jo_3d_mesh *mesh){
	static int state = 1;
	
	
	switch (state) {
		case 1:
		if (!sameint(verts, verts1, numverts)) {
		 for (int i = 0; i < numverts; i++) {
        verts[i][0] = verts[i][0] + ((verts1[i][0] - verts4[i][0])/frames);
       verts[i][1] = verts[i][1] + ((verts1[i][1] - verts4[i][1])/frames);
       verts[i][2] = verts[i][2] + ((verts1[i][2] - verts4[i][2])/frames);
		jo_3d_set_mesh_vertice(mesh, jo_int2fixed(verts[i][0]), jo_int2fixed(verts[i][1]), jo_int2fixed(verts[i][2]), i);
		 }	
	}
	else {state = 2;}
	break;
	
	case 2:
		if (!sameint(verts, verts2, numverts)) {
		 for (int i = 0; i < numverts; i++) {
        verts[i][0] = verts[i][0] + ((verts2[i][0] - verts1[i][0])/frames);
      verts[i][1] = verts[i][1] + ((verts2[i][1] - verts1[i][1])/frames);
      verts[i][2] = verts[i][2] + ((verts2[i][2] - verts1[i][2])/frames);
		jo_3d_set_mesh_vertice(mesh, jo_int2fixed(verts[i][0]), jo_int2fixed(verts[i][1]), jo_int2fixed(verts[i][2]), i);
		 }	
	}
	else {state = 3;}
	break;	

	case 3:
		if (!sameint(verts, verts3, numverts)) {
		 for (int i = 0; i < numverts; i++) {
        verts[i][0] = verts[i][0] + ((verts3[i][0] - verts2[i][0])/frames);
      verts[i][1] = verts[i][1] + ((verts3[i][1] - verts2[i][1])/frames);
      verts[i][2] = verts[i][2] + ((verts3[i][2] - verts2[i][2])/frames);
		jo_3d_set_mesh_vertice(mesh, jo_int2fixed(verts[i][0]), jo_int2fixed(verts[i][1]), jo_int2fixed(verts[i][2]), i);
		 }	
	}
	else {state = 4;}
	break;	
	
		case 4:
		if (!sameint(verts, verts4, numverts)) {
		 for (int i = 0; i < numverts; i++) {
        verts[i][0] = verts[i][0] + ((verts4[i][0] - verts3[i][0])/frames);
      verts[i][1] = verts[i][1] + ((verts4[i][1] - verts3[i][1])/frames);
      verts[i][2] = verts[i][2] + ((verts4[i][2] - verts3[i][2])/frames);
		jo_3d_set_mesh_vertice(mesh, jo_int2fixed(verts[i][0]), jo_int2fixed(verts[i][1]), jo_int2fixed(verts[i][2]), i);
		 }	
	}
	else {state = 1;}
	break;	
}
}

		void	interpolate_fixedverts(jo_fixed verts[][3],jo_fixed verts1[][3],jo_fixed verts2[][3],jo_fixed verts3[][3],jo_fixed verts4[][3], int frames, int numverts, jo_3d_mesh *mesh, obj object[]){
	
		
		
	
	
	switch (object[0].frame) {
		case 0:
	
			for (int i = 0; i < numverts; i++) {
		verts[i][0] = verts4[i][0];
		verts[i][1] = verts4[i][1];
		verts[i][2] = verts4[i][2];
		}
		object[0].frame = 1;
		break;
	

		case 1:
		if (object[0].kff < (1<<frames)) {
		 for (int i = 0; i < numverts; i++) {
		verts[i][0] = interpolate(verts4[i][0], verts1[i][0], ((JO_FIXED_1>>frames)*object[0].kff));
		verts[i][1] = interpolate(verts4[i][1], verts1[i][1], ((JO_FIXED_1>>frames)*object[0].kff));
		verts[i][2] = interpolate(verts4[i][2], verts1[i][2], ((JO_FIXED_1>>frames)*object[0].kff));
		 }
		++object[0].kff;
	}
	else {
		object[0].kff = 0;
		object[0].frame = 2;
	}
	break;
	
	case 2:
		if (object[0].kff < (1<<frames)) {
		 for (int i = 0; i < numverts; i++) {
 		verts[i][0] = interpolate(verts1[i][0], verts2[i][0], ((JO_FIXED_1>>frames)*object[0].kff));
		verts[i][1] = interpolate(verts1[i][1], verts2[i][1], ((JO_FIXED_1>>frames)*object[0].kff));
		verts[i][2] = interpolate(verts1[i][2], verts2[i][2], ((JO_FIXED_1>>frames)*object[0].kff));
			 }
	++object[0].kff;
	}
	else {
		object[0].kff = 0;
		object[0].frame = 3;
	}
	break;	
	
	case 3:
		if (object[0].kff < (1<<frames)) {
		 for (int i = 0; i < numverts; i++) {
 		verts[i][0] = interpolate(verts2[i][0], verts3[i][0], ((JO_FIXED_1>>frames)*object[0].kff));
		verts[i][1] = interpolate(verts2[i][1], verts3[i][1], ((JO_FIXED_1>>frames)*object[0].kff));
		verts[i][2] = interpolate(verts2[i][2], verts3[i][2], ((JO_FIXED_1>>frames)*object[0].kff));
		 }
	++object[0].kff;
	}
		else {
		object[0].kff = 0;
		object[0].frame = 4;
	}
	break;
	
	case 4:
		if (object[0].kff < (1<<frames)) {
		 for (int i = 0; i < numverts; i++) {
 		verts[i][0] = interpolate(verts3[i][0], verts4[i][0], ((JO_FIXED_1>>frames)*object[0].kff));
		verts[i][1] = interpolate(verts3[i][1], verts4[i][1], ((JO_FIXED_1>>frames)*object[0].kff));
		verts[i][2] = interpolate(verts3[i][2], verts4[i][2], ((JO_FIXED_1>>frames)*object[0].kff));
		 }
		++object[0].kff;
	}
	else {
		object[0].kff = 0;
		object[0].frame = 1;
	}
	break;
}
}

void revertfixedverts(jo_fixed verts[][3],jo_fixed verts1[][3],int numverts, jo_3d_mesh *mesh, obj object[]){
	
		for (int i = 0; i < numverts; i++) {
		verts[i][0] = verts1[i][0];
		verts[i][1] = verts1[i][1];
		verts[i][2] = verts1[i][2];
		//jo_3d_set_mesh_vertice(mesh, (verts[i][0]), (verts[i][1]), (verts[i][2]), i);
		}
		object[0].frame = 0;
}
	






// Display

jo_camera cam;
jo_palette image_pal;



void debug_menu(void) {
    // Write Text to Screen
    
	jo_printf(0, 0, "Dynamic memory usage: %d%% ", jo_memory_usage_percent());
	jo_printf(0, 2, "Event: %7d ", eventNo);
	jo_printf(0, 4, "Colliding: %7d ", colliding);
		
	//jo_printf(0, 0, "              *Puff Pastrie Panic*              ");
  //  jo_printf(0, 3, "Camera Angle: %4d Degrees", cam_angle[1]);
   // jo_printf(0, 4, "Camera Position:%7d,%7d,%7d ", cam_pos[0], cam_pos[1], cam_pos[2]);
//	jo_printf(0, 3, "Ground height:%7d, ", flrmin);
	//jo_printf(0, 4, "jumstart:%7d, ", caskNo);
    jo_printf(0, 5, "Camera Target:  %7d,%7d,%7d ", cam_tar[0], cam_tar[1], cam_tar[2]);
   // jo_printf(0, 6, "Camera Fixed Position:%7d,%7d,%7d ", dcpos[0], dcpos[1], dcpos[2]);
    jo_printf(0, 27, "Polygons: %7d ", jo_3d_get_polygon_count());
   // jo_printf(0, 28, "Vertices: %7d ", jo_3d_get_vertices_count());
    jo_printf(0, 29, "Displayed Polygons: %7d ", jo_3d_get_displayed_polygon_count());
	
}

void draw_mesh(jo_3d_mesh *mesh, obj position[], int numobj) {
	
	player[1].x = (cam_pos[0]) + (800 * jo_sin(cam_angle[1]) >> 15);
    player[1].z = (cam_pos[2]) + (800 * jo_cos(cam_angle[1]) >> 15);
	
    int i;
    for (i = 0; i < numobj; i++) {
		
		if (distancesqr(position[i].x, player[1].x, position[i].z, player[1].z) < 4000000){
		
		jo_3d_push_matrix();
        {
            jo_3d_translate_matrix(position[i].x, position[i].y, position[i].z);
            jo_3d_rotate_matrix(position[i].rx, position[i].ry, position[i].rz);
            jo_3d_mesh_draw(mesh);
        }
        jo_3d_pop_matrix();
    }
}
}





void init_3d_planes(const char* floor_tga_filename, const char* sky_tga_filename) {
    jo_img_8bits img;

    jo_core_tv_off();

    jo_enable_background_3d_plane(JO_COLOR_Black);

    // FLOOR
    img.data = JO_NULL;
    jo_tga_8bits_loader(&img, JO_ROOT_DIR, floor_tga_filename, JO_COLOR_Transparent);
    jo_background_3d_plane_a_img(&img, image_pal.id, true, true);
    jo_free_img(&img);

    // SKY
    jo_tga_8bits_loader(&img, JO_ROOT_DIR, sky_tga_filename, JO_COLOR_Transparent);
    jo_background_3d_plane_b_img(&img, image_pal.id, true, true);
    jo_free_img(&img);

    jo_core_tv_on();
}



jo_palette *my_tga_palette_handling(void) {
    jo_create_palette(&image_pal);
    return (&image_pal);
}

void	draw_planes(void){

    jo_3d_push_matrix();
    {
        jo_3d_rotate_matrix(90, 0, 0);
        jo_3d_translate_matrix(0, 0, 0);
        jo_background_3d_plane_a_draw(true);
    }
    jo_3d_pop_matrix();
	
	    jo_3d_push_matrix();
    {
		jo_3d_translate_matrix(0, -600, 0);
		jo_3d_rotate_matrix(90, 0, 0);
		jo_background_3d_plane_b_draw(true);
    }
    jo_3d_pop_matrix();
    
}















void loadTitle(void)
{
	
	
	
		titlescreen = ML_LoadMesh("TITLE.TMF", JO_ROOT_DIR, castleNo);
		
	dcpos[0] = 0;
	dcpos[1] = 0;
    dcpos[2] = 0;
	
	cam_angle[1] = 0;
	eventNo = 0;
	
	menu->x = dcpos[0] >> 5;
    menu->y = dcpos[1] >> 5;
    menu->z = dcpos[2] >> 5;
	
	cam_pos[0] = 200;
	cam_pos[1] = 0;
	cam_pos[2] = 0;
	
	
	cam_tar[0] = menu->x ;
	cam_tar[1] = menu->y;
	cam_tar[2] = menu->z;
	
	/*
	bg = (jo_img *)jo_malloc(sizeof(jo_img));
    bg->data = NULL;
    jo_tga_loader(bg, JO_ROOT_DIR, "MMENU.TGA", JO_COLOR_Transparent);
    jo_set_background_sprite(bg, 0, 0);
	jo_free_img(bg); 
	      
	jo_free(bg);   
	bg = NULL;	
	
	
	// allocate image structure in RAM
jo_img *bg = (jo_img *)jo_malloc(sizeof(jo_img));
bg->data = NULL;

// Load image and set it
jo_tga_loader(bg, JO_ROOT_DIR, "MMENU.TGA", JO_COLOR_Transparent);
jo_set_background_sprite(bg, 0, 0);

// Free used system RAM
 
			jo_free(bg->data); // same as jo_free_img(bg);
		jo_free(bg);
*/


//jo_sprite_add_tga(JO_ROOT_DIR, "MMENU.TGA", JO_COLOR_Black);		
}

void title()
{
    if (jo_is_pad1_key_down(JO_KEY_START))
    {
		unload_mesh(titlescreen, 1);
		load_lv_1();
        level = 1;
    }
	else{
	//draw_mesh(&titlescreen[0], menu, 1);
	debug_menu();
	}
	}

