#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	// Load a texture from a file
	sf::Texture texture;
	if (!texture.loadFromFile("texture.jpg"))
		return -1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					if (shape.getFillColor() != sf::Color::Red)
					{
						shape.setFillColor(sf::Color::Red);
					}
					else
					{
						shape.setFillColor(sf::Color::Green);
					}
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					shape.move(0, -1);
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					shape.move(0, 1);
				}
				if (event.key.code == sf::Keyboard::A)
				{
					shape.setRadius(49.6);
				}
				if (event.key.code == sf::Keyboard::B)
				{
					shape.setTexture(&texture);
				}
				if (event.key.code == sf::Keyboard::Left)
				{
					shape.move(-1, 0);
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					shape.move(1, 0);
				}

			
			}
			if (shape.getPosition().x < -2 * shape.getRadius())
			{
				shape.setPosition(1000, shape.getPosition().y);
			}
			if (shape.getPosition().x > 1000)
			{
				shape.setPosition(-2*shape.getRadius(), shape.getPosition().y);
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}