/*
** Jo Sega Saturn Engine
** Copyright (c) 2012-2017, Johannes Fetz (johannesfetz@gmail.com)
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**     * Neither the name of the Johannes Fetz nor the
**       names of its contributors may be used to endorse or promote products
**       derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL Johannes Fetz BE LIABLE FOR ANY
** DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
** ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/




#include <jo/jo.h>
#include "globals.h"
#include "models3d.h"
#include "display.h"
#include "mechanics.h"
#include "ai.h"
#include "levels.h"
#include "modelLoader.h"

	

void initialise(void)
{	
	jo_core_init(JO_COLOR_Blue);
	jo_3d_camera_init(&cam);
	jo_sprite_change_sprite_scale(2);
	

	
	}




void camera(void) {
    jo_3d_camera_look_at(&cam);
	jo_3d_camera_set_viewpoint(&cam,cam_pos[0],cam_pos[1],cam_pos[2]);
    jo_3d_camera_set_target(&cam,cam_tar[0],cam_tar[1],cam_tar[2]);
}





void			    CPU1(void)
{  
camera();
level_1();
}



	




void			jo_main(void)
{
	initialise();
	//loadTitle();
	jo_core_add_callback(camera);
	jo_core_add_callback(levels);
	slDynamicFrame(ON);
	jo_core_run();
}



/*
** END OF FILE
*/
