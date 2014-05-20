#include "Precompiled.h"

bool			gDrawGrid;

float			zoom;

sf::Vector2i	gPrevMousePos;

enum
{
	Hand,
	AddTerrain
}Tool;

void ConstrainView(sf::View& view);

int main()
{
	// Create the window
	sf::RenderWindow window(sf::VideoMode(1280, 760), "Map Editor");

	window.setVerticalSyncEnabled(true);

	// Create a clock to keep track of the elapsed time
	sf::Clock clock;

	// create a view with the rectangular area of the 2D world to show
	sf::View view(sf::FloatRect(0, 0, 1280, 760));

	gDrawGrid = true;

	Grid grid(50);

	Sky sky;

	Map map;

	window.setView(view);
	ConstrainView(view);

	zoom = 1;

	Tool = AddTerrain;

	// MAIN LOOP
	while (window.isOpen())
	{
		// Event variable type to catch events with
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
					gDrawGrid = !gDrawGrid;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
					Tool = Hand;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
					Tool = AddTerrain;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					map.Export("map");
				}
			}
			if (event.type == sf::Event::MouseWheelMoved)
			{
				view.zoom(1+event.mouseWheel.delta * -0.5f);
				zoom *=  1+event.mouseWheel.delta * -0.5f;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (Tool == Hand)
			{
				view.move((sf::Vector2f)(gPrevMousePos - sf::Mouse::getPosition()) * zoom);
				ConstrainView(view);
			}
			else if (Tool == AddTerrain)
			{
				map.AddTerrain(Vector2(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x, window.mapPixelToCoords(sf::Mouse::getPosition(window)).y));
			}
		}
		gPrevMousePos = sf::Mouse::getPosition();

		sf::Time elapsed = clock.restart();

		window.setView(view);	

		window.clear(sf::Color::Black);

		// DRAWING HERE

		sky.Draw(window);

		map.Draw(window);

		if (gDrawGrid)
		{
			window.draw(grid);
		}

		window.display();


	}

	return 0;
}

void ConstrainView(sf::View& view)
{
	if(view.getCenter().x < SCREEN_WIDTH/2)
	{
		view.setCenter(SCREEN_WIDTH/2, view.getCenter().y);
	}

	if(view.getCenter().x > WORLD_WIDTH - SCREEN_WIDTH/2)
	{
		view.setCenter(WORLD_WIDTH - SCREEN_WIDTH/2, view.getCenter().y);
	}

	if(view.getCenter().y < SCREEN_HEIGHT/2)
	{
		view.setCenter(view.getCenter().x, SCREEN_HEIGHT/2);
	}

	if(view.getCenter().y > WORLD_HEIGHT - SCREEN_HEIGHT/2)
	{
		view.setCenter(view.getCenter().x, WORLD_HEIGHT - SCREEN_HEIGHT/2);
	}
}