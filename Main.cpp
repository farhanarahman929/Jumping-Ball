#include "iGraphics.h"
#include "iostream"
#include "stdlib.h"
#include "math.h"

int squreRoot(int number);
int screenHeight = 720, screenWidth = 1280;
 
//=============================btn: 

#define START (mx >= 740 && mx <= 899 && my >= 420 && my <= 477)

#define CREDIT (mx >= 740 && mx <= 899 && my >= 211 && my <= 265)

#define INSTRUCTIONS (mx >= 740 && mx <= 899 && my >= 352 && my <= 408)

#define HOWTOPLAY (mx >= 740 && mx <= 899 && my >= 282 && my <= 339)

#define EXIT (mx >= 740 && mx <= 899 && my >= 140 && my <= 198)

char btn[5][100] = {"btn\\start.bmp", "btn\\ins.bmp", "btn\\high.bmp", "btn\\credits.bmp", "btn\\exit.bmp"};
int bt = 0;

//---------------------

enum p{MENU, GAME, CREDITS, Instructions, Howtoplay, Exit};

int page = MENU;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Music
bool musicOn = false;

//Health
int life = 3;
int dxLife = 35;
int life_x1 = screenWidth - 40-40,
	life_y1 = screenHeight - 40;
bool lifeI = true;

int life_x2 = life_x1 - dxLife,
	life_y2 = life_y1;
bool lifeII = true;

int life_x3 = life_x2 - dxLife,
	life_y3 = life_y1;
bool lifeIII = true;

char times = 'X';


//button
int dButton = 30;



int rdx = 200, rdy = 50;
int rectangle_x = (screenWidth - rdx)/2,
    rectangle_y = screenHeight/2+dButton;

int rectangle_x2 = (screenWidth - rdx)/2,
    rectangle_y2 = screenHeight/2-dButton;

int rectangle_x3 = rectangle_x,
    rectangle_y3 = rectangle_y2-(2*dButton);

int startBG_x1 = 0,
	startBG_y1 = 0;

bool startG = true;
int start_x = rectangle_x + 80,
	start_y = rectangle_y + 20;
int start_color[3] = {0, 0, 0};

bool hScore = true;
int hScore_x = rectangle_x2 + 50,
	hScore_y = rectangle_y2 + 20;
int hScore_color[3] = {0, 0, 0};

bool xit = true;
int xit_x = rectangle_x3 + 80,
	xit_y = rectangle_y3 + 20;
int xit_color[3] = {0, 0, 0};

//pause
bool pause_state = false;
int dpp = 250;
int dpy  = 10;
int cp1 = 255, cp2  = 0, cp3 = 0;

int rectangle_px = (screenWidth - rdx)/2+dpp,
    rectangle_py = screenHeight/2+dButton-rdy/2;
bool p1 = true;

int rectangle_px2 = (screenWidth - rdx)/2+dpp,
    rectangle_py2 =  rectangle_py + dpy + rdy;
bool p2 = false;

int rectangle_px3 = (screenWidth - rdx)/2+dpp,
    rectangle_py3 =  rectangle_py-dpy-rdy;
bool p3 = false;

//Scoreboard
int st_score, score = 0;
int score_x = screenWidth/2-5;
int score_y = screenHeight-30;
int sr = 255, sg = 140, sb = 0;

int hisc;
int hisc_x = 10,
	hisc_y = score_y;

int sp1 = 10;
int sp2 = 10; 
int sp3 = 10; 
int sp4 = 10; 
int sp5 = 10; 
int sp6 = 10; 
int sp7 = 10; 
int sp8 = 10; 
int sp9 = 10; 
int sp10 = 10; 
int sp11 = 10; 

char str1[10] = "0";
char * str, * go = "Game Over";

char str3[10];
char * str2;

char str4[10];
char * str5;

bool gameOver = false;
int go_x = -50;
int go_y = -50;

//Bubble color
int c = 0;
int r[6] = {(int) rand()%255, (int) rand()%255, (int) rand()%255, (int) rand()%255, (int) rand()%255,(int) rand()%255},
	g[6] = {(int) rand()%255, (int) rand()%255, (int) rand()%255, (int) rand()%255, (int) rand()%255,(int) rand()%255},
	b[6] = {(int) rand()%255, (int) rand()%255, (int) rand()%255, (int) rand()%255, (int) rand()%255,(int) rand()%255};

