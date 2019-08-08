#ifndef __SUPERMARKET_H__
#define __SUPERMARKET_H__

#include <cstdio>
#include <list>

#include "Product.h"

using namespace std;

Product createProduct(const char *bc,float pr,const char *nm){
	Product p(bc,pr,nm);
	return p;
}
// This class could also be name Products, but SuperMarket seems better
class SuperMarket{
public:
    std::list<Product> allProducts;

public:
    void read(const char *file);
    void getDiscounts(const char *file);
    void printProducts();
}; 

void SuperMarket::read(const char *file){ // We could do it with threads (FORGET IT)
        FILE *input;
        input = fopen(file,"r");

        int c;
        while( (c = fgetc(input)) != EOF){
                char bc[100] = {'0'};
                char name[100] = {'0'};
                
		int pos_bc = 0;
                int pos_nm = 0;
                
		float pr = 0.0;

        while((char)(c) != ' '){
                        bc[pos_bc++] = (char)(c);
                        c = fgetc(input);
        }
                
		fscanf(input,"%f",&pr);
		
		c = fgetc(input); // I guess for the soace
		c = fgetc(input);
        while(static_cast<char>(c) != '\n' && c != EOF){
            name[pos_nm++] = (char)(c);
                        c = fgetc(input);
                }
                allProducts.push_back(createProduct((char *)(bc),pr,(char *)(name)));
        }
        fclose(input);
}
void SuperMarket::getDiscounts(const char *file){
    // It will be : barcode percentage %
    FILE *input;
    input = fopen(file,"r");
    
    int c;
    while( (c= fgetc(input)) != EOF){
        char bc[100] = {'0'};
        float per;
        int barcode = 0;
        while((char)c != ' '){
            bc[barcode++] = (char)c;
            c = fgetc(input);
        }
        fscanf(input,"%f",&per); 
        c = fgetc(input); // %
        c = fgetc(input); // \n
        // Now add the discount to the list
        for(list<Product>::iterator it = allProducts.begin(); it != allProducts.end(); ++it){
            bool found = true;
            int i = 0;
            while(bc[i]){
                if(!found) 
                    break;
                if(bc[i] != it->barcode[i]) 
                    found = false;
                ++i;
            }
            if(found) (*it).setDisc(per);
            if(found) break;
        }
    }
}
void SuperMarket::printProducts(){
        for(list<Product>::iterator it = allProducts.begin(); it != allProducts.end(); ++it)
                it->printProduct();
}


#endif
