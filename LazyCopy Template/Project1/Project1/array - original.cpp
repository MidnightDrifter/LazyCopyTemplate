#include "array.h"
#include <fstream>
#include <iostream>
namespace CS225 {





	const ElementProxy Array::operator[](long pos) { return (ElementProxy(*this, pos)); }
	// Array class implementation

	std::ostream& operator<<(std::ostream &out, Array const& array) {
		for (int i = 0; i < (array.size); ++i) {
			out << array.data[i] << " ";
		}
		return out;
	}

	void Array::Insert(int pos, Integer const& val) {
		if (*(this->counter) > 1)
		{
			 this->DeepCopy();
		}
		if (pos >= size) {
			int old_size = size;
			size = 2 * pos + 1; // +1 is required if the first write is at 0
			//std::cout << "in function " << __FUNCTION__ << ": new size = " << size << std::endl;
			Integer* new_data = new Integer[size];
			//std::cout << "in function " << __FUNCTION__ << ": copy " << old_size << " elements" << std::endl;
			for (int i = 0; i < old_size; ++i) {
				new_data[i] = data[i];
			}

			delete[] data;
			data = new_data;
		}
		//std::cout << "in function " << __FUNCTION__ << ": insert element at position " << pos << std::endl;
		data[pos] = val;
		//return *this;
	}


	void Array::DeepCopy()
	{
		--(*(this->counter));
		Integer* t = new Integer[this->size];
		for (int i = 0; i < this->size; ++i)
		{
			t[i] = this->data[i];
		}
		this->data = t;
		this->counter = new int();
		*(this->counter) = 1;
		

	}


	/*
	Array const& Array::DeepCopy()
	{
		//std::cout <<"Entered deep copy"<<std::endl;

		Array const& out = Array(this->size);

		for (int i = 0; i < (out.size); ++i)
		{
			
				out.data[i] = this->data[i];
			
		}
	//	std::cout << "Exiting deep copy" << std::endl;
		return out;
	}

	*/
	Array::~Array()
	{
		//std::cout << "Calling destructor" << std::endl;
		--(*counter);
		if ((*counter) == 0)
		{
			delete [] data;
			delete counter;
			
		}
	
	}




	const Array& Array::operator=(const Array& a)
	{
		
		--(*(this->counter));
		//if this->counter ==0, delete it---should be taken care of by destructor?
		if (*(this->counter) == 0)
		{
			delete[] this->data;
			delete this->counter;
		}
		this->counter = a.counter;
		this->data = a.data;
		
		++(*(this->counter));
		

		return *this;
		

	}
}
