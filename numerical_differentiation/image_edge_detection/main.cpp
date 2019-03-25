#include <QImage>
#include <iostream>
#include <QColor>
#include <cmath>

double backward(int x_index, int y_index, QImage image);
double forward(int x_index, int y_index, QImage image);
double central(int x_index, int y_index, QImage image);

int main(int argc, char *argv[]) {
    QImage image("/home/lucas/image_edge/escada.jpg");
    QImage copy = image.convertToFormat(QImage::Format_Grayscale8);
    copy.save("/home/lucas/image_edge/escada_2.jpg");

    int width = copy.width();
    int height = copy.height();

    for(int i = 0; i<width; i++){
        for(int j = 0; j<height; j++){
            int value;
            if(i != 0 && i != width-1){
                value = std::abs(central(i, j, copy));
            } else if(i == 0){
                value = std::abs(forward(i, j, copy));
            } else if(i == width){
                value = std::abs(backward(i, j, copy));
            }

            if(value > 100){
                value = 255;
            } else {
                value = 0;
            }

            copy.setPixel(i, j, QColor(value, value, value).rgb());
        }
    }

    copy.save("/home/lucas/image_edge/escada_3.jpg");
}

double central(int x_index, int y_index, QImage image){
    return (qGray(image.pixel(x_index+1, y_index)) - qGray(image.pixel(x_index - 1, y_index)))/2;
}

double backward(int x_index, int y_index, QImage image){
    return qGray(image.pixel(x_index, y_index)) - qGray(image.pixel(x_index - 1, y_index));
}

double forward(int x_index, int y_index, QImage image){
    return qGray(image.pixel(x_index + 1, y_index)) - qGray(image.pixel(x_index, y_index));
}
