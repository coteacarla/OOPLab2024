#pragma once
class Sort
{
private:
    int* v;
    int count;
    public:
        // add constuctors
        Sort(int n, int mini, int maxi);
        Sort(int a[10001], int nr);
        Sort(int nrparametrii...);
        Sort(char* s);
        Sort();
        void InsertSort(bool ascendent);
        void QuickSort(bool ascendent);
        void BubbleSort(bool ascendent);
        void Print();
        int  GetElementsCount();
        int  GetElementFromIndex(int index);
 

};

