int hashFunction(const std::string& key) const {
    int hash = 0;
    for (char ch : key) {
        hash += static_cast<int>(ch);
    }
    return hash % TABLE_SIZE;  // Restituisce l'indice iniziale
}

int findSlot(int currentIndex) const {
    int index = currentIndex;
    
    // Probing lineare: cerchiamo un slot libero
    while (table[index] != nullptr) {
        index = (index + 1) % TABLE_SIZE;  // Aumentiamo l'indice linearmente
    }
    
    return index;
}
