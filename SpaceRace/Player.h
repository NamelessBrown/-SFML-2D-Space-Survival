#pragma once

#include "Rocks.h"

class Player
{
public:
	Player();
	virtual ~Player();

	Player(const Player&) = delete;
	Player operator=(const Player&) = delete;

	//functions
	void Update();
	void Render(sf::RenderTarget& target);

	//getters
	const sf::Sprite& getSprite() const { return mSprite; }

private:
	sf::Texture* mTexture;
	sf::Sprite mSprite;
	sf::IntRect mTextureRect;

	int mCycleAnimation;
	float mSpeed;

	//functions
	void Animation();
	void Movement();
};

