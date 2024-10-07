#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>

#include <numeric>
#include <algorithm>
//#include <memory>

class Rectangle {
  private :
    int _len=0;
    int _breadth=0;
 
  public :
    Rectangle(int len, int breadth):_len(len), _breadth(breadth){
        std::cout << "constructing rectangle with len : " << _len << " breadth : " << _breadth << std::endl;
    }
    
    void print_rect(){
        std::cout << "print rectangle function len : " << this->_len << " breadth : " << this->_breadth << std::endl;
    }
};

void fun(){
    std::unique_ptr<Rectangle> rect_obj(new Rectangle(1,2));
    std::unique_ptr<Rectangle> rect_obj2(new Rectangle(3,4));
    rect_obj2 = std::move(rect_obj);
    rect_obj2->print_rect();
    //rect_obj->print_rect();
    
    std::unique_ptr<Rectangle> rect_obj3(new Rectangle(-1,-3));
    rect_obj3->print_rect();
    
    std::shared_ptr<Rectangle> rect_obj_shared_ptr1(new Rectangle(12,24));
    std::cout <<"use count : " << rect_obj_shared_ptr1.use_count() << std::endl;
    std::shared_ptr<Rectangle> rect_obj_shared_ptr2;
    rect_obj_shared_ptr2 = rect_obj_shared_ptr1;
    std::cout <<"use count : " << rect_obj_shared_ptr1.use_count() << std::endl;
    
    std::shared_ptr<Rectangle> rect_obj_shared_ptr3(new Rectangle(12,24));
    std::cout <<"use count : " << rect_obj_shared_ptr3.use_count() << std::endl;
    std::weak_ptr<Rectangle> rect_obj_weak_ptr1;
    rect_obj_weak_ptr1 = rect_obj_shared_ptr3;
    std::cout <<"rect_obj_weak_ptr1 use count : " << rect_obj_weak_ptr1.use_count() << std::endl;
    std::cout <<"rect_obj_shared_ptr3 use count : " << rect_obj_shared_ptr3.use_count() << std::endl;
}

int main()
{
    std::cout<<"Hello World\n";
    
    fun();
    
    return 0;
}
