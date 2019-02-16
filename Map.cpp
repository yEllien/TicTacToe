#include "Map.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

Map::Map(RenderWindow *Win)
{
	W = Win;

	p = &sx;

	o.loadFromFile("im.O.png");
	x.loadFromFile("im.X.png");

	so.setTexture(o);
	sx.setTexture(x);

	float w = 0, h = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			rects[i][j].sq.setSize(Vector2f(160,160));
			rects[i][j].sq.setFillColor(Color::Black);
			rects[i][j].sq.setPosition(Vector2f(w,h));
			rects[i][j].c = -1;
			w += 170;
		}
		h += 170;
		w = 0;
	}
}

void Map::update()
{
	int ol, xl, oc, xc;
	Vector2f mouse;

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		mouse = W->mapPixelToCoords(sf::Mouse::getPosition(*W));
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//---------------------------------------------------------------------------------
				if (rects[i][j].sq.getGlobalBounds().contains(mouse) && rects[i][j].c == -1)
				{
					p->setPosition(Vector2f(rects[i][j].sq.getPosition()));
					inp.push_back(*p);
					if (p == &sx)
					{
						p = &so;
						rects[i][j].c = Xn;
					}
					else
					{
						p = &sx;
						rects[i][j].c = On;
					}
				}
				//----------------------------------------------------------------------------------
			}
		}

		for (int i = 0; i < 3; i++)
		{
			int c = 0;
			int o = 0;
			int c1 = 0;
			int o1 = 0;
			for(int n = 0; n < 3; n++)
			{
				if (rects[i][n].c == Xn) c++;
				if (rects[i][n].c == On) o++;
				if (rects[n][i].c == Xn) c1++;
				if (rects[n][i].c == On) o1++;
			}
			if (c == 3) cout << "X wins" << endl;
			if (c1 == 3) cout << "X wins" << endl;
			if (o == 3) cout << "O wins" << endl;
			if (o1 == 3) cout << "O wins" << endl;

		}

		int cc = 0;
		int cn = 0;
		int cco = 0;
		int cno = 0;
		int n = 3;
		for (int i = 0; i < 3; i++)
		{
			n--;
			if (rects[i][i].c == Xn) cc++;
			if (rects[i][i].c == On) cn++;
			if (rects[n][n].c == Xn) cco++;
			if (rects[n][n].c == On) cno++;

		}
		if (cc == 3) cout << "X wins" << endl;
		if (cn == 3) cout << "O wins" << endl;
		if (cco == 3) cout << "X wins" << endl;
		if (cno == 3) cout << "O wins" << endl;

		//i love tony sooooooooooo much, i love you too Ellie <3
	}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			W->draw(rects[i][j].sq);

	for (auto &s : inp)
		W->draw(s);
	
}
