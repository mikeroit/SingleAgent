//Binary heap used for the Open/Closed lists in A*
#include "Node.h"
#include <iostream>

//static class functions
//Get Left Child
static int GetLeftChildIndex(int index)
{
    return index * 2;
}

//Get Right Child
static int GetRightChildIndex(int index)
{
    return (index * 2) + 1;
}

// Get Parent
static int GetParentIndex(int index)
{
    return index/2;
}


//class header
template <typename State>
class BinHeap
{
    public:

        //constructor
        BinHeap(Node<State>* firstVal); 
        void Push(Node<State> value);
        Node<State>& Pop();

    private:
        std::vector<Node<State>>* myArray; //holds values
        int myNumElements; //stores size of data structure

        //private helper functions
        void swap(int a, int b);
        int sift_up(int start);
        void sift_down(int start);
};

// constructor
template <typename State>
BinHeap<State>::BinHeap(Node<State>* firstVal)
{
    //allocate vec
    myArray = new  std::vector<Node<State>>();

    //clear vec
    myArray->clear();

    //add first val
    myArray->push_back(*firstVal);
    myNumElements = 1;

    std::cout << myArray->size() << std::endl;
}



// private swap
template <typename State>
void BinHeap<State>::swap(int a, int b)
{
    Node<State> temp = myArray->at(a); //store value at a

    myArray->at(a) = myArray->at(b); //overwrite value at a

    myArray->at(b) = temp;
}

//private sift up
template <typename State>
int BinHeap<State>::sift_up(int start)
{
    int currentIndex = start; 

    while(myArray->at(currentIndex).GetFCost() < myArray->at(GetParentIndex(currentIndex)).GetFCost())
    {
        swap(currentIndex, GetParentIndex(currentIndex));
        currentIndex = GetParentIndex(currentIndex);
    }
    return currentIndex;
}

//private sift down
template <typename State>
void BinHeap<State>::sift_down(int start)
{
    bool sifted = false;
    int currentIndex = start;

    while(! sifted)
    {
        int leftVal = 0xFFFFFFFF;
        int rightVal = 0xFFFFFFFF;

        bool hasLeftChild = (GetLeftChildIndex(currentIndex) < myNumElements);
        bool hasRightChild = (GetRightChildIndex(currentIndex) < myNumElements);
        if((!hasRightChild) && (!hasLeftChild)) break; 

        if(hasLeftChild) leftVal = myArray->at(GetLeftChildIndex(currentIndex)).GetFCost();
        if(hasRightChild) rightVal = myArray->at(GetRightChildIndex(currentIndex)).GetFCost();

        
        //are we sifted?
        if((myArray->at(currentIndex).GetFCost() <= rightVal) &&
            (myArray->at(currentIndex).GetFCost() <= leftVal))
        {
            sifted = true;
        }

        //do we need to swap with left child?
        else if(hasLeftChild && (myArray->at(currentIndex).GetFCost() > myArray->at(GetLeftChildIndex(currentIndex)).GetFCost()))
        {
            swap(currentIndex, GetLeftChildIndex(currentIndex));
            currentIndex = GetLeftChildIndex(currentIndex);
        }

        //must need to swap with right child
        else if(hasRightChild)
        {
            swap(currentIndex, GetRightChildIndex(currentIndex));
            currentIndex = GetRightChildIndex(currentIndex);
        }
    }
}

// BinHeap Push
template <typename State>
void BinHeap<State>::Push(Node<State> value)
{
    myArray->push_back(value);
    myNumElements++;

    int indexSiftedUp = sift_up(myNumElements - 1);
    sift_down(indexSiftedUp);
}

// BinHeap Pop
template <typename State>
Node<State>& BinHeap<State>::Pop()
{
	//get return value
	Node<State>* result = new Node<State>(myArray->front().myState);

	//replace root with last leaf
	myArray[0] = myArray[myNumElements - 1];
	myArray->pop_back();

	//reheapify
	sift_down(0);

    return *result;
}




















