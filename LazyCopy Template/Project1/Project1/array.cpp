#include "array.h"
#include <iostream>

namespace CS225 {

    template<typename DataType>
	const ElementProxy Array::operator[](long pos) { return (ElementProxy(*this, pos)); }
	// Array class implementation


	Array::Array() : size(0), data(NULL), counter(new int()) { *counter = 1; }
	Array::Array(int s) : size(s), data(new DataType[s]), counter(new int()) { *counter = 1; }
	Array::Array(Array const& a) : size(a.size), data(a.data), counter(a.counter) { *(a.counter) += 1; }

	ElementProxy::ElementProxy() : v(v), pos(-1) {}
	ElementProxy::ElementProxy(Array& v, long pos) : v(v), pos(pos) {}


	std::ostream& operator<<(std::ostream &out, Array const& array) {
		for (int i = 0; i < (array.size); ++i) {
			out << array.data[i] << " ";
		}
		return out;
	}

	void Array::Insert(int pos, DataType const& val) {
		if (*(this->counter) > 1)
		{
			this->DeepCopy();
		}
		if (pos >= size) {
			int old_size = size;
			size = 2 * pos + 1; // +1 is required if the first write is at 0
								//std::cout << "in function " << __FUNCTION__ << ": new size = " << size << std::endl;
			DataType* new_data = new DataType[size];
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
		DataType* t = new DataType[this->size];
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
			delete[] data;
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





	ElementProxy::~ElementProxy()
	{
		//std::cout << "Calling EP destructor" << std::endl;
		if (*(v.counter) == 0)
			delete &v;
	}ElementProxy::operator int() const
	{
		return this->v.data[pos];
	}


	ElementProxy&	ElementProxy::operator=(DataType const& x)
	{
		//this->v.Insert(x, this->getPos());

		this->v.Insert(this->getPos(), x);
		return *this;
	}
	const ElementProxy& ElementProxy::operator=(DataType const&  x) const
	{
		//this->v.Insert(x, this->getPos());

		this->v.Insert(this->getPos(), x);
		return *this;

	}

	ElementProxy& ElementProxy::operator=(int const& x)
	{

		this->v.Insert(this->getPos(), x);

		return *this;
	}

	const ElementProxy& ElementProxy::operator=(int const& x) const
	{
		this->v.Insert(this->getPos(), x);
		return *this;
	}

	long ElementProxy::getPos() const
	{
		return this->pos;
	}

	Array& ElementProxy::getArray() const
	{
		return this->v;
	}


	void ElementProxy::setPos(long pos)
	{
		this->pos = pos;
	}


	int ElementProxy::operator[](long pos) const { return data[pos]; }

	/*
    void Array<DataType>::Insert( int pos, DataType const& val ) {
        
         // ....
         
        if ( pos >= size ) {
            int old_size = size;
            size = 2*pos +1;
            DataType* new_data = new DataType[ size ];
            for ( int i=0; i<old_size; ++i ) {
                new_data[i] = data[i];
            }

            delete [] data;
            data = new_data;
        }
        data[ pos ] = val;
    }


    template<typename T>
    std::ostream& operator<<( std::ostream &out, Array<T> const& array ) {
        for ( int i=0; i<array.size; ++i ) {
            out << array.data[i] << " ";
        }
        return out;
    }
	*/
}
