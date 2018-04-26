#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <math.h>

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int background_SIZE = 32;

int main(int argc, char **argv) {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *background = NULL;
	ALLEGRO_BITMAP *background2 = NULL;
	ALLEGRO_BITMAP *background3 = NULL;

	al_init_image_addon();
	//these get rewritten by a and b
	float background_x = 320;
	float background_y = 240;
	float background2_x = 400;
	float background2_y = 300;
	float background3_x = 100;
	float background3_y = 100;
	/*float background_dx = -4.0, background_dy = 4.0;
	float background2_dx = -4.0, background2_dy = 4.0;
	float background3_dx = -4.0, background3_dy = 4.0;*/
	bool redraw = true;
	int a = 200;
	int b = 200;
	int angle = 20;
	int radius = 20;
	int delay = 0;
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
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

	background = al_load_bitmap("n.png");
	background2 = al_load_bitmap("u.png");
	background3 = al_load_bitmap("m.png");
	if (!background && !background2 && !background3) {
		fprintf(stderr, "failed to create background bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}



	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(background);
		al_destroy_bitmap(background2);
		al_destroy_bitmap(background3);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));


	al_flip_display();

	al_start_timer(timer);

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			background_x =  + cos(angle)*radius;
			background_y = b + sin(angle)*radius;
			background2_x = a + 60 + cos(angle)*radius;
			background2_y = b  + sin(angle)*radius;
			background3_x = a + 300 + cos(angle)*radius;
			background3_y = b + sin(angle)*radius;
			if (delay % 5 == 0)
				angle++;
			delay++;

			

			/*background_x += background_dx;
			background_y += background_dy;
			background2_x += background2_dx;
			background2_y += background2_dy;
			background3_x += background3_dx;
			background3_y += background3_dy;*/

			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_draw_bitmap(background, background_x, background_y, 0);
			al_draw_bitmap(background2, background2_x, background2_y, 0);
			al_draw_bitmap(background3, background3_x, background3_y, 0);

			al_flip_display();
		}
	}

	al_destroy_bitmap(background);
	al_destroy_bitmap(background2);
	al_destroy_bitmap(background3);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}