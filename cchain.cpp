#include "cchain.h"


using namespace blockchain;


CChain::CChain(int difficulty)
{
    mDifficulty = difficulty;

    mChain.push_back(CBlock(0));

    mCurrentlBlock = &mChain[0];
};


void CChain::appendToCurrentBlock(uint8_t* data, uint32_t size)
{
    mCurrentlBlock->appendData(data, size);
};


void CChain::nextBlock()
{
    CBlock block(mCurrentlBlock);

    block.mine(mDifficulty);

    mChain.push_back(block);

    mCurrentlBlock = &mChain.back();
};


CBlock* CChain::getCurrentBlock()
{
    return mCurrentlBlock;
};