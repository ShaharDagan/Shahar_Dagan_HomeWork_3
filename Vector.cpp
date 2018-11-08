#include "Vector.h"

/*
Input:int n
Output:return an instance to the Vector class
*/
Vector::Vector(int n) 
{
	//initalize elements default values 
	this->_size = 0;
	if (n < MIN_SIZE) 
	{
		this->_elements = new int[MIN_SIZE];
		this->_resizeFactor = MIN_SIZE;
	}
	else 
	{
		this->_capacity = n;
		this->_elements = new int[n];
		this->_resizeFactor = n;
	}
}
/*
adds val to the elements
Input:const int&val
Ouptut:none
*/
void Vector::push_back(const int&val) 
{
	//check if we need to change the size
	if (this->_size == this->_capacity) 
	{
		reserve(this->_capacity+this->_resizeFactor);
	}
	//increment counter(size) and set the value to val
	this->_elements[this->_size] = val;
	this->_size += 1;
}

/*
Tries to remove the last element
Input:none
Ouptut:the value of last
*/
int Vector::pop_back()
{
	//check if empty
	if (!this->_size) 
	{
		cout << "error: pop from empty vector";
		return ERROR_CODE;
	}
	//gets the last element
	else 
	{
		int last = this->_elements[this->_size];
		this->_elements[this->_size] = NULL;
		this->_size= this->_size - 1;
		return last;
	}
	
}
/*
change size to >=n
Input:int n
Output:none
*/
void Vector::reserve(int n)
{
	//increment the capcity by the resize factor until enough
	int length = this->_capacity;
	while(length <= n)
	{
		length += this->_resizeFactor;
	}
	this->_capacity = length;
	//create the new array
	int *p = new int[length];
	for (int i = 0; i < this->_size; i++)
	{
		p[i] = this->_elements[i];
	}
	delete[]this->_elements;
	this->_elements = p;
}
/*
Resize the vector to the size n
and initalize values of array
Input int n
Output:none
*/
void Vector::resize(int n)
{
	//increment the size to larger value and sets empty cells
	if (n > this->_capacity) 
	{
		reserve(n);
		for (int i = this->_size; i < this->_capacity; i++)
		{
			this->_elements[i] = NULL;
		}
	}
	else 
	{
		//create array with initalized values
		int* p = new int[n]();
		cout << p[1]<<"\n";
		for (int i = 0; i < n; i++)
		{
			p[i] = this->_elements[i];
			this->_elements[i] = NULL;
		}
		//update pointer
		delete[]this->_elements;
		this->_elements = p;
		this->_capacity = n;
		this->_size = n ;
	}
}
/*
sets all elements to val
Input:int val
Output:none
*/
void Vector::assign(int val)
{
	for (int i = 0; i < this->_size; i++)
	{
		this->_elements[i] = val;
	}
}
/*
resize the vector and sets new elements to val
Input:int n,const int&val
Output:none
*/
void Vector::resize(int n, const int & val)
{
	//call the regular function 
	resize(n);
	//sets the new elements to val
	for (int i = this->_size; i < this->_capacity; i++) 
	{
		this->_elements[i] = val;
	}

}
/*
Copy constructor
Input:const Vector & other
Output:sets Vector with the values of other
*/
Vector::Vector(const Vector & other)
{
	this->_capacity = other.capacity();
	this->_size = other.size();
	this->_resizeFactor = other.resizeFactor();
	this->_elements = new int[this->_size];
	for (int i = 0; i < this->_size; i++)
	{
		this->_elements[i] = other._elements[i];
	}
}
/*
Using the copy constructor to make assigemnt
Input:const Vector &other
Output:return the new vector with other values
*/
Vector & Vector::operator=(const Vector & other)
{
	Vector v(other);
	return v;
}
/*
The destructor
deletes the dynamicly memory array
*/
Vector::~Vector() 
{
	delete []this->_elements;
}

/*
Input:none
Output:get the resizeFactor 
*/
int Vector::resizeFactor() const
{
	return this->_resizeFactor;
}
/*
return if vector empty
Input:none
Output:true/ false
*/
bool Vector::empty()const 
{
	return (this->_size == 0) ? true : false;
}
/*
gets capacity
Input:none
Output:the capacity
*/
int Vector::capacity()const {
	return this->_capacity;
}
/*
gets size
Input:none
Output:the size 
*/
int Vector::size() const
{
	return this->_size;
}
/*
return the address to element we want to access
Input:int n
Output:address
*/
int & Vector::operator[](int n) const
{
	if (n > this->_size) 
	{
		int *a = (this->_elements + n);
		return *a;
	}
	else 
	{
		cerr << "Index out of the array";
		return *(this->_elements + 0);
	}
	
}

/*
The function prints the elemnts of the array
Input:none
Ouptut:none
*/
void Vector::Print() const
{
	//iterate the elements 
	for (int i = 0; i < this->_size; i++)
	{
		cout<<this->_elements[i]<<" ";
	}
	cout << "\n";
}
