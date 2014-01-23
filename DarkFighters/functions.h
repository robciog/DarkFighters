#ifndef functions_h
#define functions_h
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//GLOBALS==============================
const int WIDTH = 1024;
const int HEIGHT = 700;
const int NUM_BULLETS = 5;
const int NUM_COMETS = 10;
enum KYES{ UP, DOWN, LEFT, RIGHT, SPACE };
extern bool keys[5];

struct Card
{
	int ID;
	//description
	int pos_x = 1500;
	int pos_y = 1500;
	bool used;
	bool inGame;
	bool inHand;
	bool onTable;
	bool selected;
	bool active;
	int atk;
	int def;
	int manaCost;
	bool golden;
	bool taunt;
};
struct Globals
{
	bool game = false;
	bool endTurn = false;
	bool stats = false;
	bool selectedToAttack = false;
	int cardID = -1;
	bool gameMenu = false;
	bool pressed = false;
	int pos_x;
	int pos_y;
	bool newGame = false;
};
struct Player
{
	int ID;
	int hp;
	int mana;
	int max_mana;
	int cardsInGame;
	int cardsInHand;
	int cardInGame;
	struct Table *myTable;
};
struct Table
{
	struct Table *next, *prev;
	int cardID;
};

//extern Table *first;

//prototypes
void InitMenu(ALLEGRO_FONT *font18, ALLEGRO_FONT *fon40, int x, int y);
void GameMenu(ALLEGRO_FONT *font18, ALLEGRO_FONT *font40, int x, int y, Globals *globals);
void initEndMenu(ALLEGRO_FONT *font18, Player *gracz, Globals *globals);
void InitGame(Card karta[30], Card karta_enemy[30], Player *gracz1, Player *gracz2);
void CheckCards(Card karta[30], Player *gracz1, Player *gracz2);
//void DrawGame(ALLEGRO_FONT *font18, ALLEGRO_DISPLAY *display, int x, int y);
void DrawGame(ALLEGRO_FONT *font18, int x, int y, Card karta[30], Card karta_enemy[30], Player *gracz1, Player *gracz2, int cardID);
void DrawStats(ALLEGRO_FONT *font18, int x, int y, int FPS);
void MoveCard(int x, int y, Card karta[30]);
void dodaj_do_listy_z_prawej(struct Table *lista, int liczba);
void usun_z_listy(struct Table **lista, Player *gracz, Card karta[30], int cardID, int pos_x);
void dodaj_do_listy_z_lewej(Table **lista, int liczba);
void dodaj_do_listy_w_srodek(struct Table *lista, int liczba, int pos);
void putCard(Player *gracz, Card karta[30], int cardID, int pos_x);
int cardsOnTable(struct Table *lista);
void endTurns(ALLEGRO_FONT *font18, Player *gracz1);
void flipCards(Card karta[30], Card karta_enemy[30]);
void drawArrow(int x, int y, Card karta[30], Card karta_enemy[30]);
void activateCards(Card karta[30]);
void deactivateCard(Card karta[30], int cardID);
#endif