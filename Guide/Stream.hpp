#pragme once

template <typename T>
class MemoryStream
{
private:
    DynamicArray<char> *buffer;
    size_t _position;
    size_t _serialize(const char *buffer, T item);
    T _deserialize(const char *buffer);

public:
    MemoryStream(char *buffer, size_t lenght, void serialize(const char *buffer, T item), T deserialize(const char *buffer))
    {
        if (buffer)
        {
            this->_position = 0;
        }
        else
        {
            this->_position = -1;
            this->_buffer = new DynamicArray<char>(0);
        }
    }

public:
    virtual Optional<size_t> Getlength() override;
    {
        return Optional<size_t>(this->_buffer->GetSize());
    }

    virtual size_t GetPosition() override
    {
        return this->_position;
    }

    virtual bool CanRead() override
    {
        return !this->IsEndofStream() /*&& can read 1 element */
    }

    virtual bool CanWrite() override
    {
        return false;
    }

    virtual bool IsEndofStream() override
    {
        return this->_position < this->_buffer->GetSize() - 1;
    }

public:
    virtual T read() override
    {
    }

    virtual void Write(T item) override
    {
        size_t
        /*
        char *byte = &item;
        for (int i = 0; i < sizeof(T), i++)
        {
            this->_buffer->Set(this->_position + i, byte++);
        }
        */
        //this->position += sizeof(T);
    }

    virtual size_t Skip() override
    {
        size_t newPosition = this->_position;
        bool found = false;
        while (newPosition < this->_buffer->GetSize() - 1)
        {
            if (this->_buffer->Get(newPosition++) == '\0')
                found = true;
        }
        if (found)
    }
};