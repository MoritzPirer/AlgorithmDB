#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <sstream>
#include <string>
using namespace std;

/* Sorting arrays is hard work and not everyone has the time required to just sit by and
 * optimize an algorithm away. Sleep sort takes your stress away, by just waiting the
 * amount of seconds for the number inside the array and then printing it one after the other.
 * This way you can do something else in the meantime and come back to a sorted array, without
 * wasting calculation-resources - seeing as your computer still works while you're away.
 */

mutex output_mutex;

void sleep_n_print(int value)
{
    this_thread::sleep_for(chrono::seconds(value)); // Putting in in seconds to waste your time and worsen runtime >:)

    // SLP putting in some work
    lock_guard<mutex> lock(output_mutex);
    cout << value << " " << flush;
}

vector<int> read_array_line()
{
    cout << "Enter your array space-separated: ";

    string line;
    getline(cin >> ws, line);

    stringstream ss(line);
    vector<int> values;

    int ch;
    while (ss >> ch)
        values.push_back(ch);

    return values;
}

int main()
{
    vector<int> values = read_array_line();

    vector<thread> threads;

    for (int v : values)
        threads.emplace_back(sleep_n_print, v);

    for (auto& t : threads)
        t.join();

    cout << endl;
    return 0;
}
