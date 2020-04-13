// SeniorSoftwareEngineering.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

struct Vector2 {
	int x;
	int y;
};

class Player {

public:
	Player(int mUniqueId);

	Player(const Player& other);
	Player& operator=(const Player &other) = default;

	int getId();
	Vector2 getPosition();

	void setStartPosition(Vector2 startPosition);

	void setMovementDelta(int deltaX, int deltaY, int speedMultiplier);

	void moveToNewPosition();

private:
	Vector2 mStartPosition;
	std::vector<Vector2> mMovementDeltas;
	Vector2 mCurrentPosition;
	int mUniqueId;
};

Player::Player(int id) {

	mUniqueId = id;

}

Player::Player(const Player& other) {
	mStartPosition = other.mStartPosition;
	mMovementDeltas = other.mMovementDeltas;
	mCurrentPosition = other.mCurrentPosition;
}

int Player::getId() {
	return mUniqueId;
}

Vector2 Player::getPosition() {
	return mCurrentPosition;
}

void Player::setStartPosition(Vector2 startPosition) {
	mStartPosition = startPosition;
	mCurrentPosition = startPosition;
}

void Player::setMovementDelta(int deltaX, int deltaY, int speedMultiplier) {
	Vector2 newPoint;
	newPoint.x = deltaX * speedMultiplier;
	newPoint.y = deltaY * speedMultiplier;
	mMovementDeltas.push_back(newPoint);
}

void Player::moveToNewPosition() {

	for (std::size_t i = 0; i < mMovementDeltas.size(); ++i) {
		mCurrentPosition.x += mMovementDeltas[i].x;
		mCurrentPosition.y += mMovementDeltas[i].y;
	}

}

int main()
{
	Player playerA(352);
	Player playerB = playerA;

	Vector2 startPos;
	startPos.x = 8;
	startPos.y = 0;

	playerA.setStartPosition(startPos);

	playerA.setMovementDelta(2, 1, 2);
	playerA.setMovementDelta(1, 3, 1);
	playerA.setMovementDelta(1, 2, 2);

	playerA.moveToNewPosition();

	std::cout << "Player A Id: " << playerA.getId() << std::endl;

	std::cout << "Player A Postion is (" << playerA.getPosition().x << ", " << playerA.getPosition().y << ")" << std::endl;

	std::cout << "Player B Id: " << playerB.getId() << std::endl;
}
