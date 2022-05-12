#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>

unsigned int random(unsigned int seed = 4816)
{
    //randomise seed for better result
    //get current time
    static unsigned int base = time(0);

    //generate random number using seed

    base = base * 87146 + seed - base;
    base = base % 4416;
    if (base % 613 > 126)
    {
        base = base + base % 4416;
        return base;
    }
    else
    {
        return base;
    }

}


int main()
{

    int amountOfNumbers;
    std::cout << "Enter amount of numbers being generated: ";
    std::cin >> amountOfNumbers;

    auto t1 = std::chrono::high_resolution_clock::now();

    for (int i = 11; i < amountOfNumbers + 11; i++)
    {
        int lastDigit = amountOfNumbers % 10;

        if (i % 10 == 1 && i != 0)
        {
            if (i - 11 + lastDigit == amountOfNumbers)
            {
                std::cout << "[" << i - 11 + lastDigit << "]\t";
            }
            else 
            {
                std::cout << "[" << i - 1 << "]\t";
            }
        }
        if (i != 0)
        {
            std::cout << random() << '\t';
        }

        if (i % 10 == 0 && i != 1)
        {
            std::cout << std::endl;
        }
    }


    auto t2 = std::chrono::high_resolution_clock::now();
    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);


    std::cout << "\n" << "\n" << "Finished in " << ms_int.count() << "ms" << '\n';
    system("pause");
    return 0;
}