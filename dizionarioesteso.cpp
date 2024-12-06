#include <iostream>
#include <string>

template <typename T>
class DizionarioEsteso {
private:
    static const int TABLE_SIZE = 100; // Dimensione fissa della tabella hash
    struct Entry {
        std::string key;
        T value;
        bool isOccupied = false;
    };

    Entry table[TABLE_SIZE];

    // Funzione hash di base
    int hashFunction(const std::string key) const {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % TABLE_SIZE; // Algoritmo di hashing semplice
        }
        return hash;
    }

public:
    // aggiungere una coppia chiave-valore
    void inserisci(const std::string key, const T value) {
        int index = hashFunction(key);

        if (table[index].isOccupied) {
            std::cerr << "Collision detected for key: " << key << " at index " << index << ". Not handling collisions.\n";
            return;
        }

        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
    }

    // ottenere il valore associato a una chiave
    T recupera(const std::string key) const {
        int index = hashFunction(key);

        if (table[index].isOccupied && table[index].key == key) {
            return table[index].value;
        }

        return "Key not found!";
    }

    // verifica se una chiave è presente nel dizionario
    bool appartiene(const std::string key) const {
        int index = hashFunction(key);
        
        // Se esiste e la cella è occupata, ritorna true
        return table[index].isOccupied && table[index].key == key;
    }

    // rimuove una coppia chiave-valore
    bool cancella(const std::string key) {
        int index = hashFunction(key);

        // Se la trova e la cella è occupata, rimuovi la coppia
        if (table[index].isOccupied && table[index].key == key) {
            table[index].isOccupied = false;
            return true;
        }

        return false; // La chiave non esiste
    }

    // stampa il contenuto del dizionario
    void stampa() const {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].isOccupied) {
                std::cout << "Index " << i << ": " << table[i].key << " => " << table[i].value << "\n";
            }
        }
    }
};
