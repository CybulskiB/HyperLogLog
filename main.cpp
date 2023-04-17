#include <iostream>
#include <fstream>
#include <iterator>
#include <thread>

#include "HyperLogLog.h"

std::string type_To_String(hashType type){
    switch(type){
        case MD5:
            return "MD5";
        case SHA1:
            return "SHA1";
        case SHA256:
            return "SHA256";
        case SHA512:
            return "SHA512";
    }
}
void getResults(int b, hashType type){
    std::vector<int> results;
    results.reserve(100000);

    using namespace std::literals;

    for (int i = 1; i <= 10000; i++) {

        auto source_Filename = "Hashes" + std::to_string(i) + ".txt"s;
        std::string in_Path = "TestData" + type_To_String(type) + "\\" + source_Filename;
        std::ifstream data_File(in_Path);
        if (!data_File) {
            std::cout << "Error during opening file" << std::endl;
        }

        std::istream_iterator<std::string> start(data_File), end;
        std::vector<std::string> Multiset(start, end);
        results.push_back(HyperLogLog(Multiset, b));

        std::cout << std::to_string(i) + " " +  type_To_String(type) + " " +  std::to_string(b) << std::endl;
    }


    auto result_Filename = "Res" + std::to_string(b) +".csv";
    std::string out_Path = "Results\\" + type_To_String(type) + "\\" + result_Filename;
    std::ofstream result_File(out_Path);
    for (int i=0; i< 10000 ; i++){
        result_File <<   std::to_string(results[i]) + ";" + std::to_string(i+1) << "\n";
    }
    result_File.close();
}

int main() {
 //   getResults(16,SHA256);

    std::thread md5_4(getResults,4,MD5);
    std::thread md5_5(getResults,5,MD5);
    std::thread md5_6(getResults,6,MD5);
    std::thread md5_7(getResults,7,MD5);
    std::thread md5_8(getResults,8,MD5);
    std::thread md5_9(getResults,9,MD5);
    std::thread md5_10(getResults,10,MD5);
    std::thread md5_11(getResults,11,MD5);
    std::thread md5_12(getResults,12,MD5);
    std::thread md5_13(getResults,13,MD5);
    std::thread md5_14(getResults,14,MD5);
    std::thread md5_15(getResults,15,MD5);
    std::thread md5_16(getResults,16,MD5);

    std::thread  sha1_4(getResults,4,SHA1);
    std::thread  sha1_5(getResults,5,SHA1);
    std::thread  sha1_6(getResults,6,SHA1);
    std::thread  sha1_7(getResults,7,SHA1);
    std::thread  sha1_8(getResults,8,SHA1);
    std::thread  sha1_9(getResults,9,SHA1);
    std::thread  sha1_10(getResults,10,SHA1);
    std::thread  sha1_11(getResults,11,SHA1);
    std::thread  sha1_12(getResults,12,SHA1);
    std::thread  sha1_13(getResults,13,SHA1);
    std::thread  sha1_14(getResults,14,SHA1);
    std::thread  sha1_15(getResults,15,SHA1);
    std::thread  sha1_16(getResults,16,SHA1);

    std::thread sha256_4(getResults, 4, SHA256);
    std::thread sha256_5(getResults, 5, SHA256);
    std::thread sha256_6(getResults, 6, SHA256);
    std::thread sha256_7(getResults, 7, SHA256);
    std::thread sha256_8(getResults, 8, SHA256);
    std::thread sha256_9(getResults, 9, SHA256);
    std::thread sha256_10(getResults, 10, SHA256);
    std::thread sha256_11(getResults, 11, SHA256);
    std::thread sha256_12(getResults, 12, SHA256);
    std::thread sha256_13(getResults, 13, SHA256);
    std::thread sha256_14(getResults, 14, SHA256);
    std::thread sha256_15(getResults, 15, SHA256);
    std::thread sha256_16(getResults, 16, SHA256);


    std::thread sha512_4(getResults,4,SHA512);
    std::thread sha512_5(getResults,5,SHA512);
    std::thread sha512_6(getResults,6,SHA512);
    std::thread sha512_7(getResults,7,SHA512);
    std::thread sha512_8(getResults,8,SHA512);
    std::thread sha512_9(getResults,9,SHA512);
    std::thread sha512_10(getResults,10,SHA512);
    std::thread sha512_11(getResults,11,SHA512);
    std::thread sha512_12(getResults,12,SHA512);
    std::thread sha512_13(getResults,13,SHA512);
    std::thread sha512_14(getResults,14,SHA512);
    std::thread sha512_15(getResults,15,SHA512);
    std::thread sha512_16(getResults,16,SHA512);

    md5_4.join();
    md5_5.join();
    md5_6.join();
    md5_7.join();
    md5_8.join();
    md5_9.join();
    md5_10.join();
    md5_11.join();
    md5_12.join();
    md5_13.join();
    md5_14.join();
    md5_15.join();
    md5_16.join();

    sha1_4.join();
    sha1_5.join();
    sha1_6.join();
    sha1_7.join();
    sha1_8.join();
    sha1_9.join();
    sha1_10.join();
    sha1_11.join();
    sha1_12.join();
    sha1_13.join();
    sha1_14.join();
    sha1_15.join();
    sha1_16.join();

    sha256_4.join();
    sha256_5.join();
    sha256_6.join();
    sha256_7.join();
    sha256_8.join();
    sha256_9.join();
    sha256_10.join();
    sha256_11.join();
    sha256_12.join();
    sha256_13.join();
    sha256_14.join();
    sha256_15.join();
    sha256_16.join();

    sha512_4.join();
    sha512_5.join();
    sha512_6.join();
    sha512_7.join();
    sha512_8.join();
    sha512_9.join();
    sha512_10.join();
    sha512_11.join();
    sha512_12.join();
    sha512_13.join();
    sha512_14.join();
    sha512_15.join();
    sha512_16.join();

    return 0;
}
