# supermarket
Super Market in C++

Before the actual program starts, it reads from .txt files the barcodes that the shop owns with the respected barcodes and 
prices. Also, I have added the aspect that the shop might by on sales, or in a supermarket for example might have multiple
products on sales in different times. Therefore, for each product it is stored a specific value (with its discount).

When the "actual program" starts, it goes through a loop. When the loop starts, it means that the previous customer concluded
his shopping, and a new customer started. 

The customer has 5 options:
1) Add a product to Cart
2) Remove a product from Cart
3) Find the respected full price that the products in the Cart has
4) Checkout, aka finish his shopping
5) Print his Cart

When a customer adds a product, he can add 1 or multipe times the same products
Moreover, when a customer wants to remove a product, he can remove it completely or partially. 
