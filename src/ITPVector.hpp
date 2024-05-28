// ITP 365 Fall 2021
// HW04 – Poker Hands
// Name: Brian Xu
// Email: brianjxu@usc.edu
// Platform: Mac
#pragma once
#include <sstream>
#include <ostream>
#include <iostream>
#include <stdexcept>

using namespace std;
//template declaration
template <typename T>

//class declaration
class ITPVector
{
    //member variables
    const static unsigned INITIAL_CAPACITY = 10;
    const static unsigned CAPACITY_MULTIPLIER = 2;
    
public:
    // Function: Constructors
    // Purpose: Initializes the ITP vector to have a
    // capacity of INITIAL_SIZE and a size of 0.
    // It also dynamically allocates the underlining array data
    // Input: None
    // Returns: Nothing
    ITPVector()
    {
        arrayCapacity = INITIAL_CAPACITY;
        arraySize = 0;
        data_array = new T[arrayCapacity] {};
    }
    ITPVector(unsigned inCapacity)
    {
        arrayCapacity = inCapacity;
        arraySize = 0;
        data_array = new T[arrayCapacity] {};
    }
    //copy constructor
    ITPVector(const ITPVector<T>& other)
    {
        //clear();
        arraySize = 0;
        arrayCapacity = other.arrayCapacity;
        data_array = new T[arrayCapacity];
        //for loop, pushing back the data at the corresponding other array
        for (unsigned i = 0; i < other.arraySize; i++){
            push_back(other.data_array[i]);
            
        }
        
        
    }
        
    // Function: capacity
    // Purpose: Returns the current capacity of the underlying array data
    // Input: None
    // Returns: Capacity of underlying array data
    unsigned capacity() const
    {
        return arrayCapacity;
    }

    // Function: size
    // Purpose: Returns the current size of the vector
    // Input: None
    // Returns: Size of vector
    unsigned size() const
    {
        // TODO fix this
        return arraySize;
    }
    //return the underlying data array in pointer form
    T* data() const
    {
        //returns data_array, which is a pointer, of generic type T, thus can house data of all types like ints, strings, booleans, constructed objects, etc. etc.
        return data_array;
    }
    
    // Function: Subscript operator (read/write version)
    // Purpose: Grabs the specified index from vector
    // Causes an error if the index is out of bounds
    // Input: Index to access
    // Returns: Value at index, by reference
    T& operator[](unsigned index)
    {
        //throws exception potentially
        if (index > arraySize)
            throw out_of_range("Error: the index is out of range.");
        
        //basic returns
        return data_array[index];
    }

    // Function: Subscript operator (read-only version)
    // Purpose: Grabs the specified index from vector
    // Causes an error if the index is out of bounds
    // Input: Index to access
    // Returns: Value at index, by reference
    const T& operator[](unsigned index) const
    {
        //throws exception potentially
        if (index > arraySize)
            throw out_of_range("Error: the index is out of range.");

        //basic returns
        return data_array[index];
    }

    //assignment "deep" copy subscript operator
    ITPVector<T>& operator=(const ITPVector<T>& other)
    {
        if (this != &other)
        {
            /*delete [] data_array;

            arraySize = other.arraySize;
            arrayCapacity = other.arrayCapacity;
            data_array = new T[arrayCapacity];*/
            clear();

            for (unsigned i = 0; i < other.arraySize; i++){
                push_back(other.data_array[i]);
            }
        }
        return *this;
        
    }

    
    // Function: insert_back
    // Purpose: Adds the specified element to the end of the ITPVector
    // It automatically reallocates the underlying array if we are
    // going over capacity
    // Input: Value to add (by const reference)
    // Returns: Nothing
    void push_back(const T& value)
    {
        //if the current array is capped out
        if (arraySize == arrayCapacity)
        {
            //increase the arrayCapacity by its multiplication relation to the multiplier
            arrayCapacity *= CAPACITY_MULTIPLIER;
            
            //create a new pointer of customVector type T
            T* newArray = new T[arrayCapacity] {};
            
            //equaling indexs of newArray to indexs of old array
            for (unsigned i = 0; i < arraySize; i++){
                newArray[i] = data_array[i];
            }
            //delete old array pointer
            delete[] data_array;
            //set member variable data_array to new pointer variable newArray
            data_array = newArray;
        }
        
        //this occurs if the current array is not capped out
        data_array[arraySize] = value;
        arraySize++;
        
    }
    
    // Function: remove_back
    // Purpose: Removes the last element from the ITPVector
    // Causes an error if there are no elements in the vector
    // Input: Nothing
    // Returns: Nothing
    void pop_back()
    {
        //if hit the end of the array, and size is == 0
        if (arraySize == 0){
            throw out_of_range("Error: There are no elements in array");
        }
        //otherwise
        data_array[arraySize-1] = T();
        //decrement arraySize
        arraySize--;
    }

    // Function: get_back
    // Purpose: Returns the current last element in the vector
    // Does not remove this element from the vector
    // Causes an error if there are no elements in the vector
    // Input: Nothing
    // Returns: Value at back of vector, by reference
    T& back()
    {
        if (arraySize == 0)
            throw out_of_range("Error: There are no elements in array");

        return data_array[arraySize - 1];
    }
           
    // Function: Output Stream Operator
    // Purpose: Prints the contents of the vector to the provided stream
    // Written in the format of {x, y, ..., z}
    // Input: Stream to write to, vector to write
    // Output: Stream after values are written
    friend std::ostream& operator<<(std::ostream& os, const ITPVector<T>& vector)
    {
        os << "{ ";
        //printing output stream
        for (unsigned i = 0; i < vector.arraySize; i++){
            os << vector[i] << ((i < vector.size() - 1) ? ", " : " ");
        }
        //use flush instead of endl, trying this out
        os << "}" << flush;
        
        return os;
    }
    
    // Function: Destructor
    // Purpose: Deletes the underlying array and
    // sets size/capacity to zero
    // Input: None
    // Returns: Nothing
    ~ITPVector()
    {
        //delete all the items in the data_array
        delete [] data_array;
        data_array = nullptr;
        
        //set capcity and size to 0
        arrayCapacity = 0;
        arraySize = 0;
        
    }
    
    // Function: clear
    // Purpose: Deletes the underlying array
    // Then creates a new underlying array with the same capacity
    // And sets the size to 0
    // Input: None
    // Returns: Nothing
    void clear()
    {
        //delete the data_array in "heap" memory
        delete [] data_array;
        //create a new data array pointer with arrayCapacity
        data_array = new T[arrayCapacity];
        //set arraySize to 0
        arraySize = 0;
    }
        
//private member variables
private:
    //self written member variables
    unsigned arrayCapacity;
    unsigned arraySize;
    T* data_array;
};
