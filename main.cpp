#include <sl.h>
#include "entities.h"
#include <string>
#include <random>
#include <vector>
#include <Windows.h>

using namespace std;

bool isCollision(Dino, Enemy);
bool isCollision(Dino, Coin);
bool isCollision(Dino, Portal);
bool isNapak(Dino, Platform);
bool isNabrakKanan(Dino, Box);
bool isNabrakKiri(Dino, Box);
bool isNabrakAtas(Dino, Box);
bool isJedot(Dino, Platform);
bool isJedot(Dino, Box);

// Backsound
void Backsound()
{
	int bgm2 = slLoadWAV("C:\\codding try and error\\dino\\Asset\\Sound\\backsound\\Main Menu.wav");
	slSoundLoop(bgm2);
}

int main()
{
	slWindow(1920, 1080, "Dino", true);
	Backsound();

	// Load Asset
	int imgBg1 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 1\\bg1.png");
	int imgBg2 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 2\\bg2.png");
	int imgBg3 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 3\\bg3.png");
	int imgBg4 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 4\\bg4.png");
	int imgFrame1 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 1\\frame1.png");
	int imgFrame2 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 2\\frame2.png");
	int imgFrame3 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 3\\frame3.png");
	int imgGround_1 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 1\\ground1.png");
	int imgGround_2 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 2\\ground2.png");
	int imgGround_3 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 3\\ground3.png");
	int imgGround_4 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 4\\ground4.png");
	int imgPlt1_1 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 1\\plt1_1.png");
	int imgPlt1_2 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 1\\plt1_2.png");
	int imgPlt1_3 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 1\\plt1_3.png");
	int imgPlt2_1 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 2\\plt2_1.png");
	int imgPlt2_2 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 2\\plt2_2.png");
	int imgPlt2_3 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 2\\plt2_3.png");
	int imgPlt3_1 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 3\\plt3_1.png");
    int imgPlt3_2 =	slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 3\\plt3_2.png");
	int imgPlt3_3 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 3\\plt3_3.png");
	int imgPlt3_4 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 3\\plt3_4.png");
	int imgPlt4_1 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 4\\plt4_1.png");
	int imgPlt4_2 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 4\\plt4_2.png");
	int imgPlt4_3 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 4\\plt4_3.png");
	int imgPlt4_4 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 4\\plt4_4.png");
	int imgPlt4_5 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 4\\plt4_5.png");
	int imgPlt4_6 = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Background\\level 4\\plt4_6.png");
	int sndcoin = slLoadWAV("C:\\codding try and error\\dino\\Asset\\Sound\\sfx\\coin.wav");
	int snddeath = slLoadWAV("C:\\codding try and error\\dino\\Asset\\Sound\\sfx\\death.wav");
	int sndportal = slLoadWAV("C:\\codding try and error\\dino\\Asset\\Sound\\sfx\\portal.wav");
	int sndjump = slLoadWAV("C:\\codding try and error\\dino\\Asset\\Sound\\sfx\\jump.wav");
	int sndtamat = slLoadWAV("C:\\codding try and error\\dino\\Asset\\Sound\\sfx\\tamat.wav");
	
	int imgApi = slLoadTexture("C:\\codding try and error\\dino\\Asset\\Enemy\\api\\api1.png");
	int font = slLoadFont("C:\\codding try and error\\dino\\Asset\\font\\score.ttf");

	// Load Asset Animasi
	// Idle Kanan
	vector<int> idleKanan = {
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Right\\idle\\tard1.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Right\\idle\\tard2.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Right\\idle\\tard3.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Right\\idle\\tard4.png")
	};
	// Idle Kiri
	vector<int> idleKiri = {
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Left\\idle\\tard1.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Left\\idle\\tard2.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Left\\idle\\tard3.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Left\\idle\\tard4.png")
	};
	// Moving Kanan
	vector<int> movingKiri = {
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Right\\moving\\tard1.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Right\\moving\\tard2.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Right\\moving\\tard3.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Right\\moving\\tard4.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Right\\moving\\tard5.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Right\\moving\\tard6.png")
	};
	// Moving Kiri
	vector<int> movingKanan = {
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Left\\moving\\tard1.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Left\\moving\\tard2.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Left\\moving\\tard3.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Left\\moving\\tard4.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Left\\moving\\tard5.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Player\\Left\\moving\\tard6.png"),
	};
	// Coin
	vector<int> idleCoin = {
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Coin\\coin1.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Coin\\coin2.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Coin\\coin3.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Coin\\coin4.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Coin\\coin5.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Coin\\coin6.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Coin\\coin7.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Coin\\coin8.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Coin\\coin9.png")
	};
	// Portal
	vector<int> idlePortal = {
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal1.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal2.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal3.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal4.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal5.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal6.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal7.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal8.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal9.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal10.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal10.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal12.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal13.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal14.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal15.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal16.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal17.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal18.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal19.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal20.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal21.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal22.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal23.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal24.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal25.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal26.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal27.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal28.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal29.png"),
		slLoadTexture("C:\\codding try and error\\dino\\Asset\\Portal\\portal30.png")
	};

	// Setting System
	// random_device rd;
	int jmlhcoin = 0;
	int level = 1;
	slSetFont(font, 40);
	bool gameOver = false;

	// Setting Animasi
	// Idle
	int currentIdleFrame = 0;
	double idleAnimationDelay = 0.2;
	// Moving
	int currentMovingFrame = 0;
	double movingAnimationDelay = 0.2;
	// idle Portal
	int currentIdlePortal = 0;
	double portalAnimationDelay = 0.1;
	// idle Coin
	int currentIdleCoin = 0;
	double coinAnimationDelay = 0.1;

	// Inisialisasi Objek
	Dino dino;
	{
		dino.posX = 1200;
		dino.posY = 125;
		dino.velX = 0;
		dino.velY = 0;
		dino.radius = 30;
		dino.gravity = -0.2;
		dino.lompat = false;
		dino.width = 20;
		dino.height = 15;
	}
	
	Coin coin1;
	{
		coin1.posX = 400;
		coin1.posY = 150;
		coin1.radius = 10;
	}

	Coin coin2;
	{
		coin2.posX = 200;
		coin2.posY = 230;
		coin2.radius = 10;
	}
	
	Coin coin3;
	{
		coin3.posX = 600;
		coin3.posY = 330;
		coin3.radius = 10;
	}

	Enemy musuh;
	{
		musuh.posX = 600;
		musuh.posY = 150;
		musuh.radius = 10;
	}
	
	Background bg1;
	{
		bg1.posX = 960;
		bg1.posY = 540;
	}
	
	Background bg2;
	{
		bg2.posX = 3000;
		bg2.posY = 540;
	}
	
	Background bg3;
	{
		bg3.posX = 3000;
		bg3.posY = 540;
	}
	
	Background bg4;
	{
		bg4.posX = 3000;
		bg4.posY = 540;
	}

	Ground ground1;
	{
		ground1.posX = 3000;
		ground1.posY = 180;
	}
	
	Ground ground2;
	{
		ground2.posX = 3000;
		ground2.posY = 180;
	}
	
	Ground ground3;
	{
		ground3.posX = 3000;
		ground3.posY = 180;
	}

	Ground ground4;
	{
		ground4.posX = 3000;
		ground4.posY = 250;
	}
	
	Platform plt1_1;
	{
		plt1_1.posX = 3000;
		plt1_1.posY = 100;
		plt1_1.kiri = 900;
		plt1_1.kanan = 350;
		plt1_1.atas = 30;
		plt1_1.height = 5;
	}


	// LVL 1
	Box box1_G1;
	{
		box1_G1.posX = 3000;
		box1_G1.posY = 0;
		box1_G1.width = 1920;
		box1_G1.height = 119;
	}

	Box box1_A1_1;
	{
		box1_A1_1.posX = 3000;
		box1_A1_1.posY = 210;
		box1_A1_1.width = 305;
		box1_A1_1.height = 40;
	}

	Box box1_A1_2;
	{
		box1_A1_2.posX = 3000;
		box1_A1_2.posY = 224;
		box1_A1_2.width = 164;
		box1_A1_2.height = 40;
	}

	Box box1_A1_3;
	{
		box1_A1_3.posX = 3000;
		box1_A1_3.posY = 239;
		box1_A1_3.width = 594;
		box1_A1_3.height = 40;
	}

	Box box1_A1_4;
	{
		box1_A1_4.posX = 3000;
		box1_A1_4.posY = 260;
		box1_A1_4.width = 250;
		box1_A1_4.height = 107;
	}

	Box box1_A1_5;
	{
		box1_A1_5.posX = 3000;
		box1_A1_5.posY = 263;
		box1_A1_5.width = 200;
		box1_A1_5.height = 150;
	}

	Box box1_A2_1;
	{
		box1_A2_1.posX = 3000;
		box1_A2_1.posY = 386;
		box1_A2_1.width = 232;
		box1_A2_1.height = 50;
	}

	Box box1_A2_2;
	{
		box1_A2_2.posX = 3000;
		box1_A2_2.posY = 416;
		box1_A2_2.width = 1000;
		box1_A2_2.height = 50;
	}

	Box box1_A2_3;
	{
		box1_A2_3.posX = 3000;
		box1_A2_3.posY = 340;
		box1_A2_3.width = 260;
		box1_A2_3.height = 80;
	}

	Box box1_A2_4;
	{
		box1_A2_4.posX = 3000;
		box1_A2_4.posY = 265;
		box1_A2_4.width = 120;
		box1_A2_4.height = 80;
	}

	Box box1_A3_1;
	{
		box1_A3_1.posX = 3000;
		box1_A3_1.posY = 577;
		box1_A3_1.width = 940;
		box1_A3_1.height = 50;
	}

	Box box1_B1_1;
	{
		box1_B1_1.posX = 3000;
		box1_B1_1.posY = 193;
		box1_B1_1.width = 305;
		box1_B1_1.height = 40;
	}

	Box box1_B1_2;
	{
		box1_B1_2.posX = 3000;
		box1_B1_2.posY = 207;
		box1_B1_2.width = 164;
		box1_B1_2.height = 10;
	}

	Box box1_B1_3;
	{
		box1_B1_3.posX = 3000;
		box1_B1_3.posY = 223;
		box1_B1_3.width = 950;
		box1_B1_3.height = 40;
	}

	Box box1_B2_1;
	{
		box1_B2_1.posX = 3000;
		box1_B2_1.posY = 370;
		box1_B2_1.width = 232;
		box1_B2_1.height = 30;
	}

	Box box1_B2_2;
	{
		box1_B2_2.posX = 3000;
		box1_B2_2.posY = 400;
		box1_B2_2.width = 1000;
		box1_B2_2.height = 40;
	}

	Box box1_B2_3;
	{
		box1_B2_3.posX = 3000;
		box1_B2_3.posY = 320;
		box1_B2_3.width = 232;
		box1_B2_3.height = 50;
	}

	Box box1_B2_4;
	{
		box1_B2_4.posX = 3000;
		box1_B2_4.posY = 230;
		box1_B2_4.width = 232;
		box1_B2_4.height = 50;
	}

	Box box1_B2_5;
	{
		box1_B2_5.posX = 3000;
		box1_B2_5.posY = 310;
		box1_B2_5.width = 232;
		box1_B2_5.height = 50;
	}

	Box box1_B3_1;
	{
		box1_B3_1.posX = 3000;
		box1_B3_1.posY = 556;
		box1_B3_1.width = 940;
		box1_B3_1.height = 50;
	}

	// LVL 2

	Box box2_G1;
	{
		box2_G1.posX = 3000;
		box2_G1.posY = 0;
		box2_G1.width = 1920;
		box2_G1.height = 119;
	}

	Box box2_A1_1;
	{
		box2_A1_1.posX = 3000;
		box2_A1_1.posY = 270;
		box2_A1_1.width = 1150;
		box2_A1_1.height = 45;
	}

	Box box2_A2_1;
	{
		box2_A2_1.posX = 3000;
		box2_A2_1.posY = 439;
		box2_A2_1.width = 240;
		box2_A2_1.height = 45;
	}

	Box box2_A2_2;
	{
		box2_A2_2.posX = 3000;
		box2_A2_2.posY = 475;
		box2_A2_2.width = 250;
		box2_A2_2.height = 45;
	}

	Box box2_A2_3;
	{
		box2_A2_3.posX = 3000;
		box2_A2_3.posY = 517;
		box2_A2_3.width = 900;
		box2_A2_3.height = 45;
	}

	Box box2_A3_1;
	{
		box2_A3_1.posX = 3000;
		box2_A3_1.posY = 708;
		box2_A3_1.width = 1277;
		box2_A3_1.height = 45;
	}

	Box box2_A3_2;
	{
		box2_A3_2.posX = 3000;
		box2_A3_2.posY = 750;
		box2_A3_2.width = 63;
		box2_A3_2.height = 45;
	}

	Box box2_A3_3;
	{
		box2_A3_3.posX = 3000;
		box2_A3_3.posY = 750;
		box2_A3_3.width = 250;
		box2_A3_3.height = 45;
	}

	Box box2_A3_4;
	{
		box2_A3_4.posX = 3000;
		box2_A3_4.posY = 494;
		box2_A3_4.width = 170;
		box2_A3_4.height = 250;
	}

	Box box2_B1_1;
	{
		box2_B1_1.posX = 3000;
		box2_B1_1.posY = 235;
		box2_B1_1.width = 1150;
		box2_B1_1.height = 30;
	}

	Box box2_B2_1;
	{
		box2_B2_1.posX = 3000;
		box2_B2_1.posY = 420;
		box2_B2_1.width = 250;
		box2_B2_1.height = 30;
	}

	Box box2_B2_2;
	{
		box2_B2_2.posX = 3000;
		box2_B2_2.posY = 450;
		box2_B2_2.width = 220;
		box2_B2_2.height = 30;
	}

	Box box2_B2_3;
	{
		box2_B2_3.posX = 3000;
		box2_B2_3.posY = 500;
		box2_B2_3.width = 900;
		box2_B2_3.height = 30;
	}

	Box box2_B3_1;
	{
		box2_B3_1.posX = 3000;
		box2_B3_1.posY = 680;
		box2_B3_1.width = 1277;
		box2_B3_1.height = 40;
	}

	Box box2_B3_2;
	{
		box2_B3_2.posX = 3000;
		box2_B3_2.posY = 483;
		box2_B3_2.width = 165;
		box2_B3_2.height = 250;
	}

	// LVL 3

	Box box3_G1;
	{
		box3_G1.posX = 3000;
		box3_G1.posY = 0;
		box3_G1.width = 500;
		box3_G1.height = 252;
	}

	Box box3_G2;
	{
		box3_G2.posX = 3000;
		box3_G2.posY = 5;
		box3_G2.width = 275;
		box3_G2.height = 90;
	}

	Box box3_G3;
	{
		box3_G3.posX = 3000;
		box3_G3.posY = 0;
		box3_G3.width = 257;
		box3_G3.height = 80;
	}

	Box box3_G4;
	{
		box3_G4.posX = 3000;
		box3_G4.posY = 0;
		box3_G4.width = 285;
		box3_G4.height = 200;
	}

	Box box3_G5;
	{
		box3_G5.posX = 3000;
		box3_G5.posY = 0;
		box3_G5.width = 580;
		box3_G5.height = 340;
		box3_G5.height = 353;
	}

	Box box3_A1_1;
	{
		box3_A1_1.posX = 3000;
		box3_A1_1.posY = 417;
		box3_A1_1.width = 750;
		box3_A1_1.height = 40;
	}

	Box box3_A2_1;
	{
		box3_A2_1.posX = 3000;
		box3_A2_1.posY = 597;
		box3_A2_1.width = 600;
		box3_A2_1.height = 40;
	}

	Box box3_A3_1;
	{
		box3_A3_1.posX = 3000;
		box3_A3_1.posY = 753;
		box3_A3_1.width = 1000;
		box3_A3_1.height = 40;
	}

	Box box3_A4_1;
	{
		box3_A4_1.posX = 3000;
		box3_A4_1.posY = 754;
		box3_A4_1.width = 400;
		box3_A4_1.height = 40;
	}

	Box box3_B1_1;
	{
		box3_B1_1.posX = 3000;
		box3_B1_1.posY = 410;
		box3_B1_1.width = 750;
		box3_B1_1.height = 25;
	}

	Box box3_B2_1;
	{
		box3_B2_1.posX = 3000;
		box3_B2_1.posY = 590;
		box3_B2_1.width = 600;
		box3_B2_1.height = 25;
	}
	
	Box box3_B3_1;
	{
		box3_B3_1.posX = 3000;
		box3_B3_1.posY = 750;
		box3_B3_1.width = 1000;
		box3_B3_1.height = 25;
	}

	Box box3_B4_1;
	{
		box3_B4_1.posX = 3000;
		box3_B4_1.posY = 750;
		box3_B4_1.width = 400;
		box3_B4_1.height = 25;
	}

	// LVL 4
	Box box4_G1;
	{
		box4_G1.posX = 3000;
		box4_G1.posY = 0;
		box4_G1.width = 700;
		box4_G1.height = 160;
	}

	Box box4_G2;
	{
		box4_G2.posX = 3000;
		box4_G2.posY = 0;
		box4_G2.width = 500;
		box4_G2.height = 83;
	}

	Box box4_G3;
	{
		box4_G3.posX = 3000;
		box4_G3.posY = 0;
		box4_G3.width = 400;
		box4_G3.height = 182;
	}

	Box box4_G4;
	{
		box4_G4.posX = 3000;
		box4_G4.posY = 0;
		box4_G4.width = 500;
		box4_G4.height = 85;
	}

	Box box4_A1_1;
	{
		box4_A1_1.posX = 3000;
		box4_A1_1.posY = 301;
		box4_A1_1.width = 450;
		box4_A1_1.height = 40;
	}

	Box box4_A2_1;
	{
		box4_A2_1.posX = 3000;
		box4_A2_1.posY = 440;
		box4_A2_1.width = 500;
		box4_A2_1.height = 40;
	}

	Box box4_A2_2;
	{
		box4_A2_2.posX = 3000;
		box4_A2_2.posY = 675;
		box4_A2_2.width = 670;
		box4_A2_2.height = 40;
	}

	Box box4_A3_1;
	{
		box4_A3_1.posX = 3000;
		box4_A3_1.posY = 500;
		box4_A3_1.width = 490;
		box4_A3_1.height = 40;
	}

	Box box4_A4_1;
	{
		box4_A4_1.posX = 3000;
		box4_A4_1.posY = 338;
		box4_A4_1.width = 400;
		box4_A4_1.height = 40;
	}

	Box box4_A5_1;
	{
		box4_A5_1.posX = 3000;
		box4_A5_1.posY = 658;
		box4_A5_1.width = 800;
		box4_A5_1.height = 40;
	}

	Box box4_A6_1;
	{
		box4_A6_1.posX = 3000;
		box4_A6_1.posY = 897;
		box4_A6_1.width = 1200;
		box4_A6_1.height = 40;
	}

	Box box4_A6_2;
	{
		box4_A6_2.posX = 3000;
		box4_A6_2.posY = 715;
		box4_A6_2.width = 500;
		box4_A6_2.height = 40;
	}

	Box box4_B1_1;
	{
		box4_B1_1.posX = 3000;
		box4_B1_1.posY = 291;
		box4_B1_1.width = 450;
		box4_B1_1.height = 25;
	}

	Box box4_B2_1;
	{
		box4_B2_1.posX = 3000;
		box4_B2_1.posY = 430;
		box4_B2_1.width = 500;
		box4_B2_1.height = 25;
	}

	Box box4_B2_2;
	{
		box4_B2_2.posX = 3000;
		box4_B2_2.posY = 665;
		box4_B2_2.width = 670;
		box4_B2_2.height = 25;
	}

	Box box4_B3_1;
	{
		box4_B3_1.posX = 3000;
		box4_B3_1.posY = 490;
		box4_B3_1.width = 490;
		box4_B3_1.height = 25;
	}

	Box box4_B4_1;
	{
		box4_B4_1.posX = 3000;
		box4_B4_1.posY = 328;
		box4_B4_1.width = 400;
		box4_B4_1.height = 25;
	}

	Box box4_B5_1;
	{
		box4_B5_1.posX = 3000;
		box4_B5_1.posY = 648;
		box4_B5_1.width = 800;
		box4_B5_1.height = 25;
	}
	
	Box box4_B6_1;
	{
		box4_B6_1.posX = 3000;
		box4_B6_1.posY = 887;
		box4_B6_1.width = 1200;
		box4_B6_1.height = 25;
	}

	Box box4_B6_2;
	{
		box4_B6_2.posX = 3000;
		box4_B6_2.posY = 705;
		box4_B6_2.width = 500;
		box4_B6_2.height = 25;
	}

	Platform plt1_2;
	{
		plt1_2.posX = 3000;
		plt1_2.posY = 200;
		plt1_2.kiri = 400;
		plt1_2.kanan = 700;
		plt1_2.atas = 60;
		plt1_2.height = 5;
	}
	
	Platform plt1_3;
	{
		plt1_3.posX = 3000;
		plt1_3.posY = 300;
		plt1_3.kiri = 300;
		plt1_3.kanan = 550;
		plt1_3.atas = 50;
		plt1_3.height = 5;
	}
	
	Platform plt2_1;
	{
		plt2_1.posX = 3000;
		plt2_1.posY = 100;
		plt2_1.kiri = 400;
		plt2_1.kanan = 400;
	}
	
	Platform plt2_2;
	{
		plt2_2.posX = 3000;
		plt2_2.posY = 100;
		plt2_2.kiri = 400;
		plt2_2.kanan = 400;
	}
	
	Platform plt2_3;
	{
		plt2_3.posX = 3000;
		plt2_3.posY = 100;
		plt2_3.kiri = 400;
		plt2_3.kanan = 400;
	}
	
	Platform plt3_1;
	{
		plt3_1.posX = 3000;
		plt3_1.posY = 100;
		plt3_1.kiri = 400;
		plt3_1.kanan = 400;
	}
	
	Platform plt3_2;
	{
		plt3_2.posX = 3000;
		plt3_2.posY = 100;
		plt3_2.kiri = 400;
		plt3_2.kanan = 400;
	}
	
	Platform plt3_3;
	{
		plt3_3.posX = 3000;
		plt3_3.posY = 100;
		plt3_3.kiri = 400;
		plt3_3.kanan = 400;
	}

	Platform plt3_4;
	{
		plt3_4.posX = 3000;
		plt3_4.posY = 100;
		plt3_4.kiri = 400;
		plt3_4.kanan = 400;
	}

	Platform plt4_1;
	{
		plt4_1.posX = 3000;
		plt4_1.posY = 380;
		plt4_1.kiri = 400;
		plt4_1.kanan = 700;
	}

	Platform plt4_2;
	{
		plt4_2.posX = 3000;
		plt4_2.posY = 600;
		plt4_2.kiri = 400;
		plt4_2.kanan = 700;
	}

	Platform plt4_3;
	{
		plt4_3.posX = 3000;
		plt4_3.posY = 500;
		plt4_3.kiri = 400;
		plt4_3.kanan = 700;
	}

	Platform plt4_4;
	{
		plt4_4.posX = 3000;
		plt4_4.posY = 400;
		plt4_4.kiri = 400;
		plt4_4.kanan = 700;
	}

	Platform plt4_5;
	{
		plt4_5.posX = 3000;
		plt4_5.posY = 720;
		plt4_5.kiri = 400;
		plt4_5.kanan = 700;
	}

	Platform plt4_6;
	{
		plt4_6.posX = 3000;
		plt4_6.posY = 795;
		plt4_6.kiri = 400;
	}

	Portal portal;
	{
		portal.posX = 2000;
		portal.posY = 80;
		portal.radius = 20;
	}
	

	while (!slShouldClose())
	{
		// Render asset
		{
			// Background
			{
				slSprite(imgBg1, bg1.posX, bg1.posY, 1920, 1080);
				slSprite(imgBg2, bg2.posX, bg2.posY, 1920, 1080);
				slSprite(imgBg3, bg3.posX, bg3.posY, 1920, 1080);
				slSprite(imgBg4, bg4.posX, bg4.posY, 1920, 1080);
			}
			// Ground
			{
				slSprite(imgGround_1, ground1.posX, ground1.posY, 1920, 500);
				slSprite(imgGround_2, ground2.posX, ground2.posY, 1920, 500);
				slSprite(imgGround_3, ground3.posX, ground3.posY, 1920, 500);
				slSprite(imgGround_4, ground4.posX, ground4.posY, 1920, 500);
			}
			// Platform
			{
				slSprite(imgPlt1_1, plt1_1.posX, plt1_1.posY, 1800, 500);
				slSprite(imgPlt1_2, plt1_2.posX, plt1_2.posY, 1500, 390);
				slSprite(imgPlt1_3, plt1_3.posX, plt1_3.posY, 1200, 333);

				slSprite(imgPlt2_1, plt2_1.posX, plt2_1.posY, 1500, 416);
				slSprite(imgPlt2_2, plt2_2.posX, plt2_2.posY, 1500, 416);
				slSprite(imgPlt2_3, plt2_3.posX, plt2_3.posY, 1500, 416);

				slSprite(imgPlt3_1, plt3_1.posX, plt3_1.posY, 786, 101);
				slSprite(imgPlt3_2, plt3_2.posX, plt3_2.posY, 616, 102);
				slSprite(imgPlt3_3, plt3_3.posX, plt3_3.posY, 636, 101);
				slSprite(imgPlt3_4, plt3_4.posX, plt3_4.posY, 409, 101);

				slSprite(imgPlt4_1, plt4_1.posX, plt4_1.posY, 452, 300);
				slSprite(imgPlt4_2, plt4_2.posX, plt4_2.posY, 1120, 400);
				slSprite(imgPlt4_3, plt4_3.posX, plt4_3.posY, 536, 80);
				slSprite(imgPlt4_4, plt4_4.posX, plt4_4.posY, 626, 280);
				slSprite(imgPlt4_5, plt4_5.posX, plt4_5.posY, 566, 280);
				slSprite(imgPlt4_6, plt4_6.posX, plt4_6.posY, 1200, 400);
			}
			// Api
			{
				slSprite(imgApi, musuh.posX, musuh.posY, 33, 54);
			}
			
		}

		// Read Input
		bool isMoving = slGetKey('D') || slGetKey('A');
		bool isJump = slGetKey('W');

		// Gamestate
		if (!gameOver)
		{
			

			// Dino Gravity
			{
				dino.velY += dino.gravity;
				dino.posY += dino.velY;
			}

			// Dino border
			{
				if (dino.posX < 50)
					dino.posX = 50;
				if (dino.posX > 1860)
					dino.posX = 1860;
			}




			if (isJump && !dino.lompat)
			{
				dino.lompat = true;
				dino.velY = 9.0;
				slSoundPlay(sndjump);
			}

			if (isCollision(dino, portal))
			{
				level += 1;
				portal.posX = 2000;
				jmlhcoin = 0;
				slSoundPlay(sndportal);
			}

			// Level
			{
				// Level 1
				if (level == 1)
				{

					// box1_G1
					{
						if (isNabrakKiri(dino, box1_G1))
						{
							dino.posX = box1_G1.posX - dino.width;
						}
						if (isNabrakKanan(dino, box1_G1))
						{
							dino.posX = box1_G1.posX + box1_G1.width;
						}
						if (isNabrakAtas(dino, box1_G1))
						{
							dino.velY = 0;
							dino.posY = box1_G1.posY + box1_G1.height + 10;
							dino.lompat = false;
						}
					}

					// box1_1
					{
						// A
						{
							// box1_A1_1
							{
								if (isNabrakKiri(dino, box1_A1_1))
								{
									dino.posX = box1_A1_1.posX - dino.width;
								}
								if (isNabrakKanan(dino, box1_A1_1))
								{
									dino.posX = box1_A1_1.posX + box1_A1_1.width;
								}
								if (isNabrakAtas(dino, box1_A1_1))
								{
									dino.velY = 0;
									dino.posY = box1_A1_1.posY + box1_A1_1.height + 10;
									dino.lompat = false;
								}
							}

							// box1_A1_2
							{
								if (isNabrakKiri(dino, box1_A1_2))
								{
									dino.posX = box1_A1_2.posX - dino.width;
								}
								if (isNabrakKanan(dino, box1_A1_2))
								{
									dino.posX = box1_A1_2.posX + box1_A1_2.width;
								}
								if (isNabrakAtas(dino, box1_A1_2))
								{
									dino.velY = 0;
									dino.posY = box1_A1_2.posY + box1_A1_2.height + 10;
									dino.lompat = false;
								}
							}

							// box1_A1_3
							{
								if (isNabrakKiri(dino, box1_A1_3))
								{
									dino.posX = box1_A1_3.posX - dino.width;
								}
								if (isNabrakKanan(dino, box1_A1_3))
								{
									dino.posX = box1_A1_3.posX + box1_A1_3.width;
								}
								if (isNabrakAtas(dino, box1_A1_3))
								{
									dino.velY = 0;
									dino.posY = box1_A1_3.posY + box1_A1_3.height + 10;
									dino.lompat = false;
								}
							}

							// box1_A1_4
							{
								if (isNabrakKiri(dino, box1_A1_4))
								{
									dino.posX = box1_A1_4.posX - dino.width;
								}
								if (isNabrakKanan(dino, box1_A1_4))
								{
									dino.posX = box1_A1_4.posX + box1_A1_4.width;
								}
								if (isNabrakAtas(dino, box1_A1_4))
								{
									dino.velY = 0;
									dino.posY = box1_A1_4.posY + box1_A1_4.height + 10;
									dino.lompat = false;
								}
							}

							// box1_A1_5
							{
								if (isNabrakKiri(dino, box1_A1_5))
								{
									dino.posX = box1_A1_5.posX - dino.width;
								}
								if (isNabrakKanan(dino, box1_A1_5))
								{
									dino.posX = box1_A1_5.posX + box1_A1_5.width;
								}
								if (isNabrakAtas(dino, box1_A1_5))
								{
									dino.velY = 0;
									dino.posY = box1_A1_5.posY + box1_A1_5.height + 10;
									dino.lompat = false;
								}
							}
						}
						// B
						{
							if (isJedot(dino, box1_B1_1))
							{
								dino.velY = 0;
								dino.posY = box1_B1_1.posY - dino.height;
							}
							if (isJedot(dino, box1_B1_2))
							{
								dino.velY = 0;
								dino.posY = box1_B1_2.posY - dino.height;
							}
							if (isJedot(dino, box1_B1_3))
							{
								dino.velY = 0;
								dino.posY = box1_B1_3.posY - dino.height;
							}
						}
					}


					// box1_2
					{
						// A
						{
							// box1_A2_2
							{
								if (isNabrakKiri(dino, box1_A2_2))
								{
									dino.posX = box1_A2_2.posX - dino.width;
								}
								if (isNabrakKanan(dino, box1_A2_2))
								{
									dino.posX = box1_A2_2.posX + box1_A2_2.width;
								}
								if (isNabrakAtas(dino, box1_A2_2))
								{
									dino.velY = 0;
									dino.posY = box1_A2_2.posY + box1_A2_2.height + 10;
									dino.lompat = false;
								}
							}
							// box1_A2_1
							{
								if (isNabrakKiri(dino, box1_A2_1))
								{
									dino.posX = box1_A2_1.posX - dino.width;
								}
								if (isNabrakKanan(dino, box1_A2_1))
								{
									dino.posX = box1_A2_1.posX + box1_A2_1.width;
								}
								if (isNabrakAtas(dino, box1_A2_1))
								{
									dino.velY = 0;
									dino.posY = box1_A2_1.posY + box1_A2_1.height + 10;
									dino.lompat = false;
								}
							}
							// box1_A2_3
							{
								if (isNabrakKiri(dino, box1_A2_3))
								{
									dino.posX = box1_A2_3.posX - dino.width;
								}
								if (isNabrakKanan(dino, box1_A2_3))
								{
									dino.posX = box1_A2_3.posX + box1_A2_3.width;
								}
								if (isNabrakAtas(dino, box1_A2_3))
								{
									dino.velY = 0;
									dino.posY = box1_A2_3.posY + box1_A2_3.height + 10;
									dino.lompat = false;
								}
							}
							// box1_A2_4
							{
								if (isNabrakKiri(dino, box1_A2_4))
								{
									dino.posX = box1_A2_4.posX - dino.width;
								}
								if (isNabrakKanan(dino, box1_A2_4))
								{
									dino.posX = box1_A2_4.posX + box1_A2_4.width;
								}
								if (isNabrakAtas(dino, box1_A2_4))
								{
									dino.velY = 0;
									dino.posY = box1_A2_4.posY + box1_A2_4.height + 10;
									dino.lompat = false;
								}
							}
						}

						// B
						{
							if (isJedot(dino, box1_B2_1))
							{
								dino.velY = 0;
								dino.posY = box1_B2_1.posY - dino.height;
							}
							if (isJedot(dino, box1_B2_2))
							{
								dino.velY = 0;
								dino.posY = box1_B2_2.posY - dino.height;
							}
							if (isJedot(dino, box1_B2_3))
							{
								dino.velY = 0;
								dino.posY = box1_B2_3.posY - dino.height;
							}
						}
					}

					// box1_3
					{
						// A
						{
							// box1_A3_1
							{
								if (isNabrakKiri(dino, box1_A3_1))
								{
									dino.posX = box1_A3_1.posX - dino.width;
								}
								if (isNabrakKanan(dino, box1_A3_1))
								{
									dino.posX = box1_A3_1.posX + box1_A3_1.width;
								}
								if (isNabrakAtas(dino, box1_A3_1))
								{
									dino.velY = 0;
									dino.posY = box1_A3_1.posY + box1_A3_1.height + 10;
									dino.lompat = false;
								}
							}
						}
						// B
						{
							if (isJedot(dino, box1_B3_1))
							{
								dino.velY = 0;
								dino.posY = box1_B3_1.posY - dino.height;
							}
						}
					}

					if (jmlhcoin == 0)
					{
						// posisi coin
						coin1.posX = 100;
						coin1.posY = 450;
						coin2.posX = 1700;
						coin2.posY = 510;
						coin3.posX = 200;
						coin3.posY = 670;

						// posisi platform
						ground1.posX = 960;
						plt1_1.posX = 900;
						plt1_1.posY = 250;
						plt1_2.posX = 1200;
						plt1_2.posY = 400;
						plt1_3.posX = 400;
						plt1_3.posY = 600;

						// posisi box 1
						{
							box1_G1.posX = 0;
							box1_A1_1.posX = 950;
							box1_A1_2.posX = 800;
							box1_A1_3.posX = 220;
							box1_A1_4.posX = 0;
							box1_A1_5.posX = 0;
							box1_A2_1.posX = 820;
							box1_A2_2.posX = 975;
							box1_A2_3.posX = 1710;
							box1_A2_4.posX = 1840;
							box1_A3_1.posX = 0;

							box1_B1_1.posX = 950;
							box1_B1_2.posX = 800;
							box1_B1_3.posX = 0;
							box1_B2_1.posX = 820;
							box1_B2_2.posX = 975;
							box1_B2_3.posX = 1710;
							box1_B2_4.posX = 1840;
							box1_B2_5.posX = 0;
							box1_B3_1.posX = 0;
						}
					}
					else if (jmlhcoin == 3)
					{
						portal.posX = 1550;
						portal.posY = 150;
					}
				}

				// Level 2
				if (level == 2)
				{

					// box2_G1
					{
						if (isNabrakKiri(dino, box2_G1))
						{
							dino.posX = box2_G1.posX - dino.width;
						}
						if (isNabrakKanan(dino, box2_G1))
						{
							dino.posX = box2_G1.posX + box2_G1.width;
						}
						if (isNabrakAtas(dino, box2_G1))
						{
							dino.velY = 0;
							dino.posY = box2_G1.posY + box2_G1.height + 10;
							dino.lompat = false;
						}
					}

					// box2_1
					{
						// box2_A1_1
						{
							if (isNabrakKiri(dino, box2_A1_1))
							{
								dino.posX = box2_A1_1.posX - dino.width;
							}
							if (isNabrakKanan(dino, box2_A1_1))
							{
								dino.posX = box2_A1_1.posX + box2_A1_1.width;
							}
							if (isNabrakAtas(dino, box2_A1_1))
							{
								dino.velY = 0;
								dino.posY = box2_A1_1.posY + box2_A1_1.height + 10;
								dino.lompat = false;
							}
						}
						// box2_B1_1
						{
							if (isJedot(dino, box2_B1_1))
							{
								dino.velY = 0;
								dino.posY = box2_B1_1.posY - dino.height;
							}
						}
					}

					// box2_2
					{
						// A
						{
							// box2_A2_1
							{
								if (isNabrakKiri(dino, box2_A2_1))
								{
									dino.posX = box2_A2_1.posX - dino.width;
								}
								if (isNabrakKanan(dino, box2_A2_1))
								{
									dino.posX = box2_A2_1.posX + box2_A2_1.width;
								}
								if (isNabrakAtas(dino, box2_A2_1))
								{
									dino.velY = 0;
									dino.posY = box2_A2_1.posY + box2_A2_1.height + 10;
									dino.lompat = false;
								}
							}
							// box2_A2_2
							{
								if (isNabrakKiri(dino, box2_A2_2))
								{
									dino.posX = box2_A2_2.posX - dino.width;
								}
								if (isNabrakKanan(dino, box2_A2_2))
								{
									dino.posX = box2_A2_2.posX + box2_A2_2.width;
								}
								if (isNabrakAtas(dino, box2_A2_2))
								{
									dino.velY = 0;
									dino.posY = box2_A2_2.posY + box2_A2_2.height + 10;
									dino.lompat = false;
								}
							}
							// box_A2_3
							{
								if (isNabrakKiri(dino, box2_A2_3))
								{
									dino.posX = box2_A2_3.posX - dino.width;
								}
								if (isNabrakKanan(dino, box2_A2_3))
								{
									dino.posX = box2_A2_3.posX + box2_A2_3.width;
								}
								if (isNabrakAtas(dino, box2_A2_3))
								{
									dino.velY = 0;
									dino.posY = box2_A2_3.posY + box2_A2_3.height + 10;
									dino.lompat = false;
								}
							}
						}
						// B
						{
							// box2_B2_1
							{
								if (isJedot(dino, box2_B2_1))
								{
									dino.velY = 0;
									dino.posY = box2_B2_1.posY - dino.height;
								}
							}
							// box2_B2_2
							{
								if (isJedot(dino, box2_B2_2))
								{
									dino.velY = 0;
									dino.posY = box2_B2_2.posY - dino.height;
								}
							}
							// box2_B2_3
							{
								if (isJedot(dino, box2_B2_3))
								{
									dino.velY = 0;
									dino.posY = box2_B2_3.posY - dino.height;
								}
							}
						}
					}

					// box2_3
					{
						// A
						{
							// box2_A3_1
							{
								if (isNabrakKiri(dino, box2_A3_1))
								{
									dino.posX = box2_A3_1.posX - dino.width;
								}
								if (isNabrakKanan(dino, box2_A3_1))
								{
									dino.posX = box2_A3_1.posX + box2_A3_1.width;
								}
								if (isNabrakAtas(dino, box2_A3_1))
								{
									dino.velY = 0;
									dino.posY = box2_A3_1.posY + box2_A3_1.height + 10;
									dino.lompat = false;
								}
							}
							// box2_A3_2
							{
								if (isNabrakKiri(dino, box2_A3_2))
								{
									dino.posX = box2_A3_2.posX - dino.width;
								}
								if (isNabrakKanan(dino, box2_A3_2))
								{
									dino.posX = box2_A3_2.posX + box2_A3_2.width;
								}
								if (isNabrakAtas(dino, box2_A3_2))
								{
									dino.velY = 0;
									dino.posY = box2_A3_2.posY + box2_A3_2.height + 10;
									dino.lompat = false;
								}
							}
							// box2_A3_3
							{
								if (isNabrakKiri(dino, box2_A3_3))
								{
									dino.posX = box2_A3_3.posX - dino.width;
								}
								if (isNabrakKanan(dino, box2_A3_3))
								{
									dino.posX = box2_A3_3.posX + box2_A3_3.width;
								}
								if (isNabrakAtas(dino, box2_A3_3))
								{
									dino.velY = 0;
									dino.posY = box2_A3_3.posY + box2_A3_3.height + 10;
									dino.lompat = false;
								}
							}
						}
						// B
						{
							// box2_B3_1
							{
								if (isJedot(dino, box2_B3_1))
								{
									dino.velY = 0;
									dino.posY = box2_B3_1.posY - dino.height;
								}
							}
							// box2_B3_2
							{
								if (isJedot(dino, box2_B3_2))
								{
									dino.velY = 0;
									dino.posY = box2_B3_2.posY - dino.height;
								}
							}
						}

					}

					if (jmlhcoin == 0)
					{
						// posisi coin
						coin1.posX = 300;
						coin1.posY = 350;
						coin2.posX = 1100;
						coin2.posY = 600;
						coin3.posX = 400;
						coin3.posY = 800;

						// reset platform 1
						plt1_1.posY = 5000;
						plt1_2.posY = 5000;
						plt1_3.posY = 5000;
						bg1.posY = 5000;
						ground1.posY = 5000;

						// posisi platform 2
						bg2.posX = 960;
						ground2.posX = 960;
						plt2_1.posX = 450;
						plt2_1.posY = 300;
						plt2_2.posX = 1600;
						plt2_2.posY = 550;
						plt2_3.posX = 560;
						plt2_3.posY = 650;

						// reset box
						{
							box1_G1.posX = 3000;
							box1_A1_1.posX = 3000;
							box1_A1_2.posX = 3000;
							box1_A1_3.posX = 3000;
							box1_A1_4.posX = 3000;
							box1_A1_5.posX = 3000;
							box1_A2_1.posX = 3000;
							box1_A2_2.posX = 3000;
							box1_A2_3.posX = 3000;
							box1_A2_4.posX = 3000;
							box1_A3_1.posX = 3000;
							box1_B1_1.posX = 3000;
							box1_B1_2.posX = 3000;
							box1_B1_3.posX = 3000;
							box1_B2_1.posX = 3000;
							box1_B2_2.posX = 3000;
							box1_B2_3.posX = 3000;
							box1_B2_4.posX = 3000;
							box1_B3_1.posX = 3000;
						}

						// posisi box2
						{
							box2_G1.posX = 0;
							box2_A1_1.posX = 0;
							box2_A2_1.posX = 884;
							box2_A2_2.posX = 1030;
							box2_A2_3.posX = 1160;
							box2_A3_1.posX = 0;
							box2_A3_2.posX = 887;
							box2_A3_3.posX = 512;
							box2_A3_4.posX = 0;

							box2_B1_1.posX = 0;
							box2_B2_1.posX = 884;
							box2_B2_2.posX = 1030;
							box2_B2_3.posX = 1160;
							box2_B3_1.posX = 0;
							box2_B3_2.posX = 0;
						}

					}
					else if (jmlhcoin == 3)
					{
						portal.posX = 630;
						portal.posY = 850;
					}
				}

				// Level 3
				if (level == 3)
				{
					// box3_G1
					{
						if (isNabrakKiri(dino, box3_G1))
						{
							dino.posX = box3_G1.posX - dino.width;
						}
						if (isNabrakKanan(dino, box3_G1))
						{
							dino.posX = box3_G1.posX + box3_G1.width;
						}
						if (isNabrakAtas(dino, box3_G1))
						{
							dino.velY = 0;
							dino.posY = box3_G1.posY + box3_G1.height + 10;
							dino.lompat = false;
						}
					}
					// box3_G2
					{
						if (isNabrakKiri(dino, box3_G2))
						{
							dino.posX = box3_G2.posX - dino.width;
						}
						if (isNabrakKanan(dino, box3_G2))
						{
							dino.posX = box3_G2.posX + box3_G2.width;
						}
						if (isNabrakAtas(dino, box3_G2))
						{
							dino.velY = 0;
							dino.posY = box3_G2.posY + box3_G2.height + 10;
							dino.lompat = false;
						}
					}
					// box3_G3
					{
						if (isNabrakKiri(dino, box3_G3))
						{
							dino.posX = box3_G3.posX - dino.width;
						}
						if (isNabrakKanan(dino, box3_G3))
						{
							dino.posX = box3_G3.posX + box3_G3.width;
						}
						if (isNabrakAtas(dino, box3_G3))
						{
							dino.velY = 0;
							dino.posY = box3_G3.posY + box3_G3.height + 10;
							dino.lompat = false;
						}
					}
					// box3_G4
					{
						if (isNabrakKiri(dino, box3_G4))
						{
							dino.posX = box3_G4.posX - dino.width;
						}
						if (isNabrakKanan(dino, box3_G4))
						{
							dino.posX = box3_G4.posX + box3_G4.width;
						}
						if (isNabrakAtas(dino, box3_G4))
						{
							dino.velY = 0;
							dino.posY = box3_G4.posY + box3_G4.height + 10;
							dino.lompat = false;
						}
					}
					// box3_G5
					{
						if (isNabrakKiri(dino, box3_G5))
						{
							dino.posX = box3_G5.posX - dino.width;
						}
						if (isNabrakKanan(dino, box3_G5))
						{
							dino.posX = box3_G5.posX + box3_G5.width;
						}
						if (isNabrakAtas(dino, box3_G5))
						{
							dino.velY = 0;
							dino.posY = box3_G5.posY + box3_G5.height + 10;
							dino.lompat = false;
						}
					}
					// box3_1
					{
						// A
						{
							// box3_A1
							{
								if (isNabrakKiri(dino, box3_A1_1))
								{
									dino.posX = box3_A1_1.posX - dino.width;
								}
								if (isNabrakKanan(dino, box3_A1_1))
								{
									dino.posX = box3_A1_1.posX + box3_A1_1.width;
								}
								if (isNabrakAtas(dino, box3_A1_1))
								{
									dino.velY = 0;
									dino.posY = box3_A1_1.posY + box3_A1_1.height + 10;
									dino.lompat = false;
								}
							}
							// box_A2
							{
								if (isNabrakKiri(dino, box3_A2_1))
								{
									dino.posX = box3_A2_1.posX - dino.width;
								}
								if (isNabrakKanan(dino, box3_A2_1))
								{
									dino.posX = box3_A2_1.posX + box3_A2_1.width;
								}
								if (isNabrakAtas(dino, box3_A2_1))
								{
									dino.velY = 0;
									dino.posY = box3_A2_1.posY + box3_A2_1.height + 10;
									dino.lompat = false;
								}
							}
							// box_A3
							{
								if (isNabrakKiri(dino, box3_A3_1))
								{
									dino.posX = box3_A3_1.posX - dino.width;
								}
								if (isNabrakKanan(dino, box3_A3_1))
								{
									dino.posX = box3_A3_1.posX + box3_A3_1.width;
								}
								if (isNabrakAtas(dino, box3_A3_1))
								{
									dino.velY = 0;
									dino.posY = box3_A3_1.posY + box3_A3_1.height + 10;
									dino.lompat = false;
								}
							}
							// box_A4
							{
								if (isNabrakKiri(dino, box3_A4_1))
								{
									dino.posX = box3_A4_1.posX - dino.width;
								}
								if (isNabrakKanan(dino, box3_A4_1))
								{
									dino.posX = box3_A4_1.posX + box3_A4_1.width;
								}
								if (isNabrakAtas(dino, box3_A4_1))
								{
									dino.velY = 0;
									dino.posY = box3_A4_1.posY + box3_A4_1.height + 10;
									dino.lompat = false;
								}
							}
						}
						// B 
						{
							// box3_B1
							{
								if (isJedot(dino, box3_B1_1))
								{
									dino.velY = 0;
									dino.posY = box3_B1_1.posY - dino.height;
								}
							}
							// box3_B2
							{
								if (isJedot(dino, box3_B2_1))
								{
									dino.velY = 0;
									dino.posY = box3_B2_1.posY - dino.height;
								}
							}
							// box3_B3
							{
								if (isJedot(dino, box3_B3_1))
								{
									dino.velY = 0;
									dino.posY = box3_B3_1.posY - dino.height;
								}
							}
							// box3_B4
							{
								if (isJedot(dino, box3_B4_1))
								{
									dino.velY = 0;
									dino.posY = box3_B4_1.posY - dino.height;
								}
							}
						}
					}
					if (jmlhcoin == 0)
					{
						// posisi coin
						{
							coin1.posX = 1800;
							coin1.posY = 600;
							coin2.posX = 500;
							coin2.posY = 700;
							coin3.posX = 1800;
							coin3.posY = 900;
						}
						

						// reset posisi platform
						{
							plt2_1.posX = 5000;
							plt2_2.posX = 5000;
							plt2_3.posX = 5000;
							bg2.posX = 5000;
							ground2.posX = 5000;
						}
						


						// posisi platform 3
						{
							bg3.posX = 960;
							ground3.posX = 960;
							plt3_1.posX = 870;
							plt3_1.posY = 450;
							plt3_2.posX = 350;
							plt3_2.posY = 630;
							plt3_3.posX = 1700;
							plt3_3.posY = 790;
							plt3_4.posX = 960;
							plt3_4.posY = 790;
						}
						

						// reset box
						{
							box2_G1.posX = 3000;
							box2_A1_1.posX = 3000;
							box2_A2_1.posX = 3000;
							box2_A2_2.posX = 3000;
							box2_A2_3.posX = 3000;
							box2_A3_1.posX = 3000;
							box2_A3_2.posX = 3000;
							box2_A3_3.posX = 3000;
							box2_A3_4.posX = 3000;
							box2_B1_1.posX = 3000;
							box2_B2_1.posX = 3000;
							box2_B2_2.posX = 3000;
							box2_B2_3.posX = 3000;
							box2_B3_1.posX = 3000;
							box2_B3_2.posX = 3000;
						}

						// posisi box3
						{
							box3_G1.posX = 0;
							box3_G2.posX = 470;
							box3_G3.posX = 890;
							box3_G4.posX = 1120;
							box3_G5.posX = 1385;
							box3_A1_1.posX = 493;
							box3_A2_1.posX = 40;
							box3_A3_1.posX = 1388;
							box3_A4_1.posX = 760;
							box3_B1_1.posX = 493;
							box3_B2_1.posX = 40;
							box3_B3_1.posX = 1388;
							box3_B4_1.posX = 760;
						}
					}
					else if (jmlhcoin == 3)
					{
						portal.posX = 800;
						portal.posY = 300;
					}
				}

				// Level 4
				if (level == 4)
				{
					// box4_G1
					{
						if (isNabrakKiri(dino, box4_G1))
						{
							dino.posX = box4_G1.posX - dino.width;
						}
						if (isNabrakKanan(dino, box4_G1))
						{
							dino.posX = box4_G1.posX + box4_G1.width;
						}
						if (isNabrakAtas(dino, box4_G1))
						{
							dino.velY = 0;
							dino.posY = box4_G1.posY + box4_G1.height + 10;
							dino.lompat = false;
						}
					}
					// box4_G2
					{
						if (isNabrakKiri(dino, box4_G2))
						{
							dino.posX = box4_G2.posX - dino.width;
						}
						if (isNabrakKanan(dino, box4_G2))
						{
							dino.posX = box4_G2.posX + box4_G2.width;
						}
						if (isNabrakAtas(dino, box4_G2))
						{
							dino.velY = 0;
							dino.posY = box4_G2.posY + box4_G2.height + 10;
							dino.lompat = false;
						}
					}
					// box4_G3
					{
						if (isNabrakKiri(dino, box4_G3))
						{
							dino.posX = box4_G3.posX - dino.width;
						}
						if (isNabrakKanan(dino, box4_G3))
						{
							dino.posX = box4_G3.posX + box4_G3.width;
						}
						if (isNabrakAtas(dino, box4_G3))
						{
							dino.velY = 0;
							dino.posY = box4_G3.posY + box4_G3.height + 10;
							dino.lompat = false;
						}
					}
					// box4_G4
					{
						if (isNabrakKiri(dino, box4_G4))
						{
							dino.posX = box4_G4.posX - dino.width;
						}
						if (isNabrakKanan(dino, box4_G4))
						{
							dino.posX = box4_G4.posX + box4_G4.width;
						}
						if (isNabrakAtas(dino, box4_G4))
						{
							dino.velY = 0;
							dino.posY = box4_G4.posY + box4_G4.height + 10;
							dino.lompat = false;
						}
					}
					// box4_1
					{
						// A
						{
							if (isNabrakKiri(dino, box4_A1_1))
							{
								dino.posX = box4_A1_1.posX - dino.width;
							}
							if (isNabrakKanan(dino, box4_A1_1))
							{
								dino.posX = box4_A1_1.posX + box4_A1_1.width;
							}
							if (isNabrakAtas(dino, box4_A1_1))
							{
								dino.velY = 0;
								dino.posY = box4_A1_1.posY + box4_A1_1.height + 10;
								dino.lompat = false;
							}
						}
						// B
						{
							if (isJedot(dino, box4_B1_1))
							{
								dino.velY = 0;
								dino.posY = box4_B1_1.posY - dino.height;
							}
						}
					}
					// box4_2
					{
						// A
						{
							// A2_1
							{
								if (isNabrakKiri(dino, box4_A2_1))
								{
									dino.posX = box4_A2_1.posX - dino.width;
								}
								if (isNabrakKanan(dino, box4_A2_1))
								{
									dino.posX = box4_A2_1.posX + box4_A2_1.width;
								}
								if (isNabrakAtas(dino, box4_A2_1))
								{
									dino.velY = 0;
									dino.posY = box4_A2_1.posY + box4_A2_1.height + 10;
									dino.lompat = false;
								}
							}
							// A2_2
							{
								if (isNabrakKiri(dino, box4_A2_2))
								{
									dino.posX = box4_A2_2.posX - dino.width;
								}
								if (isNabrakKanan(dino, box4_A2_2))
								{
									dino.posX = box4_A2_2.posX + box4_A2_2.width;
								}
								if (isNabrakAtas(dino, box4_A2_2))
								{
									dino.velY = 0;
									dino.posY = box4_A2_2.posY + box4_A2_2.height + 10;
									dino.lompat = false;
								}
							}
						}
						// B
						{
							// B2_1
							{
								if (isJedot(dino, box4_B2_1))
								{
									dino.velY = 0;
									dino.posY = box4_B2_1.posY - dino.height;
								}
							}
							// B2_2
							{
								if (isJedot(dino, box4_B2_2))
								{
									dino.velY = 0;
									dino.posY = box4_B2_2.posY - dino.height;
								}
							}
						}
						{
							if (isJedot(dino, box4_B1_1))
							{
								dino.velY = 0;
								dino.posY = box4_B1_1.posY - dino.height;
							}
						}
					}
					// box4_3
					{
						// A
						{
							if (isNabrakKiri(dino, box4_A3_1))
							{
								dino.posX = box4_A3_1.posX - dino.width;
							}
							if (isNabrakKanan(dino, box4_A3_1))
							{
								dino.posX = box4_A3_1.posX + box4_A3_1.width;
							}
							if (isNabrakAtas(dino, box4_A3_1))
							{
								dino.velY = 0;
								dino.posY = box4_A3_1.posY + box4_A3_1.height + 10;
								dino.lompat = false;
							}
						}
						// B
						{
							if (isJedot(dino, box4_B3_1))
							{
								dino.velY = 0;
								dino.posY = box4_B3_1.posY - dino.height;
							}
						}
					}
					// box4_4
					{
						// A
						{
							if (isNabrakKiri(dino, box4_A4_1))
							{
								dino.posX = box4_A4_1.posX - dino.width;
							}
							if (isNabrakKanan(dino, box4_A4_1))
							{
								dino.posX = box4_A4_1.posX + box4_A4_1.width;
							}
							if (isNabrakAtas(dino, box4_A4_1))
							{
								dino.velY = 0;
								dino.posY = box4_A4_1.posY + box4_A4_1.height + 10;
								dino.lompat = false;
							}
						}
						// B
						{
							if (isJedot(dino, box4_B4_1))
							{
								dino.velY = 0;
								dino.posY = box4_B4_1.posY - dino.height;
							}
						}
					}
					// box4_5
					{
						// A
						{
							if (isNabrakKiri(dino, box4_A5_1))
							{
								dino.posX = box4_A5_1.posX - dino.width;
							}
							if (isNabrakKanan(dino, box4_A5_1))
							{
								dino.posX = box4_A5_1.posX + box4_A5_1.width;
							}
							if (isNabrakAtas(dino, box4_A5_1))
							{
								dino.velY = 0;
								dino.posY = box4_A5_1.posY + box4_A5_1.height + 10;
								dino.lompat = false;
							}
						}
						// B
						{
							if (isJedot(dino, box4_B5_1))
							{
								dino.velY = 0;
								dino.posY = box4_B5_1.posY - dino.height;
							}
						}
					}
					// box4_6
					{
						// A
						{
							// A6_1
							{
								if (isNabrakKiri(dino, box4_A6_1))
								{
									dino.posX = box4_A6_1.posX - dino.width;
								}
								if (isNabrakKanan(dino, box4_A6_1))
								{
									dino.posX = box4_A6_1.posX + box4_A6_1.width;
								}
								if (isNabrakAtas(dino, box4_A6_1))
								{
									dino.velY = 0;
									dino.posY = box4_A6_1.posY + box4_A6_1.height + 10;
									dino.lompat = false;
								}
							}
							// A6_2
							{
								if (isNabrakKiri(dino, box4_A6_2))
								{
									dino.posX = box4_A6_2.posX - dino.width;
								}
								if (isNabrakKanan(dino, box4_A6_2))
								{
									dino.posX = box4_A6_2.posX + box4_A6_2.width;
								}
								if (isNabrakAtas(dino, box4_A6_2))
								{
									dino.velY = 0;
									dino.posY = box4_A6_2.posY + box4_A6_2.height + 10;
									dino.lompat = false;
								}
							}
						}
						// B
						{
							// B6_1
							{
								if (isJedot(dino, box4_B6_1))
								{
									dino.velY = 0;
									dino.posY = box4_B6_1.posY - dino.height;
								}
							}
							// B6_2
							{
								if (isJedot(dino, box4_B6_2))
								{
									dino.velY = 0;
									dino.posY = box4_B6_2.posY - dino.height;
								}
							}
						}
					}
					if (jmlhcoin == 0)
					{
						// posisi coin
						{
							coin1.posX = 1800;
							coin1.posY = 420;
							coin2.posX = 950;
							coin2.posY = 850;
							coin3.posX = 200;
							coin3.posY = 800;
						}
						

						// reset platform
						{
							ground3.posX = 3000;
							plt3_1.posX = 3000;
							plt3_2.posX = 3000;
							plt3_3.posX = 3000;
							plt3_4.posX = 3000;
							bg3.posX = 3000;
						}
						

						// reset box
						{
							box3_G1.posX = 3000;
							box3_G2.posX = 3000;
							box3_G3.posX = 3000;
							box3_G4.posX = 3000;
							box3_G5.posX = 3000;
							box3_A1_1.posX = 3000;
							box3_A2_1.posX = 3000;
							box3_A3_1.posX = 3000;
							box3_A4_1.posX = 3000;
							box3_A3_1.posX = 3000;
							box3_B1_1.posX = 3000;
							box3_B2_1.posX = 3000;
							box3_B3_1.posX = 3000;
							box3_B4_1.posX = 3000;
						}

						// posisi platform 4
						{
							bg4.posX = 960;
							ground4.posX = 960;
							plt4_1.posX = 226;
							plt4_2.posX = 560;
							plt4_3.posX = 1265;
							plt4_4.posX = 1880;
							plt4_5.posX = 1700;
							plt4_6.posX = 1100;
						}
						
						// posisi box
						{
							box4_G1.posX = 0;
							box4_G2.posX = 600;
							box4_G3.posX = 1190;
							box4_G4.posX = 1500;
							box4_A1_1.posX = 0;
							box4_A2_1.posX = 455;
							box4_A2_2.posX = 0;
							box4_A3_1.posX = 1027;
							box4_A4_1.posX = 1560;
							box4_A5_1.posX = 1400;
							box4_A6_1.posX = 500;
							box4_A6_2.posX = 807;


							box4_B1_1.posX = 0;
							box4_B2_1.posX = 455;
							box4_B2_2.posX = 0;
							box4_B3_1.posX = 1027;
							box4_B4_1.posX = 1560;
							box4_B5_1.posX = 1400;
							box4_B6_1.posX = 500;
							box4_B6_2.posX = 807;
						}
					}
					else if (jmlhcoin == 3)
					{
						portal.posX = 960;
						portal.posY = 250;
					}
				}


			}

			// - Enemy

			// Cek apakah ada collision dengan dino
			{
				if (isCollision(dino, musuh))
				{
					gameOver = true;
					slSoundPlay(snddeath);
				}
			}

			// - Coin

			// Cek apakah collision dengan dino
			{
				if (isCollision(dino, coin1))
				{
					coin1.posX = 2000;
					jmlhcoin++;
					slSoundPlay(sndcoin);
				}
				if (isCollision(dino, coin2))
				{
					coin2.posX = 2000;
					jmlhcoin++;
					slSoundPlay(sndcoin);
				}
				if (isCollision(dino, coin3))
				{
					coin3.posX = 2000;
					jmlhcoin++;
					slSoundPlay(sndcoin);
				}
			}
		}
		else if (!gameOver && level == 5)
		{
			slSoundPlay(sndtamat);
			}
		else
		{
			slSetForeColor(1, 1, 1, 1);
			slSetTextAlign(SL_ALIGN_CENTER);
			slText(400, 200, "Game Over");
			slText(400, 150, "Push Spacebar Continue");

			// Restart level jika game over
			if (slGetKey(' '))
			{
				gameOver = false;
				dino.posX = 300;
				dino.posY = 300;
				jmlhcoin = 0;

				coin1.posX = coin1.posX;
				coin2.posX = coin2.posX;
				coin3.posX = coin3.posX;
				portal.posX = 2000;

			}

		}

		// Text
		{
			slSetForeColor(1, 1, 1, 1);
			slSetTextAlign(SL_ALIGN_CENTER);
			slText(960, 900, "Kumpulkan 3 coin !");

			slSetTextAlign(SL_ALIGN_LEFT);
			slText(20, 1020, "Coin :");
			slText(210, 1020, to_string(jmlhcoin).c_str());
		}

		// Animasi
		{
			// Dino
			// Jalan
			if (isMoving && !gameOver)
			{

				if (slGetKey('D'))
				{
					//dino.posX += 3;
					dino.velX = 3;
					dino.posX += dino.velX;
				}

				if (slGetKey('A'))
				{
					dino.velX = -3;
					dino.posX += dino.velX;
				}


				// Cek apakah dino menghadap kiri atau kanan
				const vector<int>& movingPlayerTexture = (slGetKey('D')) ? movingKiri : movingKanan;

				slSprite(movingPlayerTexture[currentMovingFrame], dino.posX, dino.posY + dino.height, 60, 60);

				// Update frame animasi dengan delay
				movingAnimationDelay -= slGetDeltaTime();
				if (movingAnimationDelay <= 0)
				{
					currentMovingFrame = (currentMovingFrame + 1) % movingPlayerTexture.size();
					movingAnimationDelay = 0.1;
				}
			}
			// Diam
			else
			{
				// Player Idle

				// Cek apakah dino menghadap kiri atau kanan
				const vector<int>& idlePlayerTexture = (slGetKey('D')) ? idleKiri : idleKanan;

				slSprite(idlePlayerTexture[currentIdleFrame], dino.posX, dino.posY + dino.height, 60, 60);

				// Update frame animasi dengan delay
				idleAnimationDelay -= slGetDeltaTime();
				if (idleAnimationDelay <= 0)
				{
					currentIdleFrame = (currentIdleFrame + 1) % idlePlayerTexture.size();
					idleAnimationDelay = 0.1;
				}
			}

			// Portal
			if (portal.posX <= 1920)
			{
				const vector<int>& portalTexture = idlePortal;

				slSprite(portalTexture[currentIdlePortal], portal.posX, portal.posY, 81, 85);

				// Update frame animasi dengan delay
				portalAnimationDelay -= slGetDeltaTime();
				if (portalAnimationDelay <= 0)
				{
					currentIdlePortal = (currentIdlePortal + 1) % portalTexture.size();
					portalAnimationDelay = 0.03;
				}
			}

			// Coin
			if (jmlhcoin <= 3)
			{
				const vector<int>& coinTexture = idleCoin;

				slSprite(coinTexture[currentIdleCoin], coin1.posX, coin1.posY, 32, 32);
				slSprite(coinTexture[currentIdleCoin], coin2.posX, coin2.posY, 32, 32);
				slSprite(coinTexture[currentIdleCoin], coin3.posX, coin3.posY, 32, 32);

				// Update frame animasi dengan delay
				coinAnimationDelay -= slGetDeltaTime();
				if (coinAnimationDelay <= 0)
				{
					currentIdleCoin = (currentIdleCoin + 1) % coinTexture.size();
					coinAnimationDelay = 0.1;
				}
			}
		}
		

		slRender();
	}
	slClose();

	return 0;
}

