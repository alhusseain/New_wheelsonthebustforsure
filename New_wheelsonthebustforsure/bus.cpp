/*#include <iostream
#include "station.h"
using namespace std;

template <typename T>
class bus{
    private:
            int capacity;
            int numberOfJourneysDoneBeforeCheckUp;
            int checkUpDuration;
            Stations<T> station; 
            int NumberOfPassengers;
            LinkedList<passengers> currentPassengers;
            public:
                bus(int capacity, int numberOfJourneysDoneBeforeCheckUp, int checkUpDuration){
                    this->capacity = capacity;
                    this->numberOfJourneysDoneBeforeCheckUp = numberOfJourneysDoneBeforeCheckUp;
                    this->checkUpDuration = checkUpDuration;
                }
                int getCapacity(){
                    return capacity;
                }
            int getNumberOfJourneys(){
                return numberOfJourneysDoneBeforeCheckUp;
            }
        int getCheckUpDuration(){
            return checkUpDuration;
        }
        void setCapacity(int capacity){
            this->capacity = capacity;
        }

        void printPassengers(){
            Node<passengers>* head = currentPassengers.gethead();
            currentPassengers.displaypassengers(head);
        }
        int getNumberOfPassengers(){
            return currentPassengers.getLength();
        }
        bool isFull(){
            return currentPassengers.getLength() == capacity;
        }
        bool isEmpty(){
            return currentPassengers.getLength() == 0;
        }
        ~bus(){
            currentPassengers.clear();
        }
};

template <typename T>
class Wbus : public bus<T> {
    public:
        Wbus(int capacity, int numberOfJourneysDoneBeforeCheckUp, int checkUpDuration) : bus<T>(capacity, numberOfJourneysDoneBeforeCheckUp, checkUpDuration){
        }
        ~Wbus(){
            ~Wbus();
        }
};


template <typename T>
class Mbus: public bus<T>{
    public:
        Mbus(int capacity, int numberOfJourneysDoneBeforeCheckUp, int checkUpDuration) : bus<T>(capacity, numberOfJourneysDoneBeforeCheckUp, checkUpDuration){
        }
        ~Mbus(){
            ~Mbus();
        }
};

int main(){
    bus<passengers> bus1(10, 5, 2);
    bus1.printPassengers();
    cout << bus1.getCapacity() << endl;
    cout << bus1.getNumberOfJourneys() << endl;
    cout << bus1.getCheckUpDuration() << endl;
    cout << bus1.getNumberOfPassengers() << endl;
    cout << bus1.isFull() << endl;
    cout << bus1.isEmpty() << endl;
    return 0;
}
*/