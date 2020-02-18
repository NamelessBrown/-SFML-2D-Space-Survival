#include "Player.h"

Player::Player()
	:mCycleAnimation(1), mTextureRect(0, 0, 100, 150), mSpeed(2.f)
{
	mTexture = new sf::Texture();
	mTexture->loadFromFile("Texture/rocket.png");

	mSprite.setTexture(*mTexture);
	mSprite.setTextureRect(mTextureRect);
	mSprite.setPosition(sf::Vector2f(200, 350));
}

Player::~Player()
{
	delete mTexture;
}

void Player::Update()
{
	Animation();
	Movement();
}

void Player::Render(sf::RenderTarget& target)
{
	target.draw(mSprite);
}

void Player::Animation()
{
	/* Loops through two possible sprites in the spritesheet */

	//mTextureRect.left = mCycleAnimation * 50;
	mSprite.setTextureRect(mTextureRect);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mTextureRect.top = mCycleAnimation * 150;
		mSprite.setTextureRect(mTextureRect);
		mSprite.move(0, -mSpeed);
	}
	else
	{
		mTextureRect.top = 0;
		mSprite.setTextureRect(mTextureRect);
		mSprite.move(0, mSpeed);
	}

}

void Player::Movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		mSprite.move(sf::Vector2f(-mSpeed, 0));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mSprite.move(sf::Vector2f(mSpeed, 0));
	}

}