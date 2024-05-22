#include <iostream>
#include <exception>
#include <algorithm> 

using namespace std;

class DivisionByZeroException : public exception
{
    virtual const char* what() const throw()
    {
        return "Division by zero!";
    }
};

class IndexOutOfBoundsException : public exception
{
    virtual const char* what() const throw()
    {
        return "Index is out of bounds!";
    }
};

class CapacityExceededException : public exception
{
    virtual const char* what() const throw()
    {
        return "Array capacity exceeded!";
    }
};

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator
{
private:
    int Current;
    T** List;
public:
    ArrayIterator() : Current(0), List(nullptr) {}
    ArrayIterator(T** list, int start) : List(list), Current(start) {}

    ArrayIterator& operator++ ()
    {
        ++Current;
        return *this;
    }

    ArrayIterator& operator-- ()
    {
        --Current;
        return *this;
    }

    bool operator= (ArrayIterator<T>& other)
    {
        return List == other.List && Current == other.Current;
    }

    bool operator!= (ArrayIterator<T>& other)
    {
        return !(*this == other);
    }

    T* GetElement()
    {
        return List[Current];
    }
};

template<class T>
class Array
{
private:
    T** List;
    int Capacity;
    int Size;

    void CheckIndex(int index) const
    {
        if (index < 0 || index >= Size)
        {
            throw IndexOutOfBoundsException();
        }
    }

public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    ~Array()
    {
        for (int i = 0; i < Size; ++i)
        {
            delete List[i];
        }
        delete[] List;
    }

    Array(int capacity) : Capacity(capacity), Size(0)
    {
        List = new T * [Capacity];
    }

    Array(const Array<T>& otherArray) : Capacity(otherArray.Capacity), Size(otherArray.Size)
    {
        List = new T * [Capacity];
        for (int i = 0; i < Size; ++i)
        {
            List[i] = new T(*otherArray.List[i]);
        }
    }

    T& operator[](int index)
    {
        CheckIndex(index);
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem)
    {
        if (Size >= Capacity)
        {
            throw CapacityExceededException();
        }
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem)
    {
        if (index < 0 || index > Size)
        {
            throw IndexOutOfBoundsException();
        }
        if (Size >= Capacity)
        {
            throw CapacityExceededException();
        }

        for (int i = Size; i > index; --i)
        {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        ++Size;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray)
    {
        if (index < 0 || index > Size)
        {
            throw IndexOutOfBoundsException();
        }
        if (Size + otherArray.Size > Capacity)
        {
            throw CapacityExceededException();
        }

        for (int i = Size - 1; i >= index; --i)
        {
            List[i + otherArray.Size] = List[i];
        }
        for (int i = 0; i < otherArray.Size; ++i)
        {
            List[index + i] = new T(*otherArray.List[i]);
        }
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index)
    {
        CheckIndex(index);
        delete List[index];
        for (int i = index; i < Size - 1; ++i)
        {
            List[i] = List[i + 1];
        }
        --Size;
        return *this;
    }

    bool operator=(const Array<T>& otherArray)
    {
        if (this != &otherArray)
        {
            for (int i = 0; i < Size; ++i)
            {
                delete List[i];
            }
            delete[] List;

            Capacity = otherArray.Capacity;
            Size = otherArray.Size;
            List = new T * [Capacity];
            for (int i = 0; i < Size; ++i)
            {
                List[i] = new T(*otherArray.List[i]);
            }
        }
        return true;
    }

    void Sort()
    {
        std::sort(List, List + Size, [](T* a, T* b) { return *a < *b; });
    }

    void Sort(int(*compare)(const T&, const T&))
    {
        std::sort(List, List + Size, [compare](T* a, T* b) { return compare(*a, *b) < 0; });
    }

    void Sort(Compare* comparator)
    {
        std::sort(List, List + Size, [comparator](T* a, T* b) { return comparator->CompareElements(a, b) < 0; });
    }

    int BinarySearch(const T& elem)
    {
        int left = 0, right = Size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (*List[mid] == elem)
            {
                return mid;
            }
            else if (*List[mid] < elem)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
    {
        int left = 0, right = Size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int comp = compare(*List[mid], elem);
            if (comp == 0)
            {
                return mid;
            }
            else if (comp < 0)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator)
    {
        int left = 0, right = Size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int comp = comparator->CompareElements(List[mid], (void*)&elem);
            if (comp == 0)
            {
                return mid;
            }
            else if (comp < 0)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }

    int Find(const T& elem)
    {
        for (int i = 0; i < Size; ++i)
        {
            if (*List[i] == elem)
            {
                return i;
            }
        }
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size; ++i)
        {
            if (compare(*List[i], elem) == 0)
            {
                return i;
            }
        }
        return -1;
    }

    int Find(const T& elem, Compare* comparator)
    {
        for (int i = 0; i < Size; ++i)
        {
            if (comparator->CompareElements(List[i], (void*)&elem) == 0)
            {
                return i;
            }
        }
        return -1;
    }

    int GetSize() const
    {
        return Size;
    }

    int GetCapacity() const
    {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator()
    {
        return ArrayIterator<T>(List, 0);
    }

    ArrayIterator<T> GetEndIterator()
    {
        return ArrayIterator<T>(List, Size);
    }
};

// Example usage
int main()
{
    try
    {
        Array<int> arr(5);
        arr += 1;
        arr += 2;
        arr += 3;
        arr.Insert(1, 4);

        for (int i = 0; i < arr.GetSize(); ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        arr.Delete(2);
        for (int i = 0; i < arr.GetSize(); ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        arr.Sort();
        for (int i = 0; i < arr.GetSize(); ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    catch (const exception& e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
