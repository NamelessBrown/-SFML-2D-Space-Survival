#pragma once

#include "Player.h"
#include <iostream>
#include <sstream>

class Game
{
public:
	Game();
	virtual ~Game();

	Game operator=(const Game&) = delete;
	Game(const Game&) = delete;

	//public functions
	void Run();

private:
	sf::RenderWindow* mWindow;
	sf::Event mEvent;
	sf::View mWindowView;
	sf::Text mText;
	sf::Font mFont;
	sf::Music* mMusic;

	Player mPlayer;
	std::vector<Rocks*> mRocks;

	int mPlayerPoints;
	int mSpawnTimer;
	int mSpawnTimerMax;
	bool gameOver;

	//functions
	void PollEvent();
	void Update();
	void SpawnRocks();
	void RockCollion();
	void Render();
};

