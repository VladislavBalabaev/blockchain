#ifndef __C_CHAIN_INCLUDED__
#define __C_CHAIN_INCLUDED__
#include "cblock.h"
#include <vector>


namespace blockchain
{
    class CChain
    {
    private:
        std::vector<CBlock> mChain;

        CBlock* mCurrentlBlock;

        int mDifficulty;


    public:
        CChain(int difficulty);

        void appendToCurrentBlock(uint8_t* data, uint32_t size);
        
        void nextBlock();

        CBlock* getCurrentBlock();
    };
};


#endif