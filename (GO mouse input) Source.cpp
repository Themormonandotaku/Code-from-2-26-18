#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
class pieces {
public:
	void initpieces(int x, int y, int i, ALLEGRO_BITMAP *picture);
	void drawpieces();
	void PrintInfo();
	bool clicked(int x, int y);
	void liftUp();
	bool isLifted();
	void move(int x, int y);
	void PutDown();
private:
	int xpos;
	int ypos;
	int index;
	bool lifted;
	ALLEGRO_BITMAP *image;
};


int main() {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	bool redraw = true;

	al_init();
	al_init_image_addon();
	al_install_mouse();
	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(SCREEN_W, SCREEN_H);
	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);

	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();


	al_start_timer(timer);
	ALLEGRO_BITMAP *airPic = al_load_bitmap("air.jpg");
	ALLEGRO_BITMAP *waterPic = al_load_bitmap("water.png");
	pieces air;
	pieces water;
	air.initpieces(50, 50, 1, airPic);
	water.initpieces(300, 100, 2, waterPic);

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (air.isLifted()) {
				air.move(bouncer_x, bouncer_y);
			}
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {

			bouncer_x = ev.mouse.x;
			bouncer_y = ev.mouse.y;


		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (air.clicked(bouncer_x, bouncer_y))
				if (air.isLifted() == false)
					air.liftUp();
				else
					air.PutDown();
		}

		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {

		}


		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);

			air.initpieces(1, 2, 3, airpic);
			water.initpieces();
		

			al_flip_display();
		}
	}

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}


void pieces::liftUp() {
	lifted = true;

}

void pieces::PutDown() {
	lifted = false;

}

bool pieces::isLifted() {

	return lifted;
}

void pieces::move(int x, int y) {
	xpos = x - piecesWIDTH / 2;
	ypos = y - piecesWIDTH / 2;


}
void pieces::initpieces(int x, int y, int i, ALLEGRO_BITMAP *picture) {
	xpos = x;
	ypos = y;
	index = i;
	lifted = false;
	image = picture;
}