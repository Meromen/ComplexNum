#include "ComplexNum.h"
#include <math.h>


ComplexNum::ComplexNum() {
    f_real = 0.0;
    f_img = 0.0;
}

ComplexNum::ComplexNum(float real, float img) {
    f_real = real;
    f_img = img;
}

 ComplexNum operator+( ComplexNum& left,  ComplexNum& right) {
    return ComplexNum(left.f_real + right.f_real, left.f_img + right.f_img);
}    

 ComplexNum operator-( ComplexNum& left,  ComplexNum& right) {
    return ComplexNum(left.f_real - right.f_real, left.f_img - right.f_img);
}

 ComplexNum operator*( ComplexNum& left,  ComplexNum& right) {
    return ComplexNum(left.f_real * right.f_real - left.f_img * right.f_img,
                      left.f_img * right.f_real + left.f_real * right.f_img);
}

 ComplexNum operator/( ComplexNum& left,  ComplexNum& right) {
    float denominator = pow(right.f_real, 2) + pow(right.f_img, 2);

    return ComplexNum((left.f_real * right.f_real + left.f_img * right.f_img) / denominator ,
                      (left.f_img * right.f_real - left.f_real * right.f_img) / denominator);
}

float ComplexNum::cn_abs( ComplexNum& z) {
    return sqrt((pow(z.f_real, 2) + pow(z.f_img, 2)));
};

float ComplexNum::cn_arg( ComplexNum& z) {
    float mod = ComplexNum::cn_abs(z);
    float f_sin = z.f_real / mod;
    float f_cos = z.f_img / mod;

    return f_sin / f_cos;
};

ComplexNum ComplexNum::cn_pow( ComplexNum& z, int power) {
    float r = ComplexNum::cn_abs(z);
    float fi = asin(z.f_real / r);
    return ComplexNum(cos(fi * power), sin(fi * power));
};

ComplexNum PolarToComplex( PolarNum& num) {
    return ComplexNum(num.getRho() * cos(num.getPi()) , num.getRho() * sin(num.getPi()));
};

PolarNum toPolar( ComplexNum& num) {  
    return PolarNum(num.cn_abs(num), num.cn_arg(num));
};

PolarNum::PolarNum() {
    f_rho = 0;
    f_pi = 0;
};

PolarNum::PolarNum(float rho, float pi) {
    f_rho = rho;
    f_pi = pi;
};

float PolarNum::pn_abs( PolarNum& num) {
    ComplexNum cN = PolarToComplex(num);
    return cN.cn_abs(cN);    
};


float PolarNum::pn_arg( PolarNum&num) {
    ComplexNum cN = PolarToComplex(num);
    return cN.cn_arg(cN);   
};

PolarNum PolarNum::pn_pow( PolarNum& num, int power) {
    ComplexNum cN = PolarToComplex(num);    
    PolarNum res = toPolar(cN.cn_pow(cN, power));
    return PolarNum(res.getRho(), res.getPi());
};




PolarNum operator+( PolarNum& left,  PolarNum& right) {
    PolarNum res = toPolar(PolarToComplex(left) + PolarToComplex(right));
    return PolarNum(res.getRho(), res.getPi());
};

PolarNum operator-( PolarNum& left,  PolarNum& right) {
    PolarNum res = toPolar(PolarToComplex(left) - PolarToComplex(right));
    return PolarNum(res.getRho(), res.getPi());
};

PolarNum operator*( PolarNum& left,  PolarNum& right) {
    PolarNum res = toPolar(PolarToComplex(left) * PolarToComplex(right));
    return PolarNum(res.getRho(), res.getPi());
};

PolarNum operator/( PolarNum& left,  PolarNum& right) {
    PolarNum res = toPolar(PolarToComplex(left) / PolarToComplex(right));
    return PolarNum(res.getRho(), res.getPi());
};