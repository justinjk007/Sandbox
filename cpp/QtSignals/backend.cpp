#include "backend.hpp"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <thread>

using namespace std;

void Backend::generateRandom()
{
    int min = 90;
    int max = 1000;
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 10; ++i) {
        // this_thread::sleep_for(std::chrono::seconds(1));  // TODO : Remove this during release
        int randomm = rand() % (max - min + 1) + min;
        QString content =
            QString(
                "<span style=\" font-size:18pt; font-weight:300; font-family:Hack,Arial;\"\\>") +
            "Random number is : " + randomm + "</span>";
        this->setContent(content);
    }
}

void Backend::setContent(QString content)
{
    /**
     *  Slot
     */
    emit contentChanged(content);  // Emit the signal
}
