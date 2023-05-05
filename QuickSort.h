#include <stack>

class QuickSort
{
private:
    int* _arr;
    int _arrSize;
public:
    QuickSort(int* arr,int arrSize){
        _arr=arr;
        _arrSize=arrSize;
    };
    ~QuickSort();
    void sort();

    void swap(int*, int*);
    void printArr(int* lPtr,int*rPtr){
        for (int i=0;i<_arrSize;i++){
                    if(_arr+i==lPtr){
                        std::cout<<'l';
                    }
                    if(_arr+i==rPtr){
                        std::cout<<'r';
                    }
                    std::cout<<*(_arr+i)<<',';
                }
                std::cout<<"\n";
    };
};



void QuickSort::sort(){
    std::stack<int*> lNow;
    std::stack<int*> rNow;
    lNow.push(_arr);
    rNow.push(_arr+_arrSize-1);

    while (!lNow.empty() )
    {
        if (lNow.top()>=rNow.top()){
            lNow.pop();
            rNow.pop();
            continue;
        }

        /* part of top */
        int* lPtr=lNow.top()-1;
        int* rPtr=rNow.top()+1;
        int pivot =(*lNow.top()+*rNow.top())/2;

        std::cout<<"NOW:";
        printArr(lPtr,rPtr);


        //維護 lPtr 左邊小於等於pivot，維護 rPtr 右邊大於等於pivot
        while (true)
        {
            while (*(++lPtr)<pivot ){ //*lPtr>=pivot ，一定不超過邊界

                std::cout<<"MOVE:";
                printArr(lPtr,rPtr);
                

            }
            while (*(--rPtr)>pivot ){ //*rPtr<=pivot
                
                std::cout<<"MOVE:";
                printArr(lPtr,rPtr);
                
            }
            std::cout<<"MOVE:";
            printArr(lPtr,rPtr);

            if (lPtr>=rPtr ){break;}
            swap(lPtr,rPtr); //維護 lPtr 左邊小於等於pivot，維護 rPtr 右邊大於等於pivot
            
            
            
            
            
        }
        std::cout<<"FINISH:"<<*(lNow.top())<<","<<*(rNow.top())<<'\n';

        



        /* lNow:[l0] rNow:[r0]  --> lNow:[l0], rNow:[] */
        int* rTmp=rNow.top();
        rNow.pop();
        /* left part  lNow:[l0], rNow:[] --> lNow:[l0], rNow:[r1] */
        rNow.push(rPtr);
        /* right part  lNow:[l0], rNow:[r1] --> lNow:[l1,l0], rNow:[r0,r1]*/
        lNow.push(rPtr+1);
        rNow.push(rTmp);
        

    }
}


void QuickSort::swap(int* x, int* y){
    int cach=*x;
    *x=*y;
    *y=cach;

    std::cout<<"SWAP:";
    for (int i=0;i<_arrSize;i++){
            if(_arr+i==x ^ _arr+i==y){
                std::cout<<'*';
            }
            std::cout<<*(_arr+i)<<',';

        }
    std::cout<<"\n";
}

QuickSort::~QuickSort()
{
}
