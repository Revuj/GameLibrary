#ifndef DATA_H_
#define DATA_H_

class Data {

private:
    int dia,mes,ano;


public:
    // construtor com valor default duma data
    Data(int d=1,int m=1,int a=2000);
    bool operator<=(const Data& D1);




};


#endif /* DATA_H_ */
