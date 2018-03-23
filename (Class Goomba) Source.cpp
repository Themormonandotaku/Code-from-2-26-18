#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
using namespace std;
class goomba {
public:
	int draw(); //you don't need to pass this, it's a variable this time
	void init(int x, int y, ALLEGRO_BITMAP *goombapic, ALLEGRO_BITMAP * deadgoombapic);			  //add an init function here
private:
	ALLEGRO_BITMAP *MinionPic1;
	ALLEGRO_BITMAP *MinionPic2;
	int xpos;
	int ypos;
	bool life;
	

};
class koopa {
public:
	int draw(); //you don't need to pass this, it's a variable this time
	void init(int x, int y, ALLEGRO_BITMAP *kappapic, ALLEGRO_BITMAP *deadkoopapic);			  //add an init function here
private:
	ALLEGRO_BITMAP * KappaPic1;
	ALLEGRO_BITMAP *KappaPic2;
	int xpos;
	int ypos;
	bool life;
	

};
int main() {
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_BITMAP *goombapic = al_load_bitmap("goomba.jpg");
	ALLEGRO_BITMAP *deadgoombapic = al_load_bitmap("deadgoomba.jpg");
	ALLEGRO_BITMAP *koopapic = al_load_bitmap("koopa.jpg");
	ALLEGRO_BITMAP *deadkoopapic = al_load_bitmap("deadkoopa.jpg");
	
	display = al_create_display(100, 100);
	goomba minion1;
	goomba minion2;
	koopa kappa1;
	koopa kappa2;
	minion1.init(20, 20, goombapic, deadgoombapic);
	minion2.init(40, 20, goombapic, deadgoombapic);
	kappa1.init(40, 60, koopapic, deadkoopapic);
	kappa2.init(60, 60, koopapic, deadkoopapic);//instantiate 3-4 goomba objects
	//initialize the objects
	minion1.draw();
	minion2.draw();//draw the objects
	al_flip_display();//flip display
	system("pause");//al pause 

}

int goomba::draw() {
	if (life = true)
		al_draw_bitmap(al_draw_bitmap(goombapic), xpos, ypos, 0); //call the al_draw_bitmap function instead, draw the first bitmap
	else
		al_draw_bitmap(al_draw_bitmap(deadgoombapic), xpos, ypos, 0); //call al_draw_bitmap, draw the second image
}



void goomba::init(int x, int y, ALLEGRO_BITMAP *goombapic, ALLEGRO_BITMAP * deadgoombapic) {
	xpos = x;
	ypos = y;
	MinionPic1 = goombapic;
	MinionPic2 = deadgoombapic;
}

int koopa::draw() {
	if (life = true)
		al_draw_bitmap(al_draw_bitmap(koopapic), xpos, ypos, 0); //call the al_draw_bitmap function instead, draw the first bitmap
	else
		al_draw_bitmap(al_draw_bitmap(deadkoopapic), xpos, ypos, 0); //call al_draw_bitmap, draw the second image
}



void koopa::init(int x, int y, ALLEGRO_BITMAP *koopapic, ALLEGRO_BITMAP *deadkoopapic) {
	xpos = x;
	ypos = y;
	KappaPic1 = koopapic;
	KappaPic2 = deadkoopapic;
}