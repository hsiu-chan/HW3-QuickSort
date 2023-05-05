# HW3-QuickSort
## Code
```c++
#include<iostream>
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
    void printArr(int* lPtr,int*rPtr){//print array
        for (int i=0;i<_arrSize;i++){
                    if(_arr+i==lPtr){
                        std::cout<<"l*";
                    }
                    if(_arr+i==rPtr){
                        std::cout<<"r*";
                    }
                    std::cout<<*(_arr+i);
                    if((i+1)!=_arrSize){std::cout<<",";}
                }
                std::cout<<"\n";
    };
    void sort();
    void swap(int*, int*);//交換
};



void QuickSort::sort(){
    std::stack<int*> lNow;//當前左邊界
    std::stack<int*> rNow;//當前右邊界
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

        /*print*/
        std::cout<<"NOW:";
        printArr(lNow.top(),rNow.top());

        //維護 lPtr 左邊小於等於pivot，維護 rPtr 右邊大於等於pivot
        while (true)
        {
            while (*(++lPtr)<pivot ){ //*lPtr>=pivot ，一定不超過邊界
                /*print*/
                std::cout<<"MOVE:";
                printArr(lPtr,rPtr);
            }

            while (*(--rPtr)>pivot ){ //*rPtr<=pivot
                /*print*/
                std::cout<<"MOVE:";
                printArr(lPtr,rPtr);                
            }
            
            
            std::cout<<"MOVE:";
            printArr(lPtr,rPtr);
            /********/

            if (lPtr>=rPtr ){break;}//交錯則跳出迴圈，*lPtr>=pivot，*rPtr<=pivot
            swap(lPtr,rPtr); //如果沒交錯維護 lPtr 左邊小於等於pivot，維護 rPtr 右邊大於等於pivot
            
        }
        std::cout<<"FINISH:"<<*(lNow.top())<<","<<*(rNow.top())<<'\n';


        /*Pop 當前區間，push 子代到 Now*/
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


void QuickSort::swap(int* x, int* y){//交換兩位置
    int cach=*x;
    *x=*y;
    *y=cach;

    /*Print*/
    std::cout<<"SWAP:";
    for (int i=0;i<_arrSize;i++){
            if(_arr+i==x ^ _arr+i==y){std::cout<<'*';}
            std::cout<<*(_arr+i);
            if((i+1)!=_arrSize){std::cout<<",";}

        }
    std::cout<<"\n";
    /**********/
}


int main(){
    const int arrSize=10;
    int arr[arrSize]={33, 67, 8, 13, 54, 119, 3, 84, 25, 41};//輸入
    QuickSort(arr,arrSize).sort();
    std::cout<<"RESULT:";
    for (auto i:arr){
        std::cout<<i<<" ";
    }
    //cout<<((arr+1)<(arr+2));

    
}

```

## Result

```
NOW:l*33,67,8,13,54,119,3,84,25,r*41
MOVE:l*33,67,8,13,54,119,3,84,25,41
MOVE:33,l*67,8,13,54,119,3,84,25,r*41
MOVE:33,l*67,8,13,54,119,3,84,r*25,41
SWAP:33,*25,8,13,54,119,3,84,*67,41
MOVE:33,25,l*8,13,54,119,3,84,r*67,41
MOVE:33,25,8,l*13,54,119,3,84,r*67,41
MOVE:33,25,8,13,l*54,119,3,r*84,67,41
MOVE:33,25,8,13,l*54,119,r*3,84,67,41
SWAP:33,25,8,13,*3,119,*54,84,67,41
MOVE:33,25,8,13,3,l*r*119,54,84,67,41
MOVE:33,25,8,13,r*3,l*119,54,84,67,41
FINISH:33,41
NOW:33,25,8,13,3,l*119,54,84,67,r*41
MOVE:33,25,8,13,3,l*119,54,84,67,r*41
SWAP:33,25,8,13,3,*41,54,84,67,*119
MOVE:33,25,8,13,3,41,l*54,84,67,r*119
MOVE:33,25,8,13,3,41,54,l*84,r*67,119
SWAP:33,25,8,13,3,41,54,*67,*84,119
MOVE:33,25,8,13,3,41,54,r*67,l*84,119
FINISH:41,119
NOW:33,25,8,13,3,41,54,67,l*84,r*119
MOVE:33,25,8,13,3,41,54,67,l*84,119
MOVE:33,25,8,13,3,41,54,67,84,l*r*119
MOVE:33,25,8,13,3,41,54,67,r*84,l*119
FINISH:84,119
NOW:33,25,8,13,3,l*41,54,r*67,84,119
MOVE:33,25,8,13,3,l*41,54,67,r*84,119
MOVE:33,25,8,13,3,41,l*54,r*67,84,119
MOVE:33,25,8,13,3,41,l*r*54,67,84,119
FINISH:41,67
NOW:33,25,8,13,3,l*41,r*54,67,84,119
MOVE:33,25,8,13,3,l*41,54,r*67,84,119
MOVE:33,25,8,13,3,41,l*r*54,67,84,119
MOVE:33,25,8,13,3,r*41,l*54,67,84,119
FINISH:41,54
NOW:l*33,25,8,13,r*3,41,54,67,84,119
MOVE:l*33,25,8,13,r*3,41,54,67,84,119
SWAP:*3,25,8,13,*33,41,54,67,84,119
MOVE:3,l*25,8,r*13,33,41,54,67,84,119
SWAP:3,*13,8,*25,33,41,54,67,84,119
MOVE:3,13,l*8,r*25,33,41,54,67,84,119
MOVE:3,13,r*8,l*25,33,41,54,67,84,119
FINISH:3,33
NOW:3,13,8,l*25,r*33,41,54,67,84,119
MOVE:3,13,8,l*25,33,r*41,54,67,84,119
MOVE:3,13,8,25,l*r*33,41,54,67,84,119
MOVE:3,13,8,r*25,l*33,41,54,67,84,119
FINISH:25,33
NOW:l*3,13,r*8,25,33,41,54,67,84,119
MOVE:l*3,13,8,r*25,33,41,54,67,84,119
MOVE:3,l*13,r*8,25,33,41,54,67,84,119
MOVE:3,l*r*13,8,25,33,41,54,67,84,119
MOVE:r*3,l*13,8,25,33,41,54,67,84,119
FINISH:3,8
NOW:3,l*13,r*8,25,33,41,54,67,84,119
MOVE:3,l*13,r*8,25,33,41,54,67,84,119
SWAP:3,*8,*13,25,33,41,54,67,84,119
MOVE:3,r*8,l*13,25,33,41,54,67,84,119
FINISH:8,13
RESULT:3 8 13 25 33 41 54 67 84 119
```
