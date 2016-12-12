//BitMap.cpp

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "BitMap.h"

void split(const string& s, char c, vector<string>& v) {
   string::size_type i = 0;
   string::size_type j = s.find(c);

   while (j != string::npos) {
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);

      if (j == string::npos)
         v.push_back(s.substr(i, s.length()));
   }
}

char BitMap::GetCell(int x, int y)
{
    return myMap[EncodeMapPosition(y, x)];
}

void BitMap::ReadFromFile(std::string fileName)
{
    std::ifstream file(filename);
    std::string line; 

    int loopIndex = 0;
    vector<string> vec;
    while (std::getline(file, line))
    {
        vec.clear();

        if(loopIndex < 4){
            switch(loopIndex)
            {
                case 1:
                    split(line, ' ', vec);
                    istringstream (vec[1]) >> myHeight;
                    break;

                case 2:
                    split(line, ' ', vec);
                    istringstream (vec[1]) >> myWidth;
                    myMap = new char[myWidth * myHeight];
                    break;

                default:
                    break;
            }
        }

        else 
        {
            for(int i = 0; i < myWidth; i++)
            {
                myMap[((loopIndex-4) * myWidth) + i] = line[i];
            }
        }

        loopIndex++;
    }

    //std::cout << "h:" << myHeight << std::endl;
    //std::cout << "w:" << myWidth << std::endl;
}

void BitMap::DecodeMapIndex(int index, Point &p)
{
    if(index >= 0 && index < (myWidth * myHeight))
    {
        p.xLoc = index % myWidth;
        p.yLoc = index / myWidth;
    }

}

int BitMap::EncodeMapPosition(int x, int y)
{
    return
        (y * myWidth) + x;
}

int BitMap::EncodeMapPosition(Point p)
{
    return
        (p.yLoc * myWidth) + p.xLoc;
}

void BitMap::PrintMap()
{
    for(int i = 0; i < myWidth; i++)
    {
        for(int j = 0; j < myHeight; j++)
        {
            std::cout << GetCell(i, j);
        }

        std::cout << std::endl;

    }
}

// getters and setters

void BitMap::SetWidth(int w)
{
    myWidth = w;
}

void BitMap::SetHeight(int h)
{
    myHeight = h;
}

int BitMap::GetHeight()
{
    return myHeight;
}

int BitMap::GetWidth()
{
    return myWidth;
}


