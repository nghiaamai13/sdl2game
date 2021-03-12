#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"
#include "stdafx.h"

#define GRAVITY_SPEED 0.8
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 5
#define PLAYER_JUMP_VALUE 20
#define MAX_FRAME_CLIP 8

class MainObj : public BaseObject
{
public:
    MainObj();
    ~MainObj();

    enum MovementType
    {
        MOVE_RIGHT = 0,
        MOVE_LEFT = 1,
        P_ATTACK = 2,
        STAND_RIGHT = 20,
        STAND_LEFT = 21,
        STAND = -1,
    };


    bool LoadImg(std :: string path, SDL_Renderer* screen);
    void Display(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    void Set_Clips();

    void DoPlayer(Map& map_data);
    void CheckToMap(Map& map_data);
    void SetMapXY(const int map_x, const int map_y) { map_x_ = map_x; map_y_ = map_y; }
    void CenterEntityOnMap(Map& map_data);
    void UpdatePlayerImg(SDL_Renderer* des);
    
    bool contains(int tiles_value);
    
private:
    float x_val_;
    float y_val_;

    float x_pos_;
    float y_pos_;

    int width_frame_;
    int height_frame_;
    
    SDL_Rect frame_clip_[MAX_FRAME_CLIP];
    Input input_type_;
    int frame_;
    int status_;
    int stand_status_;
    bool on_ground_;

    int map_x_;
    int map_y_;
    
    int come_back_time_;
};

#endif