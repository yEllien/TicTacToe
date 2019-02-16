#include <SFML/Graphics.hpp>
#include "Map.h"

using namespace sf;

int main()
{
	RenderWindow win(VideoMode(500, 500), "Tic-Tac-Toe");	

	Vector2i mpos;

	Event ev;

	Map map(&win);

	while (win.isOpen())
	{
		win.clear(Color::White);
		
		
		while (win.pollEvent(ev))
		{}
		map.update();

		win.display();
	}

	return 0;
}