#ifndef _BLOCKCHAIN
#define _BLOCKCHAIN

#include <cstdint>
#include <vector>
#include "Block.h"
using namespace std;

class Blockchain
{
public:
    Blockchain();

    void AddBlock(Block newBlock);

private:
    uint32_t _diff;
    vector<Block> _chain;

    Block _GetLastBlock() const;
};

#endif