#include <iostream>
#include <memory>

class SortStrategy{
  public : 
    virtual void sort (int* arr, int size) = 0;  
};

class BubbleSort : public SortStrategy{
  public:
    void sort(int* arr, int size){
        std::cout << "bubble sort\n";
    }
};

class MergeSort : public SortStrategy{
  public:
    void sort(int* arr, int size){
        std::cout << "merge sort\n";
    }
};

class Sorter{
    private:
      SortStrategy *_strategy;
    public:
      Sorter(SortStrategy* strategy):_strategy(strategy){}
      void setStrategy(SortStrategy *strategy){
          this->_strategy = strategy;
      }
      
      void sort(int* arr, int size){
          _strategy->sort(arr,size);
      }
};

int main()
{
    std::cout << "Hello World\n";
    
    int arr[] = {1,2,3,5,21,22,11,10};
    int size = 8;
    std::unique_ptr<Sorter> sortS = std::make_unique<Sorter>(new BubbleSort());
    //Sorter *sortS = new Sorter(new BubbleSort());
    sortS->sort(arr, size);
    
    //sortS = new Sorter(new MergeSort());
    //sortS->sort(arr, size);
    sortS->setStrategy(new MergeSort());
    sortS->sort(arr, size);
    
    std::unique_ptr<Sorter> sortS1 = std::make_unique<Sorter>(new MergeSort());
    sortS->sort(arr, size);

    return 0;
}
