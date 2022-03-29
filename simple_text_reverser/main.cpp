/*
 * Simple Text Reverser
 *
 * Author: iCAROS7 (hominlab@gmail.com)
 * Date/Time: 2022.03.29 22:14
 */

#include <iostream>
#include <fstream>

int main(int argc, const char * argv[]) {
    std::ifstream is{ "input.txt" };
    std::ofstream os {"output.txt" };
    if (!is || !os) {   // 파일 열기 실패시
        std::cerr << "파일 오픈에 실패하였습니다." << std::endl;
        exit(1);        // 1과 함께 종료
    }

    is.seekg(0, std::ios::end);  // 커서 위치를 가장 끝으로 이동
    int num = is.tellg();   // 현재 커서 위치를 파일의 크기로 간주하고 저장
    char c;
    
    for (int i = num - 1; i >= 0; i--) {
        is.seekg(i, std::ios::beg);
        is.get(c);
        os << c;
    }
    return 0;
}
