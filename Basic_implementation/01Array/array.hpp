#pragma once
#include <iostream>
#include <initializer_list>
class mArray{
public:
    //初始化数组，最小容量为1
    mArray(int capacity = 1):capacity_(capacity), size_(0)
    {
        mArray_ = new int [capacity];
    }
    mArray(std::initializer_list<int> list):capacity_(list.size()), 
        size_(list.size())
    {
        mArray_ = new int[capacity_];
        int i = 0;
        for(int val: list){
            mArray_[i++] = val;
        }
    }
    //销毁数组
    ~mArray()
    {
        delete []mArray_;
    }
    //只支持有效元素的随机访问
    int operator[](int index){
        if(index < 0 || index >= size_){
            std::cerr << "Array::operator[]: Array access out of bounds!\n";
            exit(-1);
        }
        return mArray_[index];
    }

    //插入元素
    //尾部插入
    void push_back(int val){
        if(size_ == capacity_){ 
            expand();
        }
        mArray_[size_++] = val;
    }
    //按下标插入，而非序号，序号的事交给调用该类的程序员
    void insert(int index, int val){
        //判断index是否合法,合法范围：数组开头直到有效元素结尾的后一位
        if(index < 0 || index > size_){
            std::cout << "mArray::insert(int index, int val) : Array access out of bounds!\n";
            return;
        }else if(index == size_){
            push_back(val);
            return;
        }
        
        if(size_ == capacity_){ 
            expand();
        }
        for(int prev = size_ - 1; prev >= index; --prev){
            mArray_[prev + 1] = mArray_[prev];
        }
        mArray_[index] = val;
        size_++;
    }
    //删除元素
    //末尾删除
    void pop_back(){
        if(size_ == 0){
            std::cout << "mArray has no elements.\n";
            return;
        }
        size_--;
    }
    //按下标删除
    void erase(int index){
        if(index < 0 || index >= size_){
            std::cout << "mArray::erase(int index): Array access out of bounds!\n";
            return;
        }
        for(int prev = index; prev < size_ - 1; ++prev){
            mArray_[prev] = mArray_[prev + 1];
        }
        size_--;
    }
    //查找元素,从头向尾线性查找，找到返回下标，没找到返回-1
    int find(int val){
        for(int i = 0; i < size_; ++i){
            if(mArray_[i] == val){
                return i;
            }
        }
        return -1;
    }
    void print(){
        std::cout << "Array: ";
        for(int i = 0; i < size_; ++i){
            std::cout << mArray_[i] << ' ';
        }
        std::cout << '\n';
    }
private:
    //扩容数组，此时capacity_ == size_
    void expand(){
        int* newArray = new int [capacity_ * 2];
        for(int i = 0; i < size_; ++i){
            newArray[i] = mArray_[i];
        }
        delete []mArray_;
        mArray_ = newArray;
        capacity_ *= 2;
    }

    int *mArray_;   //数组的起始地址
    int size_;      //有效元素的个数
    int capacity_;  //数组的容量
};