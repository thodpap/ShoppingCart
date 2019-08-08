#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <stdio.h>

class Product{
public:
    char barcode[30];
    char name[50];
    int barcodeLength;
    int nameLength;
    
    float fullPrice;
    float price;

public:
    Product(const char *bc,float pr,const char *nm);

    void printProduct();
    void setDisc(float per);
};
Product::Product(const char *bc,float pr,const char *nm){
	fullPrice = pr;
	price = pr;
    barcodeLength = 0;
	nameLength = 0;

	while(bc[barcodeLength]){
		barcode[barcodeLength] = bc[barcodeLength];
		++barcodeLength;
	}
	while(nm[nameLength]){
		name[nameLength] = nm[nameLength];
		++nameLength;
	}
    for(int i = barcodeLength; i < 30; ++i) barcode[i] = '\0';
    for(int i = nameLength; i < 50; ++i) name[i] = '0';
}
void Product::setDisc(float per){ // x%, per = x
    price -= per * fullPrice / 100.0;
}    
void Product::printProduct(){
	for(int i = 0; i < barcodeLength; ++i) printf("%c",barcode[i]);
    printf(" %.3f ",static_cast<double>(price));
	for(int i = 0; i < nameLength; ++i) printf("%c",name[i]);
	printf("\n");
}

#endif
