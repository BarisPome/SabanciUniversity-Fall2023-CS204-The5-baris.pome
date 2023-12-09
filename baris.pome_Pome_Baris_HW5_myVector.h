//Fall 2023 CS204 HW#5 -- myVector.h
//Barış Pome 31311 Section A-2
#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;
/*******************************************************************************************************
    IMPLEMENT FOLLOWING CLASSES
    YOU CAN ADD ANY FUNCTION/STRUCT/CLASS THAT YOU WILL USE HOWEVER YOU CANNOT TOUCH MAIN FUNCTION
*******************************************************************************************************/
template <typename T1, typename T2>
class myVector {
public:
    struct pair { // struct that holds two variables that are given in the template and one of them is the key and the other is the value
        T1 value;
        T2 key;
        pair(T1 first, T2 second) : value(first), key(second) {}
    };
    class Iterator {
    public:
        Iterator(myVector& source) : source(source), index(0) {} // constructor

        bool hasMore() { // checks if there is more elements in the vector
            if (index < source.vec->size()) {
                return true;
            }
            else {
                return false;
            }
        }
        pair& next() { // returns the next element in the vector
            return source.vec->at(index++);
        }
        pair& current() { // returns the current element in the vector
            return source.vec->at(index);
        }
        void Init() { // initializes the index to 0
            index = 0;
        }
        void printVector() { // prints the vector in the order of the keys sorted in ascending order
            for (Init(); hasMore(); next()) {
                cout << "Value: " << current().value << ", Key: " << current().key << endl;
            }
        }
        bool find(T2 key, myVector& source) { // checks if the given key is in the vector
            for (Init(); hasMore(); next()) {
                if (current().key == key) {
                    return true;

                }
            }
            return false;
        }
        bool replaceKey(T2 key) { // replaces the key of the current element with the given key
            current().key = key;
        }
    private:
        myVector& source;
        int index;
    };
    myVector() { // constructor
        vec = new vector<pair>;
    }
    ~myVector() { // destructor
        delete vec;
    }
    myVector(const myVector& other) : vec(new vector<pair>(*other.vec)), name(other.name) {} // deep copy constructor

    Iterator begin() { // returns the iterator
        Iterator itr(*this);
        return itr;
    }

    void setName(string name) { // sets the name of the vector
        this->name = name;
    }
    string getName() { // returns the name of the vector
        return name;
    }
    bool isEmpty() { // checks if the vector is empty
        return vec->empty();
    }
    void push_back(T1 value, T2 key) { // adds the given value and key to the vector
        vec->push_back(pair(value, key));
    }
    void remove(T2 key) { // removes the element that has the given key
        if (vec->empty()) {
            return;
        }
        for (int i = 0; i < vec->size(); i++) {
            if (vec->at(i).key == key) {
                vec->erase(vec->begin() + i);
                break;
            }
        }
    }
    //the functions for operator overloading
    bool operator==(myVector& other) const { // operator overloading that checks if two vectors are equal
        if (vec->size() != other.vec->size()) {
            return false;
        }
        for (int i = 0; i < vec->size(); i++) {
            if (vec->at(i).key != other.vec->at(i).key) {
                return false;
            }
            if (vec->at(i).value != other.vec->at(i).value) {
                return false;
            }
        }
        return true;
    }

    T1* operator[](T2 key) { // operator overloading that returns the value of the element that has the given key
        for (int i = 0; i < vec->size(); i++) {
            if (vec->at(i).key == key) {
                return &vec->at(i).value;
            }
        }
        return nullptr;
    }

    myVector& operator=(const myVector& other) { // operator overloading that copies the given vector to the vector that calls the function
        vec->clear();
        for (int i = 0; i < other.vec->size(); i++) {
            vec->push_back(pair(other.vec->at(i).value, other.vec->at(i).key));
        }
        return *this;
    }

