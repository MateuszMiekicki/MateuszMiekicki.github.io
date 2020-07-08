#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>
#include <vector>

struct safeThreadCout : public std::stringstream
{
    static inline std::mutex cout_mutex;
    ~safeThreadCout()
    {
        std::lock_guard<std::mutex> l{cout_mutex};
        std::cout << rdbuf();
        std::cout.flush();
    }
};
static void print_cout(int id)
{
    std::cout << "Cout o numerze " << id << '\n';
}
static void print_safeThreadCout(int id)
{
    safeThreadCout{} << "safeThreadCout o numerze " << id << '\n';
}
int main()
{
    std::vector<std::thread> threads;
    for (size_t i{0}; i < 10; ++i)
    {
        threads.emplace_back(print_cout, i);
    }
    for (auto &thread : threads)
    {
        thread.join();
    }
    std::cout << "=====================\n";
    threads.clear();
    for (size_t i{0}; i < 10; ++i)
    {
        threads.emplace_back(print_safeThreadCout, i);
    }
    for (auto &thread : threads)
    {
        thread.join();
    }
}