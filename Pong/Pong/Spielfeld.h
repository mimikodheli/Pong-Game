#ifndef SPIELFELD
#define SPIELFELD
struct Spielfeld
{
	char symbol_grenze;
	char symbol_mittel;
	int offset_y;
	int offset_x;
	int ysize;
	int xsize;
};
void spielfeld_init(struct Spielfeld* sf_ptr);
void spielfeld_zeichne_grenze(const struct Spielfeld* sf_ptr);
void spielfeld_zeichne_mittellinie(const struct Spielfeld* sf_ptr);
void spielfeld_zeichnen(struct Spielfeld* sf_ptr);
#endif

