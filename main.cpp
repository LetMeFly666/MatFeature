/*
 * @Author: LetMeFly
 * @Date: 2022-04-22 21:07:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-08 13:55:30
 */
// g++.exe main.cpp -o main.exe -I . -I MatFeature
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
    show1feature("Rms", matFeature.rms());
    show1feature("Sra", matFeature.sra());
    show1feature("Energy", matFeature.energy());
    show1feature("ShapeFactor", matFeature.shapeFactor());
    show1feature("CrestFactor", matFeature.crestFactor());
    show1feature("ImpulseFactor", matFeature.impulseFactor());
    show1feature("ClearanceFactor", matFeature.clearanceFactor());
    show1feature("Cs", matFeature.cs());
    show1feature("Ckf", matFeature.ckf());
    show1feature("Fc", matFeature.fc());
    show1feature("Msf", matFeature.msf());
    show1feature("Rmsf", matFeature.rmsf());
    show1feature("Vf", matFeature.vf());
    show1feature("Rvf", matFeature.rvf());

    return 0;
}