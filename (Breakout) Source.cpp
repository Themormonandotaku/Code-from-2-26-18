//Make sure that the ttf font style is in your files
//Also, the collision on the right side of the paddle is pretty wonky. Still, this game works
#include <stdio.h>
#include <allegro5/allegro.h>
#include<iostream>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include<allegro5/allegro_primitives.h>
#include <windows.h>
using namespace std;
int score;
int counter;
bool collision(int BallX, int BallY, int BallW, int BallH, int PaddleX, int PaddleY, int PaddleW, int PaddleH);
class brick {
public:
	void killbrick();
	void constructor();
	void initbrick(int w, int h, int x, int y, bool d);
	void draw();
	bool isdead();
	bool Collision(int BallX, int BallY, int BallW, int BallH);

private:
	int width;
	int height;
	int xposition;
	int yposition;
	bool dead;

};
bool doexit = false;
int main(int argc, char **argv) {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *rectangle = NULL;


	float bouncer_x = 55;
	float bouncer_y = 360;

	float square_x = 50;
	float square_y = 400;

	bool key[2] = { false, false, };


	float bouncer_dx = -4.0, bouncer_dy = 4.0;
	bool redraw = true;

	al_init();
	al_init_primitives_addon();
	al_install_keyboard(); //need this for input
	al_init_font_addon();
	al_init_ttf_addon();
	//cout << "im dead" << endl;
	ALLEGRO_FONT *font = al_load_ttf_font("Raleway-Black.ttf", 32, 0);

	timer = al_create_timer(.02);

	display = al_create_display(640, 480);

	bouncer = al_create_bitmap(32, 32);


	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 100, 100));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	//this section checks for stuff to put in the event queue

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());



	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	//Make twenty
	brick b1;//instantiating (stamping) the brick
	b1.initbrick(50, 10, 20, 20, 0); //giving the brick a position and stuff
	brick b2;
	b2.initbrick(50, 10, 100, 20, 0);
	brick b3;
	b3.initbrick(50, 10, 180, 20, 0);
	brick b4;
	b4.initbrick(50, 10, 260, 20, 0);
	brick b5;
	b5.initbrick(50, 10, 340, 20, 0);
	brick b6;
	b6.initbrick(50, 10, 420, 20, 0);
	brick b7;
	b7.initbrick(50, 10, 500, 20, 0);
	brick b8;
	b8.initbrick(50, 10, 580, 20, 0);
	brick b9;
	b9.initbrick(50, 10, 20, 100, 0);
	brick b10;
	b10.initbrick(50, 10, 100, 100, 0);
	brick b11;
	b11.initbrick(50, 10, 180, 100, 0);
	brick b12;
	b12.initbrick(50, 10, 260, 100, 0);
	brick b13;
	b13.initbrick(50, 10, 340, 100, 0);
	brick b14;
	b14.initbrick(50, 10, 420, 100, 0);
	brick b15;
	b15.initbrick(50, 10, 500, 100, 0);
	brick b16;
	b16.initbrick(50, 10, 580, 100, 0);
	brick b17;
	b17.initbrick(50, 10, 20, 180, 0);
	brick b18;
	b18.initbrick(50, 10, 100, 180, 0);
	brick b19;
	b19.initbrick(50, 10, 180, 180, 0);
	brick b20;
	b20.initbrick(50, 10, 260, 180, 0);
	brick b21;
	b21.initbrick(50, 10, 340, 180, 0);
	brick b22;
	b22.initbrick(50, 10, 420, 180, 0);
	brick b23;
	b23.initbrick(50, 10, 500, 180, 0);
	brick b24;
	b24.initbrick(50, 10, 580, 180, 0);
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//////////////////////////////////////////////////////////////////////////////////////////////////
		//here's the movement algorithm

		if (ev.type == ALLEGRO_EVENT_TIMER) {

			if (bouncer_x < 0 || bouncer_x > 640 - 32) {
				bouncer_dx = -bouncer_dx;
			}
			if (bouncer_y < 0 || bouncer_y > 480 - 32) {
				bouncer_dy = -bouncer_dy;
			}


			bouncer_x += bouncer_dx;
			bouncer_y += bouncer_dy;

			if (collision(bouncer_x, bouncer_y, 32, 32, square_x, square_y, 32, 32)) {
				bouncer_dy = -bouncer_dy;

			}

			//cool sound effect here
			//increase score
			if (b1.Collision(bouncer_x, bouncer_y, 32, 32) && b1.isdead() == false) {
				bouncer_dy *= -1;
				b1.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b2.Collision(bouncer_x, bouncer_y, 32, 32) && b2.isdead() == false) {
				bouncer_dy *= -1;
				b2.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b3.Collision(bouncer_x, bouncer_y, 32, 32) && b3.isdead() == false) {
				bouncer_dy *= -1;
				b3.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b4.Collision(bouncer_x, bouncer_y, 32, 32) && b4.isdead() == false) {
				bouncer_dy *= -1;
				b4.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b5.Collision(bouncer_x, bouncer_y, 32, 32) && b5.isdead() == false) {
				bouncer_dy *= -1;
				b5.killbrick();
				score = score + 100;
				counter = counter + 1;
			}
			if (b6.Collision(bouncer_x, bouncer_y, 32, 32) && b6.isdead() == false) {
				bouncer_dy *= -1;
				b6.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b7.Collision(bouncer_x, bouncer_y, 32, 32) && b7.isdead() == false) {
				bouncer_dy *= -1;
				b7.killbrick();
				score = score + 100;
				counter = counter + 1;
			}
			if (b8.Collision(bouncer_x, bouncer_y, 32, 32) && b8.isdead() == false) {
				bouncer_dy *= -1;
				b8.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b9.Collision(bouncer_x, bouncer_y, 32, 32) && b9.isdead() == false) {
				bouncer_dy *= -1;
				b9.killbrick();
				score = score + 100;
				counter = counter + 1;
			}
			if (b10.Collision(bouncer_x, bouncer_y, 32, 32) && b10.isdead() == false) {
				bouncer_dy *= -1;
				b10.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b11.Collision(bouncer_x, bouncer_y, 32, 32) && b11.isdead() == false) {
				bouncer_dy *= -1;
				b11.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b12.Collision(bouncer_x, bouncer_y, 32, 32) && b12.isdead() == false) {
				bouncer_dy *= -1;
				b12.killbrick();
				score = score + 100;
				counter = counter + 1;
			}
			if (b13.Collision(bouncer_x, bouncer_y, 32, 32) && b13.isdead() == false) {
				bouncer_dy *= -1;
				b13.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b14.Collision(bouncer_x, bouncer_y, 32, 32) && b14.isdead() == false) {
				bouncer_dy *= -1;
				b14.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b15.Collision(bouncer_x, bouncer_y, 32, 32) && b15.isdead() == false) {
				bouncer_dy *= -1;
				b15.killbrick();
				score = score + 100;
				counter = counter + 1;
			}
			if (b16.Collision(bouncer_x, bouncer_y, 32, 32) && b16.isdead() == false) {
				bouncer_dy *= -1;
				b16.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b17.Collision(bouncer_x, bouncer_y, 32, 32) && b17.isdead() == false) {
				bouncer_dy *= -1;
				b17.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b18.Collision(bouncer_x, bouncer_y, 32, 32) && b18.isdead() == false) {
				bouncer_dy *= -1;
				b18.killbrick();
				score = score + 100;
				counter = counter + 1;
			}
			if (b19.Collision(bouncer_x, bouncer_y, 32, 32) && b19.isdead() == false) {
				bouncer_dy *= -1;
				b19.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b20.Collision(bouncer_x, bouncer_y, 32, 32) && b20.isdead() == false) {
				bouncer_dy *= -1;
				b20.killbrick();
				score = score + 100;
				counter = counter + 1;
			}
			if (b21.Collision(bouncer_x, bouncer_y, 32, 32) && b21.isdead() == false) {
				bouncer_dy *= -1;
				b21.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b22.Collision(bouncer_x, bouncer_y, 32, 32) && b22.isdead() == false) {
				bouncer_dy *= -1;
				b22.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b23.Collision(bouncer_x, bouncer_y, 32, 32) && b23.isdead() == false) {
				bouncer_dy *= -1;
				b23.killbrick();
				score = score + 100;
				counter = counter + 1;
			}

			if (b24.Collision(bouncer_x, bouncer_y, 32, 32) && b24.isdead() == false) {
				bouncer_dy *= -1;
				b24.killbrick();
				score = score + 100;
				counter = counter + 1;
			}



			redraw = true;


			if (counter == 24) {
				al_clear_to_color(al_map_rgb(0, 0, 0));//wipes screen to black
				al_draw_text(font, al_map_rgb(255, 255, 255), 20, 300, NULL, "You Win!");
				al_flip_display();
				al_rest(3);//pause to read it
				return 0;
			}
			//if the left button is pressed AND we're still right of the left wall
			//move the box left by 4 pixels
			if (key[0] && square_x >= 0) {
				square_x -= 4.0;
			}

			//if the left button is pressed AND we're still left of the right wall
			//move the box right by 4 pixels
			if (key[1] && square_x <= 640 - 32) {
				square_x += 4.0;

				//if the box hits the left wall OR the right wall
				if (bouncer_y < 0 || bouncer_y > 480 - 32) {
					//flip the x direction
					bouncer_dy = bouncer_dy;
				}
			}

			//redraw at every tick of the timer
			redraw = true;
		}//end timer section
		 ///////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			return 0;//kill the program
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT:
				key[0] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[1] = false;
				break;

			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

			//"keycode" holds all the different keys on the keyboard
			switch (ev.keyboard.keycode) {
				cout << "key down" << endl;
				//if the up key has been pressed


				//if the left key has been pressed
			case ALLEGRO_KEY_LEFT:
				key[0] = true;
				break;

				//if the right key has been pressed
			case ALLEGRO_KEY_RIGHT:
				key[1] = true;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}


		//kill the program if someone presses escape





		//render section
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));


			//le paddle
			al_draw_filled_rectangle(square_x, square_y, square_x + 70, square_y + 20, al_map_rgb(44, 9, 36));


			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);

			//draw bricks
			if (b1.isdead() == false)
				b1.draw();
			if (b2.isdead() == false)
				b2.draw();
			if (b3.isdead() == false)
				b3.draw();
			if (b4.isdead() == false)
				b4.draw();
			if (b5.isdead() == false)
				b5.draw();
			if (b6.isdead() == false)
				b6.draw();
			if (b7.isdead() == false)
				b7.draw();
			if (b8.isdead() == false)
				b8.draw();
			if (b9.isdead() == false)
				b9.draw();
			if (b10.isdead() == false)
				b10.draw();
			if (b11.isdead() == false)
				b11.draw();
			if (b12.isdead() == false)
				b12.draw();
			if (b13.isdead() == false)
				b13.draw();
			if (b14.isdead() == false)
				b14.draw();
			if (b15.isdead() == false)
				b15.draw();
			if (b16.isdead() == false)
				b16.draw();
			if (b17.isdead() == false)
				b17.draw();
			if (b18.isdead() == false)
				b18.draw();
			if (b19.isdead() == false)
				b19.draw();
			if (b20.isdead() == false)
				b20.draw();
			if (b21.isdead() == false)
				b21.draw();
			if (b22.isdead() == false)
				b22.draw();
			if (b23.isdead() == false)
				b23.draw();
			if (b24.isdead() == false)
				b24.draw();

			al_draw_textf(font, al_map_rgb(255, 255, 255), 20, 10, NULL, "Score= %d", score);

			al_flip_display();


		}//end render
	}//end game loop

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

