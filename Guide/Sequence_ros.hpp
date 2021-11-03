template <typename T>
class Sequence
{
protected:
    int length;

public:
    int GetLength() const
    {
        return this->length;
    }
    bool IsEmpty()
    {
        return this->length == 0;
    }

public:
    virtual void SetSize(int size) = 0; //
    virtual int GetSize() const = 0;    //
    virtual T Get(int index) const = 0; //
    virtual T GetFirst() const = 0;     //
    virtual T GetLast() const = 0;      //
    virtual Sequence<T> *GetSubsequence(int startIndex, int endIndex) const = 0;
    virtual void Print() const = 0;

public:
    // virtual void Set(int index, T item) = 0;
    virtual void Append(T item) = 0;  //
    virtual void Prepend(T item) = 0; //
    virtual void InsertAt(int index, T item) = 0;
    // virtual bool Remove(T item) = 0;
    virtual void DeleteAt(int index) = 0;
    virtual void DeleteLast() = 0;
    virtual void DeleteFirst() = 0;
};