#ifndef Binary_H
#define Binary_H
#include <vector>
#include <math.h>
#include <string>

class Binary{
public:
    Binary()
    { 
        _size = 0;
        _binary = new int[_size];
    }
    Binary(int input[],int s)
    { 
        _size = s;
        _binary = new int[_size];
        for(int i = 0; i < _size; i++)
        {
            _binary[i] = input[i];
        }
    }
    Binary(const Binary & b)
    {
        _size = b._size;
        _binary = new int [_size];
        for(int i = 0; i < _size; i++)
        {
            _binary[i] = b._binary[i];
        }
    }
    ~Binary()
    {
        delete [] _binary;
    }

    Binary & operator=(Binary const &b)
    { 
        int *bin = new int [_size];
        for(int i = 0; i < _size; i++)
        {
            bin[i] = _binary[i];
        }
        //delete [] _binary;
        _binary = bin;
        bin = nullptr;

        return *this;
    }
    Binary operator+(Binary const &b){ }
    Binary operator-(Binary const &b){ }
    Binary operator>>(int a){ }
    Binary operator<<(int a){ }
    void resize(int new_size){ }
    void setBit(int pos,int a){ }
    int toInt() const
    { 
        int decimal = 0;
        for(int i = this->_size - 1; i >= 0; i--)
        {
            if (this->_binary[i] == 1)
            {
                decimal += pow(2, this->_size - 1 - i);
            }
        }
        return decimal;
    }
    std::string toString() const
    { 
        std::string zero = "0";
        std::string one = "1";
        std::string binString;
        for(int i = 0; i < _size; i++)
        {
            if(_binary[i] == 0)
            {
                binString.append(zero);
            }
            else
            {
                binString.append(one);
            }
        }
        return binString;
    }

private:
    int _size;
    int *_binary;

};

#endif