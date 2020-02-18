#include "Rocks.h"

Rocks::Rocks(sf::Vector2f randomPosition)
	:mSpeed(2.5f)
{
	mRock.setRadius(static_cast<float>(rand() % 20 + 20));
	mRock.setPointCount(rand() % 20 + 3);
	mRock.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255, rand() % 255, rand() % 255));
	mRock.setPosition(randomPosition);
}

Rocks::~Rocks()
{
}

void Rocks::Render(sf::RenderTarget& target)
{
	mRock.move(0.f, mSpeed);
	target.draw(mRock);
}
