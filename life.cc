#include "life.hh"

void clear()
{
  cout << string(100, '\n');
}

void life(int size, bool random = true)
{
  Board b(size, random);
  for (int i = 0; i < 100; i++)
  {
    clear();
    for (int j = 0; j < size; j++)
    {
      for (int k = 0; k < size; k++)
      {
        if (b.get(j, k)) cout << 'x';
        else cout << ' ';
      }
      cout << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(TICKRATE));
    b.next();
  }
}

int main(int argc, char** argv)
{
  life(10);
}

Board::Board(int size, bool random)
{
  this->size = size;
  board = new vector<vector<bool>>();

  for (int i = 0; i < size; i++)
  {
    board->push_back(vector<bool>());
    for (int j = 0; j < size; j++)
    {
      if (randInt(10)/9)
      {
        (*board)[i].push_back(true);
      }
      else
      {
        (*board)[i].push_back(false);
      }
    }
  }
}

inline void Board::set(int x, int y, bool v)
{
  (*board)[x][y] = v;
}

inline bool Board::get(int x, int y)
{
  return (*board)[x][y];
}

void Board::next()
{
  vector<vector<bool>>* next = new vector<vector<bool>>();
  for (int i = 0; i < size; i++)
  {
    next->push_back(vector<bool>());
    for (int j = 0; j < size; j++)
    {
      int score = this->score(i, j);
      if (get(i, j))
      {
        if (score < 2 || score > 3)
        {
          (*next)[i].push_back(false);
        }
        else (*next)[i].push_back(true);
      }
      else
      {
        if (score < 4 && score > 1)
        {
          (*next)[i].push_back(true);
        }
        else (*next)[i].push_back(false);
      }
    }
  }
  this->board = next;
}

int Board::score(int x, int y)
{
  int score = 0;
  for (int i = x-1; i <= x+1; i++)
  {
    if (i < 0 || i >= size || i == x) continue;
    for (int j = y-1; j <= y+1; j++)
    {
      if (j < 0 || j >= size || j == y) continue;
      score += get(i, j);
    }
  }
  return score;
}
