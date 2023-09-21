#include <iostream>


class Rectangle
{
protected:
	int width, height;
public:
	Rectangle(int width, int height):width(width),height(height)
	{}
	int getHeight() const { return height; }
	int getWidth() const { return width; }

	virtual void setHeight(const int h) { height = h; }
	virtual void setWidth(const int w) { width = w; }

	int area() const { return width * height; }
};

class Square : public Rectangle
{
public:
	Square(int size):Rectangle(size,size)
	{}

	void setWidth(int width) override
	{
		this->width = this->height = width;
	}
	void setHeight(int height) override
	{
		this->width = this->height = height;
	}
};

void process(Rectangle& r)
{
	int w = r.getWidth();
	r.setHeight(10);
	std::cout << "Expeceted area = " << (w * 10) << " got " << r.area() << std::endl;
}


class RectangleFactory
{
	static Rectangle create_rectangle(int w, int h);
	static Rectangle create_square(int size);
};

int main3()
{
	Rectangle r(3, 4);
	return 0;
}