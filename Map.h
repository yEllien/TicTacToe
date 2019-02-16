#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

#define On 0
#define Xn 1


struct square
{
	RectangleShape sq;
	int c;
};

class Map
{
private:
	Texture o, x;
	Sprite *p;
	Sprite so;
	Sprite sx;
	RenderWindow *W;
	vector <Sprite> inp;
	square rects[3][3];
public:
	Map(RenderWindow *Win);
	void update();
};

