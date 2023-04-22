#ifndef BOARD_H
#define BOARD_H
#define RETRY_MAX 5

enum ResponseType { HIT, MISS, NEARMISS };

class Board {
private:
  int move_count, height, width;
  bool **board;

  bool has_adjacent();

public:
  Board(const int &width, const int &height);
  ~Board();
  void init(const int &num_ships);
  ResponseType guess(const int &x, const int &y);
  void print();
  int get_move_count();
};

#endif /* BOARD_H */
