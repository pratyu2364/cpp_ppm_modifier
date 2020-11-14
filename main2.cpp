#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <cstdlib>
using namespace std;
class RGB {
public:
    //Constructor to set R, G, and B to 0 automatically.
    RGB() : r(0), g(0), b(0) {};

    //Values
     int r, g, b;
};
int main()
{
  std::fstream file;
  std::string size ,max_limt,_R,_G,_B,height,width,number;
  int _height,_width,_max_limit;

  file.open("blackbuck.ascii.ppm",ios::in | ios::out);
  file>>number;
  std::cout << number << '\n';
  if(number!="P3" )
  {
  file.close();
  //return;
  }
  else
  {
  //std::cout << "1"<< '\n';
  file>>width>>height;
  _height = stoi(height);
  _width = stoi(width);
//  vector< vector< vector<int> > > RGB(_height, vector< vector<int> >(_width , vector<int>(3)));
  std::cout <<_height<<_width<<'\n';
  file>>max_limt;
  _max_limit = stoi(max_limt.c_str());
//std::cout << "2"<< '\n';
  //file.close();
  vector<RGB> pixels;
  //RGB tmp;
  pixels.clear();
  std::cout<<max_limt <<std::endl;
  for (int i = 0; i < _width*_height; i++) {
    RGB tmp;
      file >> _R >> _G >> _B;
      tmp.r = stoi(_R);
      tmp.g = stoi(_G);
      tmp.b = stoi(_B);

      pixels.push_back(tmp);
  }
  /*for(int i =0 ;i<_height;i++)
  {
    for(int j=0;j<_width;j++)
    {
  //  std::cout << "3"<< '\n';
    file>>R>>G>>B;
    //file>>G;
    //file>>B;
    _R = atoi(R.c_str());
    _G = atoi(G.c_str());
    _B = atoi(B.c_str());
    //std::cout <<_R<<" "<< '\n';
    RGB[i][j][0] = _R;
    RGB[i][j][1] = _G;
    RGB[i][j][2] = _B;
  }
  //std::cout << "4"<< '\n';
}*/
    //file.close();
  /*for(int i =0; i<_height;i++)
  {
    for(int j =0 ;j<_width;j++)
    {
      std::cout << RGB[i][j][0]<<" " << RGB[i][j][0]<<" "<<RGB[i][j][0]<<" ";
    }
  std::cout<<std::endl;

}*/
file.close();
file.open("star_field.ascii.ppm", ios::out | ios::trunc);
/*for(int i=0;i<_width*_height;i++)
{
  cout<<pixels[i].r<<" "<<pixels[i].g<<" "<<pixels[i].b;
    std::cout<<std::endl;
}*/
for(int i=0;i<_width*_height;i++)
{
  int temp1=pixels[i].r;
  int temp2 = pixels[i].g;
  int temp3 = pixels[i].b;
  pixels[i].r =temp3;
  pixels[i].g =temp1;
  pixels[i].b =temp2;
}
file<<number<<endl;
file<<_width<<" "<<_height<<endl;
file<<_max_limit<<endl;
for(int i=0;i<_width*_height;i++)
{
  file<<pixels[i].r<<" "<<pixels[i].g<<" "<<pixels[i].b;
    file<<std::endl;
}



}
}