// 

//bubble
int bub_r = 40;
int bub_vel = 20,
	bub_vel_x = 2;
int bounceHeight = screenHeight*.8;
int horD = (screenWidth-2*bub_r)/5;

bool stage1 = true, stage2 = true;
bool bounce = false, bounce2 = false;
bool bounceUp = false, bounceUp2 = false;
bool bounceDown = false, bounceDown2 = false;

int bub_x1 = bub_r;
int	bub_y1 = screenHeight + bub_r;
bool bub_state1 = true;

int bub_x2 = bub_x1 + 1*horD;
int	bub_y2 = screenHeight + bub_r;
bool bub_state2 = true;

int bub_x3 = bub_x1 + 2*horD;
int	bub_y3 = screenHeight + bub_r;
bool bub_state3 = true;

int bub_x4 = bub_x1 + 3*horD;
int	bub_y4 = screenHeight + bub_r;
bool bub_state4 = true;

int bub_x5 = bub_x1 + 4*horD;
int	bub_y5 = screenHeight + bub_r;
bool bub_state5 = true;

int bub_x6 = bub_x1 + 5*horD;
int	bub_y6 = screenHeight + bub_r;
bool bub_state6 = true;

//Stage 2
int bub_x7 = bub_x1+ horD/2;
int	bub_y7 = screenHeight + bub_r + bounceHeight;
bool bub_state7 = true;

int bub_x8 = bub_x2 + horD/2;
int	bub_y8 = screenHeight + bub_r+ bounceHeight;
bool bub_state8 = true;

int bub_x9 = bub_x3 + horD/2;
int	bub_y9 = screenHeight + bub_r+ bounceHeight;
bool bub_state9 = true;

int bub_x10 = bub_x4 + horD/2;
int	bub_y10 = screenHeight + bub_r+ bounceHeight;
bool bub_state10 = true;

int bub_x11 = bub_x5 + horD/2;
int	bub_y11 = screenHeight + bub_r+ bounceHeight;
bool bub_state11 = true;

int bub_startx[11] = {bub_x1, bub_x2, bub_x3, bub_x4, bub_x5, bub_x6, bub_x7, bub_x8, bub_x9, bub_x10, bub_x11},
	bub_starty[11] = {bub_y1, bub_y2, bub_y3, bub_y4, bub_y5, bub_y6, bub_y7, bub_y8, bub_y9, bub_y10, bub_y11};

//Character
int char_x = screenWidth/2;
int char_y = 132.5;
bool char_state = true;

int target_x = screenHeight/2;
int target_y = screenWidth/2;

bool blade = false;
int initial = -1;
int blade_x = initial;
int blade_y = initial;
int blade_vel = 50;

int prev_X = char_x;
int prev_Y = char_y;

int vel = 30;

int indexRunLeft = 1;
int indexRunRight = 1;
int indexStance = 0;

char runLeft[7][10] = {"bg2.bmp", "1.bmp", "2.bmp", "3.bmp", "4.bmp", "5.bmp","6.bmp"};
char runRight[7][10] = {"R0.bmp", "R1.bmp", "R2.bmp", "R3.bmp", "R4.bmp", "R5.bmp","R6.bmp"};
char stance[7][10] = {"i.bmp", "ii.bmp", "iii.bmp", "iv.bmp", "v.bmp", "vi.bmp","vii.bmp"};
char element[7][15] = {"aim.bmp"};

bool leftMax = false;
bool rightMax = false;

bool leftRun = false;
bool rightRun = false;

int
	state = 0,
	runningLeft = -1,
	notRunning = 0,
	runningRight = 1;

int i;

//test
bool musicMain = true;
bool q = false;
bool GameOver = false;
bool hscore = true;

//Level
bool hsc = true;
bool lv1 = false,
	 lv2 = false,
	 lv3 = false;


bool lv_c = false,
	 lv1_c = false,
	 lv2_c = false,
	 lv3_c = false;

int lv1_loop = 6,
	lv2_loop = 10,
	lv3_loop = 20;

//Arcade

bool arcadeStart = true;


void Background(){
	iShowBMP(0, 0, "bg4.1.bmp");
}

