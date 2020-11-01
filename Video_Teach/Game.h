#pragma once
#include"NPC.h"


class Game
{

private:
	sf::RenderWindow* window;

	//NPC
	NPC* npc;

	//function
	void iniWindow();
	void iniNpc();
	void updateEvent();

public:
	Game();
	virtual ~Game();

	//funtion
	void run();
	void update();
	void updatenpc();
	void render();
};

