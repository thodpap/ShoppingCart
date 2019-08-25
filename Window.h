#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <cstdio>

#include "Cart.h"

class Window{
	public:
		void welcomeMsg();
		void mainMenu();
		void clearScreen(bool wantMenu = false);

		int chooseMenu();

};
void Window::welcomeMsg(){
	printf("Enjoy your shopping\n\n");
}
void Window::mainMenu(){
	printf("1. Scan Barcode\n");
	printf("2. Remove Product\n"); // I will have 2 steps
	printf("3. Check Price\n");
	printf("4. Checkout\n");
	printf("5. Print Your Cart\n");
}
int Window::chooseMenu(){
	printf("Pick a Number : ");
	int c = getchar();
	switch ((char)c) {
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		default:
			printf("Something Went Wrong... please pick again\n");
			return chooseMenu();

	}
}
void Window::clearScreen(bool wantMenu){
	for(int i = 0; i < 8; ++i)
		printf("\n");
	if(!wantMenu) return ;
	mainMenu();
	for(int i = 0; i < 10;++i)
		printf("\n");
}

#endif
