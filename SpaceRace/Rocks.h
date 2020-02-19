#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

class Rocks
{
public:
	Rocks(sf::Vector2f randomPosition);
	virtual ~Rocks();

	void Render(sf::RenderTarget& target);

	const sf::CircleShape& getRock() const { return mRock; }
private:
	sf::CircleShape mRock;
	float mSpeed;

};

