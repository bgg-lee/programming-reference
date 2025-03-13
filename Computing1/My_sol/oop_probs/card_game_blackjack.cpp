/*
Create classes to represent cards (rank/suit), a deck that can be shuffled and dealt, and players that have different strategies. Or you can implement a partial Blackjack or Poker logic.
Requirements:
    Card class: rank, suit, a method to get value. Possibly an enum for suit (Clubs, Diamonds, Hearts, Spades), rank (2…Ace).
    Deck: has 52 Cards in a std::vector, plus shuffle(), dealCard().
    Player (abstract?) → maybe HumanPlayer, AIPlayer deriving from it if you want. Each has hand, a method takeCard(Card c), virtual bool decideDraw(...) const = 0; in Blackjack scenario, etc.
    Game: manages players, deck, dealing, scoring.
    Show usage in main(): shuffle deck, deal cards, etc.
OOP:
Possibly a pure virtual decideDraw() in Player, overridden by different strategies for an AI vs. a human prompt.
*/
/*********************************************************
 * CardGame.cpp
 * Demonstrates a simple card/deck system plus an 
 * abstract Player class (HumanPlayer, AIPlayer).
 *********************************************************/

 #include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <random>
 #include <memory>
 #include <ctime>
 
 //------------------------------------------------
 // 1) Enums for Suit, Rank
 //------------------------------------------------
 enum class Suit { Clubs, Diamonds, Hearts, Spades };
 enum class Rank {
     Two=2, Three, Four, Five, Six, Seven,
     Eight, Nine, Ten, Jack=11, Queen=12,
     King=13, Ace=14
 };
 
 std::string suitToString(Suit s) {
     switch(s) {
         case Suit::Clubs:    return "Clubs";
         case Suit::Diamonds: return "Diamonds";
         case Suit::Hearts:   return "Hearts";
         case Suit::Spades:   return "Spades";
     }
     return "Unknown";
 }
 
 std::string rankToString(Rank r) {
     if(r >= Rank::Two && r <= Rank::Ten) {
         return std::to_string(static_cast<int>(r));
     }
     switch(r) {
         case Rank::Jack:  return "Jack";
         case Rank::Queen: return "Queen";
         case Rank::King:  return "King";
         case Rank::Ace:   return "Ace";
         default: return "??";
     }
 }
 
 //------------------------------------------------
 // 2) Card class
 //------------------------------------------------
 class Card {
 private:
     Rank rank;
     Suit suit;
 
 public:
     Card(Rank r, Suit s) : rank(r), suit(s) {}
 
     Rank getRank() const { return rank; }
     Suit getSuit() const { return suit; }
 
     // for a game like Blackjack, you might define a value function.
     int valueForBlackjack() const {
         int rv = static_cast<int>(rank);
         if(rv >= 11 && rv <= 13) {
             // Jack, Queen, King => 10
             return 10;
         } else if(rv == 14) {
             // Ace => 11 or 1, let's choose 11 for simplicity
             return 11;
         }
         return rv; // 2..10
     }
 
     std::string toString() const {
         return rankToString(rank) + " of " + suitToString(suit);
     }
 };
 
 //------------------------------------------------
 // 3) Deck class
 //------------------------------------------------
 class Deck {
 private:
     std::vector<Card> cards;
     int index; // next card to deal
 
 public:
     Deck() {
         // fill with 52 cards
         for(int s=0; s<4; s++){
             for(int r=2; r<=14; r++){
                 cards.emplace_back(static_cast<Rank>(r), static_cast<Suit>(s));
             }
         }
         index = 0;
     }
 
     void shuffle() {
         static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
         std::shuffle(cards.begin(), cards.end(), rng);
         index = 0;
     }
 
     bool empty() const {
         return (index >= (int)cards.size());
     }
 
     Card dealOne() {
         if(empty()) {
             throw std::runtime_error("No more cards in deck");
         }
         return cards[index++];
     }
 };
 
 //------------------------------------------------
 // 4) Abstract Base: Player
 //------------------------------------------------
 class Player {
 protected:
     std::string name;
     std::vector<Card> hand;
 
 public:
     Player(const std::string& n) : name(n) {}
     virtual ~Player() {}
 
     void takeCard(const Card& c) {
         hand.push_back(c);
     }
 
     virtual bool decideDraw(const Deck& deck) const = 0;
 
     virtual void printStatus() const {
         std::cout << name << "'s hand:\n";
         for(auto &c : hand){
             std::cout << "  " << c.toString() << "\n";
         }
     }
 
     std::string getName() const { return name; }
 };
 
 //------------------------------------------------
 // 5) Derived: HumanPlayer
 //------------------------------------------------
 class HumanPlayer : public Player {
 public:
     HumanPlayer(const std::string& n)
         : Player(n) {}
 
     bool decideDraw(const Deck& deck) const override {
         if(deck.empty()) return false;
 
         // For simplicity, auto-choose or prompt user. We'll just do a prompt:
         char choice;
         std::cout << name << ", draw a card? (y/n): ";
         std::cin >> choice;
         return (choice == 'y' || choice == 'Y');
     }
 };
 
 //------------------------------------------------
 // 6) Derived: AIPlayer
 //------------------------------------------------
 class AIPlayer : public Player {
 public:
     AIPlayer(const std::string& n)
         : Player(n) {}
 
     bool decideDraw(const Deck& deck) const override {
         if(deck.empty()) return false;
         // simple AI: if hand total < 15 (Blackjack style?), draw
         int total = 0;
         for(auto &c : hand){
             total += c.valueForBlackjack();
         }
         return (total < 15);
     }
 };
 
 //------------------------------------------------
 // 7) main() - minimal demonstration
 //------------------------------------------------
 int main() {
     Deck deck;
     deck.shuffle();
 
     // Create players
     std::vector<std::unique_ptr<Player>> players;
     players.push_back(std::make_unique<HumanPlayer>("Alice"));
     players.push_back(std::make_unique<AIPlayer>("CPU_BOT"));
 
     // Deal 2 cards to each
     for(int i=0; i<2; i++){
         for(auto &p : players){
             p->takeCard(deck.dealOne());
         }
     }
 
     // Each player can decide to draw additional cards
     bool someoneDrew = true;
     while(someoneDrew) {
         someoneDrew = false;
         for(auto &p : players){
             p->printStatus();
             if(p->decideDraw(deck)) {
                 // they decided to draw
                 p->takeCard(deck.dealOne());
                 someoneDrew = true;
             }
         }
         std::cout << "--------------------------------\n";
     }
 
     // Final status
     std::cout << "\n=== Final Hands ===\n";
     for(auto &p : players){
         p->printStatus();
     }
 
     std::cout << "End of demonstration.\n";
     return 0;
 }
 