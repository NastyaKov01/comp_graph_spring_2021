#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H


#include "Image.h"
#include "drawmap.h"

enum
{
    Wall = 35, Floor = 46, Woodenfloor = 95, FlamePic = 102, MoonPic = 109,
    ShieldPic = 115, PotionPic = 112, Mist0 = 77, Mist1 = 73,
    Mist2 = 83, Mist3 = 84, Gold = 71, Goblet = 103,
    Candle = 99, Jewel = 106, Abyss = 32, Arch1 = 97, Arch2 = 65,
    Arch3 = 104, Arch4 = 72, Book1 = 98, Book2 = 66, Book3 = 107,
    Book4 = 75, Crown = 67, Necklace = 110, Temple = 43, Potion = 80,
    Redarch1 = 101, Redarch2 = 69, Redarch3 = 100, Redarch4 = 68,
    Door = 120, Redring = 114, Star = 42, Quit = 81
};

struct Point
{
  int x;
  int y;
};

enum class MovementDir
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};

struct Player
{
  explicit Player(Point pos = {.x = 10, .y = 10}) :
                 coords(pos), old_coords(coords) {};

  bool Moved() const;
  void ChangeCoords(int y, int x);
  void ProcessInput(MovementDir dir, Image &screen, Image &copy, int **tiles, int *treasures, bool &wood, int &m, int &n);
  void Draw(Image &pic, Image &screen, Image &copy);
  void GetTreasure(Image &screen, Image &copy, int **tiles, int *treasures, bool &wood, int &m, int &n);
  void Kill() { dead = true; }
  bool Killed() { return dead; }
  void Find() { found = true; }
  bool Found() { return found; }
  void Lose() { found = false; }
  bool Win() { return victory; }

private:
  Point coords {.x = 10, .y = 10};
  Point old_coords {.x = 10, .y = 10};
  Pixel color {.r = 255, .g = 255, .b = 0, .a = 255};
  int move_speed = 4;
  bool dead = false;
  bool found = false;
  bool victory = false;
};

#endif //MAIN_PLAYER_H
