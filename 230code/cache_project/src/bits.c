#include "cache.h"
#include "bits.h"

int get_set (Cache *cache, address_type address) {
  // TODO:
  //  Extract the set bits from a 32-bit address.
  //
    int block_bits = cache->block_bits;
    int set_bits = cache->set_bits;
    int tag_bits = (32 - (set_bits + block_bits));
    
    return (address << tag_bits) >> (tag_bits + block_bits);

}

int get_line (Cache *cache, address_type address) {
  // TODO:
  // Extract the tag bits from a 32-bit address.
  //
    int block_bits = cache->block_bits;
    int set_bits = cache->set_bits;
    int tag_bits = (32 - (set_bits + block_bits));
    
    return address >> (block_bits + set_bits);
  
}

int get_byte (Cache *cache, address_type address) {
  // TODO
  // Extract the block (byte index) bits from a 32-bit address.
  //
    int block_bits = cache->block_bits;
    int move_bits = (32 - (block_bits));
    
    
    return address << (move_bits)>>(move_bits);
}


