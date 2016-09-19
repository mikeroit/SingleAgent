//Binary heap for open list
//Note: code for this class was modeled, but not copied, from:
// http://www.codeproject.com/Tips/816934/Min-Binary-Heap-Implementation-in-Cplusplus


#include <vector>

template <typename T>
class BinHeap
{
    public:
        BinHeap();
        void Push(T newT);
        T Pop();

    private:
        std::vector<T> myHeap;

        void SiftUp(int index);
        void SiftDown(int index);
        void Reheapify();
};

BinHeap::BinHeap()
{

}

void BinHeap::Reheapify()
{
    for(int i = myHeap.size() - 1; i >= 0; i--)
    {
        SiftDown(i);
    }
}

void BinHeap::SiftDown(int index)
{
    int l = myHeapp.size();
    int left = (2*index) + 1;
    int right = (2*index + 2);

    if(left >= l) //leaf 
    {
        return;
    }

    int minIndex = index;
    if(myHeap[index] > myHeap[left])
    {
        minIndex = left;
    }

    if(right < l && myHeap[minIndex] > myHeap[right])
    {
        minIndex = right;
    }

    if(minINdex != index)
    {
        T temp = myHeap[index];
        myHeap[index] = myHeap[minIndex];
        myHeap[minIndex] = temp;
        SiftDown(minIndex);
    }
}



















