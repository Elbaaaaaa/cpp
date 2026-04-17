#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array
{
	private:
		T* _data;
		unsigned int _size;
	public:
		Array() : _data(NULL), _size(0) {}
	
		Array(unsigned int n) : _data(NULL), _size(n)
		{
			_data = new T[_size]();
		}
	
		Array(const Array& other) : _data(NULL), _size(other._size)
		{
			if (_size == 0)
				return;
			_data = new T[_size]();
			for (unsigned int i = 0; i < _size; ++i)
				_data[i] = other._data[i];
		}
	
		Array& operator=(const Array& other)
		{
			if (this == &other)
				return *this;
		
			delete[] _data;
			_data = NULL;
			_size = other._size;
		
			if (_size == 0)
				return *this;
		
			_data = new T[_size]();
			for (unsigned int i = 0; i < _size; ++i)
				_data[i] = other._data[i];
			return *this;
		}
	
		~Array()
		{
			delete[] _data;
		}
	
		T& operator[](int index)
		{
			if (index < 0 || static_cast<unsigned int>(index) >= _size)
				throw OutOfBounds();
			return _data[index];
		}
	
		T const& operator[](int index) const
		{
			if (index < 0 || static_cast<unsigned int>(index) >= _size)
				throw OutOfBounds();
			return _data[index];
		}
	
		unsigned int size() const
		{
			return _size;
		}
	
		class OutOfBounds : public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return "Array: index out of bounds";
			}
		};
};

#endif