bool isCollision(Dino d, Enemy e)
{
	double dx = d.posX - e.posX;
	double dy = d.posY - e.posY;
	double distance = sqrt(pow(dx, 2.0) + pow(dy, 2.0));
	if (distance <= d.radius + e.radius)
		return true;

	return false;
}

bool isCollision(Dino d, Coin c)
{
	double dx = d.posX - c.posX;
	double dy = d.posY - c.posY;
	double distance = sqrt(pow(dx, 2.0) + pow(dy, 2.0));
	if (distance <= d.radius + c.radius)
		return true;

	return false;
}

bool isCollision(Dino d, Portal p)
{
	double dx = d.posX - p.posX;
	double dy = d.posY - p.posY;
	double distance = sqrt(pow(dx, 2.0) + pow(dy, 2.0));
	if (distance <= d.radius + p.radius)
		return true;

	return false;
}

bool isNapak(Dino d, Platform p)
{
	if ((p.posX - p.kiri) < d.posX && d.posX < (p.posX + p.kanan))
	{
		if (d.posY < p.posY + p.atas && d.posY > p.posY + (p.atas - 10))
			return true;
	}

	return false;
}

bool isJedot(Dino d, Platform p)
{
	if (p.posX - p.kiri < d.posX && d.posX < p.posX + p.kanan)
		if (d.posY < p.posY + p.height && d.posY + d.height > p.posY)
			return true;

	return false;
}

bool isNabrakKiri(Dino d, Box b)
{
	if (d.posX < b.posX + b.width && d.posX + d.width > b.posX && d.posY < b.posY + b.height && d.posY + d.height > b.posY)
		if (d.posX < b.posX + (b.width/2))
			return true;
	return false;
}

bool isNabrakKanan(Dino d, Box b)
{
	if (d.posX < b.posX + b.width && d.posX + d.width > b.posX && d.posY < b.posY + b.height && d.posY + d.height > b.posY)
		if (d.posX > b.posX + (b.width/2))
			return true;
	return false;
}

bool isNabrakAtas(Dino d, Box b)
{
	if (d.posX < b.posX + b.width && d.posX + d.width > b.posX && d.posY >= b.posY + b.height && d.posY + d.height > b.posY)
		if (d.velY < 0 && d.posY < b.posY + b.height + 10)
			return true;
	return false;
}

bool isJedot(Dino d, Box b)
{
	if (d.posX < b.posX + b.width && d.posX + d.width > b.posX && d.posY < b.posY + b.height && d.posY + d.height > b.posY)
		return true;
	return false;
}
