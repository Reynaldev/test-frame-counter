#include <iostream>
#include <ctime>
#include <vector>
#include <Windows.h>

typedef char i8;
typedef unsigned char u8;

typedef int i32;
typedef unsigned int u32;

int main(int argc, char **argv)
{
    bool isRunning = true;

    clock_t distanceTime = 0;
    std::vector<i32> avgFrame;
    while (isRunning)
    {
        clock_t currentTime = clock();
        clock_t deltaTime = currentTime - distanceTime;
        distanceTime = currentTime;

        static i32 frameCounter = 0;

        frameCounter++;

        if (currentTime % 1000 == 0)
        {
            // printf("A second passes\n");
            avgFrame.push_back(frameCounter);
            frameCounter = 0;
        }

        if (avgFrame.size() > 10)
        {
            i32 avg = 0;

            for (size_t i = 1; i <= avgFrame.size(); i++)
            {
                avg += avgFrame[i];
            }

            avg /= avgFrame.size();

            printf("Average frame: %i\n", avg);

            avgFrame.clear();
        }
    }
    
    return 0;
}