#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "stdafx.h"'
#include "CommonFunc.h"
#include "BaseObject.h"
#include "BulletObject.h"

#define GRAVITY_SPEED 0.9
#define MAX_FALL_SPEED 12
#define PLAYER_SPEED 6.5
#define PLAYER_JUMP_VALUE 23
#define MAX_FRAME_CLIP 8
#define MONEY_TILE 290


class MainObj : public BaseObject
{
public:
    MainObj();
    ~MainObj();

    enum MovementType
    {
        MOVE_RIGHT = 1,
        MOVE_LEFT = 2,
        STAND = 0,
        P_ATTACK = 3,
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
    
    void set_bullet_list(std :: vector <BulletObj*> bullet_list)
    {
        p_bullet_list_ = bullet_list;
    }
    std :: vector <BulletObj*> get_bullet_list() const {return p_bullet_list_;}
    void HandleBullet(SDL_Renderer* des );
    
    void RemoveBulletHit(const int& idx);

    void IncreaseMoney();

private:
    std :: vector <BulletObj*> p_bullet_list_;

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

    int money_count;
};

#endif