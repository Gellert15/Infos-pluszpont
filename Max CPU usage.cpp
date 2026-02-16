#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

/**
 * Ez a függvény végzi a nehéz munkát.
 * A 'volatile' kulcsszó biztosítja, hogy a fordító ne dobja ki a ciklust
 * optimalizáláskor, így valóban terheli a processzort.
 */
void run_stress_test() {
    volatile double dummy_val = 1.0;
    while (true) {
        dummy_val *= 1.0000001; // Folyamatos műveletvégzés
    }
}

int main() {
    // Lekérdezzük a logikai processzormagok számát
    const auto core_count = std::thread::hardware_concurrency();

    std::cout << "--- CPU Terheles Inditasa ---" << std::endl;
    std::cout << "Eszlelt szalak szama: " << core_count << std::endl;

    std::vector<std::thread> workers;
    workers.reserve(core_count); // Előre lefoglaljuk a helyet a vektornak

    // Szálak létrehozása és indítása
    for (unsigned int i = 0; i < core_count; ++i) {
        workers.emplace_back(std::thread(run_stress_test));
    }

    std::cout << "Minden mag 100%-on porog. Leallitashoz zard be a programot!" << std::endl;

    // Megvárjuk, amíg a szálak végeznek (ami sosem fog megtörténni a while(true) miatt)
    for (auto& worker : workers) {
        if (worker.joinable()) {
            worker.join();
        }
    }

    return 0;
}
