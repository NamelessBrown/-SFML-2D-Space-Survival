#include "Game.h"

Game::Game()
	:mEvent(sf::Event()), mSpawnTimer(0), mSpawnTimerMax(50), gameOver(false), mPlayerPoints(0)
{
	mWindow = new sf::RenderWindow(sf::VideoMode(500, 500), "SpaceDodgers", sf::Style::Close | sf::Style::Titlebar);
	mWindow->setFramerateLimit(60); //Sets the framrate to 60, so I don't have to do calculations.
	mWindowView.setCenter(mPlayer.getSprite().getPosition());

	mFont.loadFromFile("Font/256BYTES.ttf");
	mText.setFont(mFont);
	mText.setCharacterSize(50);
	mText.setStyle(sf::Text::Italic | sf::Text::Bold);

	mMusic = new sf::Music();

	mMusic->openFromFile("Sound/KevinMacLeod _MysticForce.ogg");
	mMusic->play();
	mMusic->setLoop(true);
}

Game::~Game()
{
	mMusic->stop();

	delete mMusic;

	//Delete everything in the vector. Then, get rid of the vector
	for (auto* i : mRocks)
	{
		delete i;
	}

	delete mWindow;

	std::cout << "Press [Enter] to continue...\n";
	std::cin.get();
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

	std::stringstream ss;

	ss << "Points: " << mPlayerPoints;

	mText.setString(ss.str());
}

void Game::SpawnRocks()
{
	/* Spawns the rocks every time SpawnTimer reaches 100,  also deletes if the Rocks are out of Screen */

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

	for (unsigned i = 0; i < mRocks.size(); ++i)
	{
		if (mRocks[i]->getRock().getGlobalBounds().top > mWindowView.getSize().y)
		{
			mRocks.erase(mRocks.begin() + i);
			++mPlayerPoints;
		}
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
			std::cout << "Your total points were -> " << mPlayerPoints << '\n';
		}
	}

	/* Game over if the player goes off the off the screen */
	if (mPlayer.getSprite().getGlobalBounds().top > mWindowView.getSize().y)
	{
		gameOver = true;
		std::cout << "Your total points were -> " << mPlayerPoints << '\n';
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

	mWindow->draw(mText);

	mWindow->display();

}
