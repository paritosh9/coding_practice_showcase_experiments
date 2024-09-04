
#include <iostream>

class experiment {
    private :
      int xyz;
    public :
      int abc;
      void hello_exp() {
          std::cout << "hellow exp\n";
      }
      
      experiment(int value) : xyz(value){
          
      }
};

int main()
{
    experiment exp1(2);
    exp1.hello_exp();
    
    std::cout<<"Hello World";

    return 0;
}


/// move constructor example
// C++ program for demonstrating the use of
// move constructor
#include <iostream>
#include <vector>
using namespace std;

// Move Class
class Move {
private:
    // Declare the raw pointer as
    // the data member of class
    int* data;

public:
    // Constructor
    Move(int d)
    {
        // Declare object in the heap
        data = new int;
        *data = d;
        cout << "Constructor is called for " << d << endl;
    };

    // Copy Constructor
    Move(const Move& source)
        : Move{ *source.data }
    {

        // Copying the data by making
        // deep copy
        cout << "Copy Constructor is called -"
             << "Deep copy for " << *source.data << endl;
    }

    // Move Constructor
    Move(Move&& source)
        : data{ source.data }
    {

        cout << "Move Constructor for " << *source.data
             << endl;
        source.data = nullptr;
    }

    // Destructor
    ~Move()
    {
        if (data != nullptr)

            // If pointer is not pointing
            // to nullptr
            cout << "Destructor is called for " << *data
                 << endl;
        else

            // If pointer is pointing
            // to nullptr
            cout << "Destructor is called"
                 << " for nullptr " << endl;

        // Free up the memory assigned to
        // The data member of the object
        delete data;
    }
};

// Driver Code
int main()
{
    // Vector of Move Class
    vector<Move> vec;

    // Inserting Object of Move Class
    vec.push_back(Move{ 10 });
    vec.push_back(Move{ 20 });
    return 0;
}

////////////////////////////
//////////////////////////
//// virtual destructor experiment code //////
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// C++ program without declaring the

#include <iostream>
#include <vector>
using namespace std;

class experiment {
  private :
    int var1;
    
  protected :
    
  public :
    experiment(){
        cout << "constructing default base experiment\n";
    }
    experiment(int var) : var1(var){
        cout << "constructing base experiment\n";
    }
    virtual ~experiment(){
        cout << "deleting experiment\n";
    }
    void getter(){
        cout << "var = " << var1 << endl;
    }
};

class sub_experiment : public experiment {
  private :
    int var1;
    
  protected :
    
  public :
    sub_experiment(int var) : var1(var){
        cout << "constructing derived sub_experiment\n";
    } 
    void getter(){
        cout << "var = " << var1 << endl;
    }
    ~sub_experiment(){
        cout << "deleting sub_experiment\n";
    }
};
// Driver Code
int main()
{
  cout << "in main\n";
  experiment *exp1 = new experiment(5);
  sub_experiment *subexp1 = new sub_experiment(4);
  
  exp1->getter();
  subexp1->getter();
  
  exp1 = subexp1;
  delete exp1;
  return 0;
}
//////////////////////
//////////////////////
