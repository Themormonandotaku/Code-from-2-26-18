#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include<iostream>
using namespace std;

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;

int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	bool redraw = true;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	al_init_primitives_addon();
	if (!al_install_mouse()) {
		fprintf(stderr, "failed to initialize the mouse!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
	if (!bouncer) {
		fprintf(stderr, "failed to create bouncer bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(bouncer);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {

			/*bouncer_x = ev.mouse.x;
			bouncer_y = ev.mouse.y;*/
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {

		}

	
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (ev.mouse.x  < 320 && ev.mouse.y < 240)
				al_draw_filled_rectangle(0, 0, 320, 240, al_map_rgb(rand()% 225, rand() % 225, rand() % 225));

			if (ev.mouse.x  > 333 && ev.mouse.y < 333)
				al_draw_filled_rectangle(320, 0, 640, 240, al_map_rgb(rand() % 225, rand() % 125, rand() % 125));

			if (ev.mouse.x  < 333 && ev.mouse.y > 333)
				al_draw_filled_rectangle(0, 240, 320, 480, al_map_rgb(rand() % 125, rand() % 225, rand() % 125));

			if (ev.mouse.x  > 333 && ev.mouse.y > 333)
				al_draw_filled_rectangle(320, 240, 640, 480, al_map_rgb(rand() % 125, rand() % 25, rand() % 225));

		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

		
			/*al_draw_filled_rectangle(0, 0, 320, 240, al_map_rgb(120, 20, 20));
			al_draw_filled_rectangle(320, 0, 640, 240, al_map_rgb(20, 20, 180));
			al_draw_filled_rectangle(0, 240, 320, 480, al_map_rgb(40, 140, 40));
			al_draw_filled_rectangle(320, 240, 640, 480, al_map_rgb(50, 150, 150));*/
			al_flip_display();
		}
	}


	return 0;
}