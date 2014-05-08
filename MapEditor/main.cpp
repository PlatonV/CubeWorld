#include "Precompiled.h"

bool			gDrawGrid;

float zoom;

sf::Vector2i	gPrevMousePos;

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

	window.setView(view);

	sf::VertexArray sky(sf::Quads, 4);

	sky[0].position = sf::Vector2f(0, 0);
	sky[1].position = sf::Vector2f(10000, 0);
	sky[2].position = sf::Vector2f(10000, 2000);
	sky[3].position = sf::Vector2f(0, 2000);

	sky[0].color = sf::Color(25,25,200,255);
	sky[1].color = sf::Color(25,25,200,255);
	sky[2].color = sf::Color(180,180,255,255);
	sky[3].color = sf::Color(180,180,255,255);;

	zoom = 1;

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
			}
			if (event.type == sf::Event::MouseWheelMoved)
			{
				view.zoom(1+event.mouseWheel.delta * -0.5f);
				zoom *=  1+event.mouseWheel.delta * -0.5f;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			view.move((sf::Vector2f)(gPrevMousePos - sf::Mouse::getPosition()) * zoom);
			ConstrainView(view);
		}
		gPrevMousePos = sf::Mouse::getPosition();

		sf::Time elapsed = clock.restart();

		window.setView(view);	

		window.clear(sf::Color::Black);

		// DRAWING HERE

		window.draw(sky);

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
	if(view.getCenter().x<1280/2)
	{
		view.setCenter(1280/2, view.getCenter().y);
	}

	if(view.getCenter().y<760/2)
	{
		view.setCenter(view.getCenter().x, 760/2);
	}
}