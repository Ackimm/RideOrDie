#ifndef _PLAYER_H_
#define _PLAYER_H_

extern char map[MaxX][MaxY];
extern int mX;
extern int mY;

struct position
{
	int x;
	int y;
};

struct facingSide
{
	bool faceUp;
	bool faceDown;
	bool faceLeft;
	bool faceRight;
};

struct play
{
	int vie;
	struct position pos;
	struct facingSide facing;
};

typedef struct play* player;


player createPlayer(int mX, int mY);
void moveLeft(player p);
void moveRight(player p);
void moveUp(player p);
void moveDown(player p);

#endif
