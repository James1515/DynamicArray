/*
 * Author: James Anthony Ortiz
 * File: main.cpp
 * Date: 05/27/2020
 * Description: A mutable array class with automatic resizing in C++17
 *
 */


#include <iostream>
#include <cmath>
using namespace std;

class Array {
public:

    //Array Constructor()
    //STATUS: DONE
    Array(int size) : size_(size)
    {
        arr_ = new int[size_];
        for(int i = 0; i < size_; ++i)
        {
            arr_[i] = 0;
        }
    }

    //size - Return the # of items in the array
    //STATUS: DONE
    int size()
    {
        return size_;
    }


    //is_empty - Check if the array is empty
    //STATUS: DONE
    bool is_empty() {

        bool isEmpty = true;
        for(int i = 0; i < size_; ++i)
        {
            if(arr_[i] != 0)
            {
                isEmpty = false;
            }
        }

        return isEmpty;
    }

    //at(index) - Return the item at the index, shift that index's value and the
    //rest of the elements to the right
    //STATUS INCOMPELETE
    int at(int index)
    {
        if(index > (size_ - 1))
        {
            cout << "Error: Index is out of bounds" << endl;
            return 0;
        }
        else
        {
            return arr_[index];
        }
    }


    //push - pushes value to the array

    void push(int item)
    {
        for(int i = 0; i < size_; i++)
        {
            //If the index is empty,
            //Insert item:
            if(arr_[i] == 0)
            {
                arr_[i] = item;
                break;
            }
        }

    }

    //Insert - Inserts item at the index shifts that index's value and
    //trailing elements to the right.
    //STATUS: INCOMPLETE
    void insert(int index, int item) {
        for(int i = 0; i < size_; ++i)
        {
            if(i == index)
            {
                //Shift elements to the right
                int temp = arr_[i];
                for( int j = i++; j < size_; ++j)
                {
                    arr_[j++] = arr_[j];

                }

                //Insert Item into index
                arr_[i] = item;
            }
        }
    }

    //Prepend - use insert above at index 0
    //INSERT the value at 0, shift to the right
    void prepend(int item)
    {

    }

    //Pop - Remove from the end of the array,
    //return the value
    int pop()
    {
        for(int i = size_; i > 0; i--)
        {
            if(arr_[i] != 0)
            {
                int temp = arr_[i];
                arr_[i] = 0;
                return temp;
            }
        }

        return 0;
    }


    //delete - deletes the item at the index,
    //shifting all trailing elements left.
    //STATUS Incomplete
    void del(int index) {

    }

    //remove(item) - looks for value and removes the index holding it
    //even in multiple places
    //Status: Incomplete
    void remove(int item) {

    }

    //find(item) - looks for the value, and return the
    //first index with that value, else -1 if
    //it is not found in the array
    //Status: Complete
    int find(int item) {
        for(int i = 0; i < size_; ++i)
        {
            //If the item is found, return location at index:
            if(arr_[i] == item)
            {
                return i;
            }
        }

        //If not found in the array return -1:
        return -1;
    }

    //Destructor for Class
    ~Array()
    {
        delete[] arr_;
    }

    //Displays array
    void PrintArray()
    {
        for(int i = 0; i < size_ ; ++i)
        {
            cout << arr_[i] << " ";
        }

        cout << " " << endl;
    }





private:
    void resize(int new_capacity)
    {
        
    }
    int *arr_;
    int size_;
};



//MAIN DRIVER CLASS:
int main()
{
    Array DArray(5);
    DArray.push(1);
    DArray.push(2);
    DArray.push(3);
    DArray.push(4);
    DArray.push(5);

    DArray.PrintArray();
    cout << "The size of the array is: " << DArray.size() << endl;
    cout << "Is the array empty? " << DArray.is_empty() << endl;
    cout << "The value at index 4 is : " << DArray.at(4) << endl;

    return 0;
}
