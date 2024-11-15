// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <math.h>
#include <chrono>
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"

int picount = 0;
bool cmp(double a,double b, int prec ){
    if(abs(a-b) < 1/pow(2,abs(prec))) {
        return true;
    }
    return false;
}
double lenpyt(double x,double y) {
    return (sqrt(pow(x,2)+pow(y,2)));
}
double dist(double x1,double y1,double x2, double y2) {
    return lenpyt(abs(x1-x2),abs(y1-y2));
}
void circlisation(bool *arr,int width,int height,double radius) {
    double centerx,centery;
    centerx = width/2;
    centery = height/2;
    for(int i = 0; i < height;i++) {
     for(int j = 0;j < width;j++) {
        if(cmp(dist(j,i,centerx,centery), radius,1)) {
            arr[i*width+j] = true;
            picount++;
        } else {
            arr[i*width+j] = false;
        }
    }   
    }
}
void initboolarr(bool*arr,int cells,bool e) {
    for(int i = 0; i < cells; i++) {
        arr[i] = e;
        //std::cout << "e";
    }
}
void renderboolarr(char yes,char no, bool*arr,int width, int height) {

    for(int i = 0; i < height;i++) {
     for(int j = 0;j < width;j++) {
            if(arr[i*width+j] == true) {
                std::cout << RED << yes << yes;
                j++;
            } else {
                //std::cout << GREEN << no;
            }
            
        }   
    //std::cout << "\n";
        
    }
}
int stri(char* cstr) {
    std::string uncstr(cstr);
    int o = 0;
    for(int n = 0; n < uncstr.length();n++) {
        switch (uncstr[n]) {
            case '1':
                o += pow(10,n);
                break;
            
            case '2':
                o += 2* pow(10,n);
                break;
            
            case '3':
                o += 3*pow(10,n);
                break;
            
            case '4':
                o += 4*pow(10,n);
                break;
            
            case '5':
                o += 5*pow(10,n);
                break;
            
            case '6':
                o += 6*pow(10,n);
                break;
            
            case '7':
                o += 7*pow(10,n);
                break;
                
            case '8':
                o += 8*pow(10,n);
                break;
            
            case '9':
                o += 9*pow(10,n);
                break;
                
            case '0':
                break;
            
            default:
                std::cout << "notanumberatposition" << n;
                break;
        }
        }
    return o;
}
void findpi (int width,int height,double radius) {
    double centerx,centery;
    centerx = width/2;
    centery = height/2;
    for(int i = 0; i < height;i++) {
        auto begin_time = std::chrono::steady_clock::now();

     for(int j = 0;j < width;j++) {
        if(cmp(dist(j,i,centerx,centery), radius,1)) {
            picount++;
        }
    }   
    auto end_time = std::chrono::steady_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - begin_time);

    std::cout << delta.count() <<"\n";
    }
}
int main(int argc, char **argv) {
    int w = std::atoi(argv[1]);
    int h = std::atoi(argv[2]);
    double r = w/2;
    std::cin.get();
    // Write C++ code here
    //bool *circle = (bool*)malloc(sizeof(bool*) * w * h);
    //initboolarr(circle,w*h,false);
   findpi(w,h,r-1);
   // circlisation(circle,w,h,r); //visualises the process basically
    //renderboolarr('#','O',circle,w,h);
    std::cout << picount/(2*r);
    std::cin.get();
    return 0;
}