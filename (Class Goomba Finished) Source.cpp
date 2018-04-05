#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include<ctime>
using namespace std;
//Create class Goomba.
//Each Goomba object has private variables for an image, and x & y position, 
//and a variable holding whether it’s alive or not.Dead Goombas should be drawn to be grey, 
//live Goombas should be brown.Instantiate several Goomba objects and draw them to the screen.


class goomba {
public:
	void draw(); //you don't need to pass this, it's a variable this time
	void init(int x, int y, ALLEGRO_BITMAP *goombapic, ALLEGRO_BITMAP * deadgoombapic, bool d);			  //add an init function here
private:
	ALLEGRO_BITMAP *MinionPic1;
	ALLEGRO_BITMAP *MinionPic2;
	int xpos;
	int ypos;
	bool life;
	

};
class koopa {
public:
	void draw(); //you don't need to pass this, it's a variable this time
	void init(int x, int y, ALLEGRO_BITMAP *kappapic, ALLEGRO_BITMAP *deadkoopapic, bool d);			  //add an init function here
private:
	ALLEGRO_BITMAP * KappaPic1;
	ALLEGRO_BITMAP *KappaPic2;
	int xpos;
	int ypos;
	bool life;
	

};
int main() {
	srand(time(NULL));
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_BITMAP *goombapic = al_load_bitmap("goomba.png");
	ALLEGRO_BITMAP *deadgoombapic = al_load_bitmap("deadgoomba.png");
	ALLEGRO_BITMAP *koopapic = al_load_bitmap("koopa.png");
	ALLEGRO_BITMAP *deadkoopapic = al_load_bitmap("deadkoopa.png");
	
	if (goombapic == NULL)
		cout << "images didn't load!" << endl;

	display = al_create_display(800, 800);
	goomba minion1;
	goomba minion2;
	koopa kappa1;
	koopa kappa2;
	minion1.init(10, 100, goombapic, deadgoombapic, true);
	minion2.init(400, 100, goombapic, deadgoombapic, false);
	kappa1.init(10, 500, koopapic, deadkoopapic, true);
	kappa2.init(400, 500, koopapic, deadkoopapic, false);//instantiate 3-4 goomba objects

	//initialize the objects
	minion1.draw();
	minion2.draw();//draw the objects
	kappa1.draw();
	kappa2.draw();
	al_flip_display();//flip display
	system("pause");//al pause 

}

void goomba::draw() {
	cout << "beginning draw function" << endl;
	if (life == true) {
		al_draw_bitmap(MinionPic1, xpos, ypos, 0);
		cout << "life is true" << endl;
	}
	else
		al_draw_bitmap(MinionPic2, xpos, ypos, 0);
	
}



void goomba::init(int x, int y, ALLEGRO_BITMAP *goombapic, ALLEGRO_BITMAP * deadgoombapic, bool d) {
	xpos = x;
	ypos = y;
	MinionPic1 = goombapic;
	MinionPic2 = deadgoombapic;
	life = d;
}

void koopa::draw() {
	cout << "beginning draw function" << endl;
	if (life == true)
		al_draw_bitmap(KappaPic1, xpos, ypos, 0); //call the al_draw_bitmap function instead, draw the first bitmap
	else
		al_draw_bitmap(KappaPic2, xpos, ypos, 0); //call al_draw_bitmap, draw the second image
	cout << "end draw function";
}



void koopa::init(int x, int y, ALLEGRO_BITMAP *koopapic, ALLEGRO_BITMAP *deadkoopapic, bool d) {
	xpos = x;
	ypos = y;
	KappaPic1 = koopapic;
	KappaPic2 = deadkoopapic;
	life =d;
}