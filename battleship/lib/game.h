#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "consts.h"

class BaseGame {
protected:
  Board * board;
  virtual int solve() = 0;
public:
  BaseGame();
  ~BaseGame();
  int run();
};


class ControlGame : public BaseGame {
protected:
    int solve() override {
        int hits = 0;
        for(int i = 0; i < HEIGHT; i++)
        {
            for(int j = 0; j < WIDTH; j++)
            {
                if(this->board->guess(i, j) == ResponseType::HIT)
                {
                    hits += 1;
                }
            }
        }
        return hits;
    }
};

class AssignmentGame : public BaseGame {
  protected:
    int solve() override {
        
        void hunt_target(){
        // enter hunt mode when no more targets left
        int guess_row, guess_col;
        if(this->targets.empty()){
            guess_row, guess_col = this->guess_random();
        }
        else{
            guess_row, guess_col = this->targets.pop();
        }
        if(this->SHIP_MAP[guess_row][guess_col] == 1){
            // add all adjacent squares to list of potential targets where possible
            vector<pair<int, int>> potential_targets;
            potential_targets.push_back(make_pair(guess_row + 1, guess_col));
            potential_targets.push_back(make_pair(guess_row, guess_col + 1));
            potential_targets.push_back(make_pair(guess_row - 1, guess_col));
            potential_targets.push_back(make_pair(guess_row, guess_col - 1));
            for(auto target : potential_targets){
                if((0 <= target.first <= 99) &&
                   (0 <= target.second <= 99) &&
                   (this->SHOT_MAP[target.first][target.second] == 0) &&
                   (find(this->targets.begin(), this->targets.end(), target) == this->targets.end())){
                    this->targets.push_back(target);
                }
            }
        }
        return make_pair(guess_row, guess_col);
    }

        return SHIP_COUNT;
    }

    
};



#endif /* GAME_H */