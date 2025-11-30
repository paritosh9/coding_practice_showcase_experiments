#include <iostream>
#include <memory>

using namespace std;

template<typename T1, typename T2>
class Rectangle{
    private :
        T1 _len;
        T2 _width;
    
    public:
        Rectangle(T1 len, T2 width) : _len(len), _width(width){
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
    unique_ptr<Rectangle<int,int>> rectPtr1(new Rectangle<int,int>(10,20));
    rectPtr1->printRect();
    
    unique_ptr<Rectangle<int,int>> rectPtr2 = move(rectPtr1);
    
    if(rectPtr1 != nullptr){
        rectPtr1->printRect();
    }else{
        cout << "unique_ptr destroyed or moved" << endl;
    }
    
    rectPtr2->printRect();
    
    unique_ptr<Rectangle<float,float>> rectPtr3 = make_unique<Rectangle<float,float>>(25,50);
    rectPtr3->printRect();
    
    ///////// shared_ptr ///////////////////
    cout <<endl;
    cout <<" shared ptr - " << endl;
    shared_ptr<Rectangle<int,int>> sharedPtr1 = make_shared<Rectangle<int,int>>(40,80);
    sharedPtr1->printRect();
    cout << "shared ptr use count - " << sharedPtr1.use_count() << endl;
    
    shared_ptr<Rectangle<int,int>> sharedPtr2(sharedPtr1);
    sharedPtr2->printRect();
    cout << "shared ptr use count - " << sharedPtr1.use_count() << endl;
    cout << "shared ptr use count - " << sharedPtr2.use_count() << endl;
    
    sharedPtr1 = nullptr;
    cout << "shared ptr use count - " << sharedPtr2.use_count() << endl;
    
    ///////// weak_ptr ///////////////////
    cout <<endl;
    cout <<" weak ptr - " << endl;
    weak_ptr<Rectangle<int,int>> weakPtr1 = sharedPtr2;
    
    if(auto tmpPtr = weakPtr1.lock()){
        tmpPtr->printRect();
    }
    cout << "weak ptr use count - " << weakPtr1.use_count() << endl;
    
    sharedPtr2.reset();
    cout << "weak ptr use count - " << weakPtr1.use_count() << endl;
    
     if (weakPtr1.expired()) {
        std::cout << "Rectangle no longer exists\n";
    }
    
    
    return 1;
}

