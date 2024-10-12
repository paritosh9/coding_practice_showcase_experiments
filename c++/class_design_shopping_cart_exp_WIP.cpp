#include <iostream>

class ShoppingCart{
private:
int _c_id;
std::vector<Product*> _p;
public:
  ShoppingCart(int c_id, std::vector<Product*> p1) : _c_id(c_id), _p(p1){}
  addProduct(Product* p){
      _p.push_back(p);
  }
  removeProduct(Product *p){
      //search and remove or change datastructure for easy search
  }
  
  order(){
      //loop over cart and find total
  }
};

class Product{
 private:
   int _id;
   string _name;
   //bool _avail;
   float _cost;
   int _quantity;
 public:
   Product(int id, string name, /*bool avail*/, float cost, int quantity):_id(id), _name(name), _avail(avail), _cost(cost),_quantity(quantity){
       
   }
};

class Order{
    
};

int main()
{
    std::cout<<"Hello World\n";
    
    ShoppingCart sc1(int customer_id, std::vector<Product*> p1)
    sc1.addproduct(Product *p2)
    sc1.order();

    return 0;
}
