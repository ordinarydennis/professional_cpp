#pragma once

#include <vector>

using std::vector;
template<typename T, 
	typename Container = vector<T>>
	//template<class _Ty, class _Alloc = allocator<_Ty>> class Container = vector>
class MyGrid
{
public:
	explicit MyGrid(size_t _width = WIDTH, size_t _height = HEIGHT);
	~MyGrid()
	{

	}
	void setElement(size_t _w, size_t h, const T& v);
	T& getElementAt(size_t x, size_t y);
	const T& getElementAt(size_t x, size_t y) const;

private:
	static const size_t WIDTH = 2;
	static const size_t HEIGHT = 2;


	//vector<Container<T>> mCells;
	vector<Container> mCells;
	size_t width = 0;
	size_t height = 0;
};

template<typename T, typename Container>
	//template<class _Ty, class _Alloc = allocator<_Ty>> class Container>
MyGrid < T, Container>::MyGrid(size_t _width, size_t _height)
	: width(_width), height(_height)
{
	mCells.resize(width);
	for (auto& e : mCells) {
		e.resize(height);
	}
}

template<typename T, typename Container>
void MyGrid<T, Container>::setElement(size_t _x, size_t _y, const T& v)
{
	mCells[_x][_y] = v;
}
template <typename T, typename Container>
T& MyGrid<T, Container>::getElementAt(size_t x, size_t y)
{
	return mCells[x][y];
}

template <typename T, typename Container>
const T& MyGrid<T, Container>::getElementAt(size_t x, size_t y) const
{
	return mCells[x][y];
}