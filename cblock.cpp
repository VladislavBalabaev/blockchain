#include "cblock.h"
#include <stdio.h>
#include <string.h>
// https://www.youtube.com/watch?v=cFSb7WEnXeY&t=6s

using namespace blockchain;


CBlock::CBlock(CBlock* prevBlock)
{
    mPrevBlock = prevBlock;

    memset(mHash, SHA256_DIGEST_LENGTH, 0);                 // initialize mHash with null

    // if (mPrevBlock)
        // memcpy(mPrevHash, )
};