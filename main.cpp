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
    Array() : List(nullptr), Capacity(0), Size(0) {}// Lista nu e alocata, Capacity si Size = 0

    ~Array()// destructor
    {
        for (int i = 0; i < Size; ++i)
        {
            delete List[i];
        }
        delete[] List;
    }

    Array(int capacity) : Capacity(capacity), Size(0)// Lista e alocata cu 'capacity' elemente
    {
        List = new T * [Capacity];
    }

    Array(const Array<T>& otherArray) : Capacity(otherArray.Capacity), Size(otherArray.Size)// constructor de copiere
    {
        List = new T * [Capacity];
        for (int i = 0; i < Size; ++i)
        {
            List[i] = new T(*otherArray.List[i]);
        }
    }

    T& operator[](int index)// arunca exceptie daca index este out of range
    {
        CheckIndex(index);
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem)// adauga un element de tipul T la sfarsitul listei si returneaza this
    {
        if (Size >= Capacity)
        {
            throw CapacityExceededException();
        }
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem)// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
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

    const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
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

    const Array<T>& Delete(int index)// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
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

    void Sort()// sorteaza folosind comparatia intre elementele din T
    {
        std::sort(List, List + Size, [](T* a, T* b) { return *a < *b; });
    }

    void Sort(int(*compare)(const T&, const T&))// sorteaza folosind o functie de comparatie
    {
        std::sort(List, List + Size, [compare](T* a, T* b) { return compare(*a, *b) < 0; });
    }

    void Sort(Compare* comparator)// sorteaza folosind un obiect de comparatie
    {
        std::sort(List, List + Size, [comparator](T* a, T* b) { return comparator->CompareElements(a, b) < 0; });
    }

    int BinarySearch(const T& elem)// cauta un element folosind binary search in Array
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

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
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

    int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator

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

    int Find(const T& elem)// cauta un element in Array
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

    int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
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

    int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
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
