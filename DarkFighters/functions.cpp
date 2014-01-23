#include "functions.h"
bool keys[5] = { false, false, false, false, false };
//Table *first;

void InitMenu(ALLEGRO_FONT *font18, ALLEGRO_FONT *font40, int x, int y)
{
	al_draw_textf(font40, al_map_rgb(255, 255, 255), WIDTH / 2, 70, ALLEGRO_ALIGN_CENTRE, "Dark Fighters");
	//al_draw_filled_circle(bullet[i].x, bullet[i].y, 2, al_map_rgb(255, 255, 255));
	al_draw_rectangle(WIDTH / 2 - 90, (HEIGHT / 4) - 40, WIDTH / 2 + 90, (HEIGHT / 4) + 40, al_map_rgb(255, 0, 0), 2);
	if (x > WIDTH / 2 - 90 && x < WIDTH / 2 + 90
		&& y >(HEIGHT / 4) * 1 - 40 && y < (HEIGHT / 4) * 1 + 40)
	{
		al_draw_textf(font18, al_map_rgb(255, 255, 255), WIDTH / 2, (HEIGHT / 4) - 10, ALLEGRO_ALIGN_CENTRE, "START");
	}
	else
		al_draw_textf(font18, al_map_rgb(0, 255, 255), WIDTH / 2, (HEIGHT / 4) - 10, ALLEGRO_ALIGN_CENTRE, "START");

	al_draw_rectangle(WIDTH / 2 - 90, (HEIGHT / 4) * 2 - 40, WIDTH / 2 + 90, (HEIGHT / 4) * 2 + 40, al_map_rgb(255, 0, 0), 2);
	if (x > WIDTH / 2 - 90 && x < WIDTH / 2 + 90
		&& y >(HEIGHT / 4) * 2 - 40 && y < (HEIGHT / 4) * 2 + 40)
	{
		al_draw_textf(font18, al_map_rgb(255, 255, 255), WIDTH / 2, (HEIGHT / 4) * 2 - 10, ALLEGRO_ALIGN_CENTRE, "OPCJE");
	}
	else
		al_draw_textf(font18, al_map_rgb(0, 255, 255), WIDTH / 2, (HEIGHT / 4) * 2 - 10, ALLEGRO_ALIGN_CENTRE, "OPCJE");

	al_draw_rectangle(WIDTH / 2 - 90, (HEIGHT / 4) * 3 - 40, WIDTH / 2 + 90, (HEIGHT / 4) * 3 + 40, al_map_rgb(255, 0, 0), 2);
	if (x > WIDTH / 2 - 90 && x < WIDTH / 2 + 90
		&& y >(HEIGHT / 4) * 3 - 40 && y < (HEIGHT / 4) * 3 + 40)
	{
		al_draw_textf(font18, al_map_rgb(255, 255, 255), WIDTH / 2, (HEIGHT / 4) * 3 - 10, ALLEGRO_ALIGN_CENTRE, "KONIEC");
	}
	else
	{
		al_draw_textf(font18, al_map_rgb(0, 255, 255), WIDTH / 2, (HEIGHT / 4) * 3 - 10, ALLEGRO_ALIGN_CENTRE, "KONIEC");
	}


	//if (ev.type == ALLEGRO_EVENT_MOUSE_AXES){
	//pos_x = ev.mouse.x;
	//pos_y = ev.mouse.y;


}
void GameMenu(ALLEGRO_FONT *font18, ALLEGRO_FONT *font40, int x, int y, Globals *globals)
{
	al_draw_textf(font40, al_map_rgb(255, 255, 255), WIDTH / 2, 70, ALLEGRO_ALIGN_CENTRE, "Dark Fighters");
	//al_draw_filled_circle(bullet[i].x, bullet[i].y, 2, al_map_rgb(255, 255, 255));
	al_draw_rectangle(WIDTH / 2 - 90, (HEIGHT / 4) - 40, WIDTH / 2 + 90, (HEIGHT / 4) + 40, al_map_rgb(255, 0, 0), 2);
	if (x > WIDTH / 2 - 90 && x < WIDTH / 2 + 90
		&& y >(HEIGHT / 4) * 1 - 40 && y < (HEIGHT / 4) * 1 + 40)
	{
		if (globals->pressed && globals->pos_x > WIDTH / 2 - 90 && globals->pos_x < WIDTH / 2 + 90 && globals->pos_y >(HEIGHT / 4) * 1 - 40 && globals->pos_y < (HEIGHT / 4) * 1 + 40)
		{
			globals->gameMenu = false;
		}
		else
		al_draw_textf(font18, al_map_rgb(255, 255, 255), WIDTH / 2, (HEIGHT / 4) - 10, ALLEGRO_ALIGN_CENTRE, "POWROT");
	}
	else
		al_draw_textf(font18, al_map_rgb(0, 255, 255), WIDTH / 2, (HEIGHT / 4) - 10, ALLEGRO_ALIGN_CENTRE, "POWROT");

	al_draw_rectangle(WIDTH / 2 - 90, (HEIGHT / 4) * 2 - 40, WIDTH / 2 + 90, (HEIGHT / 4) * 2 + 40, al_map_rgb(255, 0, 0), 2);
	if (x > WIDTH / 2 - 90 && x < WIDTH / 2 + 90
		&& y >(HEIGHT / 4) * 2 - 40 && y < (HEIGHT / 4) * 2 + 40)
	{
		if (globals->pressed && globals->pos_x > WIDTH / 2 - 90 && globals->pos_x < WIDTH / 2 + 90 && globals->pos_y >(HEIGHT / 4) * 2 - 40 && globals->pos_y < (HEIGHT / 4) * 2 + 40)
		{
			globals->gameMenu = false;
			globals->newGame = true;
		}
		else
		al_draw_textf(font18, al_map_rgb(255, 255, 255), WIDTH / 2, (HEIGHT / 4) * 2 - 10, ALLEGRO_ALIGN_CENTRE, "NOWA GRA");
	}
	else
		al_draw_textf(font18, al_map_rgb(0, 255, 255), WIDTH / 2, (HEIGHT / 4) * 2 - 10, ALLEGRO_ALIGN_CENTRE, "NOWA GRA");

	al_draw_rectangle(WIDTH / 2 - 90, (HEIGHT / 4) * 3 - 40, WIDTH / 2 + 90, (HEIGHT / 4) * 3 + 40, al_map_rgb(255, 0, 0), 2);
	if (x > WIDTH / 2 - 90 && x < WIDTH / 2 + 90
		&& y >(HEIGHT / 4) * 3 - 40 && y < (HEIGHT / 4) * 3 + 40)
	{
		if (globals->pressed && globals->pos_x > WIDTH / 2 - 90 && globals->pos_x < WIDTH / 2 + 90 && globals->pos_y >(HEIGHT / 4) * 3 - 40 && globals->pos_y < (HEIGHT / 4) * 3 + 40)
		{
			globals->gameMenu = false;
			globals->game = false;
		}
		else
		al_draw_textf(font18, al_map_rgb(255, 255, 255), WIDTH / 2, (HEIGHT / 4) * 3 - 10, ALLEGRO_ALIGN_CENTRE, "WYJSCIE DO MENU");
	}
	else
	{
		al_draw_textf(font18, al_map_rgb(0, 255, 255), WIDTH / 2, (HEIGHT / 4) * 3 - 10, ALLEGRO_ALIGN_CENTRE, "WYJSCIE DO MENU");
	}


	//if (ev.type == ALLEGRO_EVENT_MOUSE_AXES){
	//pos_x = ev.mouse.x;
	//pos_y = ev.mouse.y;


}
void initEndMenu(ALLEGRO_FONT *font18, Player *gracz, Globals *globals)
{
	if (gracz->ID==2)
		al_draw_textf(font18, al_map_rgb(255, 0, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Wygral gracz Pierwszy");
	else
		al_draw_textf(font18, al_map_rgb(255, 0, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Wygral gracz Drugi");
	al_draw_rectangle(WIDTH / 4 - 100, HEIGHT / 2 - 50, WIDTH / 4 + 100, HEIGHT / 2 + 50, al_map_rgb(255, 255, 255), 2);
	if (globals->pressed && globals->pos_x>WIDTH / 4 - 100 && globals->pos_y>HEIGHT / 2 - 50 && globals->pos_x<WIDTH / 4 + 100 && globals->pos_y<HEIGHT / 2 + 50)
	{
		globals->game = false;
		globals->newGame = true;
		gracz->hp = 30;
	}
}
void CheckCards(Card karta[30], Player *gracz1, Player *gracz2)
{
	int max = gracz1->cardsInHand;
	int count = 0;
	int i = 0;
	int k = 0;
	for (int j = 0; j <30; j++)
	{
		if (karta[j].inHand)
			count++;
	}
	while (count < max && i<30)
	{
		if (max>0)
		{
			if (!karta[i].inHand && !karta[i].used && !karta[i].onTable)
			{
				karta[i].inGame = true;
				karta[i].inHand = true;
				count++;				
			}
			i++;
		}
	}
	max = count;
	count = 0;
	i = 0;
	while (count < max)
	{
		if (max>0)
		{
			if (max % 2 == 0)
			{
				if (karta[i].inHand)
				{
					count++;
					karta[i].pos_x = (WIDTH / 2) - (max / 2 - 1) * 100 - 95 + (k * 100);
					k++;
					karta[i].pos_y = HEIGHT / 4 * 3+10;
				}
				i++;


			}
			else
			{
				if (karta[i].inHand)
				{
					count++;
					karta[i].pos_x = (WIDTH / 2) - (max / 2) * 100 - 45 + (k * 100);
					k++;
					karta[i].pos_y = HEIGHT / 4 * 3+10;
				}
				i++;
			}
		}
	}
}
void DrawGame(ALLEGRO_FONT *font18, int x, int y, Card karta[30], Card karta_enemy[30], Player *gracz1, Player *gracz2, int cardID)
{
	int count = 0;
	for (int j = 0; j <30; j++)
	{
		if (karta[j].inGame)
			count++;
	}
	//portraits
	al_draw_filled_circle(80, 130, 30, al_map_rgb(0, 255, 255));
	al_draw_filled_circle(80, 195, 40, al_map_rgb(0, 255, 255));
	al_draw_filled_rectangle(30, 180, 130, 235, al_map_rgb(0, 0, 0));
	if (gracz1->ID==1)
		al_draw_textf(font18, al_map_rgb(255, 0, 0), 80, 60, ALLEGRO_ALIGN_CENTRE, "Drugi");
	else
		al_draw_textf(font18, al_map_rgb(255, 0, 0), 80, 60, ALLEGRO_ALIGN_CENTRE, "Pierwszy");
	al_draw_rectangle(30, 80, 130, 180, al_map_rgb(0, 255, 255), 0);
	al_draw_filled_circle(117, 167, 12, al_map_rgb(0, 0, 0));
	al_draw_textf(font18, al_map_rgb(255, 0, 0), 117, 157, ALLEGRO_ALIGN_CENTRE, "%d", gracz2->hp);
	for (int i = 0; i < gracz2->max_mana; i++)
	{
		if (i < 5)
		{
			al_draw_circle(30 + i * 25, 200, 10, al_map_rgb(0, 255, 255), 2);
			if (i<gracz2->mana)
				al_draw_filled_circle(30 + i * 25, 200, 8, al_map_rgb(0, 255, 255));
		}
		else
		{
			al_draw_circle(30 + (i - 5) * 25, 230, 10, al_map_rgb(0, 255, 255), 2);
			if (i<gracz2->mana)
				al_draw_filled_circle(30 + (i - 5) * 25, 230, 8, al_map_rgb(0, 255, 255));
		}
	}

	if (gracz1->ID == 1)
		al_draw_textf(font18, al_map_rgb(255, 0, 0), 80, HEIGHT - 200, ALLEGRO_ALIGN_CENTRE, "Pierwszy");
	else
		al_draw_textf(font18, al_map_rgb(255, 0, 0), 80, HEIGHT - 200, ALLEGRO_ALIGN_CENTRE, "Drugi");
	al_draw_rectangle(30, HEIGHT - 180, 130, HEIGHT - 80, al_map_rgb(0, 255, 255), 0);
	al_draw_textf(font18, al_map_rgb(255, 0, 0), 119, HEIGHT - 100, ALLEGRO_ALIGN_CENTRE, "%d",gracz1->hp);
	for (int i = 0; i < gracz1->max_mana; i++)
	{
		if (i < 5)
		{
			al_draw_circle(30+i*25, 640, 10, al_map_rgb(0, 255, 255), 2);
			if (i<gracz1->mana)
				al_draw_filled_circle(30 + i * 25, 640, 8, al_map_rgb(0, 255, 255));
		}
		else
		{
			al_draw_circle(30 + (i-5) * 25, 670, 10, al_map_rgb(0, 255, 255), 2);
			if (i<gracz1->mana)
				al_draw_filled_circle(30 + (i-5) * 25, 670, 8, al_map_rgb(0, 255, 255));
		}
	}

	al_draw_line(0, HEIGHT / 2, WIDTH, HEIGHT / 2, al_map_rgb(255, 255, 255), 2);
	
	//cards
	for (int j = 0; j <30; j++)
	{
		if (count == 0)
			break;
		if (karta[j].inGame)
		{
			if (x>karta[j].pos_x && y > karta[j].pos_y && x < karta[j].pos_x + 90 && y < karta[j].pos_y + 150) //hover card
			{
				if (karta[j].selected)
				{
					al_draw_rectangle(karta[j].pos_x, karta[j].pos_y, karta[j].pos_x + 90, karta[j].pos_y + 150, al_map_rgb(96, 96, 96), 2);
				}
				else
				al_draw_rectangle(karta[j].pos_x, karta[j].pos_y, karta[j].pos_x + 90, karta[j].pos_y + 150, al_map_rgb(0, 139, 0), 2);
				al_draw_filled_rectangle(karta[j].pos_x, karta[j].pos_y, karta[j].pos_x + 89, karta[j].pos_y + 149, al_map_rgb(139, 90, 0));
				al_draw_textf(font18, al_map_rgb(255, 0, 0), karta[j].pos_x + 45, karta[j].pos_y + 70, ALLEGRO_ALIGN_CENTRE, "%d", j);
				al_draw_filled_circle(karta[j].pos_x + 10, karta[j].pos_y + 140, 9, al_map_rgb(0, 0, 0));
				al_draw_filled_circle(karta[j].pos_x + 80, karta[j].pos_y + 140, 9, al_map_rgb(0, 0, 0));
				al_draw_filled_circle(karta[j].pos_x + 10, karta[j].pos_y + 10, 9, al_map_rgb(0, 0, 0));
				al_draw_textf(font18, al_map_rgb(255, 0, 0), karta[j].pos_x + 10, karta[j].pos_y + 130, ALLEGRO_ALIGN_CENTRE, "%d", karta[j].atk);
				al_draw_textf(font18, al_map_rgb(255, 0, 0), karta[j].pos_x + 80, karta[j].pos_y + 130, ALLEGRO_ALIGN_CENTRE, "%d", karta[j].def);
				al_draw_textf(font18, al_map_rgb(255, 0, 0), karta[j].pos_x + 10, karta[j].pos_y , ALLEGRO_ALIGN_CENTRE, "%d", karta[j].manaCost);

				//details
				al_draw_filled_rectangle(50, HEIGHT / 2 - 150, 210, HEIGHT / 2 + 150, al_map_rgb(0, 139, 0));
				al_draw_textf(font18, al_map_rgb(139, 0, 0), 105, HEIGHT/2, ALLEGRO_ALIGN_CENTER, "OPIS");
				al_draw_textf(font18, al_map_rgb(139, 0, 0), 80, HEIGHT / 2+130, ALLEGRO_ALIGN_CENTER, "Atak %d", karta[j].atk);
				al_draw_textf(font18, al_map_rgb(139, 0, 0), 165, HEIGHT / 2+130, ALLEGRO_ALIGN_CENTER, "Obrona %d", karta[j].def);
				al_draw_textf(font18, al_map_rgb(139, 0, 0), 110, HEIGHT / 2 - 150, ALLEGRO_ALIGN_CENTER, "Koszt many: %d", karta[j].manaCost);

				//al_rotate_transform();

			}
			else
			{
				if (karta[j].selected)
				{
					al_draw_rectangle(karta[j].pos_x, karta[j].pos_y, karta[j].pos_x + 90, karta[j].pos_y + 150, al_map_rgb(96, 96, 96), 2);
				}
				else if (karta[j].active)
				{
					al_draw_rectangle(karta[j].pos_x, karta[j].pos_y, karta[j].pos_x + 90, karta[j].pos_y + 150, al_map_rgb(0, 139, 0), 5);
				}
				else
				al_draw_rectangle(karta[j].pos_x, karta[j].pos_y, karta[j].pos_x + 90, karta[j].pos_y + 150, al_map_rgb(0, 139, 0), 0);
				if (karta[j].golden)
					al_draw_filled_rectangle(karta[j].pos_x, karta[j].pos_y, karta[j].pos_x + 89, karta[j].pos_y + 149, al_map_rgb(255, 178, 102));
				else
				al_draw_filled_rectangle(karta[j].pos_x, karta[j].pos_y, karta[j].pos_x + 89, karta[j].pos_y + 149, al_map_rgb(139, 90, 0));
				al_draw_textf(font18, al_map_rgb(255, 0, 0), karta[j].pos_x + 45, karta[j].pos_y + 70, ALLEGRO_ALIGN_CENTRE, "%d", j);
				al_draw_filled_circle(karta[j].pos_x + 10, karta[j].pos_y + 140, 9, al_map_rgb(0, 0, 0));
				al_draw_filled_circle(karta[j].pos_x + 80, karta[j].pos_y + 140, 9, al_map_rgb(0, 0, 0));
				al_draw_filled_circle(karta[j].pos_x + 10, karta[j].pos_y + 10, 9, al_map_rgb(0, 0, 0));
				al_draw_textf(font18, al_map_rgb(255, 0, 0), karta[j].pos_x + 10, karta[j].pos_y + 130, ALLEGRO_ALIGN_CENTRE, "%d", karta[j].atk);
				al_draw_textf(font18, al_map_rgb(255, 0, 0), karta[j].pos_x + 80, karta[j].pos_y + 130, ALLEGRO_ALIGN_CENTRE, "%d", karta[j].def);
				al_draw_textf(font18, al_map_rgb(255, 0, 0), karta[j].pos_x + 10, karta[j].pos_y , ALLEGRO_ALIGN_CENTRE, "%d", karta[j].manaCost);
			}
			count--;
		}
	}
	int cardOnTable = cardsOnTable(gracz1->myTable);


	if (cardOnTable<7 && cardID!=-1) // pokazuje gdzie karta zostanie wstawiona na stole
	{
		struct Table *wsk;
		wsk = gracz1->myTable;
		if (cardOnTable<1 && y > 360 && y < 510)
		{
			al_draw_rectangle(467, 360, 557, 510, al_map_rgb(250, 250, 0), 2);
		}
		else
		{
			while (wsk != NULL)
			{

				if (x < karta[wsk->cardID].pos_x + 45 && wsk->prev == NULL && y > 360 && y < 510)
				{
					al_draw_rectangle(karta[wsk->cardID].pos_x - 100, 360, karta[wsk->cardID].pos_x - 10, 510, al_map_rgb(250, 250, 0), 2);
					break;
				}
				if (wsk->next != NULL)
				if (x >karta[wsk->cardID].pos_x + 45 && x < karta[wsk->next->cardID].pos_x + 45 && y > 360 && y < 510)
				{
					al_draw_rectangle(karta[wsk->cardID].pos_x + 45, 360, karta[wsk->cardID].pos_x + 135, 510, al_map_rgb(250, 250, 0), 2);
					break;
				}
				if (x >karta[wsk->cardID].pos_x + 45 && wsk->next == NULL && y > 360 && y < 510)
				{
					al_draw_rectangle(karta[wsk->cardID].pos_x + 100, 360, karta[wsk->cardID].pos_x + 190, 510, al_map_rgb(250, 250, 0), 2);
					break;
				}
				else
					wsk = wsk->next;
			}
		}
	}
	if (cardID != -1)
	{
		al_draw_rectangle(karta[cardID].pos_x, karta[cardID].pos_y, karta[cardID].pos_x + 90, karta[cardID].pos_y + 150, al_map_rgb(0, 139, 0), 0);
		al_draw_filled_rectangle(karta[cardID].pos_x, karta[cardID].pos_y, karta[cardID].pos_x + 89, karta[cardID].pos_y + 149, al_map_rgb(139, 90, 0));
		al_draw_textf(font18, al_map_rgb(255, 0, 0), karta[cardID].pos_x + 45, karta[cardID].pos_y + 70, ALLEGRO_ALIGN_CENTRE, "%d", cardID);
	}

	//enemy cards
	count = 0;
	for (int j = 0; j <30; j++)
	{
		if (karta_enemy[j].inGame)
			count++;
	}
	//for (int i = 0; i < 5; i++)
	//{
	//	if (x>WIDTH / 4 + i * 100 && y < HEIGHT / 4 * 1 && x < WIDTH / 4 + i * 100 + 80 && y > HEIGHT / 4 * 1 - 150) //hover card
	//	{
	//		al_draw_rectangle(WIDTH / 4 + i * 100, HEIGHT / 4 * 1, WIDTH / 4 + i * 100 + 80, HEIGHT / 4 * 1 - 150, al_map_rgb(190, 90, 0), 2);
	//	}
	//	else
	//	{
	//		al_draw_rectangle(WIDTH / 4 + i * 100, HEIGHT / 4 * 1, WIDTH / 4 + i * 100 + 80, HEIGHT / 4 * 1 - 150, al_map_rgb(139, 90, 0), 0);
	//	}
	//}
	for (int j = 0; j <30; j++)
	{
		if (count == 0)
			break;
		if (karta_enemy[j].inGame)
		{
			if (karta_enemy[j].onTable &&  x>karta_enemy[j].pos_x && y < karta_enemy[j].pos_y && x < karta_enemy[j].pos_x + 90 && y > karta_enemy[j].pos_y - 150) //hover card
			{
				al_draw_rectangle(karta_enemy[j].pos_x, karta_enemy[j].pos_y, karta_enemy[j].pos_x + 90, karta_enemy[j].pos_y - 150, al_map_rgb(0, 139, 0), 2);
				al_draw_filled_rectangle(karta_enemy[j].pos_x, karta_enemy[j].pos_y, karta_enemy[j].pos_x + 89, karta_enemy[j].pos_y - 149, al_map_rgb(139, 90, 0));
				al_draw_textf(font18, al_map_rgb(255, 0, 0), karta_enemy[j].pos_x + 45, karta_enemy[j].pos_y - 70, ALLEGRO_ALIGN_CENTRE, "%d", j);
				al_draw_filled_circle(karta_enemy[j].pos_x + 10, karta_enemy[j].pos_y - 10, 9, al_map_rgb(0, 0, 0));
				al_draw_filled_circle(karta_enemy[j].pos_x + 80, karta_enemy[j].pos_y - 10, 9, al_map_rgb(0, 0, 0));
				al_draw_filled_circle(karta_enemy[j].pos_x + 10, karta_enemy[j].pos_y - 140, 9, al_map_rgb(0, 0, 0));
				al_draw_textf(font18, al_map_rgb(255, 0, 0), karta_enemy[j].pos_x + 10, karta_enemy[j].pos_y - 20, ALLEGRO_ALIGN_CENTRE, "%d", karta_enemy[j].atk);
				al_draw_textf(font18, al_map_rgb(255, 0, 0), karta_enemy[j].pos_x + 80, karta_enemy[j].pos_y - 20, ALLEGRO_ALIGN_CENTRE, "%d", karta_enemy[j].def);
				al_draw_textf(font18, al_map_rgb(255, 0, 0), karta_enemy[j].pos_x + 10, karta_enemy[j].pos_y - 150, ALLEGRO_ALIGN_CENTRE, "%d", karta_enemy[j].manaCost);

				//details
				al_draw_filled_rectangle(50, HEIGHT / 2 - 150, 210, HEIGHT / 2 + 150, al_map_rgb(0, 139, 0));
				al_draw_textf(font18, al_map_rgb(139, 0, 0), 105, HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "OPIS");
				al_draw_textf(font18, al_map_rgb(139, 0, 0), 80, HEIGHT / 2 + 130, ALLEGRO_ALIGN_CENTER, "Atak: %d", karta_enemy[j].atk);
				al_draw_textf(font18, al_map_rgb(139, 0, 0), 165, HEIGHT / 2 + 130, ALLEGRO_ALIGN_CENTER, "Obrona: %d", karta_enemy[j].def);
				al_draw_textf(font18, al_map_rgb(139, 0, 0), 110, HEIGHT / 2 - 150, ALLEGRO_ALIGN_CENTER, "Koszt many: %d", karta_enemy[j].manaCost);
				//al_rotate_transform();

			}
			else
			{
				al_draw_rectangle(karta_enemy[j].pos_x, karta_enemy[j].pos_y, karta_enemy[j].pos_x + 90, karta_enemy[j].pos_y - 150, al_map_rgb(0, 139, 0), 0);
				al_draw_filled_rectangle(karta_enemy[j].pos_x, karta_enemy[j].pos_y, karta_enemy[j].pos_x + 89, karta_enemy[j].pos_y - 149, al_map_rgb(139, 90, 0));
				al_draw_textf(font18, al_map_rgb(255, 0, 0), karta_enemy[j].pos_x + 45, karta_enemy[j].pos_y - 70, ALLEGRO_ALIGN_CENTRE, "%d", j);
				if (karta_enemy[j].onTable)
				{
					al_draw_filled_circle(karta_enemy[j].pos_x + 10, karta_enemy[j].pos_y - 10, 9, al_map_rgb(0, 0, 0));
					al_draw_filled_circle(karta_enemy[j].pos_x + 80, karta_enemy[j].pos_y - 10, 9, al_map_rgb(0, 0, 0));
					al_draw_filled_circle(karta_enemy[j].pos_x + 10, karta_enemy[j].pos_y - 140, 9, al_map_rgb(0, 0, 0));
					al_draw_textf(font18, al_map_rgb(255, 0, 0), karta_enemy[j].pos_x + 10, karta_enemy[j].pos_y - 20, ALLEGRO_ALIGN_CENTRE, "%d", karta_enemy[j].atk);
					al_draw_textf(font18, al_map_rgb(255, 0, 0), karta_enemy[j].pos_x + 80, karta_enemy[j].pos_y - 20, ALLEGRO_ALIGN_CENTRE, "%d", karta_enemy[j].def);
					al_draw_textf(font18, al_map_rgb(255, 0, 0), karta_enemy[j].pos_x + 10, karta_enemy[j].pos_y - 150, ALLEGRO_ALIGN_CENTRE, "%d", karta_enemy[j].manaCost);
				}
			}
			count--;
		}
	}

	//decs
	for (int i = 0; i < 5; i++)
	{
		al_draw_filled_rectangle(WIDTH - 100 + i * 3, HEIGHT / 2 + 50 - i * 2, WIDTH - 20 + i * 3, HEIGHT / 2 + 200 - i * 2, al_map_rgb(139, 90, 0));
		al_draw_rectangle(WIDTH - 100 + i * 3, HEIGHT / 2 + 50 - i * 2, WIDTH - 20 + i * 3, HEIGHT / 2 + 200 - i * 2, al_map_rgb(0, 139, 0), 1);
	}

	//ture end
	al_draw_rectangle(WIDTH - 150, HEIGHT / 2 - 20, WIDTH - 50, HEIGHT / 2 + 20, al_map_rgb(255, 0, 0), 0);
	al_draw_filled_ellipse(WIDTH - 100, HEIGHT / 2, 50, 20, al_map_rgb(255, 0, 0));
	if (x>WIDTH - 150 && y>HEIGHT / 2 - 20 && x<WIDTH - 50 && y<HEIGHT / 2 + 20) //hover
		al_draw_rectangle(WIDTH - 150, HEIGHT / 2 - 20, WIDTH - 50, HEIGHT / 2 + 20, al_map_rgb(0, 255, 0), 2);
	else
		al_draw_rectangle(WIDTH - 150, HEIGHT / 2 - 20, WIDTH - 50, HEIGHT / 2 + 20, al_map_rgb(255, 0, 0), 2);

	//options
	//al_draw_circle(WIDTH - 30, HEIGHT - 30, 20.0, al_map_rgb(139, 35, 35), 4);
	if ((WIDTH - 30 - x)*(WIDTH - 30 - x) + (HEIGHT - 30 - y)*(HEIGHT - 30 - y)<400)
	{
		al_draw_circle(WIDTH - 30, HEIGHT - 30, 20.0, al_map_rgb(139, 35, 35), 4);
	}
	else
		al_draw_circle(WIDTH - 30, HEIGHT - 30, 20.0, al_map_rgb(139, 35, 35), 2);
}
void DrawStats(ALLEGRO_FONT *font18, int x, int y, int FPS)
{
	//mouse position
	al_draw_textf(font18, al_map_rgb(255, 255, 255), 5, 5, ALLEGRO_ALIGN_LEFT, "x: %i  y: %i r: %i FPS: %i", x, y, (WIDTH - 30 - x)*(WIDTH - 30 - x) + (HEIGHT - 30 - y)*(HEIGHT - 30 - y), FPS);
}
void InitGame(Card karta[30], Card karta_enemy[30], Player *gracz1, Player *gracz2)
{
	srand(time(NULL));
	for (int i = 0; i < 30; i++)
	{
		karta[i].ID = i;
		if (i == 3 || i == 5)
			karta[i].used = true;
		else
			karta[i].used = false;
		karta[i].inGame = false;

		karta[i].inHand = false;
		karta[i].onTable = false;
		karta[i].selected = false;
		karta[i].atk = rand() % 5 + 1;
		karta[i].def = rand() % 5 + 1;
		karta[i].manaCost = (karta[i].atk + karta[i].def) / 2;
		karta[i].active = false;
		karta[i].golden = false;

	}
	for (int i = 0; i < 30; i++)
	{
		karta_enemy[i].ID = i;
		if (i == 3 || i == 5)
			karta_enemy[i].used = true;
		else
			karta_enemy[i].used = false;
		karta_enemy[i].inGame = false;
		karta_enemy[i].inHand = false;
		karta_enemy[i].onTable = false;
		karta_enemy[i].selected = false;
		karta_enemy[i].atk = rand() % 5 + 1;
		karta_enemy[i].def = rand() % 5 + 1;
		karta_enemy[i].manaCost = (karta_enemy[i].atk + karta_enemy[i].def) / 2;
		karta_enemy[i].active = false;
		karta_enemy[i].golden = false;

	}
	karta[rand() % 30].golden = true;
	karta_enemy[rand() % 30].golden = true;
	gracz1->ID = 1;
	gracz1->hp = 30;
	gracz1->max_mana = 1;
	gracz1->mana = gracz1->max_mana;
	gracz1->cardsInHand = 4;
	gracz2->ID = 2;
	gracz2->hp = 30;
	gracz2->max_mana = 1;
	gracz2->mana = gracz2->max_mana;
	gracz2->cardsInHand = 3;
}
void MoveCard(int x, int y, Card karta[30])
{
	for (int i = 0; i < 30; i++)
	{
		if (x>karta[i].pos_x && x<karta[i].pos_x + 90 && y>karta[i].pos_y && y < karta[i].pos_y + 150)
		{
			karta[i].pos_x = x - 45;
			karta[i].pos_y = y - 75;
		}
	}
}
void dodaj_do_listy_z_prawej(struct Table *lista, int liczba)
{
	struct Table *wsk, *nowy;
	wsk = lista;
	while (wsk->next != NULL)          /* 1 */
	{
		wsk = wsk->next; /* przesuwamy wsk a¿ znajdziemy ostatni element */
	}
	nowy = (struct Table*)malloc(sizeof(Table));  /* 2 */
	nowy->cardID = liczba;                /* 3 */
	nowy->prev = wsk;
	nowy->next = NULL;                 /* 4 */
	wsk->next = nowy;                  /* 5 */
}
void usun_z_listy(struct Table **lista, Player *gracz, Card karta[30], int cardID, int pos_x)
{
	//struct Table *wsk;
	//wsk = lista;
	//while (wsk->next != NULL)          /* 1 */
	//{
	//	wsk = wsk->next; /* przesuwamy wsk a¿ znajdziemy ostatni element */
	//}
	//
	//(wsk->prev)->next = NULL;
	//free(wsk);            /* 5 */

	int cardOnTable = cardsOnTable(gracz->myTable);
	if (cardOnTable == 1)
	{
		//karta[cardID].pos_x = 467;
		//karta[cardID].pos_y = 360;
		//gracz->myTable = (struct Table*) malloc(sizeof(Table));
		//gracz->myTable->cardID = cardID;
		//gracz->myTable->next = NULL;
		//gracz->myTable->prev = NULL;
		*lista = NULL;
	}
	else
	{
		//int pos = 1;
		struct Table *wsk;
		wsk = gracz->myTable;
		while (wsk != NULL)
		{
			if (pos_x < karta[wsk->cardID].pos_x + 90 && wsk->prev == NULL)
			{
				//dodaj_do_listy_z_lewej(&(gracz->myTable), cardID);
				wsk->next->prev = NULL;
				gracz->myTable = wsk->next;
				free(wsk);
				break;
			}
			if (wsk->next != NULL)
			if (pos_x >= karta[wsk->cardID].pos_x && pos_x < karta[wsk->cardID].pos_x + 90)
			{
				//dodaj_do_listy_w_srodek(gracz->myTable, cardID, pos);
				wsk->prev->next = wsk->next;
				wsk->next->prev = wsk->prev;
				free(wsk);
				break;
			}
			if (pos_x >= karta[wsk->cardID].pos_x  && wsk->next == NULL)
			{
				//dodaj_do_listy_z_prawej(gracz->myTable, cardID);
				wsk->prev->next = NULL;
				free(wsk);
				break;
			}
			else
				wsk = wsk->next;
			//pos++;
		}
		wsk = gracz->myTable;
		cardOnTable--;
		int k = 0;
		while (wsk != NULL)
		{
			if (cardOnTable % 2 == 0)
			{
				karta[wsk->cardID].pos_x = (WIDTH / 2) - (cardOnTable / 2 - 1) * 100 - 95 + (k * 100);
				//karta[wsk->cardID].pos_y = 360;
				k++;
				wsk = wsk->next;
			}
			else
			{
				karta[wsk->cardID].pos_x = (WIDTH / 2) - (cardOnTable / 2) * 100 - 45 + (k * 100);
				//karta[wsk->cardID].pos_y = 360;
				k++;
				wsk = wsk->next;
			}
		}
	}
	
}
void dodaj_do_listy_z_lewej(Table **lista, int liczba)
{
	struct Table *wsk, *nowy;
	wsk = *lista;
	while (wsk->prev != NULL)          /* 1 */
	{
		wsk = wsk->prev; /* przesuwamy wsk a¿ znajdziemy ostatni element */
	}
	nowy = (struct Table*)malloc(sizeof(Table));  /* 2 */
	nowy->cardID = liczba;
	nowy->next = wsk;					/* 3 */
	nowy->prev = NULL;                 /* 4 */
	wsk->prev = nowy;
	*lista = nowy;/* 5 */
}
void dodaj_do_listy_w_srodek(struct Table *lista, int liczba, int pos)
{
	int current = 0;
	struct Table *wsk, *wsk_n, *nowy;
	wsk = lista;
	while (wsk->next != NULL && (pos - 1) != current)          /* 1 */
	{
		current++;
		wsk = wsk->next; /* przesuwamy wsk a¿ znajdziemy ostatni element */
	}
	wsk_n = wsk->next;
	nowy = (struct Table*)malloc(sizeof(Table));  /* 2 */
	nowy->cardID = liczba;                /* 3 */
	nowy->next = wsk_n;
	nowy->prev = wsk;                 /* 4 */
	wsk->next = nowy;
	wsk_n->prev = nowy;				/* 5 */
}
int cardsOnTable(struct Table *lista)
{
	int cardsOnTable = 0;
	struct Table *wsk = lista;          /* 1 */
	if (wsk != NULL)
	{
		cardsOnTable++;
		while (wsk->next != NULL)          /* 2 */
		{
			cardsOnTable++; /* 3 */
			wsk = wsk->next;            /* 4 */
		}
	}
	return cardsOnTable;
}
void putCard(Player *gracz, Card karta[30], int cardID, int pos_x)
{
	int cardOnTable = cardsOnTable(gracz->myTable);
	if (cardOnTable < 1)
	{
		karta[cardID].pos_x = 467;
		karta[cardID].pos_y = 360;
		gracz->myTable = (struct Table*) malloc(sizeof(Table));
		gracz->myTable->cardID = cardID;
		gracz->myTable->next = NULL;
		gracz->myTable->prev = NULL;
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			if (i == 0)
			{
				int pos = 1;
				struct Table *wsk;
				wsk = gracz->myTable;
				while (wsk != NULL)
				{
					if (pos_x < karta[wsk->cardID].pos_x + 45 && wsk->prev == NULL)
					{
						dodaj_do_listy_z_lewej(&(gracz->myTable), cardID);
						break;
					}
					if (wsk->next != NULL)
					if (pos_x >=karta[wsk->cardID].pos_x + 45 && pos_x < karta[wsk->next->cardID].pos_x + 45)
					{
						dodaj_do_listy_w_srodek(gracz->myTable, cardID, pos);
						break;
					}
					if (pos_x >=karta[wsk->cardID].pos_x + 45 && wsk->next == NULL)
					{
						dodaj_do_listy_z_prawej(gracz->myTable, cardID);
						break;
					}
					else
						wsk = wsk->next;
					pos++;
				}
			}
			else
			{
				int k = 0;
				struct Table *wsk;
				wsk = gracz->myTable;
				cardOnTable++;
				while (wsk != NULL)
				{
					if (cardOnTable % 2 == 0)
					{
						karta[wsk->cardID].pos_x = (WIDTH / 2) - (cardOnTable / 2 - 1) * 100 - 95 + (k * 100);
						karta[wsk->cardID].pos_y = 360;
						k++;
						wsk = wsk->next;
					}
					else
					{
						karta[wsk->cardID].pos_x = (WIDTH / 2) - (cardOnTable / 2) * 100 - 45 + (k * 100);
						karta[wsk->cardID].pos_y = 360;
						k++;
						wsk = wsk->next;
					}
				}
			}
		}
	}
}
void endTurns(ALLEGRO_FONT *font18, Player *gracz1)
{
	if (gracz1->ID==1)
		al_draw_textf(font18, al_map_rgb(255, 0, 0), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTRE, "Tura gracza drugiego");
	else
		al_draw_textf(font18, al_map_rgb(255, 0, 0), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, "Tura gracza pierwszego");
	al_draw_rectangle(WIDTH / 4 - 100, HEIGHT / 2 - 50, WIDTH / 4 + 100, HEIGHT / 2 + 50, al_map_rgb(255, 255, 255), 2);
}
void flipCards(Card karta[30], Card karta_enemy[30])
{
	for (int i = 0; i < 30; i++)
	{
		if (karta[i].pos_y>1 && karta[i].inGame)
			karta[i].pos_y = 700 - karta[i].pos_y;
		if (karta_enemy[i].pos_y>1 && karta_enemy[i].inGame)
			karta_enemy[i].pos_y = 700 - karta_enemy[i].pos_y;
	}

}
void drawArrow(int x, int y, Card karta[30], Card karta_enemy[30])
{
	for (int i = 0; i < 30; i++)
	{
		if (karta[i].selected)
		{
			for (int j = 0; j<30; j++)
			{
				if (x>karta_enemy[j].pos_x && x<karta_enemy[j].pos_x + 90 && y<karta_enemy[j].pos_y && y > karta_enemy[j].pos_y - 150 && karta_enemy[j].onTable)
				{
					al_draw_rectangle(karta_enemy[j].pos_x, karta_enemy[j].pos_y, karta_enemy[j].pos_x + 90, karta_enemy[j].pos_y - 150, al_map_rgb(255, 0, 0), 3);
				}
				if (x>30 && x<130 && y>80 && y<180)
				{
					al_draw_rectangle(30, 80, 130, 180, al_map_rgb(255, 0, 0), 3);
				}
			}
		}
		if (karta[i].selected && y<karta[i].pos_y+75)
		{
			al_draw_line(karta[i].pos_x + 45, karta[i].pos_y + 75, x, y, al_map_rgb(255, 0, 0), 2);
			al_draw_line(x, y, x, y + 10, al_map_rgb(255, 0, 0), 2);
			if (karta[i].pos_x+45<x)
				al_draw_line(x, y, x - 10, y, al_map_rgb(255, 0, 0), 2);
			else
				al_draw_line(x, y, x + 10, y, al_map_rgb(255, 0, 0), 2);
		}
	}
}
void activateCards(Card karta[30])
{
	for (int i = 0; i < 30; i++)
	{
		if (karta[i].onTable)
		{
			karta[i].active = true;
		}
	}
}
void deactivateCard(Card karta[30], int cardID)
{
	karta[cardID].active = false;
}