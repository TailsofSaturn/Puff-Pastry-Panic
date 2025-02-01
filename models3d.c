
#include "models3d.h"





	void	loadHUD(void)
{
	jo_sprite_add_tga(JO_ROOT_DIR, "SBUBBLE.TGA", JO_COLOR_White);
	
	
}




void	loadsfx(void)
{
		jo_audio_load_pcm("JUMP.PCM", JoSoundMono16Bit, &hop);
		jo_audio_load_pcm("STEP.PCM", JoSoundMono16Bit, &step);
		
		
	
}

// models

	jo_3d_mesh*   car;
	int* carNo;

	jo_3d_mesh*    boulder;
	int* boulderNo;

	jo_3d_mesh*    house;
	int* houseNo;

	jo_3d_mesh*    female;
	int* femaleNo;

	jo_3d_mesh*    ferg;
	int* fergNo;

	jo_3d_mesh*   tree;
	int* treeNo;

	jo_3d_mesh*    cliff;
	int* cliffNo;

	jo_3d_mesh*    croissant;
	int* croissantNo;

	jo_3d_mesh*    treewall;
	int* treewallNo;

	jo_3d_mesh*    townhouse;
	int* townhouseNo;

	jo_3d_mesh*         cask;
	int* caskNo;
	
	jo_3d_mesh*         castle;
	int* castleNo;
	
	jo_3d_mesh*         castle2;
	int* castle2No;
	
	jo_3d_mesh*    miniferg;
	int* minifergNo;
	
	jo_3d_mesh*    chef;
	
	jo_3d_mesh*		titlescreen;
	
	jo_img* bg;


void    unload_mesh(jo_3d_mesh* mesh, int meshNo){
        
		static int i;
		for (i=0; i<meshNo; i++){
        jo_free(mesh[i].data.pntbl);
        jo_free(mesh[i].data.pltbl);
        jo_free(mesh[i].data.attbl);
		}
		jo_free(mesh);
}