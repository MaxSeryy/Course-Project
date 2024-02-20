#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED

struct Kitchen;
struct Dish;
struct Product;

struct Kitchen {

    char* name;
    int workers;

    Dish* *DishArray;
    unsigned int arrSize;
    unsigned int DishCount;
};

struct Dish {

    char *name;
    unsigned int minutes;
    int price;

    Product *firstProduct;
    Kitchen *parent;
};

struct Product {

    char *name;
    int mass;

    Product *nextProduct;
    Dish *parent;
};

#endif