    //the functions for processing the data
    void displayMean() { // displays the mean of the vector if the type is int or double
        double sum = 0;
        for (int i = 0; i < vec->size(); i++) {
            sum += vec->at(i).value;
        }
        cout << "Mean: " << sum / vec->size() << endl;
    }
    void displayMedian() { // displays the median of the vector if the type is int or double
        if (vec->size() % 2 == 0) { // checks if the size of the vector is even or odd
            cout << "Median: " << (vec->at(vec->size() / 2).value + vec->at(vec->size() / 2 - 1).value) / 2 << endl;
        }
        else {
            cout << "Median: " << vec->at(vec->size() / 2).value << endl;
        }
    }
    void displayMode() { // displays the mode of the vector if the type is int or double
        double max = 0;
        double mode = 0;
        for (int i = 0; i < vec->size(); i++) {
            int count = 0;
            for (int j = 0; j < vec->size(); j++) {
                if (vec->at(i).value == vec->at(j).value) {
                    count++;
                }
            }
            if (count > max) {
                max = count;
                mode = vec->at(i).value;
            }
        }
        cout << "Mode: " << mode << endl;
    }
    void displayMax() { // displays the max of the vector if the type is int or double
        double max = vec->at(0).value;
        for (int i = 1; i < vec->size(); i++) {
            if (vec->at(i).value > max) {
                max = vec->at(i).value;
            }
        }
        cout << "Max: " << max << endl;
    }
    void displayStandartDeviation() { // displays the standart deviation of the vector if the type is int or double
        double sum = 0;
        for (int i = 0; i < vec->size(); i++) {
            sum += vec->at(i).value;
        }
        double mean = sum / vec->size();
        double sumOfSquares = 0;
        for (int i = 0; i < vec->size(); i++) {
            sumOfSquares += pow(vec->at(i).value - mean, 2);
        }
        cout << "Standart Deviation: " << sqrt(sumOfSquares / vec->size()) << endl;
    }
    void displayFrequentCharacter() { // displays the most frequent character of the vector if the type is string
        int array[52] = { 0 }; // array that holds the frequencies of the characters
        for (int i = 0; i < vec->size(); i++) {
            for (int j = 0; j < vec->at(i).value.length(); j++) {
                if (vec->at(i).value[j] >= 'a' && vec->at(i).value[j] <= 'z') {
                    array[vec->at(i).value[j] - 'a']++; // increments the frequency of the character
                }
                else if (vec->at(i).value[j] >= 'A' && vec->at(i).value[j] <= 'Z') {
                    array[vec->at(i).value[j] - 'A' + 26]++; // increments the frequency of the character
                }
            }
        }
        int max = 0; // holds the max frequency
        int index = 0; // holds the index of the max frequency
        for (int i = 51; i >= 0; i--) { // checks the frequencies of the characters in the descending order it is because of the lexigraphical if 2 characters have the same frequency the one that comes first in the alphabet is the most frequent character
            if (array[i] >= max) { // checks if the frequency is greater than the max frequency for the lexigraphical order
                max = array[i];
                index = i;
            }
        }
        if (index < 26) { // checks if the character is lowercase or uppercase
            cout << "Most Frequent Character: \'" << (char)(index + 'a') << "\' (Frequency: " << max << ")" << endl;
        }
        else { // checks if the character is lowercase or uppercase
            cout << "Most Frequent Character: \'" << (char)(index - 26 + 'A') << "\' (Frequency: " << max << ")" << endl;
        }
    }

    void displayFrequentWord() { // displays the most frequent word of the vector if the type is string
        int max = 0;
        string word;
        for (int i = 0; i < vec->size(); i++) { // checks the frequency of the words
            int count = 0;
            for (int j = 0; j < vec->size(); j++) {
                if (vec->at(i).value == vec->at(j).value) {
                    count++;
                }
            }
            if (count > max) { // checks if the frequency is greater than the max frequency
                max = count;
                word = vec->at(i).value;
            }
            else if (count == max) { // checks if the frequency is equal to the max frequency for the lexigraphical order
                if (vec->at(i).value < word) {
                    word = vec->at(i).value;
                }
            }
        }
        cout << "Most Frequent Word: \"" << word << "\" (Frequency: " << max << ")" << endl;

    }

    void make_it_ordered_value() { // sorts the vector if the type is int or double according to the values
        for (int i = 0; i < vec->size(); i++) {
            for (int j = 0; j < vec->size() - 1; j++) {
                if (vec->at(j).value > vec->at(j + 1).value) {
                    pair temp = vec->at(j);
                    vec->at(j) = vec->at(j + 1);
                    vec->at(j + 1) = temp;
                }
            }
        }
    }

    void process_data() { // processes the data according to the type
        if constexpr (is_same<T1, int>::value || is_same<T1, double>::value) { // checks if the type is int or double
            myVector* deep_copy = new myVector(*this); // creates a deep copy of the vector
            deep_copy->make_it_ordered_value(); // sorts the vector and then processes the data
            deep_copy->displayMean();
            deep_copy->displayMedian();
            deep_copy->displayStandartDeviation();
            deep_copy->displayMax();
            deep_copy->displayMode();
            delete deep_copy; // deletes the deep copy of the vector to prevent memory leak
        } else if constexpr (is_same<T1, string>::value) { // checks if the type is string
            displayFrequentCharacter();
            displayFrequentWord();
        }
    }


private:
    vector<pair> *vec; // vector that holds the data
    string name; // name of the vector
};
/*******************************************************************************************************/
