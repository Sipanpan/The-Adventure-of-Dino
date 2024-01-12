#pragma once

struct Dino
{
	double posX;
	double posY;
	double velX;
	double velY;
	double radius;
	double gravity;
	double lompat;
	double width;
	double height;
};

struct Coin
{
	double posX;
	double posY;
	double radius;
};

struct Enemy
{
	double posX;
	double posY;
	double radius;
};

struct Background
{
	double posX;
	double posY;
};

struct Ground
{
	double posX;
	double posY;
};

struct Platform
{
	double posX;
	double posY;
	double kiri;
	double kanan;
	double atas;
	double height;
};

struct Portal
{
	double posX;
	double posY;
	double radius;
};

struct Kiri
{
	double posX;
};

struct Kanan
{
	double posX;
};

struct Box
{
	double posX, posY;
	double width, height;
};