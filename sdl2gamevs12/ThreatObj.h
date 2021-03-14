#ifndef THREATS_OBJ_H_
#define THREATS_OBJ_H_

#include"stdafx.h"
#include"CommonFunc.h"
#include "BaseObject.h"

#define THREAT_FRAME 8
#define THREAT_GRAVITY_SPEED 0.8
#define THREAT_MAX_FALL_SPEED 10

class ThreatsObject : public BaseObject
{
public:
	ThreatsObject();
	~ThreatsObject();

	void SetXVal(const float& xVal) { x_val_ = xVal; }
	void SetYVal(const float& yVal) { y_val_ = yVal; }
	void SetXPos(const float& xPos) { x_pos_ = xPos; }
	void SetYPos(const float& yPos) { y_pos_ = yPos; }
	float GetXPos() const { return x_pos_; }
	float GetYPos() const { return y_pos_; }
	void SetMapXY(const int& mapX, const int& mapY) { map_x_ = mapX, map_y_ = mapY; }
	void SetCLips();
	bool LoadImg(std::string path, SDL_Renderer* screen);
	void Display(SDL_Renderer* des);
	int GetHeightFrame() const { return height_frame_; }
	int GetWidthFrame() const { return width_frame_; }
	void DoThreats(Map& g_map_);
	void CheckToMap(Map& g_map_);
	bool contains(int tiles_value);

private:

	float x_pos_;
	float y_pos_;
	float x_val_;
	float y_val_;

	int map_x_;
	int map_y_;

	int come_back_time;

	SDL_Rect frame_clip_[THREAT_FRAME];
	int width_frame_;
	int height_frame_;
	int frame_;

	int on_ground_;



};




#endif // !THREATS_OBJ_H_

