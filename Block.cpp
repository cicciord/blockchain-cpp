#include "Block.h"
#include "sha256.h"

/**
 * CONSTRUCTOR
 */
Block::Block(uint32_t indexIn, const string &dataIn) : _index(indexIn), _data(dataIn)
{
    _nonce = -1;
    _time = time(nullptr);
}

/**
 * block's hash accessor
 */
string Block::getHash()
{
    return _hash;
}

/**
 * block mining method
 */
void Block::mineBlock(uint32_t diff)
{
    // create a string of zeros as long as the difficulty
    char chstr[diff + 1];
    for (uint32_t i = 0; i < diff; i++)
    {
        chstr[i] = '0';
    }
    chstr[diff] = '\0';
    string str(chstr);

    // loop until the beginning of the hash starts with zeros
    while (_hash.substr(0, diff) != str)
    {
        _nonce++;
        _hash = _calculateHash();
    }

    cout << "Block mined: " << _hash << endl;
}

inline string Block::_calculateHash() const
{
    stringstream strs;
    strs << _index << _time << _data << _nonce << prevHash;

    return sha256(strs.str());
}