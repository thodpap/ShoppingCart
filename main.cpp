#include <cstdio>
#include <iostream>
#include <unistd.h>

#include "Product.h"
#include "SuperMarket.h"
#include "Cart.h"
#include "Window.h"

int main(){
	ShoppingCart cart;
        cart.read("barcodes.txt");

        cart.getDiscounts("discount.txt");

	while( true ){
		cart.setValue(0.0);
		cart.clear();

                Window window;
		window.welcomeMsg();

                int option = 0;

                while(option != 4){
			window.mainMenu();
			option = window.chooseMenu();

			switch (option) {
				case 1: // addProduct
					cart.readBarcode();
					break;
				case 2: // Remove Product
					cart.removeBarcode(); 
					break;
				case 3: // Print price
                                        cart.printPrice();
					break;
				case 4: // Checkout
                                        printf("Checkout : $%.3f\n",cart.getPrice());
					break;
				case 5: // Print list of Products 
					cart.printCart();
                                        cart.printPrice();
					break;
				default:
					break;
                        }

                        if(option >= 3)
                            sleep(3);

                        getchar();

                        system("clear");
		}
		getchar();
		window.clearScreen();
	}
}

