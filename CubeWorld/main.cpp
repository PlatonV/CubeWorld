#include "Precompiled.h"

int main()
{
	// Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cubes World");

	sf::Shader lightShader;

	lightShader.loadFromFile("Vertex.vert", sf::Shader::Vertex);
	lightShader.loadFromFile("Light.frag", sf::Shader::Fragment);

	Player player;
	player.setPosition(100,100);
	player.Init();

	Square ground(2000);
	ground.setPosition(0,525);
	ground.Init();

	Fire fire(400,450);
	Light l(400,450,1,1,1,1);

	SceneManager sceneManager;
	sceneManager.Add(&player);
	sceneManager.Add(&ground);

	// Create a clock to keep track of the elapsed time
    sf::Clock clock;

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player.MoveRight();
		}

		player.MoveLeft();

        window.clear();

		sf::Time elapsed = clock.restart();

		//player.Update(elapsed);
		sceneManager.Update(elapsed);
		fire.Update(elapsed);

		window.draw(player);
		window.draw(ground);

		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE);

		for (unsigned int i = 0; i < fire.mParticles.size();++i)
		{
			lightShader.setParameter("lightPos", fire.mParticles[i].Position);
			lightShader.setParameter("color", fire.mParticles[i].r, 
				fire.mParticles[i].g, 
				fire.mParticles[i].b,1);
			lightShader.setParameter("intensity", fire.mParticles[i].intensity);

			window.draw(rect, &lightShader);
		}

		glDisable(GL_BLEND);

        window.display();
    }

    return 0;
}