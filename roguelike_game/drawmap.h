#include "Image.h"

int DrawTile(Image &picture, Image &screen, Image &back, int xstart, int ystart);
void PrintNumber(Image &screen, Image &floor, int n);
void ReadMap(const std::string &name, int **tiles);
void DrawRoom(Image &screen, int **tiles, bool &wood, int m, int n);
