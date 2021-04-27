#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include "CommonFunc.h"
#include "BaseObject.h"

class IMG_DISPLAY : public BaseObject
{
public:
	IMG_DISPLAY();
	~IMG_DISPLAY();


	void setNum(static int& NUM) { num = NUM; }
	//void addPos(const int& Pos);
	void Show(SDL_Renderer* screen);
	void Init(SDL_Renderer* screen);

	//void Increase();
	//void Decrease();

private:
	int pos[5];
	int num;

};




#endif // !1

