#include <iostream>
#include "dizionarioesteso.cpp"

int main() {
    // Creiamo un dizionario 
    DizionarioEsteso<int> dizionario;

    // Aggiungi coppie chiave-valore
    dizionario.inserisci("D550", 10);
    dizionario.inserisci("gigio", 20);
    dizionario.inserisci("macchina", 30);

    // Stampa il dizionario 
    std::cout << "Contenuto del dizionario dopo gli inserimenti:\n";
    dizionario.stampa();

    // Aggiungi un caso di collisione
    dizionario.inserisci("5D50", 4); // Probabile collisione con "D550"
    dizionario.inserisci("ggiio", 5); // Probabile collisione con "gigio"
    
    // dizionario dopo le collisioni
    std::cout << "\nContenuto del dizionario dopo aggiunta delle voci con collisioni:\n";
    dizionario.stampa();

    // valore associato alla chiave "gigio"
    std::cout << "\nValore associato a 'gigio': " << dizionario.recupera("gigio") << "\n";
    std::cout << "Valore associato a '5D50': " << dizionario.recupera("5D50") << "\n";

    // Verifica se una chiave esiste
    if (dizionario.appartiene("D550")) {
        std::cout << "'D550' è presente nel dizionario.\n";
    }
    if (!dizionario.appartiene("giovanni")) {
        std::cout << "'giovanni' non è presente nel dizionario.\n";
    }

    // Rimuovi una coppia
    if (dizionario.cancella("gigio")) {
        std::cout << "'gigio' è stato rimosso dal dizionario.\n";
    } else {
        std::cout << "'gigio' non è stato trovato nel dizionario.\n";
    }

    // Stampa il dizionario dopo la rimozione
    std::cout << "\nContenuto del dizionario dopo la rimozione di 'gigio':\n";
    dizionario.stampa();

    // Rimuovi una chiave che non esiste
    if (!dizionario.cancella("giovanni")) {
        std::cout << "'giovanni' non esiste nel dizionario, impossibile rimuoverlo.\n";
    }

    // Stampa finale del dizionario
    std::cout << "\nSituazione finale del dizionario:\n";
    dizionario.stampa();

    return 0;
}
