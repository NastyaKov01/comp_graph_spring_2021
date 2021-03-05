#include <fstream>
#include <iostream>

#include "drawmap.h"

enum
{
    Wall = 35, Floor = 46, Woodenfloor = 95, FlamePic = 102, MoonPic = 109,
    ShieldPic = 115, PotionPic = 112, Mist0 = 77, Mist1 = 73,
    Mist2 = 83, Mist3 = 84, Gold = 71, Goblet = 103,
    Candle = 99, Jewel = 106, Abyss = 32, Arch1 = 97, Arch2 = 65,
    Arch3 = 104, Arch4 = 72, Book1 = 98, Book2 = 66, Book3 = 107,
    Book4 = 75, Crown = 67, Temple = 43, Potion = 80,
    Redarch1 = 101, Redarch2 = 69, Redarch3 = 100, Redarch4 = 68,
    Door = 120, Redring = 114, Star = 42, Quit = 81, Player = 64
};

int DrawTile(Image &picture, Image &screen, Image &back, int xstart, int ystart)
{
    for (int y = 0; y < picture.Height(); ++y) {
        for (int x = 0; x < picture.Width(); ++x) {
            Pixel pix = picture.GetPixel(x, y);
            if (pix.a == 0) {
                screen.PutPixel(xstart + x, screen.Height() - ystart - y - 1, back.GetPixel(x % tileSize, y % tileSize));
            } else {
                screen.PutPixel(xstart + x, screen.Height() - ystart - y - 1, picture.GetPixel(x, y));
            }
        }
    }
    return 0;
}

void ReadMap(const std::string &name, int **tiles)
{
    std::ifstream map;
    map.open(name);
    if (!map) {
        std::cout << "Cannot open the file map.txt" << std::endl;
    } else {
        int ch;
        std::ifstream file;
        int n = 0, m = 0;
        ch = map.get();
        while (!map.eof()) {
            if (char(ch) != '\n') {
                switch (ch)
                {
                    case 80:
                    {
                        file.open("./maps/roomP.txt");
                        break;  
                    }
                    case 65:
                    {
                        file.open("./maps/roomA.txt");
                        break;  
                    }
                    case 66:
                    {
                        file.open("./maps/roomB.txt");
                        break;  
                    }
                    case 67:
                    {
                        file.open("./maps/roomC.txt");
                        break;  
                    }
                    case 68:
                    {
                        file.open("./maps/roomD.txt");
                        break;  
                    }
                    case 69:
                    {
                        file.open("./maps/roomE.txt");
                        break;  
                    }
                    case 70:
                    {
                        file.open("./maps/roomF.txt");
                        break;  
                    }
                    case 71:
                    {
                        file.open("./maps/roomG.txt");
                        break;  
                    }
                    case 83:
                    {
                        file.open("./maps/roomS.txt");
                        break;  
                    }
                }
                if (!file) {
                    std::cout << "Cannot open the file with room map" << std::endl;
                } else {
                    int sym;
                    for (int i = 0; i < windowHeight / tileSize; ++i) {
                        for (int j = 0; j < windowWidth / tileSize; ++j) {
                            sym = file.get();
                            if (char(sym) == '\n') {
                                sym = file.get();
                            }
                            tiles[m * windowHeight / tileSize + i][n * windowWidth / tileSize + j] = sym;
                        }
                    }
                    file.close();
                    file.clear();
                    ++n;
                }
            } else {
                n = 0;
                ++m;
            }
            ch = map.get();
        }
        map.close();
    }
}

