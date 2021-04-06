/** @file */
#include <curl/curl.h>

#include <array>
#include <cstdio>
#include <functional>
#include <iostream>
#include <memory>

#include "json.hpp"

typedef std::unique_ptr<CURL, std::function<void(CURL *)>> CURL_ptr;

// CURL * 类型在 C 语言中为 void* 类型，它可以指向任何类型
// 因此没有办法提前获知具体的析构函数，需要定制资源释放模块
class CurlHandle {
   public:
    CurlHandle() : curlptr(curl_easy_init(), deleter) {
        curl_global_init(CURL_GLOBAL_ALL);
    }

    void setUrl(std::string url) {
        curl_easy_setopt(curlptr.get(), CURLOPT_URL, url.c_str());
    }

    CURLcode fetch() { return curl_easy_perform(curlptr.get()); }

   private:
    CURL_ptr curlptr;
    constexpr static auto deleter = [](CURL *c) {
        curl_easy_cleanup(c);
        curl_global_cleanup();
    };
};

class Bitcoin {
   public:
    Bitcoin() : curlhandle({}) { curlhandle.setUrl(API_URL); }

    void fetchBitcoinData() { curlhandle.fetch(); }

   private:
    CurlHandle curlhandle;
    static constexpr const char *API_URL = "https://blockchain.info/ticker";
};

int main() {
    Bitcoin bitcoin;
    bitcoin.fetchBitcoinData();
    return 0;
}
