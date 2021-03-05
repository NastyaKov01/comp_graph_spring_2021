#include "Player.h"

#include <iostream>
bool Player::Moved() const
{
    if(coords.x == old_coords.x && coords.y == old_coords.y)
        return false;
    else
        return true;
}

void Player::GetTreasure(Image &screen, Image &copy, int **tiles, bool &wood)
{
    Image floor("./resources/grey.jpg");
    Image woodenfloor("./resources/tex_-95.png");
    Image wall("./resources/pic_-0.png");
    int ycentre, xcentre;
    ycentre = windowHeight - coords.y - tileSize/2 - 1;
    xcentre = coords.x + tileSize/2;
    switch(tiles[ycentre / tileSize][xcentre / tileSize]) 
    {
    case Gold:
        if (wood) {
            tiles[ycentre / tileSize][xcentre / tileSize] = 95;
            DrawTile(woodenfloor, screen, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(woodenfloor, copy, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        } else {
            tiles[ycentre / tileSize][xcentre / tileSize] = 46;
            DrawTile(floor, screen, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(floor, copy, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        }
        break;
    case Goblet:
        if (wood) {
            tiles[ycentre / tileSize][xcentre / tileSize] = 95;
            DrawTile(woodenfloor, screen, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(woodenfloor, copy, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        } else {
            tiles[ycentre / tileSize][xcentre / tileSize] = 46;
            DrawTile(floor, screen, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(floor, copy, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        }
        break;
        break;
    case Potion:
        if (wood) {
            tiles[ycentre / tileSize][xcentre / tileSize] = 95;
            DrawTile(woodenfloor, screen, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(woodenfloor, copy, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        } else {
            tiles[ycentre / tileSize][xcentre / tileSize] = 46;
            DrawTile(floor, screen, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(floor, copy, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        }
        break;
    case Jewel:
        if (wood) {
            tiles[ycentre / tileSize][xcentre / tileSize] = 95;
            DrawTile(woodenfloor, screen, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(woodenfloor, copy, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        } else {
            tiles[ycentre / tileSize][xcentre / tileSize] = 46;
            DrawTile(floor, screen, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(floor, copy, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        }
        break;
    case Redring:
        if (wood) {
            tiles[ycentre / tileSize][xcentre / tileSize] = 95;
            DrawTile(woodenfloor, screen, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(woodenfloor, copy, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        } else {
            tiles[ycentre / tileSize][xcentre / tileSize] = 46;
            DrawTile(floor, screen, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(floor, copy, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        }
        break;
    case Crown:
        if (wood) {
            tiles[ycentre / tileSize][xcentre / tileSize] = 95;
            DrawTile(woodenfloor, screen, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(woodenfloor, copy, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        } else {
            tiles[ycentre / tileSize][xcentre / tileSize] = 46;
            DrawTile(floor, screen, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(floor, copy, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        }
        break;
    case Star:
        if (wood) {
            tiles[ycentre / tileSize][xcentre / tileSize] = 95;
            DrawTile(woodenfloor, screen, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(woodenfloor, copy, woodenfloor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        } else {
            tiles[ycentre / tileSize][xcentre / tileSize] = 46;
            DrawTile(floor, screen, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
            DrawTile(floor, copy, floor, xcentre / tileSize * tileSize, ycentre / tileSize * tileSize);
        }
        break;
    default:
        break;
    }
}

void Player::ProcessInput(MovementDir dir, Image &screen, Image &copy, int **tiles, bool &wood)
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

    switch(tiles[(windowHeight-coords.y-1)/tileSize][coords.x/tileSize]) 
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

    switch(tiles[(windowHeight-coords.y-tileSize)/tileSize][(coords.x+tileSize-1)/tileSize])
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

    switch(tiles[(windowHeight-coords.y-tileSize)/tileSize][coords.x/tileSize]) 
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
    
    switch(tiles[(windowHeight-coords.y-1)/tileSize][(coords.x+tileSize-1)/tileSize]) 
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
    Player::GetTreasure(screen, copy, tiles, wood);
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
            //std::cout << "a = " << int(pix.a) << " ";
            if (pix.a == 0) {
                ///std::cout << "***" << std::endl;
                Pixel back = copy.Data()[copy.Width() * (coords.y + y) + coords.x + x];
                screen.PutPixel(coords.x + x, coords.y + y, back);
            } else {
                screen.PutPixel(coords.x + x, coords.y + y, pix);
            }
        }
       // std::cout << std::endl;
    }
}
