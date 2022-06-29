#include "Configuration.h"
#include "Console.h"
#include "Spiel.h"

int main(int argc, char* argv[])
{
	
	system("pause");
	console_init();
	struct Spiel* spiel_ptr = spiel_erzeugen();
	spiel_zeichnen(spiel_ptr);
	run(spiel_ptr);
}