bool brick::Collision(int BallX, int BallY, int BallW, int BallH) {

	//any time the ball's x position is LESS than the paddle's x position plus its width, you've collided
	if ((BallX + BallW > xposition) && (BallX < xposition + width) &&
		//AND any time the ball's x position plus its width is greater than the paddle's x position

		//AND repeat for y (you'll need two statements again)...
		(BallY + BallH > yposition) && (BallY < yposition + height)

		)
		return true; //collision!
	else
		return false; //no collision


}

void brick::killbrick() {

	dead = 1;
}

void brick::initbrick(int w, int h, int x, int y, bool d) {
	width = w;
	height = h;
	xposition = x;
	yposition = y;
	dead = d;

}

void brick::draw() {

	al_draw_filled_rectangle(xposition, yposition, xposition + width, yposition + height, al_map_rgb(200, 30, 0));
}


bool brick::isdead() {
	if (dead == true)
		return true;
	else
		return false;

}

void brick::constructor() {
	width = 0;
	height = 0;
	xposition = 0;
	yposition = 0;
	dead = 0;

}
bool collision(int BallX, int BallY, int BallW, int BallH, int PaddleX, int PaddleY, int PaddleW, int PaddleH) {

	//any time the ball's x position is LESS than the paddle's x position plus its width, you've collided
	if ((BallX + BallW > PaddleX) && (BallX < PaddleX + PaddleW) &&
		//AND any time the ball's x position plus its width is greater than the paddle's x position

		//AND repeat for y (you'll need two statements again)...
		(BallY + BallH > PaddleY) && (BallY < PaddleY + PaddleH)

		)
		return true; //collision!
	else
		return false; //no collision


}