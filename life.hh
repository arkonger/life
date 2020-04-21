#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <string>
#include <thread>
#include <chrono>

// ms/tick
#define TICKRATE 1000/5
#define RADIUS 7

using namespace std;

random_device rd; //Seed
mt19937 gen(rd()); //Random Generator

//Random int function for [min, max)
inline int randInt(int max, int min = 0)
{
  uniform_int_distribution<> r(min, max);
  return r(gen);
}

class Board
{
  int size;
  vector<vector<bool>>* board;
  
  public: Board(int size, bool random);
  inline void set(int x, int y, bool v);
  public: inline bool get(int x, int y);
  public: void next();
  int score(int x, int y);
};
