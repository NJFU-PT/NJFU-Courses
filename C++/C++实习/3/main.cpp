//	假设电信计费标准：固定电话长途话费0.02元/秒，固定电话本地话费0.06元/分，
//  无线电话长途话费1.00元/分，无线电话本地话费0.60元/分，无线电话接听话费0.50元/分。
//	源数据文件中存放：电话号码，电信服务类别，通话时间（秒）。
//	生成固定长途电话文件：长途电话号码和通话时间。
//	生成固定本地电话文件：本地电话号码和通话时间。
//	生成无线长途电话文件：长途电话号码和通话时间。
//	生成无线本地电话文件：本地电话号码和通话时间。
//	生成无线接听电话文件：接听电话号码和通话时间。
//	生成统计电信费用文件：电话号码、累计电信费用。
#include"Cost.cpp"
#include <iostream>
int main(){
    Cost cost;
    cost.in();
    cost.out();
    cost.cost();
    // std::cout << cost << std::endl;
}