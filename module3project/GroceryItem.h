#pragma once
#include <string>

class GroceryItem {
private:
    std::string itemName;  // Name of the grocery item
    int quantity;          // How many of this item we have

public:
    // Default constructor
    // Sets itemName to empty and quantity to 0
    GroceryItem();

    // Constructor that sets name and quantity
    // @param name - the name of the grocery item
    // @param qty - how many items to start with (default is 1)
    GroceryItem(const std::string& name, int qty = 1);

    // Get the name of the item
    // @returns - the name as a string
    std::string getName() const;

    // Get the item quantity
    // @returns - the quantity as an int
    int getQuantity() const;

    // Change the name of the item
    // @param name - new name to use
    void setName(const std::string& name);

    // Change the quantity of the item
    // @param qty - new quantity to use
    void setQuantity(int qty);

    // Increase quantity by 1
    void incrementQuantity();
};