//
//  main.cpp
//  wbxml
//
//  Created by jasenhuang-iMac on 14-1-13.
//  Copyright (c) 2014年 tencent. All rights reserved.
//
#include <unistd.h>
#include <iostream>
#include "ASWBXML.h"

std::string encode(std::string xmlString);
std::string decode(unsigned char* bytes , unsigned int len);
void encode_file(std::string in_file , std::string out_file);
void decode_file(std::string in_file , std::string out_file);
void parseOpt(int argc , char * const * argv);

int main(int argc, char * const * argv)
{
    parseOpt(argc, argv);
    return 0;
}
void parseOpt(int argc , char * const * argv)
{
    int result;
    std::string in_file, out_file,action;
    opterr = 0; //使getopt不行stderr输出错误信息
    while( (result = getopt(argc, argv, "edi:o:")) != -1 )
    {
        switch(result)
        {
            case 'e':
                action = (char *)"encode";
                break;
            case 'd':
                action = (char *)"decode";
                break;
            case 'i':
                in_file = optarg;
                break;
            case 'o':
                out_file = optarg;
                break;
            default:
                printf("Usage:\n    ./wbxml -d -i input -o output\n");
                break;
        }
    }
    if (action == "encode"){
        encode_file(in_file,out_file);
    }else if (action == "decode") {
        decode_file(in_file,out_file);
    }
}
void encode_file(std::string in_file , std::string out_file)
{
    if (out_file.empty()) out_file = "encode.out";
    std::cout<<"Encode Begin .... "<<std::endl;
    std::cout<<"in:"<<in_file<<" out:"<<out_file<<std::endl;
    FILE * in_fd = fopen(in_file.c_str(), "rb");
    FILE * out_fd = fopen(out_file.c_str(), "wb");
    long file_size = -1;
    char * buff = NULL;
    if (in_fd == NULL || out_fd == NULL) {
        printf("Error: can not open file %s\n" , in_file.c_str());
        if (in_fd) fclose(in_fd);
        if (out_fd) fclose(out_fd);
        return;
    }
    fseek(in_fd, 0, SEEK_END);
    file_size = ftell(in_fd);
    fseek(in_fd, 0, SEEK_SET);
    
    buff = new char[file_size];
    fread(buff, 1 , file_size , in_fd);
    std::string out = encode(std::string(buff, file_size));
    fwrite(out.c_str(), 1, out.length(), out_fd);
    delete buff;
    
    if (in_fd) fclose(in_fd);
    if (out_fd) fclose(out_fd);
    
    std::cout<<"Encode Done!"<<std::endl;
}
std::string encode(std::string xmlString)
{
    ASWBXML::CASWBXML* encoder = new ASWBXML::CASWBXML();
    encoder->LoadXml(xmlString);
    unsigned char * bytes = NULL;
    unsigned int byteLen = 0;
    encoder->GetBytes(&bytes,&byteLen);
    return std::string((char*)bytes,byteLen);
}
void decode_file(std::string in_file , std::string out_file)
{
    if (out_file.empty()) out_file = "decode.out";
    std::cout<<"Decode Begin .... "<<std::endl;
    std::cout<<"in:"<<in_file<<" out:"<<out_file<<std::endl;
    FILE * in_fd = fopen(in_file.c_str(), "rb");
    FILE * out_fd = fopen(out_file.c_str(), "wb");
    long file_size = -1;
    char * buff = NULL;
    if (in_fd == NULL || out_fd == NULL) {
        printf("Error: can not open file %s\n" , in_file.c_str());
        if (in_fd) fclose(in_fd);
        if (out_fd) fclose(out_fd);
        return;
    }
    fseek(in_fd, 0, SEEK_END);
    file_size = ftell(in_fd);
    fseek(in_fd, 0, SEEK_SET);
    
    buff = new char[file_size];
    fread(buff, 1 , file_size , in_fd);
    std::string out = decode((unsigned char*)buff , (unsigned int)file_size);
    printf("Decode:\n%s\n" , out.c_str());
    fwrite(out.c_str(), 1, out.length(), out_fd);
    delete buff;
    if (in_fd) fclose(in_fd);
    if (out_fd) fclose(out_fd);
    std::cout<<"Decode Done!"<<std::endl;
}
std::string decode(unsigned char* bytes , unsigned int len)
{
    return ASWBXML::CASWBXML::WB2XML(bytes, len);
}