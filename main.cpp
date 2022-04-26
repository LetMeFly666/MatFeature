/*
 * @Author: LetMeFly
 * @Date: 2022-04-22 21:07:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-26 14:04:43
 */
#include <MatFeature/MatFeature>
#include <MatFeature/Reader>
#include <Eigen/Dense>
#include <iostream>
#include <cstring>
using namespace std;
using Eigen::MatrixXd;

int main() {
    string sourceFile = "Datas/sample01.txt";
    MatrixXd mat = Read(sourceFile.c_str());
    MatFeature matFeature = MatFeature(mat);

    cout << "Maxium: " << matFeature.maximum() << endl;
    cout << "Minium: " << matFeature.minimum() << endl;
    cout << "Mean: " << matFeature.mean() << endl;
    cout << "Peak: " << matFeature.peak() << endl;
    cout << "Ma: " << matFeature.ma() << endl;
    cout << "Var: " << matFeature.var() << endl;
    cout << "Std: " << matFeature.std() << endl;
    cout << "Kurtosis: " << matFeature.kurtosis() << endl;

    return 0;
}