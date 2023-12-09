//Fall 2023 CS204 HW#5 -- main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "baris.pome_Pome_Baris_HW5_myVector.h"

/*******************************************************************************************************
    DO NOT CHANGE THE MAIN FUNCTION BELOW
    YOU WILL NOT GET ANY POINTS FROM THIS HOMEWORK IF YOU CHANGE IT
*******************************************************************************************************/
int main()
{
    //Vector and iterator declarations
    myVector<std::string, int> vecStringInt;
    vecStringInt.setName("vecStringInt");
    myVector<std::string, int>::Iterator itrStringInt(vecStringInt.begin());

    myVector<double, double> vecDoubleDouble;
    vecDoubleDouble.setName("vecDoubleDouble");
    myVector<double, double>::Iterator itrDoubleDouble(vecDoubleDouble.begin());

    myVector<int, std::string> vecIntString;
    vecIntString.setName("vecIntString");
    myVector<int, std::string>::Iterator itrIntString(vecIntString.begin());

    myVector<double, std::string> vecDoubleString;
    vecDoubleString.setName("vecDoubleString");
    myVector<double, std::string>::Iterator itrDoubleString(vecDoubleString.begin());

    myVector<std::string, int> vecStringInt2;
    vecStringInt2.setName("vecStringInt2");
    myVector<std::string, int>::Iterator itrStringInt2(vecStringInt2.begin());

    myVector<double, double> vecDoubleDouble2;
    vecDoubleDouble2.setName("vecDoubleDouble2");
    myVector<double, double>::Iterator itrDoubleDouble2(vecDoubleDouble2.begin());

    myVector<int, std::string> vecIntString2;
    vecIntString2.setName("vecIntString2");
    myVector<int, std::string>::Iterator itrIntString2(vecIntString2.begin());

    myVector<double, std::string> vecDoubleString2;
    vecDoubleString2.setName("vecDoubleString2");
    myVector<double, std::string>::Iterator itrDoubleString2(vecDoubleString2.begin());

    //File reading
    std::string filename;
    std::cout << "Enter the filename: ";
    std::getline(std::cin, filename);
    std::ifstream inFile(filename);

    if (!inFile.is_open() || inFile.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "Error: Input file is empty or cannot be opened." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string command, vecName, key;
        iss >> command;

        if (command.empty()) {
            continue; // Skip empty lines or lines with only spaces
        }

        if (command == "push") {
            std::string stringKey;
            int intKey;
            double doubleKey;
            iss >> vecName;
            if (vecName == "vecStringInt") {
                std::string stringValue;
                iss >> intKey >> stringValue;
                vecStringInt.push_back(stringValue, intKey);
            } else if (vecName == "vecDoubleDouble") {
                double doubleValue;
                iss >> doubleKey >> doubleValue;
                vecDoubleDouble.push_back(doubleValue, doubleKey);
            } else if (vecName == "vecIntString") {
                int intValue;
                std::string stringValue;
                iss >> stringKey >> intValue;
                vecIntString.push_back(intValue, stringKey);
            } else if (vecName == "vecDoubleString") {
                double doubleValue;
                iss >> stringKey >> doubleValue;
                vecDoubleString.push_back(doubleValue, stringKey);
            }
        }
        else if (command == "remove") {
            std::string stringKey;
            int intKey;
            double doubleKey;
            iss >> vecName;

            if (vecName == "vecStringInt") {
                iss >> intKey;
                vecStringInt.remove(intKey);
            } else if (vecName == "vecDoubleDouble") {
                iss >> doubleKey;
                vecDoubleDouble.remove(doubleKey);
            } else if (vecName == "vecIntString") {
                iss >> stringKey;;
                vecIntString.remove(stringKey);
            } else if (vecName == "vecDoubleString") {
                iss >> stringKey;
                vecDoubleString.remove(stringKey);
            }
        }
        else if (command == "find") {
            std::string stringKey;
            int intKey;
            double doubleKey;
            iss >> vecName;
            if (vecName == "vecStringInt") {
                iss >> intKey;
                std::string* foundValue = vecStringInt[intKey];
                if (foundValue) std::cout << "Found: Key = " << intKey << ", Value = " << *foundValue << std::endl;
                else std::cout << "Key not found: " << intKey << std::endl;
            } 
            else if (vecName == "vecDoubleDouble") {
                iss >> doubleKey;
                double* foundValue = vecDoubleDouble[doubleKey];
                if (foundValue) std::cout << "Found: Key = " << doubleKey << ", Value = " << *foundValue << std::endl;
                else std::cout << "Key not found: " << doubleKey << std::endl;
            }
            else if (vecName == "vecIntString") {
                iss >> stringKey;
                int* foundValue = vecIntString[stringKey];
                if (foundValue) std::cout << "Found: Key = " << stringKey << ", Value = " << *foundValue << std::endl;
                else std::cout << "Key not found: " << stringKey << std::endl;
            }
            else if (vecName == "vecDoubleString") {
                iss >> stringKey;
                double* foundValue = vecDoubleString[stringKey];
                if (foundValue) std::cout << "Found: Key = " << stringKey << ", Value = " << *foundValue << std::endl;
                else std::cout << "Key not found: " << stringKey << std::endl;
            }
        }

        else if (command == "replace_value") {
            std::string stringKey;
            int intKey;
            double doubleKey;
            iss >> vecName;
            if (vecName == "vecStringInt") {
                std::string stringValue;
                iss >> intKey >> stringValue;
                std::string* foundValue = vecStringInt[intKey];
                if (foundValue) *foundValue = stringValue;
                else std::cout << "Key not found for replacement: " << intKey << std::endl;
            } 
            else if (vecName == "vecDoubleDouble") {
                double doubleValue;
                iss >> doubleKey >> doubleValue;
                double* foundValue = vecDoubleDouble[doubleKey];
                if (foundValue) *foundValue = doubleValue;
                else std::cout << "Key not found for replacement: " << doubleKey << std::endl;
            }
            else if (vecName == "vecIntString") {
                int intValue;
                iss >> stringKey >> intValue;
                int* foundValue = vecIntString[stringKey];
                if (foundValue) *foundValue = intValue;
                else std::cout << "Key not found for replacement: " << stringKey << std::endl;
            }
            else if (vecName == "vecDoubleString") {
                double doubleValue;
                iss >> stringKey >> doubleValue;
                double* foundValue = vecDoubleString[stringKey];
                if (foundValue) *foundValue = doubleValue;
                else std::cout << "Key not found for replacement: " << stringKey << std::endl;
            }
        }

        if (command == "replace_key") {
            std::string oldKeyStr, newKeyStr;
            int oldKeyInt, newKeyInt;
            double oldKeyDouble, newKeyDouble;
            
            iss >> vecName;
            if (vecName == "vecStringInt") {
                iss >> oldKeyInt >> newKeyInt;
                if (itrStringInt.find(oldKeyInt, vecStringInt)) {
                    itrStringInt.replaceKey(newKeyInt);
                } else {
                    std::cout << "Key not found: " << oldKeyInt << std::endl;
                }
            } else if (vecName == "vecDoubleDouble") {
                iss >> oldKeyDouble >> newKeyDouble;
                if (itrDoubleDouble.find(oldKeyDouble, vecDoubleDouble)) {
                    itrDoubleDouble.replaceKey(newKeyDouble);
                } else {
                    std::cout << "Key not found: " << oldKeyDouble << std::endl;
                }
            } else if (vecName == "vecIntString") {
                iss >> oldKeyStr >> newKeyStr;
                if (itrIntString.find(oldKeyStr, vecIntString)) {
                    itrIntString.replaceKey(newKeyStr);
                } else {
                    std::cout << "Key not found: " << oldKeyStr << std::endl;
                }
            } else if (vecName == "vecDoubleString") {
                iss >> oldKeyStr >> newKeyStr;
                if (itrDoubleString.find(oldKeyStr, vecDoubleString)) {
                    itrDoubleString.replaceKey(newKeyStr);
                } else {
                    std::cout << "Key not found: " << oldKeyStr << std::endl;
                }
            } else {
                std::cout << "Unknown vector name: " << vecName << std::endl;
            }
        }

        else if (command == "print") {
            std::string stringKey;
            int intKey;
            double doubleKey;
            iss >> vecName;
            if (vecName == "vecStringInt") {
                iss >> intKey;
                std::string* value = vecStringInt[intKey];
                if (value) {
                    std::cout << "Key: " << intKey << ", Value: " << *value << std::endl;
                } else {
                    std::cout << "Error: Key not found: " << intKey << " in vector '" << vecName << "'" << std::endl;
                }
            }
            else if (vecName == "vecDoubleDouble")
            {
                iss >> doubleKey;
                double* value = vecDoubleDouble[doubleKey];
                if (value) {
                    std::cout << "Key: " << doubleKey << ", Value: " << *value << std::endl;
                } else {
                    std::cout << "Error: Key not found: " << doubleKey << " in vector '" << vecName << "'" << std::endl;
                }
            }
            else if (vecName == "vecIntString")
            {
                iss >> stringKey;
                int* value = vecIntString[stringKey];
                if (value) {
                    std::cout << "Key: " << stringKey << ", Value: " << *value << std::endl;
                } else {
                    std::cout << "Error: Key not found: " << stringKey << " in vector '" << vecName << "'" << std::endl;
                }
            }
            else if (vecName == "vecDoubleString")
            {
                iss >> stringKey;
                double* value = vecDoubleString[stringKey];
                if (value) {
                    std::cout << "Key: " << stringKey << ", Value: " << *value << std::endl;
                } else {
                    std::cout << "Error: Key not found: " << stringKey << " in vector '" << vecName << "'" << std::endl;
                }
            }
        }

        else if (command == "print_vector") {
            iss >> vecName;
            if (vecName == "vecStringInt") {
                if (vecStringInt.isEmpty()) {
                    std::cout << "Error: vecStringInt is empty." << std::endl;
                } else {
                    std::cout << "\nPrinting vecStringInt:" << std::endl;
                    itrStringInt.printVector();
                }
            } else if (vecName == "vecDoubleDouble") {
                if (vecDoubleDouble.isEmpty()) {
                    std::cout << "Error: vecDoubleDouble is empty." << std::endl;
                } else {
                    std::cout << "\nPrinting vecDoubleDouble:" << std::endl;
                    itrDoubleDouble.printVector();
                }
            } else if (vecName == "vecIntString") {
                if (vecIntString.isEmpty()) {
                    std::cout << "Error: vecIntString is empty." << std::endl;
                } else {
                    std::cout << "\nPrinting vecIntString:" << std::endl;
                    itrIntString.printVector();
                }
            } else if (vecName == "vecDoubleString") {
                if (vecDoubleString.isEmpty()) {
                    std::cout << "Error: vecDoubleString is empty." << std::endl;
                } else {
                    std::cout << "\nPrinting vecDoubleString:" << std::endl;
                    itrDoubleString.printVector();
                }
            } else {
                std::cout << "Error: Unknown vector name '" << vecName << "'" << std::endl;
            }
        }

        else if (command == "copy") {
            std::string targetVecName;
            iss >> vecName >> targetVecName;

            if (vecName == "vecStringInt" && targetVecName == "vecStringInt2") {
                vecStringInt2 = vecStringInt;
                std::cout << "\nPrinting vecStringInt2:" << std::endl;
                itrStringInt2.printVector();
            } 
            else if (vecName == "vecDoubleDouble" && targetVecName == "vecDoubleDouble2") {
                vecDoubleDouble2 = vecDoubleDouble;
                std::cout << "\nPrinting vecDoubleDouble2:" << std::endl;
                itrDoubleDouble2.printVector();
            } 
            else if (vecName == "vecIntString" && targetVecName == "vecIntString2") {
                vecIntString2 = vecIntString;
                std::cout << "\nPrinting vecIntString2:" << std::endl;
                itrIntString2.printVector();
            } 
            else if (vecName == "vecDoubleString" && targetVecName == "vecDoubleString2") {
                vecDoubleString2 = vecDoubleString;
                std::cout << "\nPrinting vecDoubleString2:" << std::endl;
                itrDoubleString2.printVector();
            } 
            else {
                std::cout << "Error: Incompatible vector types or unknown vector names for copy." << std::endl;
            }
        }

        else if (command == "check_equal") {
            std::string targetVecName;
            iss >> vecName >> targetVecName;

            if (vecName == "vecStringInt" && targetVecName == "vecStringInt2") {
                if (vecStringInt == vecStringInt2) {
                    std::cout << vecName << " and " << targetVecName << " are equal." << std::endl;
                } else {
                    std::cout << vecName << " and " << targetVecName << " are not equal." << std::endl;
                }
            } else if (vecName == "vecDoubleDouble" && targetVecName == "vecDoubleDouble2") {
                if (vecDoubleDouble == vecDoubleDouble2) {
                    std::cout << vecName << " and " << targetVecName << " are equal." << std::endl;
                } else {
                    std::cout << vecName << " and " << targetVecName << " are not equal." << std::endl;
                }
            } else if (vecName == "vecIntString" && targetVecName == "vecIntString2") {
                if (vecIntString == vecIntString2) {
                    std::cout << vecName << " and " << targetVecName << " are equal." << std::endl;
                } else {
                    std::cout << vecName << " and " << targetVecName << " are not equal." << std::endl;
                }
            } else if (vecName == "vecDoubleString" && targetVecName == "vecDoubleString2") {
                if (vecDoubleString == vecDoubleString2) {
                    std::cout << vecName << " and " << targetVecName << " are equal." << std::endl;
                } else {
                    std::cout << vecName << " and " << targetVecName << " are not equal." << std::endl;
                }
            } else {
                std::cout << "Error: Incompatible vector types or unknown vector names for comparison." << std::endl;
            }
        }

        if (command == "process_data") {
            iss >> vecName;
            if (vecName == "vecStringInt") {
                std::cout << "Processing data of vector " << vecStringInt.getName() << ":" << std::endl;
                vecStringInt.process_data();
            } else if (vecName == "vecDoubleDouble") {
                std::cout << "Processing data of vector " << vecDoubleDouble.getName() << ":" << std::endl;
                vecDoubleDouble.process_data();
            } else if (vecName == "vecIntString") {
                std::cout << "Processing data of vector " << vecIntString.getName() << ":" << std::endl;
                vecIntString.process_data();
            } else if (vecName == "vecDoubleString") {
                std::cout << "Processing data of vector " << vecDoubleString.getName() << ":" << std::endl;
                vecDoubleString.process_data();
            } else {
                std::cout << "Error: Unknown vector name '" << vecName << "'" << std::endl;
            }
        }
    }


    inFile.close();
    return 0;
}
/*******************************************************************************************************/