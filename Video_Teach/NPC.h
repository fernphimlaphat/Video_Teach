#pragma once
#include"SFML/Graphics.hpp"

class NPC
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	//animation
	float speedMove;
	float A_x = 0;
	float A_y = 75;

	//function
	void iniTexture();
	void iniSprite();

public:
	NPC();
	virtual ~NPC();

	//function
	void Moveupdate(sf::RenderWindow* window);
	void update(sf::RenderWindow* window);
	const sf::Vector2f& getPos() const;
	void render(sf::RenderTarget* target);
};