void startScreen(){
	
	if(page == MENU)
{
	iShowBMP(0, 0, "bg4.bmp");

	for(int i = 0, x = 740, y = 420; i < 5; i++, y -= 70)
	{
		iShowBMP(x, y, btn[i]);

	}

}
if(page == CREDITS)
{
	iShowBMP(0 , 0, "bg35.bmp");
	
}
if(page == Instructions)
{
	iShowBMP(0 , 0, "bg30.bmp");
	
	
}
if(page == Howtoplay)
{
	iShowBMP(0 , 0, "bg36.bmp");
	
	
}
if(page == Exit) //gameplay starts 0623
{
	exit(0);

}
if(page == GAME) //gameplay starts 0623
{
	startG = false;

}
}



void bubbleDraw(bool bub_state, int bub_x, int bub_y, int i){
	if(bub_state)
	{
		iFilledCircle(bub_x, bub_y, bub_r);
		iSetColor(r[i], g[i], b[i]);
	}
}

void stageY1(){
	if(stage1)
	{
	bubbleDraw(bub_state1, bub_x1, bub_y1, 0);
	bubbleDraw(bub_state2, bub_x2, bub_y2, 1);
	bubbleDraw(bub_state3, bub_x3, bub_y3, 2);
	bubbleDraw(bub_state4, bub_x4, bub_y4, 3);
	bubbleDraw(bub_state5, bub_x5, bub_y5, 4);
	bubbleDraw(bub_state6, bub_x6, bub_y6, 5);

	}
}

void charMove(){
	if(char_state)
	{
		if(state==runningLeft)
		iShowBMP2(char_x, char_y, runLeft[indexRunLeft], 0);
		else if(state==runningRight)
		iShowBMP2(char_x, char_y, runRight[indexRunRight], 0);
		else
		iShowBMP2(char_x, char_y, stance[indexStance], 0);
	}
}



void stageY2(){
	if(stage2){
	if(bub_state7)
	{
	iFilledCircle(bub_x7, bub_y7, bub_r);
	iSetColor(r[5], g[5], b[5]);
	}
	if(bub_state8)
	{
	iFilledCircle(bub_x8, bub_y8, bub_r);
	iSetColor(r[4], g[4], b[4]);
	}
	if(bub_state9)
	{
	iFilledCircle(bub_x9, bub_y9, bub_r);
	iSetColor(r[3], g[3], b[3]);
	}
	if(bub_state10)
	{
	iFilledCircle(bub_x10, bub_y10, bub_r);
	iSetColor(r[2], g[2], b[2]);
	}
	if(bub_state11)
	{
	iFilledCircle(bub_x11, bub_x11, bub_r);
	iSetColor(r[1], g[1], b[1]);
	}
}
}

void bounceY(){
	if(!bounce){
		if( bub_y1>(char_y+bub_r)){
		bub_y1 -= bub_vel;
		bub_y2 -= bub_vel;
		bub_y3 -= bub_vel;
		bub_y4 -= bub_vel;
		bub_y5 -= bub_vel;
		bub_y6 -= bub_vel;
		}
		else {
			bounce = true;
			bounceUp = true;
		}
	}
	if(bounceUp)
	{
		bub_y1 += bub_vel;
		bub_y2 += bub_vel;
		bub_y3 += bub_vel;
		bub_y4 += bub_vel;
		bub_y5 += bub_vel;
		bub_y6 += bub_vel;
	}
	if(bounce && bub_y1>=bounceHeight){
			bounceUp = false;
			bounceDown = true;
		}
	if(bounceDown)
	{

		bub_y1 -= bub_vel;
		bub_y2 -= bub_vel;
		bub_y3 -= bub_vel;
		bub_y4 -= bub_vel;
		bub_y5 -= bub_vel;
		bub_y6 -= bub_vel;

		if(bounce && bub_y1<=(char_y+bub_r)){
			bounceUp = true;
			bounceDown = false;
		}
	}
}

void bounceY2(){
	if(stage2){
	if(!bounce2){
		if( bub_y7>(char_y+bub_r)){
		bub_y7 -= bub_vel;
		bub_y8 -= bub_vel;
		bub_y9 -= bub_vel;
		bub_y10 -= bub_vel;
		bub_y11 -= bub_vel;
		}
		else {
			bounce2 = true;
			bounceUp2 = true;
		}
	}
	if(bounceUp2)
	{
		bub_y7 += bub_vel;
		bub_y8 += bub_vel;
		bub_y9 += bub_vel;
		bub_y10 += bub_vel;
		bub_y11 += bub_vel;
	}
	if(bounce2 && bub_y7>=bounceHeight){
			bounceUp2 = false;
			bounceDown2 = true;
		}
	if(bounceDown2)
	{

		bub_y7 -= bub_vel;
		bub_y8 -= bub_vel;
		bub_y9 -= bub_vel;
		bub_y10 -= bub_vel;
		bub_y11 -= bub_vel;

		if(bounce2 && bub_y7<=(char_y+bub_r)){
			bounceUp2 = true;
			bounceDown2 = false;
		}
	}
}
}

