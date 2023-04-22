#include "../lib/board.h"
#include <iostream>
#include <random>
#include <set>
Board::Board(const int &width, const int &height) {
  this->width = width;
  this->height = height;
  this->board = new bool *[height];
  for (int i = 0; i < height; i++) {
    this->board[i] = new bool[width];
    this->move_count = 0;
  }
}

struct Point {
  int x, y;

  Point(const int &x, int &y) {
    this->x = x;
    this->y = y;
  }

  static Point random(const int &max_width, const int &max_height) {
    std::default_random_engine random_engine(std::random_device{}());

    std::uniform_int_distribution<int> x_distribution(0, max_width - 1);
    std::uniform_int_distribution<int> y_distribution(0, max_height - 1);

    auto x = x_distribution(random_engine);
    auto y = y_distribution(random_engine);
    return Point(x, y);
  }
};

struct PointCompare {
  bool operator()(const Point &a, const Point &b) const {
    if (a.x == b.x) {
      return a.y < b.y;
    }
    return a.x < b.x;
  }
};

Board::~Board() {
  for (int i = 0; i < this->height; i++) {
    delete[] this->board[i];
  }
  delete[] this->board;
}

void Board::init(const int &num_ships) {
  std::set<Point, PointCompare> points;
  while (points.size() < num_ships) {
    auto p = Point::random(this->width, this->height);
    points.insert(p);
  }

  for (auto p : points) {
    this->board[p.x][p.y] = true;
  }
}

bool Board::has_adjacent() {
  int rows = this->height;
  int cols = this->width;

  const int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                {0, 1},   {1, -1}, {1, 0},  {1, 1}};
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      if (this->board[row][col]) {
        for (const auto &dir : directions) {
          int new_row = row + dir[0];
          int new_col = col + dir[1];

          if (new_row >= 0 && new_row < rows && new_col >= 0 &&
              new_col < cols && this->board[new_row][new_col]) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

ResponseType Board::guess(const int &x, const int &y) {
  this->move_count += 1;
  if (this->board[x][y]) {
    return ResponseType::HIT;
  }
  return this->has_adjacent() ? ResponseType::NEARMISS : ResponseType::MISS;
}

void Board::print() {
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      std::cout << this->board[i][j];
    }
    std::cout << std::endl;
  }
}

int Board::get_move_count() { return this->move_count; }
