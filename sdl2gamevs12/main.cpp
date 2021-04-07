
#include"stdafx.h"
#include"CommonFunc.h"
#include"BaseObject.h"
#include"game_map.h"
#include "MainObj.h"
#include "ImplementTimer.h"
#include "ThreatObj.h"

BaseObject g_background;

bool Init()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0)
        return false;
    
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    g_window = SDL_CreateWindow("Game SDL2.0 Demo",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                SCREEN_WIDTH,
                                SCREEN_HEIGHT,
                                SDL_WINDOW_SHOWN);

    if (g_window == NULL)
    {
        success = false;
    }
    else
    {
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if (g_screen == NULL)
            success = false;
        else
        {
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR
                                    , RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) && imgFlags))
                success = false;
        }
    }

    return success;
}

bool LoadBackground()
{
    bool ret = g_background.LoadImg("img//background.png", g_screen);
    if (ret == false)
        return false;

    return true;
}

void Close()
{

    g_background.Free();
  
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_Quit();
}

std::vector<ThreatsObject*> MakeThreatList()
{
    std::vector<ThreatsObject*> threat_list;
    
    //MOVING THREAT
    ThreatsObject* dynamic_threat = new ThreatsObject[40];
    for (int i = 0; i < 20; i++) 
    {
        ThreatsObject* p_threat = (dynamic_threat + i);
        if (p_threat != NULL)
        {
            p_threat->LoadImg("img//threat_left.png", g_screen);
            p_threat->SetCLips();
            p_threat->set_type_move(ThreatsObject::MOVING_THREAT);
            p_threat->SetXPos(500 + i * 1150);
            p_threat->SetYPos(250);

            int pos1 = p_threat->GetXPos() - 60;
            int pos2 = p_threat->GetXPos() + 60;
            
            p_threat->set_animation_pos(pos1, pos2);
            p_threat->set_input_left(1);
            threat_list.push_back(p_threat);
        }
    }

    //STATIC_THREAT
    ThreatsObject* threat_objs = new ThreatsObject[20];
    for (int i = 0; i < 20; i++)
    {
        ThreatsObject* p_threat = (threat_objs + i);
        if (p_threat != NULL)
        {
            p_threat->LoadImg("img//threat1.png", g_screen);
            p_threat->SetCLips();
            p_threat->set_type_move(ThreatsObject::STATIC_THREAT);
            p_threat->set_input_left(0);
            p_threat->SetXPos(700 + i * 1200);
            p_threat->SetYPos(250);

            threat_list.push_back(p_threat);
        }
    }
    return threat_list;
}

int main(int argc, char* argv[])
{   

    if (Init() == false)
        return -1;
    if (LoadBackground() == false)
        return -1;

	GameMap game_map;
	bool bRet = game_map.LoadMap("map/map11.dat");
    if (bRet == false)
        return - 1;

	game_map.LoadTiles(g_screen);

    MainObj p_player;
    p_player.LoadImg("img//player_right3.png", g_screen);
    p_player.Set_Clips();

    std::vector<ThreatsObject*> threat_list = MakeThreatList();
   
    ImpTimer fps_timer;
    bool is_quit = false;
    while(!is_quit)
    {
        fps_timer.start();
        while (SDL_PollEvent(&g_event) != 0)
        {
            if (g_event.type == SDL_QUIT)
            {
                is_quit = true;
            }
            p_player.HandleInputAction(g_event, g_screen);

        }
 
        SDL_RenderClear(g_screen);
        g_background.Render(g_screen, NULL);

        Map map_data = game_map.getMap();
        for (int i = 0; i < threat_list.size(); i++)
        {
            ThreatsObject* p_threat = threat_list.at(i);
            if (p_threat != NULL)
            {
                p_threat->SetMapXY(map_data.start_x_, map_data.start_y_);
                p_threat->ImpMovement(g_screen);
                p_threat->DoThreats(map_data);
                p_threat->Display(g_screen);
            }
        }
  
        game_map.DrawMap(g_screen);

        p_player.HandleBullet(g_screen);
        p_player.SetMapXY(map_data.start_x_, map_data.start_y_);
        p_player.DoPlayer(map_data);
        p_player.Display(g_screen);

        game_map.SetMap(map_data);



        SDL_RenderPresent(g_screen);

        int real_imp_time = fps_timer.get_ticks();
        int time_per_frame = 1000 / FRAME_PER_SECOND;
        if (real_imp_time < time_per_frame)
        {
            int delayed_time = time_per_frame - real_imp_time;
            if(delayed_time >= 0)
                SDL_Delay(delayed_time);
        }
    }
    
    Close();

    return 0;
}