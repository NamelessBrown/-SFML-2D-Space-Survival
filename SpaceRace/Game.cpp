#include "Game.h"

Game::Game()
	:mEvent(sf::Event()), mSpawnTimer(0), mSpawnTimerMax(100), gameOver(false)
{
	mWindow = new sf::RenderWindow(sf::VideoMode(500, 500), "SpaceDodgers", sf::Style::Close | sf::Style::Titlebar);
	mWindow->setFramerateLimit(60); //Sets the framrate to 60, so I don't have to do calculations.
	mWindowView.setCenter(mPlayer.getSprite().getPosition()); 
}

Game::~Game()
{
	//Delete everything in the vector. Then, get rid of the vector
	for (auto* i : mRocks)
	{
		delete i;
	}

	delete mWindow;
}

void Game::Run()
{
	while (mWindow->isOpen() && !gameOver)
	{
		Update();
		Render();
	}
}

void Game::PollEvent()
{
	while (mWindow->pollEvent(mEvent))
	{
		switch (mEvent.type)
		{
		case sf::Event::Closed:
			mWindow->close();
			break;
		}
	}
}

void Game::Update()
{
	PollEvent();
	mPlayer.Update();
	SpawnRocks();
	RockCollion();
}

void Game::SpawnRocks()
{
	/* Spawns the rocks every time SpawnTimer reaches 100 */

	if (mSpawnTimer > mSpawnTimerMax)
	{
		mRocks.push_back(new Rocks
		(sf::Vector2f(static_cast<float>(rand() % mWindow->getSize().x - 20), 
			static_cast<float>(rand() % mWindow->getSize().y - 20))));
		mSpawnTimer = 0;
	}
	else
	{
		mSpawnTimer++;
	}
}

void Game::RockCollion()
{
	/* Detects collion and ends the game! */
	for (auto* i : mRocks)
	{
		if (mPlayer.getSprite().getGlobalBounds().contains(i->getRock().getPosition()))
		{
			gameOver = true;
		}
	}
}

void Game::Render()
{
	mWindow->setView(mWindowView);
	mWindow->clear();

	//Draw everything here

	mPlayer.Render(*mWindow);

	for (auto* i : mRocks)
	{
		i->Render(*mWindow);
	}

	mWindow->display();

}
