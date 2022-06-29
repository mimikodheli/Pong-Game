#include <stdio.h>
#include <stdlib.h>

#include "Punktestand.h"

void punktestand_init(struct Punktestand* punktestand_ptr)
{
	punktestand_ptr->position.p_x = PUNKTSTAND_XPOS;
	punktestand_ptr->position.p_y = PUNKTSTAND_YPOS;
	punktestand_ptr->punkte_spieler1 = 0;
	punktestand_ptr->punkte_spieler2 = 0;
}
void digit_ausgabe(int nummer)
{
	int zahlgroesse = 5;
	char zahlen[12][5 * 5] = {

						{	' ','*','*','*',' ',
							' ','*',' ','*',' ',
							' ','*',' ','*',' ',
							' ','*',' ','*',' ',
							' ','*','*','*',' ', },// 0

						{	' ',' ',' ','*',' ',
							' ',' ','*','*',' ',
							' ','*',' ','*',' ',
							' ',' ',' ','*',' ',
							' ',' ','*','*','*', }, // 1

						{	' ','*','*','*',' ',
							' ',' ',' ','*',' ',
							' ','*','*','*',' ',
							' ','*',' ',' ', ' ',
							' ','*','*','*',' ',}, // 2

						{	' ','*','*','*',' ',
							' ',' ',' ','*',' ',
							' ','*','*','*',' ',
							' ',' ',' ','*',' ',
							' ','*','*','*',' ',}, // 3

						{	' ','*',' ','*',' ',
							' ','*',' ','*',' ',
							' ','*','*','*',' ',
							' ',' ',' ','*',' ',
							' ',' ',' ','*',' ',}, // 4

						{	' ','*','*','*',' ',
							' ','*',' ',' ',' ',
							' ','*','*','*',' ',
							' ',' ',' ','*',' ',
							' ','*','*','*',' ',}, // 5

						{	' ','*','*','*',' ',
							' ','*',' ',' ',' ',
							' ','*','*','*',' ',
							' ','*',' ','*',' ',
							' ','*','*','*',' ',}, // 6

						{	'*','*','*','*','*',
							' ',' ',' ','*',' ',
							' ',' ','*',' ',' ',
							' ','*',' ',' ',' ',
							'*',' ',' ',' ',' ',}, // 7

						{	' ','*','*','*',' ',
							' ','*',' ','*',' ',
							' ','*','*','*',' ',
							' ','*',' ','*',' ',
							' ','*','*','*',' ',}, // 8

						{	' ','*','*','*',' ',
							' ','*',' ','*',' ',
							' ','*','*','*',' ',
							' ',' ',' ','*', ' ',
							' ','*','*','*',' ',},// 9
							
						{	' ',' ','*','*',' ',
							' ',' ','*','*',' ',
							' ',' ',' ',' ',' ',
							' ',' ','*','*',' ',
							' ',' ','*','*',' ',}, // :

						{	' ',' ',' ',' ',' ',
							' ',' ',' ',' ',' ',
							' ',' ',' ',' ',' ',
							' ',' ',' ',' ',' ',
							' ',' ',' ',' ',' ',} }; // Leer

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			printf("%c", zahlen[nummer][x * 5 + y]);
		}
		cursor_runter(1);
		cursor_links(5);
	}
}
void punktestand_zeichnen(struct Punktestand* p_ptr)
{
	cursor_bewegen(p_ptr->position.p_x, p_ptr->position.p_y);
	digit_ausgabe(p_ptr->punkte_spieler1);
	cursor_bewegen(p_ptr->position.p_x + 5, p_ptr->position.p_y);
	digit_ausgabe(10);
	cursor_bewegen(p_ptr->position.p_x + 10, p_ptr->position.p_y);
	digit_ausgabe(p_ptr->punkte_spieler2);
}