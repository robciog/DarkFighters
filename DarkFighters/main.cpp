
//#include "objects.h"
#include "functions.h"

Card card_my[30],card_enemy[30];
Card *karta = card_my, *karta_enemy=card_enemy;
Player gracz1, gracz2;
Player *wsk_Player1 = &gracz1;
Player *wsk_Player2 = &gracz2;
Globals globals_s;
Globals *globals_wsk = &globals_s;





int main(void)
{
	//primitive variable
	bool done = false;
	bool redraw = true;
	bool pressed = false;
	const int FPS = 60;
	bool isGameOver = false;
	//bool game = false;
	//bool endTurn = false;
	//bool stats = false;
	float gameTime = 0;
	int frames = 0;
	int gameFPS = 0;

	int cardID = -1;
	

	

	InitGame(karta,karta_enemy, wsk_Player1, wsk_Player2);

	int player = 0;
	//pozycje kursora
	int oldPos_x, oldPos_y; 
	int pos_x = 0,pos_y = 0;

	//object variables


	//Allegro variables
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_FONT *font18 = NULL, *font40 = NULL;
	

	//Initialization Functions
	if (!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(WIDTH, HEIGHT);			//create our display object

	if (!display)										//test display object
		return -1;

	al_init_primitives_addon();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	srand(time(NULL));

	font18 = al_load_font("arial.ttf", 18, 0);
	font40 = al_load_font("arial.ttf", 40, 0);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_start_timer(timer);
	wsk_Player1 = &gracz2;
	wsk_Player2 = &gracz1;
	karta = card_enemy;
	karta_enemy = card_my;
	CheckCards(karta, wsk_Player1, wsk_Player2);
	flipCards(karta, karta_enemy);
	wsk_Player1 = &gracz1;
	wsk_Player2 = &gracz2;
	karta = card_my;
	karta_enemy = card_enemy;
	CheckCards(karta, wsk_Player1, wsk_Player2);

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);


		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			frames++;
			if (al_current_time() - gameTime >= 1)
			{
				gameTime = al_current_time();
				gameFPS = frames;
				frames = 0;
			}
			if (keys[UP])
			{
				//MoveShipUp(ship);
			}
			if (keys[DOWN])
			{
				//MoveShipDown(ship);
			}
			if (keys[LEFT])
			{
				//MoveShipLeft(ship);
			}
			if (keys[RIGHT])
			{
				//MoveShipRight(ship);
			}

			if (!isGameOver)
			{
				/*UpdateBullet(bullets, NUM_BULLETS);
				StartComet(comets, NUM_COMETS);
				UpdateComet(comets, NUM_COMETS);
				CollideBullet(bullets, NUM_BULLETS, comets, NUM_COMETS, ship);
				CollideComet(comets, NUM_COMETS, ship);*/

				//if (ship.lives <= 0)
					//isGameOver = true;
			}

		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_S:
				if (globals_s.stats) globals_s.stats= false;
				else globals_s.stats = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
				//FireBullet(bullets, NUM_BULLETS, ship);
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
				break;
			}
		}
		//--------------------MOUSE MOVE-----------------------------------//
		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;
		}
		//--------------------MOUSE BUTTON DOWN----------------------------//
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			/*if (game && pos_x > karta[0].pos_x && pos_x<karta[0].pos_x+90 && pos_y>karta[0].pos_y && pos_y<karta[0].pos_y+150)
			{
				if (!pressed)
				pressed = true;
				
			}*/
			if (!globals_s.pressed)
			{
				globals_s.pressed = true;
				globals_s.pos_x = pos_x;
				globals_s.pos_y = pos_y;
			}
			if (ev.mouse.button & 2) // usuwanie kart z gry - tymczasowe
			{
				for (int i = 0; i < 30; i++)
				{
					if (globals_s.game && pos_x>karta[i].pos_x && pos_x<karta[i].pos_x + 90 && pos_y>karta[i].pos_y && pos_y < karta[i].pos_y + 150)
					{
						karta[i].inGame = false;
						karta[i].inHand = false;
						karta[i].used = true;
						karta[i].pos_x = 0;
						karta[i].pos_y = 0;
						//gracz1.cardsInGame--;
						wsk_Player1->cardsInHand--;
							
					}
				}
			}
			else
			{
				for (int i = 0; i < 30; i++) //przesuwanie karty
				{
					if (globals_s.game && pos_x>karta[i].pos_x && pos_x<karta[i].pos_x + 90 && pos_y>karta[i].pos_y && pos_y < karta[i].pos_y + 150 && karta[i].inGame)
					{
						if (!pressed && !karta[i].onTable)
						{
							pressed = true;
							cardID = i;
							oldPos_x = karta[i].pos_x;
							oldPos_y = karta[i].pos_y;
							for (int j = 0; j < 30;j++)
							if (karta[j].selected) //odznacz aktywna karte na stole
								karta[j].selected = false;
						}
						if (!pressed && karta[i].onTable && karta[i].active && !globals_s.selectedToAttack) //aktywowanie i dezaktywowanie karty na stole
						{
							if (!karta[i].selected)
							{
								karta[i].selected = true;
								globals_s.cardID = i;
								globals_s.selectedToAttack = true;
							}
							
						}
						else
						{
							karta[globals_s.cardID].selected = false;
							globals_s.cardID = -1;
							globals_s.selectedToAttack = false;
						}
					}
					if (globals_s.selectedToAttack && karta_enemy[i].onTable && pos_x > karta_enemy[i].pos_x && pos_x<karta_enemy[i].pos_x + 90 && pos_y<karta_enemy[i].pos_y && pos_y>karta_enemy[i].pos_y - 150)
					{
						karta_enemy[i].def -= karta[globals_s.cardID].atk;
						karta[globals_s.cardID].def -= karta_enemy[i].atk;
						karta[globals_s.cardID].active = false;
						karta[globals_s.cardID].selected = false;
						if (karta[globals_s.cardID].def <= 0)
						{
							karta[globals_s.cardID].onTable = false;
							karta[globals_s.cardID].inGame = false;
							karta[globals_s.cardID].selected = false;
							karta[globals_s.cardID].used = true;
							
							karta[globals_s.cardID].pos_y = 1500;
							wsk_Player1->cardsInGame--;
							//usun_z_listy_z_lewej(&(wsk_Player1->myTable));
							usun_z_listy((&(wsk_Player1->myTable)), wsk_Player1, karta, globals_s.cardID, karta[globals_s.cardID].pos_x + 10);
							karta[globals_s.cardID].pos_x = 1500;

						}
						if (karta_enemy[i].def <= 0)
						{
							karta_enemy[i].onTable = false;
							karta_enemy[i].inGame = false;
							//karta_enemy[i].selected = false;
							karta_enemy[i].used = true;
							
							karta_enemy[i].pos_y = 1500;
							wsk_Player2->cardsInGame--;
							//usun_z_listy_z_lewej(&(wsk_Player2->myTable));
							usun_z_listy((&(wsk_Player2->myTable)), wsk_Player2, karta_enemy, i, pos_x);
							karta_enemy[i].pos_x = 1500;

						}
						globals_s.cardID = -1;
						globals_s.selectedToAttack = false;
						CheckCards(karta, wsk_Player1, wsk_Player2);
					}
					if (globals_s.selectedToAttack && pos_x>30 && pos_x<130 && pos_y>80 && pos_y<180)
					{
						wsk_Player2->hp -= karta[globals_s.cardID].atk;
						karta[globals_s.cardID].selected = false;
						karta[globals_s.cardID].active = false;
						globals_s.cardID = -1;
						globals_s.selectedToAttack = false;

					}
					
				}
				if (!globals_s.game && ev.mouse.button == 1 && ev.mouse.x > WIDTH / 2 - 90 && ev.mouse.x < WIDTH / 2 + 90 //wyjscie z gry
					&& ev.mouse.y >(HEIGHT / 4) * 3 - 40 && ev.mouse.y < (HEIGHT / 4) * 3 + 40)
				{
					done = true;
				}
				if (ev.mouse.button == 1 && ev.mouse.x > WIDTH / 2 - 90 && ev.mouse.x < WIDTH / 2 + 90 //uruchomienie gry
					&& ev.mouse.y >(HEIGHT / 4) * 1 - 40 && ev.mouse.y < (HEIGHT / 4) * 1 + 40)
					globals_s.game = true;
				if (globals_s.game && (WIDTH - 30 - ev.mouse.x)*(WIDTH - 30 - ev.mouse.x) + (HEIGHT - 30 - ev.mouse.y)*(HEIGHT - 30 - ev.mouse.y) < 400) //wywolanie menu 
				{
					globals_s.gameMenu = true;
				}
				if (globals_s.game && pos_x>WIDTH - 150 && pos_y>HEIGHT / 2 - 20 && pos_x < WIDTH - 50 && pos_y < HEIGHT / 2 + 20)
				{
					//globals_s.game = false;
					globals_s.endTurn = true;
				}
				if (globals_s.endTurn && pos_x>WIDTH / 4 - 100 && pos_y>HEIGHT / 2 - 50 && pos_x<WIDTH / 4 + 100 && pos_y<HEIGHT / 2 + 50)
				{
					//globals_s.game = true;
					globals_s.endTurn = false;
					if (wsk_Player1 == &gracz1)
					{
						if (wsk_Player2->cardsInHand<7)
						wsk_Player2->cardsInHand++;

						wsk_Player1 = &gracz2;
						wsk_Player2 = &gracz1;
						karta = card_enemy;
						karta_enemy = card_my;
						activateCards(karta);
						
						
					}
					else
					{
						if (wsk_Player1->max_mana < 10)
							wsk_Player1->max_mana++;
						if (wsk_Player2->max_mana < 10)
							wsk_Player2->max_mana++;
						wsk_Player1->mana = wsk_Player1->max_mana;
						wsk_Player2->mana = wsk_Player2->max_mana;

						if (wsk_Player2->cardsInHand<7)
						wsk_Player2->cardsInHand++;

						wsk_Player1 = &gracz1;
						wsk_Player2 = &gracz2;
						karta = card_my;
						karta_enemy = card_enemy;
						activateCards(karta);
					}
					flipCards(karta, karta_enemy);
					CheckCards(karta, wsk_Player1, wsk_Player2);
				}
				if (true)
				{

				}
			}
				
		}

		//--------------------MOUSE BUTTON UP----------------------------//
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			if (globals_s.pressed)
			{
				globals_s.pressed = false;
				globals_s.pos_x = 2000;
				globals_s.pos_y = 2000;
			}
			if (ev.mouse.button & 2)
			{
				CheckCards(karta, wsk_Player1, wsk_Player2);
			}
			if (pressed)
			{
				pressed = false;
				if (!karta[cardID].onTable)
				{
					int cardOnTable = cardsOnTable(wsk_Player1->myTable); // sprawdza ile jest juz kart na stole
					if (pos_x > 160 && pos_x<850 && pos_y>360 && pos_y < 510 && wsk_Player1->mana>0 && cardOnTable<7 && karta[cardID].manaCost<=wsk_Player1->mana)
					{
						putCard(wsk_Player1, karta, cardID, pos_x); //rozmieszcza karty w odpowiednich miejscach na stole
						karta[cardID].inHand = false;
						karta[cardID].onTable = true;
						wsk_Player1->cardsInHand--;
						CheckCards(karta, wsk_Player1, wsk_Player2);
						wsk_Player1->mana-=karta[cardID].manaCost;
					}
					else
					{
						karta[cardID].pos_x = oldPos_x;
						karta[cardID].pos_y = oldPos_y;
					}
					cardID = -1;
				}
			}
		}


		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;

			if (!isGameOver)
			{
				if (!globals_s.game && !globals_s.endTurn)		//rysowanie menu glownego gry
				{
					InitMenu(font18, font40,  pos_x, pos_y);
				}
				/*if (!globals_s.game && !globals_s.endTurn)
				{
				}*/
				else
				{
					if (wsk_Player1->hp <= 0)
					{
						initEndMenu(font18, wsk_Player1, globals_wsk);
					}
					else if (wsk_Player2->hp <= 0)
					{
						initEndMenu(font18, wsk_Player2, globals_wsk);
					}
					else if (globals_s.endTurn)		//rysowanie menu tury przeciwnika
					{
						endTurns(font18, wsk_Player1);
					}
					else if (globals_s.gameMenu)		//rysowanie menu w grze
					{
						GameMenu(font18, font40, pos_x, pos_y, globals_wsk);		
					}
					else
					{
						if (globals_s.newGame)		//inicjowanie nowej gry
						{
							InitGame(karta, karta_enemy, wsk_Player1, wsk_Player2);
							wsk_Player1 = &gracz2;
							wsk_Player2 = &gracz1;
							karta = card_enemy;
							karta_enemy = card_my;
							CheckCards(karta, wsk_Player1, wsk_Player2);
							flipCards(karta, karta_enemy);
							wsk_Player1 = &gracz1;
							wsk_Player2 = &gracz2;
							karta = card_my;
							karta_enemy = card_enemy;
							CheckCards(karta, wsk_Player1, wsk_Player2);
							globals_s.newGame = false;
						}
						if (globals_s.stats)	//rysowanie statystyk
						{
							DrawStats(font18, pos_x, pos_y, gameFPS);
						}
						if (pressed)	//rysowanie przesowanej karty
						{
							karta[cardID].pos_x = pos_x - 45;
							karta[cardID].pos_y = pos_y - 75;
						}
						DrawGame(font18, pos_x, pos_y, karta, karta_enemy, wsk_Player1, wsk_Player2, cardID);	//rysowanie gry
						drawArrow(pos_x, pos_y, karta, karta_enemy);	//rysowanie strzalki
					}
				}

				/*DrawShip(ship);
				DrawBullet(bullets, NUM_BULLETS);
				DrawComet(comets, NUM_COMETS);*/

				//al_draw_textf(font18, al_map_rgb(255, 0, 255), 5, 5, 0, "Player has %i lives left. Player has destroyed %i objects", ship.lives, ship.score);
			}
			else
			{
				//al_draw_textf(font18, al_map_rgb(0, 255, 255), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Game Over. Final Score: %i", ship.score);
			}


			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}

	}

	al_destroy_display(display);						//destroy our display object

	return 0;
}



