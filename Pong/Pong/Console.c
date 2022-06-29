#include <stdio.h>

//Leere Terminal
void console_leeren()
{
	printf("\33[2J");
}
//Verstecke Cursor
void cursor_verstecken()
{
	printf("\33[?25l");
}
//Leere Bildschirm, verstecke Cursor, Position 0,0
void console_init()
{
	console_leeren();
	cursor_verstecken();
}
void cursor_zeigen()
{
	printf("\33[?25h");
}
//Positioniere Cursor an Position x,y
void cursor_bewegen(int x, int y)
{
	printf("\33[%d;%dH", y, x);//\033[<L>; <C>f

}
//Zeichne Zeichen c an Position x, y
void cursor_zeichne_punkt(int x, int y, char c)
{
	printf("\33[%d;%dH%c", y, x, c);
}
// Bewege Cursor um n Stellen nach oben:
void cursor_hoch(int n)
{
	printf("\033[%dA", n);
}
//Bewege Cursor um n Stellen nach unten: \033[<N>B
void cursor_runter(int n)
{
	printf("\033[%dB", n);
}
//Bewege Cursor um n Stellen/Spalten nach rechts: \033[<N>C
void cursor_rechts(int n)
{
	printf("\033[%dC", n);
}
//Bewege Cursor um n Stellen/Spalten nach links: \033[<N>D
void cursor_links(int n)
{
	printf("\033[%dD", n);
}
//Setze Cursor-Farbe
void cursor_setze_Farbe(const char* farbe)
{
	printf(farbe);
}
//Speichert die aktuelle Cursor Position
void cursor_speicherePosition()
{
	printf("\033[s");
}
//Stellt die gespeicherte Cursor Position wieder her
void cursor_gehezu_letzteGespeichertePosition()
{
	printf("\033[u");
}