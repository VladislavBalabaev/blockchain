#ifndef __C_BLOCK_INCLUDED__
#define __C_BLOCK_INCLUDED__
#include <string>
#include <openssl/sha.h>


namespace blockchain
{
    class CBlock
    {
        private:
        uint8_t mHash[SHA256_DIGEST_LENGTH];                // current hash
        uint8_t mPrevHash[SHA256_DIGEST_LENGTH];            // previous hash
        CBlock* mPrevBlock;                                 // a pointer to previous block
        uint8_t* mData;                                     // byte data of the transactions
        uint32_t mDataSize;                                 // size of the data
        time_t mCreatedTS;                                  // timestamp of block creation
        uint32_t mNonce;                                    // nonce of the block


        public:
        CBlock(CBlock* prevBlock);                          // constructor
        void calculateHash();                               // calculates sha256 hash
        uint8_t getHash();                                  // current hash -> mHash
        std::string getHashStr();                           // get string representation of the hash
        CBlock* getPrevBlock();                             // get a pointer to the previous block
        void appendData(uint8_t* data, uint32_t size);      // append data to the mData
        bool isDifficulty(int difficulty);                  // difficulty
        void mine(int difficulty);                          // mine the block
        uint32_t getNonce();                                // get nonce value
    };
};


#endif