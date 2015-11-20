#ifndef ARRAY_H
#define ARRAY_H


#include <fstream> // std::ostream
#include <iostream>
#include "int.h"

namespace CS225 {
	class ElementProxy;

	 template<typename DataType>

	class Array {
		friend class ElementProxy;
	private:
		int size;
		DataType* data;
		int* counter;


	public:
		Array(); 
		Array(int s); 
		Array(Array const& a); 

		~Array();


		const ElementProxy operator[](long pos);// { return ElementProxy(*this, pos); }
		int operator[](long pos) const// { return data[pos]; }
		//const DataType operator[](long pos) const { return data[pos]; }
		friend std::ostream& operator<<(std::ostream &out, Array const& array);
		void Insert(int pos, DataType const& val);
		//Array const& DeepCopy();
		void DeepCopy();
		const Array& operator=(const Array& a);

	};





	class ElementProxy {
		friend class Array;
	private:
		Array &v;
		long pos;



	public:
		ElementProxy();  
		ElementProxy(Array& v, long pos);  
		~ElementProxy();
	/*	{
			//std::cout << "Calling EP destructor" << std::endl;
			if (*(v.counter) == 0)
				delete &v;
		}
		*/

		//friend ElementProxy operator*(int t, ElementProxy& p);

		operator int() const;
		/*{
			return this->v.data[pos];
		}
		*/
		ElementProxy& operator=(DataType const& x);
		/*{
			//this->v.Insert(x, this->getPos());

			this->v.Insert(this->getPos(), x);
			return *this;
		}*/

		const ElementProxy& operator=(DataType const&  x) const;
	/*	{
			//this->v.Insert(x, this->getPos());

			this->v.Insert(this->getPos(), x);
			return *this;

		}
		*/
		ElementProxy& operator=(int const& x);
		/*{

			this->v.Insert(this->getPos(), x);

			return *this;
		}*/

		const ElementProxy& operator=(int const& x) const;
		/*{
			this->v.Insert(this->getPos(), x);
			return *this;
		}*/



		long getPos() const;
		/*{
			return this->pos;
		}*/

		Array& getArray() const;
		/*{
			return this->v;
		}*/

		void setPos(long pos);
		/*{
			this->pos = pos;
		}*/



#endif
