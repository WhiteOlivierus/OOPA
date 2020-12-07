#pragma once

#include <string>
#include <ostream>

class Block
{
public:
    Block(int size, std::string name);
    // 'big three'
    virtual ~Block() noexcept;            // destructor
    Block(const Block &other);            // copy-constructor
    Block &operator=(const Block &other); // assignment-operator

    // nog nodig voor de 'big five'
    Block(Block &&other) noexcept;  // move-constructor
    Block operator=(Block &&block); //TODO: move-assignment operator

private:
    std::string name;
    int *data;
    int size;

    friend std::ostream &operator<<(std::ostream &os, const Block &block);
};