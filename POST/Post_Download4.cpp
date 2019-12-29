#include <curl/curl.h>
//#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    CURL *curl;
    FILE *fp;
    string url =
        "https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Nusfjord_road%2C_2010_09.jpg/"
        "1280px-Nusfjord_road%2C_2010_09.jpg";  // ok
    //    string url = "http://b.hiphotos.baidu.com/image/pic/item/908fa0ec08fa513db777cf78376d55fbb3fbd9b3.jpg";  // ok
    // string url = "http://10.69.144.186:8800/rest/ems/media/ems/json/Camera2ImuTransformTest.json";  // ok
    string save_path = "/home/beyoung/Desktop/test.jpg";
    CURLcode result;

    fp = fopen(save_path.c_str(), "wb");

    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
    //    curl_easy_setopt(curl, CURLOPT_PROXY, "10.69.60.221:8080");
    //    curl_easy_setopt(curl, CURLOPT_PROXYUSERPWD, "binyang.hu:deliveryHBY432");

    result = curl_easy_perform(curl);

    fclose(fp);

    if (result == CURLE_OK) {
        cout << "download successfully" << endl;
    } else {
        cout << "error, error code is: " << result << ", it is " << curl_easy_strerror(result) << endl;
    }
}
