#pragma once

#include <iostream>
#include <string>

typedef struct tagRunningInfo {
    std::string tool_suite_id;
    std::string enclosure_id;
    std::string user_id;
    std::string password_id = "222";  // default value 222
} RunningInfo;

using namespace std;

extern int write_data(void* buffer, int size, int nmemb, void* userp);
extern int upload(string url, string& body, string* response, std::string& sendFile, int flag);

#include <curl/curl.h>
#include <string.h>
#include <iostream>
//#include "CurlSendRecv.h"

int write_data(void* buffer, int size, int nmemb, void* userp) {
    std::string* str = dynamic_cast<std::string*>((std::string*)userp);
    str->append((char*)buffer, size * nmemb);
    return nmemb;
}

int upload(string url, string& body, string* response, std::string& sendFile, int flag) {
    CURL* curl;
    CURLcode ret;
    cout << "response: " << response << endl;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    struct curl_httppost* post = NULL;
    struct curl_httppost* last = NULL;
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, (char*)url.c_str());
        if (flag == 0) {
            curl_formadd(&post, &last, CURLFORM_COPYNAME, "file_data", CURLFORM_FILE, sendFile.c_str(),
                         CURLFORM_END);  // form-data key(file) "./test.jpg"为文件路径  "hello.jpg" 为文件上传时文件名
        } else {
            curl_formadd(&post, &last, CURLFORM_COPYNAME, "file", CURLFORM_FILE, sendFile.c_str(),
                         CURLFORM_END);  // form-data key(file) "./test.jpg"为文件路径  "hello.jpg" 为文件上传时文件名
        }
        curl_easy_setopt(curl, CURLOPT_HTTPPOST, post);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)response);

        // curl_easy_setopt (curl,CURLOPT_SSL_VERIFYPEER, falase);

        // curl_easy_setopt (curl,CURLOPT_SSL_VERIFYHOST, false);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 0);

        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3);
        curl_easy_setopt(curl, CURLOPT_LOW_SPEED_LIMIT, 1);
        curl_easy_setopt(curl, CURLOPT_LOW_SPEED_TIME, 60);
        ret = curl_easy_perform(curl);
        if (ret == 0) {
            cout << "uploadTest:" << curl_easy_strerror(ret) << endl;
            cout << "response: " << response << endl;
            curl_easy_cleanup(curl);
            return 0;
        } else {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(ret));
            curl_easy_cleanup(curl);
            return ret;
        }
    } else {
        return -1;
    }
}

int main(int argc, char* argv[]) {
    // prepare the parameters
    RunningInfo running_info_;
    running_info_.tool_suite_id = "1234";
    running_info_.enclosure_id = "5678";
    running_info_.user_id = "432";
    string url = "http://10.69.144.186:8800/rest/ems/soft/upload/4";
    string body = running_info_.tool_suite_id + ", " + running_info_.enclosure_id + ", " + running_info_.user_id +
                  ", " + running_info_.password_id;
    string response = "";
    string sendFile = "/home/beyoung/Desktop/Sa-Upload-Test2.zip";
    int flag = 0;
    // upload
    upload(url, body, &response, sendFile, flag);
    return 0;
}
