#include "NPC.h"

void NPC::iniTexture()
{
	//load file
	this->texture.loadFromFile("img/Girl2.png");
}

void NPC::iniSprite()
{
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(0,0,50,75));
	this->sprite.setPosition(400,300);
}

NPC::NPC()
{
	this->iniTexture();
	this->iniSprite();
}

NPC::~NPC()
{
}

void NPC::Moveupdate(sf::RenderWindow* window)
{
	this->speedMove = 4.25;

	if (this->sprite.getPosition().x >=300 && this->sprite.getPosition().x <= 400)
	{
		//left
		this->sprite.move(-2.f, 0.f);
		window->setFramerateLimit(this->speedMove);

		this->sprite.setTextureRect(sf::IntRect(this->A_x * 50, this->A_y * 1, 50, 75));

		this->A_x = A_x + 1;

		if (this->A_x * 50 >= 200)
		{
			this->A_x = 0;
		}
	}
	else if(this->sprite.getPosition().x <= 400 && this->sprite.getPosition().y >= 200 )
	{
		//top
		this->sprite.move(0.f, -2.f);
		window->setFramerateLimit(this->speedMove);

		this->sprite.setTextureRect(sf::IntRect(this->A_x * 50, this->A_y * 3, 50, 75));

		this->A_x = A_x + 1;

		if (this->A_x * 50 >= 200)
		{
			this->A_x = 0;
		}

	}
	else
	{
		window->setFramerateLimit(this->speedMove);

		this->sprite.setTextureRect(sf::IntRect(this->A_x * 0, this->A_y * 0, 50, 75));
	}

}

void NPC::update(sf::RenderWindow* window)
{
	this->Moveupdate(window);
}

const sf::Vector2f& NPC::getPos() const
{
	return this->sprite.getPosition();
}



void NPC::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
