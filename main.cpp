#include <cstdio>

#include "Product.h"
#include "SuperMarket.h"
#include "Cart.h"
#include "Window.h"

int main(){
    ShoppingCart cart;
    cart.read("barcodes.txt");
    cart.printProducts();
    printf("\n");
    cart.getDiscounts("discount.txt");
    cart.printProducts();
    
    while( true ){
        cart.setValue(0.0);
        cart.clear();

        Window window;
        window.clearScreen();
        window.welcomeMsg();

        int option = 0;
        //printf("You choose %i\n",window.chooseMenu());
        while(option != 4){
            window.clearScreen();

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
                    break;
                default:
                    break;
            }
            getchar();
        }
        getchar();
    }
}
 
