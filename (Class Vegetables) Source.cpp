#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
using namespace std;
class vegetable {
public:
	void init(int x, int y);
	void draw(ALLEGRO_BITMAP *image);
	
private:
	int xpos;
	int ypos;
};

int main() {
	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	ALLEGRO_BITMAP *image = NULL;
	ALLEGRO_BITMAP *image2 = NULL;
	ALLEGRO_BITMAP *image3 = NULL;
	ALLEGRO_DISPLAY * display = al_create_display(1200, 1200);

	vegetable potato;
	vegetable radish;
	vegetable carrot;


	
	cout << "flag1" << endl;
	image = al_load_bitmap("bunny.jpg");
	image2 = al_load_bitmap("dog.jpg");
	image3 = al_load_bitmap("cat.jpg");
	if (image == NULL)cout << "image is null!" << endl;

	while (1) {
		potato.draw(image2);
		radish.draw(image3);
		carrot.draw(image);
		al_flip_display();
	}

	
}
void vegetable::draw(ALLEGRO_BITMAP *image) {

	al_draw_bitmap(image, rand() % 1200, rand() % 1200, 0);
}
