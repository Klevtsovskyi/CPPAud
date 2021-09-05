#include <iostream>
#define N 25


using namespace std;


class Vector
{
private:

    unsigned size;
    double *items;

public:

    Vector(): Vector(N)
    {
        cout << "Creating vector\n";
    }

    Vector(unsigned count): size(count)
    {
        cout << "Creating vector with " << size << " items\n";
        items = new double[size];
        for (int i = 0; i < size; i++)
            items[i] = 0;
    }

    Vector(unsigned count, double* array): Vector(count)
    {
        cout << "Creating vector with " << count << " items using array\n";
        set_items(array);
    }

    Vector(const Vector& v): Vector(v.size, v.items)
    {
        cout << "Creating copy of vector with " << v.size << " items\n";
    }

    ~Vector()
    {
        cout << "Deleting vector of size " << this->size << ": ";
        print(*this);
        delete[] items;
    }

    unsigned get_size()
    {
        return size;
    }

    double get_item(int i)
    {
        while (i < 0)
            i += size;
        while (i >= size)
            i -= size;
        return items[i];
    }

    void set_item(int i, double x)
    {
        while (i < 0)
            i += size;
        while (i >= size)
            i -= size;
        items[i] = x;
    }

    void set_items(double* array)
    {
        for (int i = 0; i < size; i++)
            items[i] = array[i];
    }

    friend void print(const Vector& v);
};


void print(const Vector& v)
{
    for (int i = 0; i < v.size; i++)
        cout << v.items[i] << ' ';
    cout << endl;
}


int main()
{
    Vector *a, *b, *c, *d, *e;
    a = new Vector(10);
    for (int i = 0; i < a->get_size(); i++)
        a->set_item(i, i + 1);
    cout << "a: "; print(*a);

    b = new Vector(*a);
    cout << "b: "; print(*b);
    cout << "a: "; delete a;
    cout << "b: "; delete b;

    double array[10] = {0,9,0,7,0,5,0,3,0,1};
    c = new Vector(5);
    c->set_items(array);
    cout << "c: "; print(*c);
    cout << "c: "; delete c;

    d = new Vector(7, array);
    cout << "d: "; print(*d);
    cout << "d: "; delete d;

    e = new Vector();
    cout << "e: "; print(*e);
    cout << "e: "; delete e;

    return 0;
}
