#include <iostream>
#include <cstddef>

template<typename T>

class Vector{
	private:
	
	//Pointer to the dynamically allocated memory
	T* elements;
	//Number of elements in vector
	std::size_t size;
	//Current capacity of vector
	std::size_t capacity;

	public:
	//Constructor
	Vector() : elements(nullptr), size(0), capacity(0) {}

	//Destructor
	~Vector() {
		delete[] elements;
	}

	//Adding elements in vector
	void push_back(const T& element){
		if(size == capacity){
			if(capacity == 0){
				capacity = 1;
			}else{
				capacity *= 2;
			}

			T* newElements = new T[capacity];

			//Copy the elements of vector to the new memory block
			for(int i = 0; i < size; ++i){
				newElements[i] = elements[i];
			}

			delete[] elements;
			elements = newElements;
		}
		
		//Adder
		elements[size] = element;
		++size;
	}

	//The size of vector
	int GetSize() const{
		return size;
	}

	//Get an element at the specified index (get access using operator[])
	T& operator[](int index){
		return elements[index];
	}
};

int main(){

	Vector<int> myVector;

	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);
	myVector.push_back(4);
	myVector.push_back(5);

	for(int i = 0; i < myVector.GetSize(); ++i){
		std::cout<< myVector[i] << std::endl;
	}
	
	return 0;
}
