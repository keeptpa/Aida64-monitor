// Aida64 monitor.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string.h>
#include <vector>


LPVOID info = NULL;
using namespace std;

string outcut(string output)
{
   output = (char*)info;
    
    while (output.find("<") != -1) { //remove xml format marks
        output.replace(output.find("<"), output.find(">") - output.find("<") + 1, "!");
    }
   int i = 0;
    while (output.find("!!") != -1) {
        switch (i)
        {
        case 0:
            output.replace(output.find("!!"), 2, "ALPHA");
            i++;
           
            break;
        case 1:
            output.replace(output.find("!!"), 2, "BETA");
            i++;
          
            break;
        case 2:
            output.replace(output.find("!!"), 2, "GAMMA");
            i++;
         
            break;
        case 3:
            output.replace(output.find("!!"), 2, "DELTA");
            i = 0;
           
            output.replace(output.find("ALPHA"), output.find("BETA") - output.find("ALPHA")+4, "\n");
            break;
            
        }
        
    }
    while (output.find("DELTA") != -1) {
        output.replace(output.find("DELTA"), 5, "");
    }
    while (output.find("GAMMA") != -1) {
        output.replace(output.find("GAMMA"), 5, "\n");
    }
    return (output);
}

/*string incut(string str) 
{

}*/

int main()
{
    string output;
    vector<string> v_output;
    string memName = "AIDA64_SensorValues";
    std::cout << "Hello World!\n";
    HANDLE hMap = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, 1, TEXT("AIDA64_SensorValues"));
    if (hMap == NULL) { std::cout << "Have you run Aida?\n"; }
    else
        
                info = ::MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);
                output = outcut(output);


                cout << "NewPackage:\n" << output << endl; 
                Sleep(1000);     
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
