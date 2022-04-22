/*
 * @Author: LetMeFly
 * @Date: 2022-04-22 15:43:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-22 16:12:53
 */
#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;
using namespace std;

int main() {

    // 图标生成
    for (int i = 0; i < 10000; i++)
        cout << rand() % 2;
    puts("");
    system("pause");
    exit(0);

    MatrixXd m = MatrixXd::Random(3, 3);
    m = (m + MatrixXd::Constant(3, 3, 1.2)) * 50;
    std::cout << "m =" << std::endl << m << std::endl;
    VectorXd v(3);
    v << 1, 2, 3;
    std::cout << "m * v =" << std::endl << m * v << std::endl;
    system("pause");
    return 0;
}