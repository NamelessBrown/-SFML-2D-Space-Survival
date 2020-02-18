#pragma once

#include "Player.h"

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

	Player mPlayer;
	std::vector<Rocks*> mRocks;

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

