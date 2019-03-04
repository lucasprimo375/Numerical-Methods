#include <QImage>
#include <iostream>
#include <QColor>
#include <cmath>

int laplace_operator(int x_index, int y_index, QImage image);

int main(int argc, char *argv[]) {
    QImage image("/home/lucas/Numerical-Methods/discrete derivative/gaussian_blur/images/escada.jpg");
    QImage copy = image.copy();

    int width = copy.width();
    int height = copy.height();

    for(int i = 0; i<width; i++){
        for(int j = 0; j<height; j++){
            int value = laplace_operator(i, j, copy);

            copy.setPixel(i, j, value);
        }
    }

    copy.save("/home/lucas/Numerical-Methods/discrete derivative/gaussian_blur/images/escada_2.jpg");
}

int laplace_operator(int x_index, int y_index, QImage image){
    int back_weigth = 0;
    int front_weigth = 0;
    int up_weigth = 0;
    int down_weigth = 0;
    int core_weight = -4*image.pixel(x_index, y_index);

    if(x_index != 0){
        back_weigth = image.pixel(x_index-1, y_index);
    }

    if(x_index != image.width() - 1){
        front_weigth = image.pixel(x_index+1, y_index);
    }

    if(y_index != 0){
        down_weigth = image.pixel(x_index, y_index-1);
    }

    if(y_index != image.height() - 1){
        up_weigth = image.pixel(x_index, y_index+1);
    }

    int result = core_weight + back_weigth + front_weigth + up_weigth + down_weigth;

    result = std::abs(result);

    return result;
}
