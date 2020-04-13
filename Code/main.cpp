
#include "GestionPort.h"
#include "Menu.h"

int main() {
     GestionPort port;
     port.import();
     Menu menu(port);
     menu.afficherMenu();
}
