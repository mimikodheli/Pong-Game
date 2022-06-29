#pragma once
#define CURSOR_SCHWARZ "\033[0;30m"
#define CURSOR_DUNKEL_GRAU "\033[1;30m"
#define CURSOR_WEISS "\033[1;37m"
#define CURSOR_ROT "\033[0;31m"
#define CURSOR_GRUEN "\033[0;32m"
#define CURSOR_BLAU "\033[0;34m"
#define CURSOR_CYAN "\033[0;36m"
#define CURSOR_LILA "\033[0;35m"
#define CURSOR_GELB "\033[1;33m"
#define CURSOR_BRAUN "\033[0;33m"
#define CURSOR_HELL_ROT "\033[1;31m"
#define CURSOR_HELL_GRUEN "\033[1;32m"
#define CURSOR_HELL_BLAU "\033[1;34m"
#define CURSOR_HELL_LILA "\033[1;35m"
#define CURSOR_HELL_CYAN "\033[1;36m"
#define CURSOR_HELL_GRAU "\033[0;37m"

void console_init(); //Leere Terminal, verstecke Cursor, Position 0,0

void console_leeren(); //Leere Terminal

void cursor_verstecken(); //Verstecke Cursor

void cursor_zeigen(); //Zeige Cursor

void cursor_zeichne_punkt(int x, int y, char c); //Zeichne Zeichen c an Position x, y

//Zeichnet eine Linie aus Zeichen c von Position x1, y1 nach Position x2, y2
void cursor_zeichne_linie(int x1, int y1, int x2, int y2, char c);

void cursor_bewegen(int x, int y); //Positioniere Cursor an Position x,y

void cursor_hoch(int n); //Bewege Cursor um n Stellen/Spalten nach oben \033[<N>A

void cursor_runter(int n); //Bewege Cursor um n Stellen/Spalten nach unten \033[<N>B

void cursor_rechts(int n); //Bewege Cursor um n Stellen/Spalten nach rechts \033[<N>C

void cursor_links(int n); //Bewege Cursor um n Stellen/Spalten nach links \033[<N>D

void cursor_setze_Farbe(const char* farbe); //Setze Cursor-Farbe

//Speichert die aktuelle Cursor Position
void cursor_speicherePosition(); //\033[s

//Stellt die gespeicherte Cursor Position wieder her
void cursor_gehezu_letzteGespeichertePosition(); //Restore cursor position : \033[u
