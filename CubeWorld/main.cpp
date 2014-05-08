#include "Precompiled.h"

int main()
{
	// Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cubes World");

	sf::View gameView;

	SceneManager sceneManager;

	// Create a clock to keep track of the elapsed time
    sf::Clock clock;

	window.setView(gameView);

	sf::RectangleShape rect(sf::Vector2f(800,600));

	// MAIN LOOP
    while (window.isOpen())
    {
		// Event variable type to catch events with
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		window.clear();

		sf::Time elapsed = clock.restart();

		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE);

		glDisable(GL_BLEND);

        window.display();
    }

    return 0;
}