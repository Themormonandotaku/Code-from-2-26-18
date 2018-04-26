#include <stdio.h>
#include <allegro5/allegro.h>

#include<allegro5\allegro_primitives.h>
#include<math.h>
#include<iostream>
using namespace std;

const float FPS = 300;
const int SCREEN_W = 1280;
const int SCREEN_H = 1000;


int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	ALLEGRO_BITMAP *background = NULL;

	int tjX = 200;
	int tjY = 150;
	double speed = .1;
	int fernyX = 930;
	int fernyY = 70;

	int treX = 500;
	int treY = 90;

	bool redraw = true;
	bool angleIncrease = true;
	bool ColorIncrease = true;

	al_init();

	al_init_primitives_addon();


	int angle = 0;
	int radius = 30;
	int delay = 0;
	int color = 0;




	timer = al_create_timer(1.0 / FPS);

	display = al_create_display(SCREEN_W, SCREEN_H);

	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {

			tjX = (100)*cos(angle * 1/*Mess with this number*/) + (cos(100)*angle*.4/*Mess with this number*/) + 00;
			tjY = (500)*sin(angle * 1/*Mess with this number*/) + (sin(200)*angle*.4/*Mess with this number*/) + 800;


			if (angleIncrease == true)
				angle++;
			else
				angle--;
			if (angle > 360 || angle<0) {
				!angleIncrease;
				//cout << "angle flip" << endl;
			}
			/*delay++;*/
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;


			if (ColorIncrease == true)
				color++;
			else
				color--;

			if (color > 255 || color<0) {
				if (ColorIncrease == false)
					ColorIncrease = true;
				else
					ColorIncrease = false;
				cout << "color is " << color << "colorIncrease is " << ColorIncrease << endl;

			}
			al_draw_filled_circle(tjX, tjY, 2, al_map_rgb(color, 0, 250));


			al_flip_display();
		}
	}


	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}