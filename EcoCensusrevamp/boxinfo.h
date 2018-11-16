#ifndef BOXINFO_H
#define BOXINFO_H

#include <QPen>
#include <math.h>

struct BoxInfo {
    QPen pen = QPen();
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;
    BoxInfo penPad() {
        BoxInfo result;
        auto pwscalar = (1.0 / 2.0);
        result.pen = pen;
        result.x = x + floor(pen.width() * pwscalar);
        result.y = y + floor(pen.width() * pwscalar);
        result.w = w - ceil(pen.width() * (2 * pwscalar));
        result.h = h - ceil(pen.width() * (2 * pwscalar));
        return result;
    }
};

#endif // BOXINFO_H
