#pragma once
#ifndef EASYATP_SHARED_H
#define EASYATP_SHARED_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <Windows.h>

#define EASYATP_REG_PATH "Directory\\shell\\EasyATP"
#define EASYATPADDTOPATH_REG_PATH "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\CommandStore\\shell\\EasyATP.AddToPath"
#define EASYATPREMOVEFROMPATH_REG_PATH "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\CommandStore\\shell\\EasyATP.RemoveFromPath"
#define EASYATPOPENPATHSETTINGS_REG_PATH "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\CommandStore\\shell\\EasyATP.OpenPathSettings"

#define EASYATPADDTOPATH_REG_COMMAND "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\CommandStore\\shell\\EasyATP.AddToPath\\command"
#define EASYATPREMOVEFROMPATH_REG_COMMAND "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\CommandStore\\shell\\EasyATP.RemoveFromPath\\command"
#define EASYATPOPENPATHSETTINGS_REG_COMMAND "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\CommandStore\\shell\\EasyATP.OpenPathSettings\\command"

using std::string;
using std::vector;
using std::cout;
using std::endl;

// Thanks Fox32 for this function
vector<string> split(const string& s, char seperator) {
    vector<string> output;

    string::size_type prev_pos = 0, pos = 0;

    while((pos = s.find(seperator, pos)) != string::npos) {
        string substring( s.substr(prev_pos, pos-prev_pos) );
        output.push_back(substring);
        prev_pos = ++pos;
    }

    output.push_back(s.substr(prev_pos, pos-prev_pos)); // Last word
    return output;
}

// Thanks user3545770 for this function
string join(const vector<string> &lst, const string &delim) {
    string ret;

    for(const auto &s : lst) {
        if(!ret.empty())
            ret += delim;

        ret += s;
    }

    return ret;
}

#endif