void bounceX(){
	if(!bounce){
		return;
	}
	else
	{
		bub_x1 += bub_vel_x;
		bub_x2 += bub_vel_x;
		bub_x3 += bub_vel_x;
		bub_x4 += bub_vel_x;
		bub_x5 += bub_vel_x;
		bub_x6 += bub_vel_x;
		bub_x7 += bub_vel_x;
		bub_x8 += bub_vel_x;
		bub_x9 += bub_vel_x;
		bub_x10 += bub_vel_x;
		bub_x11 += bub_vel_x;
	}
	if(bub_x1>screenWidth)
		bub_x1 = -50;
	if(bub_x2>screenWidth)
		bub_x2 = -50;
	if(bub_x3>screenWidth)
		bub_x3 = -50;
	if(bub_x4>screenWidth)
		bub_x4 = -50;
	if(bub_x5>screenWidth)
		bub_x5 = -50;
	if(bub_x6>screenWidth)
		bub_x6 = -50;
	if(bub_x7>screenWidth)
		bub_x7 = -50;
	if(bub_x8>screenWidth)
		bub_x8 = -50;
	if(bub_x9>screenWidth)
		bub_x9 = -50;
	if(bub_x10>screenWidth)
		bub_x10 = -50;
	if(bub_x11>screenWidth)
		bub_x11 = -50;

	/*else if(bounceDown)
	{

		bub_x1 -= bub_vel_x;
		bub_x2 -= bub_vel_x;
		bub_x3 -= bub_vel_x;
		bub_x4 -= bub_vel_x;
		bub_x5 -= bub_vel_x;
		bub_x6 -= bub_vel_x;

		if(bounce && bub_y1<=(char_y+bub_r)){
			bounceUp = true;
			bounceDown = false;
		}
	}*/
}
void gameO()
{
		if(life>1){
			life--;
			if(lifeIII)
				lifeIII = false;
			else if(lifeII)
				lifeII = false;

			gameOver = false;
			return;
		}
		lifeI = false;
		score_y = screenHeight/2;
		go_x = score_x-18;
		go_y = score_y+30;
		sr = 255, sg = 0, sb = 0;
		stage1 = stage2 = false;
		char_state = false;
		GameOver = true;
		return;
}

bool l1 = true, 
	 l2 = false,
	 l3 = false;

void level1(){
	stageY1();
	bounceY();
}
void level2(){
	//bubble
	stageY1();
	stageY2();
	//Bounce
	bounceY();
	bounceY2();
	//Bounce2
}

void level3(){
	stageY1();
	bounceY();
	stageY2();
	bounceY2();
	bounceX();
}

void levelC(){


	bub_state1 = true;
	bub_state2 = true;
	bub_state3 = true;
	bub_state4 = true;
	bub_state5 = true;
	bub_state6 = true;
	bub_state7 = true;
	bub_state8 = true;
	bub_state9 = true;
	bub_state10 = true;
	bub_state11 = true;

	bub_x1 = bub_startx[0];
	bub_x2 = bub_startx[1];
	bub_x3 = bub_startx[2];
	bub_x4 = bub_startx[3];
	bub_x5 = bub_startx[4];
	bub_x6 = bub_startx[5];

		bub_x7 = bub_startx[6];
		bub_x8 = bub_startx[7];
		bub_x9 = bub_startx[8];
		bub_x10 = bub_startx[9];
		bub_x11 = bub_startx[10];

	bub_y1 = bub_starty[0];
	bub_y2 = bub_starty[1];
	bub_y3 = bub_starty[2];
	bub_y4 = bub_starty[3];
	bub_y5 = bub_starty[4];
	bub_y6 = bub_starty[5];
		bub_y7 = bub_starty[6];
		bub_y8 = bub_starty[7];
		bub_y9 = bub_starty[8];
		bub_y10 = bub_starty[9];
		bub_y11 = bub_starty[10];

	bounce = false;

  bounce = false;
  bounce2 = false;
  bounceUp = false; 
  bounceUp2 = false;
  bounceDown = false; 
  bounceDown2 = false;

}


