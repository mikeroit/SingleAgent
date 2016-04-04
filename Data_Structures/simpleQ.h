//
// Created by mikeroit on 3/30/2016.
//

#ifndef SINGLEAGENTHW1_SIMPLEQ_H
#define SINGLEAGENTHW1_SIMPLEQ_H


using namespace std;

//-------------------------------------------------------------------------------------------------------
template <typename T>
class simpleQ{

    public:
        simpleQ();
        ~simpleQ();
        simpleQ(const simpleQ& a);

//      return true if the queue is empty
        bool IsEmpty() const;

//      enqueue the next item at the tail of the queue.
        void Add(T value);

        void AddHead(T value);

//      dequeue the next queue element and store it in "item" variable.  The function returns
//      false if the queue is empty and no item can be retrieved.
        bool Remove(T &item);

//      print list
        void Print();

    private:

//      data structure to package template items
        struct QueueItem {
            T item;
            QueueItem *next;
        };

//      start of list
        QueueItem *head;

//      implemented with tail for easy insertion at end
        QueueItem *tail;
};
//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------
template <typename T>
simpleQ<T>::simpleQ(){
    head = NULL;
    tail = NULL;
}
//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------
template <typename T>
simpleQ<T>::simpleQ(const simpleQ& a){
    head = a.head;
    tail = a.tail;
}
//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------
template <typename T>
simpleQ<T>::~simpleQ(){
    while (head != NULL){
        Remove(head->item);
    }
}
//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------
template <typename T>
bool simpleQ<T>::IsEmpty() const{

    return (head == NULL);

}
//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------
template <typename T>
void simpleQ<T>::Add(T value){
    //Make a node to insert, point to NULL
    QueueItem *temp = new QueueItem;


    temp->item = value;
    if (!(tail == NULL)){
        tail->next = temp;
        tail = temp;
        tail->next = NULL;
    }
    else{
        tail = temp;
        tail->next = NULL;
        head = temp;
    }
}
//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------
template <typename T>
bool simpleQ<T>::Remove(T &item){
//  make sure list has a value to remove
    if (IsEmpty()){
        return false;
    }

//  fetch next queue item from queue
    QueueItem *temp = head;

//  store popped value
    item = head->item;

//  advance head
    head = head->next;

//  handle would-be memory leak
    delete temp;

//  assert that for an empty queue: head=tail = NULL
    if (head == NULL){
        tail = NULL;
    }
    return true;
}
//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------
template <typename T>
    void simpleQ<T>::Print(){
    QueueItem* temp = head;
    while (temp != NULL){
        std::cout << temp->item << std::endl;
        temp = temp->next;
    }
}
//-------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------
template <typename T>
void simpleQ<T>::AddHead(T value){
    //Make a node to insert, point to NULL
    QueueItem *temp = new QueueItem;

    temp->item = value;
    if (!(tail == NULL)){
        temp->next = head;
        head = temp;
    }
    else{
        tail = temp;
    }
}
//-------------------------------------------------------------------------------------------------------
#endif //SINGLEAGENTHW1_SIMPLEQ_H