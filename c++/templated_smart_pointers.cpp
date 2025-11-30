#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class Rectangle{
    private :
        T _len, _width;
    
    public:
        Rectangle(T len, T width) : _len(len), _width(width){
            cout << "Constructed Rectangle with len : " << _len << " width : " << _width << endl;
        }
        
        void printRect(){
            cout << "print rect len : " << _len << " type : "<< typeid(_len).name() 
                << " | width : "  << _width << " type : "<< typeid(_width).name() << endl;
        }
        
    
};

int main(){
    
    ///////// unique_ptr ///////////////////
    cout <<" unique ptr - " << endl;
    unique_ptr<Rectangle<int>> rectPtr1(new Rectangle<int>(10,20));
    rectPtr1->printRect();
    
    unique_ptr<Rectangle<int>> rectPtr2 = move(rectPtr1);
    
    if(rectPtr1 != nullptr){
        rectPtr1->printRect();
    }else{
        cout << "unique_ptr destroyed or moved" << endl;
    }
    
    rectPtr2->printRect();
    
    unique_ptr<Rectangle<float>> rectPtr3 = make_unique<Rectangle<float>>(25,50);
    rectPtr3->printRect();
    
    ///////// shared_ptr ///////////////////
    cout <<endl;
    cout <<" shared ptr - " << endl;
    shared_ptr<Rectangle<int>> sharedPtr1 = make_shared<Rectangle<int>>(40,80);
    sharedPtr1->printRect();
    cout << "shared ptr use count - " << sharedPtr1.use_count() << endl;
    
    shared_ptr<Rectangle<int>> sharedPtr2(sharedPtr1);
    sharedPtr2->printRect();
    cout << "shared ptr use count - " << sharedPtr1.use_count() << endl;
    cout << "shared ptr use count - " << sharedPtr2.use_count() << endl;
    
    sharedPtr1 = nullptr;
    cout << "shared ptr use count - " << sharedPtr2.use_count() << endl;
    
    ///////// weak_ptr ///////////////////
    return 1;
}
