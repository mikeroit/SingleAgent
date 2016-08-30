//BitMap.h

#include <string>

using namespace std;

struct Point
{
    int xLoc;
    int yLoc;

    Point(int x, int y)
    {
        xLoc = x;
        yLoc = y;
    }
};

class BitMap
{
    public:
        inline BitMap();
        inline BitMap(int h, int w);

        void ReadFromFile(std::string fileName);
        void DecodeMapIndex(int index, Point &p);
        int EncodeMapPosition(Point p);
        int EncodeMapPosition(int x, int y);
        void SetWidth(int w);
        void SetHeight(int h);
        int GetHeight();
        int GetWidth();
        char GetCell(int x, int y);

    private:
        int myHeight;
        int myWidth;

        char* myMap;
};


BitMap::BitMap()
{
    myHeight = 0; myWidth = 0;
}

BitMap::BitMap(int h, int w)
{
    myHeight = h; myWidth = w;
}

