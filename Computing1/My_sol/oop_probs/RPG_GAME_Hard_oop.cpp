/*
Multiple inheritance with pure virtual “interfaces” (IEquippable, IConsumable).
A base class Item (abstract) that holds shared data (ItemID, name) and a pure virtual printStats().
Derived classes (Weapon, Potion) that override methods and also implement optional interfaces (IEquippable, IConsumable).
A typedef (or using) for numeric types like Money or ItemID.
A Shop that stores various items for sale, each with a price.
A Champion class that can buy items (polymorphic) from the shop, store them in an Inventory, and can equip or consume them if they implement the corresponding interface. We use dynamic_cast to detect at runtime if an item is equippable/consumable.
A main function with simple test cases to illustrate the workflow.

This demonstrates complex OOP topics: multiple inheritance (for interface-like classes), typedef/using, function overriding, virtual destructors, runtime checks (dynamic_cast), containers of polymorphic objects, etc.
*/
/**************************************************************
 * RPG_Inventory_Shop.cpp
 *
 * Demonstrates an advanced OOP scenario in C++:
 * - Multiple inheritance for interfaces (IEquippable, IConsumable)
 * - An abstract base class Item
 * - Derived classes Weapon (equippable), Potion (consumable)
 * - A Shop that sells items (polymorphic), each at a certain price
 * - A Champion who has gold, an Inventory of items, and can buy/equip/consume
 * - typedef (or using) for advanced type usage (Money, ItemID)
 **************************************************************/

 #include <iostream>
 #include <string>
 #include <vector>
 #include <memory>
 #include <unordered_map>
 #include <stdexcept>
 #include <iomanip>
 #include <algorithm>
 
 //=============================================================
 // 1) Useful typedefs / using
 //=============================================================
 using Money = unsigned int;   // currency type
 using ItemID = unsigned int;  // item unique ID
 
 //=============================================================
 // 2) Interface: IEquippable
 //    A purely abstract class representing "equip" behavior
 //=============================================================
 class IEquippable {
 public:
     virtual ~IEquippable() {} 
     virtual void equip() = 0;
     virtual void unequip() = 0;
 };
 
 //=============================================================
 // 3) Interface: IConsumable
 //    A purely abstract class representing "consume" behavior
 //=============================================================
 class IConsumable {
 public:
     virtual ~IConsumable() {}
     virtual void consume() = 0;
 };
 
 //=============================================================
 // 4) Base class: Item (abstract)
 //    All items have an ID, name. They can be "printStats()"
 //=============================================================
 class Item {
 protected:
     ItemID id;
     std::string name;
 
 public:
     Item(ItemID i, const std::string& n)
         : id(i), name(n) {}
 
     virtual ~Item() {}
 
     ItemID getID() const { return id; }
     const std::string& getName() const { return name; }
 
     // A pure virtual function to display item-specific stats
     virtual void printStats() const = 0;
 };
 
 //=============================================================
 // 5) Derived class: Weapon
 //    - Inherits from Item
 //    - Also implements IEquippable
 //=============================================================
 class Weapon : public Item, public IEquippable {
 private:
     int attackPower;
     bool equipped;
 
 public:
     Weapon(ItemID i, const std::string& n, int atk)
         : Item(i,n), attackPower(atk), equipped(false)
     {}
 
     // Overriding the pure virtual from Item
     void printStats() const override {
         std::cout << "Weapon [ID=" << id << ", Name=" << name
                   << ", Attack=" << attackPower
                   << (equipped ? ", (Equipped)" : ", (Not equipped)")
                   << "]\n";
     }
 
     // IEquippable interface
     void equip() override {
         if(!equipped) {
             equipped = true;
             std::cout << name << " is now equipped!\n";
         } else {
             std::cout << name << " is already equipped.\n";
         }
     }
 
     void unequip() override {
         if(equipped) {
             equipped = false;
             std::cout << name << " is now unequipped.\n";
         } else {
             std::cout << name << " is not currently equipped.\n";
         }
     }
 };
 
 //=============================================================
 // 6) Derived class: Potion
 //    - Inherits from Item
 //    - Also implements IConsumable
 //=============================================================
 class Potion : public Item, public IConsumable {
 private:
     int healingAmount;
     bool consumed;
 
 public:
     Potion(ItemID i, const std::string& n, int heal)
         : Item(i,n), healingAmount(heal), consumed(false)
     {}
 
     void printStats() const override {
         std::cout << "Potion [ID=" << id << ", Name=" << name
                   << ", Healing=" << healingAmount
                   << (consumed ? ", (Consumed)" : "")
                   << "]\n";
     }
 
     // IConsumable interface
     void consume() override {
         if(!consumed) {
             consumed = true;
             std::cout << name << " potion is consumed. Heal for "
                       << healingAmount << " HP!\n";
         } else {
             std::cout << name << " potion has already been consumed.\n";
         }
     }
 };
 
 //=============================================================
 // 7) Shop
 //    - Holds a collection of items for sale, each with a price
 //    - Allows purchasing an item by ID
 //=============================================================
 class Shop {
 private:
     // We'll store items in a map: itemID -> (unique_ptr<Item>, price)
     struct ShopItem {
         std::unique_ptr<Item> item;
         Money price;
     };
     std::unordered_map<ItemID, ShopItem> catalog;
 
 public:
     // Add an item to the shop with a given price
     void addItem(std::unique_ptr<Item> it, Money cost) {
         ItemID i = it->getID();
         // move item into the ShopItem
         catalog[i] = { std::move(it), cost };
     }
 
     // Display all items with their prices
     void listAll() const {
         std::cout << "\n=== Shop Catalog ===\n";
         for(const auto& kv : catalog) {
             ItemID i = kv.first;
             const ShopItem& si = kv.second;
             std::cout << "ItemID=" << i
                       << ", Price=" << si.price << " => ";
             si.item->printStats();
         }
     }
 
     // Attempt to buy an item (returns ownership if successful, or nullptr)
     std::unique_ptr<Item> buyItem(ItemID i, Money buyerGold, Money& costOut) {
         auto it = catalog.find(i);
         if(it == catalog.end()) {
             std::cerr << "Shop: No item with ID=" << i << "\n";
             return nullptr;
         }
         ShopItem &si = it->second;
         if(buyerGold < si.price) {
             std::cerr << "Shop: Not enough gold to buy " << si.item->getName() << "\n";
             return nullptr;
         }
         // Transaction success:
         costOut = si.price;
         // move the item out of the shop
         std::unique_ptr<Item> purchased = std::move(si.item);
         // remove from catalog
         catalog.erase(it);
         return purchased;
     }
 };
 
 //=============================================================
 // 8) Champion
 //    - Has gold, an inventory of items
 //    - Can buy from shop, equip items if IEquippable, consume if IConsumable
 //=============================================================
 class Champion {
 private:
     std::string name;
     Money gold;
     // Owned items
     std::vector<std::unique_ptr<Item>> inventory;
 
 public:
     Champion(const std::string& n, Money g)
         : name(n), gold(g) {}
 
     void printStatus() const {
         std::cout << "\nChampion: " << name << ", Gold=" << gold << "\n";
         std::cout << "Inventory:\n";
         for(const auto &it : inventory) {
             it->printStats();
         }
     }
 
     // Buy an item from the shop
     void buyItem(Shop& shop, ItemID id) {
         Money cost=0;
         std::unique_ptr<Item> purchased = shop.buyItem(id, gold, cost);
         if(purchased) {
             // pay gold
             gold -= cost;
             // add to inventory
             inventory.push_back(std::move(purchased));
             std::cout << name << " bought item (ID=" << id
                       << ") for " << cost << " gold\n";
         }
     }
 
     // Attempt to equip an item from inventory if it implements IEquippable
     void equipItem(ItemID id) {
         for(auto &it : inventory) {
             if(it->getID() == id) {
                 // try dynamic_cast to IEquippable
                 IEquippable* eq = dynamic_cast<IEquippable*>(it.get());
                 if(eq) {
                     eq->equip();
                 } else {
                     std::cout << "Item " << it->getName() << " is not equippable.\n";
                 }
                 return;
             }
         }
         std::cout << "No item with ID=" << id << " in inventory.\n";
     }
 
     // Attempt to consume an item from inventory if it implements IConsumable
     void consumeItem(ItemID id) {
         for(auto &it : inventory) {
             if(it->getID() == id) {
                 // try dynamic_cast to IConsumable
                 IConsumable* c = dynamic_cast<IConsumable*>(it.get());
                 if(c) {
                     c->consume();
                 } else {
                     std::cout << "Item " << it->getName() << " is not consumable.\n";
                 }
                 return;
             }
         }
         std::cout << "No item with ID=" << id << " in inventory.\n";
     }
 };
 
 //=============================================================
 // 9) Main - Demo usage
 //=============================================================
 int main(){
     // 1) Create a shop
     Shop shop;
 
     // 2) Populate shop with items
     // Using ItemID as we want (unique, e.g. 1001, 1002,...)
     auto sword = std::make_unique<Weapon>(1001, "Steel Sword", 15);
     auto potionHp = std::make_unique<Potion>(1002, "Health Potion", 50);
     auto bigSword = std::make_unique<Weapon>(1003, "Buster Sword", 30);
     auto megaPotion = std::make_unique<Potion>(1004, "Mega Potion", 200);
 
     // add them with different prices
     shop.addItem(std::move(sword), 100);
     shop.addItem(std::move(potionHp), 35);
     shop.addItem(std::move(bigSword), 300);
     shop.addItem(std::move(megaPotion), 120);
 
     // show shop
     shop.listAll();
 
     // 3) Create champion
     Champion hero("Arthur", 200);
 
     // 4) Try to buy some items
     hero.buyItem(shop, 1001); // sword
     hero.buyItem(shop, 1002); // potion
     // Attempt a too-expensive item
     hero.buyItem(shop, 1003); // bigSword => not enough gold ?
 
     // print champion status
     hero.printStatus();
 
     // 5) Equip the sword
     hero.equipItem(1001);
 
     // 6) Consume the potion
     hero.consumeItem(1002);
 
     // 7) Print final
     std::cout << "\n--- Final Status ---\n";
     hero.printStatus();
     shop.listAll(); // what's left in the shop?
 
     return 0;
 }
 