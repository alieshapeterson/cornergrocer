#include "GroceryItem.h"

// Default constructor
GroceryItem::GroceryItem()
    : itemName(""), quantity(0)
{
    // No additional logic needed
}

// Constructor that sets name and quantity
GroceryItem::GroceryItem(const std::string& name, int qty)
    : itemName(name), quantity(qty)
{
    // Initialized with provided values
}

// Get the item name
std::string GroceryItem::getName() const
{
    return itemName;
}

// Get the item quantity
int GroceryItem::getQuantity() const
{
    return quantity;
}

// Set a new item name
void GroceryItem::setName(const std::string& name)
{
    itemName = name;
}

// Set a new item quantity
void GroceryItem::setQuantity(int qty)
{
    quantity = qty;
}

// Increase quantity by 1
void GroceryItem::incrementQuantity()
{
    ++quantity;  // Increment existing quantity
}