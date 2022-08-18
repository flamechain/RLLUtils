#include "shared.h"
#include <filesystem>

#define PATH_SIZE_LIMIT 2047

int main(int argc, char ** argv) {

    if (argc > 1) {
        string arg = argv[1];

        if (arg.compare("--help") == 0) {
            cout << "usage: easyatp [add|rm] [path]" << endl;
            cout << "options:" << endl;
            cout << "\t--help   shows this message" << endl;
            cout << "\tadd      adds the given directory to the path" << endl;
            cout << "\t             does not modify system environment variables" << endl;
            cout << "\t             does not add duplicate directories" << endl;
            cout << "\trm       removes the given directory from the path" << endl;
            cout << "\t             does not modify system environment variables" << endl;
            cout << "\t             does nothing if the given directory is already on the path" << endl;
            return 0;
        }
    }

    if (argc != 3) {
        cout << "EasyATP: Error: Incorrect number of arguments (expected 2, got " << argc - 1 << "); use '--help' for more information" << endl;
        return 1;
    }

    string input = argv[2];
    std::replace(input.begin(), input.end(), '/', '\\');

    if (!std::filesystem::exists(input)) {
        cout << "EasyATP: Error: Given path does not exist";
        return 1;
    }

    DWORD attributes = GetFileAttributesA(input.c_str());
    if (attributes != FILE_ATTRIBUTE_DIRECTORY) {
        cout << "EasyATP: Error: Given path is not a directory";
        return 1;
    }

    string mode = argv[1];

    HKEY hKey;

    LONG error = RegOpenKeyEx(HKEY_CURRENT_USER, "Environment", 0, KEY_ALL_ACCESS, &hKey);

    if (error != ERROR_SUCCESS) {
        cout << "EasyATP: Error: Failed to open key \"HKEY_CURRENT_USER\\Environment\" (error code " << error << ");" << endl;
        return 1;
    }

    DWORD size_buffer = PATH_SIZE_LIMIT;
    char * buffer = (char *)malloc(PATH_SIZE_LIMIT);

    RegGetValue(HKEY_CURRENT_USER, "Environment", "Path", RRF_RT_REG_EXPAND_SZ, NULL, buffer, &size_buffer);

    string path = buffer;

    if (path[path.size()-1] == ';')
        path.pop_back();

    vector<string> splitPath = split(path, ';');

    if (mode == "add") {
        bool found = false;

        for (string s : splitPath) {
            if (s.compare(input) == 0)
                found = true;
        }

        if (!found) {
            path.push_back(';');
            path.append(input);
        }
    } else if (mode == "rm") {
        for (int i=0; i<splitPath.size(); i++) {
            if (splitPath[i].compare(input) == 0) {
                splitPath.erase(splitPath.begin() + i);
                path = join(splitPath, ";");
                break;
            }
        }
    } else {
        cout << "EasyATP: Error: Unknown option '" << mode << "'" << endl;
        return 1;
    }

    path.push_back(';');

    if (path.size() + 1 > PATH_SIZE_LIMIT) {
        cout << "EasyATP: Error: New path length exceeds path size limit (size:" << path.size() + 1 << " limit:" << PATH_SIZE_LIMIT << ")" << endl;
        return 1;
    }

    RegSetValueEx(hKey, "Path", 0, REG_EXPAND_SZ, (LPBYTE)path.c_str(), PATH_SIZE_LIMIT);

    return 0;
}
