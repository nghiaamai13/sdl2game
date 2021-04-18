#include "stdafx.h"
#include "BulletObject.h"

BulletObj :: BulletObj()
{
    x_val_ = 0;
    y_val_ = 0;
    is_moving = false;
    bullet_type = SPHERE_BULLET;
}

BulletObj :: ~BulletObj()
{

}

void BulletObj :: LoadImgBullet(SDL_Renderer* des)
{
    if (bullet_type == LASER_BULLET)
    {
        LoadImg("img//laser_bullet", des);
    }
    else if(bullet_type == SPHERE_BULLET)
    {
        LoadImg("img//sphere_bullet", des);
    }
}

void BulletObj :: HandleMove(const int &x_border , const int &y_border)
{
    if(bullet_dir == DIR_RIGHT)
    {
        rect_.x += x_val_;
        if(rect_.x > x_border)
        {
            is_moving = false;
        }
    }
    else if(bullet_dir == DIR_LEFT)
    {
        rect_.x -= x_val_;
        if(rect_.x < 0)
        {
            is_moving = false;
        }
    }

}

