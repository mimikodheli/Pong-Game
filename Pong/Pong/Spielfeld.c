#include "Spielfeld.h"
#include "Position.h"
#include "Console.h"
#include "Configuration.h"
//Initialisiert die Struktur mit den in Configuration.h hinterlegten Werten.
void spielfeld_init(struct Spielfeld* sf_ptr)
{
	sf_ptr->offset_x = SPIELFELD_OFFSET_X;
	sf_ptr->offset_y = SPIELFELD_OFFSET_Y;
	sf_ptr->symbol_grenze = SPIELFELD_SYMBOL_GRENZE;
	sf_ptr->symbol_mittel = SPIELFELD_SYMBOL_MITTEL;
	sf_ptr->xsize = SPIELFELD_XSIZE;
	sf_ptr->ysize = SPIELFELD_YSIZE;

}
//Zeichnet die Spielfeldumrandung mit dem Vorgegebenen Offset (siehe Abbildung)
//unter Verwendung der Funktion cursor_zeichne_punkt
void spielfeld_zeichne_grenze(const struct Spielfeld* sf_ptr)
{
	for (int y = sf_ptr->offset_y; y < sf_ptr->ysize + sf_ptr->offset_y; y++)	
	{
		for (int x = sf_ptr->offset_x; x < sf_ptr->xsize + sf_ptr->offset_x; x++)
		{
			if ((x == sf_ptr->offset_x) || (y == sf_ptr->offset_y) || (x == sf_ptr->xsize + sf_ptr->offset_x - 1) || (y == sf_ptr->ysize + sf_ptr->offset_y - 1 ))
			{
				cursor_zeichne_punkt(x, y, sf_ptr->symbol_grenze);
			}
		}
	}
}
//Zeichnet die Mittellinie (siehe Abbildung) unter Verwendung der Funktion
//cursor_zeichne_punkt
void spielfeld_zeichne_mittellinie(const struct Spielfeld* sf_ptr)
{

	for (int y = sf_ptr->offset_y + 1; y < sf_ptr->ysize + sf_ptr->offset_y - 1; y++)
	{
		cursor_zeichne_punkt(sf_ptr->offset_x + (sf_ptr->xsize / 2), y, sf_ptr->symbol_mittel);
	}

}
//Zeichnet das Spielfeld mittels Aufruf von spielfeld_zeichne_grenze und
//spielfeld_zeichne_mittellinie
void spielfeld_zeichnen(struct Spielfeld* sf_ptr)
{
	spielfeld_zeichne_grenze(sf_ptr);
	spielfeld_zeichne_mittellinie(sf_ptr);

}