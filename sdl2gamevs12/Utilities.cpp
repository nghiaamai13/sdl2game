#include"stdafx.h"
#include"Utilities.h"

IMG_DISPLAY::IMG_DISPLAY()
{
	num = 3;
}

IMG_DISPLAY::~IMG_DISPLAY()
{
	
}



void IMG_DISPLAY::Init(SDL_Renderer* screen)
{
	LoadImg("img//player_life.png", screen);
	
	for (int j = 0; j < num ; ++j)
	{
		pos[j] = 20 + j * 40;
	}
}

void IMG_DISPLAY::Show(SDL_Renderer* screen)
{
	for (int i = 0; i < num  ; i++)
	{
		rect_.x = pos[i];
		rect_.y = 0;
		Render(screen);
	}
}

/*void IMG_DISPLAY::Increase()
{
	num++;
	int last_pos = pos.back();
	last_pos += 40;
	pos.push_back(last_pos);
}

void IMG_DISPLAY::Decrease()
{
	num--;
	pos.pop_back();
}*/