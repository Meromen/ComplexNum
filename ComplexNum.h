
class PolarNum;

class ComplexNum {
 private:
   float f_real;
   float f_img;
 public:
    ComplexNum();
    ComplexNum(float, float);
    ~ComplexNum() = default;

    float getImg()  {
        return f_img;
    };

    float getReal()  {
        return f_real;
    };

    void setImg(float i) {
        f_img = i;
    };

    void setReal(float r) {
        f_real = r;
    };
    
    ComplexNum& operator=( ComplexNum&) = default;
    friend  ComplexNum operator+( ComplexNum&,  ComplexNum&);
    friend  ComplexNum operator-( ComplexNum&,  ComplexNum&);
    friend  ComplexNum operator*( ComplexNum&,  ComplexNum&);
    friend  ComplexNum operator/( ComplexNum&,  ComplexNum&);

    float cn_abs( ComplexNum&);
    float cn_arg( ComplexNum&);
    ComplexNum cn_pow( ComplexNum&, int);
    ComplexNum toComplex( PolarNum&);

};

class PolarNum {
 private:
    float f_rho;
    float f_pi;    
 public:
    PolarNum(float, float);
    PolarNum();

    float getRho()  {
        return f_rho;
    };

    float getPi()  {
        return f_pi;
    };

    void setRho(float rho) {
        f_rho = rho;
    };

    void setPi(float pi) {
        f_pi = pi;
    };

    ~PolarNum() = default;

    PolarNum& operator=( PolarNum&) = default;
    friend PolarNum operator+( PolarNum&,  PolarNum&);
    friend PolarNum operator-( PolarNum&,  PolarNum&);
    friend PolarNum operator*(PolarNum,  PolarNum&);
    friend PolarNum operator/(PolarNum,  PolarNum&);

    float pn_abs( PolarNum&);
    float pn_arg( PolarNum&);
    PolarNum pn_pow( PolarNum&, int);
    PolarNum toComplex(ComplexNum&);
};