#ifndef __CART_H__
#define __CART_H__

#include <cstdio>
#include <list>

#include "Product.h"
#include "SuperMarket.h"

using namespace std;

class ShoppingCart:public SuperMarket{
private:
    float total_cost;
    std::list<std::pair<Product,int> > myProducts; // the Product + the quanity
    bool searchBarcode(const char *bc); // Search to find if the barcode exists in my database

public:
    ShoppingCart():total_cost(0){}

    void setValue(float a){ total_cost = a; }
    void clear();

    void readBarcode();
    void removeBarcode();

    void addProduct(Product prod, int q = 1,bool check = true);
    void addProduct(const char *bc,int q = 1); // q = quantity

    void removeProduct(const char *bc);
    void removeProduct(const char *bc,int q); // quantity

    float getPrice(){ return total_cost; }
    float getProductPrice(const char *bc);

    void printPrice(){ printf("The Overall Price is : $%.3f\n",getPrice()); }
    void printCart();
};
void ShoppingCart::clear(){
    myProducts.clear();
}
void ShoppingCart::addProduct(Product prod,int q,bool check){
        // I guess that q >= 0, since I will take it from screen with positive numbmers
        if(q == 0) return ;
        // I have to check if the prod
        //it is already in my Cart
        for(std::list<std::pair<Product,int> >::iterator it = myProducts.begin(); it != myProducts.end(); ++it){
                int i = 0;
                bool found = true;
                while(prod.barcode[i]){
                        if(!found)
                                break;
                        if(prod.barcode[i] != (*it).first.barcode[i])
                                found = false;
                        ++i;
                }
                if(found){
                        (*it).second += q;
                        total_cost += (*it).first.price * q;
                        return ;
                }
        }
        if(!check){
            total_cost += prod.price * q;
            myProducts.push_back(make_pair(prod,q));
            return ;
        }
        // There isn't such product
        for(list<Product>::iterator it = allProducts.begin(); it != allProducts.end(); ++it){
                int i = 0;
                bool found = true;
                while(prod.barcode[i]){
                        if(!found) break;
                        if(prod.barcode[i] != (*it).barcode[i]) found = false;
                        ++i;
                }
                if(found){
                        total_cost += it->price * q;
                        myProducts.push_back(make_pair((*it),q));
                        return ;
                }
        }
}
void ShoppingCart::addProduct(const char *bc,int q){
    if(q == 0) return ;
    // Find the barcode in the Products list, and pass it over to the other addProduct function
    for(list<Product>::iterator it = allProducts.begin(); it != allProducts.end(); ++it){
            int i = 0;
            bool found = true;
            while(bc[i]){
                    if(!found)
                            break;
                    if(bc[i] != (*it).barcode[i])
                            found = false;
                    ++i;
            }
            if(found){
                addProduct(*it,q,false);
                return ;
            }
    }
}
void ShoppingCart::removeProduct(const char *bc){
        for(list<pair<Product,int> >::iterator it = myProducts.begin(); it != myProducts.end(); ++it){
                int i = 0;
                bool found = true;
                while(bc[i]){
                        if(!found)
                                break;
                        if(bc[i] != (*it).first.barcode[i])
                                found = false;
                        ++i;
                }
                if(found){
                    total_cost -= (*it).second * (*it).first.price;
                    myProducts.erase(it);
                    return ;
                }
        }
}
void ShoppingCart::removeProduct(const char *bc,int q){
        for(list<pair<Product,int> >::iterator it = myProducts.begin(); it != myProducts.end(); ++it){
                int i = 0;
                bool found = true;
                while(bc[i]){
                        if(!found)
                                break;
                        if(bc[i] != (*it).first.barcode[i])
                                found = false;
                        ++i;
                }
                if(found){
                        if((*it).second <= q){
                                total_cost -= (*it).second * (*it).first.price;
                                myProducts.erase(it);
                        }
                        else{
                                (*it).second -= q;
                                total_cost -= (*it).first.price * q;
                        }
                        return ;
                }
        }
}
float ShoppingCart::getProductPrice(const char *bc){
        for(list<Product>::iterator it = allProducts.begin(); it != allProducts.end(); ++it){
                int i = 0;
                bool found = true;
                while(bc[i]){
                        if(!found)
                                break;
                        if(bc[i] != (*it).barcode[i])
                                found = false;
                        ++i;
                }
                if(found) return (*it).price;
        }
        return -1.0;
}
bool ShoppingCart::searchBarcode(const char *bc){
        // We have allProducts array
        for(list<Product>::iterator it = allProducts.begin(); it != allProducts.end(); ++it){
                int i = 0;
                bool found = true;
                while(bc[i]){
                        if(!found) break;
                        if(bc[i] != (*it).barcode[i]) found = false;
                        ++i;
                }
                if(found) return true;
        }
        return false;
}
void ShoppingCart::printCart(){
        int count = 0;
        for(list<pair<Product,int> >::iterator it = myProducts.begin(); it != myProducts.end(); ++it,++count){
                printf("Quantity : %i, Product : ",(*it).second);
                (*it).first.printProduct();
        }
        if(count == 0) printf("Empty Cart\n");
}
void ShoppingCart::readBarcode(){
    printf("Scan the Barcode : ");
    getchar();
    int c,q;
    char bc[30] = {'0'};
    int len = 0;
    while((c = getchar()) != '\n'){
        bc[len++] = (char)c;
    }
    printf("How many times ? ");
    scanf("%i",&q);
    addProduct(bc,q);
}
void ShoppingCart::removeBarcode(){
    printf("Scan the Barcode : ");
    getchar();

    int c,q,y;

    char bc[30] = {'0'};

    int len = 0;
    while((c = getchar()) != '\n')
        bc[len++] = (char)c;

    printf("If you want to remove completely press 1\nelse press anything else for partially : ");
    scanf("%i",&y);
    if(y == 1)
        removeProduct(bc);
    else{
        printf("How many do you want to remove ? ");
        scanf("%i",&q);
        removeProduct(bc,q);
    }
    //getchar();
}
#endif
