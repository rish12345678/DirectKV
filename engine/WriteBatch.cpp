#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fcntl.h>    // For open(), O_DIRECT
#include <unistd.h>   // For write(), close()
#include <stdlib.h>   // For posix_memalign



// Prac synchronoush DMA

// This is the part of the engine that is the staging area.  We are gathering loads of requests
// and batching then together into one shipment to feed the engine.

class WriteBatch {
public:
    // Basic Constructor
    WriteBatch() : batch_("") {}

    // Byte Stream format:

    // [Type of op] [size of key] [key] [size of val] [val]

    // Operations
    void put(const Slice &key, const Slice &value) {
        char buf[sizeof(0x1) + uint32_t + sizeof(key.size()) + uint32_t + sizeof(value.size())];
        

    }

    void remove(const Slice &key) {
        // TODO: Share same format but with del intentionality and place formated byte-stream in batch
    }

private:
    std::string batch_;
}

int main() {

}