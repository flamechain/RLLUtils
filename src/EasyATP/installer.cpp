#include "shared.h"

int main(int argc, char ** argv) {

    string location = argv[1];
    std::replace(location.begin(), location.end(), '/', '\\');

    string name = "Add to Path";
    string subCommands = "EasyATP.AddToPath;EasyATP.RemoveFromPath;EasyATP.OpenPathSettings";
    string addname = name;
    string addcommand = location + string(" add") + " \"%V\"";
    string rmname = "Remove from Path";
    string rmcommand = location + string(" rm") + " \"%V\"";
    string pname = "Open Path Settings";
    string pcommand = "rundll32 sysdm.cpl,EditEnvironmentVariables";

    HKEY hKey;

    DWORD error = RegCreateKeyEx(HKEY_CLASSES_ROOT, EASYATP_REG_PATH, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);

    if (error != ERROR_SUCCESS) {
        cout << "EasyATP: Installer Error: Failed to create key \"HKEY_CLASSES_ROOT\\" << EASYATP_REG_PATH << "\" (error code " << error << ");" << endl;
        return 1;
    }

    RegSetValueEx(hKey, "MUIVerb", 0, REG_EXPAND_SZ, (LPBYTE)name.c_str(), name.size() + 1);
    RegSetValueEx(hKey, "SubCommands", 0, REG_EXPAND_SZ, (LPBYTE)subCommands.c_str(), subCommands.size() + 1);
    RegCloseKey(hKey);

    error = RegCreateKeyEx(HKEY_LOCAL_MACHINE, EASYATPADDTOPATH_REG_PATH, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);

    if (error != ERROR_SUCCESS) {
        cout << "EasyATP: Installer Error: Failed to create key \"HKEY_LOCAL_MACHINE\\" << EASYATPADDTOPATH_REG_PATH << "\" (error code " << error << ");" << endl;
        return 1;
    }

    RegSetValueEx(hKey, NULL, 0, REG_EXPAND_SZ, (LPBYTE)addname.c_str(), addname.size() + 1);
    RegCloseKey(hKey);


    error = RegCreateKeyEx(HKEY_LOCAL_MACHINE, EASYATPADDTOPATH_REG_COMMAND, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);

    if (error != ERROR_SUCCESS) {
        cout << "EasyATP: Installer Error: Failed to create key \"HKEY_LOCAL_MACHINE\\" << EASYATPADDTOPATH_REG_COMMAND << "\" (error code " << error << ");" << endl;
        return 1;
    }

    RegSetValueEx(hKey, NULL, 0, REG_EXPAND_SZ, (LPBYTE)addcommand.c_str(), addcommand.size() + 1);
    RegCloseKey(hKey);

    error = RegCreateKeyEx(HKEY_LOCAL_MACHINE, EASYATPREMOVEFROMPATH_REG_PATH, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);

    if (error != ERROR_SUCCESS) {
        cout << "EasyATP: Installer Error: Failed to create key \"HKEY_LOCAL_MACHINE\\" << EASYATPREMOVEFROMPATH_REG_PATH << "\" (error code " << error << ");" << endl;
        return 1;
    }

    RegSetValueEx(hKey, NULL, 0, REG_EXPAND_SZ, (LPBYTE)rmname.c_str(), rmname.size() + 1);
    RegCloseKey(hKey);

    error = RegCreateKeyEx(HKEY_LOCAL_MACHINE, EASYATPREMOVEFROMPATH_REG_COMMAND, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);

    if (error != ERROR_SUCCESS) {
        cout << "EasyATP: Installer Error: Failed to create key \"HKEY_LOCAL_MACHINE\\" << EASYATPREMOVEFROMPATH_REG_COMMAND << "\" (error code " << error << ");" << endl;
        return 1;
    }

    RegSetValueEx(hKey, NULL, 0, REG_EXPAND_SZ, (LPBYTE)rmcommand.c_str(), rmcommand.size() + 1);
    RegCloseKey(hKey);

    error = RegCreateKeyEx(HKEY_LOCAL_MACHINE, EASYATPOPENPATHSETTINGS_REG_PATH, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);

    if (error != ERROR_SUCCESS) {
        cout << "EasyATP: Installer Error: Failed to create key \"HKEY_LOCAL_MACHINE\\" << EASYATPOPENPATHSETTINGS_REG_PATH << "\" (error code " << error << ");" << endl;
        return 1;
    }

    RegSetValueEx(hKey, NULL, 0, REG_EXPAND_SZ, (LPBYTE)pname.c_str(), pname.size() + 1);
    RegCloseKey(hKey);

    error = RegCreateKeyEx(HKEY_LOCAL_MACHINE, EASYATPOPENPATHSETTINGS_REG_COMMAND, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);

    if (error != ERROR_SUCCESS) {
        cout << "EasyATP: Installer Error: Failed to create key \"HKEY_LOCAL_MACHINE\\" << EASYATPOPENPATHSETTINGS_REG_COMMAND << "\" (error code " << error << ");" << endl;
        return 1;
    }

    RegSetValueEx(hKey, NULL, 0, REG_EXPAND_SZ, (LPBYTE)pcommand.c_str(), pcommand.size() + 1);
    RegCloseKey(hKey);

    return 0;
}
