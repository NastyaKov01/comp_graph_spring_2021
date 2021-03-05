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
    Door = 120, Redring = 114, Star = 42
};

int DrawTile(Image &picture, Image &screen, Image &back, int xstart, int ystart)
{
    for (int y = 0; y < picture.Height(); ++y) {
        for (int x = 0; x < picture.Width(); ++x) {
            Pixel pix = picture.GetPixel(x, y);
            if (pix.a == 0) {
                screen.PutPixel(xstart + x, screen.Height() - ystart - y - 1, back.GetPixel(x, y));
            } else {
                screen.PutPixel(xstart + x, screen.Height() - ystart - y - 1, picture.GetPixel(x, y));
            }
        }
    }
    return 0;
}

void ReadMap(Image &screen, int **tiles, bool &wood)
{
    const char *fname = "./maps/roomS.txt";
    std::ifstream file(fname);
    if (!file) {
        std::cout << "Cannot open the file" << std::endl;
    } else {
        int ch;
        ch = file.get();
        int xcur = 0, ycur = 0;
        int i = 0, j = 0;
        Image floor("./resources/grey.jpg");
        Image woodenfloor("./resources/tex_-95.png");
        Image wall("./resources/pic_-0.png");
        while (!file.eof()) {
            if (char(ch) != '\n') {
                tiles[i][j] = ch;
                ++j;
                switch (ch) {
                    case Wall:
                    {
                        DrawTile(wall, screen, wall, xcur, ycur);
                        xcur += tileSize;
                        break;
                    }
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
            } else {
                xcur = 0;
                ycur += tileSize;
                j = 0;
                ++i;
            }
            ch = file.get();
        }
        file.close();
    }
}

