#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main() {
	al_init();
	al_init_primitives_addon();

	ALLEGRO_DISPLAY *display = al_create_display(640, 500);


	while (1) {
		al_draw_filled_rectangle(rand() % 256, rand() % 256, rand() % 256, rand() % 256, al_map_rgb(rand() % 256, rand() % 256, rand() % 256));
		al_draw_filled_circle(rand() % 256, rand() % 256, rand() % 256, al_map_rgb(rand() % 256, rand() % 256, rand() % 256));
		al_draw_filled_triangle(rand() % 256, rand() % 256, rand() % 256, rand() % 256, rand() % 256, rand() % 256, al_map_rgb(rand() % 256, rand() % 256, rand() % 256));
		al_rest(.02);
		al_flip_display();
	}
}