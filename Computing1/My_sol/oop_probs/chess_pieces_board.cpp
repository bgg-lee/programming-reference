/*
Simulate chess pieces on a board. We have a base class ChessPiece with derived classes for King, Queen, Rook, Bishop, Knight, Pawn. Each piece knows its position (row, column) and color (white/black). We want to define how each piece moves.
ChessPiece (abstract base):
    Data: position (row, col), color (enum?), piece type name?
    virtual bool isValidMove(int newRow, int newCol) const = 0; – checks if moving from (row,col) to (newRow,newCol) is valid for that piece’s movement pattern.
    Possibly virtual void printInfo() const; for debugging.
Derived classes: King, Queen, Rook, Bishop, Knight, Pawn
    Each implements isValidMove(...) with chess rules.
    For example, Rook can move if newRow == row || newCol == col.
    Bishop moves diagonally, etc.
    Might add special logic for Pawn capturing, etc. (that can be advanced).
ChessBoard:
    8×8 board of pointers to ChessPiece or maybe std::unique_ptr<ChessPiece> board[8][8].
    A method bool movePiece(int fromRow, int fromCol, int toRow, int toCol); – checks isValidMove(), if valid, move it.
    Possibly handle captures, en passant, or other complexities if you want advanced.
*/
/*********************************************************
 * ChessExample.cpp
 * Demonstrates a simple ChessPiece hierarchy:
 * ChessPiece (abstract), Rook, Bishop, minimal ChessBoard
 *********************************************************/

 #include <iostream>
 #include <string>
 #include <vector>
 #include <memory>
 
 // Color for the chess pieces
 enum class Color { WHITE, BLACK };
 
 //------------------------------------------------
 // 1) Abstract Base: ChessPiece
 //------------------------------------------------
 class ChessPiece {
 protected:
     int row, col;
     Color color;
 
 public:
     ChessPiece(int r, int c, Color clr)
         : row(r), col(c), color(clr) {}
 
     virtual ~ChessPiece() {}
 
     virtual bool isValidMove(int newRow, int newCol) const = 0;
     virtual std::string getType() const = 0;
 
     // Optionally you can have a method to do the move
     void setPosition(int r, int c) { row = r; col = c; }
 
     int getRow() const { return row; }
     int getCol() const { return col; }
     Color getColor() const { return color; }
 };
 
 //------------------------------------------------
 // 2) Derived: Rook
 //------------------------------------------------
 class Rook : public ChessPiece {
 public:
     Rook(int r, int c, Color clr)
         : ChessPiece(r, c, clr) {}
 
     bool isValidMove(int newRow, int newCol) const override {
         // Rook moves if same row or same column
         return (newRow == row) || (newCol == col);
     }
 
     std::string getType() const override { return "Rook"; }
 };
 
 //------------------------------------------------
 // 3) Derived: Bishop
 //------------------------------------------------
 class Bishop : public ChessPiece {
 public:
     Bishop(int r, int c, Color clr)
         : ChessPiece(r,c,clr) {}
 
     bool isValidMove(int newRow, int newCol) const override {
         // Bishop moves diagonally => difference in row == difference in col
         int rowDiff = newRow - row;
         int colDiff = newCol - col;
         return (std::abs(rowDiff) == std::abs(colDiff));
     }
 
     std::string getType() const override { return "Bishop"; }
 };
 
 //------------------------------------------------
 // 4) ChessBoard (very minimal example, 8x8 or similar)
 //------------------------------------------------
 class ChessBoard {
 private:
     // We'll store up to 64 squares in a 2D array of unique_ptr<ChessPiece>.
     static const int SIZE = 8;
     std::unique_ptr<ChessPiece> board[SIZE][SIZE];
 
 public:
     ChessBoard() {
         // init empty
         for(int r=0; r<SIZE; r++){
             for(int c=0; c<SIZE; c++){
                 board[r][c] = nullptr;
             }
         }
     }
 
     bool inBounds(int r, int c) const {
         return (r>=0 && r<SIZE && c>=0 && c<SIZE);
     }
 
     void placePiece(std::unique_ptr<ChessPiece> piece, int r, int c) {
         if(!inBounds(r,c)) {
             std::cerr << "Invalid square!\n";
             return;
         }
         board[r][c] = std::move(piece);
     }
 
     bool movePiece(int fromR, int fromC, int toR, int toC) {
         if(!inBounds(fromR, fromC) || !inBounds(toR, toC)) {
             std::cerr << "Invalid from/to square.\n";
             return false;
         }
         if(!board[fromR][fromC]) {
             std::cerr << "No piece at (" << fromR << "," << fromC << ")\n";
             return false;
         }
 
         ChessPiece* piece = board[fromR][fromC].get();
         if(piece->isValidMove(toR, toC)) {
             // For simplicity, we won't handle captures differently. 
             board[toR][toC] = std::move(board[fromR][fromC]);
             piece->setPosition(toR, toC);
             std::cout << piece->getType() << " moved to (" << toR << "," << toC << ")\n";
             return true;
         } else {
             std::cerr << piece->getType() << " cannot move there!\n";
             return false;
         }
     }
 
     void printBoard() const {
         for(int r=0; r<SIZE; r++){
             for(int c=0; c<SIZE; c++){
                 if(board[r][c]) {
                     std::cout << board[r][c]->getType().at(0);
                 } else {
                     std::cout << ".";
                 }
                 std::cout << " ";
             }
             std::cout << "\n";
         }
     }
 };
 
 //------------------------------------------------
 // main() - Test
 //------------------------------------------------
 int main() {
     ChessBoard cb;
 
     // Place a White Rook at (0,0)
     cb.placePiece(std::make_unique<Rook>(0,0, Color::WHITE), 0,0);
     // Place a Black Bishop at (2,2)
     cb.placePiece(std::make_unique<Bishop>(2,2, Color::BLACK), 2,2);
 
     cb.printBoard();
 
     // Attempt to move the Rook from (0,0) to (0,5)
     cb.movePiece(0,0, 0,5); // valid
     cb.printBoard();
 
     // Attempt invalid move for Bishop from (2,2) to (3,5)
     cb.movePiece(2,2, 3,5); // should fail
     cb.printBoard();
 
     // Attempt diagonal move for Bishop from (2,2) to (4,4)
     // Actually the bishop is still at (2,2), let's do that again
     cb.movePiece(2,2, 4,4); // valid
     cb.printBoard();
 
     return 0;
 }
 