#include "path_operations.h"


int main() {
    printDirectory("/Users/pawelmalecki/Documents/GitHub/uj-emcpp-assignments/11_concepts");
    printDirectory("/non_existing_path");


    fs::path directoryPath = "/Users/pawelmalecki/Documents/GitHub/uj-emcpp-assignments/11_concepts";
    std::string fileNamesRegex = ".*\\.txt";
    std::string newExtension = ".changed";
    changeExtension(directoryPath, fileNamesRegex, newExtension);

    return 0;
}