void pause(){
	 iShowBMP(0, 0, "bg5.bmp");
		iSetColor(0,0,0);
		iRectangle(rectangle_px, rectangle_py, rdx, rdy);
		iSetColor(cp1, 0, 0);
		iText(rectangle_px2+60, rectangle_py2+20, "Resume", GLUT_BITMAP_TIMES_ROMAN_24);
	
		iSetColor(0,0,0);
		iRectangle(rectangle_px2, rectangle_py2, rdx, rdy);
		iSetColor(cp2, 0, 0);
		iText(rectangle_px+20, rectangle_py+20, "Music ON/OFF", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(0,0,0);
		iRectangle(rectangle_px3, rectangle_py3, rdx, rdy);
		iSetColor(cp3, 0, 0);
		iText(rectangle_px3+80, rectangle_py3+20, "Exit", GLUT_BITMAP_TIMES_ROMAN_24);

}
void highscore(int score){
	std::cout << score << "\n";

	int c;
	FILE *fp;
	fp = fopen("Highscore.txt", "w");
	char str[20] = "Hello World!";
	sprintf(str,"%d",score);
	if (fp)
	{
		for(int i=0; i<strlen(str); i++) 
			putc(str[i],fp);
	}
	fclose(fp);

	FILE *fp1;
	fp1 = fopen("Highscore.txt", "r");
	if (fp1)
	{
		while ((c = getc(fp1)) != EOF)
			putchar(c);
		fclose(fp1);
	}
}

void iDraw()
{


	//place your drawing codes here
	iClear();
	
	//Do not suffle Start and Pause
	//Music

	//Start
	if(startG)	startScreen();
	if(startG)	return;


	//Pause
	if(pause_state)	 
	{ 
	pause(); 
	return; 
	}

	//Background
	iShowBMP(0, 0, runLeft[0]);
	sprintf(str1,"Score: %d",score);
	str = str1;
	iSetColor(sr, sg, sb);
	iText(score_x, score_y, str, GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf(str4,"Highscore: %d",(hisc>score)?hisc:score);
	str5 = str4;
	iSetColor(0, 100, 0);
	//hisc_x=10;
	//hisc_y=screenHeight-30;
	iText(hisc_x, hisc_y, str5, GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(sr, sg, sb);
	iText(go_x, go_y, go, GLUT_BITMAP_TIMES_ROMAN_24);
	

	if(GameOver){	
		lifeI = false;
		score_y = screenHeight/2;
		go_x = score_x-18;
		go_y = score_y+30;
		hisc_x = score_x - 22;
		hisc_y = score_y-60;
		sr = 255, sg = 0, sb = 0;
		stage1 = stage2 = false;
		char_state = false;
		if(hsc) { 
			if(score>hisc)
				highscore(score); 
			hsc = false; 
		}
		return;
	}

	if(gameOver){	
		gameO();
	}

	sprintf(str3,"x%d", life);
	str2 = str3;
	iSetColor(255, 0, 0);
	iText(life_x1+40, life_y1+5, str2, GLUT_BITMAP_TIMES_ROMAN_24);
	if(lifeI)
	iShowBMP2(life_x1, life_y1, "lf1.bmp", 0);
	if(lifeII)
	iShowBMP2(life_x2, life_y2, "lf1.bmp", 0);
	if(lifeIII)
	iShowBMP2(life_x3, life_y3, "lf1.bmp", 0);

	//level1();
		//level2();
	level3();



	//Playground Range
	leftMax = (char_x <= screenWidth) ? true : false;
	rightMax = (char_x >= screenWidth) ? true : false;
	//Blade
	if(blade==true) {
		(blade_y <= screenHeight)? (blade_y+=blade_vel) : blade = false;
	}
	iSetColor(0, 0, 0);
	iFilledCircle(blade_x, blade_y, 5, 100);

	charMove();
}



/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	
}

/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	//place your codes here
}


/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
bool color = false;
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		//place your codes here
		if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		//place your codes here
		blade = true;
		blade_x = char_x+25;
		blade_y = char_y+50;
	}
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && START && page == MENU)  //if left mouse click on "START" WHEN you are in MENU page
	{
		//place your codes here
		page = GAME;

	}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && CREDIT && page == MENU)  //if left mouse click on "CREDIT" WHEN you are in MENU page
	{
		//place your codes here
		page = CREDITS;
	}
	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && INSTRUCTIONS && page == MENU)  //if left mouse click on "CREDIT" WHEN you are in MENU page
	{
		//place your codes here
		page = Instructions;
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && Howtoplay&& page == MENU)  //if left mouse click on "CREDIT" WHEN you are in MENU page
	{
		//place your codes here
		page = Howtoplay;
	}
	 if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx>740 && mx<900) && (my>144 && my<197))  //if left mouse click on "CREDIT" WHEN you are in MENU page
	{
			page = Exit;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == ' ')
	{
		//do something with 'x'
		if(start_color[1]>0){
			startG = false;
			xit = false;
		}
		else if(xit_color[1] >0)
			exit(0);

		//pause
		if(p1)
			pause_state = false;
		else if(p2) {
			musicOn = !musicOn;
		}
		else if(p3) {
				p3 = false;
				startG = true;
				pause_state = false;
				page = MENU;
				levelC();
				p1 = true;
				p2 = false;
			gameOver = false;
			GameOver = false;
			lifeI = lifeII = lifeIII = true;
			score_y = screenHeight-30;
			go_x = -50;
			go_y = -50;
			sr = 255, sg = 0, sb = 0;
			stage1 = stage2 = true;
			char_state = true;
			bub_vel = 20;
			bub_vel_x = 2;
			score = 0;
			hisc_y = screenHeight - 30; 
			}


	}
	//place your codes for other keys here
	else if(key == 'p')
	{
		//do something with 'x'
		pause_state = true;
	}
	else if(key == '1')
	{
		//do something with 'x'
		lv1 = true;
		lv2 = lv3 = false;
	}
	else if(key == '2')
	{
		//do something with 'x'
		lv1 = false;
		lv3 = false;
		lv2 = true;
	}
	else if(key == '3')
	{
		//do something with 'x'
		lv1 = false;
		lv3 = false;
		lv3 = true;
	}
	else if(key == 'g')
	{
		//do something with 'x'	
		
		exit(0);
	}
	else if(key == 'b')
	{
		//do something with 'x'
		levelC();
	}
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/


