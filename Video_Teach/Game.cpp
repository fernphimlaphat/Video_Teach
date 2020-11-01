#include "Game.h"

void Game::iniWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "My Game");
	this->window->setFramerateLimit(60);
}

void Game::iniNpc()
{
	this->npc = new NPC();
}

void Game::updateEvent()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
		{
			this->window->close();
		}
		if (e.Event::KeyPressed  && e.Event::key.code == sf::Keyboard::Escape)
		{
			this->window->close();
		}
	}
}

void Game::updatenpc()
{
	this->npc->update(this->window);
}

Game::Game()
{
	iniWindow();
	iniNpc();
}

Game::~Game()
{
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateEvent();
		this->update();
		this->render();
	}
}

void Game::update()
{
	this->updatenpc();
}

void Game::render()
{
	this->window->clear();
	
	//reder target
	npc->render(this->window);

	this->window->display();
}
