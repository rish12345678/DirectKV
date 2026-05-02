#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fcntl.h>    // For open(), O_DIRECT
#include <unistd.h>   // For write(), close()
#include <stdlib.h>   // For posix_memalign

// For timing benchmarking
#include <chrono>

// Prac synchronoush DMA

int main() {
    void* buffer = nullptr; // Our buffer in memory to store a page of memory to push to disc
    posix_memalign(&buffer, 4096, 4096); // Align our buffer so that in RAM it sits at the start of a page
    auto fd = open("file.txt", O_WRONLY | O_CREAT | O_DIRECT, 0644);
    memset(buffer, 0xAB, 4096);

    auto time_start = std::chrono::steady_clock::now();
    int iter{};
    while (iter < 262144) {
        write(fd, buffer, 4096);
        iter++;
    }
    auto time_end = std::chrono::steady_clock::now();

    double elapsed_time = std::chrono::duration<double>(time_end - time_start).count();
    double gb_written = 1.0;

    double throughput = gb_written / elapsed_time;

    printf("%.2f GB written / sec\n", throughput);
}