void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		page = MENU;
	}
	if(key == GLUT_KEY_LEFT)
	{
		if(char_x>30) char_x-=vel;
	}
	if(key == GLUT_KEY_RIGHT)
	{
		if(char_x<=(screenWidth-60)) char_x+=vel;
	}
	if(key == GLUT_KEY_UP)
	{
		if(startG){
		start_color[1] = 100; 
		xit_color[1] = 0; 
		}
		if(pause_state){
		if(p1) {
				p3 = true;
				cp3 = 255;
				cp1 = 0;
				
				p1 = false;
			}
			else if(p2) {
				p1 = true;
				cp1 = 255;
				cp2 = 0;
				p2 = false;
			}
			else if(p3) {
				p2 = true;
				cp2 = 255;
				cp3 = 0;
				p3 = false;
			}
		}

	}
	if(key == GLUT_KEY_DOWN)
	{	
		if(startG){
		start_color[1] = 0; 
		xit_color[1] = 100; 
		}
		if(pause_state){
			if(p1) {
				p2 = true;
				cp2 = 255;
				cp1 = 0;
				p1 = false;
			}
			else if(p2) {
				p3 = true;
				cp3 = 255;
				cp2 = 0;
				p2 = false;

			}
			else if(p3) {
				p1 = true;
				cp1 = 255;
				cp3 = 0;
				p3 = false;
			}
		}
	}
	//place your codes for other keys here
}

void activity(){
	if(pause_state)	return; 

	if     (prev_X>char_x)	 {state = runningLeft;	indexRunLeft==6?  indexRunLeft=1  : indexRunLeft++;  
													indexStance  = 1;	}
	else if(prev_X<char_x)   {state = runningRight; indexRunRight==6? indexRunRight=1 : indexRunRight++;
													indexStance  = 1;	}
	else if(prev_X==char_x)	 {state = notRunning;	indexStance  ==4? indexStance=0 : indexStance++;
													indexRunRight = indexRunLeft = 1; }
	prev_X = char_x;
}

