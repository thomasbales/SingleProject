#pragma once
#include "Point.h"
#include "Level.h"

enum class ActorColor
{
	Regular = 7,
	Blue = 9,
	Green = 10,
	Red = 12,
	SolidGreen = 34,
	SolidRed = 68,
	SolidBlue = 153
};

enum class ActorType
{
	Door,
	Enemy,
	Goal,
	Key,
	Money,
	Player,
	Box
};

class PlacableActor
{
public:
	PlacableActor(int x, int y, ActorColor color = ActorColor::Regular);
	virtual ~PlacableActor();

	int GetXPosition();
	int GetYPosition();
	int* GetXPositionPointer();
	int* GetYPositionPointer();
	void SetPosition(int x, int y);

	ActorColor GetColor() { return m_color; }

	void Remove() { m_IsActive = false; }
	bool IsActive() { return m_IsActive; }
	void Place(int x, int y);

	virtual ActorType GetType() = 0;
	virtual void Draw() = 0;
	virtual void Update(Level* level)
	{

	}

protected:
	Point* m_pPosition;

	bool m_IsActive;
	ActorColor m_color;
};