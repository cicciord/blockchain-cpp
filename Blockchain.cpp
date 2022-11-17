#include "Blockchain.h"

Blockchain::Blockchain()
{
    _chain.emplace_back(Block(0, "Genesis Block"));
    _diff = 6;
}

void Blockchain::addBlock(Block newBlock)
{
    newBlock.prevHash = _getLastBlock().getHash();
    newBlock.mineBlock(_diff);
    _chain.push_back(newBlock);
}

Block Blockchain::_getLastBlock() const
{
    return _chain.back();
}