//void ccSub1(int * bub_state, int * bub_x, int * bub_y){
//	int i = *bub_state;
//	if(i)
//		if( blade_x<(*bub_x+bub_r) && blade_x>(*bub_x-bub_r) )
//			if( blade_y >= (*bub_y-bub_r) )
//			{
//				*bub_state = false;
//				score++;
//				blade = false;
//				blade_x = blade_y = -1;
//			}
//}


void collisionCheck(){
	if(pause_state)	return; 

	if(bub_state1)
		if( blade_x<(bub_x1+bub_r) && blade_x>(bub_x1-bub_r) )
			if( blade_y >= (bub_y1-bub_r) )
			{
				bub_state1 = false;
				score++;
				blade = false;
				blade_x = blade_y = -1;
			}

	if(bub_state2)
		if( blade_x<(bub_x2+bub_r) && blade_x>(bub_x2-bub_r) )
			if( blade_y >= (bub_y2-bub_r) )
			{
				bub_state2 = false;
				score++;
				blade = false;
				blade_x = blade_y = initial;
			}
	if(bub_state3)
		if( blade_x<(bub_x3+bub_r) && blade_x>(bub_x3-bub_r) )
			if( blade_y >= (bub_y3-bub_r) )
			{
				bub_state3 = false;
				score++;
				blade = false;
				blade_x = blade_y = initial;
			}

	if(bub_state4)
		if( blade_x<(bub_x4+bub_r) && blade_x>(bub_x4-bub_r) )
			if( blade_y >= (bub_y4-bub_r) )
				{
					bub_state4 = false;
					score++;
					blade = false;
					blade_x = blade_y = initial;
				}

	if(bub_state5)
		if( blade_x<(bub_x5+bub_r) && blade_x>(bub_x5-bub_r) )
			if(blade_y >= (bub_y5-bub_r))
				{
					bub_state5 = false;
					score++;
					blade = false;
					blade_x = blade_y = initial;
				}

	if(bub_state6) 
		if( blade_x<(bub_x6+bub_r) && blade_x>(bub_x6-bub_r) )
			if( blade_y >= (bub_y6-bub_r) )
				{
					bub_state6 = false;
					score++;
					blade = false;
					blade_x = blade_y = initial;
				}

if(stage2){	
	if(bub_state7) 
		if( blade_x<(bub_x7+bub_r) && blade_x>(bub_x7-bub_r) )
			if( ((blade_x-bub_x7)*(blade_x-bub_x7) + (blade_x-bub_y7)*(blade_x-bub_y7)) > bub_r*bub_r)
				{
					bub_state7 = false;
					score++;
					blade = false;
					blade_x = blade_y = initial;
				}
	if(bub_state8) 
		if( blade_x<(bub_x8+bub_r) && blade_x>(bub_x8-bub_r) )
			if( ((blade_x-bub_x8)*(blade_x-bub_x8) + (blade_x-bub_y8)*(blade_x-bub_y8)) > bub_r*bub_r)
				{
					bub_state8 = false;
					score++;
					blade = false;
					blade_x = blade_y = initial;
				}
	if(bub_state9) 
		if( blade_x<(bub_x9+bub_r) && blade_x>(bub_x9-bub_r) )
			if( ((blade_x-bub_x9)*(blade_x-bub_x9) + (blade_x-bub_y9)*(blade_x-bub_y9)) > bub_r*bub_r)
				{
					bub_state9 = false;
					score++;
					blade = false;
					blade_x = blade_y = initial;
				}

	if(bub_state10) 
		if( blade_x<(bub_x10+bub_r) && blade_x>(bub_x10-bub_r) )
			if( ((blade_x-bub_x10)*(blade_x-bub_x10) + (blade_x-bub_y10)*(blade_x-bub_y10)) > bub_r*bub_r)
				{
					bub_state10 = false;
					score++;
					blade = false;
					blade_x = blade_y = initial;
				}

	if(bub_state11) 
		if( blade_x<(bub_x11+bub_r) && blade_x>(bub_x11-bub_r) )
			if( ((blade_x-bub_x11)*(blade_x-bub_x11) + (blade_x-bub_y11)*(blade_x-bub_y11)) > bub_r*bub_r)
				{
					bub_state11 = false;
					score++;
					blade = false;
					blade_x = blade_y = initial;
				}
}

	if(((bub_state1 == false && bub_state2 == false && bub_state3 == false && bub_state4 == false && bub_state5 == false && bub_state6 == false)&&
		(bub_state7 == false && bub_state8 == false && bub_state9 == false && bub_state10 == false && bub_state11 == false))||(char_state == false))
	{
		levelC();



		
	}
	/*if((bub_state1 == false  && bub_state3 == false && bub_state5 == false)){
		bub_state1 = true;
		bub_state4 = true;  
		bub_state6 = true;
	}
	
	if((bub_state2 == false  && bub_state4 == false && bub_state6 == false)){
		bub_state2 = true; 
		bub_state4 = true;  
		bub_state6 = true;
	}
	if((bub_state7 == false  && bub_state9 == false && bub_state11 == false)){
		bub_state7 = true; 
		bub_state9 = true;  
	}

	if((bub_state8 == false && bub_state10 == false)){
		bub_state8 = true; 
		bub_state10 = true;  
	}*/

	if(score>st_score){
		if(!stage1) stage1 = true;
		if(!stage2) stage1 = true;
		st_score+=6;
	}
}

