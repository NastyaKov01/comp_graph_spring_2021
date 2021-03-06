#include "Player.h"

#include <iostream>

bool Player::Moved() const
{
    if(coords.x == old_coords.x && coords.y == old_coords.y)
        return false;
    else
        return true;
}

void Player::ChangeCoords(int y, int x)
{
    coords.y = y;
    coords.x = x;
}

void Player::GetTreasure(Image &screen, Image &copy, int **tiles, int *treasures, bool &wood, int &m, int &n)
{
    Image floor("./resources/grey.jpg");
    Image woodenfloor("./resources/tex_-95.png");
    Image wall("./resources/pic_-0.png");
    int ycentre, xcentre;
    ycentre = windowHeight - coords.y - tileSize/2 - 1;
    xcentre = coords.x + tileSize/2;
    switch(tiles[(m * windowHeight + ycentre) / tileSize][(n * windowWidth + xcentre) / tileSize]) 
    {
        case Gold:
        {
            Image gold("./resources/coins.png");
            found = true;
            ++treasures[0];
            DrawTile(gold, screen, wall, 992, 0);
            PrintNumber(screen, wall, treasures[0]);
            break; 
        }
        case Goblet:
        {
            Image goblet("./resources/goblet.png");
            found = true;
            ++treasures[1];
            DrawTile(goblet, screen, wall, 992, 0);
            PrintNumber(screen, wall, treasures[1]);
            break;
        }
        case Potion:
        {
            Image potion("./resources/potion.png");
            found = true;
            ++treasures[2];
            DrawTile(potion, screen, wall, 992, 0);
            PrintNumber(screen, wall, treasures[2]);
            break;
        }
        case Jewel:
        {
            Image jewel("./resources/jewels.png");
            found = true;
            ++treasures[3];
            DrawTile(jewel, screen, wall, 992, 0);
            PrintNumber(screen, wall, treasures[3]);
            break;
        }
        case Redring:
        {
            Image redring("./resources/redring.png");
            found = true;
            ++treasures[4];
            DrawTile(redring, screen, wall, 992, 0);
            PrintNumber(screen, wall, treasures[4]);
            break;
        }
        case Star:
        {
            Image star("./resources/star.png");
            found = true;
            ++treasures[5];
            DrawTile(star, screen, wall, 992, 0);
            PrintNumber(screen, wall, treasures[5]);
            break;
        }
        case Crown:
        {
            found = true;
            ++treasures[6];
            PrintNumber(screen, wall, treasures[6]);
            break;
        }
        default:
            break;
    }
    if (found) {
        if (wood) {
            tiles[(m * windowHeight + ycentre) / tileSize][(n * windowWidth + xcentre) / tileSize] = 95;
            DrawTile(woodenfloor, screen, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(woodenfloor, copy, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        } else {
            tiles[(m * windowHeight + ycentre) / tileSize][(n * windowWidth + xcentre) / tileSize] = 46;
            DrawTile(floor, screen, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(floor, copy, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        }
    }
}

void Player::ProcessInput(MovementDir dir, Image &screen, Image &copy, int **tiles, int *treasures, bool &wood, int &m, int &n)
{
    int move_dist = move_speed * 1;
    switch(dir)
    {
    case MovementDir::UP:
        if (coords.y + move_dist + tileSize < 672) {
            old_coords.y = coords.y;
            coords.y += move_dist;
        }
        break;
    case MovementDir::DOWN:
        if (coords.y - move_dist >= 0) {
            old_coords.y = coords.y;
            coords.y -= move_dist;
        }
        break;
    case MovementDir::LEFT:
        if (coords.x - move_dist >= 0) {
            old_coords.x = coords.x;
            coords.x -= move_dist;
        }
        break;
    case MovementDir::RIGHT:
        if (coords.x + move_dist + tileSize < 1024) {
            old_coords.x = coords.x;
            coords.x += move_dist;
        }
        break;
    default:
        break;
    }
    int ycorner = ((m + 1) * windowHeight - coords.y - 1) / tileSize;
    int xcorner = (n * windowWidth + coords.x) / tileSize;
    int yfarcorner = ((m + 1) * windowHeight - coords.y - tileSize) / tileSize;
    int xfarcorner = (n * windowWidth + coords.x + tileSize - 1) / tileSize;
    switch(tiles[ycorner][xcorner]) 
    {
    case Wall:
    case FlamePic:
    case MoonPic:
    case ShieldPic:
    case PotionPic:
    case Candle:
    case Arch3:
    case Arch4:
    case Book1:
    case Book2:
    case Book3:
    case Book4:
    case Temple:
    case Redarch3:
    case Redarch4:
        coords.y = old_coords.y;
        coords.x = old_coords.x;
        break;
    default:
        break;
    }
    
    switch(tiles[yfarcorner][xfarcorner])
    {
    case Wall:
    case FlamePic:
    case MoonPic:
    case ShieldPic:
    case PotionPic:
    case Candle:
    case Arch3:
    case Arch4:
    case Book1:
    case Book2:
    case Book3:
    case Book4:
    case Temple:
    case Redarch3:
    case Redarch4:
        coords.y = old_coords.y;
        coords.x = old_coords.x;
        break;
    default:
        break;
    }

    switch(tiles[yfarcorner][xcorner]) 
    {
    case Wall:
    case FlamePic:
    case MoonPic:
    case ShieldPic:
    case PotionPic:
    case Candle:
    case Arch3:
    case Arch4:
    case Book1:
    case Book2:
    case Book3:
    case Book4:
    case Temple:
    case Redarch3:
    case Redarch4:
        coords.y = old_coords.y;
        coords.x = old_coords.x;
        break;
    default:
        break;
    }
    
    switch(tiles[ycorner][xfarcorner]) 
    {
    case Wall:
    case FlamePic:
    case MoonPic:
    case ShieldPic:
    case PotionPic:
    case Candle:
    case Arch3:
    case Arch4:
    case Book1:
    case Book2:
    case Book3:
    case Book4:
    case Temple:
    case Redarch3:
    case Redarch4:
        coords.y = old_coords.y;
        coords.x = old_coords.x;
        break;
    default:
        break;
    }
    Player::GetTreasure(screen, copy, tiles, treasures, wood, m, n);
    int ycentre, xcentre;
    ycentre = windowHeight - coords.y - tileSize/2 - 1;
    xcentre = coords.x + tileSize/2;
    bool found = false;
    switch(tiles[(m * windowHeight + ycentre) / tileSize][(n * windowWidth + xcentre) / tileSize]) 
    {
        case Door:
            if (coords.x + tileSize == 1008) {
                ++n;
                Player::ChangeCoords(288, 32);
            } else if (coords.x == 12) {
                --n;
                Player::ChangeCoords(288, 960);
            } else if (coords.y == 12) {
                ++m;
                Player::ChangeCoords(608, 512);
            } else if (coords.y + tileSize == 656) {
                --m;
                Player::ChangeCoords(32, 512);
            }
            DrawRoom(screen, tiles, wood, m, n);
            copy = screen;
            for (int i = 0; i < 7; ++i) {
                std::cout << treasures[i] << " ";
            }
            std::cout << std::endl;
            break;
        case Quit:
            {
            Image win("./resources/victory.png");
            Image wall("./resources/pic_-0.png");
            DrawTile(win, screen, wall, 192, 240);
            victory = true;
            break;
            }
        case Abyss:
        case Mist0:
        case Mist1:
        case Mist2:
        case Mist3:
        {
            Image defeat("./resources/defeat.png");
            Image wall("./resources/pic_-0.png");
            DrawTile(defeat, screen, screen, 334, 218);
            Player::Kill();
            break;
        }
        default:
            break;
    }

}

void Player::Draw(Image &pic, Image &screen, Image &copy)
{
    if(Moved())
    {
        for(int y = old_coords.y; y <= old_coords.y + tileSize; ++y)
        {
            for(int x = old_coords.x; x <= old_coords.x + tileSize; ++x)
            {
                Pixel pix = copy.Data()[copy.Width() * y + x];
                screen.PutPixel(x, y, pix);
            }
        }
        old_coords = coords;
    }

    for(int y = 0; y <= tileSize; ++y)
    {
        for(int x = 0; x <= tileSize; ++x)
        {
            Pixel pix = pic.GetPixel(x, y);
            if (pix.a == 0) {
                Pixel back = copy.Data()[copy.Width() * (coords.y + y) + coords.x + x];
                screen.PutPixel(coords.x + x, coords.y + y, back);
            } else {
                screen.PutPixel(coords.x + x, coords.y + y, pix);
            }
        }
    }
}
