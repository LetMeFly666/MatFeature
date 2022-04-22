/*
 * @Author: LetMeFly
 * @Date: 2022-04-22 15:43:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-22 15:44:18
 */
#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;
using namespace std;

int main() {
    MatrixXd m = MatrixXd::Random(3, 3);
    m = (m + MatrixXd::Constant(3, 3, 1.2)) * 50;
    std::cout << "m =" << std::endl << m << std::endl;
    VectorXd v(3);
    v << 1, 2, 3;
    std::cout << "m * v =" << std::endl << m * v << std::endl;
    system("pause");
    return 0;
}