void ccSub(bool state, int bub_x, int bub_y){
	if(state)
		if( (char_x+20)<(bub_x+bub_r) && char_x+20>(bub_x-bub_r) )
			if(char_y>=bub_y-bub_r)
			{
				gameOver = true;
			}
}

void collisionCheck2(){

	if(pause_state)	return; 

	ccSub(bub_state1, bub_x1, bub_y1);	
	ccSub(bub_state2, bub_x2, bub_y2);	
	ccSub(bub_state3, bub_x3, bub_y3);	
	ccSub(bub_state4, bub_x4, bub_y4);	
	ccSub(bub_state5, bub_x5, bub_y5);	
	ccSub(bub_state6, bub_x6, bub_y6);	
	ccSub(bub_state7, bub_x7, bub_y7);	
	ccSub(bub_state8, bub_x8, bub_y8);	
	ccSub(bub_state9, bub_x9, bub_y9);	
	ccSub(bub_state10, bub_x10, bub_y10);	
	ccSub(bub_state11, bub_x11, bub_y11);	
}



int dx = (.6*screenHeight+bub_r);
void stageChange(){
	if(pause_state)	return; 

	if(stage2 == false)
		stage2 = true;
}

void bouncexPlus(){
	//bub_vel_x = squreRoot(bub_y1);
	if(pause_state)	return; 
}

int squreRoot(int number)
{
    float temp, sqrt;

    printf("Provide the number: \n");

    scanf("%d", &number);

    // store the half of the given number e.g from 256 => 128
    sqrt = number / 2;
    temp = 0;

    // Iterate until sqrt is different of temp, that is updated on the loop
    while(sqrt != temp){
        // initially 0, is updated with the initial value of 128
        // (on second iteration = 65)
        // and so on
        temp = sqrt;

        // Then, replace values (256 / 128 + 128 ) / 2 = 65
        // (on second iteration 34.46923076923077)
        // and so on
        sqrt = ( number/temp + temp) / 2;
    }

//    printf("The square root of '%d' is '%f'", number, sqrt);
	int n = ((int) sqrt);
	return n;
}
void musico(){
	if(musicOn){
		musicMain = false; 
		PlaySound("music\\HomeMusic.wav",NULL,SND_LOOP | SND_ASYNC);
	}
}

void speedUP(){
	bub_vel += 3;
	bub_vel_x += 3;
}

int read_ints (const char* file_name)
{
  FILE* file = fopen (file_name, "r");
  int i = 0;

  fscanf (file, "%d", &i);    
  return i;

  fclose (file);        
}

int main()
{

	//place your own initialization codes here.
	
	hisc = read_ints("Highscore.txt");
	std::cout<< hisc;

	if(musicMain)
	PlaySound("music\\HomeMusic.wav",NULL,SND_LOOP | SND_ASYNC);
	iSetTimer(10000, speedUP);
	iSetTimer(0, activity);
	iSetTimer(0, musico);
	iSetTimer(0, collisionCheck);
	iSetTimer(0, collisionCheck2);
	iSetTimer(10000, stageChange);
	iSetTimer(1000, bouncexPlus);
	iInitialize(screenWidth, screenHeight,  "PictureDemo");
	iStart();

	return 0;
}


	