void DrawRoom(Image &screen, int **tiles, bool &wood, int m, int n)
{
    int ch;
    int xcur = 0, ycur = 0;
    int i = 0, j = 0;
    Image floor("./resources/grey.jpg");
    Image woodenfloor("./resources/tex_-95.png");
    Image wall("./resources/pic_-0.png");
    wood = false;
    for (int i = 0; i < windowHeight / tileSize; ++i) {
        for (int j = 0; j < windowWidth / tileSize; ++j) {
            ch = tiles[m * windowHeight / tileSize + i][n * windowWidth / tileSize + j];
            switch (ch) {
                case Wall:
                {
                    DrawTile(wall, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Player:
                case Floor:
                {
                    DrawTile(floor, screen, floor, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Woodenfloor:
                {
                    wood = true;
                    DrawTile(woodenfloor, screen, floor, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case FlamePic:
                {
                    Image flamepic("./resources/pic_-3.png");
                    DrawTile(flamepic, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case MoonPic:
                {
                    Image moonpic("./resources/pic_-25.png");
                    DrawTile(moonpic, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case ShieldPic:
                {
                    Image shieldpic("./resources/pic_-4.png");
                    DrawTile(shieldpic, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case PotionPic:
                {
                    Image potionpic("./resources/pic_-7.png");
                    DrawTile(potionpic, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Mist0:
                {
                    Image mist0("./resources/mist0.png");
                    DrawTile(mist0, screen, floor, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Mist1:
                {
                    Image mist1("./resources/mist1.png");
                    DrawTile(mist1, screen, floor, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Mist2:
                {
                    Image mist2("./resources/mist2.png");
                    DrawTile(mist2, screen, floor, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Mist3:
                {
                    Image mist3("./resources/mist3.png");
                    DrawTile(mist3, screen, floor, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Gold:
                {
                    Image gold("./resources/coins.png");
                    if (wood)
                        DrawTile(gold, screen, woodenfloor, xcur, ycur);
                    else
                        DrawTile(gold, screen, floor, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Goblet:
                {
                    Image goblet("./resources/goblet.png");
                    if (wood)
                        DrawTile(goblet, screen, woodenfloor, xcur, ycur);
                    else
                        DrawTile(goblet, screen, floor, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Candle:
                {
                    Image candle("./resources/candle.png");
                    DrawTile(candle, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Jewel:
                {
                    Image jewel("./resources/jewels.png");
                    if (wood)
                        DrawTile(jewel, screen, woodenfloor, xcur, ycur);
                    else
                        DrawTile(jewel, screen, floor, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Abyss:
                {
                    Image abyss("./resources/abyss.png");
                    DrawTile(abyss, screen, floor, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Arch1:
                {
                    Image arch1("./resources/arch1.png");
                    DrawTile(arch1, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Arch2:
                {
                    Image arch2("./resources/arch2.png");
                    DrawTile(arch2, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Arch3:
                {
                    Image arch3("./resources/arch3.png");
                    DrawTile(arch3, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Arch4:
                {
                    Image arch4("./resources/arch4.png");
                    DrawTile(arch4, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Book1:
                {
                    Image book1("./resources/book1.png");
                    DrawTile(book1, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Book2:
                {
                    Image book2("./resources/book2.png");
                    DrawTile(book2, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Book3:
                {
                    Image book3("./resources/book3.png");
                    DrawTile(book3, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Book4:
                {
                    Image book4("./resources/book4.png");
                    DrawTile(book4, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Crown:
                {
                    Image crown("./resources/crown.png");
                    if (wood)
                        DrawTile(crown, screen, woodenfloor, xcur, ycur);
                    else
                        DrawTile(crown, screen, floor, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Temple:
                {
                    Image temple("./resources/temple.png");
                    DrawTile(temple, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Door:
                case Quit:
                {
                    Image door("./resources/door.png");
                    DrawTile(door, screen, wall, xcur, ycur);
                    xcur += door.Width();
                    break;
                }
                case Potion:
                {
                    Image potion("./resources/potion.png");
                    if (wood)
                        DrawTile(potion, screen, woodenfloor, xcur, ycur);
                    else
                        DrawTile(potion, screen, floor, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Redarch1:
                {
                    Image redarch1("./resources/redarch1.png");
                    DrawTile(redarch1, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Redarch2:
                {
                    Image redarch2("./resources/redarch2.png");
                    DrawTile(redarch2, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Redarch3:
                {
                    Image redarch3("./resources/redarch3.png");
                    DrawTile(redarch3, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Redarch4:
                {
                    Image redarch4("./resources/redarch4.png");
                    DrawTile(redarch4, screen, wall, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Redring:
                {
                    Image redring("./resources/redring.png");
                    if (wood)
                        DrawTile(redring, screen, woodenfloor, xcur, ycur);
                    else
                        DrawTile(redring, screen, floor, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
                case Star:
                {
                    Image star("./resources/star.png");
                    if (wood)
                        DrawTile(star, screen, woodenfloor, xcur, ycur);
                    else
                        DrawTile(star, screen, floor, xcur, ycur);
                    xcur += tileSize;
                    break;
                }
            }
        }
        xcur = 0;
        ycur += tileSize;
    }
}
