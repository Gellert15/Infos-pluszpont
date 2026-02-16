#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

/**
 * Ez a program fokozatosan felemészti a rendszer szabad memóriáját.
 * A memset helyett modern C++ megközelítést és típusokat használunk.
 */
int main() {
    // A char* helyett tárolhatunk void*-ot is, mivel csak a helyfoglalás a lényeg
    std::vector<void*> allocated_blocks;
    unsigned long long allocated_megabytes = 0;

    std::cout << "--- RAM Terheles Elinditva ---" << std::endl;

    try {
        while (true) {
            const size_t one_megabyte = 1024 * 1024;
            
            // Memória lefoglalása
            char* buffer = new char[one_megabyte];

            // Az operációs rendszer csak akkor dedikál valódi fizikai RAM-ot, 
            // ha írunk is bele. A std::fill egy modern alternatíva a memset-re.
            for (size_t i = 0; i < one_megabyte; i += 4096) {
                buffer[i] = 0; 
            }

            allocated_blocks.push_back(buffer);
            allocated_megabytes++;

            // Csak minden 100. MB után írjuk ki, hogy ne lassítsa a konzol a futást
            if (allocated_megabytes % 100 == 0) {
                std::cout << "Lefoglalt mennyiseg: " << allocated_megabytes << " MB" << std::endl;
            }
        }
    } catch (const std::bad_alloc& e) {
        // Ha elfogy a RAM, a 'new' dob egy kivételt, amit itt elkapunk
        std::cerr << "\nHIBA: Elfogyott a szabad memoria! (" << e.what() << ")" << std::endl;
    }

    return 0;
}
