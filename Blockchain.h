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

    void addBlock(Block newBlock);

private:
    uint32_t _diff;
    vector<Block> _chain;

    Block _getLastBlock() const;
};

#endif