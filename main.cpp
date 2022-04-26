/*
 * @Author: LetMeFly
 * @Date: 2022-04-22 21:07:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-26 17:01:11
 */
#include <MatFeature/MatFeature>
#include <MatFeature/Reader>
#include <MatFeature/Test>
#include <Eigen/Dense>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
using Eigen::MatrixXd;

#define show1feature(featureName, featureGettingMethod)\
    cout << featureName << ": ";\
    debug(featureGettingMethod)

int main() {
    string sourceFile = "Datas/sample01.txt";
    MatrixXd mat = Read(sourceFile.c_str());
    MatFeature matFeature = MatFeature(mat);

    show1feature("Maximum", matFeature.maximum());
    show1feature("Minimum", matFeature.minimum());
    show1feature("Mean", matFeature.mean());
    show1feature("Peak", matFeature.peak());
    show1feature("Ma", matFeature.ma());
    show1feature("Var", matFeature.var());
    show1feature("Std", matFeature.std());
    show1feature("Kurtosis", matFeature.kurtosis());
    show1feature("Skewness", matFeature.skewness());

    return 0;
}