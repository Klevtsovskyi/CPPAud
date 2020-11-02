#include <iostream>
#define N 10


using namespace std;


typedef struct
{
    size_t size;
    size_t count;
    int* items;
} int_set;


int item_index(int_set* s, int item)
{
    for (int i = 0; i < s->count; i++)
    {
        if (s->items[i] == item)
            return i;
    }
    return -1;
}


void restructure(int_set* s, int n)
{
    s->count += n;
    if (s->count >= s->size)
    {
        s->size *= 2;
        s->items = (int*) realloc(s->items, s->size * sizeof (int));
    }
}


void add(int_set* s, int item)
{
    if (item_index(s, item) != -1)
        return;
    restructure(s, 1);
    s->items[s->count - 1] = item;
}


void remove(int_set* s, int item)
{
    int i = item_index(s, item);
    if (i != -1)
    {
        s->items[i] = s->items[s->count - 1];
        restructure(s, -1);
    }
}


int_set create_int_set(int* items, int n)
{
    int_set s;
    if (n > N)
        s.size = n;
    else
        s.size = N;

    s.count = 0;
    s.items = (int*) malloc(s.size * sizeof (int));
    for (int i = 0; i < n; i++)
        add(&s, items[i]);

    return s;
}


void delete_int_set(int_set *s)
{
    free(s->items);
    s->items = NULL;
    s->count = 0;
    s->size = 0;
}


bool int_set_is_empty(int_set* s)
{
    return s->count == 0;
}


void print(int_set s)
{
    for (int i = 0; i < s.count; i++)
        cout << s.items[i] << ' ';
    cout << endl;
}


int_set union_int_set(int_set* a, int_set* b)
{
    int_set s = create_int_set(NULL, 0);
    for (int i = 0; i < a->count; i++)
        add(&s, a->items[i]);
    for (int i = 0; i < b->count; i++)
        add(&s, b->items[i]);
    return s;
}


int_set intersect_int_set(int_set* a, int_set* b)
{
    int_set s = create_int_set(NULL, 0);
    for (int i = 0; i < a->count; i++)
    {
        if (item_index(b, a->items[i]) != -1)
            add(&s, a->items[i]);
    }
    return s;
}


int_set minus_int_set(int_set* a, int_set* b)
{
    int_set s = create_int_set(NULL, 0);
    for (int i = 0; i < a->count; i++)
    {
        if (item_index(b, a->items[i]) == -1)
            add(&s, a->items[i]);
    }
    return s;
}


int save_int_set(int_set s, const char* filename)
{
    FILE* f = fopen(filename, "wb");
    if (f)
    {
        int count = fwrite(&s, sizeof s, 1, f);
        fwrite(s.items, sizeof (int), s.count, f);
        fclose(f);
        return count;
    }
    else
        return -1;
}


int load_int_set(int_set* s, const char* filename)
{
    FILE* f = fopen(filename, "rb");
    if (f)
    {
        int count = fread(s, sizeof *s, 1, f);
        s->items = (int*) malloc(s->size * sizeof (int));
        fread(s->items, sizeof (int), s->count, f);
        fclose(f);
        return count;
    }
    else
        return -1;
}


int main()
{
    int items[10] = {0, 1, -2, 1, 3, 4, 1, 10, 0, 12};
    int_set a = create_int_set(items, 10);
    //for (int i = 0; i < 600; i++)
    //    add(&a, i);

    cout << "a: " << endl; print(a);
    //cout << a.count << ' ' << a.size << endl;

    save_int_set(a, "output.intset");
    delete_int_set(&a);
    cout << "a is empty: " << int_set_is_empty(&a) << endl;


    load_int_set(&a, "output.intset");
    cout << "a: " << endl; print(a);

    remove(&a, 0);
    cout << "a: " << endl; print(a);

    int_set b = create_int_set(items, 3);
    cout << "b: " << endl; print(b);

    int_set unn, inst, mns;
    unn = union_int_set(&a, &b);
    cout << "a|b: " << endl; print(unn);
    delete_int_set(&unn);
    inst = intersect_int_set(&a, &b);
    cout << "a&b: " << endl; print(inst);
    delete_int_set(&inst);
    mns = minus_int_set(&a, &b);
    cout << "a-b: " << endl; print(mns);
    delete_int_set(&mns);



    return 0;
}
